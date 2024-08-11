#include <iostream>

using namespace std;

class Node
{
public:
	int Data;
	Node* Next;

	Node(int Value =0)
	{
		Data = Value;
		Next = NULL;

	}

};

class Linked_List
{
private :
	Node* Head;

public:

	Linked_List()
	{
		Head = NULL;
	}

	bool Is_Empty()
	{
		if (Head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Insert_First(int new_item)
	{
		Node* newnode = new Node(new_item);


		if (Is_Empty())
		{
			Head = newnode;
		}

		else
		{
			newnode->Next = Head;

			Head = newnode;

		}

	}

	void Append(int new_value)
	{
		if (Is_Empty())
		{
			Insert_First(new_value);
		
		}
		else
		{
			Node* newnode = new Node(new_value);

			Node* Temp = Head;

			while (Temp->Next)
			{
				Temp = Temp->Next;
			}

			newnode->Next = NULL;

			Temp->Next = newnode;

		}
	}

	void Insert_Befor(int befor_value, int new_value)
	{
		if (Is_Found(befor_value) == 0)
		{
			cout << "The elment you enter it not found !! " << endl;

		}
		else
		{
			if (Head->Data == befor_value)
			{
				Insert_First(new_value);
			}

			else
			{
				Node* newnode = new Node(new_value);
				Node* Temp = Head;

				while ( (Temp->Next->Data != befor_value) && (Temp != NULL) )
				{
					Temp = Temp->Next;

				}

				newnode->Next = Temp->Next;
				Temp->Next = newnode;

			}
		}
	}

	void Delet_First(void)
	{

		Node* delptr = Head;
		Head = Head->Next;

		delete delptr;

	}

	void Delete(int befor_item)
	{

		if (Is_Found(befor_item) == 0)
		{
			cout << "The element you enter it not found " << endl;
		}

		else

		{

			if (befor_item == Head->Data)
			{
				Delet_First();
			}

			else
			{
				Node* prevptr = Head;

				while ((prevptr->Next->Data != befor_item) && (prevptr != NULL))
				{
					prevptr = prevptr->Next;

				}

				Node* delptr = prevptr->Next;

				prevptr->Next = delptr->Next;
				delete delptr;

			}
		}
	}
		
	bool Is_Found(int Value)
	{
			bool Check = false;

			Node* Temp = Head;

			while (Temp)
			{
				if (Temp->Data == Value)
				{
					Check = true;
					break;
				}
				
				Temp = Temp->Next;

			}

			return Check;

	}
	
	int Count(void)
		{
			int counter = 0;
			Node* Temp = Head;

			while (Temp)
			{
				counter++;
				Temp = Temp->Next;
			}

			return counter;

		}
	
	void Display(void)
		{
			Node* Temp = Head;

			if (Is_Empty())
			{
				cout << "NO element to print it " << endl;
				return;

			}

			while (Temp)
			{

				cout << Temp->Data << "\t";
				Temp = Temp->Next;

			}

			cout << endl;

		}


	~Linked_List()
		{
			delete Head;
		}
	
};





int main()
{
	Linked_List l;

	l.Display();
	cout << "NO of element :: " << l.Count() << endl;

	l.Insert_First(10);
	l.Insert_First(20);
	l.Insert_First(30);

	l.Display();
	cout << "NO of element :: " << l.Count() << endl;


	l.Append(100);
	l.Display();


	l.Insert_Befor(30, 5);
	l.Insert_Befor(10, 90);
	l.Display();
	cout << "NO of element :: " << l.Count() << endl;


	bool X = l.Is_Found(5);

	cout << X << endl;


	l.Delet_First();

	l.Delete(123);

	l.Delete(30);

	l.Delete(90);

	l.Display();


	return 0;

}