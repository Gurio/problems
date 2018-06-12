/*
 *
 https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int findKthLargest(vector<int>& nums, int s, int e, int k) {
    cout << s << " "<< e << " "<< k<< ": " << nums[s] << endl;
    if (s>=e) {return nums[s];}
    int pivot = nums[s];
    int i=s+1, j=e;
    while(i<=j){
        while (i<=j && nums.at(i)<=pivot){i++;}
        while (i<=j && nums.at(j)>=pivot){j--;}
        if (j<=i)break;
        swap(nums[i], nums[j]);
    }
    if (i>0){i--;}
    if (nums[s] > nums[i]) {swap(nums[i],nums[s]);}
    if (i==k) {return nums[i];}
    if (i>k){
        return findKthLargest(nums,s,i-1,k);
    }
    return findKthLargest(nums,i+1,e,k);
}

int findKthLargest(vector<int> nums, int k) {
    if (nums.empty()){return 0;}
    return findKthLargest(nums, 0, nums.size()-1, nums.size()-k);
}

int main(){
    vector<int> input = {3, 1, 2, 4, 5};
    int result = findKthLargest(input, 2);
    cout << result << endl; 

    input = {3, 1, 2, 4, 5};    
    result = findKthLargest(input, 3);
    cout << result << endl; 

    input = {1,2,1};
    result = findKthLargest(input, 1);
    cout << result << endl; 

    input = {1,1};
    result = findKthLargest(input, 2);
    cout << result << endl; 
    return 0;
}