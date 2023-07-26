class Solution {
public:
    double timeRequired(vector<int> dist,int speed){
        double time = 0.0;
        for(int i=0;i<dist.size();i++){
            double x = (double)dist[i]/(double)speed;
            time+= (i==dist.size()-1) ? x: ceil(x);
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int minspeed = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(timeRequired(dist,mid)<=hour){
                minspeed=mid;
               high=mid-1;
            }
            else
                low=mid+1;
        }
        return minspeed;
    }
};