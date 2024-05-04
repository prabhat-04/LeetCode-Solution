const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j){
            ans++;
            if(people[i]+people[j]>limit) j--;
            else{
                i++;
                j--;
            }
        }
        // if(i==j) ans++;
        return ans;
    }
};