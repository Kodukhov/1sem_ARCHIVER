int huff_compress(unsigned char * str, int N, unsigned char * strnew, table * arr) {
    unsigned char buf = 0;
    int cntbuf = 0;
    int k, i, j;
    int curnum;
    int y = 0;
    for (i = 0; i < N; ++i) {
        unsigned char c = str[i];
        j = 0;
        while (j < 256 && arr[j].val != c)
            ++j;
        curnum = j;
        for (k = 0; k < arr[curnum].cnt; ++k) {
            if (cntbuf == 8) {
                cntbuf = 0;
                strnew[y++] = buf;
                buf == 0;
            }
            buf = (buf << 1) | arr[curnum].str[k];
            cntbuf++;
        }
    }
    while (cntbuf != 8) {
        buf = buf << 1;
        cntbuf++;
    }
    strnew[y] = buf;
    return y + 1;
}
