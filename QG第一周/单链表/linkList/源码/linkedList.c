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
                printf("已经存在链表！请先摧毁链表再初始化链表");
                return ERROR;
            }
            (*L) = (LNode *)malloc(sizeof(LNode)); //head指向头节点
            if((*L) == NULL) return ERROR;//没有开辟成功结点，返回ERROR
            (*L)->data = NULL;  //头节点初始化
            (*L)->next = NULL;
            LinkedList pre1, pre2,pre3;
            printf("现在来初始化链表数据吧！若不想初始化数据或是初始化完成请输入 -1 \n");
            int flag;
            int type1;
            char ele[100];
            float type3;
            int *intnum;
            float *fo;
            char *chac;  //指向字符数组的指针变量



        if(type==1){
                while(1){
                while(!scanf("%d",&type1))//输入错误
                {
                fflush(stdin);
                printf("输入错误，请重新输入:\n");
                }
                if(type1 == -1){
                    break;
                }
                else{
                intnum = (int *)malloc(sizeof(int));
                *intnum = type1;

                pre1 = (*L);//头指针
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
                pre2 = (*L);//头指针
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
                while(!scanf("%f",&type3))//输入错误
                {
                fflush(stdin);
                printf("输入错误，请重新输入:\n");
                }
                if(type3 == -1){
                    break;
                }else{
                fo = (float *)malloc(sizeof(float));
                *fo = type3;
                pre3 = (*L);//头指针
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
        printf("还没有初始化链表！");
		return ;
	}
	if(head->next==NULL){
            free(head);
            (*L) = NULL;
            printf("摧毁成功\n");
            return;

	}else{
	LNode* cur = head->next;//cur等于头结点中的next，指向第二个结点
	while(1)
	{
		LNode* next = cur->next; //next等于第二个结点中的next，指向第三个结点
		free(cur);               //释放第二个结点
		cur = next;              //往后移动
		if(cur->next == NULL)
            break;                //此时已经遍历到尾
	}
	free(head);                       //释放头结点
	(*L) = NULL;                   //头指针为空
	printf("摧毁成功\n");
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
         printf("删除成功，删除的结点后的第一个结点的值为：\n");
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
void TraverseList(LinkedList L, void (*visit)(void* e)) {//LNode* L (头指针）
    if (NULL == L || NULL == visit)
	{
		return ;
	}
	LNode* cur = L->next;   //cur等于头节点的next
	while(1)
	{
		(*visit)(cur->data);   //从第二个结点开始才data域才有数据
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
	LNode* cur = L->next;   //cur等于头节点的next
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
Status ReverseList(LinkedList *L) {//指向头指针的指针
    if (NULL == (*L) )
	{
		return ERROR;
	}
	LNode* pre = NULL;
	LNode* cur = (*L)->next;
	LNode* next = NULL;
	while (cur!=NULL)
	{
		//记录下一个结点
		next = cur->next;
		//当前结点指向前驱结点
		cur->next = pre;
		//cur pre 往后移动
		pre = cur;
		cur = next;
	}
	//将头结点指向最后一个结点 实现翻转
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

    //若节点小于2个，直接返回
    if(NULL == head || NULL == head->next)
        return head;

    LNode* first = head;
    LNode* second = head->next;
    //至少交换一次，返回新头节点指向原head的第二个节点
    LNode* newHead = second;

    do{
        first->next=second->next;
        second->next=first;
        first=first->next;

        //根据下次是否有足够节点进行交换，决定是将已交换过的节点的next重行指向即将交换的节点，还是直接退出循环
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
	return slow;//此时slow指针指向中间结点


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
    printf("请选择想要存入链表的数据类型\n");
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
            printf("输入数据错误，请重新输入！\n");
        }
        else{
            choice = atoi(str);
            if(choice>=1&&choice<=3)
            {
                return choice;
            }
            else{
                     printf("输入数据错误，请重新输入！\n");

            }
        }

    }



}

int SelectMenu_function()
{
	printf("请选择要查询的内容：\n");
	printf("*****************************************************\n");
	printf("1----  初始化链表\n\n");
	printf("2----  摧毁链表\n\n");
	printf("3----  在输入的结点值后面插入一个结点\n\n");
	printf("4----  打印删除的节点之后的第一个节点的值\n\n");
	printf("5----  遍历链表并打印\n\n");
	printf("6----  翻转链表\n\n");
	printf("7----  判断链表是否循环\n\n");
	printf("8----  将链表中结点两两交换\n\n");
	printf("9----  找到中间结点并打印\n\n");
	printf("0----  退出\n");
	printf("*****************************************************\n");

	char str[100];
    int choice;
    while ( 1 )
    {
        printf("input :");
        scanf("%s", str );
        int length=strlen(str);
        if ( chk_data( str )==ERROR )//判断不是非法数据
        {
            printf("输入数据错误，请重新输入！\n");
        }
        else{
            choice = atoi(str);
            if(choice>=0&&choice<=10)
            {
                return choice;
            }
            else{
                     printf("输入数据错误，请重新输入！\n");

            }
       }
     }
}

//校验输入的数据是否为数字
Status chk_data( char *num )
{
    int i;
    for( i=0;num[i];i++ )
    {
        if ( num[i] >'9'|| num[i] <'0' ) //只要有非数字，就返回错误
            return ERROR;
    }

    return SUCCESS;
}



LNode *matchNode(LNode *head, LNode* (*method)(LinkedList L, void* e)) {
    LNode* find;
    int* in;
    char* ch ;
    float* ft ;
    printf("请输入想要查找的结点的值\n");

        if(type==1){
            in = (int *)malloc(sizeof(int));
            while(!scanf("%d",in))
          {
            fflush(stdin);
            printf("\n输入错误，请重新输入:\n");
          }

                find =method(head,in);


        }
        if(type==2){
            ch = (char*)malloc(sizeof(char)*100);
            while(!scanf("%s",ch))
          {
           fflush(stdin);
           printf("\n输入错误，请重新输入:\n");
        }

                find =method(head,ch);


        }
        if(type==3){
            ft = (float*)malloc(sizeof(float)) ;
            while(!scanf("%f",ft))
            {
            fflush(stdin);
         printf("\n输入错误，请重新输入:\n");
            }

            find =method(head,ft);}


        if(find!=NULL){
            printf("已经找到了该结点！\n");
        }else{
            printf("没有该结点，请重新输入\n");
        }

    return find;
}
