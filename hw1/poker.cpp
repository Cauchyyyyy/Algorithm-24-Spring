#include<iostream>
#include<cmath>
using namespace std;

struct poker
{
    int num;
    struct poker *next;
    struct poker *last;
};

int main(){
    int n;
    cin>>n;
    struct poker *head,*p1,*p2,*tail,*headorigin,*tailorigin;
    p1=new struct poker;
    head=p1;tail=p1;p1->last=p1->next=NULL;
    for(int i=0;i<n;i++){
        cin>>p1->num;
        p2=p1;
        if(i!=n-1){
            p1=new struct poker;
            p2->next=p1;
            p1->last=p2;
        }
        tail=p1;p1->next=NULL;
    }
    headorigin=tail->last;tailorigin=tail;
    p1=headorigin->last;
    while (p1!=NULL)
    {
        headorigin->last=p2=tailorigin;
        tailorigin=tailorigin->last;
        tailorigin->next=NULL;
        p2->next=headorigin;
        p2->last=p1;p1->next=p2;
        headorigin=p1;
        p1=p1->last;
    }
    while (headorigin!=NULL)
    {
        cout<<headorigin->num<<" ";
        headorigin=headorigin->next;
    }
    
    return 0;
}
