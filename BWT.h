#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char* str = NULL;
int str_size;

int compare(const void* a, const void* b)
{
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

int searching_of_size(FILE* a)
{
	int size = 0;
	if (a != NULL)
	{
		fseek(a, 0, SEEK_END);
		size = ftell(a);
		fseek(a, 0, SEEK_SET);
		return size;
	}
}

char* encoded_str_fun(char* s, int* word)
{
	int i;
	s = malloc(sizeof(char) * str_size);
	for (i = 0; i < str_size; i++)
	{
		*(s + i) = str[(str_size - 1 + (*(word + i))) % str_size];
	}
	return s;
}

char* BWT(char* encoded_str)
{
	int i;
	int* word = malloc(sizeof(int) * str_size);
	for (i = 0; i < str_size; i++)
		*(word + i) = i;

	qsort(word, str_size, sizeof(int), compare);

	encoded_str = encoded_str_fun(encoded_str, word);
	free(word);
	return encoded_str;
}

void print_str(char* s, FILE* out)
{
	int i;
	for (i = 0; i < str_size; i++)
	{
		fprintf(out, "%c", *(s + i));
	}
}