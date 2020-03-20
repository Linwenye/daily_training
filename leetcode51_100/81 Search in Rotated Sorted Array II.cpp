class Solution {
public:
    int target;
    bool search(vector<int>& nums, int target) {
        this->target=target;
        if(nums.empty()) return false;
        stack<int> pointers;
        
        int l=0;
        int r=nums.size();
        pointers.push(l);
        pointers.push(r);
        
        bool res=false;
        while(!pointers.empty()){
            r=pointers.top();
            pointers.pop();
            l=pointers.top();
            pointers.pop();
            if(r-l==1){
                if(nums[l]==target){
                    return true;
                }
                continue;
            }
            int mid = (l+r)/2;
            if(nums[mid]>nums[l]){
                if(target<nums[mid]&&target>=nums[l]){
                    pointers.push(l);
                    pointers.push(mid);
                }
                else{
                    pointers.push(mid);
                    pointers.push(r);
                }
            }
            else if(nums[mid]<nums[l]){
                if(nums[mid]<=target&&target<=nums[r-1]){
                    pointers.push(mid);
                    pointers.push(r);
                }
                else{
                    pointers.push(l);
                    pointers.push(mid);
                }
            }
            else{
                pointers.push(l);
                pointers.push(mid);
                pointers.push(mid);
                pointers.push(r);
            }
        }
        return res;
    }
    
};