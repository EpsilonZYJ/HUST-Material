#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define BOOL int
#define INFINITY INT_MAX

#define SET_INIT_SIZE 100
#define SETINCREMENT 10

typedef int status;

/******�ڽӱ�ͼ******/
typedef int KeyType;
typedef enum {DG,DN,UDG,UDN} GraphKind;//{����ͼ��������������ͼ��������}
typedef struct {
    KeyType  key;
    char others[20];
} VertexType; //�������Ͷ���

typedef struct ArcNode {         //�������Ͷ���
    int adjvex;              //����λ�ñ��
    struct ArcNode  *nextarc;	   //��һ������ָ��
} ArcNode;

typedef struct VNode{				//ͷ��㼰���������Ͷ���
    VertexType data;       	//������Ϣ
    ArcNode *firstarc;      	 //ָ���һ����
} VNode,AdjList[MAX_VERTEX_NUM];

typedef  struct {  //�ڽӱ�����Ͷ���
    AdjList vertices;     	 //ͷ�������
    int vexnum,arcnum;   	  //������������
    GraphKind  kind;        //ͼ������
} ALGraph;
/************/


/******��ͼ����******/
typedef struct{
    struct{
        char name[30];
        ALGraph Graph;
    }elem[100];
    int length;
    int listsize;
}GRAPHS;

status AddGraph(GRAPHS &graphs, char GraphName[]);
status RemoveGraph(GRAPHS &graphs, char GraphName[]);
int LocateGraph(GRAPHS &graphs, char GraphName[]);
status InitGRAPHS(GRAPHS &graphs);
/************/


/******��������******/
typedef int QElemType;
typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode, *QNodePtr;

typedef struct LinkQueue{
    QNode *front;
    QNode *rear;
}LinkQueue;

status InitQueue(LinkQueue &Q);
status EnQueue(LinkQueue &Q, QElemType elem);
status DeQueue(LinkQueue &Q, QElemType &elem);
status QueueEmpty(LinkQueue Q);
status DestroyQueue(LinkQueue &Q);
/************/


/******����******/
typedef KeyType SetElemType;
typedef struct{
    SetElemType *elem;
    int setsize;
    int setlength;
}Set, *SetPtr;

status SetInit(Set &set);
status SetInsert(Set &set, SetElemType elem);
status SetDestroy(Set &set);
void PrintSet(Set set, ALGraph G);
/************/


BOOL *visited;//����Ƿ������

status CreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2], GraphKind kind);
status DestroyGraph(ALGraph &G);
int LocateVex(ALGraph G,KeyType u);
status PutVex(ALGraph &G,KeyType u,VertexType value);
int FirstAdjVex(ALGraph G,KeyType u);
int NextAdjVex(ALGraph G,KeyType v,KeyType w);
status InsertVex(ALGraph &G,VertexType v);
status DeleteVex(ALGraph &G,KeyType v);
status InsertArc(ALGraph &G,KeyType v,KeyType w);
status DeleteArc(ALGraph &G,KeyType v,KeyType w);
status DFSTraverse(ALGraph &G,void (*visit)(VertexType));
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));
status SaveGraph(ALGraph G, char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]);
void DFS(ALGraph G, int pos, void (*visit)(VertexType));

Set VerticesSetLessThanK(ALGraph G, KeyType v, int k);
int ShortestPathLength(ALGraph G, KeyType v, KeyType w);
void DFS_CCN(ALGraph G, int pos);
int ConnectedComponentsNums(ALGraph G);

status Multi_Graph_management();
void visit(VertexType v);

