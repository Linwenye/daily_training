#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> empty;
        res.push_back(empty);
        for (int num : nums)
        {
            int former_size = res.size();
            for (int i = 0; i < former_size; i++)
            {
                vector<int> new_vec = res[i];
                new_vec.push_back(num);
                res.push_back(new_vec);
            }
        }
        return res;
    }
};

int main(){
    Solution so;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = so.subsets(nums);
    for(vector<int> &v:res){
        for(int num:v){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}