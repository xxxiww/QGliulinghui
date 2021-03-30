#include <stdio.h>
#include <stdlib.h>
#include"testlink.h"

int main()
{
    int choice = 1;
    int h;
    int element;
    DuLNode* head = NULL;
    DuLNode* find = NULL;
     Status result1;
    Status result2;
    Status result4;
    Status result5;
    Status result6;
    DuLNode* newNode;
    DuLNode* newNode5;
    while(choice)
       {
	        choice = SelectMenu_function();

	        if(choice==0) break;
			switch (choice)
			{
				case 1://初始化链表
					system("cls");
					result1=InitList_DuL(&head);
					if(result1 == SUCCESS){
                        printf("创建成功");

					}else{
					printf("创建失败！");}


					system("pause");
	                system("cls");
	                break;
                case 2:
	            	system("cls");
	            	printf("请输入你想尾插的数字:\n");
                    while(!scanf("%d",&element))
                  {
                         fflush(stdin);
                        printf("\n输入错误，请重新输入:\n");
                  }
                    result2 = addNode(head, element);
	            	if(result2==SUCCESS){
                        printf("尾插成功！！\n");
					}else{
					    printf("尾插失败！！\n");
					  }
                    system("pause");
                    system("cls");
                    break;
	            case 3:
	            	system("cls");
	            	DestroyList_DuL(&head);
	            	printf("摧毁成功！！\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
	            	system("cls");
                    find = matchNode(head, SearchList);
                    if(find==NULL){
                        printf("链表为空！\n");
                    }
                    else{
                    printf("请创造一个结点,请输入你想赋给这个结点的值\n");
                    while(!scanf("%d",&h))
                    {
                    fflush(stdin);
                    printf("\n输入错误，请重新输入:\n");
                    }
                    newNode =createNewnode(h);
                    if(newNode!=NULL){
                    printf("创建结点成功");}
                    else{
                       printf("创建结点失败");
                    }
                   result4 =  InsertBeforeList_DuL(find, newNode);
                   if(result4==SUCCESS){
                    printf("插入成功\n");
                   }else{
                      printf("插入不成功\n");}}
                    system("pause");
                    system("cls");
                    break;
                case 5:
	            	system("cls");
	            	find = matchNode(head, SearchList);
                    printf("请创造一个结点,请输入你想赋给这个结点的值\n");
                    while(!scanf("%d",&h))
                    {
                    fflush(stdin);
                    printf("\n输入错误，请重新输入:\n");
                    }
                    newNode5 =createNewnode(h);
                    if(newNode5!=NULL){
                    printf("创建结点成功");}
                    else{
                       printf("创建结点失败");
                    }
                   result5 = InsertAfterList_DuL(find, newNode5);
                   if(result5==SUCCESS){
                    printf("插入成功\n");
                   }else{
                      printf("插入不成功\n");}
                    system("pause");
                    system("cls");
                    break;
                case 6:
	            	system("cls");
	            	ElemType e ;
					find = matchNode(head, SearchList);
					result6 =DeleteList_DuL(find, &e);
					if(result6==SUCCESS){
                        printf("成功删除p后面的结点！其值为：%d",e);

					}else{
					printf("没有成功！");}
                    system("pause");
                    system("cls");
                    break;
                case 7:
	            	system("cls");
	            	printf("开始遍历\n");
					TraverseList_DuL(head,Print_int);
                    printf("遍历完成\n");
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
