#include "suffix_tree.h"

void max_suffix()
{
	printf("\n3-) Tekrar eden en uzun alt katar '%s' dir ve 1 kere tekrar eder.", &kaynak[1]);
}

void in_suffix(int i)
{
	if (i)
		printf("\n2-) '%s' katari icinde '%s' katari vardir pozisyonu %d dir ve %d kere vardir.", kaynak, aranan, aranan_i, aranan_sayisi);
	else
		printf("\n2-) '%s' katari icinde '%s' katari yoktur!", kaynak, aranan);
}
