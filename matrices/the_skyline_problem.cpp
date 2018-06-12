/*
 *
 https://leetcode.com/problems/the-skyline-problem
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

void print_tuple (tuple<int,int,int> t){
    cout << "(" << get<0>(t) << "," << get<2>(t) << "," <<get<2>(t) << "," << ")";
}

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    map<int, vector<int>> heightToCoordsMapping;
    multiset<int> heights = {0};
    for(auto b: buildings) {
        heightToCoordsMapping[b[0]].push_back(b[2]);
        heightToCoordsMapping[b[1]].push_back(-b[2]);
    }
    vector<pair<int,int>> res;
    for(auto elem: heightToCoordsMapping) {
        for (auto h: elem.second) {
            if (h > 0) heights.insert(h);
            else {
                auto itr = heights.find(-h);
                if(itr!=heights.end()){
                    heights.erase(itr);
                }
            }
        }
        if (res.empty() || *heights.rbegin() != res.back().second) {
            res.push_back(make_pair(elem.first, *heights.rbegin()));
        }
    }
    return res;
}


int main(){
    vector<vector<int>> input ={{2, 9, 10},
                                {3, 7, 15},
                                {5, 12, 12},
                                {15, 20, 10},
                                {19, 24, 8}};
    
    vector<pair<int, int>> res;
    res = getSkyline(input);
    cout << "res: "<< endl;
    for (std::vector<pair<int, int>>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << i->first << ":" << i->second << ", "; 
    cout << endl;

    input ={{2, 9, 10},
            {3, 7, 15},
            {5, 12, 12},
            {15, 20, 10},
            {19, 24, 8},
            {23, 28, 8}};
    res = getSkyline(input);
    cout << "res: "<< endl;
    for (std::vector<pair<int, int>>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << i->first << ":" << i->second << ", "; 
    cout << endl;

    input ={{0, 2, 3},
            {2, 5, 3}};
    res = getSkyline(input);
    cout << "res: "<< endl;
    for (std::vector<pair<int, int>>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << i->first << ":" << i->second << ", "; 
    cout << endl;

    input ={{0,2147483647,2147483647}};
    res = getSkyline(input);
    cout << "res: "<< endl;
    for (std::vector<pair<int, int>>::const_iterator i = res.begin(); i != res.end(); ++i)
        cout << i->first << ":" << i->second << ", "; 
    cout << endl;
    return 0;
}