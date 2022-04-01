/**
* 数据结构复习指南实现
* 1.排序算法实现  √
* 2.二分查找实现  √
* 3.树相关内容，树的静态列表，树的构建，树的前中后，层次遍历  √
* 4.完全二叉树内容  √
* 5.字符串匹配   √
* 6.列表，队列，向量STL
* 7.图相关内容
* 8.c++基础语法函数，素数，进制转换，丑数
*/

/*1.排序算法实现*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>


using namespace std;

//冒泡排序
void bubbleSort(vector<int>& a);
//选择排序
void selectionSort(vector<int>& a);
//插入排序
void insertionSort(vector<int>& a);
//希尔排序
void shell_Sort(vector<int>& a);
//快速排序
void qSort(vector<int>& a);
//归并排序
void mSort(vector<int>& a);





void bubbleSort(vector<int>& a)
{
	int len = a.size();
	for (int i = 0; i < len - 1; i++) 
	{
		for (int j = 0; j < len - 1 - i; j++) 
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]); //不满足偏序，交换
			}
		}
	}
}

void selectionSort(vector<int>& a)
{
	int len = a.size();
	int minIndex;
	for (int i = 0; i < len - 1; i++) //需要循环次数
	{
		minIndex = i;                     //最小下标
		for (int j = i + 1; j < len; j++) //访问未排序的元素
		{
			if (a[j] < a[minIndex])
				minIndex = j; //找到最小的
		}
		swap(a[i], a[minIndex]);
	}
}

void insertionSort(vector<int>& a)
{
	int len = a.size();
	int j, temp;
	for (int i = 0; i < len - 1; i++) 
	{
		j = i;
		temp = a[i + 1];
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}



void shell_Sort(vector<int>& a)
{
	int len = a.size();
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = 0; i < gap; i++)
		{
			for (int j = i + gap, temp, preIndex; j < len; j = j + gap) 
			{
				//类似插入排序分组
				temp = a[j];        
				preIndex = j - gap; 
				while (preIndex >= 0 && a[preIndex] > temp)
				{
					a[preIndex + gap] = a[preIndex]; 
					preIndex -= gap;                 
				}
				a[preIndex + gap] = temp; 
			}
		}
	}
}


/********************************************************/
int partition(vector<int>& a, int left, int right)
{
	int pivot = a[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[right]);
	return i + 1;
}

void quickSort(vector<int>& a, int left, int right)
{
	if (left < right)
	{
		int mid = partition(a, left, right);
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}
}

void qSort(vector<int>& a)
{
	quickSort(a, 0, a.size() - 1);
}


/********************************************************************/

void mergeSort(vector<int>& a, vector<int>& T, int left, int right)
{
	if (right - left == 1)
	{
		return;
	}
	int mid = left + right >> 1, tmid = left + right >> 1, tleft = left, i = left;
	mergeSort(a, T, left, mid), mergeSort(a, T, mid, right);
	while (tleft < mid || tmid < right)
	{
		if (tmid >= right || (tleft < mid && a[tleft] <= a[tmid]))
		{
			T[i++] = a[tleft++];
		}
		else
		{
			T[i++] = a[tmid++];
		}
	}
	for (int i = left; i < right; i++)
	{
		a[i] = T[i];
	}
}
void mSort(vector<int>& a)
{
	int len = a.size();
	vector<int> T(len);
	mergeSort(a, T, 0, len);
}


/***************************************************************/

/*
int main()
{
	vector<int> number = { 12,32,65,33,43,77,55,38,67 };
	for (size_t i = 0; i < number.size(); i++)
	{
		cout << number.at(i) << " ";
	}
	cout << endl;
	//bubbleSort(number);
	make_heap(number.begin(), number.end());
	sort_heap(number.begin(), number.end());
	//转置
	//reverse(number.begin(), number.end());
	//selectionSort(number);
	for (size_t i = 0; i < number.size(); i++)
	{
		cout << number.at(i) << " ";
	}
	cout << endl;
	return 0;
}
*/
/******************************************************************************/



/*二分查找实现*/

int binSearch(vector<int> srcArray, int start, int end, int key)
{
	int mid = (end - start) / 2 + start;
	if (srcArray[mid] == key) {
		return mid;
	}
	if (start >= end) {
		return -1;
	}
	else if (key > srcArray[mid]) 
	{
		return binSearch(srcArray, mid + 1, end, key);
	}
	else if (key < srcArray[mid]) 
	{
		return binSearch(srcArray, start, mid - 1, key);
	}
	return -1;
}

