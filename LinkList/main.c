/*
 * main.c
 *
 *  Created on: 2019年4月26日
 *      Author: Zuokp
 */
#include "link_list.h"

int main(int argc, char *argv[])
{
	LinkList pHead = NULL;
	pHead = initList(0);

	int i;
	for (i = 1; i <= 5; ++i)
	{
		insertNodeByFront(&pHead, i);
	}
	showLinkList(pHead);
	destroyLinkList(&pHead);
	pHead->next = NULL;

	for (i = 1; i <= 5; ++i)
	{
		insertNodeByTail(&pHead, i);
	}
	showLinkList(pHead);
	insertNodeByPos(&pHead, 5, 6);
	showLinkList(pHead);
	deleteNodeByData(&pHead, 6);
	showLinkList(pHead);
	deleteNodeByPos(&pHead, 1);
	showLinkList(pHead);
	reverseLinklist(&pHead);
	showLinkList(pHead);
	sortLinkList(&pHead);
	showLinkList(pHead);
	destroyLinkList(&pHead);
	pHead->next = NULL;
	free(pHead);
	pHead = NULL;
	return 0;
}



