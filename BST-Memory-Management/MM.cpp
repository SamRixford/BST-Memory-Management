//Sam Rixford

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "data_structures.h"
#include "MM.h"

void MMPrintList(STORE* list, float value){
  fprintf(stdout, "Key values on local list:\n");
  NODE* head = list->head;
  float i = 0;
  while((head != NULL) && (i < value)){
    fprintf(stdout, "%f\n", head->key);
    head = head->R;
    i = i + 1;
  }
}

void MMAdd(STORE* list, NODE* node){
  if(list->head == NULL){
    list->head = node;
    return;
  }
  NODE* temp = list->head;
  temp->P = node;
  node->R = temp;
  list->head = node;
}
