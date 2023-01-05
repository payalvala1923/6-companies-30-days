#include<stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
		for(int i = 0; i < tokens.size(); i ++){
			if( (tokens[i] == "+") ||(tokens[i] == "-") ||(tokens[i] == "*") |(tokens[i] == "/")){
					long long x = st.top();
					st.pop();
					long long y = st.top();
					st.pop();
					long long z;
					if(tokens[i] == "+") z = y + x;
					if(tokens[i] == "-") z = y - x;
					if(tokens[i] == "*") z = y * x;
					if(tokens[i] == "/") z = y / x;
					st.push(z);
				}
			else{
				long long t = stoi(tokens[i]);
				st.push(t);
			}
		}
		long long ans= st.top();
		return ans;
    }
};
