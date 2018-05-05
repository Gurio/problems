/*
 *
 https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
 https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


double correctMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
    double median = 0;
    std::vector<int> dst;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));
    size_t size = dst.size();
    median = size % 2 ? dst[size / 2] : ((double)dst[size / 2 - 1] + (double)dst[size / 2]) / 2;
    return median;
}

// A utility function to find median of two integers
float MO2(int a, int b)
{ return ( a + b ) / 2.0; }
 
// A utility function to find median of three integers
float MO3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c))
                     - min(a, min(b, c));
}
 
// A utility function to find median of four integers
float MO4(int a, int b, int c, int d)
{
    int Max = max( a, max( b, max( c, d ) ) );
    int Min = min( a, min( b, min( c, d ) ) );
    return ( a + b + c + d - Max - Min ) / 2.0;
}
 
// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
   if (n == 0)
      return -1;
   if (n%2 == 0)
        return (double)(arr[n/2] + arr[n/2-1])/2;
   return arr[n/2];
}
 
// This function assumes that N is smaller than or equal to M
// This function returns -1 if both arrays are empty
float findMedianUtil( int A[], int N, int B[], int M )
{
    // If smaller array is empty, return median from second array
    if (N == 0)
      return medianSingle(B, M);
 
    // If the smaller array has only one element
    if (N == 1)
    {
        // Case 1: If the larger array also has one element,
        // simply call MO2()
        if (M == 1)
            return MO2(A[0], B[0]);
 
        // Case 2: If the larger array has odd number of elements,
        // then consider the middle 3 elements of larger array and
        // the only element of smaller array. Take few examples
        // like following
        // A = {9}, B[] = {5, 8, 10, 20, 30} and
        // A[] = {1}, B[] = {5, 8, 10, 20, 30}
        if (M & 1)
            return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );
 
        // Case 3: If the larger array has even number of element,
        // then median will be one of the following 3 elements
        // ... The middle two elements of larger array
        // ... The only element of smaller array
        return MO3( B[M/2], B[M/2 - 1], A[0] );
    }
 
    // If the smaller array has two elements
    else if (N == 2)
    {
        // Case 4: If the larger array also has two elements,
        // simply call MO4()
        if (M == 2)
            return MO4(A[0], A[1], B[0], B[1]);
 
        // Case 5: If the larger array has odd number of elements,
        // then median will be one of the following 3 elements
        // 1. Middle element of larger array
        // 2. Max of first element of smaller array and element
        //    just before the middle in bigger array
        // 3. Min of second element of smaller array and element
        //    just after the middle in bigger array
        if (M & 1)
            return MO3 ( B[M/2],
                         max(A[0], B[M/2 - 1]),
                         min(A[1], B[M/2 + 1])
                       );
 
        // Case 6: If the larger array has even number of elements,
        // then median will be one of the following 4 elements
        // 1) & 2) The middle two elements of larger array
        // 3) Max of first element of smaller array and element
        //    just before the first middle element in bigger array
        // 4. Min of second element of smaller array and element
        //    just after the second middle in bigger array
        return MO4 ( B[M/2],
                     B[M/2 - 1],
                     max( A[0], B[M/2 - 2] ),
                     min( A[1], B[M/2 + 1] )
                   );
    }
 
    int idxA = ( N - 1 ) / 2;
    int idxB = ( M - 1 ) / 2;
 
     /* if A[idxA] <= B[idxB], then median must exist in
        A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB] )
      return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA );
 
    /* if A[idxA] > B[idxB], then median must exist in
       A[...idxA] and B[idxB....] */
    return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}
 
// A wrapper function around findMedianUtil(). This function
// makes sure that smaller array is passed as first argument
// to findMedianUtil
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if (nums1.size() > nums2.size())
       return findMedianUtil( nums2.data(), nums2.size(), nums1.data(), nums1.size() );
 
    return findMedianUtil( nums1.data(), nums1.size(), nums2.data(), nums2.size() );
}

int main(){
    vector<int> input_1 = {1,2};
    vector<int> input_2 = {4};
    double correct_result = correctMedianSortedArrays(input_1, input_2);
    double result = findMedianSortedArrays(input_1, input_2);
    cout << correct_result << " : " << result << endl;


    input_1 = {1,2,3,11,12,16};
    input_2 = {5,13,14,14};
    correct_result = correctMedianSortedArrays(input_1, input_2);
    result = findMedianSortedArrays(input_1, input_2);
    cout << correct_result << " : " << result << endl;
    return 0;
}

/*

int checkFit (vector<int>& nums, int i, int num){
    bool lesser = (i>0 && nums[i-1]>num);
    bool greater = (i<nums.size()-1 && nums[i+1]>num);
    if (!lesser && !greater) {return 0;}
    if (lesser) return -1;
    return 1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size = nums1.size() + nums2.size();
    int i_offset = nums1.size()/2;
    int j_offset = nums2.size()/2;
    int i = i_offset;
    int j = j_offset;
    while (i_offset && j_offset){
        i_offset /= 2;
        j_offset /= 2;
        int num1 = nums1[i];
        int num2 = nums2[j];
        int fit_i = checkFit(nums2,j,num1);
        int fit_j = checkFit(nums1,i,num2);
        if (fit_i){i = i + (fit_i*i_offset);}
        if (fit_j){j = j + (fit_j*j_offset);}
        if ((fit_j == 0 && fit_i == 0) || (!i_offset && !j_offset)){
            if (size % 2 == 0){
                return ((double)(num1+num2))/2.0;
            }
            if ((double)(i+j+1)>((double)(size))/2.0){
                return min (num1,num2);
            } else {
                return max (num1,num2);
            }
        }
    }
    cout << "what do I do?" << endl;
}
*/