#include "median_two_array.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(median_two_array, TwoSingleElement)
{
    Solution solution;
    int A[]{1};
    int B[]{2};
    double median = solution.findMedianSortedArrays(A, 1, B, 1);

    ASSERT_EQ(1.5, median);
}

TEST(median_two_array, HappyPath_Odd)
{
    Solution solution;
    int A[]{1,3,5,9,13};
    int B[]{7,8,15,19};
    double median = solution.findMedianSortedArrays(A, 5, B, 4);

    ASSERT_EQ(8, median);
}

TEST(median_two_array, HappyPath_Odd_2)
{
    Solution solution;
    int A[]{1};
    int B[]{2, 3};
    double median = solution.findMedianSortedArrays(A, 1, B, 2);

    ASSERT_EQ(2, median);
}

TEST(median_two_array, HappyPath_Odd_3)
{
    Solution solution;
    int A[]{1};
    int B[]{2, 3, 4, 5};
    double median = solution.findMedianSortedArrays(A, 1, B, 4);

    ASSERT_EQ(3, median);
}

TEST(median_two_array, Meidan_Appear_Multiple_Instances)
{
    Solution solution;
    int A[]{1,2};
    int B[]{1,2,3};
    double median = solution.findMedianSortedArrays(A, 2, B, 3);

    ASSERT_EQ(2, median);
}

TEST(median_two_array, Meidan_Appear_Multiple_Instances_2)
{
    Solution solution;
    int A[]{1, 1, 3, 3};
    int B[]{1, 1, 3, 3};
    double median = solution.findMedianSortedArrays(A, 4, B, 4);

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

TEST(median_two_array, HappyPath_Even_2)
{
    Solution solution;
    int A[]{1, 2, 3, 7};
    int B[]{4, 5, 6, 8, 9, 10};
    double median = solution.findMedianSortedArrays(A, 4, B, 6);

    ASSERT_EQ(5.5, median);
}

TEST(median_two_array, HappyPath_Even_3)
{
    Solution solution;
    int A[]{1};
    int B[]{2, 3, 4, 5, 6, 7, 8};
    double median = solution.findMedianSortedArrays(A, 1, B, 7);

    ASSERT_EQ(4.5, median);
}

TEST(median_two_array, HappyPath_Even_4)
{
    Solution solution;
    int A[]{4};
    int B[]{1, 2, 3};
    double median = solution.findMedianSortedArrays(A, 1, B, 3);

    ASSERT_EQ(2.5, median);
}

TEST(median_two_array, HappyPath_Even_5)
{
    Solution solution;
    int A[]{1, 2};
    int B[]{3, 4};
    double median = solution.findMedianSortedArrays(A, 2, B, 2);

    ASSERT_EQ(2.5, median);
}

TEST(median_two_array, HappyPath_Even_6)
{
    Solution solution;
    int A[]{7, 8, 9};
    int B[]{1, 2, 3, 4, 5, 6, 10};
    double median = solution.findMedianSortedArrays(A, 3, B, 7);

    ASSERT_EQ(5.5, median);
}

TEST(median_two_array, HappyPath_Even_SingleElement)
{
    Solution solution;
    int A[]{1};
    int B[]{1};
    double median = solution.findMedianSortedArrays(A, 1, B, 1);

    ASSERT_EQ(1, median);
}

TEST(median_two_array, HappyPath_Even_DoubleElement)
{
    Solution solution;
    int A[]{1, 2};
    int B[]{1, 2};
    double median = solution.findMedianSortedArrays(A, 2, B, 2);

    ASSERT_EQ(1.5, median);
}

TEST(median_two_array, NoOverlap)
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

TEST(median_two_array, EmptyArray1)
{
    Solution solution;

    int B[]{2};
    double median = solution.findMedianSortedArrays(nullptr, 0, B, 1);

    ASSERT_EQ(2, median);
}

TEST(median_two_array, EmptyArray2)
{
    Solution solution;

    int B[]{2, 3};
    double median = solution.findMedianSortedArrays(nullptr, 0, B, 2);

    ASSERT_EQ(2.5, median);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
