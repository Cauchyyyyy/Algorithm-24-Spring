#include<iostream>
using namespace std;
class heap
{
private:
    int n_size;
    int capacity;
    double *p;
public:
    heap(/* args */);
    ~heap();
    void push(double x);
    void pop();
    void query();
    void size();
};

heap::heap(/* args */)
{
    n_size=0;
    capacity=1;
    p=new double[capacity];
}

heap::~heap()
{
}

void heap::push(double x){
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

void heap::pop(){
    if(n_size==0){
        cout<<"ERR_CANNOT_POP"<<endl;
    }
    else{
        double t=p[0];int j=0;
        for (int i = 1; i < n_size; i++)
        {
           if(t>p[i]){
                t=p[i];j=i;
           }
        }
        if(j!=n_size){
            double *newp;
            newp=new double[capacity];
            for (int i = 0; i < n_size-1; i++)
            {   if(i<j){
                    newp[i]=p[i];
                }
                else if(i>=j){
                    newp[i]=p[i+1];
                }
            }
            p=newp;
        }
        n_size--;
    }
}

void heap::size(){
    cout<<n_size<<endl;
}

void heap::query(){
    if(n_size==0){
        cout<<"ERR_CANNOT_QUERY"<<endl;
    }else{
        double t=p[0];int j=0;
        for (int i = 1; i < n_size; i++)
        {
           if(t>p[i]){
                t=p[i];j=i;
           }
        }
        cout<<p[j]<<endl;
    }
}

int main(){
    int n,a;
    double x;
    heap y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){
            cin>>x;
            y.push(x);
        }
        else if(a==3){
            y.pop();
        }else if(a==2){
            y.query();
        }else if(a==4){
            y.size();
        }else{
            cout<<"error"<<endl;
        }
    }
    return 0;
}