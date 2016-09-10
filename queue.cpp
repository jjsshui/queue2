#include<iostream>
#include<stack>
using namespace std;


class MyQueue
{
public:
	bool empty()const
	{
		return head.empty()&&tail.empty();//两个栈head和tail
	}

	void push(int t)//队列的进队函数
	{
		head.push(t);//head栈  压栈
	}

	void pop()//队列的出队函数,栈tail开始是没有元素的
	{
		if(this->empty())//首先判断队列是否为空，队列为空就是head栈和tail栈同时为空，empty是队列的成员函数
		{
			cout<<"队列为空"<<endl;
		}
		while(!head.empty())//head栈不为空
		{
			tail.push(head.top());//head的栈顶元素压入tail栈中
			head.pop();//弹出栈顶元素
		}
		tail.pop();

		while(!tail.empty())
		{
			head.push(tail.top());
			tail.pop();//清空tail栈
		}
	}

	int back()
	{
		if(this->empty())
		{
			cout<<"队列为空"<<endl;
		}
		return head.top();
	}

	int front()
	{
		if(this->empty())
		{
			cout<<"队列为空"<<endl;
		}
		while(!head.empty())
		{
			tail.push(head.top());
			head.pop();
		}

		int tmp = tail.top();

		while(!tail.empty())
		{
			head.push(tail.top());
			tail.pop();
		}
		return tmp;
	}


private:
	stack<int> head;
	stack<int> tail;
};

int main()
{
	MyQueue q;
	for(int i=1;i<5;i++)
	{
		q.push(i);
	}
	cout<<q.front()<<endl;//1
	q.pop();
	cout<<q.front()<<endl;//2
	q.pop();
	cout<<q.front()<<endl;//3
	q.push(19);
	cout<<q.back()<<endl;
}
