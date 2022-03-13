#include "insertion.h"

void insertionSort(ArrayList *arrayList)
{
	int size = arrayList->currentElementCount;\
	int insertData;
	int i, j;

	for (i = 1; i < size; i++) {
		insertData = (arrayList->pElement)[i].data;
		for (j = i - 1; j >= 0 && (arrayList->pElement)[j].data > insertData; j--) {
			(arrayList->pElement)[j + 1].data = (arrayList->pElement)[j].data;
		}
		(arrayList->pElement)[j + 1].data = insertData;
	}
}
