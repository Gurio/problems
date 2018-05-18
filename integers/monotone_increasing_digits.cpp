/*
 *
 https://leetcode.com/problems/monotone-increasing-digits
 *
 */

#include <iostream>

using namespace std;

int monotoneIncreasingDigits(int N) {
    int nines = 9;
    int prev = N%10;
    int result = prev;
    if (prev==N){return N;}
    N /= 10;
    while (N){
        int digit = N % 10;
        if (digit > prev){
            result = (nines+1)*(digit-1) + nines;
            prev = digit - 1;
        } else {
            result = (nines+1)*digit + result;
            prev = digit;
        }
        nines = nines*10 + 9;
        N /= 10; 
    }
    return result;
}


int main(){
    cout << monotoneIncreasingDigits(42) << endl;
    cout << monotoneIncreasingDigits(1234) << endl;
    cout << monotoneIncreasingDigits(121) << endl;
    cout << monotoneIncreasingDigits(10) << endl;
    cout << monotoneIncreasingDigits(332) << endl;
    cout << monotoneIncreasingDigits(4321) << endl;
    cout << monotoneIncreasingDigits(12388321) << endl;
    return 0;
}