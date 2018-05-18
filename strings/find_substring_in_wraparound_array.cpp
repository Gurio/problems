/*
 *
 https://leetcode.com/problems/unique-substrings-in-wraparound-string
 *
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <functional>
#include <chrono>



struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

using namespace std;
using namespace std::chrono;

bool isSeq (char a, char b){
    if (a=='z' && b=='a') {return true;}
    if (a>='a' && b<='z') {return a==b-1;}
}

int findSubstringInWraproundString(string& p) {
    unordered_set<pair<char, int>, pairhash> unique_seqs;
    int len=0;
    for (int i=0; i<p.size(); i++){
        unique_seqs.insert(make_pair(p[i],0));
        if (i && !isSeq(p[i-1],p[i])){
            len = 0;
        }
        for (int j=1; j<=len; j++){
            unique_seqs.insert(make_pair(p[i-j],j));
        }
        len++;
    }
    return unique_seqs.size();
}

int main(){
    string test_str = "a";
    int result = findSubstringInWraproundString(test_str);
    cout << result << endl;
    test_str = "cac";
    result = findSubstringInWraproundString(test_str);
    cout << result << endl;
    test_str = "zab";
    result = findSubstringInWraproundString(test_str);
    cout << result << endl;
    test_str = "cabcz";
    result = findSubstringInWraproundString(test_str);
    cout << result << endl;
    test_str = "cabcdz";
    result = findSubstringInWraproundString(test_str);
    cout << result << endl;
    test_str = "pwxykew";
    result = findSubstringInWraproundString(test_str);
    cout << result << endl;

    test_str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    result = findSubstringInWraproundString(test_str);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << result << endl;
    cout << "time: " << duration;
    return 0;
}