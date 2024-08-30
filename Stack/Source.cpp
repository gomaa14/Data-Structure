#include <iostream>

using namespace std;

class Node
{
public:
	int Data;
	Node* Next;

	Node(int Value =0 )
	{
		Data = Value;
		Next = NULL;

	}
};


class Stack
{
	Node* Top;

public:

	Stack()
	{
		Top = NULL;
	}
	
	bool Is_Empty(void)
	{
		if (Top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(int item)
	{
		Node* newnode = new Node(item);
		if (Is_Empty())
		{
			newnode->Next = NULL;
			Top = newnode;
		}
		else
		{
			newnode->Next = Top;
			Top = newnode;
		}
	}

	void Pop(void)
	{
		//int Ret_Val = 0;
		if (Is_Empty())
		{
			cout << "Stack is emty !!" << endl;
		}
		else
		{
			Node* delptr = Top;
			Top = Top->Next;
			//Ret_Val = delptr->Data;
			delete delptr;
		}
	}

	int count(void)
	{
		Node* Temp = Top;
		int counter = 0;
		while (Temp)
		{
			counter++;
			Temp = Temp->Next;
		}

		return counter;
	}

	bool Is_Found(int Value)
	{
		bool found = false;
		Node* Temp = Top;
		while (Temp)
		{
			if (Temp->Data == Value)
			{
				found = true;
				break;
			}

			Temp = Temp->Next;
		}
		return found;
	}

	int Peek(void)
	{
		return Top->Data;
	}

	bool Is_Full()
	{
		Node* temp = new Node();

		if (temp == NULL)
		{
			cout << "Stack is full " << endl;
			return true;
		}
		else
		{
			return false;
		}
	}

	void Display(void)
	{
		if (Is_Empty())
		{
			cout << "NO element to display " << endl;
			return;
		}

		Node* Temp = Top;

		while (Temp)
		{
			cout << Temp->Data << "\t";
			Temp = Temp->Next;
		}
		cout << endl;
	}


	~Stack()
	{
		delete Top;
	}
};


int main()
{

	Stack s;
	int iteme = 0;
	bool found = 0;

	cout << s.Is_Empty() << endl;

	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.Push(40);
	s.Push(50);

	s.Display();

	cout << "No of element is :: " << s.count() << endl;

	s.Pop();
	s.Pop();

	s.Display();

	cout << "No of element is :: " << s.count() << endl;

	cout << "Please enter elment to search it :: ";
	cin >> iteme;

	found = s.Is_Found(iteme);

	if (found == 1)
	{
		cout << iteme << " is found " << endl;
	}

	else
	{
		cout << iteme << " is not found " << endl;
	}

	return 0;

}


