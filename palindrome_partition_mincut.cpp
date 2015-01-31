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

        int i = 0, j = 0, iteration = 0;
        while (iteration < s.length())
        {
            if (result[j][j + i] < 0)
            {
                Compute(s, j, j + i, result);
            }

            if (j < s.length() - 1)
            {
                i++;
                j++;
            }
            else
            {
                iteration++;
                i = 0;
                j = iteration;
            }
        }

        return result[0][s.length() - 1];
    }

    void Compute(const string &s, int i, int j, int **result)
    {
        string targetString = s.substr(i, j - i + 1);
        if (IsPalindrom(targetString))
        {
            result[i][j] = 0;
            return;
        }

        int min = std::numeric_limits<int>::max();
        for (int k = i; k < j - i; k++)
        {
            assert(result[i][k] > -1);
            assert(result[k + 1][j] > -1);

            int resultCutAtK = result[i][k] + result[k + 1][j] + 1; 
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
