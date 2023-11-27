#include <iostream>
#include <vector>
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

};

int main(){
    Solution S;
    
    vector<int> pref = {5,2,0,3,1};
    vector<double> ans = S.convertTemperature(36.50);

    for(size_t i; i != ans.size(); ++i){
        cout << ans[i] << " ";
    }
}