#include "bubble.h"

void bubbleSort(ArrayList *arrayList)
{
	int size = arrayList->currentElementCount;
	int i, j;
	int tmp;

	for (i = size - 1; i >= 1; i--) {
		for (j = 0; j < i; j++) {
			if ((arrayList->pElement)[j + 1].data < (arrayList->pElement)[j].data) {
				tmp = (arrayList->pElement)[j + 1].data;
				(arrayList->pElement)[j + 1].data = (arrayList->pElement)[j].data;
				(arrayList->pElement)[j].data = tmp;
			}
		}
	}

}
