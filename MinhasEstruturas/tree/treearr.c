#include "treearr.h"

int tree[1001];

void criaTree() {
    for (int i = 0; i < 1001; i++)
        tree[i] = -1;
}
int cria_no(int data) {
    tree[1] = data;
    return 1;
}
int insere(int idx, int data) {
    if (idx >= 1001) return -1;
    if (tree[idx] == -1) {
        tree[idx] = data;
        return idx;
    }
    if (data < tree[idx]) return insere(idx * 2, data);
    return insere(idx * 2 + 1, data);
}
void ordem(int idx) {
    if (idx >= 1001 || tree[idx] == -1) return;
    ordem(idx * 2);
    printf("%d ", tree[idx]);
    ordem(idx * 2 + 1);
}
void pre_ordem(int idx) {
    if (idx >= 1001 || tree[idx] == -1) return;
    printf("%d ", tree[idx]);
    pre_ordem(idx * 2);
    pre_ordem(idx * 2 + 1);
}
void pos_ordem(int idx) {
    if (idx >= 1001|| tree[idx] == -1) return;
    pos_ordem(idx * 2);
    pos_ordem(idx * 2 + 1);
    printf("%d ", tree[idx]);
}
int idxmin(int idx) {
    if (idx >= 1001 || tree[idx] == -1) return -1;
    while (idx * 2 < 1001 && tree[idx * 2] != -1) idx = idx * 2;
    return idx;
}
int remover(int idx, int value) {
    if (idx >= 1001 || tree[idx] == -1) return -1;
    if (value < tree[idx]) return remover(idx * 2, value);
    else if (value > tree[idx]) return remover(idx * 2 + 1, value);
    else {
        int left = idx * 2;
        int right = idx * 2 + 1;
        if ((left >= 1001 || tree[left] == -1) && (right >= 1001 || tree[right] == -1))
        {
            tree[idx] = -1;
            return idx;
        }
        if (left >= 1001 || tree[left] == -1) {
            tree[idx] = tree[right];
            remover(right, tree[right]);
            return idx;
        }
        if (right >= 1001 || tree[right] == -1) {
            tree[idx] = tree[left];
            remover(left, tree[left]);
            return idx;
        }
        int succ = idxmin(right);
        tree[idx] = tree[succ];
        remover(succ, tree[succ]);
        return idx;
    }
}
int DFS(int idx, int value) {
    if (idx >= 1001 || tree[idx] == -1) return -1;
    if (tree[idx] == value) return idx;
    int left = DFS(idx * 2, value);
    if (left != -1) return left;
    return DFS(idx * 2 + 1, value);
}
int BFS(int idx, int value) {
    if (idx >= 1001 || tree[idx] == -1) return -1;
    int q[1001], front = 0, back = 0;
    q[back++] = idx;
    while (front < back) {
        int u = q[front++];
        if (tree[u] == value) return u;
        int L = u * 2;
        int R = u * 2 + 1;
        if (L < 1001 && tree[L] != -1) q[back++] = L;
        if (R < 1001 && tree[R] != -1) q[back++] = R;
    }
    return -1;
}


