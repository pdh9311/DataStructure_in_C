#include "arraylist.h"
#include <stdlib.h>

ArrayList*	createArrayList(int maxElementCount)
{
	ArrayList	*arraylist;

	arraylist = (ArrayList *)malloc(sizeof(ArrayList));
	if (arraylist == NULL)
		return (NULL);
	arraylist->maxElementCount = maxElementCount;
	arraylist->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * )
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
