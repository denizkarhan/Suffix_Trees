#include "suffix_tree.h"

int Dal_Uzunlugu(Node *iter)
{
	if (iter == root)
		return (0);
	return *(iter->son) - (iter->ilk) + 1;
}

int Dal_Duzenle(Node *Dal)
{
	if (yeni_uzunluk >= Dal_Uzunlugu(Dal))
	{
		yeni_dal = kaynak[yeni_dal + Dal_Uzunlugu(Dal)] - 32;
		yeni_uzunluk -= Dal_Uzunlugu(Dal);
		yeni_Dugum = Dal;
		return 1;
	}
	return 0;
}

void Dal_Olustur(int konum)
{
	yaprak_sonu = konum;
	kalan_dugum++;
	onceki_Node = NULL;

	while(kalan_dugum > 0) {
		
		if (yeni_uzunluk == 0)
			yeni_dal = kaynak[konum] - 32;

		if (yeni_Dugum->Dallar[yeni_dal] == NULL)
		{
			yeni_Dugum->Dallar[yeni_dal] = Yeni_Dugum(konum, &yaprak_sonu);
			if (onceki_Node != NULL)
			{
				onceki_Node->next = yeni_Dugum;
				onceki_Node = NULL;
			}
		}
		else
		{
			Node *next = yeni_Dugum->Dallar[yeni_dal];
			if (Dal_Duzenle(next))
				continue;
			if (kaynak[next->ilk + yeni_uzunluk] == kaynak[konum])
			{
				if(onceki_Node != NULL && yeni_Dugum != root)
				{
					onceki_Node->next = yeni_Dugum;
					onceki_Node = NULL;
				}
				yeni_uzunluk++;
				break;
			}
			catal_sonu = (int*) malloc(sizeof(int));
			*catal_sonu = next->ilk + yeni_uzunluk - 1;

			Node *Ayir = Yeni_Dugum(next->ilk, catal_sonu);
			yeni_Dugum->Dallar[yeni_dal] = Ayir;

			Ayir->Dallar[kaynak[konum]- 32] = Yeni_Dugum(konum, &yaprak_sonu);
			next->ilk += yeni_uzunluk;
			Ayir->Dallar[yeni_dal] = next;

			if (onceki_Node != NULL)
				onceki_Node->next = Ayir;

			onceki_Node = Ayir;
		}
		kalan_dugum--;
		if (yeni_Dugum == root && yeni_uzunluk > 0)
		{
			yeni_dal = kaynak[konum - kalan_dugum + 1] - 32;
			yeni_uzunluk--;
		}
		else if (yeni_Dugum != root)
			yeni_Dugum = yeni_Dugum->next;
	}
}
