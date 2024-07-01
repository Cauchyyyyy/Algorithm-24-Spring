#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct Interval {
    int low;
    int high;
} Interval;

// Structure to represent a node in the interval tree
typedef struct Node {
    Interval *interval;
    int max;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new interval node
Node* newNode(Interval *interval) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->interval = interval;
    node->max = interval->high;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new interval into the interval tree
Node* insert(Node *root, Interval *interval) {
    if (root == NULL)
        return newNode(interval);

    int l = root->interval->low;

    if (interval->low < l) {
        root->left = insert(root->left, interval);
    } else {
        root->right = insert(root->right, interval);
    }

    if (root->max < interval->high)
        root->max = interval->high;

    return root;
}

// Function to check if two intervals overlap
int doOverlap(Interval *interval1, Interval *interval2) {
    if (interval1->low <= interval2->high && interval2->low <= interval1->high)
        return 1;
    return 0;
}

// Function to check if the given interval overlaps with any interval in the tree
int checkOverlap(Node *root, Interval *interval) {
    if (root == NULL)
        return 0;

    if (doOverlap(root->interval, interval))
        return -1;

    if (root->left != NULL && root->left->max >= interval->low)
        return checkOverlap(root->left, interval);

    return checkOverlap(root->right, interval);
}

int main() {
    Node *root = NULL;
    int n=0;
    scanf("%d", &n);
    
    // Inserting intervals one by one and checking for overlap
    Interval intervals[n];
    for(int i=0;i<n;i++){
        int a=0,b=0;
        scanf("%d %d",&a,&b);
        intervals[i].low=a;
        intervals[i].high=b;
    }

    for (int i = 0; i < n; i++) {
        int result = checkOverlap(root, &intervals[i]);
        printf("%d\n", result);
        if(result == 0)
            root = insert(root, &intervals[i]);
        
    }

    return 0;
}
