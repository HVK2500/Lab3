#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <vector>
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
		GenerateSortedData(a, n);
		break;
	case 2:
		GenerateReverseData(a, n);
		break;
	case 3:
		GenerateNearlySortedData(a, n);
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