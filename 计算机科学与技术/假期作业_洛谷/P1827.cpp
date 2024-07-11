#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct BiNode{
    char val;
    struct BiNode* left, *right;
}BiNode, *BiTree;

void postorder(BiTree T){
    if(T){
        postorder(T->left);
        postorder(T->right);
        printf("%c", T->val);
    }
    return;
}

BiTree buildTree(char* preorder, int preorderSize, char* inorder, int inorderSize) {
    if(inorderSize == 0)    return NULL;
    int a = preorder[0];
    BiTree T = (BiTree) malloc(sizeof(BiNode));
    T->val = a;
    int i = 0;
    while(*(inorder+i) != *preorder) i++;
    T->left = buildTree(preorder+1, i, inorder, i);
    T->right = buildTree(preorder+1+i, inorderSize-i-1, inorder+i+1, inorderSize-i-1);
    return T;
}

void DelEnter(char*& s){
    int pos = 0;
    while(*(s + pos) != '\n') pos ++;
    *(s+pos) = '\0';
}

int main(){
    char *pre = (char*) malloc(sizeof(char)* 30);
    char *in = (char*) malloc(sizeof(char)* 30);
    fgets(in, 28, stdin);
    fgets(pre, 28, stdin);
    DelEnter(in);
    DelEnter(pre);
    BiTree T;
    int len = 0;
    while(pre[len]) len ++;
    T = buildTree(pre, len, in, len);
    postorder(T);
    // printf("\n");
    // system("pause");
    return 0;
}