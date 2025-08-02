#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

typedef int ElemType;
typedef struct LNode{  //��������ʽ�ṹ�����Ķ���
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//��ͷ��������

typedef struct LISTNode{
    struct {
        char name[30];
        LinkList L;
    };
    struct LISTNode *next;
}LISTNode, *LISTS;

status InitList(LinkList &L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L,int i,ElemType &e);
status LocateElem(LinkList L,ElemType e);
status PriorElem(LinkList L,ElemType e,ElemType &pre);
status NextElem(LinkList L,ElemType e,ElemType &next);
status ListInsert(LinkList &L,int i,ElemType e);
status ListDelete(LinkList &L,int i,ElemType &e);
status ListTraverse(LinkList L);
status SaveList(LinkList L,char FileName[]);
status LoadList(LinkList &L,char FileName[]);
status reverseList(LinkList &L);
status RemoveNthFromEnd(LinkList &L, int n);
void swap_data(LNode* &s, LNode* &p);
status sortList(LinkList &L);
int Multi_LinearTable_management();
status AddList(LISTS &Lists, char ListName[]);
status RemoveList(LISTS &List, char ListName[]);
int LocateList(LISTS Lists, char ListName[], ...);

int main(void){
    printf("*************************************************\n");
    printf("*                   WELCOME                     *\n");
    printf("*              author: Zhou Yujie               *\n");
    printf("*************************************************\n");

    LinkList L;
    L = NULL;
    int op = -1;
    while(op){
        printf("\n\n");
        printf("MENU\n");
        printf("--------------------------------------------------\n");
        printf("|    1.InitList              9.NextEelem         |\n");
        printf("|    2.DestroyList           10.ListInsert       |\n");
        printf("|    3.ClearList             11.ListDelete       |\n");
        printf("|    4.ListEmpty             12.ListTrabverse    |\n");
        printf("|    5.ListLength            13.SaveList         |\n");
        printf("|    6.GetElem               14.LoadList         |\n");
        printf("|    7.LocateElem                                |\n");
        printf("|    8.PriorElem                                 |\n");
        printf("|    0.exit                                      |\n");
        printf("--------------------------------------------------\n");
        printf("|ADDITIONAL:                                     |\n");
        printf("|    15.reverseList         17.sortList          |\n");
        printf("|    16.RemoveNthFromEnd    18.Multi-linear table|\n");
        printf("--------------------------------------------------\n");
        printf("������ѡ��[0-18]:");
        scanf("%d", &op);

        int states = 0;
        enum st{
            EXIT = 0, INIT_LIST = 1, DESTROY_LIST, CLEAR_LIST, LIST_EMPTY, LIST_LENGTH, GET_ELEM, LOCATE_ELEM,
        PRIOR_ELEM, NEXT_ELEM, LIST_INSERT, LIST_DELETE, LIST_TRABVERSE, SAVE_LIST, LOAD_LIST, REVERSE_LIST,
        REMOVE_NTH_FROM_END, SORT_LIST, MULT_LINEAR_TABLE
        };
        int e = 0;
        int pos = 0;
        char name[30];
        switch(op){
            case EXIT:
                break;
            case INIT_LIST:
                printf("\n");
                states = InitList(L);
                if(states == OK)
                    printf("InitList: Success!\n");
                else if(states == INFEASIBLE){
                    printf("InitList: ERROR!\n");
                    printf("���Ա��Ѵ���.\n");
                }
                break;
            case DESTROY_LIST:
                printf("\n");
                states = DestroyList(L);
                if(states == OK)
                    printf("DestroyList: Success!\n");
                else if(states == INFEASIBLE){
                    printf("DestroyList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                break;
            case CLEAR_LIST:
                printf("\n");
                states = ClearList(L);
                if(states == OK)
                    printf("ClearList: Success!\n");
                else if(states == INFEASIBLE){
                    printf("ClearList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                break;
            case LIST_EMPTY:
                printf("\n");
                states = ListEmpty(L);
                if(states == INFEASIBLE){
                    printf("ListEmpty: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == TRUE)
                    printf("���Ա�Ϊ��.\n");
                else
                    printf("���Ա�Ϊ��.\n");
                break;
            case LIST_LENGTH:
                printf("\n");
                states = ListLength(L);
                if(states == INFEASIBLE){
                    printf("ListLength: ERROR!.\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("���Ա���Ϊ%d.\n", states);
                break;
            case GET_ELEM:
                states = ListLength(L);
                if(states == INFEASIBLE){
                    printf("\nGetElem: ERROR!.\n");
                    printf("���Ա�����.\n");
                }
                else if(states == 0){
                    printf("���Ա���Ԫ��.\n");
                }
                else{
                    printf("\n����������鿴��Ԫ�ص�λ��.\n");
                    printf("λ�õķ�Χ�� 1-%d ��.\n", states);
                    scanf("%d", &pos);
                    states = GetElem(L, pos, e);
                    if(states == ERROR){
                        printf("GetElem: ERROR!\n");
                        printf("λ�õķ�ΧӦ���� 1-%d.\n", ListLength(L));
                    }
                    else
                        printf("��%d��Ԫ��Ϊ%d.\n", pos, e);
                }
                break;
            case LOCATE_ELEM:
                printf("\n");
                printf("����������鿴��Ԫ�أ�");
                scanf("%d", &e);
                states = LocateElem(L, e);
                if(states == INFEASIBLE){
                    printf("LocateElem: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR)
                    printf("Ԫ�ز�����.\n");
                else
                    printf("Ԫ��%d�ڱ��е�%d��λ��.\n", e, states);
                break;
            case PRIOR_ELEM:
                printf("\n");
                printf("������Ԫ�أ�");
                scanf("%d", &pos);
                states = PriorElem(L, pos, e);
                if(states == INFEASIBLE){
                    printf("PriorElem: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("LocateElem: ERROR!\n");
                    printf("ǰ��Ԫ�ز�����.\n");
                }
                else
                    printf("ǰ��Ԫ��Ϊ%d.\n", e);
                break;
            case NEXT_ELEM:
                printf("\n");
                printf("������Ԫ�أ�");
                scanf("%d", &pos);
                states = NextElem(L, pos, e);
                if(states == INFEASIBLE){
                    printf("NextElem: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("NextElem: ERROR!\n");
                    printf("���Ԫ�ز�����.\n");
                }
                else
                    printf("���Ԫ��Ϊ%d.\n", e);
                break;
            case LIST_INSERT:
                printf("\n");
                printf("��������������λ�ú�Ԫ�أ�");
                scanf("%d%d", &pos, &e);
                states = ListInsert(L, pos, e);
                if(states == INFEASIBLE){
                    printf("ListInsert: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("ListInsert: ERROR!\n");
                    printf("����λ�÷Ƿ�!\n");
                }
                else
                    printf("ListInsert: Success!\n");
                break;
            case LIST_DELETE:
                printf("\n");
                printf("����������ɾ����Ԫ�ص�λ�ã�\n");
                scanf("%d", &pos);
                states = ListDelete(L, pos, e);
                if(states == INFEASIBLE){
                    printf("ListDelete: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("ListDelete: ERROR!\n");
                    printf("ɾ��λ�÷Ƿ�!\n");
                }
                else
                    printf("ListDelete: Success!\n");
                break;
            case LIST_TRABVERSE:
                printf("\n");
                states = ListTraverse(L);
                if(states == INFEASIBLE){
                    printf("ListTraverse: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else {
                    if(L->next == NULL)
                        printf("���Ա�Ϊ��.\n");
                    printf("ListTraverse: Success!\n");
                }
                break;
            case SAVE_LIST:
                printf("\n");
                printf("����1���ļ���������������0ΪĬ������.\n");
                scanf("%d", &states);
                if(states == 1){
                    scanf("%s", name);
                    states = SaveList(L, name);
                    if(states == INFEASIBLE){
                        printf("SaveList: ERROR!\n");
                        printf("���Ա�����.\n");
                    }
                    else if(states == ERROR){
                        printf("SaveList: ERROR!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveList: Success!\n");
                }
                else if(states == 0){
                    states = SaveList(L, "save.dat");
                    if(states == INFEASIBLE){
                        printf("SaveList: ERROR!\n");
                        printf("���Ա�����.\n");
                    }
                    else if(states == ERROR){
                        printf("SaveList: ERROR!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveList: Success!\n");
                }
                else
                    printf("������1��0!\n");
                break;
            case LOAD_LIST:
                printf("\n");
                printf("������������ص��ļ�����.\n");
                scanf("%s", name);
                states = LoadList(L, name);
                if(states == INFEASIBLE){
                    printf("LoadList: ERROR!\n");
                    printf("���Ա��Ѵ���.\n");
                }
                else if(states == ERROR){
                    printf("LoadList: ERROR!\n");
                    printf("�򲻿��ļ�!\n");
                }
                else
                    printf("LoadList: Success!\n");
                break;
            case REVERSE_LIST:
                printf("\n");
                states = reverseList(L);
                if(states == INFEASIBLE){
                    printf("reverseList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("reverseList: Success!\n");
                break;
            case SORT_LIST:
                printf("\n");
                states = sortList(L);
                if(states == INFEASIBLE){
                    printf("sortList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("sortList: ERROR!\n");
                    printf("���Ա�Ϊ��.\n");
                }
                else
                    printf("sortList: Success!\n");
                break;
            case REMOVE_NTH_FROM_END:
                printf("\n");
                printf("�����������Ƴ������ڼ���Ԫ��\n");
                scanf("%d", &pos);
                states = RemoveNthFromEnd(L, pos);
                if(states == INFEASIBLE){
                    printf("RemoveNthFromEnd: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("RemoveNthFromEnd: ERROR!\n");
                    printf("ɾ��λ�÷Ƿ�.\n");
                }
                else
                    printf("RemoveNthFromEnd: Success!\n");
                break;
            case MULT_LINEAR_TABLE:
                Multi_LinearTable_management();
                op = -1;
                continue;
            default:
                printf("\n");
                printf("����ѡ��Ӧ����[0-18]�ķ�Χ�ڣ�\n");
                break;
        }
        while(getchar() != '\n');//��տ���̨���ַ��ȷǷ��ַ�
        if(op != 0) op = -1; //��ֹop��δ�ı����ڶ������ʱδ����ֵ��������һ���Ĳ���
    }
    printf("\n\n");
    printf("*************************************************\n");
    printf("*             Welcome back again!               *\n");
    printf("*************************************************\n");
    printf("\n\n");
    system("pause");
    return 0;
}

int Multi_LinearTable_management(){
    LISTS ls;
    ls = (LISTS) malloc(sizeof(LISTNode));
    ls->next = NULL;
    int op = -1;
    while(op){
        printf("\n\n");
        printf("MENU\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+    1.InitList              12.ListTrabverse    +\n");
        printf("+    2.DestroyList           13.SaveList         +\n");
        printf("+    3.ClearList             14.LoadList         +\n");
        printf("+    4.ListEmpty             15.reverseList      +\n");
        printf("+    5.ListLength            16.RemoveNthFromEnd +\n");
        printf("+    6.GetElem               17.sortList         +\n");
        printf("+    7.LocateElem            18.AddList          +\n");
        printf("+    8.PriorElem             19.RemoveList       +\n");
        printf("+    9.NextEelem             20.LocateList       +\n");
        printf("+    10.ListInsert                               +\n");
        printf("+    11.ListDelete                               +\n");
        printf("+    0.exit                                      +\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("������ѡ��[0-20]:");
        scanf("%d", &op);

        int states = 0;
        enum st{
            EXIT = 0, INIT_LIST = 1, DESTROY_LIST, CLEAR_LIST, LIST_EMPTY, LIST_LENGTH, GET_ELEM, LOCATE_ELEM,
            PRIOR_ELEM, NEXT_ELEM, LIST_INSERT, LIST_DELETE, LIST_TRABVERSE, SAVE_LIST, LOAD_LIST, REVERSE_LIST, REMOVE_NTH_FROM_END,
            SORT_LIST, ADD_LIST, REMOVE_LIST, LOCATE_LIST
        };
        int e = 0;
        int pos = 0;
        char name[30];
        LISTNode *ls_p = NULL;
        int ls_pos = 0;
        switch(op){
            case EXIT:
                break;
            case INIT_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = InitList(ls_p->L);
                if(states == OK)
                    printf("InitList: Success!\n");
                else if(states == INFEASIBLE){
                    printf("InitList: ERROR!\n");
                    printf("���Ա��Ѵ���.\n");
                }
                break;
            case DESTROY_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = DestroyList(ls_p->L);
                if(states == OK)
                    printf("DestroyList: Success!\n");
                else if(states == INFEASIBLE){
                    printf("DestroyList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                break;
            case CLEAR_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = ClearList(ls_p->L);
                if(states == OK)
                    printf("ClearList: Success!\n");
                else if(states == INFEASIBLE){
                    printf("ClearList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                break;
            case LIST_EMPTY:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = ListEmpty(ls_p->L);
                if(states == INFEASIBLE){
                    printf("ListEmpty: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == TRUE)
                    printf("���Ա�Ϊ��.\n");
                else
                    printf("���Ա�Ϊ��.\n");
                break;
            case LIST_LENGTH:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = ListLength(ls_p->L);
                if(states == INFEASIBLE){
                    printf("ListLength: ERROR!.\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("���Ա���Ϊ%d.\n", states);
                break;
            case GET_ELEM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = ListLength(ls_p->L);
                if(states == INFEASIBLE){
                    printf("\nGetElem: ERROR!.\n");
                    printf("���Ա�����.\n");
                }
                else if(states == 0){
                    printf("���Ա���Ԫ��.\n");
                }
                else{
                    printf("\n����������鿴��Ԫ�ص�λ��.\n");
                    printf("λ�õķ�Χ�� 1-%d ��.\n", states);
                    scanf("%d", &pos);
                    states = GetElem(ls_p->L, pos, e);
                    if(states == ERROR){
                        printf("GetElem: ERROR!\n");
                        printf("λ�õķ�ΧӦ���� 1-%d.\n", ListLength(ls_p->L));
                    }
                    else
                        printf("��%d��Ԫ��Ϊ%d.\n", pos, e);
                }
                break;
            case LOCATE_ELEM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("����������鿴��Ԫ�أ�");
                scanf("%d", &e);
                states = LocateElem(ls_p->L, e);
                if(states == INFEASIBLE){
                    printf("LocateElem: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR)
                    printf("Ԫ�ز�����.\n");
                else
                    printf("Ԫ��%d�ڱ��е�%d��λ��.\n", e, states);
                break;
            case PRIOR_ELEM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("������Ԫ�أ�");
                scanf("%d", &pos);
                states = PriorElem(ls_p->L, pos, e);
                if(states == INFEASIBLE){
                    printf("PriorElem: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("LocateElem: ERROR!\n");
                    printf("ǰ��Ԫ�ز�����.\n");
                }
                else
                    printf("ǰ��Ԫ��Ϊ%d.\n", e);
                break;
            case NEXT_ELEM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("������Ԫ�أ�");
                scanf("%d", &pos);
                states = NextElem(ls_p->L, pos, e);
                if(states == INFEASIBLE){
                    printf("NextElem: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("NextElem: ERROR!\n");
                    printf("���Ԫ�ز�����.\n");
                }
                else
                    printf("���Ԫ��Ϊ%d.\n", e);
                break;
            case LIST_INSERT:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("��������������λ�ú�Ԫ�أ�");
                scanf("%d%d", &pos, &e);
                states = ListInsert(ls_p->L, pos, e);
                if(states == INFEASIBLE){
                    printf("ListInsert: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("ListInsert: ERROR!\n");
                    printf("����λ�÷Ƿ�!\n");
                }
                else
                    printf("ListInsert: Success!\n");
                break;
            case LIST_DELETE:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("����������ɾ����Ԫ�ص�λ�ã�\n");
                scanf("%d", &pos);
                states = ListDelete(ls_p->L, pos, e);
                if(states == INFEASIBLE){
                    printf("ListDelete: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("ListDelete: ERROR!\n");
                    printf("ɾ��λ�÷Ƿ�!\n");
                }
                else
                    printf("ListDelete: Success!\n");
                break;
            case LIST_TRABVERSE:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = ListTraverse(ls_p->L);
                if(states == INFEASIBLE){
                    printf("ListTraverse: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else {
                    if(ls_p->L->next == NULL)
                        printf("���Ա�Ϊ��.\n");
                    printf("ListTraverse: Success!\n");
                }
                break;
            case SAVE_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("����1���ļ���������������0ΪĬ������.\n");
                scanf("%d", &states);
                if(states == 1){
                    scanf("%s", name);
                    states = SaveList(ls_p->L, name);
                    if(states == INFEASIBLE){
                        printf("SaveList: ERROR!\n");
                        printf("���Ա�����.\n");
                    }
                    else if(states == ERROR){
                        printf("SaveList: ERROR!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveList: Success!\n");
                }
                else if(states == 0){
                    states = SaveList(ls_p->L, "save.dat");
                    if(states == INFEASIBLE){
                        printf("SaveList: ERROR!\n");
                        printf("���Ա�����.\n");
                    }
                    else if(states == ERROR){
                        printf("SaveList: ERROR!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveList: Success!\n");
                }
                else
                    printf("������1��0!\n");
                break;
            case LOAD_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("������������ص��ļ�����.\n");
                scanf("%s", name);
                states = LoadList(ls_p->L, name);
                if(states == INFEASIBLE){
                    printf("LoadList: ERROR!\n");
                    printf("���Ա��Ѵ���.\n");
                }
                else if(states == ERROR){
                    printf("LoadList: ERROR!\n");
                    printf("�򲻿��ļ�!\n");
                }
                else
                    printf("LoadList: Success!\n");
                break;
            case REVERSE_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = reverseList(ls_p->L);
                if(states == INFEASIBLE){
                    printf("reverseList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("reverseList: Success!\n");
                break;
            case SORT_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = sortList(ls_p->L);
                if(states == INFEASIBLE){
                    printf("sortList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("sortList: ERROR!\n");
                    printf("���Ա�Ϊ��.\n");
                }
                else
                    printf("sortList: Success!\n");
                break;
            case REMOVE_NTH_FROM_END:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name, &ls_p);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("�����������Ƴ������ڼ���Ԫ��\n");
                scanf("%d", &pos);
                states = RemoveNthFromEnd(ls_p->L, pos);
                if(states == INFEASIBLE){
                    printf("RemoveNthFromEnd: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else if(states == ERROR){
                    printf("RemoveNthFromEnd: ERROR!\n");
                    printf("ɾ��λ�÷Ƿ�.\n");
                }
                else
                    printf("RemoveNthFromEnd: Success!\n");
                break;
            case ADD_LIST:
                printf("\n");
                printf("�����������ı���(25��Ӣ���ַ�����):");
                scanf("%s", name);
                states = AddList(ls, name);
                if(states == ERROR){
                    printf("AddList: ERROR!\n");
                    printf("�����ַ���������.\n");
                }
                else
                    printf("AddList: Success!\n");
                break;
            case REMOVE_LIST:
                printf("\n");
                printf("������Ҫɾ���ı�����");
                scanf("%s", name);
                states = RemoveList(ls, name);
                if(states == ERROR){
                    printf("RemoveList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("RemoveList: Success!\n");
                break;
            case LOCATE_LIST:
                printf("\n");
                printf("������Ҫ���ҵı�����");
                scanf("%s", name);
                states = LocateList(ls, name);
                if(!states){
                    printf("LocateList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("�������ҵ����Ա��ڵ�%d��λ��.\n", states);
                break;
            default:
                printf("\n");
                printf("����ѡ��Ӧ����[0-20]�ķ�Χ�ڣ�\n");
                break;
        }
        while(getchar() != '\n');//��տ���̨���ַ��ȷǷ��ַ�
        if(op != 0) op = -1; //��ֹop��δ�ı����ڶ������ʱδ����ֵ��������һ���Ĳ���
    }
    return 0;
}

status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    if(L)
        return INFEASIBLE;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}

status DestroyList(LinkList &L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    LNode *s = L;
    while(L->next != NULL){
        L = L->next;
        free(s);
        s = L;
    }
    free(s);
    L = NULL;
    s = NULL;
    return OK;
}

status ClearList(LinkList &L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    LNode *s = L->next;
    while(L->next != NULL){
        L->next = s->next;
        free(s);
        s = L->next;
    }
    return OK;
}

status ListEmpty(LinkList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    if(L->next == NULL)
        return TRUE;
    return FALSE;
}

int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    int len = 0;
    LNode *s = L;
    while(s->next != NULL){
        s = s->next;
        len ++;
    }
    return len;
}

status GetElem(LinkList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    if(i < 1)
        return ERROR;
    int pos = 0;
    LNode *s = L;
    while(pos < i && s){
        s = s->next;
        pos ++;
    }
    if(!s)
        return ERROR;
    e = s->data;
    return OK;
}

status LocateElem(LinkList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    int pos = 0;
    LNode *s = L;
    while(s && s->data != e){
        s = s->next;
        pos ++;
    }
    if(!s)
        return ERROR;
    return pos;
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    LNode *s = L;
    if(s->next == NULL || s->next->data == e)
        return ERROR;
    while(s->next != NULL){
        if(s->next->data == e){
            pre = s->data;
            return OK;
        }
        s = s->next;
    }
    return ERROR;
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    LNode *s = L;
    if(s->next == NULL)
        return ERROR;
    s = s->next;
    while(s->next != NULL){
        if(s->data == e){
            next = s->next->data;
            return OK;
        }
        s = s->next;
    }
    return ERROR;
}

status ListInsert(LinkList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    if(i < 1)
        return ERROR;
    int pos = 0;
    LNode *s = L;
    while(s && pos < i - 1){
        s = s->next;
        pos ++;
    }
    if(!s)
        return ERROR;
    LNode *p = (LNode *) malloc(sizeof(LNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return OK;
}

status ListDelete(LinkList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    if(i < 1)
        return ERROR;
    int pos = 0;
    LNode *s = L;
    while(s && pos < i - 1){
        s = s->next;
        pos ++;
    }
    if(!s)
        return ERROR;
    if(!s->next)
        return ERROR;
    LNode *p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return OK;
}

status ListTraverse(LinkList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    LNode *s = L->next;
    while(s){
        printf("%d", s->data);
        printf("%c",(s->next ? ' ' : '\n'));
        s = s->next;
    }
    return OK;
}

status SaveList(LinkList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    if(!L)
        return INFEASIBLE;
    FILE *fp = fopen(FileName, "w");
    if(!fp)
        return ERROR;
    LNode *s = L->next;
    while(s){
        fprintf(fp, "%d", s->data);
        fprintf(fp, "%c", (s->next ? ' ' : '\n'));
        s = s->next;
    }
    fclose(fp);
    return OK;
}

status LoadList(LinkList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if(L)
        return INFEASIBLE;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    FILE *fp = fopen(FileName, "r");
    if(!fp)
        return ERROR;
    ElemType data;
    LNode *cur, *pre;
    pre = L;
    while(fscanf(fp, "%d", &data) != EOF){
        cur = (LNode*) malloc(sizeof(LNode));
        cur->data = data;
        pre->next = cur;
        pre = cur;
    }
    cur->next = NULL;
    fclose(fp);
    return OK;
}

status reverseList(LinkList &L)
{
    if(!L)
        return INFEASIBLE;
    if(!L->next)
        return OK;
    LinkList rev = (LinkList) malloc(sizeof(LNode));
    LNode *L_cur;
    L_cur = L->next;
    rev->next = NULL;
    while(L_cur != NULL){
        L->next = L_cur->next;
        L_cur->next = rev->next;
        rev->next = L_cur;
        L_cur = L->next;
    }
    L->next = rev->next;
    free(rev);
    rev = NULL;
    L_cur = NULL;
    return OK;
}

status RemoveNthFromEnd(LinkList &L, int n)
{
    if(!L)
        return INFEASIBLE;
    if(!L->next || n < 1)
        return ERROR;
    int cnt = 0;
    LNode *pre, *cur;
    pre = cur = L;
    while(cnt < n && pre->next != NULL){
        pre = pre->next;
        cnt ++;
    }
    if(cnt < n)
        return ERROR;
    while(pre->next != NULL){
        pre = pre->next;
        cur = cur->next;
    }
    LNode *s = cur->next;
    cur->next = s->next;
    free(s);
    s = NULL;
    return OK;
}

void swap_data(LNode* &s, LNode* &p)
{
    int tmp;
    tmp = s->data;
    s->data = p->data;
    p->data = tmp;
}

status sortList(LinkList &L)
{
    if(!L)
        return INFEASIBLE;
    if(L->next == NULL)
        return ERROR;
    LNode *s, *p;
    s = L->next;
    p = L->next;
    for(s; s != NULL; s = s->next){
        for(p = s->next; p != NULL; p = p->next){
            if(s->data > p->data)
                swap_data(s, p);
        }
    }
    return OK;
}

status AddList(LISTS &Lists, char ListName[])
{
    LISTNode *s = (LISTNode *) malloc(sizeof(LISTNode));
    int i = 0;
    while(ListName[i]) i ++;
    if(i >= 30)
        return ERROR;
    strcpy(s->name, ListName);
    s->L = NULL;
    InitList(s->L);
    s->next = Lists->next;
    Lists->next = s;
    return OK;
}

status RemoveList(LISTS &List, char ListName[])
{
    if(!List->next)
        return ERROR;
    LISTNode *cur, *nxt;
    cur = List;
    nxt = cur->next;
    while(nxt && strcmp(nxt->name, ListName) != 0){
        cur = cur->next;
        nxt = nxt->next;
    }
    if(nxt == NULL)
        return ERROR;
    cur->next = nxt->next;
    free(nxt);
    nxt = NULL;
    return OK;
}

int LocateList(LISTS Lists, char ListName[], ...)
{
    if(!Lists->next)
        return 0;
    int pos = 1;
    LISTNode *cur = Lists->next;
    while(cur && strcmp(cur->name, ListName) != 0){
        cur = cur->next;
        pos ++;
    }
    if(!cur)
        return 0;
    va_list ap;
    va_start(ap, 1);
    LISTNode **s = va_arg(ap, LISTNode**);
    if(s){
        *s = cur;
        va_end(ap);
    }
    return pos;
}
