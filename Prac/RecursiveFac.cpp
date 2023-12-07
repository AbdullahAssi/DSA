#include<iostream>
using namespace std;

int fact(int num){
    if(num > 0){
        return num * fact(num - 1);
    }
    else{
        return 1;
    }
}

int main (){
    int num;
    cout << "Enter the number to find factorial of: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << fact(num) << endl;
    return 0;
}
