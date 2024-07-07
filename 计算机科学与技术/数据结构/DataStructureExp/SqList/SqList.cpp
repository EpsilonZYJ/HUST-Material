/*Linear Table On Sequence Structure*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;   //�������Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//˳���ṹ����
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

typedef struct{  //���Ա�Ĺ������
    struct {
        char name[30];
        SqList L;
    } elem[10];
    int length;
    int listsize;
}LISTS;

status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList& L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L,int i,ElemType &e);
int LocateElem(SqList L,ElemType e);
status PriorElem(SqList L,ElemType e,ElemType &pre);
status NextElem(SqList L,ElemType e,ElemType &next);
status ListInsert(SqList &L,int i,ElemType e);
status ListDelete(SqList &L,int i,ElemType &e);
status ListTraverse(SqList L);
status SaveList(SqList L,char FileName[]);
status LoadList(SqList &L,char FileName[]);
status AddList(LISTS &Lists,char ListName[]);
status RemoveList(LISTS &Lists,char ListName[]);
int LocateList(LISTS Lists,char ListName[]);
int Multi_LinearTable_management();
status sortList(SqList &L);
int SubArrayNum(SqList L, int k);
int MaxSubArray(SqList L);

int main(void)
{
    SqList L;
    L.elem = NULL;
    printf("*************************************************\n");
    printf("*                   WELCOME                     *\n");
    printf("*              author: Zhou Yujie               *\n");
    printf("*************************************************\n");

    int op = -1;
    while(op){
        printf("\n\n");
        printf("MENU\n");
        printf("-------------------------------------------------\n");
        printf("|    1.InitList              9.NextElem         |\n");
        printf("|    2.DestroyList           10.ListInsert      |\n");
        printf("|    3.ClearList             11.ListDelete      |\n");
        printf("|    4.ListEmpty             12.ListTraverse    |\n");
        printf("|    5.ListLength            13.SaveList        |\n");
        printf("|    6.GetElem               14.LoadList        |\n");
        printf("|    7.LocateElem            15.Multi-linear    |\n");
        printf("|    8.PriorElem                table           |\n");
        printf("|    0.exit                                     |\n");
        printf("-------------------------------------------------\n");
        printf("|ADDITIONAL:                                    |\n");
        printf("|    16.sortList             17.SubArrayNum     |\n");
        printf("|    18.MaxSubArray                             |\n");
        printf("-------------------------------------------------\n");
        printf("������ѡ��[0-18]:");
        scanf("%d", &op);
        int states = 0;
        enum st{EXIT = 0, INIT_LIST = 1, DESTROY_LIST, CLEAR_LIST, LIST_EMPTY, LIST_LENGTH, GET_ELEM, LOCATE_ELEM, PRIOR_ELEM,
            NEXT_ELEM, LIST_INSERT, LIST_DELETE, LIST_TRABVERSE, SAVE_LIST, LOAD_LIST, MULTI_TABLLE, SORT_LIST, SUB_ARRAY_NUM, MAX_SUB_ARRAY};
        int e = 0;
        int pos = 0;
        char name[30];
        int k;
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
                else if(states == 0)
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
                    if(L.length == 0)
                        printf("�����Ա�.\n");
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
            case MULTI_TABLLE:
                Multi_LinearTable_management();
                op = -1;
                continue;
            case SORT_LIST:
                printf("\n");
                states = sortList(L);
                if(states == INFEASIBLE){
                    printf("sortList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("sortList: Success!\n");
                break;
            case SUB_ARRAY_NUM:
                printf("\n");
                printf("������������ĺ�K��");
                scanf("%d", &k);
                states = SubArrayNum(L, k);
                if(states == INFEASIBLE){
                    printf("SubArrayNum: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else{
                    printf("��%d����Ϊ%d�������顣\n", states, k);
                    printf("SubArrayNum: Success!\n");
                }
                break;
            case MAX_SUB_ARRAY:
                printf("\n");
                states = MaxSubArray(L);
                if (states == INFEASIBLE){
                    printf("MaxSubArray: ERROR!\n");
                    printf("���Ա����ڻ����Ա�Ϊ��.\n");
                }
                else{
                    printf("��������������Ϊ%d.\n", states);
                    printf("MaxSubArray: Success!\n");
                }
                break;
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

int Multi_LinearTable_management() {
    int op = -1;
    LISTS ls;
    ls.length = 0;
    ls.listsize = 0;
    while (op) {
        printf("\n\n");
        printf("MENU-�����Ա����\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+    0.exit                  9.NextElem         +\n");
        printf("+    1.InitList              10.ListInsert      +\n");
        printf("+    2.DestroyList           11.ListDelete      +\n");
        printf("+    3.ClearList             12.ListTraverse    +\n");
        printf("+    4.ListEmpty             13.SaveList        +\n");
        printf("+    5.ListLength            14.LoadList        +\n");
        printf("+    6.GetElem               15.AddList         +\n");
        printf("+    7.LocateElem            16.RemoveList      +\n");
        printf("+    8.PriorElem             17.LocateList      +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+ADDITIONAL:                                    +\n");
        printf("+    18.sortList             19.SubArrayNum     +\n");
        printf("+    20.MaxSubArray                             +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("������ѡ��[0-20]:");
        scanf("%d", &op);
        int states = 0;
        int k = 0;
        enum st {
            EXIT = 0,
            INIT_LIST = 1,
            DESTROY_LIST,
            CLEAR_LIST,
            LIST_EMPTY,
            LIST_LENGTH,
            GET_ELEM,
            LOCATE_ELEM,
            PRIOR_ELEM,
            NEXT_ELEM,
            LIST_INSERT,
            LIST_DELETE,
            LIST_TRABVERSE,
            SAVE_LIST,
            LOAD_LIST,
            ADD_LIST,
            REMOVE_LIST,
            LOCATE_LIST,
            SORT_LIST,
            SUB_ARRAY_NUM,
            MAX_SUB_ARRAY
        };
        int e = 0;
        int pos = 0;
        int ls_pos = 0;
        char name[30];
        switch (op) {
            case EXIT:
                break;
            case INIT_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = InitList(ls.elem[ls_pos - 1].L);
                if (states == OK)
                    printf("InitList: Success!\n");
                else if (states == INFEASIBLE) {
                    printf("InitList: ERROR!\n");
                    printf("���Ա��Ѵ���.\n");
                }
                break;
            case DESTROY_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = DestroyList(ls.elem[ls_pos - 1].L);
                if (states == OK)
                    printf("DestroyList: Success!\n");
                else if (states == INFEASIBLE) {
                    printf("DestroyList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                break;
            case CLEAR_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = ClearList(ls.elem[ls_pos - 1].L);
                if (states == OK)
                    printf("ClearList: Success!\n");
                else if (states == INFEASIBLE) {
                    printf("ClearList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                break;
            case LIST_EMPTY:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = ListEmpty(ls.elem[ls_pos - 1].L);
                if (states == INFEASIBLE) {
                    printf("ListEmpty: ERROR!\n");
                    printf("���Ա�����.\n");
                } else if (states == TRUE)
                    printf("���Ա�Ϊ��.\n");
                else
                    printf("���Ա�Ϊ��.\n");
                break;
            case LIST_LENGTH:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = ListLength(ls.elem[ls_pos - 1].L);
                if (states == INFEASIBLE) {
                    printf("ListLength: ERROR!.\n");
                    printf("���Ա�����.\n");
                } else
                    printf("���Ա���Ϊ%d.\n", states);
                break;
            case GET_ELEM:
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = ListLength(ls.elem[ls_pos - 1].L);
                if (states == INFEASIBLE) {
                    printf("\nGetElem: ERROR!.\n");
                    printf("���Ա�����.\n");
                } else if (states == 0) {
                    printf("���Ա���Ԫ��.\n");
                } else {
                    printf("\n����������鿴��Ԫ�ص�λ��.\n");
                    printf("λ�õķ�Χ�� 1-%d ��.\n", states);
                    scanf("%d", &pos);
                    states = GetElem(ls.elem[ls_pos - 1].L, pos, e);
                    if (states == ERROR) {
                        printf("GetElem: ERROR!\n");
                        printf("λ�õķ�ΧӦ���� 1-%d.\n", ListLength(ls.elem[ls_pos - 1].L));
                    } else
                        printf("��%d��Ԫ��Ϊ%d.\n", pos, e);
                }
                break;
            case LOCATE_ELEM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("����������鿴��Ԫ�أ�");
                scanf("%d", &e);
                states = LocateElem(ls.elem[ls_pos - 1].L, e);
                if (states == INFEASIBLE) {
                    printf("LocateElem: ERROR!\n");
                    printf("���Ա�����.\n");
                } else if (states == 0)
                    printf("Ԫ�ز�����.\n");
                else
                    printf("Ԫ��%d�ڱ��е�%d��λ��.\n", e, states);
                break;
            case PRIOR_ELEM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("������Ԫ�أ�");
                scanf("%d", &pos);
                states = PriorElem(ls.elem[ls_pos - 1].L, pos, e);
                if (states == INFEASIBLE) {
                    printf("PriorElem: ERROR!\n");
                    printf("���Ա�����.\n");
                } else if (states == ERROR) {
                    printf("LocateElem: ERROR!\n");
                    printf("ǰ��Ԫ�ز�����.\n");
                } else
                    printf("ǰ��Ԫ��Ϊ%d.\n", e);
                break;
            case NEXT_ELEM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("������Ԫ�أ�");
                scanf("%d", &pos);
                states = NextElem(ls.elem[ls_pos - 1].L, pos, e);
                if (states == INFEASIBLE) {
                    printf("NextElem: ERROR!\n");
                    printf("���Ա�����.\n");
                } else if (states == ERROR) {
                    printf("NextElem: ERROR!\n");
                    printf("���Ԫ�ز�����.\n");
                } else
                    printf("���Ԫ��Ϊ%d.\n", e);
                break;
            case LIST_INSERT:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("��������������λ�ú�Ԫ�أ�");
                scanf("%d%d", &pos, &e);
                states = ListInsert(ls.elem[ls_pos - 1].L, pos, e);
                if (states == INFEASIBLE) {
                    printf("ListInsert: ERROR!\n");
                    printf("���Ա�����.\n");
                } else if (states == ERROR) {
                    printf("ListInsert: ERROR!\n");
                    printf("����λ�÷Ƿ�!\n");
                } else
                    printf("ListInsert: Success!\n");
                break;
            case LIST_DELETE:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("����������ɾ����Ԫ�ص�λ�ã�\n");
                scanf("%d", &pos);
                states = ListDelete(ls.elem[ls_pos - 1].L, pos, e);
                if (states == INFEASIBLE) {
                    printf("ListDelete: ERROR!\n");
                    printf("���Ա�����.\n");
                } else if (states == ERROR) {
                    printf("ListDelete: ERROR!\n");
                    printf("ɾ��λ�÷Ƿ�!\n");
                } else
                    printf("ListDelete: Success!\n");
                break;
            case LIST_TRABVERSE:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                states = ListTraverse(ls.elem[ls_pos - 1].L);
                if (states == INFEASIBLE) {
                    printf("ListTraverse: ERROR!\n");
                    printf("���Ա�����.\n");
                } else {
                    if(ls.elem[ls_pos - 1].L.length == 0)
                        printf("�����Ա�\n");
                    printf("ListTraverse: Success!\n");
                }
                break;
            case SAVE_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("����1���ļ���������������0ΪĬ������.\n");
                scanf("%d", &states);
                if (states == 1) {
                    scanf("%s", name);
                    states = SaveList(ls.elem[ls_pos - 1].L, name);
                    if (states == INFEASIBLE) {
                        printf("SaveList: ERROR!\n");
                        printf("���Ա�����.\n");
                    } else if (states == ERROR) {
                        printf("SaveList: ERROR!\n");
                        printf("�޷����ļ�!\n");
                    } else
                        printf("SaveList: Success!\n");
                } else if (states == 0) {
                    states = SaveList(ls.elem[ls_pos - 1].L, "save.dat");
                    if (states == INFEASIBLE) {
                        printf("SaveList: ERROR!\n");
                        printf("���Ա�����.\n");
                    } else if (states == ERROR) {
                        printf("SaveList: ERROR!\n");
                        printf("�޷����ļ�!\n");
                    } else
                        printf("SaveList: Success!\n");
                } else
                    printf("������1��0!\n");
                break;
            case LOAD_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("������������ص��ļ�����.\n");
                scanf("%s", name);
                states = LoadList(ls.elem[ls_pos - 1].L, name);
                if (states == INFEASIBLE) {
                    printf("LoadList: ERROR!\n");
                    printf("���Ա��Ѵ���.\n");
                } else if (states == ERROR) {
                    printf("LoadList: ERROR!\n");
                    printf("�򲻿��ļ�!\n");
                }
                else
                    printf("LoadList: Success!\n");
                break;
            case ADD_LIST:
                printf("\n");
                printf("�����������ı���(25��Ӣ���ַ�����)��");
                scanf("%s", name);
                states = AddList(ls, name);
                if(states == OVERFLOW){
                    printf("AddList: ERROR!\n");
                    printf("���������޷������.\n");
                }
                else if(states == ERROR){
                    printf("AddList: ERROR!\n");
                    printf("�����ַ����������ޣ�\n");
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
            case SORT_LIST:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = sortList(ls.elem[ls_pos-1].L);
                if(states == INFEASIBLE){
                    printf("sortList: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else
                    printf("sortList: Success!\n");
                break;
            case SUB_ARRAY_NUM:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                printf("������������ĺ�K��");
                scanf("%d", &k);
                states = SubArrayNum(ls.elem[ls_pos-1].L, k);
                if(states == INFEASIBLE){
                    printf("SubArrayNum: ERROR!\n");
                    printf("���Ա�����.\n");
                }
                else{
                    printf("��%d����Ϊ%d�������顣\n", states, k);
                    printf("SubArrayNum: Success!\n");
                }
                break;
            case MAX_SUB_ARRAY:
                printf("\n");
                printf("��������������ı�����");
                scanf("%s", name);
                ls_pos = LocateList(ls, name);
                if (ls_pos == 0) {
                    printf("���Ա�����");
                    break;
                }
                printf("\n");
                states = MaxSubArray(ls.elem[ls_pos-1].L);
                if (states == INFEASIBLE){
                    printf("MaxSubArray: ERROR!\n");
                    printf("���Ա����ڻ����Ա�Ϊ��.\n");
                }
                else{
                    printf("��������������Ϊ%d.\n", states);
                    printf("MaxSubArray: Success!\n");
                }
                break;
            default:
                printf("\n");
                printf("����ѡ��Ӧ����[0-20]�ķ�Χ�ڣ�\n");
                break;
        }
        while(getchar() != '\n');
        if(op != 0) op = -1;
    }
    return 0;
}

status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�� ���򷵻�INFEASIBLE��
{
    if(L.elem)
        return INFEASIBLE;	//���Ա���ڣ��򷵻�INFEASIBLE
    L.elem = (ElemType*) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if(!L.elem)
        exit(OVERFLOW);	//���벻���ռ䣬��������˳����򲢷���OVERFLOW
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status DestroyList(SqList& L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    L.length = 0;
    L.listsize = 0;
    free(L.elem);
    L.elem = NULL;
    return OK;
}

status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    if(L.length)
        return FALSE;
    return TRUE;
}

status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    return L.length;
}

status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
{
    if(!L.elem)
        return INFEASIBLE;
    for (int i = 0; i < L.length; i++)
    {
        if(L.elem[i] == e)
            return i + 1;
    }
    return 0;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    for (int i = 0; i < L.length; i++)
    {
        if(L.elem[i] == e){
            if(i == 0)
                return ERROR;
            pre = L.elem[i - 1];
            return OK;
        }
    }
    return ERROR;
}

status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    for (int i = 0; i < L.length; i++)
    {
        if(L.elem[i] == e){
            if(i == L.length - 1)
                return ERROR;
            next = L.elem[i + 1];
            return OK;
        }
    }
    return ERROR;
}

status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    if(i < 1 || i > L.length + 1)
        return ERROR;
    if(L.length == L.listsize){
        L.elem = (ElemType*) realloc(L.elem, sizeof(ElemType)*(L.listsize + LISTINCREMENT));
        if(L.elem == NULL)
            exit(OVERFLOW);
        L.listsize += LISTINCREMENT;
    }
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length ++;
    return OK;
}

status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    for (int j = i - 1; j < L.length; j++)
    {
        L.elem[j] = L.elem[j + 1];
    }
    L.length --;
    return OK;
}

status ListTraverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    for (int i = 0; i < L.length; i++)
    {
        printf("%d", L.elem[i]);
        printf("%c", (i == L.length - 1 ? '\n' : ' '));
    }
    return OK;
}

status SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    if(!L.elem)
        return INFEASIBLE;
    FILE *fp = fopen(FileName, "wb");
    if(!fp)
        return ERROR;
    fwrite(L.elem, sizeof(ElemType), L.length, fp);
    fclose(fp);
    return OK;
}

status LoadList(SqList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem)
        return INFEASIBLE;
    FILE *fp = fopen(FileName, "rb");
    if(!fp)
        return ERROR;
    L.elem = (ElemType*) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if(!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    while(fread(&L.elem[L.length], sizeof(ElemType), 1, fp)){
        L.length ++;
        if(L.length >= L.listsize){
            L.elem = (ElemType*) realloc(L.elem, sizeof(ElemType) * (L.listsize + LISTINCREMENT));
            if(!L.elem)
                exit(OVERFLOW);
            L.listsize += LISTINCREMENT;
        }
    }
    fclose(fp);
    return OK;
}

status AddList(LISTS &Lists,char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{
    if(Lists.length == 10)
        return OVERFLOW;
    int i = 0;
    while(ListName[i])  i++;
    if(i >= 30)
        return ERROR;
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length].L.elem = (ElemType*) malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
    Lists.length ++;
    return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{
    int pos;
    for (pos = 0; pos < Lists.length; pos++)
    {
        if(!strcmp(Lists.elem[pos].name, ListName))
            break;
    }
    if(pos == Lists.length)
        return ERROR;
    free(Lists.elem[pos].L.elem);
    for(int i = pos; i < Lists.length - 1; i ++){
        strcpy(Lists.elem[i].name, Lists.elem[i+1].name);
        if(Lists.elem[i].L.listsize < Lists.elem[i+1].L.listsize){
            Lists.elem[i].L.elem = (ElemType*) realloc(Lists.elem[i+1].L.elem, Lists.elem[i+1].L.listsize);
            Lists.elem[i].L.listsize = Lists.elem[i+1].L.listsize;
            Lists.elem[i].L.length = Lists.elem[i+1].L.length;
        }
        else{
            for (int j = 0; j < Lists.elem[i + 1].L.length; ++j) {
                Lists.elem[i].L.elem[j] = Lists.elem[i+1].L.elem[j];
            }
            Lists.elem[i].L.length = Lists.elem[i+1].L.length;
        }
    }
    Lists.length --;
    free(Lists.elem[Lists.length].L.elem);
    return OK;
}

int LocateList(LISTS Lists,char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
    int pos = 0;
    while(pos < Lists.length && strcmp(Lists.elem[pos].name, ListName))
    {
        pos ++;
    }
    if(pos == Lists.length)
        return 0;
    return pos + 1;
}

status sortList(SqList &L)
{
    if(!L.elem)
        return INFEASIBLE;
    ElemType tmp;
    int i, j;
    for(i = 0; i < L.length - 1; i ++){
        for(j = 0; j < L.length - 1 - i; j ++){
            if(L.elem[j] > L.elem[j + 1]){
                tmp = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = tmp;
            }
        }
    }
    return OK;
}

int SubArrayNum(SqList L, int k)
{
    if(!L.elem)
        return INFEASIBLE;
    if(L.length == 1 || L.length == 0)
        return 0;
    SqList prefix;
    prefix.elem = (ElemType *) malloc(sizeof(ElemType) * (L.length + 5));
    prefix.length = 0;
    int sum = 0;
    prefix.elem[0] = sum;
    prefix.length ++;
    for(int i = 0; i < L.length; i ++){
        sum += L.elem[i];
        prefix.elem[prefix.length] = sum;
        prefix.length ++;
    }
    int num = 0;
    for(int i = 1; i < prefix.length; i ++){
        int j;
        for(j = i; j < prefix.length; j ++){
            if(prefix.elem[j] - prefix.elem[i - 1] == k)
                if(j - i + 1 >= 2)
                    num ++;
        }
    }
    free(prefix.elem);
    return num;
}

int MaxSubArray(SqList L)
{
    if(!L.elem)
        return INFEASIBLE;
    if(L.length == 0)
        return INFEASIBLE;
    int ThisSum, MaxSum, j;
    ThisSum = 0;
    MaxSum = 0;
    for(j = 0; j < L.length; j ++){
        ThisSum += L.elem[j];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}
