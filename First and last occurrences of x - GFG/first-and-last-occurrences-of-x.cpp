//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int firstOccurrence(int arr[],int low,int high,int key){
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==key){
                if(mid==0 || arr[mid-1]!=arr[mid])
                    return mid;
                else 
                    high = mid-1;
            }
            else if(key<arr[mid])
                high = mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
    
    int lastOccurrence(int arr[],int low,int high,int key){
        int temp = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==key){
                if(mid==temp || arr[mid]!=arr[mid+1])
                    return mid;
                else 
                    low=mid+1;
            }
            else if(key<arr[mid])
                high = mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        int a = firstOccurrence(arr,0,n-1,x);
        if(a==-1)
            return {-1,-1};
        int y = lastOccurrence(arr,0,n-1,x);
        return{a,y};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends