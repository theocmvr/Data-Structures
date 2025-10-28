#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    struct Node* next;
    char letra;
} Node;
typedef struct Stack{
    Node* top;
} Stack;
Stack* createStack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return s;
    s->top = NULL;
    return s;
}
void pop(Stack* s){
    if (s == NULL || s->top == NULL) return;
    Node* temp = s->top;
    s->top = temp->next;
    free(temp);
}
void push(Stack* s, char c){
    if (s == NULL) return;
    Node* newNode = (Node* )malloc(sizeof(Node));
    newNode->letra = c;
    newNode->next = s->top;
    s->top = newNode;
}
void freeStack(Stack* s) {
    while (s->top != NULL)
        pop(s);
    free(s);
}
char peak(Stack* s){
    if (s->top == NULL) return 'a';
    return s->top->letra;
}
int main(){
    int n;
    scanf("%d", &n);
    getchar();
    int aux = 1;
    while(n--){
        aux = 1;
        Stack* s = createStack();
        char string[129];
        fgets(string, 129, stdin);
        for(int i = 0; i < (int)strlen(string)-1; i++){
            //printf("Iterando\n");
            if (string[i] == '(' || string[i] == '['){
                //printf("Este caractere entrou na stack: %c\n", string[i]);
                push(s, string[i]);
            } else {
                if (peak(s) != 'a' && (string[i] == ']' && peak(s) == '[' || string[i] == ')' && peak(s) == '(')){
                    //printf("Casal formado!\n");
                    pop(s);
                } else {
                    aux = 0;
                    //printf("Este caractere vai ser comparado agora: %c\n", string[i]);
                    printf("No\n");
                    break;
                }
            }
        }
        if(aux) printf("Yes\n");
        freeStack(s);
    }
}