pair * build_huff (unsigned char * str, int N) {
    int i, x;
    pair * cnt[256];
    //int i;
    for (i = 0; i < 256; ++i) { //обнулили массив cnt
        cnt[i] = (pair*)malloc(sizeof(pair));
        cnt[i]->cnt = 0;
        cnt[i]->val = (unsigned char)i;
        cnt[i]->right = NULL;
        cnt[i]->left = NULL;
    }
    for (i = 0; i < N; ++i) { //считываем строку
        x = str[i];
        ++(cnt[x]->cnt); //считаем частоту
    }
    list_pair * build = NULL;
    for (i = 0; i < 256; ++i) {
        build = pair_push_sort(build, cnt[i]);
    }
    pair_print(build);
    while (build && build->next)
         build = build_tree(build);
    pair_print(build);
    for (i = 0; i < 256; ++i) {
        free(cnt[i]);
    }
    pair * q = build->pp;
    free(build);
    return q;
}

