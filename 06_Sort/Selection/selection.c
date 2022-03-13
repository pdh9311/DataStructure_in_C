#include "selection.h"

void selectionSort(ArrayList *arrayList)
{
	int	tmp;
	int size = arrayList->currentElementCount;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((arrayList->pElement)[i].data > (arrayList->pElement)[j].data) {
				tmp = (arrayList->pElement)[i].data;
				(arrayList->pElement)[i].data = (arrayList->pElement)[j].data;
				(arrayList->pElement)[j].data = tmp;
			}
		}
	}
}
