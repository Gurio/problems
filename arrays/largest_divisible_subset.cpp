/*
 *
 https://leetcode.com/problems/largest-divisible-subset
 *
 */
 
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
    for (auto s:subsets){
        cout << s.first << ": ";
        for (std::vector<int>::const_iterator i = s.second.begin(); i != s.second.end(); ++i)
            cout << *i << ", "; 
        cout << endl;
    }



                cout << "max for " << num << ", div:"<< divisor << "; ";
                for (std::vector<int>::const_iterator i = max->begin(); i != max->end(); ++i)
                    cout << *i << ", "; 
                cout << endl;
*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size()<2){return nums;}
    map<int,int> num_freq;
    for (int n:nums){
        ++num_freq[n];
    }
    unordered_map<int,vector<int>> subsets;
    int max_len, max_id;
    max_len=0;
    int num, freq;
    for (auto& p:num_freq){
        tie(num,freq) = p;
        vector<int> *max = nullptr;
        for (auto divisor_n_f:num_freq){
            int divisor = divisor_n_f.first;
            if (divisor>num){break;}
            if (num % divisor == 0 && (!max || max->size()<subsets[divisor].size())){
                max = &subsets[divisor];
            }

        }
        vector<int> new_subset(*max);
        new_subset.insert(new_subset.end(), freq, num);
        subsets[num] = new_subset;
        if (max_len < new_subset.size()){
            max_len = new_subset.size();
            max_id = num;
        }
        
    }

    return subsets[max_id];
}


int main(){
    vector<int> res;
    vector<int> input = {1,2,3};
    res = largestDivisibleSubset(input);
    cout << "res: "<< endl;
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl << endl;

    input = {1,2,3,4,6,24};
    res = largestDivisibleSubset(input);
    cout << "res: "<< endl;
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl << endl;
    
    input = {1,2,4,8,9};
    res = largestDivisibleSubset(input);
    cout << "res: "<< endl;
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl << endl;
    
    input = {1,2,3,4,5};
    res = largestDivisibleSubset(input);
    cout << "res: "<< endl;
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl << endl;


    input = {1,2,3,4,5,6,3,4,51,23,7,4,132,45,12,54,75,45,110,919,923,99,293,439,743,374,328,812,843,288,238,283,412,712,53,92,827,9,12,45,12,62,13,45,20,19,59,239,34,54,39,17,982,2038,43918,12093,29380,12098,438,10293,8038,401920,43091,32097,4031,70,1923,897,837,9023,4309,2390,391,23901,102,983,10,283,7832,298,398,128,849,547,897,298,2,8492,230983,23982,39832,9328,9238,9832,923,2938,984,2982,8709,2982,98298,29,298,609,328,324,239,2349,2349,341,345,346,349,394,90,309,394,892,983,390,980,849,800,9038,856,933,93,947,5498,94580,503,9450,304,709,3450,034,509,304,109,340,209,83240,93,40,209340};
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    res = largestDivisibleSubset(input);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "res: "<< endl;
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << *i << ", "; 
    cout << endl << endl;
    cout << "time: " << duration;
    return 0;
}