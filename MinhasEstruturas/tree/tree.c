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
        printf(")");
        return;
    }
    printf("%d", root->data);
    printf(" ");
    printtree(root->left);
    printf(" ");
    printtree(root->right);
    printf(")");
}
void in(Node* node){
    if (!node) return;
    in(node->left);
    printf("%d ", node->data);
    in(node->right);
}
void pre(Node* node){
    if (!node) return;
    printf("%d", node->data); 
    pre(node->left);
    pre(node->right);
}
void pos(Node* node){
    if (!node) return;
    pos(node->left);
    pos(node->right);
    printf("%d ", node->data);
}
Node* dfs(Node* root, int val){
    if(!root || root->data == val) return root;
    if (root->data > val) return dfs(root->left, val);
    return dfs(root->right, val);
}
Node* min(Node* root) {
    if (!root) return NULL;
    Node* atual = root;
    while (atual->left) {
        atual = atual->left;
    }
    return atual;
}

Node* remove(Node* root, int val){
    if (!root) return NULL;
    if (val < root->data) root->left = remove(root->left, val);
    else if(val > root->data)root->right = remove(root->right, val);
    else {
        if (!root->left && !root->right){
            free(root);
            return NULL;
        }
        if (!root->left){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (!root->right){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* next = min(root->right);
        root->data = next->data;
        root->right = remove(root->right, next->data);
    }
    return root;
}
