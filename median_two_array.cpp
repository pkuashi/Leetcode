#include <cstdlib>
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

        bool even = std::accumulate(
            arrays.begin(),
            arrays.end(),
            0 /*init*/,
            [&](int x, vector<int> y){ return x + y.size(); }) % 2 == 0;

        vector<double> result;
        for (size_t i = 0; i < arrays.size(); i++)
        {
            boudaries[i].first = 0;
            boudaries[i].second = arrays[i].size() > 0 ? arrays[i].size() - 1 : 0;
        }

        for (size_t i = 0; i < arrays.size(); i++)
        {
            bool found = false;
            size_t candidate = 0;

            do
            {
                size_t index = (boudaries[i].first + boudaries[i].second) / 2;
                candidate = arrays[i][index];

                // the -1 stands of the candidate itself in its own array, we should exclude it.
                size_t smaller_count = -1 + std::accumulate(
                    arrays.begin(),
                    arrays.end(),
                    0 /*init*/,
                    [&](int x, vector<int> y){ return x + numberofElementsLessOrEqual(candidate, y);});

                size_t bigger_count = -1 + std::accumulate(
                    arrays.begin(),
                    arrays.end(),
                    0 /*init*/,
                    [&](int x, vector<int> y){ return x + numberofElementsGreaterOrEqaul(candidate, y); });

                if ((!even && smaller_count == bigger_count) || (even && abs(smaller_count - bigger_count) == 1))
                {
                }
                else
                {
                    boudaries[i].first = index;
                }
            }
            while (boudaries[i].second - boudaries[i].first > 1);

            if (found)
            {
                break;
            }

            // The right boundary element is not visited. TODO: is there a better way to handle the right boundary?
            // the -1 stands of the candidate itself in its own array, we should exclude it.
            size_t smaller_count = -1 + std::accumulate(
                arrays.begin(),
                arrays.end(),
                0 /*init*/,
                [&](int x, vector<int> y){ return x + numberofElementsLessOrEqual(boudaries[i].second, y);});

            size_t bigger_count = -1 + std::accumulate(
                arrays.begin(),
                arrays.end(),
                0 /*init*/,
                [&](int x, vector<int> y){ return x + numberofElementsGreaterOrEqaul(boudaries[i].second, y); });

            if ((!even && smaller_count == bigger_count) || (even && abs(smaller_count - bigger_count) == 1))
            {
                result.push_back(candidate);
                break;
            }
        }

        if (even)
        {

        }

        if (even)
        {
            return (result[0] + result[1])/2;
        }
        else
        {
            return result[0];
        }
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

