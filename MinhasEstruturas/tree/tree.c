#include "tree.h"

Node* makeNode(int data){
    Node* new = malloc(sizeof(Node));
    if (new == NULL) return NULL;
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
Node* insert(Node* node, int data){
    if (node == NULL) return makeNode(data);
    if (node->data > data) node->left = insert(node->left, data);
    else if (node->data < data) node->right = insert(node->right, data);
    return node;
}
void dfp(Node* node){
    if (node == NULL) return;
    dfp(node->left);
    printf("%d ", node->data);
    dfp(node->right);
}
int height(Node* root){
    if (!root) return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    if (hl > hr) return hl+1;
    return hr+1;
}
void printtree(Node* root){
    printf("(");
    if (!root){
        printf(")\n");
        return;
    }
    printf("%d", root->data);
    printf(" ");
    printtree(root->left);
    printf(" ");
    printtree(root->right);
    printf(")\n");
}
