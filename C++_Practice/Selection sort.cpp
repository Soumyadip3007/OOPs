//Time Complexcity: O(n^2 ) // n is the number of elements in the array
//Space Complexcity: O(1)  // No extra space is used
#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<=n-2;i++)
    {
        int mini=i; // Assume the first element is the minimum
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j]<arr[mini])
            {
                mini=j; // Update the minimum index
            }
        }
        swap(arr[i],arr[mini]); // Swap the minimum element with the first element
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
    SelectionSort(arr);
    cout<<"Sorted array is: ";
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}