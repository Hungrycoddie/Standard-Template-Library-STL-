//The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and 
//functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. 
//It is a generalized library and so, its components are parameterized. A working knowledge of template classes is a 
//prerequisite for working with STL.

//STL has 4 components.......

//1.Algorithms & numeric 

//(a)Sorting - array , quick sort code 
// C++ program to sort an array
#include <algorithm>
#include <iostream>

using namespace std;

void show(int a[], int array_size)
{
	for (int i = 0; i < array_size; ++i)
		cout << a[i] << " ";
}

// Driver code
int main()
{
	int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	// size of the array
	int asize = sizeof(a) / sizeof(a[0]);
	cout << "The array before sorting is : \n";

	// print the array
	show(a, asize);

	// sort the array
	sort(a, a + asize);

	cout << "\n\nThe array after sorting is :\n";

	// print the array after sorting
	show(a, asize);

	return 0;
}

//quick sort code 
//quick sort code in C++

#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

int main()
{

	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
	int n = 10;

	quickSort(arr, 0, n - 1);
	cout<<"array after using quick sort: "<<endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

//C++ program of heap sort

#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout <<endl;
}

// Driver program
int main()
{
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int n = 10;

	heapSort(arr, n);

	cout << "array after using heap sort:"<<endl;
	printArray(arr, n);
}

//C++ program of insertion sort

#include <bits/stdc++.h>
using namespace std;

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key, to one
		// position ahead of their
		// current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int N =10;

	insertionSort(arr, N);
	cout<<"array after using insertion sort:"<<endl;
	printArray(arr, N);

	return 0;
}



//(b)Searching 

// CPP program to implement
// Binary Search in
// Standard Template Library (STL)
#include <algorithm>
#include <iostream>

using namespace std;

void show(int a[], int arraysize)
{
	for (int i = 0; i < arraysize; ++i)
		cout << a[i] << ",";
}

int main()
{
	int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	int asize = sizeof(a) / sizeof(a[0]);
	cout << "\nThe array is : \n";
	show(a, asize);

	cout << "\n\nLet's say we want to search for ";
	cout << "\n2 in the array So, we first sort the array";
	sort(a, a + asize);
	cout << "\n\nThe array after sorting is : \n";
	show(a, asize);
	cout << "\n\nNow, we do the binary search";
	if (binary_search(a, a + 10, 2))
		cout << "\nElement found in the array";
	else
		cout << "\nElement not found in the array";

	cout << "\n\nNow, say we want to search for 10";
	if (binary_search(a, a + 10, 10))
		cout << "\nElement found in the array";
	else
		cout << "\nElement not found in the array";

	return 0;
}

//(c)Important STL Algorithms


//Useful Array algorithms
//Partition Operations


//Containers....

//Functions....

//Iterators....


