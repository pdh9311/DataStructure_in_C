#include "selection.h"
#include <time.h>

int main(void) {

	ArrayList *arrayList;
	ArrayListNode element;
	int max = 10;

	srand(time(NULL));
	arrayList = createArrayList(max);
	for (int i = 0; i < max; i++) {
		element.data = rand() % 100;	// 0 ~ 99
		addALElement(arrayList, i, element);
	}
	printf("========= init arrayList =========\n");
	displayArrayList(arrayList); printf("\n");

	printf("========= ascending sort =========\n");
	selectionSort(arrayList);
	displayArrayList(arrayList); printf("\n");

	printf("========= descending sort =========\n");
	for (int i = 0; i < arrayList->currentElementCount; i++) {
		(arrayList->pElement)[i].data *= -1;
	}
	selectionSort(arrayList);
	for (int i = 0; i < arrayList->currentElementCount; i++) {
		(arrayList->pElement)[i].data *= -1;
	}
	displayArrayList(arrayList); printf("\n");
}
