/*
 *
 https://leetcode.com/problems/string-to-integer-atoi/
 *
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <limits>

using namespace std;

pair<int,int> getNumberPos(const string& str){
    int start=0;
    int end=0;
    while (str[start]<'0' || str[start]>'9'){
        start++;
    }
    if (start != 0 && str[start-1]=='-') {start--;}
    end = start+1;
    while (str[end]>='0' && str[end]<='9'){
        end++;
    }
    return make_pair(start, end);
}

bool fitInInt32 (const string& str, int start, int end){
    string max_v;
    if (str[start] == '-') {
        max_v = "2147483648";
        start++;
    } else {
        max_v = "2147483647";
    }
    int max_size = 10;
    int size = (end - start); 
    if (size < max_size) {return true;}
    if (size > max_size) {return false;}
    for (int i=0; i<size; i++){
        cout << str[i] << ", ";
        if (str[start+i]>max_v[i]){
            return false;
        } else if (str[start+i]<max_v[i]) {
            return true;
        }
    }
    cout << endl;
    return true;
}

int myatoi(const string& s) {
    if (s.empty()) {return 0;}
    int result = 0;
    int start, end;
    tie(start, end) = getNumberPos(s);
    int sign = s[start] == '-' ? -1 : 1;
    if (!fitInInt32(s, start, end)){
        if (sign == -1) {return numeric_limits<int>::min();}
        return numeric_limits<int>::max();
    }
    if (sign == -1) {start++;}
    for (int i = start; i<end; i++){
        cout << s[i] << ", ";
        int digit = s[i]-'0';
        result = result*10 + digit;
    }
    cout << endl;
    return result*sign;
}

int main(){
    cout << myatoi("42") << endl;
    cout << myatoi("   -42") << endl;
    cout << myatoi("4193 with words") << endl;
    cout << myatoi("words and 987") << endl;
    cout << myatoi("words and -987 and words") << endl;
    cout << myatoi("words and - 987") << endl;
    cout << myatoi("-91283472332") << endl;
    cout << myatoi("1095502006p8") << endl;
    return 0;
}