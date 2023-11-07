#include<iostream>
using namespace std;
void findminmax(int arr[],int low,int high,int &min,int &max){
    if(low == high){
        min =max = arr[low];
    }
    else if (low == high + 1 ){
        if(arr[low]< arr[high]){
            min = arr[low];
            max = arr[high];
        }
        else{
            min = arr[high];
            max = arr[low];
        }
    }
    else{
        int mid = (low + high)/2;
        int min1,max1;
        findminmax(arr,low,mid,min,max);
        findminmax(arr,mid+1,high,min1,max1);
        if(min1<min){
            min = min1;
        }
        if(max1>max){
            max = max1;
        }
    }
}
int main(){
    int arr[10];
    cout<<"Enter An array of 10 elements: ";
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    int min = arr[0];
    int max = arr[0];
    findminmax(arr,0,9,min,max);
    cout<<"Minimum: "<<min<<endl;
    cout<<"Maximum: "<<max<<endl;
    return 0;
}