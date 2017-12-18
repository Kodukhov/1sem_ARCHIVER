#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "list.h"
#include "BWT.h"
#include "mtf_transform.h"
#include "pair.h"
#include "buildhuff.h"
#include "list2.h"
#include "huff.h"

char* str = NULL;
int str_size;
table arr[256];
int num = 0;
char a[256];

int compare(const void* a, const void* b) {
	int i;
	int* k1 = (int*)a;
	int* k2 = (int*)b;
	char* str1 = malloc(sizeof(char) * str_size);
	char* str2 = malloc(sizeof(char) * str_size);
	for (i = 0; i < (str_size - *k1); i++)
	{
		*(str1 + i + *k1) = str[i];
	}
	for (i = 0; i < (str_size - *k1); i++)
	{
		*(str1 + i) = str[*k1 + i];
	}
	for (i = 0; i < (str_size - *k2); i++)
	{
		*(str2 + i + *k2) = str[i];
	}
	for (i = 0; i < (str_size - *k2); i++)
	{
		*(str2 + i) = str[*k2 + i];
	}
	int com = strcmp(str1, str2);
	free(str1);
	free(str2);
	return com;
}

unsigned char* BWT(unsigned char* encoded_str) {
	int i;
	int* word = (int*)malloc(sizeof(int) * str_size);
	for (i = 0; i < str_size; i++) {
        *(word + i) = i;
	}
	qsort(word, str_size, sizeof(int), compare);
	encoded_str = encoded_str_fun(encoded_str, word, str, str_size);
	free(word);
	return encoded_str;
}

void build_table(pair * root, int pl) {
    if (root->left) {
        ///добавить 0;
        a[pl] = 0;
        build_table(root->left, pl + 1);
    }
    if (root->right) {
        ///добавить 1;
        a[pl] = 1;
        build_table(root->right, pl + 1);
    }
    if (!root->right && !root->left) {
        ///добавить букву;
        arr[num].val = root->val;
        arr[num].cnt = pl;
        int i;
        for (i = 0; i < pl; ++i) {
            arr[num].str[i] = a[i];
        }
        ++num;
    }
}

int main() {
    FILE *in, *out, *in1;
    in1 = fopen("input.txt", "r");
    str_size = searching_of_size(in1);
    fclose(in1);
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    str = (char *)malloc(sizeof(char) * (str_size + 2));
    int i;
    for (i = 0; i < str_size; i++)
    {
        fscanf(in, "%c", (str + i));
        if (*(str + i) == '\n' || *(str+i)=='\0')
        {
            *(str + i) = '^';
            *(str + i + 1) = '^';
            i++;
        }
    }
    str[str_size] = '$';
    str[str_size + 1] = '$';
    str_size = str_size + 2;
    unsigned char * encoded_str = NULL;
    encoded_str = BWT(encoded_str);
    list * dict = NULL;
    for (i = 255; i >= 0; --i) {
        dict = list_push(dict, (unsigned char)i);
    }
    unsigned char * strnew = (unsigned char *)malloc(str_size * sizeof(unsigned char));
    mtf(encoded_str, strnew, str_size, dict);
    free(encoded_str);
    list_free(dict);
    int j;
    pair * treehuf = NULL;
    treehuf = build_huff(strnew, str_size);
    build_table(treehuf, 0);
    //tree_free(treehuf);


    unsigned char * strnew2 = (unsigned char *)malloc(str_size * sizeof(unsigned char));
    for (i = 0; i < str_size; ++i) {
        strnew2[i] = 0;
    }
    int size = huff_compress(strnew, str_size, strnew2, arr);
    for (i = 0; i < size; ++i) {
        fprintf(out, "%c", strnew2[i]);
    }

    printf("%f", (float)str_size / (float)size);

    free(strnew);
    free(strnew2);
    free(str);
    fclose(in);
    fclose(out);
    return 0;
}
