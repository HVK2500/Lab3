#include "DataGenerator.h"
using namespace std;

template <class T>
void Swap(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// This function generates a random array
void GenerateRandomData(vector<int>& a, int n)
{
	srand((int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// This function generates a sorted array (ascending order)
void GenerateSortedData(vector<int>& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// This function generates a reverse-sorted array (descending order)
void GenerateReverseData(vector<int>& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// This function generates a nearly-sorted array
void GenerateNearlySortedData(vector<int>& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}

	srand((int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		Swap(a[r1], a[r2]);
	}
}
void GenerateData(vector<int>& a, int n, int dataType)
{
	switch (dataType)
	{
	case 0:
		GenerateRandomData(a, n);
		break;
	case 1:
		GenerateNearlySortedData(a, n);
		break;
	case 2:
		GenerateSortedData(a, n);
		break;
	case 3:
		GenerateReverseData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}
void PrintList(vector<int> arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int choose_data(string data) {
	if (data == "-rand") return 0;
	else if (data == "-nsorted") return 1;
	else if (data == "-sorted") return 2;
	else if (data == "-rev") return 3;
	else return 4;
}
void NameData(int dataType) {
	switch (dataType) {
	case 0: cout << "Randomize" << endl; break;
	case 1: cout << "Nearly Sorted" << endl; break;
	case 2: cout << "Sorted" << endl; break;
	case 3: cout << "Reversed" << endl; break;
	default: cout << "Unknow" << endl;
	}
}