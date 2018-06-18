/*
 *
 https://leetcode.com/problems/third-maximum-number
 *
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int thirdMax(vector<int>& nums) {
    if (nums.empty()) {return 0;}
    vector<int> max_3;

    for (auto n: nums){
        bool cnt = false;
        for (auto m: max_3){
            if (m==n){cnt=true;}
        }
        if (cnt){continue;}
        if (max_3.size() < 3) {
            max_3.push_back(n);
            sort (max_3.begin(),max_3.end());
            continue;
        }
        if (max_3[0]>n){continue;}
        max_3[0] = n;
        sort (max_3.begin(),max_3.end());
    }
    if (max_3.size()==3){return max_3[0];}
    return max_3[max_3.size()-1];
}

int main(){
    vector<int> input = {3, 1, 1, 5, 5, 5, 4, 4, 5, 6};
    int result = thirdMax(input);
    cout << result << endl; 

    input = {3, 1, 2, 4, 5};
    result = thirdMax(input);
    cout << result << endl; 

    input = {1,2,1};
    result = thirdMax(input);
    cout << result << endl; 

    input = {1,1};
    result = thirdMax(input);
    cout << result << endl; 

    input = {1};
    result = thirdMax(input);
    cout << result << endl; 
    return 0;
}