#include<iostream>
#include<cmath>
using namespace std;

struct nlist
{
    int num;
    struct nlist *next;
};

int main(){
    int n,a,x,y;
    struct nlist *head,*p1,*p2;
    head=new struct nlist;
    head->num=1;
    head->next=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){
            cin>>x>>y;p1=head;
            while (p1->num!=x)
            {
                p1=p1->next;
            }
            p2=new struct nlist;
            p2->num=y;
            p2->next=p1->next;
            p1->next=p2;
        }else if(a==2){
            cin>>x;p1=head;
            while (p1->num!=x)
            {
                p1=p1->next;
            }
            if(p1->next!=NULL){
                p1=p1->next;
                cout<<p1->num<<endl;
            }else{
                cout<<"0"<<endl;
            }
            
        }else if(a==3){
            cin>>x;p1=head;
            while (p1->num!=x)
            {
                p1=p1->next;
            }
            p2=p1->next;
            p1->next=p2->next;
        }else{
            cout<<"error"<<endl;
            return 0;
        }
    }
    return 0;
}
