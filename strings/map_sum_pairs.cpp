/*
 *
 https://leetcode.com/problems/map-sum-pairs
 *
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <limits>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>

using namespace std;

map <string, int> pairs;

void insert(string key, int val) {
    pairs[key] = val;
}

int sum(string prefix) {
    if (prefix.empty()) {return 0;}
    string end_prefix = prefix;
    ++end_prefix[end_prefix.size()-1];
    int sum = 0;
    auto start = pairs.lower_bound(prefix);
    auto end = pairs.lower_bound(end_prefix);
    if (end!=pairs.end()&&
        end->first.find(prefix)==0){
            ++end;
        }
    while (start != end){
        sum += start->second;
        ++start;
    }
    return sum;
}

int main(){
    insert("apple", 1);
    insert("bow", 1);
    insert("three", 4);
    insert("apple", 3);
    insert("aq", 3);
    cout << sum("ap") << endl;
    insert("application", 2);
    cout << sum("ap") << endl;
    insert("ap", 1);
    cout << sum("ap") << endl;
    cout << sum("a") << endl;

    return 0;
}