#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (!(num1.size() && num2.size()))
            return "";
        if(num1=="0"||num2=="0") return "0";
        vector<int> res(num1.size() + num2.size());
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            for (int j = num1.size() - 1; j >= 0; j--)
            {
                int temp = (num1[j] - '0') * (num2[i] - '0');
                int insert_k = i + j + 1;
                res[insert_k] += temp;
                while (res[insert_k] >= 10)
                {
                    int add_up = res[insert_k] / 10;
                    res[insert_k] = res[insert_k] % 10;
                    insert_k--;
                    res[insert_k] += add_up;
                }
            }
        }
        int i = 0;
        if (res[0] == 0)
            i++;
        string res_s;
        for (; i < res.size(); i++)
        {
            res_s += res[i] + '0';
        }
        return res_s;
    }
};

int main()
{
    Solution so;
    cout<<so.multiply("0", "0");
}