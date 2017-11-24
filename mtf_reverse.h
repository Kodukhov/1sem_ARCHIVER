void mtf_reverse(const unsigned char * str, unsigned char * strnew, const int N, list * dict) {
    int i, j;
    unsigned char c;
    for (i = 0; i < N; ++i) {
        c = str[i];
        if (c == 0) {
            strnew[i] = dict->val;
        }
        else {
            list * prev = dict;
            list * p = dict->next;
            for (j = 1; j < (int)c; ++j) {
                prev = prev->next;
                p = p->next;
            }
            strnew[i] = p->val;
            prev->next = p->next;
            p->next = dict;
            dict = p;
        }
    }
}
