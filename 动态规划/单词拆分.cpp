/*


给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。


示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

示例 2：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> map;
        for(auto s : wordDict)  map.insert(s);
        int n = s.size();
        bool *dp = new bool[n+1];
        dp[0] = true;
        for(int i = 1;i < n+1;i++){
            dp[i] =  false;
            for(int j = 0;j < i;j++){
                if(dp[j] == true && map.count(s.substr(j,i-j))){
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};