/*
 * link_list.h
 *
 *  Created on: 2019年4月26日
 *      Author: Zuokp
 */

#ifndef LINK_LIST_H_
#define LINK_LIST_H_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/****有头链表****/
typedef struct stNode
{
	int nData;
	struct stNode *next;
}Node, *LinkList;

LinkList initList(int data);
LinkList createNode(int data);
uint32_t countNode(LinkList head);
void insertNodeByFront(LinkList *head, int data);
void insertNodeByTail(LinkList *head, int data);
void insertNodeByPos(LinkList *head, uint32_t pos, int data);
void deleteNodeByData(LinkList *head, int data);
void deleteNodeByPos(LinkList *head, int pos);
void reverseLinklist(LinkList *head);
void sortLinkList(LinkList *head);
void showLinkList(LinkList head);
void destroyLinkList(LinkList *head);
#endif /* LINK_LIST_H_ */
