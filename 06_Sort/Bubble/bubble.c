#include "bubble.h"

void bubbleSort(ArrayList *arrayList)
{
	int size = arrayList->currentElementCount;
	int i, j;
	int tmp;

	/*
		94 40 39 24 4

		40 94 39 24 4
		40 39 94 24 4
		40 39 24 94 4
		40 39 24 4  |94

		39 40 24 4  |94
		39 24 40 4  |94
		39 24 4  |40 94

		24 39 4  |40 94
		24 4  |39 40 94

		4 24 39 40 94
	 */
	for (i = size - 1; i >= 1; i--)
	{
		for (j = 0; j < i; j++)	// j == size - 2
		{
			if ((arrayList->pElement)[j + 1].data < (arrayList->pElement)[j].data)
			{
				tmp = (arrayList->pElement)[j + 1].data;
				(arrayList->pElement)[j + 1].data = (arrayList->pElement)[j].data;
				(arrayList->pElement)[j].data = tmp;
			}
		}
	}
}
