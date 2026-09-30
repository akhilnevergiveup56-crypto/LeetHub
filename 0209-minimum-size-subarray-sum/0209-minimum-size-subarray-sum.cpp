class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int l=nums.size();
        int sum=0;
        int mini=INT_MAX;
        
        
        while(j<l){
            sum+=nums[j];

            if (sum < target){
                j++;

            }
            else{
                while ( sum >= target && i<=j){
                int len = j-i+1;
                mini = min(len,mini);
                sum=sum-nums[i];
                i++;
                
                }j++;
            }
            
            
        
        }if ( mini == INT_MAX){
            return 0;
        }return mini;
        
    }
};