class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int top;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		top = stack2.top();
		stack2.pop();
		return top;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};