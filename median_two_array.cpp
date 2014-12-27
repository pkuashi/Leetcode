#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        vector<vector<int>> arrays{vector<int>(A, A+m), vector<int>(B, B+n)};
        vector<pair<size_t, size_t>> boudaries(arrays.size());

        double result = numeric_limits<double>::min();
        for (size_t i = 0; i < arrays.size(); i++)
        {
            boudaries[i].first = 0;
            boudaries[i].second = arrays[i].size() - 1;
        }

        for (size_t i = 0; i < arrays.size(); i++)
        {
            do
            {
                size_t index = (boudaries[i].first + boudaries[i].second) / 2;
                result = arrays[i][index];

                // the -1 stands of the result itself in its own array, we should exclude it.
                size_t smaller_count = -1 + std::accumulate(
                    arrays.begin(),
                    arrays.end(),
                    0 /*init*/,
                    [&](int x, vector<int> y){ return x + numberofElementsLessOrEqual(result, y);});

                size_t bigger_count = -1 + std::accumulate(
                    arrays.begin(),
                    arrays.end(),
                    0 /*init*/,
                    [&](int x, vector<int> y){ return x + numberofElementsGreaterOrEqaul(result, y); });

                // TODO: have to consider the situation where the size of all arrays is even.
                if (smaller_count == bigger_count)
                {
                    break;
                }
                else if (smaller_count > bigger_count)
                {
                    boudaries[i].second = index;
                }
                else
                {
                    boudaries[i].first = index;
                }
            }
            while ();
        }

        return result;
    }

    size_t numberofElementsLessOrEqual(double value, vector<int> array)
    {
        if (array.size() == 0)
        {
            return 0;
        }

        int start = 0, end = array.size() - 1;

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

        int start = 0, end = array.size() - 1;

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

int main()
{
    int A[5]{1, 3, 6, 9, 13};
    int B[4]{2, 15, 17, 21};

    Solution solution;
    cout<< "Median is: " << solution.findMedianSortedArrays(A, 5, B, 4) << endl;
    return 0;
}
