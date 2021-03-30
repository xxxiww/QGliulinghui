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
    type = SelectMenu_dataType(); //ѡ�������������������
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
    LNode* head = NULL; //���������ȳ�ʼ��ͷָ��
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
                     printf("�����ɹ�\n");}
                    else{
                     printf("����ʧ��\n");}

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
                    printf("�봴��һ�����\n");
                    LNode* newNode = (LNode*)malloc(sizeof(LNode));
                    if(type==1){
                        in = (int *)malloc(sizeof(int));
                        flag=  scanf("%d",in);
                        if(flag=1){

                            newNode->data = in;
                        }
                        else{
                            printf("������Ĳ���int�����ݣ�\n");

                        }

                    }
                    if(type==2){
                       ch = (char*)malloc(sizeof(char)*100);
                        flag=  scanf("%s",ch);
                        if(flag=1){
                            newNode->data = ch;
                        }
                        else{
                            printf("������Ĳ���char�����ݣ�\n");

                        }

                    }
                    if(type==3){
                        ft = (float*)malloc(sizeof(float)) ;
                        flag=  scanf("%f",ft);
                        if(flag=1){
                            newNode->data = ft;

                        }
                        else{
                            printf("������Ĳ���float�����ݣ�\n");

                        }

                    }
                    printf("�������ɹ�");
                   Status result3 =  InsertList(find, newNode);
                   if(result3==SUCCESS){
                    printf("����ɹ�\n");
                   }else{
                      printf("���벻�ɹ�\n");}
                    system("pause");
	                system("cls");
					break;
                case 4:
					system("cls");
					void *e;
					find = matchNode(head, SearchList);
					Status result4 = DeleteList(find, e);
					if(result4==SUCCESS){
                        printf("�ɹ�ɾ������ӡ��һ������ֵ");
					}else{
					printf("û�гɹ���");}
					system("pause");
	                system("cls");
					break;
                case 5:
					system("cls");
					printf("��ʼ����\n");
					TraverseList(head,dataPrint);
                    printf("�������\n");
					system("pause");
	                system("cls");
					break;

                case 6:
					system("cls");
                    Status result7 =  ReverseList(&head);
					if (result7 == SUCCESS) {
                     printf("����ת�ɹ�\n");}
                    else{
                     printf("����û�з�ת�ɹ�\n");}
					system("pause");
	                system("cls");
					break;
                case 7:
					system("cls");
					Status result8 = IsLoopList(head);
					if (result8 == SUCCESS) {
                     printf("����ѭ��\n");}
                    else{
                     printf("����ѭ��\n");}
					system("pause");
	                system("cls");
					break;
                case 8:
					system("cls");
					head = ReverseEvenList(head);
					printf("��ż��㽻���ɹ���ͷָ���Ѿ�ˢ�£�");
					system("pause");
	                system("cls");
					break;
                case 9:
					system("cls");
					LNode *midNode =FindMidNode(head);
					printf("�ҵ����м��㣬����ֵΪ��\n");
					dataPrint(midNode->data);
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
