#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> myMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum=0;
        int* intArr[s.size()];
        for (int i=0; i<s.size()-1; i++){ // last element always added
            if (myMap[s[i]] >= myMap[s[i+1]]){
                sum+=myMap[s[i]];
            }
            else {
                sum-=myMap[s[i]];
            }
        }
        sum+=myMap[s[s.size()-1]];
        return sum;
    }
};

int main(){
    //std::vector<int> gas= {1, 2, 3, 4, 5};
    //std::vector<int> cost= {3, 4, 5, 1, 2};
    Solution s;
    s.romanToInt("IV");
    return 0;
} 



class Solution {
public:
    string intToRoman(int num) {
        char* ones[] = {"I", "X", "C", "M"};
        char* fives[] = {"V", "L", "D", "M"};
        char* tens[] = {"X", "C", "M", "M"}; // don't care last 2
        string myStr;
        int i = -1;
        while (num > 0){
            char compare = num % 10;
            i++;
            num /= 10;
            if (compare == 4){
                myStr += fives[i];
                myStr += ones[i];
                continue;
            }
            else if (compare == 9){
                myStr += tens[i];
                myStr += ones[i];
                continue;
            }
            if (compare >= 5){
                for(int j=5; j<compare; j++){
                    myStr += ones[i];
                }
                myStr += fives[i];
                continue;
            }
            for(int j=0; j<compare; j++){
                myStr += ones[i];
            }

        }
        std::reverse(myStr.begin(), myStr.end());
        return myStr;
    }
};