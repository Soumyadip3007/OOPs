//Time Complexity: O(n^2)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main()
{
    vector<int>arr={8,9,2,7,5,8,0};
    cout<<"Original array is: ";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    InsertionSort(arr);
    cout<<"Sorted array is: ";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}