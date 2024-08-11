#include <iostream>

using namespace std;

class items
{
public:
	int* ptr;
	int size;
	int length;

public:

	items(int array_size)
	{
		ptr = new int[array_size];
		size = array_size;
		length = 0;
		
	}

	void fill()
	{
		int nom_of_item;
		int i = 0;

		cout << "please enter nom of elements  of array you want to insert it :: ";
		cin >> nom_of_item;

		if (nom_of_item > size)
		{
			cout << "Error, can.t creat the array !!\n";
		}

		else
		{

			for (i = 0;i < nom_of_item;i++)
			{
				cout << "enter " << i + 1 << " elment :: ";
				cin >> ptr[i];
				length++;

			}


		}


	}

	void Display()
	{
		int index = 0;
		if (length == 0)
		{
			cout << "No element to Display it !! \n";
		}
		else
		{
			for (index = 0;index < length;index++)
			{

				cout << "A[" << index << "] :: " << ptr[index] << endl;
			}

		}

	}

	int search(int Value)
	{

		int index = -1;
		int i = 0;

		for (i = 0;i < length;i++)
		{
			if (Value == ptr[i])
			{
				index = i;
				break;
			}
		}

		return index;

	}

	void Append(int Value)
	{
		if (length == size)
		{
			cout << "Array is full " << endl;

		}

		else
		{

			ptr[length] = Value;
			length++;
		
		}
	}

	void insert(int Value, int index) // 0 1 33 4 5 .. .. .. 
	{
		if ((index < 0) || (index >= size)) 
		{
			cout << "Error out of range !! \n";

		}

		else
		{
			for (int i = length; i > index;i--)
			{
				ptr[i] = ptr[i - 1];
			}

			ptr[index] = Value;

			length++;

		}
	}


	void Delete(int index)
	{

		if (index < 0 || index >= size)
		{
			cout << "index out of range " << endl;

		}

		else // 1 2 33 4 5 .. .. .. 
		{
			if (index < length)
			{
				int i = 0;

				for (i = index;i < length - 1;i++)
				{

					ptr[i] = ptr[i + 1];
				}

				length--;

			}
			

		}

	}

	void Enlarge(int new_size)
	{
		if (new_size < size)
		{
			cout << "New size must be large than old size" << endl;

		}

		else
		{
			int* old = ptr;
			
			size = new_size;

			ptr = new int[size];

			for (int i = 0;i < length;i++)
			{
				ptr[i] = old[i];

			}

			delete[]old;

		}
	}

	void merge(items Other)
	{
		int index = 0;

		int* old = ptr;

		size = size + Other.get_size();

		ptr = new int[size];

		for (index = 0;index < length;index++)
		{
			ptr[index] = old[index];
		}

		delete[]old;

		for (int j = 0;j < Other.get_length();j++)
		{
			ptr[index + j] = Other.ptr[j];
			length++;

		}
	}


	int get_length()
	{
		return length;

	}

	int get_size()
	{
		return size;
	}


	~items()
	{
		delete[] ptr;

	}
};







int main()
{
	int element = 0;
	int index = 0;

	items A(12);
	cout << "Length :: " << A.get_length() << endl;
	cout << "Size   :: " << A.get_size() << endl;

	A.Display();

	A.fill();

	cout << "Length :: " << A.get_length() << endl;
	cout << "Size   :: " << A.get_size() << endl;

	A.Display();

	cout << "enter element you want to search it :: ";
	cin >> element;

	index = A.search(element);

	if (index < 0)
	{
		cout << "Element not found " << endl;

	}

	else
	{
		cout << "element founded in index :: " << index << endl;

	}


	cout << "Please enter elementyou  want to appent it :: ";
	cin >> element;

	A.Append(element);
	A.Display();

	cout << "Length :: " << A.get_length() << endl;
	cout << "Size   :: " << A.get_size() << endl;

	cout << "please enter elment you want to insert it and index :: ";
	cin >> element >> index;

	A.insert(element, index);

	A.Display();

	cout << "Length :: " << A.get_length() << endl;
	cout << "Size   :: " << A.get_size() << endl;


	cout << "\n===============================================\n";

	cout << "Please nenter index you want to delete it :: ";
	cin >> index;

	A.Delete(index);

	A.Display();

	cout << "Length :: " << A.get_length() << endl;
	cout << "Size   :: " << A.get_size() << endl;




	return 0;

}


