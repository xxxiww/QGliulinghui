# include "linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList *L) {

            if(*L!= NULL){
                printf("�Ѿ������������ȴݻ������ٳ�ʼ������");
                return ERROR;
            }
            (*L) = (LNode *)malloc(sizeof(LNode)); //headָ��ͷ�ڵ�
            if((*L) == NULL) return ERROR;//û�п��ٳɹ���㣬����ERROR
            (*L)->data = NULL;  //ͷ�ڵ��ʼ��
            (*L)->next = NULL;
            LinkedList pre1, pre2,pre3;
            printf("��������ʼ���������ݰɣ��������ʼ�����ݻ��ǳ�ʼ����������� -1 \n");
            int flag;
            int type1;
            char ele[100];
            float type3;
            int *intnum;
            float *fo;
            char *chac;  //ָ���ַ������ָ�����



        if(type==1){
                while(1){
                while(!scanf("%d",&type1))//�������
                {
                fflush(stdin);
                printf("�����������������:\n");
                }
                if(type1 == -1){
                    break;
                }
                else{
                intnum = (int *)malloc(sizeof(int));
                *intnum = type1;

                pre1 = (*L);//ͷָ��
                while(1){
                if(pre1->next==NULL){
                LNode* newNode1 = (LNode*)malloc(sizeof(LNode));
                pre1->next = newNode1;
                newNode1->data=intnum;
                newNode1->next=NULL;
                break;
                }
                pre1=pre1->next;}
                }

            }
        }








    if(type==2){
                while(1){
                scanf("%s",ele);
                if(strcmp("-1",ele)){
                    break;
                }else{
                pre2 = (*L);//ͷָ��
                chac = (char*)malloc(sizeof(char) * 100);
                strcpy(chac, ele);
                while(1){
                if(pre2->next==NULL){
                LNode* newNode2 = (LNode*)malloc(sizeof(LNode));
                pre2->next = newNode2;
                newNode2->data=chac;
                newNode2->next=NULL;
                break;
                }
                pre2=pre2->next;}
                }}
    }




    if(type==3){
               while(1){
                while(!scanf("%f",&type3))//�������
                {
                fflush(stdin);
                printf("�����������������:\n");
                }
                if(type3 == -1){
                    break;
                }else{
                fo = (float *)malloc(sizeof(float));
                *fo = type3;
                pre3 = (*L);//ͷָ��
                while(1){
                if(pre3->next==NULL){
                LNode* newNode3 = (LNode*)malloc(sizeof(LNode));
                pre3->next = newNode3;
                newNode3->data=fo;
                newNode3->next=NULL;
                break;
                }
                pre3=pre3->next;}}}
    }





        return SUCCESS;}



/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {

    LNode* head = (*L);
    if (NULL == head)
	{
        printf("��û�г�ʼ������");
		return ;
	}
	if(head->next==NULL){
            free(head);
            (*L) = NULL;
            printf("�ݻٳɹ�\n");
            return;

	}else{
	LNode* cur = head->next;//cur����ͷ����е�next��ָ��ڶ������
	while(1)
	{
		LNode* next = cur->next; //next���ڵڶ�������е�next��ָ����������
		free(cur);               //�ͷŵڶ������
		cur = next;              //�����ƶ�
		if(cur->next == NULL)
            break;                //��ʱ�Ѿ�������β
	}
	free(head);                       //�ͷ�ͷ���
	(*L) = NULL;                   //ͷָ��Ϊ��
	printf("�ݻٳɹ�\n");
	return ;}


}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
     if(p==NULL || q == NULL)
        return ERROR;
     q->next =  p->next;
     p->next = q;
     return SUCCESS;

}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, void *e) {
         if(p->next == NULL)
            return ERROR;
         LNode* temp = p->next;
         e = temp->data;
         printf("ɾ���ɹ���ɾ���Ľ���ĵ�һ������ֵΪ��\n");
         (*dataPrint)(e);
         p->next = temp->next;
         free(temp);
         return SUCCESS;


}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(void* e)) {//LNode* L (ͷָ�룩
    if (NULL == L || NULL == visit)
	{
		return ;
	}
	LNode* cur = L->next;   //cur����ͷ�ڵ��next
	while(1)
	{
		(*visit)(cur->data);   //�ӵڶ�����㿪ʼ��data���������
		cur = cur->next;
		if(cur == NULL)
           break;
	}
	return ;



}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */

