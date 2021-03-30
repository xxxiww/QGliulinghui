#include"testlink.h"
#include<stdlib.h>
#include<stdio.h>


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : 初始化一个只有head节点的空链表
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
 /**typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;**/

Status InitList_DuL(DuLinkedList *L) {
    DuLNode * head= *L;

    (*L) = (DuLNode*)malloc(sizeof(DuLNode));
	(*L)->next = NULL;
	(*L)->data= 0;
	(*L)->prior = NULL;
	if((*L)==NULL){
        return ERROR;//没有开辟成功
	}
	return SUCCESS;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : 销毁链表
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
  DuLNode* head = (*L);
 DuLNode* cur = head->next;
 while (cur != NULL)
 {
  DuLNode* next = cur->next;
  free(cur);
  cur = next;
 }
 free(head);
 *L = NULL;

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : 在节点p之前插入节点q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
     if(p==NULL||q==NULL){
       return ERROR;}
    //传入的是指向p和q的指针
    q->prior = p->prior;
    p->prior->next = q;
    q->next = p;
    p-> prior = q;
    return SUCCESS;


}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : 在节点p之后插入节点q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(p==NULL||q==NULL){
       return ERROR;}
    q->prior =p->next->prior;//q的pri指向p结点
    q->next = p->next;//q中的next指向p后一个结点
    p->next->prior=q;
    p->next = q;//p结点的next指向q
    return SUCCESS;



}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : 删除节点p之后的第一个节点，并将其值赋给e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    //判断传入的是否为尾结点
    if(p->next==NULL)
        {
        return ERROR;}
    DuLNode* temp = p->next;
    p->next->next->prior = p;//第三结点的pri指向结点p
    *e = p->next->data;//赋值成功
    p->next = p->next->next;//p指向的结点的指针域指向第三结点
    free(temp);
    return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : 遍历链表并调用函数访问
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLNode* L, void (*visit)(ElemType e)) {
    //传过来的是指向head的指针，即二级指针
    DuLNode * head = L;
     if (NULL == head || NULL == visit)
	{
		return ;
	}
	DuLNode* cur = head->next;   //cur等于头节点的next
	while(1)
	{
		(*visit)(cur->data);   //从第二个结点开始才data域才有数据
		cur = cur->next;
		if(cur == NULL)
           break;
	}
	return ;

}
void Print_int(int num)
{

	printf(" %d ", num);
	return;

}
Status addNode(DuLNode* head, int val) {
 if (head == NULL ) {
  return ERROR;
 }
 DuLNode*  pNew;
 DuLNode* p;
 p = head;//头节点的next
 while(p->next != NULL){
  p = p->next;
 }
 pNew = (DuLNode* )malloc(sizeof(DuLNode));
 pNew->data = val;
 pNew->next = NULL;
 pNew->prior = p;
 p->next = pNew;
 return SUCCESS;
}
//功能菜单
int SelectMenu_function()
{
    printf("这里是双向不循环带头节点的链表\n");
	printf("请选择要实现的功能：\n");
	printf("*****************************************************\n");
	printf("1----  初始化链表\n\n");
	printf("2----  给链表连续尾插结点\n\n");
	printf("3----  摧毁链表\n\n");
	printf("4----  在节点p之前插入节点q\n\n");
	printf("5----  在节点p之后插入节点q\n\n");
	printf("6----  删除节点p之后的第一个节点，并将其值赋给e\n\n");
	printf("7----  遍历链表并打印\n\n");
	printf("0----  退出\n");
	printf("*****************************************************\n");

    int choice;

    while(!scanf("%d",&choice))
          {
           fflush(stdin);
           printf("\n输入错误，请重新输入:\n");
          }

        return choice;

  }

//创造新的结点
DuLNode* createNewnode(ElemType x){

    DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));
    newnode->data = x;
	newnode->next = NULL;
	newnode->prior= NULL;
	return newnode;//返回一级指针

}
//根据传来的值找结点
DuLNode* SearchList(DuLNode* L, ElemType e) {
     int flag;
     DuLNode* p = L->next;//头节点的next
     if (NULL == L || p == NULL)
	{
		return NULL;
	}
	DuLNode* cur = L->next;   //cur等于头节点的next
	while(p!=NULL)
	{

            if (e == (p->data)){
                flag = 1;
                break;
            }

	    p = p->next;
	}
	if(flag) {
        return p;}
	 else {
        return NULL;}


}
DuLNode *matchNode(DuLNode *head, DuLNode* (*method)(DuLNode* L, ElemType e)) {
    if(head==NULL){
        return NULL;
    }
    DuLNode* find;
    int flag;
    int in;
    printf("请输入想要查找的结点的值\n");


            while(!scanf("%d",&in))
          {
              fflush(stdin);
           printf("\n输入错误，请重新输入:\n");
          }

          find =(*method)(head,in);

           if(find!=NULL){
            printf("已经找到了该结点！\n");

        }else{
            printf("没有该结点，请重新输入\n");
        }

    return find;
}
