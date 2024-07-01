#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int value=0;
    int depth=0;
    struct node* next=NULL;
    int color=0;
    int start=0;
    int end=0;
};
int times=0;


void dfs_visit(vector<struct node> &edges,struct node &node){
    node.color=1;
    times++;
    node.start=times;
    auto temp=node;
    while(temp.next!=NULL){
        temp=*temp.next;
        if(edges[temp.value-1].color==0){
            dfs_visit(edges,edges[temp.value-1]);
        }
    }
    node.color=2;
    times++;
    node.end=times;
}
int depthFirstSearch(vector<struct node> &edges,vector<pair<int,int>> endtimes){
    times=0;int count=0;
    for(int i=0;i<edges.size();i++){
        if(edges[endtimes[i].first].color==0){
            dfs_visit(edges,edges[endtimes[i].first]);
            count++;
        }
    }    
    return count;
}
void graphTranspose(vector<struct node> &edges){
    vector<struct node> transpose(edges.size());
    for(int i=0;i<edges.size();i++){
        auto temp=edges[i];
        transpose[i].value=i+1;
        while (temp.next!=NULL)
        {
            temp=*temp.next;
            struct node *temp2=new struct node;
            temp2->value=i+1;
            temp2->next=transpose[temp.value-1].next;
            transpose[temp.value-1].next=temp2;
        }
        
    }
    edges=transpose;
}
int main(){
    int N,M;
    cin>>N>>M;
    
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
    vector<pair<int,int>> endtimes(N);
    for(int i=0;i<N;i++){
        endtimes[i].first=i;
        endtimes[i].second=i;
    }
    depthFirstSearch(edges,endtimes);    
    for(int i=0;i<N;i++){
        endtimes[i].second=edges[i].end;
    }
    sort(endtimes.begin(),endtimes.end(),[](pair<int,int> a, pair<int,int> b) { return a.second > b.second; });
    graphTranspose(edges);
    cout<<depthFirstSearch(edges,endtimes);
}