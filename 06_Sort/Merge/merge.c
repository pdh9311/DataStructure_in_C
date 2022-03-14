#include "merge.h"

static void merge(ArrayList *arrayList, int left, int mid, int right, ArrayList *sorted)
{
	int i, j, k, l;

	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if ((arrayList->pElement)[i].data <= (arrayList->pElement)[j].data) {
			(sorted->pElement)[k++].data = (arrayList->pElement)[i++].data;
		} else {
			(sorted->pElement)[k++].data = (arrayList->pElement)[j++].data;
		}
	}
	if (i > mid) {
		for (l = j; l <= right; l++)
			(sorted->pElement)[k++].data = (arrayList->pElement)[l].data;
	} else {
		for (l = i; l <= mid; l++)
			(sorted->pElement)[k++].data = (arrayList->pElement)[l].data;
	}

	for (l = left; l <= right; l++) {
		(arrayList->pElement)[l].data = (sorted->pElement)[l].data;
	}
}

void mergeSort(ArrayList *arrayList, int left, int right, ArrayList *sorted)
{
	int mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	mergeSort(arrayList, left, mid, sorted);
	mergeSort(arrayList, mid + 1, right, sorted);
	merge(arrayList, left, mid, right, sorted);
}