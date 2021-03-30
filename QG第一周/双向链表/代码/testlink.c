#include"testlink.h"
#include<stdlib.h>
#include<stdio.h>


/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : ��ʼ��һ��ֻ��head�ڵ�Ŀ�����
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
        return ERROR;//û�п��ٳɹ�
	}
	return SUCCESS;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : ��������
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
 *	@description : �ڽڵ�p֮ǰ����ڵ�q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
     if(p==NULL||q==NULL){
       return ERROR;}
    //�������ָ��p��q��ָ��
    q->prior = p->prior;
    p->prior->next = q;
    q->next = p;
    p-> prior = q;
    return SUCCESS;


}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : �ڽڵ�p֮�����ڵ�q
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(p==NULL||q==NULL){
       return ERROR;}
    q->prior =p->next->prior;//q��priָ��p���
    q->next = p->next;//q�е�nextָ��p��һ�����
    p->next->prior=q;
    p->next = q;//p����nextָ��q
    return SUCCESS;



}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    //�жϴ�����Ƿ�Ϊβ���
    if(p->next==NULL)
        {
        return ERROR;}
    DuLNode* temp = p->next;
    p->next->next->prior = p;//��������priָ����p
    *e = p->next->data;//��ֵ�ɹ�
    p->next = p->next->next;//pָ��Ľ���ָ����ָ��������
    free(temp);
    return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : �����������ú�������
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLNode* L, void (*visit)(ElemType e)) {
    //����������ָ��head��ָ�룬������ָ��
    DuLNode * head = L;
     if (NULL == head || NULL == visit)
	{
		return ;
	}
	DuLNode* cur = head->next;   //cur����ͷ�ڵ��next
	while(1)
	{
		(*visit)(cur->data);   //�ӵڶ�����㿪ʼ��data���������
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
 p = head;//ͷ�ڵ��next
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
//���ܲ˵�
int SelectMenu_function()
{
    printf("������˫��ѭ����ͷ�ڵ������\n");
	printf("��ѡ��Ҫʵ�ֵĹ��ܣ�\n");
	printf("*****************************************************\n");
	printf("1----  ��ʼ������\n\n");
	printf("2----  ����������β����\n\n");
	printf("3----  �ݻ�����\n\n");
	printf("4----  �ڽڵ�p֮ǰ����ڵ�q\n\n");
	printf("5----  �ڽڵ�p֮�����ڵ�q\n\n");
	printf("6----  ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e\n\n");
	printf("7----  ����������ӡ\n\n");
	printf("0----  �˳�\n");
	printf("*****************************************************\n");

    int choice;

    while(!scanf("%d",&choice))
          {
           fflush(stdin);
           printf("\n�����������������:\n");
          }

        return choice;

  }

//�����µĽ��
DuLNode* createNewnode(ElemType x){

    DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));
    newnode->data = x;
	newnode->next = NULL;
	newnode->prior= NULL;
	return newnode;//����һ��ָ��

}
//���ݴ�����ֵ�ҽ��
DuLNode* SearchList(DuLNode* L, ElemType e) {
     int flag;
     DuLNode* p = L->next;//ͷ�ڵ��next
     if (NULL == L || p == NULL)
	{
		return NULL;
	}
	DuLNode* cur = L->next;   //cur����ͷ�ڵ��next
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
    printf("��������Ҫ���ҵĽ���ֵ\n");


            while(!scanf("%d",&in))
          {
              fflush(stdin);
           printf("\n�����������������:\n");
          }

          find =(*method)(head,in);

           if(find!=NULL){
            printf("�Ѿ��ҵ��˸ý�㣡\n");

        }else{
            printf("û�иý�㣬����������\n");
        }

    return find;
}
