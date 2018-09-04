/*
 *
 CCI 1.5 One away
 *
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <limits>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool oneAway (const string& left, const string& right){
    unordered_map<char,int> chars;
    for (auto c: left){
        ++chars[c];
    }
    for (auto c: right){
        --chars[c];
    }
    int dels = 0, adds = 0;
    for (auto kv: chars){
        if (!kv.second) {continue;}
        if (abs(kv.second) > 1) {return false;}
        if (kv.second > 0) {
            adds += 1;
        } else {
            dels += 1;
        }
    }
    return ((adds < 2 && dels < 2));
}

int main(){
    
    cout << oneAway("ape", "abe") << endl;
    cout << oneAway("ape", "apee") << endl;
    cout << oneAway("ape", "pe") << endl;
    cout << oneAway("ape", "be") << endl;
    cout << oneAway("ape", "ape") << endl;

    return 0;
}