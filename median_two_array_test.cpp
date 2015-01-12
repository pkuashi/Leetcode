#include "median_two_array.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(median_two_array, HappyPath_Odd)
{
    Solution solution;
    int A[]{1,3,5,9,13};
    int B[]{7,8,15,19};
    double median = solution.findMedianSortedArrays(A, 5, B, 4);

    ASSERT_EQ(8, median);
}

TEST(median_two_array, Meidan_Appear_Multiple_Instances)
{
    Solution solution;
    int A[]{1,2};
    int B[]{1,2,3};
    double median = solution.findMedianSortedArrays(A, 2, B, 3);

    ASSERT_EQ(2, median);
}

TEST(median_two_array, HappyPath_Even)
{
    Solution solution;
    int A[]{1,3,5,9,13};
    int B[]{7,8,15,19,20};
    double median = solution.findMedianSortedArrays(A, 5, B, 5);

    ASSERT_EQ(8.5, median);
}

TEST(median_two_array, OnOverlap)
{
    Solution solution;
    int A[]{1, 3, 5, 7, 9};
    int B[]{15, 19, 20, 24};
    double median = solution.findMedianSortedArrays(A, 5, B, 4);

    ASSERT_EQ(9, median);
}

TEST(median_two_array, LargeAAndSmallB)
{
    Solution solution;
    int A[]{1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int B[]{15};
    double median = solution.findMedianSortedArrays(A, 10, B, 1);

    ASSERT_EQ(11, median);
}

TEST(median_two_array, SmallAAndLargeB)
{
    Solution solution;
    int A[]{15};
    int B[]{1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    double median = solution.findMedianSortedArrays(A, 1, B, 10);

    ASSERT_EQ(11, median);
}

//TEST(median_two_array, SingleElement)
//{
//    Solution solution;
//    int A[0]{};
//    int B[]{7};
//    double median = solution.findMedianSortedArrays(A, 0, B, 1);
//
//    ASSERT_EQ(7, median);
//}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
