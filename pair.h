struct pair_ {
    int cnt;
    unsigned char val;
    struct pair_ * right;
    struct pair_ * left;
};

typedef struct pair_ pair;

struct listp_ {
    pair * pp;
    struct list_ * next;
};

typedef struct listp_ list_pair;

list_pair * pair_push_sort(list_pair * head, pair * p) {
    if (!p->cnt) {
        return head;
    }
    if (!head) {
        list_pair * q = (list_pair *)malloc(sizeof(list_pair));
        q->pp = p;
        q->next = NULL;
        return q;
    }
    list_pair * q = (list_pair*)malloc(sizeof(list_pair));
    q->pp = p;
    int c = q->pp->cnt;
    if (c < head->pp->cnt) {
        q->next = head;
        return q;
    }
    list_pair * prev = head, * cur = head->next;
    while (cur && c >= cur->pp->cnt) {
        cur = cur->next;
        prev = prev->next;
    }
    prev->next = q;
    q->next = cur;
    return head;
}

void pair_print(list_pair *head) {
    list_pair * p = head;
    while (p) {
        printf("%c: %d\n", p->pp->val, p->pp->cnt);
        p = p->next;
    }
    printf("\n");
}

list_pair * build_tree(list_pair * head) {
    if (!head)
        return head;
    if (!head->next)
        return head;
    list_pair * p = head;
    list_pair * q = head->next;
    pair * b = (pair *)malloc(sizeof(pair));
    b->cnt = p->pp->cnt + q->pp->cnt;
    b->val = '*';
    b->left = p->pp;
    b->right = q->pp;
    head = pair_push_sort(head, b);
    list_pair * qq = q->next;
    free(p);
    free(q);
    return qq;
}

void tree_inf(pair * root) {
    if (root) {
        tree_inf(root->left);
        printf("%c ", root->val);
        tree_inf(root->right);
    }
}

void tree_pref(pair * root) {
    if (root) {
        printf("%c ", root->val);
        tree_pref(root->left);
        tree_pref(root->right);
    }
}

pair * tree_free(pair * root) {
    if (!root)
        return NULL;
    root->right = tree_free(root->right);
    root->left = tree_free(root->left);
    free(root);
    return NULL;
}
