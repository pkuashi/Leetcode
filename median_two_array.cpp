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
        binary_tranverse(B, n, A, m, result);

        if (!even)
        {
            return *result.begin();
        }
        else if (result.size() == 2)
        {
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
        size_t begin = 0, end = m;

        do
        {
            size_t index = (begin + end) / 2;
            cout << "begin=" << begin << "; end=" << end << endl;
            cout << "try " << a[index] << endl;
            if ((m + n - 1) / 2 > index)
            {
                if (a[index] > b[(m + n - 1) / 2 - index])
                {
                    cout << a[index] << " is too big." << endl;
                    end = index;
                }
                else if (a[index] < b[(m + n - 1) / 2 - index - 1])
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
                if (a[index] <= b[0])
                {
                    cout << "find " << a[index] << endl;
                    result.insert(a[index]);
                }
            }

            if (result.size() == 2)
            {
                break;
            }
        } while (end - begin > 1);
    }

    bool IsMedian(int A[], size_t index, int B[], size_t n)
    {
        return true;
    }

    size_t numberofElementsLessOrEqual(double value, vector<int> array)
    {
        if (array.size() == 0)
        {
            return 0;
        }

        int start = 0;
        int end = array.size() > 0 ? array.size() - 1 : 0;

        do
        {
            int result = (start + end) / 2;

            if (array[result] > value)
            {
                end = result;
            }
            else if (array[result] <= value)
            {
                start = result;
            }
        }
        while (start < end - 1);

        if (array[end] <= value)
        {
            return array.size();
        }
        else if (array[start] <= value)
        {
            return start + 1;
        }
        else
        {
            return 0;
        }
    }

    int numberofElementsGreaterOrEqaul(double value, vector<int> array)
    {
        if (array.size() == 0)
        {
            return 0;
        }

        int start = 0;
        int end = array.size() > 0 ? array.size() - 1 : 0;

        do
        {
            int result = (start + end) / 2;

            if (array[result] >= value)
            {
                end = result;
            }
            else if (array[result] < value)
            {
                start = result;
            }
        }
        while (start < end - 1);

        if (array[start] >= value)
        {
            return array.size();
        }
        else if (array[end] >= value)
        {
            return array.size() - end;
        }
        else
        {
            return 0;
        }
    }
};

