/*
 *
 https://leetcode.com/problems/search-in-rotated-sorted-array
 *
 */
 
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int getOffset(const vector<int>& nums){
    int start = nums[0];
    int left = 0;
    int right = nums.size()-1;
    int mid = right/2+1;
    while (left < right+1){
        if (mid > 0 && nums[mid-1] > nums[mid]){
            return mid;
        } else if (mid == 0 && nums.size() > 1 && nums[mid] > nums[mid+1]) {
            return mid+1;
        }
        if (nums[mid]>start){
            left = mid+1;
        } else {
            right = mid-1;
        }
        mid = left + (right-left)/2;
    }
    return mid;
}

int search (const vector<int>& nums, int target){
    if (nums.empty()){return -1;}
    int offset = getOffset(nums);
    int left = 0;
    int right = nums.size()-1;
    int mid = right/2+1;
    while (left < right+1){
        size_t idx = (mid+offset)%nums.size();
        int num = nums[idx];
        if (num == target){
            return idx;
        }
        if (num < target){
            left = mid+1;
        } else {
            right = mid-1;
        }
        mid = left + (right-left)/2;
    }
    return -1;
}

int main(){
    vector<int> input = {1,2,3,4,5};
    int result = search(input, 5);
    cout << result << endl;
    return 0;
}