#include <iostream>

using namespace std;

class Node
{
public:
	int Data;
	Node* Next;

	Node(int Value = 0)
	{
		Data = Value;
		Next = NULL;
	}

};

class Queue
{
public:
	Node* Front;
	Node* Rear;

	Queue()
	{
		Front = NULL;
		Rear = NULL;
	}


	bool Is_Empty()
	{
		if ((Front == NULL) && (Rear == NULL))
		{
			return true;
		}

		else
		{
			return false;
		}

	}

	void Enqueue(int Value)
	{
		Node* newnode = new Node(Value);

		if (Is_Empty())
		{
			Front = newnode;
			Rear = newnode;

		}

		else
		{
			Rear->Next = newnode;
			Rear = newnode;
		}

	}

	void Dequeue(void)
	{
		if (Is_Empty())
		{
			cout << "No elemente to dequeue !!" << endl;
		}

		else if (Front == Rear)
		{
			delete Front;
			Front = NULL;
			Rear = NULL;

		}

		else
		{
			Node* delptr = Front;

			Front = Front->Next;

			delete delptr;

		}

	}

	void Clear(void)
	{
		while (!Is_Empty())
		{
			Dequeue();

		}

	}

	int Get_Rear(void)
	{
		return Rear->Data;
	}

	int Get_Front(void)
	{
		return Front->Data;
	}

	bool Search(int iteme)
	{
		Node* Temp = Front;
		bool check = 0;

		while (Temp)
		{
			if (Temp->Data == iteme)
			{
				check = 1;
				break;
			}
		}

		return check;

	}

	int count(void)
	{
		int counter = 0;
		Node* Temp = Front;

		while (Temp)
		{
			counter++;
			Temp = Temp->Next;
		}

		return counter;
	}

	void Display()
	{
		if (Is_Empty())
		{
			cout << "No elment to print it !! " << endl;
		}

		else
		{
			Node* Temp = Front;

			while (Temp)
			{
				cout << Temp->Data << "\t";
				Temp = Temp->Next;

			}
			cout << endl;
		}
		
	}

	~Queue()
	{
		delete Front;
		delete Rear;
	}
};







int main()
{

	Queue q;

	cout << q.Is_Empty() << endl;

	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);

	q.Display();

	q.Dequeue();
	q.Dequeue();

	q.Display();

	cout << "No of element :: " << q.count() << endl;

	q.Clear();

	q.Display();


	return 0;

}

