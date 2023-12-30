#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);

    cout<<"Top Element: "<<pq.top()<<endl;
    cout<<"Size: "<<pq.size()<<endl;

    while(!pq.empty()){
        cout<<"the top is "<<pq.top()<<" "<<endl;
        pq.pop();
    }
}