int binSearch(vector<int> srcArray, int key) 
{
	int mid;
	int start = 0;
	int end = srcArray.size() - 1;
	while (start <= end) 
	{
		mid = (end - start) / 2 + start;
		if (key < srcArray[mid]) 
		{
			end = mid - 1;
		}
		else if (key > srcArray[mid]) 
		{
			start = mid + 1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;
}

/*
int main()
{
	vector<int> number = { 1,2,3,4,5,6,7,8,9,11,13,14,15,16,17,19 };
	//int flag = binSearch(number,0,number.size(),10);
	//int flag = binSearch(number, 120);
	//bool flag = binary_search(number.begin(), number.end(), 10);
	
	if (flag)
	{
		cout << "sajdhj1";
	}
	else
	{
		cout << "siajkdh2";
	}
	return 0;
}
*/

/******************************************************************************/

/*5.字符串匹配*/
/*
* 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
*/
/*
#include <ctype.h>

int main()
{
	string s = "race a car";
	string str;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalnum(s[i]))
		{
			s[i] = tolower(s[i]);
			str += s[i];
		}
	}
	string str1;
	str1 = str;
	reverse(str.begin(), str.end());
	if (str == str1)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	return 0;

}
*/
/****************************************************************************/




/******************************************************************************/

/*3.二叉树的基本内容*/

struct node
{
	int data;
	node* lchild;
	node* rchild;
	//构造函数
	node(int d) :data(d), lchild(NULL), rchild(NULL)
	{};
};

void insert(node* &T, int num)
{
	if (T == NULL)
	{
		T = new node(num);
	}
	else if (num > T->data)
	{
		insert(T->rchild, num);
	}
	else if (num < T->data)
	{
		insert(T->lchild, num);
	}
	else
	{
		return;
	}
}


void preOrder(node*& T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		cout << T->data << " ";
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(node*& T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		inOrder(T->lchild);
		cout << T->data << " ";
		inOrder(T->rchild);
	}
}

void postOrder(node*& T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		cout << T->data << " ";
	}
}

//层次遍历
void LeverOrder(node*& T)
{
	queue<node*> Q;
	Q.push(T);
	while (!Q.empty())
	{
		node* p = Q.front();
		Q.pop();
		cout << p->data << " ";
		if (p->lchild != NULL)
		{
			Q.push(p->lchild);
		}
		if (p->lchild != NULL)
		{
			Q.push(p->rchild);
		}
	}
}



int numberOfLeafNodes(node*& T)
{
	int num = 0;
	if (T->lchild == NULL && T->rchild == NULL)
	{
		num++;
	}
	if (T->lchild != NULL)
	{
		num += numberOfLeafNodes(T->lchild);
	}
	if (T->lchild != NULL)
	{
		num += numberOfLeafNodes(T->rchild);
	}
	return num;
}

int treeDepth(node*& T)
{
	if (T == NULL)
	{
		return 0;
	}
	int nlchild = treeDepth(T->lchild) + 1;
	int nrchild = treeDepth(T->rchild) + 1;
	return max(nlchild, nrchild);
}

int numberNode(node*& T)
{
	if (T == NULL)
	{
		return 0;
	}
	return 1 + numberNode(T->lchild) + numberNode(T->rchild);
}

/****************************************************************************/




/******************************************************************************/

/*4.完全二叉树*/


/*
* 完全二叉树采用静态表示
* tree[N] 表示数
* root 根节点为1，tree[0]空出, tree[0] = root
* 任意一节点，node i
* 左孩子  -> 2*i
* 右孩子  -> 2*i+1
* 父母节点-> i/2
*/

vector<node> tree;

bool IsCompleteTree(node*& T)
{
	bool flag = false;
	queue<node*> Q;
	if (T == NULL)
	{
		return true;
	}
	Q.push(T);
	while (!Q.empty())
	{
		node* p;
		p = Q.front();
		if (p->lchild == NULL && p->rchild != NULL)
		{
			return false;
		}
		if (flag == true &&(p->lchild != NULL || p->rchild != NULL))
		{
			return false;
		}
		if (p->lchild == NULL || p->rchild == NULL)
		{
			flag = true;
		}
		Q.pop();
		if (T->lchild != NULL)
		{
			Q.push(T->lchild);
		}
		if (T->rchild != NULL)
		{
			Q.push(T->rchild);
		}
	}
	return true;
}


//判断是否我二叉搜索树
bool isBST_InOrder(node*& T)
{
	vector<int> a;
	inorder(T, a);
	//判断a是否为升序
	vector<int> b(a.begin(), a.end());
	sort(a.begin(), a.end());
	for (auto i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

void inorder(node*& T, vector<int>& a)
{
	if (T == NULL)
	{
		return;
	}
	inorder(T->lchild, a);
	a.push_back(T->data);
	inorder(T->rchild, a);
}


//一个深度为k，节点个数为 2^k - 1 的二叉树为满二叉树
bool isFulltree(node*& T)
{
	int highnumber = treeDepth(T);
	int number = numberNode(T);
	if (number == 2*highnumber - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}




