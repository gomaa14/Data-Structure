#include <iostream>

using namespace std;

class Node
{
public:
	int Data;
	Node* Left;
	Node* Right;

	Node(int value = 0)
	{
		Data = value;
		Left = NULL;
		Right = NULL;
	}
};

class BST
{
public:

	Node* Root;

	BST()
	{
		Root = NULL;
	}

	Node* Insert(Node* r, int item)
	{

		if (r == NULL)
		{
			Node* newnode = new Node(item);
			r = newnode;
		}

		else if (item < r->Data)
		{
			r->Left = Insert(r->Left, item);
		}
		else if (item > r->Data)
		{
			r->Right = Insert(r->Right, item);
		}

		return r;

	}

	void Insert(int item)
	{
		Root = Insert(Root, item);
	}

	Node* Search(Node* r, int key)
	{
		if (r == NULL)
			return NULL;

		else if (key == r->Data)
			return r;

		else if (key < r->Data)
			return Search(r->Left, key);

		else
			Search(r->Right, key);

	}

	bool Search(int key)
	{
		Node* Result = Search(Root, key);

		if (Result == NULL)
		{
			return false;
		}

		else
		{
			return true;
		}

	}

	Node* FindMin(Node* r)
	{
		if (r == NULL)
		{
			return NULL;
		}

		else if (r->Left == NULL)
		{
			return r;
		}

		else
		{
			return FindMin(r->Left);
		}

	}

	Node* FindMax(Node* r)
	{
		if (r == NULL)
		{
			return NULL;
		}

		else if (r->Right == NULL)
		{
			return r;

		}

		else
		{
			return FindMax(r->Right);

		}
	}



	void Preorder(Node* r)//Root -> Left -> Right
	{
		if (r == NULL)
		{
			return;
		}

		cout << r->Data << "\t";
		Preorder(r->Left);
		Preorder(r->Right);

	}

	void Inorder(Node* r)//Left -> Root -> Right
	{
		if (r == NULL)
		{
			return;
		}

		Inorder(r->Left);

		cout << r->Data << "\t";

		Inorder(r->Right);

	}

	void Postorder(Node* r)//Left -> Right -> Root
	{
		if (r == NULL)
		{
			return;
		}

		Postorder(r->Left);

		Postorder(r->Right);

		cout << r->Data << "\t";

	}

	~BST()
	{
		delete Root;
	}

};



int main()
{
	// 45, 15, 79, 90, 10, 55, 12, 20, 50
	BST Btree;
	int item = 0;
	bool check = 0;

	Btree.Insert(45);
	Btree.Insert(15);
	Btree.Insert(79);
	Btree.Insert(90);
	Btree.Insert(10);
	Btree.Insert(55);
	Btree.Insert(12);
	Btree.Insert(20);
	Btree.Insert(50);

	cout << "Tree Content " << endl;

	Btree.Preorder(Btree.Root);
	cout << "\n.........................................................\n";

	Btree.Inorder(Btree.Root);
	cout << "\n.........................................................\n";

	Btree.Postorder(Btree.Root);
	cout << "\n.........................................................\n";


	cout << "Please enter item you want to search it :: ";
	cin >> item;

	check = Btree.Search(item);

	if (check == true)
	{
		cout << "Iteem is founded" << endl;
	}
	else
	{
		cout << "Iteem not found" << endl;
	}


	cout << "Find Min " << endl;

	Node* min = Btree.FindMin(Btree.Root);

	if (min == NULL)
	{
		cout << "No min";
	}
	else
	{
		cout << "Min :: " << min->Data << endl;
	}


	cout << "Find Max " << endl;

	Node* Max = Btree.FindMax(Btree.Root);

	if (Max == NULL)
	{
		cout << "No Max";
	}
	else
	{
		cout << "Max :: " << Max->Data << endl;
	}







	return 0;

}


