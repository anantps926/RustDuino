#include <bits/stdc++.h>
using namespace std;

int flag = 0;

int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}

int applyOp(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int evaluate(string tokens){
	int i;
	
	
	stack <int> values;
	stack <char> ops;
	for(i = 0; i < tokens.length(); i++){
		
		
		if(tokens[i] == ' ')
			continue;
		else if(isdigit(tokens[i])){
			int val = 0;
			while(i < tokens.length() &&
						isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			
			values.push(val);
			i--;
			if(val > 1000 ){
				flag = 1;
			}
		}
		else
		{
			while(!ops.empty() && precedence(ops.top())
								>= precedence(tokens[i])){
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			
			ops.push(tokens[i]);
		}

	}
	while(!ops.empty()){
		int val2 = values.top();
		values.pop();
				
		int val1 = values.top();
		values.pop();
				
		char op = ops.top();
		ops.pop();
				
		values.push(applyOp(val1, val2, op));
	}
	
	return values.top();

}



int main(){
	string expr;
	int res ,i = 0;
	char ch;
	cout << "Enter an expression: " ;
	getline(cin,expr);
	res = evaluate(expr);
	if((res == -1) || flag == 1 ){
		cout << "Incorrect input: numbers cannot exceed 1000. Program terminated, please try again." << endl;
	}
	else{
		cout << "Result: " << res << endl;
	}
	
	return 0;
}