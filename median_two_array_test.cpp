#include "median_two_array.cpp"
#include <gtest/gtest.h>

TEST(median_two_array, HappyPath_Odd)
{
    Solution solution;
    int A[5]{1,3,5,9,13};
    int B[4]{7,8,15,19};
    double median = solution.findMedianSortedArrays(A, 5, B, 4);

    ASSERT_EQ(8, median);
}

TEST(median_two_array, HappyPath_Even)
{
    Solution solution;
    int A[5]{1,3,5,9,13};
    int B[5]{7,8,15,19,20};
    double median = solution.findMedianSortedArrays(A, 5, B, 5);

    ASSERT_EQ(8.5, median);
}

TEST(median_two_array, SingleElement)
{
    Solution solution;
    int A[0]{};
    int B[1]{7};
    double median = solution.findMedianSortedArrays(A, 0, B, 1);

    ASSERT_EQ(7, median);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
