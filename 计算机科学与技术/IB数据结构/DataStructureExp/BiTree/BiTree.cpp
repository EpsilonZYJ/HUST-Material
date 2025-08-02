#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

#define MAX(a, b) (((a) > (b)) ? (a) : (b) )

/******����������******/
typedef int status;
typedef int KeyType;
typedef struct {
    KeyType  key;
    char others[20];
} TElemType; //������������Ͷ���


typedef struct BiTNode{  //����������Ķ���
    TElemType  data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

static BiTree ans = NULL;
/************/


/******��Ƕ������Ƿ�Ϊ��******/
enum BiTreeEmpty{EMPTY, N_EMPTY};
static int EMP = 0;
/************/


/******����ջ******/
typedef BiTree SElemType;
typedef struct BiStack{
    SElemType *base;
    SElemType *top;
    int stacksize;
}BiStack;

status StackInit(BiStack &S);
status GetTop(BiStack S, SElemType &e);
status Pop(BiStack &S, SElemType &e);
status Push(BiStack &S, SElemType e);
status StackEmpty(BiStack S);
status StackDestroy(BiStack &S);
/************/

/******��������******/
typedef BiTree QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QNodePtr;

typedef struct LinkQueue{
    QNode *front;
    QNode *rear;
}LinkQueue;

status InitQueue(LinkQueue &Q);
status EnQueue(LinkQueue &Q, QElemType e);
status DeQueue(LinkQueue &Q, QElemType &e);
status GetHead(LinkQueue Q, QElemType &e);
status QueueEmpty(LinkQueue Q);
status QueueDestroy(LinkQueue &Q);
/************/

/******����������******/
typedef struct{
    struct{
        char name[30];
        BiTree Tree;
    }elem[100];
    int length;
    int listsize;
}TREES;
/************/

status CreateBiTree(BiTree &T,TElemType definition[]);
status ClearBiTree(BiTree &T);
int BiTreeDepth(BiTree T);
BiTNode* LocateNode(BiTree T,KeyType e);
status Assign(BiTree &T,KeyType e,TElemType value);
BiTNode* GetSibling(BiTree T,KeyType e);
BiTNode* GetParent(BiTree T, KeyType e);
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c);
status DeleteNode(BiTree &T,KeyType e);
status PreOrderTraverse(BiTree T,void (*visit)(BiTree));
status InOrderTraverse(BiTree T,void (*visit)(BiTree));
status PostOrderTraverse(BiTree T,void (*visit)(BiTree));
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree));
status WriteTree(BiTree T, FILE* fout);
status ReadTree(BiTree &T, FILE* fin);
status SaveBiTree(BiTree T, char FileName[]);
status LoadBiTree(BiTree &T,  char FileName[]);
status InvertTree(BiTree &T);
int MaxPathSum(BiTree T);
BiTNode *LowestCommonAncestor(BiTree T, BiTNode *e1, BiTNode *e2);
BOOL DFS(BiTree T, BiTNode *e1, BiTNode *e2);
status BiTreeEmpty(BiTree T);
status DestroyBiTree(BiTree &T);

status AddTree(TREES &Trees, char TreeName[]);
status RemoveTree(TREES &Trees, char TreeName[]);
int LocateTree(TREES Trees, char TreeName[]);
status InitTrees(TREES &Trees);
status Multi_BiTree_management();
void visit(BiTree T);

