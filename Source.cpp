/*
This solution has been approached by Yousef Wael
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s)
	{
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') //checks for opening parentheses
			{
				st.push(s[i]);
				continue;
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}') //checks for closing parentheses
			{
				if (st.empty()) //if there is a closing parentheses and the stack is empty then parentheses are unbalanced
				{
					return false;
				}
				else
				{
					if (st.top() == '(' && s[i] == ')')
					{
						st.pop();
					}
					else if (st.top() == '[' && s[i] == ']')
					{
						st.pop();
					}
					else if (st.top() == '{' && s[i] == '}')
					{
						st.pop();
					}
					else
					{
						return false;
					}
				}
			}
		}
		if (st.empty()) //to ensure that every opening parentheses has been popped from the stack
		{
			return true;
		}
		else
		{
			return false;
		}
    }
};

int main()
{
	Solution r;
	bool result = r.isValid(""); //Use for test cases
	cout << result;
}