//Sam Rixford

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "BST.h"
#include "MM.h"
#include "data_structures.h"

int main(int argc, char **argv){
    TREE* tree = new TREE();
    tree->size = 0;
    NODE* tempNode;
    NODE* rootNode;
    STORE* list = new STORE();
    int num;
    FILE* fp;
    float value;
    char filename[100];
    int returnV;
    char Word[100];
    const char* storeValue;

    if (argc < 2){
        fprintf(stderr, "Usage: ./PJ3 flagMM\n");
        exit(0);
    }
    storeValue = argv[1];
    while (1){
      returnV = nextInstruction(Word, &num, &value, filename);

        if (returnV == 0){
            fprintf(stderr, "Warning: Invalid instruction\n");
            continue;
        }


        if (strcmp(Word, "Stop")==0){
            return 0;
        }

	if (strcmp(Word, "Read")==0){
	   if (tree->size != 0){
	   fprintf(stderr, "Error: Reading into non-empty tree\n");
	   continue;
	   }
	   fp = fopen(filename, "r");
	   if (!fp){
	   fprintf(stdout, "Reading unsuccessful\n");
	   continue;
	   }
	   int sizee = 0;
	   fscanf(fp, "%d", &sizee);
	   for(int i = 0; i < sizee; i++){
	     fscanf(fp, "%f", &value);
	     BSTInsert(tree, value, list, storeValue);
	   }
	   fprintf(stdout, "Reading successful\n");
	   fclose(fp);
	  continue;
        }

        if (strcmp(Word, "PrintList")==0){
	   if (list == NULL){
	    fprintf(stderr, "Error: store is NULL\n");
	    continue;
	   }  
	   MMPrintList(list, num);
            continue;
        }


        if (strcmp(Word, "Minimum")==0){
	  if(tree->size == 0){
            fprintf(stderr, "Error: tree is empty\n");
	    continue;
	  }
	        rootNode = tree->root;
                rootNode = BSTMinimum(rootNode);
		value = rootNode->key;
                fprintf(stdout, "Minimum = %f\n", value);
	    continue;
	}
    


        if (strcmp(Word, "Write")==0){
	  if (tree == NULL){
	      fprintf(stderr, "Error: tree is NULL\n");
	      continue;
	    }
                fp = fopen(filename, "w");
                if (!fp){
                    fprintf(stderr, "Write unsuccessful\n");
                    continue;
                }
		fprintf(fp, "%d\n", tree->size);
		rootNode = tree->root;
		BSTWrite(tree, rootNode, fp);
		fprintf(stdout, "Writing successful\n");
                fclose(fp);
	  continue;
        }


        if (strcmp(Word, "Insert")==0){
	  if (tree == NULL){
	    fprintf(stderr, "Error: tree is NULL\n");
	    continue;
	  }
	  rootNode = tree->root;
	  tempNode = BSTSearch(rootNode, value);
	  if (tempNode != NULL){
	    fprintf(stdout, "%f already in tree, no insertion\n", value);
	    tempNode = NULL;
	    continue;
	  }
	  BSTInsert(tree, value, list, storeValue);
	  fprintf(stdout, "%f inserted\n", value);
	  tempNode = NULL;
	  continue;
        }


        if (strcmp(Word, "Maximum")==0){
	  if(tree->size == 0){
            fprintf(stderr, "Error: tree is empty\n");
            continue;
          }
	  value = BSTMaximum(tree);
	  fprintf(stdout, "Maximum = %f\n", value);
	  continue;

        }


        if (strcmp(Word, "PreOrder")==0){
	   if (tree == NULL){
	    fprintf(stderr, "Error: tree is NULL\n");
 	    continue;
	  }
	   tempNode = tree->root;
	   BSTPreOrder(tempNode, num);
	   tempNode = NULL;
	  continue;
        }
    
        if (strcmp(Word, "InOrder")==0){	  
	  if (tree == NULL){
            fprintf(stderr, "Error: tree is NULL\n");
            continue;
          }
	  tempNode = tree->root;
	  BSTInOrder(tempNode, num);
	  tempNode = NULL;
          continue;

        }

        if (strcmp(Word, "PostOrder")==0){	  
	  if (tree == NULL){
            fprintf(stderr, "Error: tree is NULL\n");
            continue;
          }
	  tempNode = tree->root;
	  BSTPostOrder(tempNode, num);
	  tempNode = NULL;
          continue;
        }

        if (strcmp(Word, "Search")==0){
	  if (tree == NULL){
            fprintf(stderr, "Error: tree is NULL\n");
            continue;
          }
	  rootNode = tree->root;
	  tempNode = BSTSearch(rootNode, value);
	  if(tempNode == NULL){
	    fprintf(stdout, "%f not found\n", value);
	  }
	  else{
	    fprintf(stdout, "%f found\n", value);
	  }
	  tempNode = NULL;
          continue;
        }

        if (strcmp(Word, "Delete")==0){
	  if (tree == NULL){
            fprintf(stderr, "Error: heap is NULL\n");
            continue;
          }
	  rootNode = tree->root;
	  tempNode = BSTSearch(rootNode, value);
          if (tempNode == NULL){
            fprintf(stdout, "%f not in tree, no deletion\n", value);
	    tempNode = NULL;  
	    continue;
          }
          BSTDeletion(tree, tempNode, list, storeValue);
          fprintf(stdout, "%f deleted\n", value);
          tempNode = NULL;
	  continue;
        }

    }
    return 1;
}
