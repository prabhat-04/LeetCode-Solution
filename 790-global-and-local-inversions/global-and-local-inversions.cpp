class Solution {
public:
    void merge(vector<int> &nums,int l,int mid,int r,long long int &count){
        int n1 = mid-l+1,n2=r-mid;
        int L[n1],M[n2];
        for(int i=0;i<n1;i++)
            L[i]=nums[i+l];
        for(int i=0;i<n2;i++)
            M[i]=nums[i+mid+1];
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(L[i]<=M[j]){
                nums[k++]=L[i];
                i++;
            }
            else{
                count+=(mid-(i+l)+1);
                nums[k++]=M[j];
                j++;
            }
        }

        while(i<n1){
            nums[k++]=L[i];
            i++;
        }
        while(j<n2){
            nums[k++]=M[j];
            j++;
        }
    }

    void mergeSort(vector<int> &nums,int l,int r,long long int &count){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(nums,l,mid,count);
            mergeSort(nums,mid+1,r,count);
            merge(nums,l,mid,r,count);
        }
    }

    bool isIdealPermutation(vector<int>& nums) {
        long long int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) cnt++;
        }
        long long int count=0;
        mergeSort(nums,0,nums.size()-1,count);
        cout<<cnt<<" "<<count<<endl;
        return cnt==count;
    }
};