//第二次数据结构作业
#include <iostream>


using namespace std;




/**
* （1）分别就栈的顺序存储结构和链式存储结构实现栈的各种基本操作。
* 
*/

//顺序栈
template<typename T>
class SeqStack
{
public:
	SeqStack(int MaxSize);
	~SeqStack();
	
	void push(const T& x);
	T getTop();
	T pop();
	bool isFull();
	bool isEmpty();
	int getSize();
	int getMaxSize();
	friend ostream& operator<<(ostream& os, const SeqStack<T>& S);

private:
	T* _elements;
	int _top;
	int _maxSize;
	void overflowProcess();

};

template<typename T> SeqStack<T>::SeqStack(int MaxSize)
{
	_maxSize = MaxSize;
	_elements = new T[_maxSize];
	if (_elements == NULL)
	{
		cerr << "内存分配错误！" << endl;
		exit(1);
	}
	_top = 0;
}

template<typename T> SeqStack<T>::~SeqStack()
{
	delete[] _elements;
}

template<typename T> int SeqStack<T>::getSize()
{
	return _top;
}

template<typename T> int SeqStack<T>::getMaxSize()
{
	return _maxSize;
}


template<typename T> bool SeqStack<T>::isEmpty()
{
	if (_top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T> bool SeqStack<T>::isFull()
{
	if (_top == _maxSize)
	{
		return true;

	}
	else
	{
		return false;
	}
}

template<typename T> T SeqStack<T>::getTop()
{
	if(isEmpty())
	{
		cerr << "栈为空" << endl;
		return NULL;
	}
	else
	{
		return _elements[_top - 1];
	}
}

template<typename T> void SeqStack<T>::push(const T& x)
{
	if (isFull())
	{
		overflowProcess();
	}
	_elements[_top++] = x;
}

template<typename T> T SeqStack<T>::pop()
{
	if (isEmpty())
	{
		cerr << "栈为空" << endl;
		return NULL;
	}
	else
	{
		T temp = _elements[_top - 1];
		_elements[_top--] = NULL;
		return temp;
	}
}

template<typename T> void SeqStack<T>::overflowProcess()
{
	T* newelements = new T[_maxSize * 2];
	if (newelements == NULL)
	{
		cerr << "内存分配错误！" << endl;
		exit(1);
	}
	for (int i = 0; i < _top; i++)
	{
		newelements[i] = _elements[i];
	}
	_maxSize = _maxSize * 2;
	delete[] _elements;
	_elements = newelements;
}


template <typename T> ostream& operator<<(ostream& os, const SeqStack<T>& S)
{
	os << "栈内存为：" << S.getMaxSize() << "/t";
	os << "共有元素：" << S.getSize() << "/t";
	os << "栈顶是：" << S.getTop() << "/t";
	for (int i = 1; i <= S.getSize(); i++)
	{
		os << "第" << i << "个元素为：" << S._elements[i - 1] << "/t";
	}
	return os;
}

//链式栈

#define Posi(T) ListNode<T>*

template <typename T>  struct ListNode
{
	T date;                      //数值
	Posi(T) link;                //后继指针  


	//默认构造器
	ListNode(T item, Posi(T) ptr = NULL)
	{
		date = item;
		link = ptr;
	}
	ListNode(Posi(T) ptr = NULL)
	{
		link = ptr;
	};
};


template<typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();

	void makeEmpty();
	void push(const T& x);
	T getTop();
	T pop();
	bool isEmpty();
	int getSize();
	Posi(T) getTopPointer();
	friend ostream& operator<<(ostream& os, LinkStack<T>& S);

private:
	Posi(T) top;
	int size;

};

template<typename T> Posi(T) LinkStack<T>::getTopPointer()
{
	return top;
}

template<typename T> LinkStack<T>::LinkStack()
{
	top = NULL;
	size = 0;
}

template<typename T> LinkStack<T>::~LinkStack()
{
	makeEmpty();
}

template<typename T> void LinkStack<T>::push(const T& x)
{
	top = new ListNode<T>(x, top);
	if (top == NULL)
	{
		cerr << "内存分配错误！" << endl;
		exit(1);
	}
	size++;
}

template<typename T> bool LinkStack<T>::isEmpty()
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T> int LinkStack<T>::getSize()
{
	return size;
}

template<typename T> T LinkStack<T>::getTop()
{
	if (isEmpty())
	{
		cerr << "栈为空" << endl;
		return NULL;
	}
	else
	{
		return top->date;
	}
}

template<typename T> T LinkStack<T>::pop()
{
	if (isEmpty())
	{
		cerr << "栈为空" << endl;
		return NULL;
	}
	else
	{
		T x = top->date;
		Posi(T) p = top;
		top = top->link;
		delete p;
		return x;
		size--;
	}
}

template<typename T> void LinkStack<T>::makeEmpty()
{
	Posi(T) p;
	while (top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}

template<typename T> ostream& operator<<(ostream& os, LinkStack<T>& L)
{
	os << "共有元素：" << L.getSize() << endl;
	os << "栈顶是：" << L.getTop() << endl;
	for (int i = L.getSize(); i > 0; i++)
	{
		Posi(T) p = L.getTopPointer();
		os << "第" << i << "个元素为：" << p->date << endl;
		p = p->link;
	}
	return os;
}







/**
* （2）实现一个顺序结构的循环队列，实现队列的基本操作。
*
*/

template<typename T>
class Queue
{
public:
	Queue(int);
	~Queue();

	bool isFull();
	bool isEmpty();
	bool inQueue(const T& x);
	T deQueue();
	T getFront();
	int get_rear() { return rear; };
	int get_front() { return front; };
	void makeEmpty();
	int getSize();
	int getMaxSize();
	friend ostream& operator<<(ostream& os, Queue<T>& Q);

private:
	int rear;                 //尾
	int front;				  //头
	T* elements;
	int maxSize;
	int size;

};

template<typename T> Queue<T>::Queue(int sz)
{
	maxSize = sz;
	size = 0;
	rear = 0;
	front = 0;
	elements = new T[maxSize];
	if (elements == NULL)
	{
		cerr << "内存分配错误！" << endl;
		exit(1);
	}
}

template<typename T> Queue<T>::~Queue()
{
	delete[] elements;
}

template<typename T> int Queue<T>::getMaxSize()
{
	return maxSize;
}

template<typename T> int Queue<T>::getSize()
{
	return size;
}

template<typename T> bool Queue<T>::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T> bool Queue<T>::isFull()
{
	if (size == maxSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T> bool Queue<T>::inQueue(const T& x)
{
	if (isFull())
	{
		cerr << "队伍已满" << endl;
		return false;
	}
	else
	{
		elements[rear] = x;
		rear = (rear + 1) % maxSize;          //同余等价
		size++;
		return true;
	}
}

template<typename T> T Queue<T>::deQueue()
{
	if (isEmpty())
	{
		cerr << "队伍为空" << endl;
		return NULL;
	}
	else
	{
		T x;
		x = elements[front];
		front = (front + 1) % maxSize;
		size--;
		return x;
	}
}

template<typename T> T Queue<T>::getFront()
{
	if (isEmpty())
	{
		cerr << "队伍为空" << endl;
		return NULL;
	}
	else
	{
		return elements[front];
	}
}

template<typename T> void Queue<T>::makeEmpty()
{
	rear = 0;
	front = 0;
	size = 0;
}

template<typename T> ostream& operator<<(ostream& os, Queue<T>& Q)
{
	os << "队伍内存为：" << Q.getMaxSize() << "/t";
	os << "共有元素：" << Q.getSize() << "/t";
	os << "队伍头是：" << Q.getFront << "/t";
	for (int i = Q.get_front; i != Q.get_rear; i = (i + 1) % Q.getMaxSize())
	{
		os << "第" << i << "个元素为：" << Q.elements[i] << "/t";
	}
	return os;
}


/*
* 
* a.用1实现的顺序栈将中缀表达式计算转换成后缀表达式。
* b.后缀表达式的计算，要考虑实际运算时，后缀表达式中相邻操作数的界定。
* 
*/

/*
#include <cctype>
#include <sstream>
#include <string>
#include <stack>




int priority(char ch)
{
	if (ch == '*' || ch == '/')
		return 1;
	if (ch == '+' || ch == '-')
		return 0;
	if (ch == '(')
		return -1;
	else
		return -2;//这是作为意外情况发生时进行判定的手段，万一没载入我想要的呢
}

string toPostfixExp(string InfixExp)
{
	stack<double> Number;
	stack<char> Operator;
	string result;
	for (size_t i = 0; i < InfixExp.length(); i++)
	{
		if (InfixExp.at(i) == '+' || InfixExp.at(i) == '-' || InfixExp.at(i) == '*' || InfixExp.at(i) == '/')
		{

			if (!Operator.empty() && Operator.top() != '(' && priority(Operator.top()) >= priority(InfixExp.at(i)))
			{
				result += Operator.top();
				result += " ";
				Operator.pop();
				while (!InfixExp.empty() && Operator.top() != '(' && priority(Operator.top()) >= priority(InfixExp.at(i)))
				{
					result += Operator.top();
					result += " ";
					Operator.pop();
				}
			}
			else
			{
				Operator.push(InfixExp.at(i));
			}
		}
		else if (InfixExp.at(i) == '(')
		{
			Operator.push(InfixExp.at(i));
		}
		else if(InfixExp.at(i) == ')')
		{
			if (Operator.empty())
			{
				cout << "输入错误" << endl;
			}
			else
			{
				while (Operator.top() != '(')
				{
					result += Operator.top();
					result += " ";
					Operator.pop();
				}
				Operator.pop();
			}
		}
		else if (isdigit(InfixExp.at(i)))
		{
			double num = 0;
			size_t n = 1;
			size_t i1 = i + 1;
			while (i1 < InfixExp.size() && (isdigit(InfixExp.at(i1)) || InfixExp.at(i1) == '.'))
			{
				n++;
				++i1;
			}
			istringstream input(InfixExp.substr(i, n));
			input >> num;
			result += InfixExp.substr(i, n);
			i = i1 - 1;
			Number.push(num);
			result += " ";
		}
		else
		{
			cout << "非法输入" << endl;
		}
	}
	while (Operator.empty() == false)
	{
		result += Operator.top();
		result += " ";
		Operator.pop();
	}
	return result;

}


//计算
double calculation(string PostfixExp)
{
	stack<double> Number;
	stack<char> Operator;

	double result = 0;
	for (size_t i = 0; i < PostfixExp.length(); i++)
	{
		if (isdigit(PostfixExp.at(i)))
		{
			double num = 0;
			size_t n = 1;
			size_t i1 = i + 1;
			while (i1 < PostfixExp.size() && (isdigit(PostfixExp.at(i1)) || PostfixExp.at(i1) == '.'))
			{
				n++;
				++i1;
			}
			istringstream input(PostfixExp.substr(i, n));
			input >> num;
			i = i1 - 1;
			Number.push(num);
		}
		else if (PostfixExp.at(i) == '+')
		{
			double num1 = Number.top();
			Number.pop();
			double num2 = Number.top();
			Number.pop();
			Number.push(num1 + num2);
		}
		else if (PostfixExp.at(i) == '-')
		{
			double num1 = Number.top();
			Number.pop();
			double num2 = Number.top();
			Number.pop();
			Number.push(num1 - num2);
		}
		else if (PostfixExp.at(i) == '*')
		{
			double num1 = Number.top();
			Number.pop();
			double num2 = Number.top();
			Number.pop();
			Number.push(num1 * num2);
		}
		else if (PostfixExp.at(i) == '/')
		{
			double num1 = Number.top();
			Number.pop();
			double num2 = Number.top();
			Number.pop();
			Number.push(num1 / num2);
		}
		else
		{
		}

	}
	result = Number.top();
	return result;
}



int main()
{
	double result = 0;
	string InfixExp;
	string PostfixExp;
	cout << "请输入要计算的表达式:" << endl;
	cin >> InfixExp;
	PostfixExp = toPostfixExp(InfixExp);
	result = calculation(PostfixExp);
	cout << "中序表达式为：" << InfixExp << endl;
	cout << "后序表达式为：" << PostfixExp << endl;
	cout << "计算结果为：" << result << endl;
	return 0;
}

*/


/*
*
* 设线性表A中有n个字符，试设计程序判断字符串是否中心对称，例如xyzyx和xyzzyx都是中心对称的字符串。
*
*/

/*
int main()
{
	stack<char> c;

	string str;
	cout << "请输入一个字符串：" << endl;
	cin >> str;
	if (str.size() % 2 == 0)
	{
		for (size_t i = 0; i < str.size(); i++)
		{
			if (c.empty() || str.at(i) != c.top())
			{
				c.push(str.at(i));
			}
			else if (str.at(i) == c.top())
			{
				c.pop();
			}
		}
		if (c.empty())
		{
			cout << str << "是中心对称" << endl;
		}
		else
		{
			cout << str << "不是中心对称" << endl;
		}
	}
	else
	{
		for (size_t i = 0; i < str.size() / 2; i++)
		{
			if (c.empty() || str.at(i) != c.top())
			{
				c.push(str.at(i));
			}
			else if (str.at(i) == c.top())
			{
				c.pop();
			}
		}
		for (size_t i = ((str.size() + 1) / 2) + 1 ; i < str.size(); i++)
		{
			if (c.empty() || str.at(i) != c.top())
			{
				c.push(str.at(i));
			}
			else if (str.at(i) == c.top())
			{
				c.pop();
			}
		}
		if (c.empty())
		{
			cout << str << "是中心对称" << endl;
		}
		else
		{
			cout << str << "不是中心对称" << endl;
		}
	}
	return 0;
}

*/

/*
int main()
{
	int select;
	SeqStack<int> intStack(20);
	//LinkStack<int> intStack;
	cout << "[1] " << "查询栈是否为空" << endl;
	cout << "[2] " << "查询栈是否为满" << endl;
	cout << "[3] " << "查询栈当前长度" << endl;
	cout << "[4] " << "查询栈最大容量" << endl;
	cout << "[5] " << "查询栈目前栈顶" << endl;
	cout << "[6] " << "入栈" << endl;
	cout << "[7] " << "出栈" << endl;
	cout << "[8] " << "退出" << endl;

	while (true)
	{
		cout << "请选择操作：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			if (intStack.isEmpty())
			{
				cout << "栈为空" << endl;
			}
			else
			{
				cout << "栈不空" << endl;
			}
			break;
		case 2:
			if (intStack.isFull())//intStack.isFull()
			{
				cout << "栈为满" << endl;
			}
			else
			{
				cout << "栈不满" << endl;
			}
			break;
		case 3:
			cout << "栈的长度为：" << intStack.getSize() << endl;
			break;
		case 4:
			cout << "栈的最大长度为：" << intStack.getMaxSize() << endl;
			break;
		case 5:
			cout << "栈顶元素为：" << intStack.getTop() << endl;
			break;
		case 6:
			int x;
			cout << "请输入要入栈的元素：";
			cin >> x;
			intStack.push(x);
			break;
		case 7:
			cout << "出栈元素为：" << intStack.pop() << endl;
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}
*/





/*
int main()
{
	int select;
	//SeqStack<int> intStack(20);
	LinkStack<int> intStack;
	cout << "[1] " << "查询栈是否为空" << endl;
	cout << "[2] " << "查询栈当前长度" << endl;
	cout << "[3] " << "查询栈目前栈顶" << endl;
	cout << "[4] " << "入栈" << endl;
	cout << "[5] " << "出栈" << endl;
	cout << "[6] " << "退出" << endl;

	while (true)
	{
		cout << "请选择操作：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			if (intStack.isEmpty())
			{
				cout << "栈为空" << endl;
			}
			else
			{
				cout << "栈不空" << endl;
			}
			break;
		case 2:
			cout << "栈的长度为：" << intStack.getSize() << endl;
			break;
		case 3:
			cout << "栈顶元素为：" << intStack.getTop() << endl;
			break;
		case 4:
			int x;
			cout << "请输入要入栈的元素：";
			cin >> x;
			intStack.push(x);
			break;
		case 5:
			cout << "出栈元素为：" << intStack.pop() << endl;
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}
*/





int main()
{
	int select;
	//SeqStack<int> intStack(20);
	//LinkStack<int> intStack;
	Queue<int> intQueue(20);
	cout << "[1] " << "查询队伍是否为空" << endl;
	cout << "[2] " << "查询队伍是否为满" << endl;
	cout << "[3] " << "查询队伍当前长度" << endl;
	cout << "[4] " << "查询队伍最大容量" << endl;
	cout << "[5] " << "查询队伍目前顶" << endl;
	cout << "[6] " << "入队伍" << endl;
	cout << "[7] " << "出队伍" << endl;
	cout << "[8] " << "退出" << endl;

	while (true)
	{
		cout << "请选择操作：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			if (intQueue.isEmpty())
			{
				cout << "队伍为空" << endl;
			}
			else
			{
				cout << "队伍不空" << endl;
			}
			break;
		case 2:
			if (intQueue.isFull())
			{
				cout << "队伍为满" << endl;
			}
			else
			{
				cout << "队伍不满" << endl;
			}
			break;
		case 3:
			cout << "队伍的长度为：" << intQueue.getSize() << endl;
			break;
		case 4:
			cout << "队伍的最大长度为：" << intQueue.getMaxSize() << endl;
			break;
		case 5:
			cout << "队伍顶元素为：" << intQueue.getFront() << endl;
			break;
		case 6:
			int x;
			cout << "请输入要入队伍的元素：";
			cin >> x;
			intQueue.inQueue(x);
			break;
		case 7:
			cout << "出队伍元素为：" << intQueue.deQueue() << endl;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}




//(5+6*3)*7
//5 6 3 * + 7 *

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
