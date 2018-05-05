/*
 *
 https://leetcode.com/problems/3sum/description/
 *
 */
 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

void sort3 (int& a, int& b, int& c){
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

vector < vector<int> > threeSum (vector<int>& nums){
    vector<vector<int>> result;
    unordered_set<int> processed;
    unordered_map<int,unordered_set<int>> triplets;
    for (int i=0; i<(nums.size()-1); i++){
        int a = nums[i];
        if (processed.find(a)==processed.end()){
            unordered_set<int> pairs;
            int complement = -1 * a;
            for (int j=i+1; j<nums.size(); j++){
                int c = nums[j];
                int b = complement - c;
                int sum = a+b+c;
                //cout << "evaluating: " << a << b << c << endl;
                if (pairs.find(b)!=pairs.end()&&!sum){

                    //cout << "good: " << a << b << c << endl;
                    int a_ = a;
                    int b_ = b;
                    int c_ = c;
                    sort3(a_,b_,c_);
                    vector<int> triplet = {a_,b_,c_};
                    if (triplets.find(a_) == triplets.end()){
                        result.push_back(triplet);
                    } else if (triplets[a_].find(b_) == triplets[a_].end()){
                        result.push_back(triplet);
                    } 
                    triplets[a_].insert(b_);
                }
                //cout << "adding: "<< c << endl;
                pairs.insert(c);
            }
        }
        processed.insert(a);
    }
    return result;
    //return {{-1,0,1},{-1,-1,2}};
}

int main(){
    //vector<int> input = {-1,0,1,2,-1,-4};
    vector<int> input = {3,0,-2,-1,1,2};
    //vector<int> input = {0,0,0};
    vector<vector<int> > result = threeSum(input);
    for (vector<vector<int> >::const_iterator v = result.begin(); v != result.end(); ++v){
        for (vector<int>::const_iterator i = v->begin(); i != v->end(); ++i)
            cout << *i << ' '; 
        cout << endl;
    }
    return 0;
}