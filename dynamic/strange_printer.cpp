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

using namespace std;

vector<vector<int>> memo;

void print_mem (){
    for (auto r:memo){
        for (auto i:r){
            cout << i << ",\t";
        }
        cout << endl;
    }
}

void print_str(string& s, int begin, int end){
    cout << "processing: ";
    for (int i = begin; i < end; i++){
        cout << s[i];
    }
    cout << endl;
} 
void print_str2(string& s, int begin, int end){
    for (int i = begin; i < end; i++){
        cout << s[i];
    }
} 

int helper(string& s, int begin, int end){
    print_str(s,begin,end);
    if (begin >= end){return 0;}
    if (end-begin<2){
        memo[begin][end-1] = 1;
    }
    if (memo[begin][end-1]){return memo[begin][end-1];}

    int start = begin;
    int finish = end;
    int middle = end;
    char cur = s[start];

    for (;start < end && s[start]==cur; start++){}
    for (;finish > start && s[finish-1]==cur; finish--){}
    // I AM NOT SURE!!!!
    if (start==finish){
        memo[begin][end-1] = 1;
        return 1;
    }
    int turns = helper(s,start,finish)+1;
    for (middle=start+1; middle < finish; middle++){
        int cur_turn = 0;
        if (s[middle]==cur){
            cur_turn += helper(s,start,middle);
            //middle++;
            for (;middle<finish && s[middle]==cur; middle++){}   
            //middle++;         
            cur_turn += helper(s,middle,finish);
            turns = min(turns,cur_turn+1);
        }
        if (cur_turn){
        }
    }
    cout << "for \"";
    print_str2(s,begin,end);
    cout << "\" current turn is: " << turns << endl;
    //turns+=1;//add turn for filling up current letter
    memo[begin][end-1] = turns;
    return turns;
}

int strangePrinter(string s) {
    memo = vector<vector<int>>(s.size(), vector<int>(s.size(),0));
    //cout << s.size() << endl; 
    return helper(s, 0, s.size());
}


int dp(string& s, int i, int j) {
    if (i > j) return 0;
    if (memo[i][j] == 0) {
        int ans = dp(s, i+1, j) + 1;
        for (int k = i+1; k <= j; ++k)
            if (s[k] == s[i])
                ans = min(ans, dp(s, i, k-1) + dp(s, k+1, j));
        memo[i][j] = ans;
    }
    return memo[i][j];
}
int strangePrinter2(string& s) {
    int N = s.size();
    memo = vector<vector<int>>(s.size(), vector<int>(s.size(),0));
    return dp(s, 0, N - 1);
}

std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

int main(){
    string str;

    // for (int i=0; i<10000; i++){
    //     str = random_string(7);
    //     int mine = strangePrinter(str);
    //     int correct = strangePrinter2(str);
    //     if (mine != correct){
    //         cout << str << " - " << strangePrinter(str) << ":"<< strangePrinter2(str) << endl;
    //     }
    // }

    // str = "aaaabb";
    // cout << strangePrinter(str) << ":"<< strangePrinter2(str) << endl;
    // //print_mem ();
    str = "ceccgco";
    cout << strangePrinter(str) << ":"<< strangePrinter2(str) << endl;
    print_mem ();
    // str = "abacabaa";
    // cout << strangePrinter(str) << ":"<< strangePrinter2(str) << endl;
    // //print_mem ();
    // str = "bcccdadccdbbcbdabbbaaccdaabbbadcaaadbccbdcabdda";
    // cout << strangePrinter(str) << ":"<< strangePrinter2(str) << endl;
    //print_mem ();
    str = "aadccbacddabbbbdadbdadababacdbdadabdccddccdc";
    //cout << strangePrinter(str) << ":"<< strangePrinter2(str) << endl;
    str = "e";
    cout << strangePrinter(str) << ":"<< strangePrinter2(str) << endl;
    return 0;
}