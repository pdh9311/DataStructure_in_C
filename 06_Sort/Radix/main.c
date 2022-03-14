#include "radix.h"
#include <time.h>

int main(void)
{
	// LinkedDeque **deque;
	// for (int i = 0; i < 10; i++) {
	// 	deque[i] = createLinkedDeque();
	// }
	ArrayList *arrayList;

	srand(time(NULL));

	arrayList = createArrayList(10);
	for (int i = 0; i < 10; i++) {
		(arrayList->pElement)[i].data = rand() % 100;
	}

	radixSort(arrayList);

	return (0);
}
