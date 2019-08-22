//思路一、每次push调整栈，保证每次pop时栈顶元素是正确的
//思路二、每次push在栈顶。pop时调整
//思路三、一个栈用于push一个栈用于pop
class Solution
{
public:
    void push(int node) {
        if(!stack2.empty())
        {
            while(!stack2.empty())
            {
                int temp = stack2.top();
                stack2.pop();
                stack1.push(temp);
            }
        }
        stack1.push(node);
    }

    int pop() {
        int res;
        if(!stack1.empty())
        {
            while(!stack1.empty())
            {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            
        }
        res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
