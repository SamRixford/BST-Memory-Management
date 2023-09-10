//Sam Rixford

#ifndef _BST_h
#define _BST_h 1
#include "data_structures.h"
#include <stdio.h>

void BSTInsert(TREE*, float, STORE*, const char*);
NODE* BSTMinimum(NODE*);
NODE* BSTSearch(NODE*, float);
float BSTMaximum(TREE*);
void BSTPreOrder(NODE*, int);
void BSTInOrder(NODE*, int);
void BSTPostOrder(NODE*, int);
void BSTDeletion(TREE*, NODE*, STORE*, const char*);
void BSTTransplant(TREE*, NODE*, NODE*);
void BSTWrite(TREE*, NODE*, FILE*);

#endif

