/*

给定一个字符串s，请你找出其中不含有重复字符的 最长子串 的长度。

样例：abccefa
输出：4

*/


//解法一：滑动窗口法
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s[0] == '\0')
            return 0;

        //用hash来判断是否有重复字符
        vector<bool> hash(256);
        hash.assign(256,false);
        int n = s.size();

        //窗口的大小，区间左侧和右侧
        int size = 0;
        int left = 0;
        int right = 0;

        //遍历字符串
        while(right < n){

            int temp = s[right] - ' ';

            //字符未在窗口中，右边界右移
            if(hash[temp] == false){
                    hash[temp] = true;
                    right++;
            }else{

                //字符已在窗口中，不断左移左边界，直到字符不在窗口中
                while(hash[temp] == true){
                    hash[(s[left]-' ')] = false;
                    left++;         
                }
            }

            //维护窗口大小
            size = size > (right-left) ? size : (right - left);
        }
        return size;
    }
};




//解法二：动态规划法
#include <vector>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s[0] == '\0')
            return 0;
        int n = s.size();
        vector<int> position(256);
        vector<int> dp(n);
        position.assign(256,-1);
        dp.assign(n,1);
        int max = 1;
        position[(s[0]-' ')] = 0;
        for(int i = 1;i < n; i++){
            int temp = s[i] - ' ';
            if(i - position[temp] > dp[i-1])
                dp[i] = dp[i-1] + 1;    
            else
                dp[i] = i - position[temp];
            position[temp] = i;

            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};