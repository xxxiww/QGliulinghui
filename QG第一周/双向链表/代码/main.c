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
				case 1://��ʼ������
					system("cls");
					result1=InitList_DuL(&head);
					if(result1 == SUCCESS){
                        printf("�����ɹ�");

					}else{
					printf("����ʧ�ܣ�");}


					system("pause");
	                system("cls");
	                break;
                case 2:
	            	system("cls");
	            	printf("����������β�������:\n");
                    while(!scanf("%d",&element))
                  {
                         fflush(stdin);
                        printf("\n�����������������:\n");
                  }
                    result2 = addNode(head, element);
	            	if(result2==SUCCESS){
                        printf("β��ɹ�����\n");
					}else{
					    printf("β��ʧ�ܣ���\n");
					  }
                    system("pause");
                    system("cls");
                    break;
	            case 3:
	            	system("cls");
	            	DestroyList_DuL(&head);
	            	printf("�ݻٳɹ�����\n");
                    system("pause");
                    system("cls");
                    break;
                case 4:
	            	system("cls");
                    find = matchNode(head, SearchList);
                    if(find==NULL){
                        printf("����Ϊ�գ�\n");
                    }
                    else{
                    printf("�봴��һ�����,���������븳���������ֵ\n");
                    while(!scanf("%d",&h))
                    {
                    fflush(stdin);
                    printf("\n�����������������:\n");
                    }
                    newNode =createNewnode(h);
                    if(newNode!=NULL){
                    printf("�������ɹ�");}
                    else{
                       printf("�������ʧ��");
                    }
                   result4 =  InsertBeforeList_DuL(find, newNode);
                   if(result4==SUCCESS){
                    printf("����ɹ�\n");
                   }else{
                      printf("���벻�ɹ�\n");}}
                    system("pause");
                    system("cls");
                    break;
                case 5:
	            	system("cls");
	            	find = matchNode(head, SearchList);
                    printf("�봴��һ�����,���������븳���������ֵ\n");
                    while(!scanf("%d",&h))
                    {
                    fflush(stdin);
                    printf("\n�����������������:\n");
                    }
                    newNode5 =createNewnode(h);
                    if(newNode5!=NULL){
                    printf("�������ɹ�");}
                    else{
                       printf("�������ʧ��");
                    }
                   result5 = InsertAfterList_DuL(find, newNode5);
                   if(result5==SUCCESS){
                    printf("����ɹ�\n");
                   }else{
                      printf("���벻�ɹ�\n");}
                    system("pause");
                    system("cls");
                    break;
                case 6:
	            	system("cls");
	            	ElemType e ;
					find = matchNode(head, SearchList);
					result6 =DeleteList_DuL(find, &e);
					if(result6==SUCCESS){
                        printf("�ɹ�ɾ��p����Ľ�㣡��ֵΪ��%d",e);

					}else{
					printf("û�гɹ���");}
                    system("pause");
                    system("cls");
                    break;
                case 7:
	            	system("cls");
	            	printf("��ʼ����\n");
					TraverseList_DuL(head,Print_int);
                    printf("�������\n");
                    system("pause");
                    system("cls");
                    break;
	            default:
	            	printf("�Ƿ����룬����������\n");
	            	system("pause");
	                system("cls");
	                break;
			}

	    }


}
