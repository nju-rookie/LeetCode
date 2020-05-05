/*

UNIX路径简化

以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

 

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"


*/



//关键在于拆分字符串path，以'/'拆分字符串，关键信息为目录a和'..'
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        path.push_back('/');
        string answer;

        //apart字符串，用来分割path中有用的部分
        string apart;

        for(auto c : path){
            if(c == '/' && apart.size()!=0){

            	//如果分割出有效目录，进入双端队列
                if(apart != ".." && apart != ".")         
                    q.push_back(apart);    

                //如果分割出返回上级目录，将上级目录删除
                if(apart == ".." && q.size() != 0)
                    q.pop_back();

                //将用于分割的字符串apart重置
                apart.resize(0);
            }    
            if(c != '/')
                apart.push_back(c);
        }

        //双端队列为空，说明路径即为当前目录
        if(q.size() == 0){
            answer.push_back('/');
        }else{
            while(q.size()!=0){
                answer.push_back('/');
                answer.append(q.front());
                q.pop_front();
            }
        }
        return answer;
    }
};