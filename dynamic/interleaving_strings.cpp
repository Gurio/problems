/*
 *
 https://leetcode.com/problems/strange-printer
 *
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

using namespace std;

vector<vector<int>> memo;

bool isInterleaveHelper(string& s1, string& s2, string& s3, int s1_st, int s2_st, int s3_st) {
    if (s1_st >= s1.size() &&
    s2_st >= s2.size() &&
    s3_st >= s3.size()){
        return true;
    }
    if (memo[s1_st][s2_st]!=-1){
        return memo[s1_st][s2_st];
    }
    int len1=s1.size()-s1_st,len2=s2.size()-s2_st,len3=s3.size()-s3_st;
    bool result = false;

    //cout << len1 << " " << len2 << endl;
    if (!len3){
        memo[s1_st][s2_st] = false;
        return false;
    }
    if (len1 && s1[s1_st]==s3[s3_st]){
        result |= isInterleaveHelper(s1,s2,s3,s1_st+1,s2_st,s3_st+1);
    }
    if (len2 && s2[s2_st]==s3[s3_st]){
        result |= isInterleaveHelper(s1,s2,s3,s1_st,s2_st+1,s3_st+1);
    }
    memo[s1_st][s2_st]=result;
    return result;
}

bool isInterleave(string& s1, string& s2, string& s3) {
    memo = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1,-1));
    return isInterleaveHelper(s1,s2,s3,0,0,0);
}

int main(){
    string str1,str2,str3;
    str1 = "aabcc"; str2 = "dbbca"; str3 = "aadbbcbcac";
    cout << isInterleave(str1,str2,str3)<<endl;

    str1 = "aabcc"; str2 = "dbbca"; str3 = "aadbbbaccc";
    cout << isInterleave(str1,str2,str3)<<endl;

    str1 = ""; str2 = ""; str3 = "a";
    cout << isInterleave(str1,str2,str3)<<endl;

    str1 = "cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc";
    str2 = "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb";
    str3 = "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb";
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bool res = isInterleave(str1,str2,str3);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << res <<endl;
    cout << "duration: " << duration << endl;

    return 0;
}