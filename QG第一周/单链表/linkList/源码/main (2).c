#include<stdio.h>
#include"linkedList.h"
#include<stdlib.h>


int main(){
    int choice;
    LNode* find;
    int flag;
    int* in;
    char* ch ;
    float* ft ;

    choice = 1;
    type = SelectMenu_dataType(); //选择链表里面的数据类型
    if(type==1){
        dataPrint=Print_int;
    }
    else if(type==2){
        dataPrint=Print_char;
    }
    else if(type==3){
        dataPrint=Print_float;
    }
    system("cls");
    LNode* head = NULL; //在主函数先初始化头指针
    while(choice)
       {
	        choice = SelectMenu_function();
	        if(choice==0) break;
			switch (choice)
			{
				case 1:
					system("cls");
					Status result = InitList(&head);
					if (result == SUCCESS) {
                     printf("操作成功\n");}
                    else{
                     printf("操作失败\n");}

					system("pause");
	                system("cls");
	                break;
	            case 2:
	            	system("cls");
	            	DestroyList(&head);
                    system("pause");
                    system("cls");
                    break;

				case 3:
					system("cls");
                    find = matchNode(head, SearchList);
                    printf("请创造一个结点\n");
                    LNode* newNode = (LNode*)malloc(sizeof(LNode));
                    if(type==1){
                        in = (int *)malloc(sizeof(int));
                        flag=  scanf("%d",in);
                        if(flag=1){

                            newNode->data = in;
                        }
                        else{
                            printf("你输入的不是int型数据！\n");

                        }

                    }
                    if(type==2){
                       ch = (char*)malloc(sizeof(char)*100);
                        flag=  scanf("%s",ch);
                        if(flag=1){
                            newNode->data = ch;
                        }
                        else{
                            printf("你输入的不是char型数据！\n");

                        }

                    }
                    if(type==3){
                        ft = (float*)malloc(sizeof(float)) ;
                        flag=  scanf("%f",ft);
                        if(flag=1){
                            newNode->data = ft;

                        }
                        else{
                            printf("你输入的不是float型数据！\n");

                        }

                    }
                    printf("创建结点成功");
                   Status result3 =  InsertList(find, newNode);
                   if(result3==SUCCESS){
                    printf("插入成功\n");
                   }else{
                      printf("插入不成功\n");}
                    system("pause");
	                system("cls");
					break;
                case 4:
					system("cls");
					void *e;
					find = matchNode(head, SearchList);
					Status result4 = DeleteList(find, e);
					if(result4==SUCCESS){
                        printf("成功删除并打印下一个结点的值");
					}else{
					printf("没有成功！");}
					system("pause");
	                system("cls");
					break;
                case 5:
					system("cls");
					printf("开始遍历\n");
					TraverseList(head,dataPrint);
                    printf("遍历完成\n");
					system("pause");
	                system("cls");
					break;

                case 6:
					system("cls");
                    Status result7 =  ReverseList(&head);
					if (result7 == SUCCESS) {
                     printf("链表反转成功\n");}
                    else{
                     printf("链表没有反转成功\n");}
					system("pause");
	                system("cls");
					break;
                case 7:
					system("cls");
					Status result8 = IsLoopList(head);
					if (result8 == SUCCESS) {
                     printf("链表循环\n");}
                    else{
                     printf("链表不循环\n");}
					system("pause");
	                system("cls");
					break;
                case 8:
					system("cls");
					head = ReverseEvenList(head);
					printf("奇偶结点交换成功，头指针已经刷新！");
					system("pause");
	                system("cls");
					break;
                case 9:
					system("cls");
					LNode *midNode =FindMidNode(head);
					printf("找到了中间结点，它的值为：\n");
					dataPrint(midNode->data);
					system("pause");
	                system("cls");
					break;

	            default:
	            	printf("非法输入，请重新输入\n");
	            	system("pause");
	                system("cls");
	                break;
			}

	    }
}
