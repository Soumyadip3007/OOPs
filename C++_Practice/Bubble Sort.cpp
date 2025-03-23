//Time Complexcity: O(n^2 ) // n is the number of elements in the array
//Space Complexcity: O(1)  // No extra space is used
#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=n-1;i>=1;i--)
    {
        int flag=0; // To check if the array is already sorted
        for(int j=0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        {
            cout<<"Array is already sorted"<<endl;
            break;
        }
    }
}

int main()
{
    //vector<int>arr={1,2,3,4,5,6,7,8};
    vector<int>arr={8,9,2,7,5,8,0};
    cout<<"Original array is: ";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    BubbleSort(arr);
    cout<<"Sorted array is: ";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}