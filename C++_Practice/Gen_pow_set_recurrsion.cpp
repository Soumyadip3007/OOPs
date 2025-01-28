#include<bits/stdc++.h>
using namespace std;

void Sub_seq(int arr[], int n, int index, vector<int>&temp, vector<vector<int>>&ans)
{
    if(index==n)
    {
        ans.push_back(temp);
        return;
    }
    // Exclude the current element and move to the next
    Sub_seq(arr,n,index+1,temp,ans);
    // Include the current element and move to the next
    temp.push_back(arr[index]);
    Sub_seq(arr,n,index+1,temp,ans);
    // Backtrack to remove the current element before moving to the next
    temp.pop_back();
}

int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>>ans;
    vector<int>temp;
    Sub_seq(arr,n,0,temp,ans);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}