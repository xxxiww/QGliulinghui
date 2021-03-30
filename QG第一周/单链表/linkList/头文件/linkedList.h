/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

int type;
void (*dataPrint)(void* ele);//��ӡ����

// define struct of linked list
typedef struct LNode {
	void* data;//ά���û��ṩ������
    struct LNode *next;
} LNode, *LinkedList;//ָ��struct LNode���͵�ָ�����ΪLinkedList

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	ԭ����������
**************************************************************/

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : ��ʼ��һ��������ֻ��head�ڵ�û��ֵ
 *	@param		 : L��ͷ���ڵ�m_��
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L);
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description :�ݻ�һ�������ͷ����нڵ�
 *	@param����		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L);

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : �ڽڵ�p�����ڵ�q
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q);

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : ɾ���ڵ�p֮��ĵ�һ���ڵ㣬����ֵ����e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, void *e);

/**
 *  @name        : void TraverseList(LinkedList L, void(*foreachFunction)(void* data))
 *	@description : �����������ú�������
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void(*foreachFunction)(void* data));

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : ����e���������еĵ�һ���ڵ�
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
LNode* SearchList(LinkedList L, void* e);

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : ��ת����
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L);

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : �ж������Ƿ�ѭ��
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L);

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : ��������ֵΪż���Ľڵ㵹���������룺1->2->3->4�����2->1->4->3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LNode* head);
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : �ҵ��м���
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList L);
void Print_int(int* num);
void Print_char(char* cha);
void Print_float(float* f);
int SelectMenu_dataType();
int SelectMenu_function();
Status chk_data( char *num );
LNode *matchNode(LNode *head, LNode* (*method)(LinkedList L, void* e));

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
