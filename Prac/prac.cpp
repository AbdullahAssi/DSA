#include<iostream>
using namespace std;
int main (){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    int even,odd =0;
    for(int i=0;i<size;i++){
        cout<<"Enter the element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Your entered array is: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
        if(arr[i]%2==0){
            even++;
        }
        else if(arr[i]%2!=0){
            odd++;
        }
        
    }

    cout<<"\nEven Values in array are: "<<even<<endl;
    cout<<"Odd values in array are: "<<odd;

}