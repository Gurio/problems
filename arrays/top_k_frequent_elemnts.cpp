/*
 *
 https://leetcode.com/problems/top-k-frequent-elements
 *
 */
 
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    if (k==0) {return {};}
    vector<int> result(k);
    unordered_map<int,int> freq;
    vector<pair<int,int>> freq_nums;
    for (int n: nums){
        freq[n]++;
    }
    for (auto p: freq){
        freq_nums.push_back(make_pair(p.second, p.first));
    }
    partial_sort(freq_nums.begin(), freq_nums.begin()+k, freq_nums.end(), greater<pair<int,int>>());
    for (int i=0; i<k; i++){
        result[i]=freq_nums[i].second;
    }
    return result;
}

int main(){
    vector<int> input = {2,3,5,6,7,8,9,1,2,3,4,1,2,1,1,2,1,3,4,5,0,0,0,0,0};
    vector<int> res = topKFrequent(input, 3);
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl;
    input = {2,3,5,6,7,8,9,1,2,3,4,1,2,1,1,2,1,3,4,5};
    res = topKFrequent(input, 2);
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl;
    return 0;
}