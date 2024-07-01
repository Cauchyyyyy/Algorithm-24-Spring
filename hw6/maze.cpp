#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int value=0;
    int depth=0;
    struct node* next=NULL;
    int color=0;
};

int main(){
    int N,M,S,T;
    cin>>N>>M>>S>>T;
    if(S==T){
        cout<<"0";
        return 0;
    }
    vector<struct node> edges(N);
    for (int i = 0; i < N; i++)
    {
       edges[i].value=i+1;
    }
    
    for(int i=0;i<M;i++){
        int a=0,b=0;
        cin>>a>>b;        
            auto temp=new struct node ;
            temp->value=b;
            temp->next=edges[a-1].next;
            if(edges[a-1].next==NULL||edges[a-1].next->value!=b){
                edges[a-1].next=temp;
            }
            
               
    }
    //breadth first search
    queue<struct node> Q;
    Q.push(edges[S-1]);
    while(!Q.empty()){
        auto temp=Q.front();
        auto vertex=Q.front();
        Q.pop();
        
        while(temp.next!=NULL){
            temp=*temp.next;
            if(edges[temp.value-1].color==0){
                edges[temp.value-1].color=1;
                edges[temp.value-1].depth=edges[vertex.value-1].depth+1;
                Q.push(edges[temp.value-1]);
            }
            
        }
        edges[vertex.value-1].color=2;
    }
    if(edges[T-1].depth==0){
        cout<<"-1";
        return 0;
    }
    cout<<edges[T-1].depth;
    return 0;
}
