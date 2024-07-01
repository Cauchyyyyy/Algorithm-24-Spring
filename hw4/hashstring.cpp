#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
struct linkedlist
{
    string value;
    struct linkedlist *next=NULL;
};



int countDistinctStrings(const vector<string>& arr) {
    vector<linkedlist *> hashstring(26*2+10);
    for(int i=0;i<arr.size();i++){
        auto temp = new linkedlist;
        if(arr[i][0]>='a' && arr[i][0]<='z'){
            temp->value = arr[i];
            temp->next = hashstring[arr[i][0]-'a'];
            hashstring[arr[i][0]-'a'] = temp;            
        }
        else if(arr[i][0]>='A' && arr[i][0]<='Z'){
            temp->value = arr[i];
            temp->next = hashstring[arr[i][0]-'A'+26];
            hashstring[arr[i][0]-'A'+26] = temp;
        }
        else if(arr[i][0]>='0' && arr[i][0]<='9'){
            temp->value = arr[i];
            temp->next = hashstring[arr[i][0]-'0'+52];
            hashstring[arr[i][0]-'0'+52] = temp;
        }
        else{
            std::cout<<"error"<<std::endl;
            return 0;
        }
    }

    int count = 0;
    for(int i=0;i<hashstring.size();i++){
        if(hashstring[i]==NULL) {continue;}
        else if(hashstring[i]->next==NULL) {count++;continue;}

        linkedlist *temp = hashstring[i];set<string> judge;
        while(temp!=NULL){
            
            judge.insert(temp->value);
            temp = temp->next;
        }
        count+=judge.size();
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout <<  countDistinctStrings(arr) << endl;
    return 0;
}
//to0 long time >=1000ms