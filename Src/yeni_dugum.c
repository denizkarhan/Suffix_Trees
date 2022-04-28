#include "suffix_tree.h"

Node *Yeni_Dugum(int ilk, int *son)
{
	node_count++;
	Node *node =(Node*) malloc(sizeof(Node));
	int i;
	for (i = 0; i < 256; i++)
		node->Dallar[i] = NULL;                                
	node->next = root;
	node->ilk = ilk;
	node->son = son;

	node->Dugum_Numarasi = -1;
	return node;
}  
