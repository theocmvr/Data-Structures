#include "tree.h"
int main(){
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 28);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 196);
    dfp(root);
    printf("\n");
    return 0;
}