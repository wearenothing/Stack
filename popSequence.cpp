#include<iostream>
using namespace std;

#define MAXSIZE 1000
int M, N, K;


typedef struct Node
{
	int data[MAXSIZE];
	int top;
}Node,*Stack;

Stack S;
bool isFull()
{
	if (S->top == M - 1)
		return true;
	else
		return false;
}
bool isEmpty()
{
	if (S->top == -1)
		return true;
	else
		return false;
}
int getTop()
{
	if (S->top == -1)
		return 0;
	else
		return S->top;
}
void clearS()
{
	S->top = -1;
}
bool Push(int n)
{
	if (isFull())
		return false;
	S->data[++(S->top)] = n;
	return true;
}
bool Pop(int& e)
{
	if (isEmpty())
		return false;
	e = S->data[(S->top)--];
	return true;
}
int main()
{
	S = (Stack)malloc(sizeof(Node));
	S->top = -1;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		bool r;
		int a[1000];
		for (int j = 0; j < N; j++)
		{
			cin >> a[j];
		}
		int base = 0;
		for (int j = 0; j < N; j++)
		{
			int t1 = a[j];
			int t2 = getTop();
			if (t1 > t2)
			{
				for (int m = base + 1; m <= t1; m++)
				{
					r = Push(m);
					if (!r)
						break;
					base++;
				}
				if (!r)
					break;
				int e;
				r = Pop(e);
				if (e != a[j])
					r = false;
				if (!r)
					break;
			}
			else if (t1 == t2)
			{
				int e;
				r = Pop(e);
			}
			else
			{
				r = false;
				break;
			}
		}
		//output
		if (r)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		//clear
		clearS();
	}
	return 0;
}