/*
 *
 https://leetcode.com/problems/spiral-matrix-ii
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;


void fill(vector<vector<int>> &board,int n,int i,int v)
{
    //cout << i << endl;
    int s=(n-i)/2;
    int e=s+i-1;

    if (s>n) {return;}
    
    //cout << s << " " << e << endl;
    for (int j=s;j<=e;j++){board[s][j]=++v;}
    //cout << ">";
    for (int j=s+1;j<=e;j++){board[j][e]=++v;}
    //cout << "|";
    for (int j=e-1;j>=s;j--){board[e][j]=++v;}
    //cout << "<";
    for (int j=e-1;j>s;j--){board[j][s]=++v;}
    //cout << "^";
    //cout << endl;
    fill(board, n, i-2, v);
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n,vector<int>(n));
    fill(ret,n,n,0);
    return ret;
}


int main(){
    auto res = generateMatrix(4);
    for (auto l :res){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    res = generateMatrix(3);
    for (auto l :res){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    res = generateMatrix(5);
    for (auto l :res){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    res = generateMatrix(1);
    for (auto l :res){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    res = generateMatrix(11);
    for (auto l :res){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    res = generateMatrix(12);
    for (auto l :res){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    return 0;
}