#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Your entered array is: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nYour reveresed array is: ";
    for(int i=size-1; i>=0; i--){
        cout<<arr[i]<<" ";
    }

}