#include "suffix_tree.h"

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
