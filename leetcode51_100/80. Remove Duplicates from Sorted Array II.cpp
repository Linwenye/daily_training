class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        
        int cursor = 1;
        bool used = false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[cursor++] = nums[i];
                used = false;
            }
            else{
                if(used){
                    continue;
                }
                else{
                    used=true;
                    nums[cursor++] = nums[i];
                }
            }
        }
        return cursor;
    }
};