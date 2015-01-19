#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <list>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0)
        {
            return 0;
        }

        auto allResults = partition(s);
        auto minElement = min_element(
            allResults.begin(),
            allResults.end(),
            [](list<string> p1, list<string> p2) {return p1.size() < p2.size(); });

        return (*minElement).size() - 1;
    }

    list<list<string>> partition(string s) {
        if (s.size() == 0) return list<list<string>>();

        return partition_palindrome(s);
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

                if (childResult.size() == 0) result.push_back(list < string > { token });
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

    cout << "result: " << solution.minCut("aab") << endl;
    
}
