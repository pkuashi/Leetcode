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

        for (int m = 0; m < s.length(); m++)
        {
            result[m] = new int [s.length()];

            for (int n = 0; n < s.length(); n++)
            {
                if (n == m)
                {
                    result[m][n] = 0; 
                }
                else
                {
                    result[m][n] = -1;
                }
            }
        }

        int i = 0, j = 0, iteration = 0;
        while (iteration < s.length())
        {
            if (result[i][j] < 0)
            {
                Compute(s, i, j, result);
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
        for (int k = i; k < j; k++)
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
        for (int i = 0; i <= (s.length() - 1) / 2; i++)
        {
            if (s[i] != s[s.length() - i - 1]) return false;
        }

        return true;
    }
};

void main()
{
    Solution solution;

    string input("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    cout << "input: " << input << "; length: " << input.length () << endl;
    cout << "result: " << solution.minCut(input) << endl;
    
}
