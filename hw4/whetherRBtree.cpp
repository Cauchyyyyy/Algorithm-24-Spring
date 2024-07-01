#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int value;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node* create_node(int value, Color color) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->color = color;
    node->left = node->right = node->parent = NULL;
    return node;
}

void insert(Node** root, int value) {
    Node* new_node = create_node(abs(value), value < 0 ? RED : BLACK);
    if (*root == NULL) {
        *root = new_node;
        return;
    }

    Node* current = *root;
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (new_node->value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    new_node->parent = parent;
    if (new_node->value < parent->value) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

int is_red_black_tree(Node* root) {
    if (root == NULL) {
        return 1;
    }

    if (root->color == RED && (root->left != NULL && root->left->color == RED || root->right != NULL && root->right->color == RED)) {
        return 0;
    }

    if (root->left != NULL && root->left->parent != root) {
        return 0;
    }

    if (root->right != NULL && root->right->parent != root) {
        return 0;
    }

    return is_red_black_tree(root->left) && is_red_black_tree(root->right);
}

int main() {
    int t=0;
    scanf("%d",&t);
    while(t){
        t--;
        int n;    
        scanf("%d", &n);

        int* numbers = (int*)malloc(n * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }

        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            insert(&root, numbers[i]);
        }

        if (is_red_black_tree(root)) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
