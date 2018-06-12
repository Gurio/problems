/*
 *
 https://leetcode.com/problems/merge-intervals
 *
 */
 
#include <unordered_map>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

namespace std
{
  template<>
    struct hash<Interval>
    {
      size_t
      operator()(const Interval & i) const
      {
        return hash<int>()((i.end << 32) ^ (i.start));
      }
    };
}

vector <Interval> mergeI (vector<Interval>& intervals){
    if (intervals.empty()){return intervals;}
    map<int, vector<bool>> is_beginning;
    vector<Interval> result;
    int cnt = 0;
    for (auto i:intervals){
        is_beginning[i.start].push_back(true);
        is_beginning[i.end].push_back(false);
    }
    Interval i;
    for (auto p:is_beginning){
        int opener = 0;
        for (bool is_beg:p.second){
            if (is_beg){opener++;}
            else {opener--;}
        } 
        if (opener==0 && cnt!=0){continue;}
        cnt += opener;
        if (!cnt){
            if (!opener){i.start=p.first;}
            i.end = p.first;
            result.push_back(i);
        } else if (cnt==opener && opener>0) {
            i.start=p.first;
        }
    }
    return result;
}

int main(){
    vector<Interval> input;
    vector<Interval> result;
    input = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18)};
    result = mergeI(input);
    for (std::vector<Interval>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << "[" << i->start<< "," << i->end << "], "; 
    cout << endl;

   input = {Interval(1,3),Interval(2,6),Interval(8,10),Interval(15,18),Interval(10,12)};
    result = mergeI(input);
    for (std::vector<Interval>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << "[" << i->start<< "," << i->end << "], "; 
    cout << endl;

   input = {Interval(1,4),Interval(1,4)};
    result = mergeI(input);
    for (std::vector<Interval>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << "[" << i->start<< "," << i->end << "], "; 
    cout << endl;

    input = {Interval(1,4),Interval(1,5)};
    result = mergeI(input);
    for (std::vector<Interval>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << "[" << i->start<< "," << i->end << "], "; 
    cout << endl;

    input = {Interval(1,4),Interval(0,0)};
    result = mergeI(input);
    for (std::vector<Interval>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << "[" << i->start<< "," << i->end << "], "; 
    cout << endl;

    input = {Interval(2,3),Interval(5,5),Interval(2,2),Interval(3,4),Interval(3,4)};
    result = mergeI(input);
    for (std::vector<Interval>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << "[" << i->start<< "," << i->end << "], "; 
    cout << endl;

    return 0;
}