struct node_ {
    struct node_ * r, *l;
    int val;
    int cnt;
};

typedef struct node_ node;

node * tree_add(node * root, const int val) {
    if (!root) {
        node * p = (node*)malloc(sizeof(node));
        p->r = NULL;
        p->l = NULL;
        p->val = val;
        p->cnt = 1;
        return p;
    }
    int c = val - root->val;
    if (c < 0)
        root->l = tree_add(root->l, val);
    else if (c == 0)
        ++(root->cnt);
    else
        root->r = tree_add(root->r, val);
    return root;
}

void tree_print(node * root) {
    if (root) {
        tree_print(root->l);
        printf("%d - %d\n", root->val, root->cnt);
        tree_print(root->r);
    }
}

node * tree_free(node * root) {
    if (!root)
        return NULL;
    root->r = tree_free(root->r);
    root->l = tree_free(root->l);
    free(root);
    return NULL;
}

int tree_find_cnt(node * root, const int key) {
	if (!root)
		return 0;
	int c = key - root->val;
	if (c == 0)
		return root->cnt;
	if (c < 0)
		return tree_find_cnt(root->l, key);
	return tree_find_cnt(root->r, key);
}

int tree_sum(node * root) {
	if (!root)
		return 0;
	return tree_sum(root->l) + tree_sum(root->r) + root->val * root->cnt;
}

int tree_left_cnt(node * root) {
	if (!root)
		return 0;
	if (!root->l)
		return tree_left_cnt(root->r);
	return tree_left_cnt(root->l) + tree_left_cnt(root->r) + 1;
}

int tree_node_cnt(node * root) {
	if (!root)
		return 0;
	if (!root->l && !root->r)
		return 1;
	return tree_node_cnt(root->r) + tree_node_cnt(root->l);
}

int tree_node_sum(node * root) {
	if (!root)
		return 0;
	if (!root->l && !root->r)
		return root->val * root->cnt;
	return tree_node_sum(root->r) + tree_node_sum(root->l);
}

int tree_h(node * root) {
	if (!root)
		return 0;
	int hl = tree_h(root->l), hr = tree_h(root->r);
	return (hl > hr) ? hl + 1 : hr + 1;

}

void tree_level_(node * root, int level, int * cnt) {
	if (root) {
		*(cnt + level) += 1;
		tree_level_(root->l, level + 1, cnt);
		tree_level_(root->r, level + 1, cnt);
	}
}

void tree_level_cnt(node * root) {
	int h = tree_h(root);
	int * cnt = (int*)malloc(sizeof(int) * h);
	int i = 0;
	for (i = 0; i < h; ++i)
		*(cnt + i) = 0;
	tree_level_(root, 0, cnt);
	for (i = 0; i < h; ++i)
		printf("%d ", *(cnt + i));
	printf("\n");
	free(cnt);
}

int tree_internodes_cnt(node * root) {
	if (!root)
		return 0;
	int cnt = 0;
	if (root->r || root->l)
		++cnt;
	return tree_internodes_cnt(root->r) + tree_internodes_cnt(root->l) + cnt;
}

void tree_inf(node * root) {
    if (root) {
        tree_inf(root->l);
        printf("%d ", root->val);
        tree_inf(root->r);
    }
}

void tree_pref(node * root) {
    if (root) {
        printf("%d ", root->val);
        tree_pref(root->l);
        tree_pref(root->r);
    }
}

void tree_postf(node * root) {
    if (root) {
        tree_postf(root->l);
        tree_postf(root->r);
        printf("%d ", root->val);
    }
}
