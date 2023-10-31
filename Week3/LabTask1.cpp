#include<iostream>
using namespace std;

int countDigits(int num){
    if(num == 0){
        return 0;
    }
    else{
        return 1 + countDigits(num / 10);
    }
}

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The number of digits in " << num << " is: " << countDigits(num) << endl;
    return 0;
}