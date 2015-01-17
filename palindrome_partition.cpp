#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;

        if (s.size() == 0) return result;

        return partition_palindrome(result, s);
    }

    vector<vector<string>> partition_palindrome(const vector<vector<string>> &input, string &s)
    {
        vector<vector<string>> result;
        if (s.size() == 0) return result;

        for (int i = 0; i < s.size(); i++)
        {
            if (IsPalinDrome(s, 0, i))
            {
                vector<vector<string>> newInput(input.size());
                copy(input.begin(), input.end(), newInput.begin());

                for(auto j : newInput)
                {
                    j.push_back(string(s.begin(), s.begin() + i));

                    auto childResult = partition_palindrome(newInput, string(s.begin() + i, s.end()));

                    for (int k = 0; k < childResult.size(); k++)
                    {
                        vector<string> partition;
                        copy(j.begin(), j.end(), partition);
                        copy(childResult[k].begin(), childResult[k].end(), partition.end());

                        result.push_back(partition);
                    }
                }
            }
        }

    }

    bool IsPalinDrome(string& s, size_t begin, size_t last)
    {
        size_t length = last - begin + 1;
        for (int i = 0; i < length / 2; i++)
        {
            if (s[i] != s[length - i - 1]) return false;
        }

        return true;
    }
};

void main()
{
    Solution solution;

    auto result = solution.partition("aab");
    for (int i = 0; i < result.size(); i++)
    {
        vector<string> partition = result[i];
        for (int j = 0; j < partition.size(); j++)
        {
            cout << partition[j] << " ";
        }

        cout << endl;
    }
}
