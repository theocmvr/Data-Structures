#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
} Node;
Node* makeNode(int data);
Node* insert(Node* no, int data);
int height(Node* root);
void printtree(Node* root);
void in(Node* root);
void pre(Node* root);
void pos(Node* root);\
void remove();
Node* dfs(Node* root, int val);
Node* bfs(Node* root, int val);
#endif