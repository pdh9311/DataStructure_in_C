#include "arraylist.h"
#include <stdlib.h>

ArrayList*	createArrayList(int maxElementCount)
{
	ArrayList	*arraylist;

	arraylist = (ArrayList *)malloc(sizeof(ArrayList));
	if (arraylist == NULL)
		return (NULL);
	arraylist->maxElementCount = maxElementCount;
	arraylist->currentElementCount = 0;
	arraylist->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (arraylist->pElement == NULL)
	{
		free(arraylist);
		arraylist = NULL;
		return (NULL);
	}
	return (arraylist);
}

void			deleteArrayList(ArrayList* pList)
{

}

int				isArrayListFull(ArrayList* pList)
{

}

int				addALElement(ArrayList* pList, int position, ArrayListNode element)
{

}

int				removeALElement(ArrayList* pList, int position)
{

}

ArrayListNode*	getALElement(ArrayList* pList, int position)
{

}

void			displayArrayList(ArrayList* pList)
{

}

void			clearArrayList(ArrayList* pList)
{

}

int				getArrayListLength(ArrayList* pList)
{

}
