class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k)
                pq.push(nums[i]);
            else if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
            // cout<<pq.top()<<endl;
        }
    }
    
    int add(int val) {
        // cout<<pq.top()<<endl;
        if(pq.size()<K) pq.push(val);
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        // if(pq.size()<K) return -1;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */