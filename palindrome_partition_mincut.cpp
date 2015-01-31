#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <list>
#include <limits>
#include <cassert>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0)
        {
            return 0;
        }

        int ** result = new int *[s.length()];

        for (int i = 0; i < s.length(); i++)
        {
            result[i] = new int [s.length()];

            for (int j = 0; j < s.length(); j++)
            {
                if (j == i)
                {
                    result[i][j] = 0;
                }
                else
                {
                    result[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (result[i+j][j] >= 0 ) continue;

                Compute(s, i, j, result);
            }
        }
    }

    void Compute(const string &s, int i, int j, int **result)
    {
        if (IsPalindrom(s.substr(i, j - i + 1)))
        {
            result[i][j] = 0;
            return;
        }

        int min = std::numeric_limits<int>::max();
        for (int k = i; k < j - i; k++)
        {
            assert(result[i][k] > -1);
            assert(result[k + 1][j] > -1);

            int resultCutAtK = result[i][k] + result[k + 1][j];
            if (resultCutAtK < min)
            {
                min = resultCutAtK;
            }
        }

        result[i][j] = min;
    }

    bool IsPalindrom(const string &s)
    {
        for (int i = 0; i < (s.length() - 1) / 2; i++)
        {
            if (s[i] != s[s.length() - i]) return false;
        }

        return true;
    }
};

void main()
{
    Solution solution;

    cout << "result: " << solution.minCut("aab") << endl;
    
}
