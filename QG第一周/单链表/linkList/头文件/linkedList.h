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
void (*dataPrint)(void* ele);//打印函数

// define struct of linked list
typedef struct LNode {
	void* data;//维护用户提供的数据
    struct LNode *next;
} LNode, *LinkedList;//指向struct LNode类型的指针变量为LinkedList

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	原型声明部分
**************************************************************/

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : 初始化一个空链表，只有head节点没有值
 *	@param		 : L（头部节点m_）
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L);
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description :摧毁一个链表，释放所有节点
 *	@param参数		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L);

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : 在节点p后插入节点q
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q);

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : 删除节点p之后的第一个节点，将其值赋给e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, void *e);

/**
 *  @name        : void TraverseList(LinkedList L, void(*foreachFunction)(void* data))
 *	@description : 遍历链表并调用函数访问
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void(*foreachFunction)(void* data));

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : 根据e查找链表中的第一个节点
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
LNode* SearchList(LinkedList L, void* e);

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : 反转链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L);

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : 判断链表是否循环
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L);

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : 将链表中值为偶数的节点倒过来，输入：1->2->3->4输出：2->1->4->3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LNode* head);
/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : 找到中间结点
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
