#include<iostream>
using namespace std;

class stack
{
private:
    
    int n_size;
    int capacity;
    double *p;
public:
    stack(/* args */);
    ~stack();
    void push(double x);
    void pop();
    void query();
    void size();
};

stack::stack(/* args */)
{
    n_size=0;
    capacity=1;
    p=new double[capacity];
}

stack::~stack()
{
}

void stack::push(double x){
    if(n_size<capacity){
        p[n_size]=x;
        n_size++;
    }else{
        capacity*=2;
        double *newp;
        newp=new double[capacity];
        for (int i = 0; i < n_size; i++)
        {
            newp[i]=p[i];
        }newp[n_size]=x;
        n_size++;
        p=newp;
    }
}

void stack::pop(){
    if(n_size==0){
        cout<<"Empty"<<endl;
    }
    else{
        n_size--;
    }
}

void stack::size(){
    cout<<n_size<<endl;
}

void stack::query(){
    if(n_size==0){
        cout<<"Anguei!"<<endl;
    }else{
        cout<<p[n_size-1]<<endl;
    }
}

int main(){
    int n,a;
    double x;
    stack y;
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