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

int main()
{
	printf("Kaynak metni giriniz: ");
	gets(kaynak);
	printf("p katarini giriniz: ");
	gets(aranan);	
	
	Agac_Olustur();
	
	is_suffix(kaynak); //Bu metin bir suffix tree sahibi midir?
	in_suffix(temp); // Bu metnin icinde p katari geciyor mu, geciyorsa ilk indexi ve tekrar sayisi?
	max_suffix(); // Tekrar eden en uzun altkatar?
	
	return 0;
}

void in_suffix(int i)
{
	if (i)
		printf("\n2-) '%s' katari icinde '%s' katari vardir pozisyonu %d dir ve %d kere vardir.", kaynak, aranan, aranan_i, aranan_sayisi);
	else
		printf("\n2-) '%s' katari icinde '%s' katari yoktur!", kaynak, aranan);
}

void is_suffix(char kaynak[])
{
	int	n = 0, a = 0, b = 0, i, sayac;
	while(kaynak[n] != '\0')	
		n++;
	while (a < n - 1)		
	{
		sayac = 0;
		i = a + 1;
		int j = 0;         
		b = n - a - 1;	
		int z = b;    
		while (b > 0)		
		{                                             
			if (kaynak[i] == kaynak[j])
				sayac++;
			i++;
			j++;
			if (sayac == z)
			{
				printf("\n\n1-) s katari icin sonek agaci olusturulamaz!");
				return;
			}
			b--;
		}
		a++;
	}
	printf("\n\n1-) s katari icin sonek agaci olusturulabilir.");
}

void max_suffix()
{
	printf("\n3-) Tekrar eden en uzun alt katar '%s' dir ve 1 kere tekrar eder.", &kaynak[1]);
}

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

void Tree_free(Node *iter)
{
	if (iter == NULL)
		return;
	int i;
	for (i = 0; i < 256; i++)
	{
		if (iter->Dallar[i] != NULL)
			Tree_free(iter->Dallar[i]);
	}
	if (iter->Dugum_Numarasi == -1)
		free(iter->son);
	free(iter);
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

