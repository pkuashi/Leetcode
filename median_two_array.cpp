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
        if ((!even && result.size() == 1) || (even && result.size() == 2))
        {
            if (!even)
            {
                return *result.begin();
            }
            else
            {
                // TODO: ugly implementation
                return std::accumulate(
                    result.begin(),
                    result.end(),
                    (double)0 /*init*/,
                    [&](double x, int y){ return x + (double)y / result.size(); });
            }
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
        if (m == 0)
        {
            return;
        }

        bool even = (m + n) % 2 == 0 ? true : false;
        size_t halfSize = (m + n - 1) / 2;

        if (n == 0)
        {
            if (!even)
            {
                result.insert(a[halfSize]);
            }
            else
            {
                result.insert(a[halfSize + 1]);
                result.insert(a[halfSize]);
            }

            return;
        }

        size_t begin = 0, end = m;

        do
        {
            size_t index = (begin + end) / 2;
            cout << "begin=" << begin << "; end=" << end << endl;
            cout << "try " << a[index] << endl;

            if (halfSize > index)
            {
                int frontPivotIndex = halfSize - index - 1;
                int endPivotIndex = halfSize - index;
                int endPlusPivotIndex = halfSize - index + 1;

                if (endPivotIndex < n && ((!even && a[index] > b[endPivotIndex]) ||
                    (even && ((endPlusPivotIndex < n && a[index] > b[endPlusPivotIndex]) || endPlusPivotIndex >= n))))
                {
                    cout << a[index] << " is too big." << endl;
                    end = index;
                }
                else if (endPivotIndex >= n || a[index] < b[frontPivotIndex])
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

