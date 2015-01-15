#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <iostream>
#include <limits>
#include <deque>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
#ifdef _DEBUG
        cout << "Array A, size " << m << endl;
        for (int i = 0; i < m; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;

        cout << "Array B, size " << n << endl;
        for (int i = 0; i < n; i++)
        {
            cout << B[i] << " ";
        }
        cout << endl;
#endif
        bool even = (m + n) % 2 == 0 ? true : false;

        deque<double> result;

        binary_tranverse(A, m, B, n, result);
        binary_tranverse(B, n, A, m, result);

        sort(result.begin(), result.end());
        auto last = unique(result.begin(), result.end());
        result.resize(distance(result.begin(), last));
        if (result.size() == 1)
        {
            return *result.begin();
        }
        else if (result.size() == 2)
        {
            // TODO: ugly implementation
            return (double)(result[0] + result[1]) / 2;
        }
        else
        {
            string message("Algorithm problem, should find the median anyway or at most 2 number. The size of the result: ");
            message += result.size();
            throw message;
        }
    }

    void binary_tranverse(int a[], size_t m, int b[], size_t n, deque<double>& result)
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
                result.push_back(a[halfSize]);
            }
            else
            {
                result.push_back(a[halfSize + 1]);
                result.push_back(a[halfSize]);
            }

            return;
        }

        size_t begin = 0, end = m;

        do
        {
            size_t index = (begin + end) / 2;
#ifdef _DEBUG
            cout << "begin=" << begin << "; end=" << end << endl;
            cout << "try " << a[index] << endl;
#endif

            int frontPivotIndex = halfSize - index - 1;
            int endPivotIndex = halfSize - index;
            int endPlusPivotIndex = halfSize - index + 1;

            if (halfSize > index)
            {
                if (endPivotIndex < n && 
                    ((!even && a[index] > b[endPivotIndex]) ||
                     (even && ((endPlusPivotIndex < n && a[index] > b[endPlusPivotIndex])))))
                {
#ifdef _DEBUG
                    cout << a[index] << " is too big." << endl;
#endif
                    end = index;
                }
                else if (/*endPivotIndex >= n || */(frontPivotIndex < n && a[index] < b[frontPivotIndex]) || frontPivotIndex >= n)
                {
#ifdef _DEBUG
                    cout << a[index] << " is too small." << endl;
#endif
                    begin = index;
                }
                else
                {
#ifdef _DEBUG
                    cout << "find " << a[index] << endl;
#endif
                    result.push_back(a[index]);
                    if (even && ((endPivotIndex < n && a[index] >= b[endPivotIndex]) || endPivotIndex < 0))
                    {
                        end = index;
                    }
                    else
                    {
                        begin = index;
                    }
                }
            }
            else
            {
                if ((!even && index == halfSize && a[index] <= b[0]) ||
                    (even && (index == halfSize && ((n > 1 && a[index] <= b[1]) || (n == 1)) || (index == halfSize + 1 && a[index] <= b[0]))))
                {
#ifdef _DEBUG
                    cout << "find " << a[index] << endl;
#endif
                    result.push_back(a[index]);

                    if (even && ((endPivotIndex < n && a[index] >= b[endPivotIndex]) || endPivotIndex < 0))
                    {
                        end = index;
                    }
                    else
                    {
                        begin = index;
                    }
                }
                else
                {
                    end = index;
                    continue;
                }
            }
        } while (end - begin > 1);

        // The begin is not visited yet unless it is a single element array.
        if (m > 1 && begin == 0)
        {
#ifdef _DEBUG
            cout << "try " << a[0] << endl;
#endif
            if ((!even && halfSize <= n && a[0] >= b[halfSize - 1] && ((halfSize < n && b[halfSize] >= a[0]) || halfSize >= n)) || 
                (even && ((halfSize < n && a[0] >= b[halfSize] && (a[0] <= b[halfSize + 1] || halfSize + 1 >= n)) || (halfSize <=n && a[0] >= b[halfSize - 1] && (halfSize >= n || a[0] <= b[halfSize])))) ||
                (n == 0 && m == 2))
            {
#ifdef _DEBUG
                cout << "find " << a[0] << endl;
#endif
                result.push_back(a[0]);
            }
        }
    }
};
