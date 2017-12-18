int searching_of_size(FILE* a) {
	int size = 0;
	if (a != NULL)
	{
		fseek(a, 0, SEEK_END);
		size = ftell(a);
		fseek(a, 0, SEEK_SET);
		return size;
	}
	return size;
}

unsigned char* encoded_str_fun(unsigned char* s, int* word, char * str, int str_size) {
	int i;
	s = malloc(sizeof(unsigned char) * str_size);
	for (i = 0; i < str_size; i++)
	{
		*(s + i) = (unsigned char)str[(str_size - 1 + (*(word + i))) % str_size];
	}
	return s;
}