LNode* SearchList(LinkedList L, void* e) {
     int flag;
     LinkedList p = L->next;
     if (NULL == L || p == NULL)
	{
		return NULL;
	}
	LNode* cur = L->next;   //cur����ͷ�ڵ��next
	while(p!=NULL)
	{
	    if(type == 1){
            if (*((int *)e) == *((int *)(p->data))){
                flag = 1;
                break;
            }
	    }
	    if(type == 2){
            if (strcmp((char *)e,(char *)(p->data)) == 0){
                flag = 1;
                break;
            }
	    }
	    if(type == 3){
            if (*((float *)e) == *((float *)(p->data))){
                flag = 1;
                break;
            }
	    }
	    p = p->next;
	}
	if(flag) {
        return p;}
	 else {
        return NULL;}


}
/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {//ָ��ͷָ���ָ��
    if (NULL == (*L) )
	{
		return ERROR;
	}
	LNode* pre = NULL;
	LNode* cur = (*L)->next;
	LNode* next = NULL;
	while (cur!=NULL)
	{
		//��¼��һ�����
		next = cur->next;
		//��ǰ���ָ��ǰ�����
		cur->next = pre;
		//cur pre �����ƶ�
		pre = cur;
		cur = next;
	}
	//��ͷ���ָ�����һ����� ʵ�ַ�ת
	(*L)->next = pre;
	return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    if(L == NULL){
        return ERROR;
    }
    LNode *pre = L->next;
    LNode *lag = L;
    while(pre){
        if(lag == pre){
            return SUCCESS;
        }
        lag = lag->next;
        pre = pre->next;
        if(pre){
            pre = pre->next;
        }
    }
    return ERROR;


}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LNode* head) {

    //���ڵ�С��2����ֱ�ӷ���
    if(NULL == head || NULL == head->next)
        return head;

    LNode* first = head;
    LNode* second = head->next;
    //���ٽ���һ�Σ�������ͷ�ڵ�ָ��ԭhead�ĵڶ����ڵ�
    LNode* newHead = second;

    do{
        first->next=second->next;
        second->next=first;
        first=first->next;

        //�����´��Ƿ����㹻�ڵ���н����������ǽ��ѽ������Ľڵ��next����ָ�򼴽������Ľڵ㣬����ֱ���˳�ѭ��
        if(first&&first->next){
            second->next->next=first->next;
            second=first->next;
        }else{
            break;
        }
    } while(1);

      LNode* newNode = (LNode*)malloc(sizeof(LNode));
      newNode->data=NULL;
      newNode->next=newHead;
      newHead=newNode;


    return newHead;



}



/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish**/

LNode* FindMidNode(LinkedList L) {
    LNode *fast = L ;
	LNode *slow = L ;
	while (1)
	{
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		slow = slow->next;
	}
	slow = slow->next;
	return slow;//��ʱslowָ��ָ���м���


}
void Print_int(int *num)
{
    if (num == NULL)
	{
		return;
	}
	printf(" %d ", *num);
	return;

}
void Print_char(char* cha)
{
	if (NULL == cha)
	{
		return;
	}
	printf(" %s ",cha);
	return;
}
void Print_float(float* f)
{
	if (NULL == f)
	{
		return;
	}
	printf(" %f ",(*f));
	return;
}


int SelectMenu_dataType()
{
    printf("��ѡ����Ҫ�����������������\n");
    printf("*****************************************************\n");
	printf("1----  int\n\n");
	printf("2----  char[]\n\n");
	printf("3----  float\n");
	printf("*****************************************************\n");
    char str[100];
    int choice;
    while ( 1 )
    {
        printf("input :");
        scanf("%s", str );
        if ( chk_data( str )==ERROR )
        {
            printf("�������ݴ������������룡\n");
        }
        else{
            choice = atoi(str);
            if(choice>=1&&choice<=3)
            {
                return choice;
            }
            else{
                     printf("�������ݴ������������룡\n");

            }
        }

    }



}

int SelectMenu_function()
{
	printf("��ѡ��Ҫ��ѯ�����ݣ�\n");
	printf("*****************************************************\n");
	printf("1----  ��ʼ������\n\n");
	printf("2----  �ݻ�����\n\n");
	printf("3----  ������Ľ��ֵ�������һ�����\n\n");
	printf("4----  ��ӡɾ���Ľڵ�֮��ĵ�һ���ڵ��ֵ\n\n");
	printf("5----  ����������ӡ\n\n");
	printf("6----  ��ת����\n\n");
	printf("7----  �ж������Ƿ�ѭ��\n\n");
	printf("8----  �������н����������\n\n");
	printf("9----  �ҵ��м��㲢��ӡ\n\n");
	printf("0----  �˳�\n");
	printf("*****************************************************\n");

	char str[100];
    int choice;
    while ( 1 )
    {
        printf("input :");
        scanf("%s", str );
        int length=strlen(str);
        if ( chk_data( str )==ERROR )//�жϲ��ǷǷ�����
        {
            printf("�������ݴ������������룡\n");
        }
        else{
            choice = atoi(str);
            if(choice>=0&&choice<=10)
            {
                return choice;
            }
            else{
                     printf("�������ݴ������������룡\n");

            }
       }
     }
}

//У������������Ƿ�Ϊ����
Status chk_data( char *num )
{
    int i;
    for( i=0;num[i];i++ )
    {
        if ( num[i] >'9'|| num[i] <'0' ) //ֻҪ�з����֣��ͷ��ش���
            return ERROR;
    }

    return SUCCESS;
}



LNode *matchNode(LNode *head, LNode* (*method)(LinkedList L, void* e)) {
    LNode* find;
    int* in;
    char* ch ;
    float* ft ;
    printf("��������Ҫ���ҵĽ���ֵ\n");

        if(type==1){
            in = (int *)malloc(sizeof(int));
            while(!scanf("%d",in))
          {
            fflush(stdin);
            printf("\n�����������������:\n");
          }

                find =method(head,in);


        }
        if(type==2){
            ch = (char*)malloc(sizeof(char)*100);
            while(!scanf("%s",ch))
          {
           fflush(stdin);
           printf("\n�����������������:\n");
        }

                find =method(head,ch);


        }
        if(type==3){
            ft = (float*)malloc(sizeof(float)) ;
            while(!scanf("%f",ft))
            {
            fflush(stdin);
         printf("\n�����������������:\n");
            }

            find =method(head,ft);}


        if(find!=NULL){
            printf("�Ѿ��ҵ��˸ý�㣡\n");
        }else{
            printf("û�иý�㣬����������\n");
        }

    return find;
}
