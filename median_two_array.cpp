class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int medianA = A[m / 2];
        int medianB = B[n / 2];

        int temp = SearchIndex(medianB, A, m);
        int floorAIndex = medianA <  temp ? medianA : temp;
        int ceilingAIndex = medianA > temp ? medianA : temp;
        temp = SearchIndex(medianA, B, n);
        int floorBIndex = medianB < temp ? medianB : temp;
        int ceilingBIndex = medianB > temp ? medianB : temp;

        double result = 0;
        int indexInA = 0, indexInB = 0;
        do
        {
            bool big = true;
            if (indexInA + indexInB < (m + n) / 2)
            {
                big = false;
            }
            result = GetIndex(A, floorAIndex, ceilingAIndex, B, floorBIndex, ceilingBIndex, big);
            indexInA = SearchIndex(result, A, m);
            indexInB = SearchIndex(result, B, n);
        } while (indexInA + indexInB != (m+n)/2); 

        return result;
    }

    double GetIndex(int Array1[], int start1, int end1, int Array2[], int start2, int end2, bool big)
    {
        return 0;
    }

    int SearchIndex(double value, int arrary[], int length)
    {
        return 0;
    }
};

int main()
{
    return 0;
}