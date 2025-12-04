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
void dfp(Node* no);

#endif