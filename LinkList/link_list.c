/*
 * link_list.c
 *
 *  Created on: 2019年4月26日
 *      Author: Zuokp
 */
#include "link_list.h"

LinkList initList(int data)
{
	LinkList head = NULL;
	head = (LinkList) malloc (sizeof(Node));
	if (head != NULL)
	{
		head->nData = data;
		head->next = NULL;
	}
	return head;
}

LinkList createNode(int data)
{
	LinkList p = NULL;
	p = (LinkList) malloc (sizeof(Node));
	if (p != NULL)
	{
		p->nData = data;
		p->next = NULL;
	}
	return p;
}

uint32_t countNode(LinkList head)
{
	uint32_t num = 0;
	if ((NULL == head) || (NULL == head->next))
		return num;
	LinkList p = head->next;
	while(p != NULL)
	{
		++num;
		p = p->next;
	}
	return num;
}

void insertNodeByFront(LinkList *head, int data)
{
	if (NULL == *head)
		return;
	LinkList p = *head;
	LinkList q = NULL;
	LinkList temp = NULL;

	q = createNode(data);
	if (q != NULL)
	{
		temp = p->next;
		p->next = q;
		q->next = temp;
	}
}

void insertNodeByTail(LinkList *head, int data)
{
	if (NULL == *head)
		return;
	LinkList p = *head;
	LinkList q = NULL;
	LinkList temp = NULL;

	while(p != NULL)
	{
		temp = p;
		p = p->next;
	}
	q = createNode(data);
	if (q != NULL)
	{
		temp->next = q;
	}
}

void insertNodeByPos(LinkList *head, uint32_t pos, int data)
{
	if ((NULL == *head) || (NULL == (*head)->next))
		return;
	uint32_t size = countNode(*head);
	if (pos > size)
		return;
	uint32_t index = 0;
	LinkList p = *head;
	LinkList q = NULL;
	LinkList temp = NULL;
	while (!(index++ == pos))
	{
		temp = p;
		p = p->next;
	}
	//
	q = createNode(data);
	if (NULL != q)
	{
		temp->next = q;
		q->next = p;
	}
}

void deleteNodeByData(LinkList *head, int data)
{
	if ((NULL == *head) || (NULL == (*head)->next))
		return;
	LinkList p = (*head)->next;
	LinkList q = NULL;
	LinkList temp = *head;

	while (p != NULL)
	{
		if (p->nData == data)
		{
			q = p->next;
			temp->next = q;
			free(p);
			p = NULL;
			p = q;
		}
		else
		{
			temp = p;
			p = p->next;
		}
	}
}

void deleteNodeByPos(LinkList *head, int pos)
{
	if ((NULL == *head) || (NULL == (*head)->next))
		return;
	uint32_t size = countNode(*head);
	if (pos > size)
		return;
	LinkList p = *head;
	LinkList q = NULL;
	LinkList temp = NULL;

	while(p != NULL)
	{
		if (0 == pos)
		{
			temp = p->next;
			q->next = temp;
			free(p);
			p = NULL;
			break;
		}
		q = p;
		p = p->next;
		--pos;
	}
}

void reverseLinklist(LinkList *head)
{
	if ((NULL == *head) || (NULL == (*head)->next))
		return;
	LinkList p = (*head)->next;
	LinkList q = NULL;
	(*head)->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = (*head)->next;
		(*head)->next = q;
	}
}

void sortLinkList(LinkList *head)
{
	if ((NULL == *head) || (*head)->next == NULL)
		return;
	LinkList pre;
	LinkList p;
	LinkList tail = NULL;

	while ((*head)->next != tail)
	{
		pre = *head;
		p = (*head)->next;
		while (p->next != tail)
		{
			if (p->nData > p->next->nData)
			{
				pre->next = p->next;
				p->next = pre->next->next;
				pre->next->next = p;
			}
			else
				p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
}

void showLinkList(LinkList head)
{
	if (NULL == head)
		return;
	LinkList p = head->next;

	while(p != NULL)
	{
		printf("%d ", p->nData);
		p = p->next;
	}
	putchar('\n');
}

void destroyLinkList(LinkList *head)
{
	if (NULL == *head)
		return;
	LinkList p = (*head)->next;
	LinkList q = NULL;

	while(p != NULL)
	{
		q = p->next;
		free(p);
		p = NULL;
		p = q;
	}
}


