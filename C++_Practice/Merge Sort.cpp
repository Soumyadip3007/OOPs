//Time Complexity: O(nlogn)
//Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int low, int high, int mid)
{
    vector<int>temp;
    int l=low;
    int r=mid+1;
    while(l<=mid && r<=high)
    {
        if(arr[l]<=arr[r])
        {
            temp.push_back(arr[l]);
            l++;
        }
        else{
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid) //right array is empty
    {
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high) //left array is empty
    {
        temp.push_back(arr[r]);
        r++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void mergesort(vector<int>&arr, int low, int high)
{
    if(low==high) return; // base case
    int mid= low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,high,mid);
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
    mergesort(arr,0,arr.size()-1);
    cout<<"Sorted array is: ";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}