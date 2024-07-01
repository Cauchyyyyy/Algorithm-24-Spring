#include <stdio.h>
#include <stdlib.h>

//given a set of numbers, construct a BST by their absolute values, 
//then if <0, mean red, else black, check if the BST is a red-black tree
//somewhere goes wrong, but I don't know why
//another version is the answer
struct Node {
    long data=0;
    struct Node* left=NULL;
    struct Node* right=NULL;
    char color='B'; 
};

struct Node* newNode(long data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    if(data<0)
        {temp->color = 'R'; }// Initially, all nodes are marked red
    else
        {temp->color='B';}
    return temp;
}

// Function to construct the BST
struct Node* constructBST(struct Node* root, long keys[],long n) {
    for(long i=0;i<n;i++){
        auto temp=newNode(keys[i]);
        auto temp2=root;
        if(root==NULL){
            root=temp;
            continue;
        }
        while(temp!=NULL){            
            if(abs(temp->data)>abs(temp2->data)){
                if(temp2->right==NULL){
                    temp2->right=temp;
                    break;
                }
                else{
                    temp2=temp2->right;
                }
            }
            else{
                if(temp2->left==NULL){
                    temp2->left=temp;
                    break;
                }
                else{
                    temp2=temp2->left;
                }
            }
        }
    }
    return root;
}


long countBlackNodes(struct Node* root) {
    // Count NULL nodes as black
    if (root == NULL)
    {    
        return 1; 
    }
    long leftBlackNodes = countBlackNodes(root->left);
    long rightBlackNodes = countBlackNodes(root->right);
    if (leftBlackNodes != rightBlackNodes || leftBlackNodes == -1 || rightBlackNodes == -1)
    { 
        return -1; 
    }
    return root->color == 'B' ? leftBlackNodes + 1 : leftBlackNodes; 
    
}


int isRedBlackTree(struct Node* root) {
    if(root==NULL){
        return 1;
    }
    if (countBlackNodes(root) == -1){
        return 0;
    }
    // Property 4: If a node is red, then both its children are black
    if(root->color=='R'){
        if(root->left!=NULL){
            if(root->left->color=='R'){
                return 0;
            }
        }
        if(root->right!=NULL){
            if(root->right->color=='R'){
                return 0;
            }
        }
    }
    return isRedBlackTree(root->left) && isRedBlackTree(root->right);
}



int main() {
    
    long t=0;
    scanf("%d",&t);
    while(t){
        struct Node* root = NULL;
        t--;

        long n=0;
        scanf("%d",&n);
        long keys[n];
        for(long i=0;i<n;i++){
            scanf("%d",&keys[i]);
        }
        
        bool flag=true;
        if(keys[0]<0){
            flag=false;            
        }
        for(int i=0;i<n;i++){
            if(keys[i]==0){
                flag=false;
                break;
            }
        }
        if(!flag){
            printf("N\n");
            continue;
        }
        root=constructBST(root,keys,n);
        if(isRedBlackTree(root)){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}

