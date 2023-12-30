#include<iostream>
using namespace std;

int linearSearch(const int arr[], int size, int target){
    for (int i=0; i <size; i++){
        if(arr[i]== target){
            return i;
        }
    }

    return -1;

}

int main (){
    int arr[7] = {2,4,6,8,10,12,14};
    int target;
    cout<<"Enter the element to search: ";
    cin>>target;

    int result = linearSearch(arr,7,target);
    if(result != -1){
        cout<<"Element found at index "<<result<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }
    return 0;
}