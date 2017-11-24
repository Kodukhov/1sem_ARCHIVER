struct list_ {
    char val;
    struct list_ * next;
};

typedef struct list_ list;

list * list_push(list * head, const char val) {
    if (!head) {
        list * p = (list*)malloc(sizeof(list));
        p->val = val;
        p->next = NULL;
        return p;
    }
    list * p = (list*)malloc(sizeof(list));
    p->val = val;
    p->next = head;
    return p;
}

list * list_push_back(list * head, const char val) {
    if (!head) {
        list * p = (list*)malloc(sizeof(list));
        p->val = val;
        p->next = NULL;
        return p;
    }
    list * p = head;
    while (p->next)
        p = p->next;
    list * q = (list*)malloc(sizeof(list));
    q->val = val;
    q->next = NULL;
    p->next = q;
    return head;
}

list * list_free(list * head) {
    if (!head){
        return NULL;
    }
    list * p = head->next;
    while(p) {
        free(head);
        head = p;
        p = p->next;
    }
    free(head);
    free(p);
    return NULL;
}

void list_print(list *head) {
    list * p = head;
    while (p) {
        printf("%c ", p->val);
        p = p->next;
    }
    printf("\n");
}
