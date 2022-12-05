#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    stack<string> st, st2;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[0] == 'p')
        {
            cout << "/";
            while (!st.empty())
            {
                st2.push(st.top());
                st.pop();
            }
            while (!st2.empty())
            {
                st.push(st2.top());
                cout << st2.top();
                st2.pop();
            }
            cout << endl;
        }
        else
        {
            string cur = "";
            cin >> s;
            s += '/';
            int l = s.length();
            for (int i = 0; i < l; i++)
            {
                cur += s[i];
                if (s[i] == '/')
                {
                    if (cur == "/")
                    {
                        while (!st.empty())
                            st.pop();
                    }
                    else if (cur == "../")
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(cur);
                    }
                    cur = "";
                }
            }
        }
    }
    return 0;
}