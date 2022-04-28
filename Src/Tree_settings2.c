#include "suffix_tree.h"

void Dugum_Numarasi(Node *iter, int Dugum_indexi)
{
	int n;
	int	sayac;
	if (iter == NULL)
		return;
	if (iter->ilk != -1)
	{
		sayac = 0;
		int	a = iter->ilk, b = *(iter->son);
		for (n=a; n<=b; n++){
			printf("%c", kaynak[n]);
			if(aranan[sayac] == kaynak[n])
				sayac++;
			else
				sayac = -100;
		}
		if (sayac == strlen(aranan))
		{
			temp = 1;
			aranan_sayisi++;
			if (aranan_i == -10)
				aranan_i = a;
		}
		printf("\n");
	}
	int yaprak = 1;
	int i;
	for (i = 0; i < 256; i++)
	{
		if (iter->Dallar[i] != NULL)
		{
			yaprak = 0;
			Dugum_Numarasi(iter->Dallar[i], Dugum_indexi + Dal_Uzunlugu(iter->Dallar[i]));
		}
	}
	if (yaprak == 1)
		iter->Dugum_Numarasi = uzunluk - Dugum_indexi;
}

void Agac_Olustur()
{
	int	i = -1;
	uzunluk = strlen(kaynak);
	dal_sonu = (int*) malloc(sizeof(int));
	*dal_sonu = - 1;
	root = Yeni_Dugum(-1, dal_sonu);
	yeni_Dugum = root;
	while (++i < uzunluk)
		Dal_Olustur(i);
	int Dugum_indexi = 0;
	Dugum_Numarasi(root, Dugum_indexi);
	Tree_free(root);
}
