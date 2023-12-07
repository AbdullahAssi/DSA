#include<iostream>
using namespace std;

int sum(int num){
    if(num <= 0){
        return 0;  
    }
    else{
        cout << "Value on Every Iteration: " << num << endl;
        return num + sum(num-1);
    }
}

int main(){
    int num;
    cout << "Enter the number to find the sum of: ";
    cin >> num;
    cout << "Sum of " << num << " is " << sum(num) << endl;
    return 0;
}
