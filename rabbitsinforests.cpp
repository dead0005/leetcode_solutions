class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int,int>b;
        for(int i:a) b[i]++;
        int sum=0;
        for(auto &it:b){
            int grp=it.first+1;
            int cnt=it.second;
            sum+=((cnt+grp-1)/grp)*grp;
        }
        return sum;
    }
};