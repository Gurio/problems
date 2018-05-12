/*
 *
 https://leetcode.com/problems/climbing-stairs
 *
 */

#include <iostream>

using namespace std;

int climbStairs(int s) {
    if (s<=0){return 0;}
    if (s<3) {return s;}
    int n_1 = 1;
    int n = 2;
    for (int i=3; i<=s; i++){
        int prev_n = n;
        n = n + n_1;
        n_1 = prev_n;
    }
    return n;
}

int main(){
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
    cout << climbStairs(4) << endl;
    cout << climbStairs(10) << endl;
    cout << climbStairs(12) << endl;
    cout << climbStairs(120) << endl;
    return 0;
}