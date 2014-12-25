#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        vector<vector<int>> arrays{vector<int>(A, A+m), vector<int>(B, B+n)};
        vector<pair<size_t, size_t>> boudaries(arrays.size());

        size_t halfSize = std::accumulate(arrays.begin(), arrays.end(), 0, [](int x, vector<int> y){return x + y.size(); }) / 2;
        double result = 0;
        for (int i = 0; i < arrays.size(); i++)
        {
            boudaries[i].first = 0;
            boudaries[i].second = arrays[i].size() - 1;
            result = arrays[i][arrays.size()/2];

            // the -1 stands of the result itself in its own array, we should exclude it.
            size_t count = -1 + std::accumulate(
                arrays.begin(),
                arrays.end(),
                0 /*init*/,
                [&](int x, vector<int> y){return x + numberofElementsBefore(result, y);});
            if (count == halfSize)
            {
                return result;
            }
        }

        return result;
    }

    int numberofElementsBefore(double value, vector<int> array)
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
            else if (array[result] < value)
            {
                start = result;
            }
            else if ((double)array[result] == value)
            {

            }
        }
        while (start < end);

        return start;
    }
};

int main()
{
    int A[5]{1, 3, 6, 9, 13};
    int B[4]{2, 15, 17, 21};

    Solution solution;
    return solution.findMedianSortedArrays(A, 5, B, 4);
    return 0;
}