int main(void)
{
    BiTree T;
    T = NULL;
    EMP = EMPTY;
    printf("*************************************************\n");
    printf("*                   WELCOME                     *\n");
    printf("*              author: Zhou Yujie               *\n");
    printf("*************************************************\n");

    int op = -1;
    while(op){
        printf("\n\n");
        printf("MENU\n");
        printf("----------------------------------------------------\n");
        printf("|    1.CreateBiTree        11.PreOrderTraverse     |\n");
        printf("|    2.DestroyBiTree       12.InOrderTraverse      |\n");
        printf("|    3.ClearBiTree         13.PostOrderTraverse    |\n");
        printf("|    4.BiTreeEmpty         14.LevelOrderTraverse   |\n");
        printf("|    5.BiTreeDepth         15.MaxPathSum           |\n");
        printf("|    6.LocateNode          16.LowestCommonAncestor |\n");
        printf("|    7.Assign              17.InvertTree           |\n");
        printf("|    8.GetSibling          18.SaveBiTree           |\n");
        printf("|    9.InsertNode          19.LoadBiTree           |\n");
        printf("|    10.DeleteNode         20.MultiBiTreeManagement|\n");
        printf("|    0.exit                                        |\n");
        printf("----------------------------------------------------\n");
        printf("������ѡ��[0-20]:");
        scanf("%d", &op);
        int states = 0;
        enum st{
            EXIT = 0, CREATE_BITREE = 1, DESTROY_BITREE, CLEAR_BITREE, BITREE_EMPTY,
            BITREE_DEPTH, LOCATE_NODE, ASSIGN, GET_SIBLING, INSERT_NODE, DELETE_NODE,
            PRE_ORDER_TRAVERSE, IN_ORDER_TRAVERSE, POST_ORDER_TRAVERSE,
            LEVEL_ORDER_TRAVERSE, MAX_PATH_SUM, LOWEST_COMMON_ANCESTOR, INVERT_TREE,
            SAVE_BITREE, LOAD_BITREE, MULTI_BITREE_MANAGEMENT
        };
        KeyType e = 0;
        char others[20];
        int pos = 0;
        char name[30];
        BiTNode *node;
        int k;
        switch(op){
            case EXIT:
                break;
            case CREATE_BITREE:
                printf("\n");
                if(EMP == N_EMPTY){
                    printf("CreateBiTree: Error!\n");
                    printf("�������Ѵ��ڣ�\n");
                }
                else{
                    int num;
                    printf("�������������\n");
                    scanf("%d", &num);
                    TElemType *definition = (TElemType*) malloc(sizeof(TElemType)*num);
                    for (int i = 0; i < num; i ++) {
                        scanf("%d %s", &definition[i].key, definition[i].others);
                    }
                    states = CreateBiTree(T, definition);
                    if(states == ERROR){
                        printf("CreateBiTree: Error!\n");
                        printf("ӵ����ͬ�ؼ��ֵĽ�㣡\n");
                    }
                    else {
                        if (T != NULL)  EMP = N_EMPTY;
                        printf("CreateBiTree: Success!\n");
                    }
                    free(definition);
                    definition = NULL;
                }
                break;
            case DESTROY_BITREE:
                printf("\n");
                if(EMP == EMPTY){
                    printf("DestroyBiTree: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else{
                    states = DestroyBiTree(T);
                    printf("DestroyBiTree: Success!\n");
                    EMP = EMPTY;
                }
                break;
            case CLEAR_BITREE:
                if(EMP == EMPTY){
                    printf("ClearBiTree: Error!\n");
                    printf("������Ϊ�գ�\n");
                }
                else{
                    states = ClearBiTree(T);
                    printf("ClearBiTree: Success!\n");
                    EMP = EMPTY;
                }
                break;
            case BITREE_EMPTY:
                printf("\n");
                states = BiTreeEmpty(T);
                if(states == TRUE)
                    printf("������Ϊ�գ�\n");
                else
                    printf("��������Ϊ�գ�\n");
                break;
            case BITREE_DEPTH:
                printf("\n");
                states = BiTreeDepth(T);
                printf("BiTreeDepth: Success!\n");
                printf("���������Ϊ%d\n", states);
                break;
            case LOCATE_NODE:
                printf("\n");
                printf("���������趨λ�Ľ��ؼ��֣�");
                scanf("%d", &e);
                node = LocateNode(T, e);
                if(node == NULL)    printf("δ���ҵ����!\n");
                else{
                    printf("LocateNode: Success!\n");
                    printf("�ؼ���Ϊ��%d\n��ϢΪ:%s\n", node->data.key, node->data.others);
                }
                break;
            case ASSIGN:
                printf("\n");
                printf("�����������޸�/��ֵ�Ľ��ؼ��֣�");
                scanf("%d", &e);
                printf("�������޸ĺ�Ľ��Ĺؼ��ֺ�ֵ��");
                TElemType val;
                scanf("%d %s", &val.key, val.others);
                states = Assign(T, e, val);
                if(states == ERROR){
                    printf("Assign: Error!\n");
                    printf("��ֵʧ�ܣ�\n");
                }
                else    printf("Assign: Success!\n");
                break;
            case GET_SIBLING:
                printf("\n");
                printf("��������ؼ��֣�");
                scanf("%d", &e);
                node = GetSibling(T, e);
                if(node == NULL) {
                    printf("GetSibiling: Error!\n");
                    printf("δ���ҵ��ֵܽ�㣡\n");
                }
                else{
                    printf("GetSibiling: Success!\n");
                    printf("�ֵܽ��Ĺؼ���Ϊ��%d, ��ϢΪ��%s\n", node->data.key, node->data.others);
                }
                break;
            case INSERT_NODE:
                printf("\n");
                printf("����������������ĸ���������ؼ��֣���");
                scanf("%d", &e);
                printf("�������½����Ϊ����(0)�����Һ��Ӳ���(1),��Ϊ���ڵ�����-1��");
                scanf("%d", &k);
                TElemType v;
                printf("�������������Ľ��Ĺؼ��֣�");
                scanf("%d", &v.key);
                printf("�������������Ľ�����Ϣ��");
                scanf("%s", v.others);
                states = InsertNode(T, e, k, v);
                if(states == ERROR){
                    printf("InsertNode: Error!\n");
                    printf("δ���ҵ�����ؼ��ֳ�ͻ��\n");
                }
                else    printf("InsertNode: Success!\n");
                break;
            case DELETE_NODE:
                printf("\n");
                printf("����������ɾ���Ľ��Ĺؼ��֣�");
                scanf("%d", &e);
                states = DeleteNode(T, e);
                if(states == INFEASIBLE){
                    printf("DeleteNode: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else if(states == ERROR){
                    printf("DeleteNode: Error!\n");
                    printf("δ�ܲ��ҵ���㣡\n");
                }
                else    printf("DeleteNode: Success!\n");
                break;
            case PRE_ORDER_TRAVERSE:
                printf("\n");
                states = PreOrderTraverse(T, visit);
                if(EMP == EMPTY){
                    printf("PreOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("PreOrderTraverse: Success!\n");
                }
                break;
            case IN_ORDER_TRAVERSE:
                printf("\n");
                states = InOrderTraverse(T, visit);
                if(EMP == EMPTY){
                    printf("InOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("InOrderTraverse: Success!\n");
                }
                break;
            case POST_ORDER_TRAVERSE:
                printf("\n");
                states = PostOrderTraverse(T, visit);
                if(EMP == EMPTY){
                    printf("PostOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("PostOrderTraverse: Success!\n");
                }
                break;
            case LEVEL_ORDER_TRAVERSE:
                printf("\n");
                states = LevelOrderTraverse(T, visit);
                if(EMP == EMPTY){
                    printf("LevelOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("LevelOrderTraverse: Success!\n");
                }
                break;
            case MAX_PATH_SUM:
                printf("\n");
                states = MaxPathSum(T);
                if(states == 0){
                    printf("MaxPathSum: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else{
                    printf("MqxSumPath: Success!\n");
                    printf("����㵽Ҷ�ӽ������·����Ϊ��%d\n", states);
                }
                break;
            case LOWEST_COMMON_ANCESTOR:
                printf("\n");
                if(EMP ==EMPTY){
                    printf("LowestCommonAncestor: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else{
                    BiTNode *node1 = (BiTNode*) malloc(sizeof(BiTNode));
                    BiTNode *node2 = (BiTNode*) malloc(sizeof(BiTNode));
                    printf("��ֱ�����������ҵ��������Ĺؼ���.\n");
                    printf("���1��");
                    scanf("%d", &node1->data.key);
                    printf("���2��");
                    scanf("%d", &node2->data.key);
                    node = LowestCommonAncestor(T, node1, node2);
                    if(node == NULL){
                        printf("LowestCommonAncestor: Error!\n");
                        printf("��������С�������ȣ�\n");
                    }
                    else{
                        printf("LowestCommonAncestor: Success!\n");
                        printf("��С�������ȵĹؼ���Ϊ��%d�� ��ϢΪ��%s\n", node->data.key, node->data.others);
                    }
                    free(node1);
                    free(node2);
                    node1 = node2 = NULL;
                }
                break;
            case INVERT_TREE:
                printf("\n");
                states = InvertTree(T);
                if(states == ERROR){
                    printf("InvertTree: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else    printf("InvertTree: Success!\n");
                break;
            case SAVE_BITREE:
                printf("\n");
                printf("����1���ļ���������������0ΪĬ�����ƣ�");
                scanf("%d", &states);
                if(states == 1){
                    scanf("%s", name);
                    states = SaveBiTree(T, name);
                    if(states == INFEASIBLE){
                        printf("SaveBiTree: Error!\n");
                        printf("������������!\n");
                    }
                    else if(states == ERROR){
                        printf("SaveBiTree: Error!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveBiTree: Success!\n");
                }
                else if(states == 0){
                    states = SaveBiTree(T, "save.txt");
                    if(states == INFEASIBLE){
                        printf("SaveBiTree: Error!\n");
                        printf("������������!\n");
                    }
                    else if(states == ERROR){
                        printf("SaveBiTree: Error!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveBiTree: Success!\n");
                }
                else
                    printf("������1��0!\n");
                break;
            case LOAD_BITREE:
                printf("\n");
                printf("������������ص��ļ����ƣ�");
                scanf("%s", name);
                states = LoadBiTree(T, name);
                if(states == INFEASIBLE){
                    printf("LoadBiTree: Error!\n");
                    printf("�������Ѵ��ڣ�\n");
                }
                else if(states == ERROR){
                    printf("LoadBiTree: Error!\n");
                    printf("�򲻿��ļ�!\n");
                }
                else{
                	printf("LoadBiTree: Success!\n");
                	EMP = N_EMPTY; 
				}
                break;
            case MULTI_BITREE_MANAGEMENT:
                Multi_BiTree_management();
                op = -1;
                continue;
            default:
                printf("\n");
                printf("����ѡ��Ӧ����[0-20]�ķ�Χ�ڣ�\n");
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

status Multi_BiTree_management(){
    int op = -1;
    TREES trees;
    InitTrees(trees);

    while(op){
        printf("\n\n");
        printf("MENU\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+    1.CreateBiTree        12.InOrderTraverse      +\n");
        printf("+    2.DestroyBiTree       13.PostOrderTraverse    +\n");
        printf("+    3.ClearBiTree         14.LevelOrderTraverse   +\n");
        printf("+    4.BiTreeEmpty         15.MaxPathSum           +\n");
        printf("+    5.BiTreeDepth         16.LowestCommonAncestor +\n");
        printf("+    6.LocateNode          17.InvertTree           +\n");
        printf("+    7.Assign              18.SaveBiTree           +\n");
        printf("+    8.GetSibling          19.LoadBiTree           +\n");
        printf("+    9.InsertNode          20.AddTree              +\n");
        printf("+    10.DeleteNode         21.RemoveTree           +\n");
        printf("+    11.PreOrderTraverse   22.LocateTree           +\n");
        printf("+    0.exit                                        +\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("������ѡ��[0-19]:");
        scanf("%d", &op);
        int states = 0;
        enum st{
            EXIT = 0, CREATE_BITREE = 1, DESTROY_BITREE, CLEAR_BITREE, BITREE_EMPTY,
            BITREE_DEPTH, LOCATE_NODE, ASSIGN, GET_SIBLING, INSERT_NODE, DELETE_NODE,
            PRE_ORDER_TRAVERSE, IN_ORDER_TRAVERSE, POST_ORDER_TRAVERSE,
            LEVEL_ORDER_TRAVERSE, MAX_PATH_SUM, LOWEST_COMMON_ANCESTOR, INVERT_TREE,
            SAVE_BITREE, LOAD_BITREE, ADD_TREE, REMOVE_TREE, LOCATE_TREE
        };
        KeyType e = 0;
        char others[20];
        int pos = 0;
        char name[30];
        char tree_name[30];
        BiTNode *node;
        int k;
        int ls_pos;
        switch(op){
            case EXIT:
                break;
            case CREATE_BITREE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree) == FALSE){
                    printf("CreateBiTree: Error!\n");
                    printf("�������Ѵ��ڣ�\n");
                }
                else{
                    int num;
                    printf("�������������\n");
                    scanf("%d", &num);
                    TElemType *definition = (TElemType*) malloc(sizeof(TElemType)*num);
                    for (int i = 0; i < num; i ++) {
                        scanf("%d %s", &definition[i].key, definition[i].others);
                    }
                    states = CreateBiTree(trees.elem[ls_pos-1].Tree, definition);
                    if(states == ERROR){
                        printf("CreateBiTree: Error!\n");
                        printf("ӵ����ͬ�ؼ��ֵĽ�㣡\n");
                    }
                    else {
                        printf("CreateBiTree: Success!\n");
                    }
                    free(definition);
                    definition = NULL;
                }
                break;
            case DESTROY_BITREE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree) == TRUE){
                    printf("DestroyBiTree: Error!\n");
                    printf("������Ϊ�գ�\n");
                }
                else{
                    states = DestroyBiTree(trees.elem[ls_pos-1].Tree);
                    printf("DestroyBiTree: Success!\n");
                }
                break;
            case CLEAR_BITREE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree) == TRUE){
                    printf("ClearBiTree: Error!\n");
                    printf("������Ϊ�գ�\n");
                }
                else{
                    states = ClearBiTree(trees.elem[ls_pos-1].Tree);
                    printf("ClearBiTree: Success!\n");
                }
                break;
            case BITREE_EMPTY:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = BiTreeEmpty(trees.elem[ls_pos-1].Tree);
                if(states == TRUE)
                    printf("������Ϊ�գ�\n");
                else
                    printf("��������Ϊ�գ�\n");
                break;
            case BITREE_DEPTH:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = BiTreeDepth(trees.elem[ls_pos-1].Tree);
                printf("BiTreeDepth: Success!\n");
                printf("���������Ϊ%d\n", states);
                break;
            case LOCATE_NODE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                printf("���������趨λ�Ľ��ؼ��֣�");
                scanf("%d", &e);
                node = LocateNode(trees.elem[ls_pos-1].Tree, e);
                if(node == NULL)    printf("δ���ҵ����!\n");
                else{
                    printf("LocateNode: Success!\n");
                    printf("�ؼ���Ϊ��%d\n��ϢΪ:%s\n", node->data.key, node->data.others);
                }
                break;
            case ASSIGN:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                printf("�����������޸�/��ֵ�Ľ��ؼ��֣�");
                scanf("%d", &e);
                printf("�������޸ĺ�Ľ��Ĺؼ��ֺ�ֵ��");
                TElemType val;
                scanf("%d %s", &val.key, val.others);
                states = Assign(trees.elem[ls_pos-1].Tree, e, val);
                if(states == ERROR){
                    printf("Assign: Error!\n");
                    printf("��ֵʧ�ܣ�\n");
                }
                else    printf("Assign: Success!\n");
                break;
            case GET_SIBLING:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                printf("��������ؼ��֣�");
                scanf("%d", &e);
                node = GetSibling(trees.elem[ls_pos-1].Tree, e);
                if(node == NULL) {
                    printf("GetSibiling: Error!\n");
                    printf("δ���ҵ��ֵܽ�㣡\n");
                }
                else{
                    printf("GetSibiling: Success!\n");
                    printf("�ֵܽ��Ĺؼ���Ϊ��%d, ��ϢΪ��%s\n", node->data.key, node->data.others);
                }
                break;
            case INSERT_NODE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                printf("����������������ĸ���������ؼ��֣���");
                scanf("%d", &e);
                printf("�������½����Ϊ����(0)�����Һ��Ӳ���(1),��Ϊ���ڵ�����-1��");
                scanf("%d", &k);
                TElemType v;
                printf("�������������Ľ��Ĺؼ��֣�");
                scanf("%d", &v.key);
                printf("�������������Ľ�����Ϣ��");
                scanf("%s", v.others);
                states = InsertNode(trees.elem[ls_pos-1].Tree, e, k, v);
                if(states == ERROR){
                    printf("InsertNode: Error!\n");
                    printf("δ���ҵ�����ؼ��ֳ�ͻ��\n");
                }
                else    printf("InsertNode: Success!\n");
                break;
            case DELETE_NODE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                printf("����������ɾ���Ľ��Ĺؼ��֣�");
                scanf("%d", &e);
                states = DeleteNode(trees.elem[ls_pos-1].Tree, e);
                if(states == INFEASIBLE){
                    printf("DeleteNode: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else if(states == ERROR){
                    printf("DeleteNode: Error!\n");
                    printf("δ�ܲ��ҵ���㣡\n");
                }
                else    printf("DeleteNode: Success!\n");
                break;
            case PRE_ORDER_TRAVERSE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = PreOrderTraverse(trees.elem[ls_pos-1].Tree, visit);
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree) == TRUE){
                    printf("PreOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("PreOrderTraverse: Success!\n");
                }
                break;
            case IN_ORDER_TRAVERSE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = InOrderTraverse(trees.elem[ls_pos-1].Tree, visit);
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree) == TRUE){
                    printf("InOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("InOrderTraverse: Success!\n");
                }
                break;
            case POST_ORDER_TRAVERSE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = PostOrderTraverse(trees.elem[ls_pos-1].Tree, visit);
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree) == TRUE){
                    printf("PostOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("PostOrderTraverse: Success!\n");
                }
                break;
            case LEVEL_ORDER_TRAVERSE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = LevelOrderTraverse(trees.elem[ls_pos-1].Tree, visit);
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree) == TRUE){
                    printf("LevelOrderTraverse: Error!\n");
                    printf("������������/������Ϊ�գ�\n");
                }
                else{
                    printf("\n");
                    printf("LevelOrderTraverse: Success!\n");
                }
                break;
            case MAX_PATH_SUM:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = MaxPathSum(trees.elem[ls_pos-1].Tree);
                if(states == 0){
                    printf("MaxPathSum: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else{
                    printf("MqxSumPath: Success!\n");
                    printf("����㵽Ҷ�ӽ������·����Ϊ��%d\n", states);
                }
                break;
            case LOWEST_COMMON_ANCESTOR:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                if(BiTreeEmpty(trees.elem[ls_pos-1].Tree)){
                    printf("LowestCommonAncestor: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else{
                    BiTNode *node1 = (BiTNode*) malloc(sizeof(BiTNode));
                    BiTNode *node2 = (BiTNode*) malloc(sizeof(BiTNode));
                    printf("��ֱ�����������ҵ��������Ĺؼ���.\n");
                    printf("���1��");
                    scanf("%d", &node1->data.key);
                    printf("���2��");
                    scanf("%d", &node2->data.key);
                    node = LowestCommonAncestor(trees.elem[ls_pos-1].Tree, node1, node2);
                    if(node == NULL){
                        printf("LowestCommonAncestor: Error!\n");
                        printf("��������С�������ȣ�\n");
                    }
                    else{
                        printf("LowestCommonAncestor: Success!\n");
                        printf("��С�������ȵĹؼ���Ϊ��%d�� ��ϢΪ��%s\n", node->data.key, node->data.others);
                    }
                    free(node1);
                    free(node2);
                    node1 = node2 = NULL;
                }
                break;
            case INVERT_TREE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                states = InvertTree(trees.elem[ls_pos-1].Tree);
                if(states == ERROR){
                    printf("InvertTree: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else    printf("InvertTree: Success!\n");
                break;
            case SAVE_BITREE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                printf("����1���ļ���������������0ΪĬ�����ƣ�");
                scanf("%d", &states);
                if(states == 1){
                    scanf("%s", name);
                    states = SaveBiTree(trees.elem[ls_pos-1].Tree, name);
                    if(states == INFEASIBLE){
                        printf("SaveBiTree: Error!\n");
                        printf("������������!\n");
                    }
                    else if(states == ERROR){
                        printf("SaveBiTree: Error!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveBiTree: Success!\n");
                }
                else if(states == 0){
                    states = SaveBiTree(trees.elem[ls_pos-1].Tree, "save.txt");
                    if(states == INFEASIBLE){
                        printf("SaveBiTree: Error!\n");
                        printf("������������!\n");
                    }
                    else if(states == ERROR){
                        printf("SaveBiTree: Error!\n");
                        printf("�޷����ļ�!\n");
                    }
                    else
                        printf("SaveBiTree: Success!\n");
                }
                else
                    printf("������1��0!\n");
                break;
            case LOAD_BITREE:
                printf("\n");
                printf("���������������������");
                scanf("%s", tree_name);
                ls_pos = LocateTree(trees, tree_name);
                if(ls_pos == 0){
                    printf("������������.\n");
                    break;
                }
                printf("������������ص��ļ����ƣ�");
                scanf("%s", name);
                states = LoadBiTree(trees.elem[ls_pos-1].Tree, name);
                if(states == INFEASIBLE){
                    printf("LoadBiTree: Error!\n");
                    printf("�������Ѵ��ڣ�\n");
                }
                else if(states == ERROR){
                    printf("LoadBiTree: Error!\n");
                    printf("�򲻿��ļ�!\n");
                }
                else
                    printf("LoadBiTree: Success!\n");
                break;
            case ADD_TREE:
                printf("\n");
                printf("����������������(25��Ӣ���ַ�����)��");
                scanf("%s", name);
                states = AddTree(trees, name);
                if(states == OVERFLOW){
                    printf("AddTree: Error!\n");
                    printf("���������޷�����ӣ�\n");
                }
                else if(states == ERROR){
                    printf("AddTree: Error!\n");
                    printf("�����ַ����������ޣ�\n");
                }
                else printf("AddTree: Success!\n");
                break;
            case REMOVE_TREE:
                printf("\n");
                printf("����������Ҫɾ����������");
                scanf("%s", name);
                states = RemoveTree(trees, name);
                if(states == ERROR){
                    printf("RemoveTree: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else printf("RemoveTree: Success!\n");
                break;
            case LOCATE_TREE:
                printf("\n");
                printf("���������������������");
                scanf("%s", name);
                states = LocateTree(trees, name);
                if(states == 0){
                    printf("LocateTree: Error!\n");
                    printf("�����������ڣ�\n");
                }
                else printf("�������ҵĶ������ڵ�%d��λ��.\n", states);
                break;
            default:
                printf("\n");
                printf("����ѡ��Ӧ����[0-20]�ķ�Χ�ڣ�\n");
                break;
        }
        while(getchar() != '\n');//��տ���̨���ַ��ȷǷ��ַ�
        if(op != 0) op = -1; //��ֹop��δ�ı����ڶ������ʱδ����ֵ��������һ���Ĳ���
    }
    return TRUE;
}

/******����ջ����******/
status StackInit(BiStack &S)
{
    S.base = (SElemType*) malloc(sizeof(SElemType) * STACK_INIT_SIZE);
    if(!S.base)
        exit(OVERFLOW);
    S.stacksize = STACK_INIT_SIZE;
    S.top = S.base;
    return OK;
}

status GetTop(BiStack S, SElemType &e)
{
    if(S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}

status Pop(BiStack &S, SElemType &e)
{
    if(S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
    S.top --;
    return OK;
}

status Push(BiStack &S, SElemType e)
{
    if(S.top == S.base + S.stacksize) {
        S.base = (SElemType *) realloc(S.base, sizeof(SElemType) * (S.stacksize + STACK_INCREMENT));
        S.stacksize += STACK_INCREMENT;
    }
    if(!S.base)
        exit(OVERFLOW);
    *(S.top) = e;
    S.top ++;
    return OK;
}

status StackEmpty(BiStack S)
{
    if(S.top == S.base)
        return TRUE;
    return FALSE;
}

status StackDestroy(BiStack &S)
{
    free(S.base);
    S.base = S.top = NULL;
    S.stacksize = 0;
    return OK;
}
/************/

/******��������******/
status InitQueue(LinkQueue &Q)
{
    Q.front = (QNode*) malloc(sizeof(QNode));
    if(!Q.front)
        exit(OVERFLOW);
    Q.rear = Q.front;
    Q.front->next = NULL;
    return OK;
}

status EnQueue(LinkQueue &Q, QElemType e)
{
    QNode *s = (QNode*) malloc(sizeof(QNode));
    if(!s)
        exit(OVERFLOW);
    s->data = (QElemType) malloc(sizeof(BiTNode));
    /*�洢����*/
    s->data->data.key = e->data.key;
    strcpy(s->data->data.others, e->data.others);
    s->data->rchild = e->rchild;
    s->data->lchild = e->lchild;

    /*���*/
    s->next = Q.rear->next;
    Q.rear->next = s;
    Q.rear = s;
    return OK;
}

status DeQueue(LinkQueue &Q, QElemType &e)
{
    if(Q.rear == Q.front)
        return ERROR;

    /*�洢����*/
    QNodePtr p = Q.front->next;
    e->data.key = p->data->data.key;
    strcpy(e->data.others, p->data->data.others);
    e->rchild = p->data->rchild;
    e->lchild = p->data->lchild;

    /*����*/
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    p = NULL;
    return OK;
}

status GetHead(LinkQueue Q, QElemType &e)
{
    if(Q.front == Q.rear)
        return ERROR;
    QNodePtr hp = Q.front->next;
    e->data.key = hp->data->data.key;
    strcpy(e->data.others, hp->data->data.others);
    e->rchild = hp->data->rchild;
    e->lchild = hp->data->lchild;
    return OK;
}

status QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    return FALSE;
}

status QueueDestroy(LinkQueue &Q)
{
    QNodePtr p = Q.front;
    while(Q.front != NULL){
        Q.front = Q.front->next;
        free(p);
        p = Q.front;
    }
    free(p);
    Q.front = NULL;
    Q.rear = NULL;
    p = NULL;
    return OK;
}

/************/

status CreateBiTree(BiTree &T,TElemType definition[])
/*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
{
    if(definition[0].key == -1){
        T = NULL;
        return OK;
    }
    static TElemType *def_ptr = definition;
    for (TElemType *pi = definition; pi->key != -1; pi ++) {
        for (TElemType *pj = definition; pj < pi; pj ++) {
            if((*pi).key == (*pj).key && (*pi).key) return ERROR;
        }
    }
    if((*def_ptr).key == 0){
        T = NULL;
        def_ptr ++;
    }
    else{
        T = (BiTree) malloc(sizeof(BiTNode));
        T->data.key = (*def_ptr).key;
        strcpy(T->data.others, (*def_ptr).others);
        def_ptr ++;
        CreateBiTree(T->lchild, def_ptr);
        CreateBiTree(T->rchild, def_ptr);
    }
    return OK;
}

status ClearBiTree(BiTree &T)
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
{
    if(T == NULL)
        return OK;
    if(T->lchild == NULL && T->rchild == NULL){
        free(T);
        T = NULL;
    }
    else if(T->lchild == NULL){
        ClearBiTree(T->rchild);
        free(T);
        T = NULL;
    }
    else if(T->rchild == NULL){
        ClearBiTree(T->lchild);
        free(T);
        T = NULL;
    }
    else{
        ClearBiTree(T->lchild);
        ClearBiTree(T->rchild);
        free(T);
        T = NULL;
    }
    return OK;
}

status DestroyBiTree(BiTree &T)
{
    EMP = EMPTY;
    return ClearBiTree(T);
}

int BiTreeDepth(BiTree T)
//�������T�����
{
    int depth;
    if(!T)
        depth = 0;
    else{
        int left_depth = BiTreeDepth(T->lchild);
        int right_depth = BiTreeDepth(T->rchild);
        depth = 1 + (left_depth > right_depth ? left_depth : right_depth);
    }
    return depth;
}

BiTNode* LocateNode(BiTree T,KeyType e)
//���ҽ��
{
    if(T == NULL)
        return NULL;
    else if(T->data.key == e)
        return T;
    else{
        BiTNode* p = LocateNode(T->lchild, e);
        if(p == NULL)
            p = LocateNode(T->rchild, e);
        return p;
    }
}

status Assign(BiTree &T,KeyType e,TElemType value)
//ʵ�ֽ�㸳ֵ
{
    BiTNode* p = LocateNode(T, e);
    BiTNode* s;
    if(!p)
        return ERROR;
    if((s = LocateNode(T, value.key)) != NULL && s != p)
        return ERROR;
    p->data.key = value.key;
    strcpy(p->data.others, value.others);
    return OK;
}

BiTNode* GetSibling(BiTree T,KeyType e)
//ʵ�ֻ���ֵܽ��
{
    if(T == NULL)
        return NULL;
    if(T->lchild && T->lchild->data.key == e)
        return T->rchild;
    if(T->rchild && T->rchild->data.key == e)
        return T->lchild;
    BiTNode *p = GetSibling(T->lchild, e);
    if (!p)
        p = GetSibling(T->rchild, e);
    return p;
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//������
{
    BiTNode *s = (BiTNode*) malloc(sizeof(BiTNode));
    s->data.key = c.key;
    strcpy(s->data.others, c.others);
    s->lchild = NULL;
    s->rchild = NULL;

    //��LRΪ-1
    if(LR == -1){
        s->rchild = T;
        T = s;
        return OK;
    }
    else {
        if(e == c.key)
            return ERROR;
        BiTNode *node_e = LocateNode(T, e);
        if(node_e == NULL)
            return ERROR;
        if (LR == 0) {
            //��Ϊ����
            s->rchild = node_e->lchild;
            node_e->lchild = s;
            return OK;
        }
        else{
            //��Ϊ�Һ���
            s->rchild = node_e->rchild;
            node_e->rchild = s;
            return OK;
        }
    }
}

BiTNode* GetParent(BiTree T, KeyType e)
{
    if(T->data.key == e)
        return NULL;
    if(T->rchild == NULL){
        if(T->lchild == NULL)
            return NULL;
        else if(T->lchild->data.key == e)
            return T;
        else
            return GetParent(T->lchild, e);
    }
    else{
        //T->rchild != NULL
        if(T->lchild == NULL){
            if(T->rchild->data.key == e)
                return T;
            else
                return GetParent(T->rchild, e);
        }
        else{
            //T->rchild != NULL && T->lchild != NULL
            if(T->lchild->data.key == e || T->rchild->data.key == e)
                return T;
            else{
                BiTNode *p = GetParent(T->lchild, e);
                if(!p)
                    p = GetParent(T->rchild, e);
                return p;
            }
        }
    }
}

status DeleteNode(BiTree &T,KeyType e)
//ɾ����㡣��������ͨ������������������ʵ�ֱ�������
{
    if(!T)  return INFEASIBLE;
    if(T->data.key == e){
        BiTree p = T;
        if(T->lchild == NULL && T->rchild == NULL){
            free(T);
            T = NULL;
        }
        else if(T->rchild == NULL){
            T = T->lchild;
            free(p);
            p = NULL;
        }
        else if(T->lchild == NULL){
            T = T->rchild;
            free(p);
            p = NULL;
        }
        else{
            BiTree RC = T->rchild;
            BiTree LC = T->lchild;
            free(T);
            T = LC;
            p = T;
            while(p->rchild) p = p->rchild;
            p->rchild = RC;
        }
        return OK;
    }
    BiTNode *parent = GetParent(T, e);
    if(!parent)
        return ERROR;
    BiTNode *del_node;
    enum flag{left, right} flag;
    if(parent->lchild->data.key == e){
        del_node = parent->lchild;
        flag = left;
    }
    else{
        del_node = parent->rchild;
        flag = right;
    }
    if(del_node->rchild == NULL && del_node->lchild == NULL){
        free(del_node);
        if(flag == left) parent->lchild = NULL;
        else    parent->rchild = NULL;
    }
    else if(del_node->rchild == NULL){
        if(flag == left){
            parent->lchild = del_node->lchild;
            free(del_node);
        }
        else{
            parent->rchild = del_node->lchild;
            free(del_node);
        }
    }
    else if(del_node->lchild == NULL){
        if(flag == left){
            parent->lchild = del_node->rchild;
            free(del_node);
        }
        else{
            parent->rchild = del_node->rchild;
            free(del_node);
        }
    }
    else{
        BiTree LC = del_node->lchild;
        BiTree RC = del_node->rchild;
        BiTree p = LC;
        while(p->rchild) p = p->rchild;
        p->rchild = RC;
        if(flag == left){
            parent->lchild = LC;
            free(del_node);
        }
        else{
            parent->rchild = LC;
            free(del_node);
        }
    }
    return OK;
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    if(T){
        visit(T);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
    return OK;
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    if(T){
        InOrderTraverse(T->lchild, visit);
        visit(T);
        InOrderTraverse(T->rchild, visit);
    }
    return OK;
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    if(T == NULL)
        return INFEASIBLE;
    BiStack stack;
    StackInit(stack);
    BiTNode *p = T;
    BiTNode *last_visit = NULL;
    while(p || !StackEmpty(stack)){
        while(p){
            Push(stack, p);
            p = p->lchild;
        }
        BiTNode *top_node;
        GetTop(stack, top_node);
        if(top_node->rchild != NULL && last_visit != top_node->rchild){
            p = top_node->rchild;
        }
        else{
            visit(top_node);
            last_visit = top_node;
            Pop(stack, top_node);
        }

    }
    StackDestroy(stack);
    return OK;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    LinkQueue q;
    InitQueue(q);
    BiTree p = (BiTree) malloc(sizeof(BiTNode));
    if(T)	EnQueue(q, T);
    while(!QueueEmpty(q)){
        DeQueue(q, p);
        if(p){
            visit(p);
            if(p->lchild) EnQueue(q, p->lchild);
            if(p->rchild) EnQueue(q, p->rchild);
        }
    }
    QueueDestroy(q);
    return OK;
}

status WriteTree(BiTree T, FILE* fout)
{
    if(T){
        fprintf(fout, "%d %s ", T->data.key, T->data.others);
        WriteTree(T->lchild, fout);
        WriteTree(T->rchild, fout);
    }
    else{
        fprintf(fout, "%d %s ", 0, "null");
    }
    return OK;
}

status ReadTree(BiTree &T, FILE* fin)
{
    TElemType tmp;
    fscanf(fin, "%d%s", &tmp.key, tmp.others);
    if(tmp.key == -1)   return ERROR;
    else{
        T = (BiTree) malloc(sizeof(BiTNode));
        if(tmp.key){
            T->data.key = tmp.key;
            strcpy(T->data.others, tmp.others);
            ReadTree(T->lchild, fin);
            ReadTree(T->rchild, fin);
        }
        else{
            T = NULL;
        }
    }
    return OK;
}

status SaveBiTree(BiTree T, char FileName[])
//���������Ľ������д�뵽�ļ�FileName��
{
    if(T == NULL)
        return INFEASIBLE;
    FILE *fp = fopen(FileName, "w");
    if(fp == NULL)  return ERROR;
    WriteTree(T, fp);
    fprintf(fp, "%d %s ", -1, "null");
    fclose(fp);
    return OK;
}

status LoadBiTree(BiTree &T,  char FileName[])
//�����ļ�FileName�Ľ�����ݣ�����������
{
    if(T)
        return INFEASIBLE;
    FILE *fp = fopen(FileName, "r");
    if(fp == NULL)  return ERROR;
    ReadTree(T, fp);
    fclose(fp);
    return OK;
}

status InvertTree(BiTree &T)
//��ת������
{
    if(!T)  return ERROR;
    BiTree l = T->lchild;
    BiTree r = T->rchild;
    T->lchild = r;
    T->rchild = l;
    if(T->lchild) InvertTree(T->lchild);
    if(T->rchild) InvertTree(T->rchild);
    return OK;
}

status InitTrees(TREES &Trees)
//������������ʼ��
{
    Trees.listsize = 100;
    Trees.length = 0;
    return OK;
}

status AddTree(TREES &Trees, char TreeName[])
//���Ӷ�����
{
    if(Trees.length == Trees.listsize)
        return OVERFLOW;
    int i = 0;
    while(TreeName[i])  i++;
    if(i >= 30) return ERROR;
    strcpy(Trees.elem[Trees.length].name, TreeName);
    Trees.elem[Trees.length].Tree = NULL;
    Trees.length ++;
    return OK;
}

status RemoveTree(TREES &Trees, char TreeName[])
//�Ƴ�������
{
    int pos = 0;
    while(pos < Trees.length && strcmp(Trees.elem[pos].name, TreeName))
        pos ++;
    if(pos == Trees.length) return ERROR;
    ClearBiTree(Trees.elem[pos].Tree);
    for(int i = pos; i < Trees.length - 1; i ++){
        strcpy(Trees.elem[i].name, Trees.elem[i+1].name);
        Trees.elem[i].Tree = Trees.elem[i+1].Tree;
    }
    Trees.length --;
    Trees.elem[Trees.length].Tree = NULL;
    return OK;
}

int LocateTree(TREES Trees, char TreeName[])
//��λ������
{
    int pos = 0;
    while(pos < Trees.length && strcmp(Trees.elem[pos].name, TreeName))
        pos ++;
    if(pos == Trees.length)
        return 0;
    return pos + 1;
}

int MaxPathSum(BiTree T)
//���ظ��ڵ㵽Ҷ�ӽ������·����
{
    if(!T)  return 0;
    int left = MaxPathSum(T->lchild);
    int right = MaxPathSum(T->rchild);
    return MAX(left, right) + T->data.key;
}

BOOL DFS(BiTree T, BiTNode *e1, BiTNode *e2)
{
    if(T == NULL)   return FALSE;
    BOOL lson = DFS(T->lchild, e1, e2);
    BOOL rson = DFS(T->rchild, e1, e2);
    if((lson && rson) || ((T->data.key == e1->data.key || T->data.key == e2->data.key) && (lson || rson)))
        ans = T;
    return (lson || rson || T->data.key == e1->data.key || T->data.key == e2->data.key);
}

BiTNode *LowestCommonAncestor(BiTree T, BiTNode *e1, BiTNode *e2)
//��ʼ�����Ƕ��������ڣ���������Ǹö�������e1����e2���������������
{
    ans = NULL;
    DFS(T, e1, e2);
    return ans;
}

status BiTreeEmpty(BiTree T)
{
    if(T)
        return FALSE;
    return TRUE;
}

void visit(BiTree T)
{
    printf("%d %s ", T->data.key, T->data.others);
    return;
}
