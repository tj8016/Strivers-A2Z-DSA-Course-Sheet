#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void backtrack(vector<string>& res, string num, int target, int pos, long sum, long multiply, string path){
        if(pos == num.size()){
            if(target == sum) res.push_back(path);
            return;
        }
        for(int i = pos; i < num.size(); i++){
            if(i != pos && num[pos] == '0') break;
            long cur = stol(num.substr(pos, i - pos + 1));
            if(pos == 0){
                backtrack(res, num, target, i + 1, cur, cur, path + to_string(cur));
            }
            else{
                backtrack(res, num, target, i + 1, sum + cur, cur, path + "+" + to_string(cur));
                backtrack(res, num, target, i + 1, sum - cur, -cur, path + "-" + to_string(cur));
                backtrack(res, num, target, i + 1, sum - multiply + multiply * cur, multiply * cur, path + "*" + to_string(cur));    
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string>res;
        backtrack(res, num, target, 0, 0, 0, "");
        return res;
    }
};

int main() {
    string s = "123";
    int target = 6;

    Solution op;
    vector<string> ans = op.addOperators(s, target);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}