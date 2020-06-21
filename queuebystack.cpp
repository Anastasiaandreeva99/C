#include<iostream>
#include<stack>
using namespace std;
class StackBasedQueue {
private:
    std::stack<int> pushStack;
    std::stack<int> popStack;

public:
  void  push(int x)
    {
        pushStack.push(x);
    }
    int peek()
    {
        if(popStack.empty())
        {
     while(!pushStack.empty())
     {
        popStack.push(pushStack.top());
        pushStack.pop();
     }
        }
        return popStack.top();
    }
     int pop()
   {
       int y=this->peek();
       popStack.pop();
       return y;
   }
       bool empty() {
        return pushStack.empty() && popStack.empty();
    }
};
int main()
{
    StackBasedQueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  s.push(5);
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
    return 0;
}
