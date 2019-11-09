#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    //遍历字符串 左括号进栈 右括号看栈顶元素是否对应不对应直接pass对应就出栈
    //最后遍历完栈为空才是满足条件 如果中途break或者最后栈不为空都不行
    bool flag = false;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == '}')
        {
            if (st.empty() || st.top() != '{')
            {
                flag = true;
                break;
            }
            else
            {
                st.pop();
            }
        }
        else if (s[i] == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                flag = true;
                break;
            }
            else
            {
                st.pop();
            }
        }
        else if (s[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                flag = true;
                break;
            }
            else
            {
                st.pop();
            }
        }
    }
    //如果中途退出或者栈最后不为空
    if (flag == true||!st.empty())
    {
        cout << "不匹配";
    }
    else
    {
        cout<<"匹配";
    }
}