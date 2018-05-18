/*
 *
 https://leetcode.com/problems/missing-number/
 *
 */
 
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

int missingNumber (const vector<int>& nums){
    int result = 0;
    for (size_t i = 0; i<nums.size(); i++){
        result ^= i;
        result ^= nums[i];
    }
    result ^= nums.size();
    return result;
}

int main(){
    vector<int> input = {2,8,3,1,4,9,5,6,0};
    int result = missingNumber(input);
    cout << result << endl;
    input = {3,0,1};
    result = missingNumber(input);
    cout << result << endl;
    return 0;
}