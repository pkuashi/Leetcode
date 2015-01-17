#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return vector<vector<string>>();

        auto listResult = partition_palindrome(s);
        vector<vector<string>> result;

        for (auto i : listResult)
        {
            vector<string> partition(i.begin(), i.end());
            result.push_back(partition);
        }

        return result;
    }

    list<list<string>> partition_palindrome(string &s)
    {
        list<list<string>> result;
        if (s.size() == 0) return result;

        for (int i = 0; i < s.size(); i++)
        {
            bool isPalinDrome = IsPalinDrome(s, 0, i);
            if (isPalinDrome)
            {
                string token(s.begin(), s.begin() + i + 1);
                string newString(s.begin() + i + 1, s.end());
                auto childResult = partition_palindrome(newString);

                if (childResult.size() == 0) result.push_back(list<string> { token });
                else
                {
                    for (auto k : childResult)
                    {
                        list<string> partition{ token };
                        copy(k.begin(), k.end(), back_inserter(partition));

                        result.push_back(partition);
                    }
                }
            }
        }

        return result;
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
