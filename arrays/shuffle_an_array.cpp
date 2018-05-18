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
#include <cstdlib>

using namespace std;

vector <int> _nums;

void init(vector<int> nums) {
    _nums = nums;
}

/** Resets the array to its original configuration and return it. */
vector<int> reset() {
    return _nums;
}

/** Returns a random shuffling of the array. */
vector<int> shuffle() {
    vector<int> res(_nums);
    for (size_t i = 0; i<res.size(); i++){
        int rand_i = i+std::rand()%(res.size()-i);
        swap (res[i],res[rand_i]);
    }
    return res;
}

int main(){
    vector<int> res;
    init ({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19});
    res = shuffle();
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl;

    res = reset();
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl;

    res = shuffle();
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl;
    
    res = reset();
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl;
    
    res = shuffle();
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl;

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