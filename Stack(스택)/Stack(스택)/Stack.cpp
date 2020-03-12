#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
private :
	int index = 0;
	vector<T> data;
public :
	void Push(T d)
	{
		if (index < data.size())
			data[index] = d;
		else
			data.push_back(d);
		index++;
	}

	T Pop()
	{
		if (index == 0)
			return -1;
		index--;
		return data[index];
	}

	T Top()
	{
		if (index == 0)
			return -1;
		return data[index - 1];
	}

	bool Empty()
	{
		return index == 0;
	}

	int Length()
	{
		return index;
	}
};


int main()
{
	Stack<char> st;
	st.Push('a');
	st.Push('b');
	cout << st.Pop() << endl;
	st.Push('c');
	cout << st.Pop() << endl;
	cout << st.Pop() << endl;
}