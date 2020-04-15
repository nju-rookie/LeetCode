/*

最长回文串


给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

*/


class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash(58);
        //odd 代表出现次数为奇数次的个数
        int ans = 0, odd = 0;
        for(auto i : s){
            hash[i-'A']++;
        }
        for(int i = 0;i < 58;i++){
            ans += hash[i];
            if(hash[i] % 2 == 1)
                odd++;             
        }
        //出现次数为偶数，都可以纳入回文串；有odd个字母出现次数为奇数，最多只有1个能全部纳入回文串
        odd = odd == 0 ? 0 : odd - 1;
        return ans - odd;
    }
};