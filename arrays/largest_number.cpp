/*
 *
 https://leetcode.com/problems/largest-number
 *
 */

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string largestNumber(vector<int>& nums) {
    if (nums.empty()){return "";}
	vector<string> str_nums;
	for (int n: nums){
		str_nums.push_back(to_string(n));
	}
	auto comparator = [](string& lhs, string& rhs){
        string s1 = lhs+rhs;
        string s2 = rhs+lhs;
		int res = s1.compare(s2);
        return res<0;
	};
    sort(str_nums.begin(),str_nums.end(),comparator);
    reverse(str_nums.begin(), str_nums.end());
    string result;
    for (auto str: str_nums){
        result += str;
    }
    return result;
}


int main(){
    cout << boolalpha;
    
    vector<int> input = {1440,7548,4240,6616,733,4712,883,8,9576};
    cout << largestNumber(input) << endl;
    if (largestNumber(input) == "9576888375487336616471242401440"){
        cout << true << endl << endl;
    } else {
        cout << false << endl << endl;
    }

    input = {3, 1, 2, 4, 5};
    cout << largestNumber(input) << endl; 

    input = {128,12};
    cout << largestNumber(input) << endl; 

    input = {10,2};    
    cout << largestNumber(input) << endl;

    input = {3,30,34,5,9};
    cout << largestNumber(input) << endl;

    input = {90,250,90111};
    cout << largestNumber(input) << endl;
    
    input = {90,250,90340};
    cout << largestNumber(input) << endl;

    input = {4704,6306,9385,7536,3462,4798,5422,5529,8070,6241,9094,7846,663,6221,216,6758,8353,3650,3836,8183,3516,5909,6744,1548,5712,2281,3664,7100,6698,7321,4980,8937,3163,5784,3298,9890,1090,7605,1380,1147,1495,3699,9448,5208,9456,3846,3567,6856,2000,3575,7205,2697,5972,7471,1763,1143,1417,6038,2313,6554,9026,8107,9827,7982,9685,3905,8939,1048,282,7423,6327,2970,4453,5460,3399,9533,914,3932,192,3084,6806,273,4283,2060,5682,2,2362,4812,7032,810,2465,6511,213,2362,3021,2745,3636,6265,1518,8398};
    cout << largestNumber(input) << endl;
    if (largestNumber(input) == "98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048"){
        cout << true << endl << endl;
    } else {
        cout << false << endl << endl;
    }

    input = {9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519};
    
    cout << largestNumber(input) << endl;
    if (largestNumber(input) == "995998549642963295795569525905189958985890288238775871870185978591838283748308830827481618052787813771758475277519744072727265721971071006861683682268046787640663256310614560285906582858175752573156385565552654905441522852245213513750414822478747104662455545424532434289408839763963946391038663723370035134023393328828692788270926232581243924362362304226421162109163016131603127210891014"){
        cout << true << endl << endl;
    } else {
        cout << false << endl << endl;
    }
    return 0;
}