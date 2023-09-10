//Sam Rixford

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "data_structures.h"
#include "MM.h"



void BSTInsert(TREE* tree, float value, STORE* list, const char* storeValue){
  NODE* newNode = new NODE();
  newNode->key = value;
  tree->size += 1;
  NODE* nullNode = NULL;
  NODE* tempNode = tree->root;

  if(strcmp(storeValue, "1")==0){
    if(list->head != NULL){
      if(list->head->R == NULL){
	list->head = NULL;
      }
      else{
    NODE* newHead = list->head->R;
    newHead->P = NULL;
    list->head = newHead;
      }
    }
  }

  while(tempNode != NULL){
    nullNode = tempNode;
    if(newNode->key < tempNode->key){
      tempNode = tempNode->L;
    }
    else{
      tempNode = tempNode->R;
    }
  }
  newNode->P = nullNode;
  if(nullNode == NULL){
    tree->root = newNode;
  }
  else if (newNode->key < nullNode->key){
    nullNode->L = newNode;
  }
  else{
    nullNode->R = newNode;
  }
}

NODE* BSTMinimum(NODE* root){
  while((root != NULL) && (root->L != NULL)){
    root = root->L;
  }
  return root;
}

NODE* BSTSearch(NODE* root, float value){
  if ((root == NULL) || (root->key == value)){
    return root;
  }
  if (value < root->key) {
    return BSTSearch(root->L, value);
  }
  else{
    return BSTSearch(root->R, value);
  }
}

float BSTMaximum(TREE* tree){
  NODE* root = tree->root;
  while((root != NULL) && (root->R != NULL)){
    root = root->R;
  }
  return root->key;
}

void BSTPreOrder(NODE* root, int num){
  if(num == 0){
    if(root != NULL){
      fprintf(stdout, "%lf\n", root->key);
      BSTPreOrder(root->L, num);
      BSTPreOrder(root->R, num);
      }
  }
  if(num == 1){
    if(root == NULL){
      fprintf(stdout, "NULL\n");
    }
    else{
      fprintf(stdout, "%lf\n", root->key);
      BSTPreOrder(root->L, num);
      BSTPreOrder(root->R, num);
    }
  }
}

void BSTInOrder(NODE* root, int num){
  if(num == 0){
    if(root != NULL){
      BSTInOrder(root->L, num);
      fprintf(stdout, "%lf\n", root->key);
      BSTInOrder(root->R, num);
    }
  }
  if(num == 1){
    if(root == NULL){
      fprintf(stdout, "NULL\n");
    }
    else{
      BSTInOrder(root->L, num);
      fprintf(stdout, "%lf\n", root->key);
      BSTInOrder(root->R, num);
    }
  }
}

void BSTPostOrder(NODE* root, int num){
  if(num == 0){
    if(root != NULL){
      BSTPostOrder(root->L, num);
      BSTPostOrder(root->R, num);
      fprintf(stdout, "%lf\n", root->key);
    }
  }
  if(num == 1){
    if(root == NULL){
      fprintf(stdout, "NULL\n");
    }
    else{
      BSTPostOrder(root->L, num);
      BSTPostOrder(root->R, num);
      fprintf(stdout, "%lf\n", root->key);
    }
  }
}

void BSTDeletion(TREE* tree, NODE* root, STORE* list, const char* storeValue){
  tree->size = tree->size - 1;
  if(root->L == NULL){
    BSTTransplant(tree, root, root->R);
  }
  else if(root->R == NULL){
    BSTTransplant(tree, root, root->L);
  }
  else{
    NODE* tempNode = BSTMinimum(root->R);
    if(tempNode->P != root){
      BSTTransplant(tree, tempNode, tempNode->R);
      tempNode->R = root->R;
      tempNode->R->P = tempNode;
    }
    BSTTransplant(tree, root, tempNode);
    tempNode->L = root->L;
    tempNode->L->P = tempNode;
  }
  if(strcmp(storeValue, "1")==0){
    NODE* insert = root;
    insert->P = NULL;
    insert->L = NULL;
    insert->R = NULL;
    MMAdd(list, insert);
  }

}

void BSTTransplant(TREE* tree, NODE* u, NODE* v){
  if(u->P == NULL){
    tree->root = v;
  }
  else if(u == u->P->L){
    u->P->L = v;
  }
  else{
    u->P->R = v;
  }
  if (v!= NULL){
    v->P = u->P;
  }
}

void BSTWrite(TREE* tree, NODE* root, FILE* fp){
  if(root != NULL){
    fprintf(fp, "%f\n", root->key);
    BSTWrite(tree, root->L, fp);
    BSTWrite(tree, root->R, fp);
  }
}
