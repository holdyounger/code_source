/********************************************************************************
 *
 *        Copyright (C) 2021  Beijing winicssec Technology
 *        All rights reserved
 *
 *        filename :      ReverseList.h
 *        description :   反转链表
 *
 *        created by  mingming.shi on Jul. 12th, 2021
 *
 ********************************************************************************/

#include <iostream>
#include <stdio.h>
#include <vld.h>
using namespace std;

#define DEFAULT_CHAR_SIZE 1000

struct ListNode {
	char*  str;
	ListNode *next;
	ListNode(void):str(" "),next(NULL){}
	ListNode(char* x)
	{
		if(sizeof(x) == 0)
		{
			str = (char*)malloc(sizeof(char));
			*str = '\0'; 
		}
		free(str);
		str = (char*)malloc(strlen(x));
		strcpy_s(str,strlen(x)+1,x);
	}
};

//ListNode* InitListNode(char* str);
//ListNode* ReverseList(ListNode* phead);
//void PrintListNode(ListNode* phead);
//bool IsNum(char* str);
//void Destory(ListNode* phead);

/*
* @fn           InitListNode
* @brief        根据字符串生成单链表   
* @param[in]    str :输入的以空格为分隔符的字符串
* @param[out]   
* @return       listNode* :链表结构体的头结点
*               
* @detail      
* @author       mingming.shi
* @date         2021-7-12
*/
ListNode* InitListNode(char* str)
{
	ListNode *head;
	ListNode *pf;
	ListNode* tempNode; // 临时节点
	char *p;

	if(str == NULL)
	{
		return NULL;
	}

	head  = (ListNode*)malloc(sizeof(ListNode));
	pf = head;

	p = strtok(str, " ");
	while(p)
	{ 
		tempNode = (ListNode*)malloc(sizeof(ListNode));
		tempNode->str = p;
		tempNode->next = NULL;

		pf->next = tempNode;
		pf = pf->next;
		p = strtok(NULL, " ");  
	}

	tempNode = head->next;
	free(head);

	return tempNode;
}

/*
* @fn           InitListNode
* @brief        根据字符串生成单链表   
* @param[in]    argc: 参数个数
				argv: 参数列表
* @param[out]   
* @return       listNode* :链表结构体的头结点
*               
* @detail      
* @author       mingming.shi
* @date         2021-7-12
*/
ListNode* InitListNode(int n,char* str[])
{
	ListNode *head=(ListNode*)malloc(sizeof(ListNode));
	ListNode *node,*p = head;
	int i=1;

	if(head==NULL)
	{
		return NULL;
	}

	head->next=NULL;

	while(i<=n)
	{
		if(NULL!=str[i])
		{
			node = (ListNode*)malloc(sizeof(ListNode));
			node->str=str[i];
			node->next=NULL;
			
			p = node;
			p = p->next;
		}
		i++;
	}

	return head;
}

/*
* @fn           ReverseList
* @brief        反转链表  
* @param[in]    phead:需要反转的链表头结点
* @param[out]   
* @return       listNode* :反转后链表结构体的头结点
*               
* @detail      
* @author       mingming.shi
* @date         2021-7-12
*/
ListNode* ReverseList(ListNode* phead)
{
	ListNode* cur = phead;
	ListNode* pre = NULL;
	ListNode* nex = NULL;
	while(cur)
	{
		nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	return pre;
}

/*
* @fn           PrintListNode
* @brief        根据字符串生成单链表   
* @param[in]    phead:需要打印的链表头结点
* @param[out]   
* @return       void
*               
* @detail      
* @author       mingming.shi
* @date         2021-7-12
*/
void PrintListNode(ListNode* phead)
{
	if(phead->str == NULL)
	{
		return;
	}

	ListNode *cur = phead;
	while (cur->next != NULL)
	{
		cout << cur->str << ",";
		cur = cur->next;
	}
	cout << cur->str << "."<< endl;
}

/*
* @fn           IsNum
* @brief        判断string是否为纯数字格式   
* @param[in]    str :字符串
* @param[out]   
* @return       True/False
*               
* @detail      
* @author       mingming.shi
* @date         2021-7-12
*/
bool IsNum(char* str)
{
	if(*str == NULL)
	{
		return false;
	}

	for (size_t i=0; i < strlen(str); i++ )
	{
		int temp = (int)str[i];

		if(temp >='0' && temp <='9'){
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;

}

/*
* @fn           Destory
* @brief		释放链表内存   
* @param[in]    phead :需要被释放的链表头结点
* @param[out]   
* @return		void
*               
* @detail      
* @author       mingming.shi
* @date         2021-7-12
*/
void Destory(ListNode* phead)
{
	if(phead == NULL)
	{
		return;
	}

	ListNode *p=phead;
	ListNode *q;

	while(p != NULL)
	{
		q=p->next;
		//free(p->str);
		free(p);
		p=q;
	}
	p = NULL;
}

/*
* @fn           Destory
* @brief		释放链表内存   
* @param[in]    phead :需要被释放的链表头结点
* @param[out]   
* @return		void
*               
* @detail      
* @author       mingming.shi
* @date         2021-7-12
*/
void ListSeparation(ListNode *list,ListNode*& numList,ListNode*& letterList)
{
	if(list == NULL)
	{
		return;
	}

	ListNode *temp,*head = list;


	ListNode *n, *l;
	n = numList;
	l = letterList;

	while (head != NULL)
	{
		temp = (ListNode*)malloc(sizeof(ListNode));
		temp->str = head->str;
		temp->next = NULL;

		if(IsNum(head->str))
		{
			n->next = temp;
			n = n->next;
		}
		else
		{
			l->next = temp;
			l = l->next;
		}
		head = head->next;
	}
	
}