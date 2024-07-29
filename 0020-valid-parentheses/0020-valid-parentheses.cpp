class Solution {
public:
    bool isValid(string x) {
    stack<char> st;
    for(char c : x)
    {
        if(c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if(c == ')')
        {
            if(st.empty() || st.top() != '(')
                return false;
            st.pop();
        }
        else if(c == ']')
        {
            if(st.empty() || st.top() != '[')
                return false;
            st.pop();
        }
        else if(c == '}')
        {
            if(st.empty() || st.top() != '{')
                return false;
            st.pop();
        }
    }
    return st.empty();
    }
};