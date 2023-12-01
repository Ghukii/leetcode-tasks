#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:

    // 1920. Build Array from Permutation
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;

        for(size_t i = 0; i != nums.size(); ++i){
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }

    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        for(size_t i = 0; i != nums.size() * 2; ++i){
            if(i < nums.size()){
                ans.push_back(nums[i]);
            }
            else{
                ans.push_back(nums[i - nums.size()]);
            }
        }

        return ans;
    }

    // 1512. Number of Good Pairs

    long double fact(int N){
        if(N < 0) 
            return 0;
        if (N == 0) 
            return 1;
        else
            return N * fact(N - 1);
    }

    int numIdenticalPairs(vector<int>& nums) {
        int arr[101], count = 0;

        for(int i = 0; i < 101; i++){
            arr[i] = 0;
        }

        for(size_t i = 0; i != nums.size(); ++i){
            arr[nums[i]]++;
        }

        for(int i = 0; i < 101; i++){
            if(arr[i] > 1){
                count += fact(arr[i]) / (fact(arr[i] - 2) * 2);
            }
        }

        return count;
    }

    // 2433. Find The Original Array of Prefix Xor

    vector<int> findArray(vector<int>& pref) {
        vector <int> arr;

        arr.push_back(pref[0]);

        for(size_t i = 1; i != pref.size(); ++i){
            arr.push_back(pref[i - 1] ^ pref[i]);
        }

        return arr;
    }

    // 2942. Find Words Containing Character

    vector<int> findWordsContaining(vector<string>& words, char x) {
        size_t n;
        vector<int> ans;
        for(size_t i = 0; i != words.size(); ++i){
            n = words[i].find(x);
            if(n != string::npos){
                ans.push_back((int) i);
            }
        }

        return ans;
    }

    // 1108. Defanging an IP Address

    string defangIPaddr(string address) {
        string ans;

        for(size_t i = 0; i != address.size(); ++i){
            if(address[i] == '.'){
                ans.push_back('[');
                ans.push_back(address[i]);
                ans.push_back(']');
            }
            else{
                ans.push_back(address[i]);
            }
        }

        return ans;
    }

    // 2469. Convert the Temperature

    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.80 + 32.00}; 
    }

    // 2011. Final Value of Variable After Performing Operations

    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;

        for(size_t i = 0; i != operations.size(); ++i){
            if(operations[i].find('+') != string::npos) X++;
            else X--;
        }

        return X;
    }

    // 2894. Divisible and Non-divisible Sums Difference

    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;

        for(int i = 0; i <= n; i++){
            if (i % m != 0) num1 += i;
            else num2 += i;
        }

        return num1 - num2;
    }

    // 9. Palindrome Number

    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x >= 0 && x <= 9) return true;

        vector <int> a;

        while(x != 0){
            a.push_back(x % 10);
            x /= 10;
        }

        for(size_t i = 0, j = a.size() - 1; i != a.size(); ++i, --j){
            if(a[i] != a[j]) return false;
        }

        return true;
    }

    // 48. Rotate Image

    void rotate(vector<vector<int>>& matrix) {

        size_t n = matrix.size();

        for(size_t i = 0; i != n; ++i){
            vector<int> tmp;
            for(size_t j = n - 1; j != 0; --j){
                tmp.push_back(matrix[j][i]);
            }
            tmp.push_back(matrix[0][i]);

            matrix.push_back(tmp);
        }

        matrix.erase(matrix.begin(), matrix.end() - n);

        for(size_t i = 0; i != matrix.size(); ++i){
            for(size_t j = 0; j != matrix[i].size(); ++j){
                cout << matrix[i][j] << " ";
            }
            cout<<endl;
        }
    }

    // 28. Find the Index of the First Occurrence in a String

    int strStr(string haystack, string needle) {
        if(haystack.find(needle) != string::npos){
            return haystack.find(needle);
        }
        else{
            return -1;
        }
    }

    // 35. Search Insert Position

    int searchInsert(vector<int>& nums, int target) {

        for(size_t i = 0; i != nums.size(); ++i){
            if(nums[i] == target) return (int) i;
            else if(nums[i] > target) return (int) i;
        }

        return (int) nums.size();
    }

    // 66. Plus One

    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; --i){
            if(digits[i] + 1 == 10){
                digits[i] = 0;
            }
            else{
                digits[i]++;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }

    // 1790. Check if One String Swap Can Make Strings Equal

    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        int differences = 0;
        string dl; // difference_letters
        for(size_t i = 0; i != s1.size(); ++i){
            if(s1[i] != s2[i]){
                differences++;
                dl.push_back(s1[i]);
                dl.push_back(s2[i]);
            }
            if(differences > 2) return false;
        }

        if(dl[0] == dl[3] && dl[1] == dl[2]) return true;
        else return false;
    }

    // 2460. Apply Operations to an Array

    vector<int> applyOperations(vector<int>& nums) {
        for(size_t i = 0; i != nums.size() - 1; ++i){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        size_t left = 0;

        for(size_t right = 0; right != nums.size(); ++right){
            if(nums[right] != 0){
                swap(nums[left], nums[right]);
                left++;
            }
        }
        return nums;
    }

    // 13. Roman to Integer

    int romanToInt(string s) {
        int summ = 0;
        map<char, int> numbers = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
        
        for(size_t i = 0; i != s.size(); ++i){
            
        }

        return summ;
    }
    



};

// 1476. Subrectangle Queries

class SubrectangleQueries {
private:
    vector<vector<int>> rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++){
            for(int j = col1; j <= col2; j++){
                rect[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rect[row][col];
    }
};

int main(){
    Solution S;

    vector<int> nums = {847,847,0,0,0,399,416,416,879,879,206,206,206,272};

    vector<int> a = S.applyOperations(nums);

    for(size_t right = 0; right != a.size(); ++right){
        cout << a[right] << " ";
    }
}