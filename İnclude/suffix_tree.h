#ifndef SUFFIX_TREE.H
# define SUFFIX_TREE.H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node_Root{
	struct Node_Root *Dallar[512];
	struct Node_Root *next;
	int ilk;
	int *son;
	int Dugum_Numarasi;
}Node;

Node *Yeni_Dugum(int ilk, int *son);
int Dal_Uzunlugu(Node *iter);
int Dal_Duzenle(Node *Dal);
void Tree_free(Node *iter);
void Dal_Olustur(int konum);
void Dugum_Numarasi(Node *iter, int Dugum_indexi);
void Agac_Olustur();
void is_suffix(char kaynak[]);
void in_suffix(int i);

Node *root, *onceki_Node, *yeni_Dugum;
int	node_count = 0, yeni_dal = -1, yeni_uzunluk = 0, uzunluk = -1;
int kalan_dugum = 0, yaprak_sonu = -1, *dal_sonu, *catal_sonu, temp = 0, aranan_sayisi = 0, aranan_i = -10;
char kaynak[100], aranan[100];

#endif
