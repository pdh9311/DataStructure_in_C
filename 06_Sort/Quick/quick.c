#include "quick.h"

static void swap(ArrayList *arrayList, int front, int end)
{
	int tmp;

	tmp = (arrayList->pElement)[front].data;
	(arrayList->pElement)[front].data = (arrayList->pElement)[end].data;
	(arrayList->pElement)[end].data = tmp;
}

static int partition(ArrayList *arrayList, int left, int right)
{
	int pivot = (arrayList->pElement)[(left + right) / 2].data;
	int frontBig = left;
	int endSmall = right;

	while (frontBig <= endSmall)
	{
		while (frontBig <= right && (arrayList->pElement)[frontBig].data < pivot)
			frontBig++;
		while (endSmall >= left && (arrayList->pElement)[endSmall].data > pivot)
			endSmall--;
		if (frontBig <= endSmall)
			swap(arrayList, frontBig++, endSmall--);
	}
	return (frontBig);
}

void quickSort(ArrayList *arrayList, int left, int right)
{
	if (left >= right)
		return ;
	int	mid = partition(arrayList, left, right);
	quickSort(arrayList, left, mid - 1);
	quickSort(arrayList, mid, right);
}
