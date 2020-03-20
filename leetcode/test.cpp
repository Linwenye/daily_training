#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string _digits;
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(!digits.size()) return res;
        _digits = digits;
        string temp = "";
        back_track(res, 0, temp);
        // for (size_t i = 0; i < res.size(); i++)
        // {
        //     cout<<res[i]<<" ";
        // }
        return res;
    }

    void back_track(vector<string> &res, int i, string &temp)
    {
        if (i == _digits.size())
        {
            res.push_back(temp);
        }
        else
        {
            for (char c : a[_digits[i] - '0'])
            {
                temp.push_back(c);
                back_track(res, i + 1, temp);
                temp.pop_back();
            }
        }
    }
};


int main(){
    Solution so;
    so.letterCombinations("23");
}