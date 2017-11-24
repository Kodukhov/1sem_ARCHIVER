#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mtf_transform.h"
#include "mtf_reverse.h"
#include "tree.h"

struct pair_ {
    int cnt;
    unsigned char val;
};

typedef struct pair_ pair;

int main()
{
    {//проверяем работоспособность
    /*list * dict = NULL, * dict2 = NULL;
    int i;
    for (i = 255; i >= 0; --i) { // создали словарь
        dict = list_push(dict, (unsigned char)i);
        dict2 = list_push(dict2, (unsigned char)i);
    }
    int N = 10;
    unsigned char * str1 = (unsigned char *)malloc(N * sizeof(unsigned char));
    unsigned char * str2 = (unsigned char *)malloc(N * sizeof(unsigned char));
    unsigned char * str3 = (unsigned char *)malloc(N * sizeof(unsigned char));
    unsigned char x;
    for (i = 0; i < N; ++i) { //считали строку
        x = getchar(); // int getchar(void);
        str1[i] = x;
    }
    mtf(str1, str2, N, dict); //прямое преобразование

    mtf_reverse(str2, str3, N, dict2); //обратное
    for (i = 0; i < N; ++i) { //проверяем, что работает
        printf("%c -> %d -> %c\n", str1[i], (int)str2[i], str3[i]);
    }
    list_free(dict);
    list_free(dict2);
    free(str1);
    free(str2);
    free(str3);*/
    }
    int N = 10;
    pair * cnt = (pair *)malloc(256 * sizeof(pair));
    int i;
    for (i = 0; i < 256; ++i) { //обнулили массив cnt
        cnt[i].cnt = 0;
        cnt[i].val = (unsigned char)i;
    }
    unsigned char * str = (unsigned char *)malloc(N * sizeof(unsigned char));
    int x;
    for (i = 0; i < N; ++i) { //считываем строку
        x = getchar(); // int getchar(void);
        str[i] = x;
        ++(cnt[x].cnt); //считаем частоту
    }
    //int sum = 0;
    for (i = 0; i < 256; ++i) {
        printf("%c -> %d\n", cnt[i].val, cnt[i].cnt);
        //sum += cnt[i].cnt;
    }
    //printf("%d\n", sum);

    return 0;
}