int main()
{
    ALGraph G;
    G.vexnum = 0;
    G.arcnum = 0;
    printf("**************************************************\n");
    printf("*                    WELCOME                     *\n");
    printf("*               author: Zhou Yujie               *\n");
    printf("**************************************************\n");

    int op = -1;
    while(op){
        printf("\n\n");
        printf("MENU\n");
        printf("-----------------------------------------------------\n");
        printf("|    1.CreateGraph        11.DFSTraverse            |\n");
        printf("|    2.DestroyGraph       12.BFSTraverse            |\n");
        printf("|    3.LocateVex          13.VerticesSetLessThanK   |\n");
        printf("|    4.PutVex             14.ShortestPathLength     |\n");
        printf("|    5.FirstAdjVex        15.ConnectedComponentsNums|\n");
        printf("|    6.NextAdjVex         16.SaveGraph              |\n");
        printf("|    7.InsertVex          17.LoadGraph              |\n");
        printf("|    8.DeleteVex          18.MultiGraphManagement   |\n");
        printf("|    9.InsertArc                                    |\n");
        printf("|    10.DeleteArc                                   |\n");
        printf("|    0.exit                                         |\n");
        printf("-----------------------------------------------------\n");
        printf("������ѡ��[0-18]:");
        scanf("%d", &op);
        int states = 0;
        enum st{
            EXIT = 0, CREATE_GRAPH = 1, DESTROY_GRAPH, LOCATE_VEX, PUT_VEX,
            FIRST_ADJ_VEX, NEXT_ADJ_VEX, INSERT_VEX, DELETE_VEX, INSERT_ARC,
            DELETE_ARC, DFS_TRAVERSE, BFS_TRAVERSE, VERTICES_SET_LESS_THAN_K,
            SHORTEST_PATH_LENGTH, CONNECTED_COMPONENTS_NUMS, SAVE_GRAPH, LOAD_GRAPH,
            MULTI_GRAPH_MANAGEMENT
        };
        if(G.vexnum == 0 && (op != 0 && op != CREATE_GRAPH && op != LOAD_GRAPH && op != MULTI_GRAPH_MANAGEMENT)) {
            printf("Error!\n");
            printf("ͼΪ�գ�\n");
            continue;
        }
        KeyType e = 0;
        KeyType v;
        KeyType w;
        VertexType value;
        char others[20];
        int pos = 0;
        char name[30];
        int k;
        VertexType V[30];
        KeyType VR[30][2];
        Set st;
        switch(op){
            case EXIT:
                break;
            case CREATE_GRAPH:
                printf("\n");
                printf("������ͼ������(DG=0,DN=1,UDG=2,UDN=3):");
                scanf("%d", &G.kind);
                printf("�����붥��ؼ��ֺ���Ϣ���� -1 null ��β��\n");
                k = 0;
                scanf("%d %s", &V[k].key, V[k].others);
                while (V[k].key != -1 && k < 30){
                    k ++;
                    scanf("%d %s", &V[k].key, V[k].others);
                }
                printf("������ߣ��� -1 -1 ��β:\n");
                k = 0;
                scanf("%d%d", &VR[k][0], &VR[k][1]);
                while(VR[k][0] != -1 && VR[k][1] != -1 && k < 30){
                    k ++;
                    scanf("%d%d", &VR[k][0], &VR[k][1]);
                }
                states = CreateGraph(G, V, VR, G.kind);
                if(states == ERROR){
                    printf("CreateGraph: Error!\n");
                    printf("����ʧ�ܣ�\n");
                }
                else printf("CreateGraph: Success!\n");
                break;
            case DESTROY_GRAPH:
                printf("\n");
                if(G.vexnum == 0){
                    printf("DestroyGraph: Error!\n");
                    printf("ͼΪ�գ�\n");
                }
                else{
                    states = DestroyGraph(G);
                    printf("DestroyGraph: Success!\n");
                }
                break;
            case LOCATE_VEX:
                printf("\n");
                printf("����������Ҫ���ҵĶ���Ĺؼ��֣�");
                scanf("%d", &e);
                states = LocateVex(G, e);
                if(states == -1){
                    printf("LocateVex: Error!\n");
                    printf("δ���ҵ����㣡\n");
                }
                else printf("�������ҵĶ����λ��Ϊ%d.\n", states);
                break;
            case PUT_VEX:
                printf("\n");
                printf("����������Ҫ�޸ĵĶ���Ĺؼ��֣�");
                scanf("%d", &e);
                printf("�������޸ĺ�Ĺؼ����붥����Ϣ��");
                scanf("%d %s", &value.key, value.others);
                states = PutVex(G, e, value);
                if(states == ERROR){
                    printf("PutVex: Error!\n");
                    printf("δ�ܲ��ҵ�������ؼ��ֲ�Ψһ��\n");
                }
                else printf("PutVex: Success!\n");
                break;
            case FIRST_ADJ_VEX:
                printf("\n");
                printf("�����붥��ؼ��֣�");
                scanf("%d", &e);
                states = FirstAdjVex(G, e);
                if(states == -1){
                    printf("FirstAdjVex: Error!\n");
                    printf("δ���ҵ����㣡\n");
                }
                else printf("�������ҵĽ��ĵ�һ�ڽӵ�λ��Ϊ%d,�ؼ���Ϊ��%d,��ϢΪ��%s.\n", states, G.vertices[states].data.key, G.vertices[states].data.others);
                break;
            case NEXT_ADJ_VEX:
                printf("\n");
                printf("����������鿴�ĸ�������һ�ڽӵ�(����ؼ���):");
                scanf("%d", &v);
                printf("����������鿴������ĸ�������һ�ڽӵ�(����ؼ���):");
                scanf("%d", &w);
                states = NextAdjVex(G, v, w);
                if(states == -1){
                    printf("NextAdjVex: Error!\n");
                    printf("δ�ҵ����㣡\n");
                }
                else printf("�������ҵĽ�����һ�ڽӵ�λ��Ϊ%d,�ؼ���Ϊ��%d,��ϢΪ��%s.\n", states, G.vertices[states].data.key, G.vertices[states].data.others);
                break;
            case INSERT_VEX:
                printf("\n");
                printf("������������ӵĶ���Ĺؼ��ֺ���Ϣ��");
                scanf("%d %s", &value.key, value.others);
                states = InsertVex(G, value);
                if(states == ERROR){
                    printf("InsertVex: Error!\n");
                    printf("δ�ܲ����㣬���������ؼ����Ѿ����ڣ�\n");
                }
                else printf("InsertVex: Success!\n");
                break;
            case DELETE_VEX:
                printf("\n");
                printf("����������ɾ���Ķ���Ĺؼ��֣�");
                scanf("%d", &e);
                states = DeleteVex(G, e);
                if(states == ERROR){
                    printf("DeleteVex: Error!\n");
                    printf("δ��ɾ�����㣬ͼ�����ڻ򶥵㲻���ڣ�\n");
                }
                else printf("DeleteVex: Success!\n");
                break;
            case INSERT_ARC:
                printf("\n");
                printf("�������������ӵĻ���");
                scanf("%d%d", &v, &w);
                states = InsertArc(G, v, w);
                if(states == ERROR){
                    printf("InsertArc: Error!\n");
                    printf("δ�ҵ���ض�����Ѵ��ڣ�\n");
                }
                else printf("InsertArc: Success!\n");
                break;
            case DELETE_ARC:
                printf("\n");
                printf("����������ɾ���Ļ���");
                scanf("%d%d", &v, &w);
                states = DeleteArc(G, v, w);
                if(states == ERROR){
                    printf("DeleteArc: Error!\n");
                    printf("δ�ҵ���ض����δ�ҵ��ߣ�\n");
                }
                else printf("DeleteArc: Success!\n");
                break;
            case DFS_TRAVERSE:
                printf("\n");
                if(G.vexnum == 0){
                    printf("DFSTraverse: Error!\n");
                    printf("ͼ�����ڣ�\n");
                }
                else{
                    states = DFSTraverse(G, visit);
                    printf("\n");
                    printf("DFSTraverse: Success!\n");
                }
                break;
            case BFS_TRAVERSE:
                printf("\n");
                if(G.vexnum == 0){
                    printf("BFSTraverse: Error!\n");
                    printf("ͼ�����ڣ�\n");
                }
                else{
                    states = BFSTraverse(G, visit);
                    printf("\n");
                    printf("BFSTraverse: Success!\n");
                }
                break;
            case VERTICES_SET_LESS_THAN_K:
                printf("\n");
                printf("�����붥��ؼ��֣�");
                scanf("%d", &v);
                printf("������·������С�ڼ���");
                scanf("%d", &k);
                st = VerticesSetLessThanK(G, v, k);
                if(st.setlength == 0)
                    printf("���������������Ķ���.\n");
                else PrintSet(st, G);
                SetDestroy(st);
                break;
            case SHORTEST_PATH_LENGTH:
                printf("\n");
                printf("����������鿴��·���������˵�Ĺؼ��֣�");
                scanf("%d%d", &v, &w);
                states = ShortestPathLength(G, v, w);
                if(states == ERROR){
                    printf("ShortestPathLength: Error!\n");
                    printf("�����ڶ���.\n");
                }
                else if(states == INFINITY) printf("�����㲻�ɴ�.\n");
                else    printf("����������·������Ϊ%d.", states);
                break;
            case CONNECTED_COMPONENTS_NUMS:
                printf("\n");
                states = ConnectedComponentsNums(G);
                printf("��ͨ������ĿΪ%d.", states);
                break;
            case SAVE_GRAPH:
                printf("\n");
                printf("�����뱣����ļ���(������25��Ӣ���ַ�)��");
                scanf("%s", name);
                states = SaveGraph(G, name);
                if(G.vexnum == 0){
                    printf("SaveGraph: Error!\n");
                    printf("ͼ�����ڣ�\n");
                }
                else if(states == ERROR){
                    printf("SaveGraph: Error!\n");
                    printf("�򲻿��ļ���\n");
                }
                else    printf("SaveGraph: Success!\n");
                break;
            case LOAD_GRAPH:
                printf("\n");
                if(G.vexnum != 0){
                    printf("Error!\n");
                    printf("ͼ�Ѵ��ڣ�\n");
                    continue;
                }
                printf("��������ص��ļ�����\n");
                scanf("%s", name);
                states = LoadGraph(G, name);
                if(states == ERROR){
                    printf("LoadGraph: Error!\n");
                    printf("�򲻿��ļ���\n");
                }
                else if(G.vexnum == 0){
                    printf("LoadGraph: Error!\n");
                    printf("ͼΪ�գ�\n");
                }
                else printf("LoadGraph: Success!\n");
                break;
            case MULTI_GRAPH_MANAGEMENT:
                Multi_Graph_management();
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

status Multi_Graph_management()
{
    GRAPHS graphs;
    InitGRAPHS(graphs);
    int op = -1;
    while(op){
        printf("\n\n");
        printf("MENU\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+    1.CreateGraph        11.DFSTraverse            +\n");
        printf("+    2.DestroyGraph       12.BFSTraverse            +\n");
        printf("+    3.LocateVex          13.VerticesSetLessThanK   +\n");
        printf("+    4.PutVex             14.ShortestPathLength     +\n");
        printf("+    5.FirstAdjVex        15.ConnectedComponentsNums+\n");
        printf("+    6.NextAdjVex         16.SaveGraph              +\n");
        printf("+    7.InsertVex          17.LoadGraph              +\n");
        printf("+    8.DeleteVex          18.AddGraph               +\n");
        printf("+    9.InsertArc          19.RemoveGraph            +\n");
        printf("+    10.DeleteArc         20.LocateGraph            +\n");
        printf("+    0.exit                                         +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("������ѡ��[0-20]:");
        scanf("%d", &op);
        int states = 0;
        enum st{
            EXIT = 0, CREATE_GRAPH = 1, DESTROY_GRAPH, LOCATE_VEX, PUT_VEX,
            FIRST_ADJ_VEX, NEXT_ADJ_VEX, INSERT_VEX, DELETE_VEX, INSERT_ARC,
            DELETE_ARC, DFS_TRAVERSE, BFS_TRAVERSE, VERTICES_SET_LESS_THAN_K,
            SHORTEST_PATH_LENGTH, CONNECTED_COMPONENTS_NUMS, SAVE_GRAPH, LOAD_GRAPH,
            ADD_GRAPH, REMOVE_GRAPH, LOCATE_GRAPH
        };
        KeyType e = 0;
        KeyType v;
        KeyType w;
        VertexType value;
        char others[20];
        int pos = 0;
        char name[30];
        char graph_name[30];
        int k;
        int ls_pos;
        VertexType V[30];
        KeyType VR[30][2];
        Set st;
        switch(op){
            case EXIT:
                break;
            case CREATE_GRAPH:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                printf("������ͼ������(DG=0,DN=1,UDG=2,UDN=3):");
                scanf("%d", &graphs.elem[ls_pos-1].Graph.kind);
                printf("�����붥��ؼ��ֺ���Ϣ���� -1 null ��β��\n");
                k = 0;
                scanf("%d %s", &V[k].key, V[k].others);
                while (V[k].key != -1 && k < 30){
                    k ++;
                    scanf("%d %s", &V[k].key, V[k].others);
                }
                printf("������ߣ��� -1 -1 ��β:\n");
                k = 0;
                scanf("%d%d", &VR[k][0], &VR[k][1]);
                while(VR[k][0] != -1 && VR[k][1] != -1 && k < 30){
                    k ++;
                    scanf("%d%d", &VR[k][0], &VR[k][1]);
                }
                states = CreateGraph(graphs.elem[ls_pos-1].Graph, V, VR, graphs.elem[ls_pos-1].Graph.kind);
                if(states == ERROR){
                    printf("CreateGraph: Error!\n");
                    printf("����ʧ�ܣ�\n");
                }
                else printf("CreateGraph: Success!\n");
                break;
            case DESTROY_GRAPH:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0){
                    printf("DestroyGraph: Error!\n");
                    printf("ͼΪ�գ�\n");
                }
                else{
                    states = DestroyGraph(graphs.elem[ls_pos-1].Graph);
                    printf("DestroyGraph: Success!\n");
                }
                break;
            case LOCATE_VEX:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("����������Ҫ���ҵĶ���Ĺؼ��֣�");
                scanf("%d", &e);
                states = LocateVex(graphs.elem[ls_pos-1].Graph, e);
                if(states == -1){
                    printf("LocateVex: Error!\n");
                    printf("δ���ҵ����㣡\n");
                }
                else printf("�������ҵĶ����λ��Ϊ%d.\n", states);
                break;
            case PUT_VEX:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("����������Ҫ�޸ĵĶ���Ĺؼ��֣�");
                scanf("%d", &e);
                printf("�������޸ĺ�Ĺؼ����붥����Ϣ��");
                scanf("%d %s", &value.key, value.others);
                states = PutVex(graphs.elem[ls_pos-1].Graph, e, value);
                if(states == ERROR){
                    printf("PutVex: Error!\n");
                    printf("δ�ܲ��ҵ�������ؼ��ֲ�Ψһ��\n");
                }
                else printf("PutVex: Success!\n");
                break;
            case FIRST_ADJ_VEX:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("�����붥��ؼ��֣�");
                scanf("%d", &e);
                states = FirstAdjVex(graphs.elem[ls_pos-1].Graph, e);
                if(states == -1){
                    printf("FirstAdjVex: Error!\n");
                    printf("δ���ҵ����㣡\n");
                }
                else printf("�������ҵĽ��ĵ�һ�ڽӵ�λ��Ϊ%d,�ؼ���Ϊ��%d,��ϢΪ��%s.\n", states, graphs.elem[ls_pos-1].Graph.vertices[states].data.key, graphs.elem[ls_pos-1].Graph.vertices[states].data.others);
                break;
            case NEXT_ADJ_VEX:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("����������鿴�ĸ�������һ�ڽӵ�(����ؼ���):");
                scanf("%d", &v);
                printf("����������鿴������ĸ�������һ�ڽӵ�(����ؼ���):");
                scanf("%d", &w);
                states = NextAdjVex(graphs.elem[ls_pos-1].Graph, v, w);
                if(states == -1){
                    printf("NextAdjVex: Error!\n");
                    printf("δ�ҵ����㣡\n");
                }
                else printf("�������ҵĽ�����һ�ڽӵ�λ��Ϊ%d,�ؼ���Ϊ��%d,��ϢΪ��%s.\n", states, graphs.elem[ls_pos-1].Graph.vertices[states].data.key, graphs.elem[ls_pos-1].Graph.vertices[states].data.others);
                break;
            case INSERT_VEX:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("������������ӵĶ���Ĺؼ��ֺ���Ϣ��");
                scanf("%d %s", &value.key, value.others);
                states = InsertVex(graphs.elem[ls_pos-1].Graph, value);
                if(states == ERROR){
                    printf("InsertVex: Error!\n");
                    printf("δ�ܲ����㣬���������ؼ����Ѿ����ڣ�\n");
                }
                else printf("InsertVex: Success!\n");
                break;
            case DELETE_VEX:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("����������ɾ���Ķ���Ĺؼ��֣�");
                scanf("%d", &e);
                states = DeleteVex(graphs.elem[ls_pos-1].Graph, e);
                if(states == ERROR){
                    printf("DeleteVex: Error!\n");
                    printf("δ��ɾ�����㣬ͼ�����ڻ򶥵㲻���ڣ�\n");
                }
                else printf("DeleteVex: Success!\n");
                break;
            case INSERT_ARC:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("�������������ӵĻ���");
                scanf("%d%d", &v, &w);
                states = InsertArc(graphs.elem[ls_pos-1].Graph, v, w);
                if(states == ERROR){
                    printf("InsertArc: Error!\n");
                    printf("δ�ҵ���ض�����Ѵ��ڣ�\n");
                }
                else printf("InsertArc: Success!\n");
                break;
            case DELETE_ARC:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("����������ɾ���Ļ���");
                scanf("%d%d", &v, &w);
                states = DeleteArc(graphs.elem[ls_pos-1].Graph, v, w);
                if(states == ERROR){
                    printf("DeleteArc: Error!\n");
                    printf("δ�ҵ���ض����δ�ҵ��ߣ�\n");
                }
                else printf("DeleteArc: Success!\n");
                break;
            case DFS_TRAVERSE:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                else{
                    states = DFSTraverse(graphs.elem[ls_pos-1].Graph, visit);
                    printf("\n");
                    printf("DFSTraverse: Success!\n");
                }
                break;
            case BFS_TRAVERSE:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                else{
                    states = BFSTraverse(graphs.elem[ls_pos-1].Graph, visit);
                    printf("\n");
                    printf("BFSTraverse: Success!\n");
                }
                break;
            case VERTICES_SET_LESS_THAN_K:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("�����붥��ؼ��֣�");
                scanf("%d", &v);
                printf("������·������С�ڼ���");
                scanf("%d", &k);
                st = VerticesSetLessThanK(graphs.elem[ls_pos-1].Graph, v, k);
                if(st.setlength == 0)
                    printf("���������������Ķ���.\n");
                else PrintSet(st, graphs.elem[ls_pos-1].Graph);
                SetDestroy(st);
                break;
            case SHORTEST_PATH_LENGTH:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                printf("����������鿴��·���������˵�Ĺؼ��֣�");
                scanf("%d%d", &v, &w);
                states = ShortestPathLength(graphs.elem[ls_pos-1].Graph, v, w);
                if(states == ERROR){
                    printf("ShortestPathLength: Error!\n");
                    printf("�����ڶ���.\n");
                }
                else if(states == INFINITY) printf("�����㲻�ɴ�.\n");
                else    printf("����������·������Ϊ%d.", states);
                break;
            case CONNECTED_COMPONENTS_NUMS:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0) {
                    printf("Error!\n");
                    printf("ͼΪ�գ�\n");
                    continue;
                }
                states = ConnectedComponentsNums(graphs.elem[ls_pos-1].Graph);
                printf("��ͨ������ĿΪ%d.", states);
                break;
            case SAVE_GRAPH:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                printf("�����뱣����ļ���(������25��Ӣ���ַ�)��");
                scanf("%s", name);
                states = SaveGraph(graphs.elem[ls_pos-1].Graph, name);
                if(graphs.elem[ls_pos-1].Graph.vexnum == 0){
                    printf("SaveGraph: Error!\n");
                    printf("ͼ�����ڣ�\n");
                }
                else if(states == ERROR){
                    printf("SaveGraph: Error!\n");
                    printf("�򲻿��ļ���\n");
                }
                else    printf("SaveGraph: Success!\n");
                break;
            case LOAD_GRAPH:
                printf("\n");
                printf("����������˲�����ͼ����");
                scanf("%s", graph_name);
                ls_pos = LocateGraph(graphs, graph_name);
                if(ls_pos == 0){
                    printf("���������ͼ������.\n");
                    break;
                }
                if(graphs.elem[ls_pos-1].Graph.vexnum != 0) {
                    printf("Error!\n");
                    printf("ͼ�Ѵ��ڣ�\n");
                    continue;
                }
                printf("��������ص��ļ�����\n");
                scanf("%s", name);
                states = LoadGraph(graphs.elem[ls_pos-1].Graph, name);
                if(states == ERROR){
                    printf("LoadGraph: Error!\n");
                    printf("�򲻿��ļ���\n");
                }
                else if(graphs.elem[ls_pos-1].Graph.vexnum == 0){
                    printf("LoadGraph: Error!\n");
                    printf("ͼΪ�գ�\n");
                }
                else printf("LoadGraph: Success!\n");
                break;
            case ADD_GRAPH:
                printf("\n");
                printf("����������ͼ��(25��Ӣ���ַ�����):");
                scanf("%s", graph_name);
                states = AddGraph(graphs, graph_name);
                if(states == OVERFLOW){
                    printf("AddGraph: Error!\n");
                    printf("���������޷�����ӣ�\n");
                }
                else if(states == ERROR){
                    printf("AddGraph: Error!\n");
                    printf("�����ַ��������ޣ�\n");
                }
                else printf("AddGraph: Success!\n");
                break;
            case REMOVE_GRAPH:
                printf("\n");
                printf("����������Ҫɾ����ͼ����");
                scanf("%s", graph_name);
                states = RemoveGraph(graphs, graph_name);
                if(states == ERROR){
                    printf("RemoveGraph: Error!\n");
                    printf("ͼ������!\n");
                }
                else printf("RemoveGraph: Success!\n");
                break;
            case LOCATE_GRAPH:
                printf("\n");
                printf("���������������ͼ����");
                scanf("%s", graph_name);
                states = LocateGraph(graphs, graph_name);
                if(states == 0){
                    printf("LocateGraph: Error!\n");
                    printf("ͼ�����ڣ�\n");
                }
                else printf("�������ҵ�ͼ�ڵ�%d��λ��.\n", states);
                break;
            default:
                printf("\n");
                printf("����ѡ��Ӧ����[0-20]�ķ�Χ�ڣ�\n");
                break;
        }
        while(getchar() != '\n');//��տ���̨���ַ��ȷǷ��ַ�
        if(op != 0) op = -1; //��ֹop��δ�ı����ڶ������ʱδ����ֵ��������һ���Ĳ���
    }
}
void visit(VertexType v)
{
    printf("%d %s ", v.key, v.others);
    return;
}

/******�������к���******/
status InitQueue(LinkQueue &Q)
{
    Q.front = (QNode *) malloc(sizeof(QNode));
    if(!Q.front)
        exit(OVERFLOW);
    Q.rear = Q.front;
    Q.front->next = NULL;
    return OK;
}

status EnQueue(LinkQueue &Q, QElemType elem)
{
    QNode *s = (QNode*) malloc(sizeof(QNode));
    if(!s) exit(OVERFLOW);
    s->data = elem;
    s->next = Q.rear->next;
    Q.rear->next = s;
    Q.rear = s;
    return OK;
}

status DeQueue(LinkQueue &Q, QElemType &elem)
{
    if(Q.front == Q.rear)   return ERROR;
    elem = Q.front->next->data;

    QNodePtr p = Q.front->next;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    p = NULL;
}

status QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    return FALSE;
}

status DestroyQueue(LinkQueue &Q)
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

/******����******/
status SetInit(Set &set)
{
    set.elem = (SetElemType *) malloc(sizeof(SetElemType) * SET_INIT_SIZE);
    if(!set.elem)
        exit(OVERFLOW);
    set.setlength = 0;
    set.setsize = SET_INIT_SIZE;
    return OK;
}

status SetInsert(Set &set, SetElemType elem)
{
    if(!set.elem)   return INFEASIBLE;
    if(set.setsize == set.setlength){
        set.elem = (SetElemType *) realloc(set.elem, sizeof(SetElemType)*(set.setsize + SETINCREMENT));
        if(set.elem == NULL)
            exit(OVERFLOW);
        set.setsize += SETINCREMENT;
    }
    set.elem[set.setlength] = elem;
    set.setlength ++;
    return OK;
}

status SetDestroy(Set &set)
{
    free(set.elem);
    set.setlength = 0;
    set.setsize = 0;
    return OK;
}

void PrintSet(Set set, ALGraph G)
{
    if(set.setlength == 0){
        printf("None!\n");
        return;
    }
    for(int i = 0; i < set.setlength; i ++){
        printf("%d ", set.elem[i]);
        int pos_elem = 0;
        for(;pos_elem < G.vexnum; pos_elem ++){
            if(G.vertices[pos_elem].data.key == set.elem[i])
                break;
        }
        printf("%s ", G.vertices[pos_elem].data.others);
        printf("%c", (i == set.setlength-1) ? '\n' : ' ');
    }
    return;
}
/************/

status CreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2], GraphKind kind)
/*����V��VR����ͼT������OK�����V��VR����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
{
    G.kind = kind;
    for(VertexType *p = V; p->key != -1; p ++){
        for(VertexType *q = V; q < p; q ++){
            if(p->key == q->key)
                return ERROR;
        }
    }
    for(int i = 0; VR[i][0] != -1 && VR[i][1] != -1; i ++){
        for(int j = 0; j < i; j ++){
            if(VR[i][0] == VR[j][0] && VR[i][1] == VR[j][1])
                return ERROR;
        }
    }
    int cnt = 0;
    while(V[cnt].key != -1)   cnt ++;
    if(cnt > MAX_VERTEX_NUM || cnt == 0)    return ERROR;
    G.vexnum = cnt;
    for(int i = 0; i < G.vexnum; i ++){
        G.vertices[i].data.key = V[i].key;
        strcpy(G.vertices[i].data.others, V[i].others);
        G.vertices[i].firstarc = NULL;
    }
    int i = 0;
    while(VR[i][0] != -1 && VR[i][1] != -1){
        int v = LocateVex(G, VR[i][0]);
        int w = LocateVex(G, VR[i][1]);
        if(v == -1 || w == -1 || v >= G.vexnum || w >= G.vexnum)  return ERROR;
        ArcNode *s = (ArcNode*) malloc(sizeof(ArcNode));
        s->adjvex = w;
        s->nextarc = G.vertices[v].firstarc;
        G.vertices[v].firstarc = s;
        G.arcnum ++;
        if(G.kind == UDN || G.kind == UDG){
            s = (ArcNode *) malloc(sizeof(ArcNode));
            s->adjvex = v;
            s->nextarc = G.vertices[w].firstarc;
            G.vertices[w].firstarc = s;
        }
        i ++;
    }
    return OK;
}

status DestroyGraph(ALGraph &G)
/*��������ͼG,ɾ��G��ȫ������ͱ�*/
{
    for(int pos = 0; pos < G.vexnum; pos ++){
        ArcNode *p = G.vertices[pos].firstarc;
        while(p){
            G.vertices[pos].firstarc = p->nextarc;
            free(p);
            p = G.vertices[pos].firstarc;
        }
        p = NULL;
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
}

int LocateVex(ALGraph G,KeyType u)
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
{
    int pos = -1;
    for(int i = 0; i < G.vexnum; i ++){
        if(G.vertices[i].data.key == u){
		    pos = i;
            break; 
    	}
    }
    return pos;
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
{
    int pos = -1;
    int cnt = 0;
    for(int i = 0; i < G.vexnum; i ++){
        if(G.vertices[i].data.key == u){
            cnt ++;
            pos = i;
        }
        if(G.vertices[i].data.key == value.key && value.key != u)
            return ERROR;
    }
    if(cnt != 1)    return ERROR;
    G.vertices[pos].data.key = value.key;
    strcpy(G.vertices[pos].data.others, value.others);
    return OK;
}

int FirstAdjVex(ALGraph G,KeyType u)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
{
    int pos = -1;
    for(int i = 0; i < G.vexnum; i ++){
        if(G.vertices[i].data.key == u)
        {
		    pos = i;
		    break;
		}
    }
    if(pos == -1)   return pos;
    if(G.vertices[pos].firstarc == NULL)    return -1;
    else return G.vertices[pos].firstarc->adjvex;
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v��ӦG��һ������,w��Ӧv���ڽӶ��㣻��������Ƿ���v�ģ������w����һ���ڽӶ����λ�����w�����һ���ڽӶ��㣬��v��w��Ӧ���㲻���ڣ��򷵻�-1��
{
    int vex = 0;
    for(; vex < G.vexnum; vex ++){
        if(G.vertices[vex].data.key == v){
            ArcNode *p;
            for(p = G.vertices[vex].firstarc; p->nextarc != NULL; p = p->nextarc){
                if(G.vertices[p->adjvex].data.key == w)  return p->nextarc->adjvex;
            }
            return -1;
        }
    }
    return -1;
}

status InsertVex(ALGraph &G,VertexType v)
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
    if(G.vexnum >= MAX_VERTEX_NUM)  return ERROR;
    for(int i = 0; i < G.vexnum; i ++){
        if(G.vertices[i].data.key == v.key) return ERROR;
    }
    G.vertices[G.vexnum].data.key = v.key;
    strcpy(G.vertices[G.vexnum].data.others, v.others);
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum ++;
    return OK;
}

status DeleteVex(ALGraph &G,KeyType v)
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
{
    if(G.vexnum == 0 || G.vexnum == 1)   return ERROR;
    int pos = 0;
    while(pos < G.vexnum){
        if(G.vertices[pos].data.key == v)
            break;
        pos ++;
    }
    if(pos == G.vexnum) return ERROR;
    ArcNode *p = G.vertices[pos].firstarc;
    while(p){
        G.vertices[pos].firstarc = p->nextarc;
        free(p);
        p = G.vertices[pos].firstarc;
        G.arcnum --;
    }
    for(int i = pos + 1; i < G.vexnum; i ++){
        G.vertices[i - 1].data.key = G.vertices[i].data.key;
        strcpy(G.vertices[i-1].data.others, G.vertices[i].data.others);
        G.vertices[i-1].firstarc = G.vertices[i].firstarc;
    }
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum --;
    for(int i = 0; i < G.vexnum; i ++){
        p = G.vertices[i].firstarc;
        while(p && p->adjvex == pos){
            G.vertices[i].firstarc = p->nextarc;
            free(p);
            p = G.vertices[i].firstarc;
            if(G.kind == DG || G.kind == DN)    G.arcnum --;
        }
        while(p){
            if(p->adjvex > pos) p->adjvex --;
            if(p->nextarc && p->nextarc->adjvex == pos){
                ArcNode *s = p->nextarc;
                p->nextarc = s->nextarc;
                free(s);
                if(G.kind == DG || G.kind == DN)    G.arcnum --;
                s = NULL;
            }
            p = p->nextarc;
        }
    }
    return OK;
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
    if(G.vexnum == 1 || G.vexnum == 0)  return ERROR;
    int pos = 0;
    for(; pos < G.vexnum; pos ++){
        if(G.vertices[pos].data.key == v)
            break;
    }
    if(pos == G.vexnum) return ERROR;

    int pos1 = 0;
    for(; pos1 < G.vexnum; pos1 ++){
        if(G.vertices[pos1].data.key == w)
            break;
    }
    if(pos1 == G.vexnum)    return ERROR;

    for(ArcNode *s = G.vertices[pos].firstarc; s != NULL; s = s->nextarc){
        if(s->adjvex == pos1)  return ERROR;
    }

    ArcNode *p = (ArcNode*) malloc(sizeof(ArcNode));
    p->adjvex = pos1;
    p->nextarc = G.vertices[pos].firstarc;
    G.vertices[pos].firstarc = p;


    if(G.kind == UDG || G.kind == UDN){
        p = (ArcNode*) malloc(sizeof(ArcNode));
        p->adjvex = pos;
        p->nextarc = G.vertices[pos1].firstarc;
        G.vertices[pos1].firstarc = p;
    }
    G.arcnum ++;
    return OK;
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
{
    if(G.vexnum == 1 || G.vexnum == 0)  return ERROR;

    int pos_v = 0;
    int pos_w = 0;
    for(pos_v; pos_v < G.vexnum; pos_v ++){
        if(G.vertices[pos_v].data.key == v)
            break;
    }
    if(pos_v == G.vexnum)   return ERROR;
    for(pos_w; pos_w < G.vexnum; pos_w ++){
        if(G.vertices[pos_w].data.key == w)
            break;
    }
    if(pos_w == G.vexnum)   return ERROR;

    ArcNode *p = G.vertices[pos_v].firstarc;
    if(p->adjvex == pos_w){
        G.vertices[pos_v].firstarc = p->nextarc;
        free(p);
        p = NULL;
        G.arcnum --;
    }
    else{
        while(p->nextarc && p->nextarc->adjvex != pos_w)
            p = p->nextarc;
        if(p->nextarc == NULL)  return ERROR;
        ArcNode *s = p->nextarc;
        p->nextarc = s->nextarc;
        free(s);
        s = NULL;
        G.arcnum --;
    }

    if(G.kind == UDG || G.kind == UDN){
        p = G.vertices[pos_w].firstarc;
        if(p->adjvex == pos_v){
            G.vertices[pos_w].firstarc = p->nextarc;
            free(p);
            p = NULL;
        }
        else{
            while(p->nextarc && p->nextarc->adjvex != pos_v)
                p = p->nextarc;
            ArcNode *s = p->nextarc;
            p->nextarc = s->nextarc;
            free(s);
            s = NULL;
        }
    }
    return OK;
}

void DFS(ALGraph G, int pos, void (*visit)(VertexType))
{
    visit(G.vertices[pos].data);
    visited[pos] =   TRUE;
    for(int w = FirstAdjVex(G, G.vertices[pos].data.key); w >= 0; w = NextAdjVex(G, G.vertices[pos].data.key, G.vertices[w].data.key)){
        if(visited[w] == FALSE)
            DFS(G, w, visit);
    }
}

status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    visited = (BOOL *) malloc(sizeof(BOOL) * (G.vexnum + 5));
    for(int i = 0; i < G.vexnum; i ++)
        visited[i] = FALSE;
    for(int v = 0; v < G.vexnum; v ++){
        if(visited[v] == FALSE)
            DFS(G, v, visit);
    }
    free(visited);
    return OK;
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    visited = (BOOL *) malloc(sizeof(BOOL) * (G.vexnum + 5));
    for(int i = 0; i < G.vexnum; i ++)
        visited[i] = FALSE;
    LinkQueue Q;
    InitQueue(Q);
    for(int pos = 0; pos < G.vexnum; pos ++){
        if(visited[pos] == FALSE){
            visit(G.vertices[pos].data);
            visited[pos] = TRUE;
            EnQueue(Q, pos);
            while(!QueueEmpty(Q)){
                int v = -1;
                DeQueue(Q, v);
                for(int w = FirstAdjVex(G, G.vertices[v].data.key); w >= 0; w = NextAdjVex(G, G.vertices[v].data.key, G.vertices[w].data.key)){
                    if(visited[w] == FALSE){
                        visit(G.vertices[w].data);
                        visited[w] = TRUE;
                        EnQueue(Q, w);
                    }
                }
            }
        }
    }
    DestroyQueue(Q);
    free(visited);
    return OK;
}

status SaveGraph(ALGraph G, char FileName[])
//��ͼ������д�뵽�ļ�FileName��
{
    FILE *fp = fopen(FileName, "w");
    if(!fp) return ERROR;
    fprintf(fp, "%d %d %d ", G.kind, G.vexnum, G.arcnum);;
    for(int i = 0; i < G.vexnum; i ++){
        fprintf(fp, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    fprintf(fp, "-1 nil ");
    for(int i = 0; i < G.vexnum; i ++){
        ArcNode *p = G.vertices[i].firstarc;
        while(p){
            fprintf(fp, "%d %d ", i, p->adjvex);
            p = p->nextarc;
        }
    }
    fprintf(fp, "-1 -1");
    fclose(fp);
    return OK;
}

status LoadGraph(ALGraph &G, char FileName[])
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
{
    VertexType V;
    KeyType VR[2];
    FILE *fp = fopen(FileName, "r");
    if(!fp) return ERROR;
    fscanf(fp, "%d", &G.kind);
    fscanf(fp, "%d%d", &G.vexnum, &G.arcnum);
    int i = 0;
    while(fscanf(fp, "%d %s", &V.key, V.others) && V.key != -1){
        G.vertices[i].data.key = V.key;
        strcpy(G.vertices[i].data.others, V.others);
        G.vertices[i].firstarc = NULL;
        i ++;
    }
    while(fscanf(fp, "%d%d", &VR[0], &VR[1]) && VR[0] != -1){
        ArcNode *p = (ArcNode *) malloc(sizeof(ArcNode));
        p->adjvex = VR[1];
        ArcNode *s = G.vertices[VR[0]].firstarc;
        while(s &&s->nextarc != NULL)   s = s->nextarc;
        if(s == NULL){
            p->nextarc = NULL;
            G.vertices[VR[0]].firstarc = p;
        }
        else{
            s->nextarc = p;
            p->nextarc = NULL;
        }
    }
    fclose(fp);
    return OK;
}

Set VerticesSetLessThanK(ALGraph G, KeyType v, int k)
{
    Set set;
    SetInit(set);
    for(int i = 0; i < G.vexnum; i ++){
        if(ShortestPathLength(G, v, G.vertices[i].data.key) < k){
            SetInsert(set, G.vertices[i].data.key);
        }
    }
    return set;
}

int ShortestPathLength(ALGraph G, KeyType v, KeyType w)
//�ӹؼ���Ϊv�Ķ��㵽�ؼ���Ϊw�Ķ�������·������
{
    int pos_v = 0;
    int pos_w = 0;
    for(pos_v; pos_v < G.vexnum; pos_v ++){
        if(G.vertices[pos_v].data.key == v)
            break;
    }
    if(pos_v == G.vexnum)   return ERROR;
    for(pos_w; pos_w < G.vexnum; pos_w ++){
        if(G.vertices[pos_w].data.key == w)
            break;
    }
    if(pos_w == G.vexnum)   return ERROR;

    int *d = (int *) malloc(sizeof(int) * (G.vexnum+5));
    for(int i = 0; i < G.vexnum; i ++)
        d[i] = INFINITY;
    LinkQueue Q;
    InitQueue(Q);
    d[pos_v] = 0;
    EnQueue(Q, pos_v);
    while(!QueueEmpty(Q)){
        int pos_next;
        DeQueue(Q, pos_next);
        if(pos_next == pos_w)
            break;
        for(int ww = FirstAdjVex(G, G.vertices[pos_next].data.key); ww >= 0; ww = NextAdjVex(G, G.vertices[pos_next].data.key, G.vertices[ww].data.key)){
//            int pos_ww;
//            for(pos_ww = 0; pos_ww < G.vexnum; pos_ww ++){
//                if(G.vertices[pos_ww].data.key == ww)
//                    break;
//            }
            if(d[ww] == INFINITY){
                d[ww] = d[pos_next] + 1;
                EnQueue(Q, ww);
            }
        }
    }
    int n = d[pos_w];
    free(d);
    DestroyQueue(Q);
    return n;
}

void DFS_CCN(ALGraph G, int pos)
{
    visited[pos] = TRUE;
    for(int w = FirstAdjVex(G, G.vertices[pos].data.key); w >= 0; w = NextAdjVex(G, G.vertices[pos].data.key, G.vertices[w].data.key)){
        if(visited[w] == FALSE)
            DFS_CCN(G, w);
    }
}

int ConnectedComponentsNums(ALGraph G)
{
    visited = (int *) malloc(sizeof(int) * (G.vexnum + 5));
    int cnt = 0;
    for(int i = 0; i < G.vexnum; i ++)
        visited[i] = FALSE;
    for(int v = 0; v < G.vexnum; v ++){
        if(visited[v] == FALSE) {
            cnt ++;
            DFS_CCN(G, v);
        }
    }
    free(visited);
    return cnt;
}

status AddGraph(GRAPHS &graphs, char GraphName[])
{
    if(graphs.length == graphs.listsize)
        return OVERFLOW;
    int i = 0;
    while(GraphName[i]) i ++;
    if(i >= 30) return ERROR;
    strcpy(graphs.elem[graphs.length].name, GraphName);
    graphs.elem[graphs.length].Graph.vexnum = 0;
    graphs.elem[graphs.length].Graph.arcnum = 0;
    graphs.length ++;
    return OK;
}
status RemoveGraph(GRAPHS &graphs, char GraphName[])
{
    int pos = 0;
    while(pos < graphs.length && strcmp(graphs.elem[pos].name, GraphName))
        pos ++;
    if(pos == graphs.length)    return ERROR;
    DestroyGraph(graphs.elem[pos].Graph);
    for (int i = pos; i < graphs.length - 1; i ++) {
        strcpy(graphs.elem[i].name, graphs.elem[i+1].name);
        graphs.elem[i].Graph = graphs.elem[i+1].Graph;
    }
    graphs.length --;
    return OK;
}
int LocateGraph(GRAPHS &graphs, char GraphName[])
{
    int pos = 0;
    while(pos < graphs.length && strcmp(graphs.elem[pos].name, GraphName))
        pos ++;
    if(pos == graphs.length)
        return 0;
    return pos + 1;
}

status InitGRAPHS(GRAPHS &graphs)
{
    graphs.listsize = 100;
    graphs.length = 0;
    return OK;
}
