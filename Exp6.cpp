// CPP program to sort an array by moving one
// space around.
#include <bits/stdc++.h>
using namespace std;

// n is total number of elements.
// index is index of 999 or space.
// k is number of elements yet to be sorted.
void sortRec(int arr[], int index, int k, int n)
{
	// print the sorted array when loop reaches
	// the base case
	if (k == 0) {
		for (int i = 1; i < n; i++)
			cout << arr[i] << " ";
		cout << 999;
		return;
	}

	// else if k>0 and space is at 0th index swap
	// each number with space and store index at
	// second last index
	else if (k > 0 && index == 0) {
		index = n - 2;
		for (int i = 1; i <= index; i++) {
			arr[i - 1] = arr[i];
		}
		arr[index] = 999;
	}

	// if space is neither start of array nor last
	// element of array and element before it greater
	// than/ the element next to space
	if (index - 1 >= 0 && index + 1 < n && 
	arr[index - 1] > arr[index + 1]) {

		// first swap space and element next to space
		// in case of {3, 999, 2} make it {3, 2, 999}
		swap(arr[index], arr[index + 1]);

		// than swap space and greater element
		// convert {3, 2, 999} to {999, 2, 3}
		swap(arr[index - 1], arr[index + 1]);
	}

	else
		swap(arr[index], arr[index - 1]);

	sortRec(arr, index - 1, k - 1, n);
}

// Wrapper over sortRec.
void sort(int arr[], int n)
{
	// Find index of space (or 999)
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 999) {
			index = i;
			break;
		}
	}

	// Invalid input
	if (index == -1)
		return;

	sortRec(arr, index, n, n);
}


// driver program
int main()
{
	int arr[] = { 3, 2, 999, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, n);
	return 0;
}
