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
    if (buildings.empty()) {return {};}
    vector<pair<int, int>> result;
    map<int, tuple<int,int,int>> starts;
    map<int, tuple<int,int,int>> ends;
    int max_end = 0;
    for (auto building:buildings){
        int start = building[0];
        int end = building[1];
        int height = building[2];
        starts[start] = make_tuple(start, end, height);
        ends[end] = make_tuple(start, end, height);
        max_end = end;
    }
    buildings.insert(buildings.begin(),vector<int>({0,max_end,0}));

    for (auto building:buildings){
        int start = building[0];
        int end = building[1];
        int height = building[2];
        auto start_it = starts.upper_bound(start);
        auto end_it = ends.upper_bound(start);
        set<tuple<int,int,int>> covers;
        while (end_it != ends.end() && get<0>(end_it->second) < end ){
            int cover_height = get<2>(end_it->second);
            if (cover_height > height){
                covers.insert(end_it->second);
                //print_tuple (end_it->second);
            }             
            ++end_it;
        }
        while (start_it != starts.end() && get<0>(start_it->second) < end ){
            int cover_height = get<2>(start_it->second);
            if (cover_height > height){
                covers.insert(start_it->second);
                //print_tuple (start_it->second);
            }             
            ++start_it;
        }
        //cout << endl;
        for (auto cover:covers){
            int cov_start = get<0>(cover);
            int cov_end = get<1>(cover);
            int cov_height = get<2>(cover);
            if (cov_start >= start){
                result.push_back(make_pair(cov_start, cov_height));
            }
            if (cov_end <= end){
                result.push_back(make_pair(cov_end, height));                
            }
            start = max (start, cov_end);
        }
    }
    sort(result.begin(),result.end());
    vector<pair<int,int>> new_res;
    for (size_t i=1;i<result.size(); i++){
        if (result[i].first == result[i-1].first || result[i].second == result[i-1].second){

        } else {
            new_res.push_back(result[i-1]);
        }
    }
    new_res.push_back(result[result.size()-1]);
    return new_res;
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