#include "suffix_tree.h"

int main()
{
	printf("Kaynak metni giriniz: ");
	gets(kaynak);
	printf("p katarini giriniz: ");
	gets(aranan);	
	Agac_Olustur();
	is_suffix(kaynak);
	in_suffix(temp);
	max_suffix();	
	return (0);
}

