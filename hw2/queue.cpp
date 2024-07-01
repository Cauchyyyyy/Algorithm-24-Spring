#include<iostream>
using namespace std;

struct list
{
    double num;
    struct list *next;
};


class queue
{
private:
    int n_size;
    struct list *head;
    struct list *tail;
public:
    queue(/* args */);
    ~queue();
    void push(double x);
    void pop();
    void query();
    void size();
};

queue::queue(/* args */)
{
    n_size=0;
    head=NULL;
   
    tail=NULL;
   
}

queue::~queue()
{
}

void queue::push(double x){
    if(n_size==0){
        head= new struct list;
        head->num=x;
        tail=head;
    }
    else{
        struct list *p= new struct list;
        p->num=x;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
    n_size++;
}

void queue::pop(){
    if(n_size==0){
        cout<<"ERR_CANNOT_POP"<<endl;
    }else{
        head=head->next;
        n_size--;
    }

}

void queue::query(){
    if(n_size==0){
        cout<<"ERR_CANNOT_QUERY"<<endl;
    }else{
        cout<<head->num<<endl;
    }
}

void queue::size(){
    cout<<n_size<<endl;
}

int main(){
    int n,a;
    double x;
    queue y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){
            cin>>x;
            y.push(x);
        }
        else if(a==2){
            y.pop();
        }else if(a==3){
            y.query();
        }else if(a==4){
            y.size();
        }else{
            cout<<"error"<<endl;
        }
    }
    return 0;
}