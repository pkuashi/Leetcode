#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        bool even = (m + n) % 2 == 0 ? true : false;

        unordered_set<double> result;

        binary_tranverse(A, m, B, n, result);
        if (!even && result.size() == 1)
        {
            return *result.begin();
        }

        binary_tranverse(B, n, A, m, result);

        if (!even)
        {
            return *result.begin();
        }
        else if (result.size() == 2)
        {
            // TODO: ugly implementation
            return std::accumulate(
                result.begin(),
                result.end(),
                (double)0 /*init*/,
                [&](double x, int y){ return x + (double)y / result.size(); });
        }
        else
        {
            throw "Algorithm problem, should find the median anyway.";
        }
    }

    void binary_tranverse(int a[], size_t m, int b[], size_t n, unordered_set<double>& result)
    {
        bool even = (m + n) % 2 == 0 ? true : false;
        size_t begin = 0, end = m;
        size_t halfSize = (m + n - 1) / 2;

        do
        {
            size_t index = (begin + end) / 2;
            cout << "begin=" << begin << "; end=" << end << endl;
            cout << "try " << a[index] << endl;

            if (halfSize > index)
            {
                if (a[index] > b[halfSize - index])
                {
                    cout << a[index] << " is too big." << endl;
                    end = index;
                }
                else if (a[index] < b[halfSize - index - 1])
                {
                    cout << a[index] << " is too small." << endl;
                    begin = index;
                }
                else
                {
                    cout << "find " << a[index] << endl;
                    result.insert(a[index]);
                    begin = index;
                }
            }
            else
            {
                if (a[index] <= b[0] && index == halfSize)
                {
                    cout << "find " << a[index] << endl;
                    result.insert(a[index]);
                }
                else
                {
                    break;
                }
            }

            if ((even && result.size() == 2) || (!even && result.size() == 1))
            {
                break;
            }
        } while (end - begin > 1);
    }
};

