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
