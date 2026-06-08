class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++){
            int f = 0;
            for(int j = 0; j < strs.size(); j++){
                if(strs[j].size()<=i || strs[j][i] != strs[0][i]){
                    f = 1;
                }
            }
            if(f == 1){
                return ans;
            }
            else{
                ans += strs[0][i];
            }
        }
        return ans;
    }
};