#include "shell.h"


static void shellInsertionSort(ArrayList *arrayList, int first, int last, int gap) {
	int i, j, tmp;

	for (i = first + gap; i <= last; i += gap) {
		tmp = (arrayList->pElement)[i].data;
		for (j = i - gap; j >= first && tmp < (arrayList->pElement)[j].data; j -= gap) {
			(arrayList->pElement)[j + gap].data = (arrayList->pElement)[j].data;
		}
		(arrayList->pElement)[j + gap].data = tmp;
	}
}

void shellSort(ArrayList *arrayList)
{
	int i, gap, n;
	n = arrayList->currentElementCount;

	for (gap = n / 2; gap > 0; gap /= 2) {
		// 성능적으로 간격이 짝수이면 1을 더하는 것이 좋은것으로 분석되어 짝수인 경우 간격에  1을 더해주었다. (안해줘도 정렬에 문제는 없다)
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {
			shellInsertionSort(arrayList, i, n - 1, gap);
		}
	}
}