void mtf(const unsigned char * str, unsigned char * strnew, const int N, list * dict) {
    int i = 0;
    unsigned char cnt = 0, c;
    for (i = 0; i < N; ++i) {
        c = str[i];
        if (dict->val == c) {
            strnew[i] = 0;
        }

        else {
            cnt = 1;
            list * prev = dict;
            list * p = dict->next;
            while (p->val != c) {
                prev = prev->next;
                p = p->next;
                cnt += 1;
            }
            prev->next = p->next;
            p->next = dict;
            dict = p;
            strnew[i] = cnt;
        }
    }
}
