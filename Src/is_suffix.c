#include "suffix_tree.h"

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
