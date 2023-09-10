//Sam Rixford

#ifndef _data_structures_h
#define _data_structures_h 1

typedef struct TAG_NODE{
    float	key;
    struct      TAG_NODE* P;
    struct      TAG_NODE* L;
    struct      TAG_NODE* R;
}NODE;

typedef struct TAG_BST{
    int 	size;
    struct      TAG_NODE* root;
}TREE;

typedef struct TAG_STORE{
    int         size;
    struct      TAG_NODE* head;
}STORE;
#endif
