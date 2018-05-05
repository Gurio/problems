/*
 *
 https://leetcode.com/problems/palindrome-number/
 *
 */

#include <iostream>

using namespace std;

bool isPalindrome(int x){
    if (x<0){return false;}
    if (x == 0) {return true;}
    int x_ = x;
    int rev = 0;
    while (x_){
        int digit = x_%10;
        rev = rev*10 + digit;
        x_ /= 10;
    }
    if (x==rev){return true;}
    return false;
}


int main(){
    cout << isPalindrome(42) << endl;
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(10) << endl;
    cout << isPalindrome(12388321) << endl;
    return 0;
}