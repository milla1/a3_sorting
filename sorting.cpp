// File:        sorting.cpp
// Author:      Geoffrey Tien
//              Jason Park
// Date:        2015-06-10
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

// the SelectionSort is modified version of the lecture note example
// Sorts array parameter by repeatedly searching for the smallest item
// It is accomplisehd by dividing the array into sorted and //unsorted parts 
// throw exception for invalid size
// PRE: arr[n] is an array of Template class.
// POST: returns the number of barometer comparison performed during execution period
// PARAM:	arr = name of the given array
//			n   = size of arr.
template <class T>
int SelectionSort(T arr[], int n)
{
	int barometerCounter = 0;
	if (n < 0)
	{
		throw std::runtime_error("invalid index of array");
	}
	else
	{
		for (int i = 0; i < n - 1; ++i)
		{
			int smallestElem = i;
			//find the index of the smallest element by comparing first item with each elements in an array
			for (int j = i + 1; (j < n) && (barometerCounter++ != -1); ++j) //BAROMETER OPERATION COUNTER SET HERE
			{
				if (arr[j] < arr[smallestElem])
				{
					smallestElem = j;
				}

			}
			//swaps the current item with the smallest item
			T temp = arr[i];
			arr[i] = arr[smallestElem];
			arr[smallestElem] = temp;
		}
	}
	return barometerCounter;
}

// Sorts array parameter by repeatedly partitioning, dividing an array 
// into sections based on criterias. In this case big or small values. 
// Then repeat the partitioning process until the array is fully sorted
// PRE:	arr[n] is an array of Template class.
// POST: returns the number of barometer operations and quicksorts arr[n]
// PARAM: arr = name of the given array.
//		  n = size of the array.
template <class T>
int Quicksort(T arr[], int n)
{
	int count = 0;
	QuicksortHelper(arr, 0, n - 1, count);
	return count;
}

// helper function which performs the array partitioning and 
// returns the index of the pivot value in the partitioned array 
// PRE: arr[n] is an array of Template class.
// POST: returns the number of barometer comparison performed during execution period
// PARAM: arr = name of the given array
//		  low = The index of the first element to consider in arr[].
//		  high = The index of the last element to consider in arr[].
//        n = size of array arr
//		  counter = used to count and update barometer operations while the function is called.
template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
	int pivot;
	if (low < high)
	{
		pivot = QSPartition(arr, low, high, counter);
		QuicksortHelper(arr, low, pivot - 1, counter);				//sorts smalls
		QuicksortHelper(arr, pivot + 1, high, counter);				//sorts bigs
	}
}

// Implemented using course text psuedo code.
// Function that determines pivots in the given 'big' or 'small' subarrays when QuicksortHelper function is called
// PRE: arr[n] is an array of Template class.
// POST: returns the number of barometer comparison performed during execution period
// PARAM: arr = name of the given array
//		  low = The index of the first element to consider in arr[].
//		  high = The index of the last element to consider in arr[].
//        n = size of array arr
//		  counter = used to count and update barometer operations while the function is called.

template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
	//set markers for pivot, smalls and bigs regions
	int pivotIndex = high;
	int indexFromLeft = low;
	int indexFromRight = high - 1;
	bool done = false;
	while (!done)
	{
		//compares each array value at indexFromLeft to pivotIndex until indexFromLeft is greater than pivotIndex
		while ((counter++ != -1) && (arr[indexFromLeft] < arr[pivotIndex])) //BAROMETER OPERATION COUNTER SET HERE
		{
			indexFromLeft++;
		}
		//compares each array value at indexFromRight to pivotIndex until value at indexFromRight is greater than value pivotIndex
		//or until the indexFromRight reaches indexFromLeft
		while (((arr[indexFromRight] > arr[pivotIndex]) && (indexFromLeft < indexFromRight)))
		{
			indexFromRight--;
		}
		//swap elements from 'smalls' and 'bigs' when the value at indexFromLeft < indexFromRight
		if ((indexFromLeft < indexFromRight))
		{
			T swap = arr[indexFromRight];
			arr[indexFromRight] = arr[indexFromLeft];
			arr[indexFromLeft] = swap;
			indexFromLeft++;
			indexFromRight--;
		}
		else
		{
			done = true;
		}
	}
	//swap values at pivot and indexFromRight[or Left since they are pointing to the same index now].
	T swap = arr[pivotIndex];
	arr[pivotIndex] = arr[indexFromLeft];
	arr[indexFromLeft] = swap;
	pivotIndex = indexFromLeft;
	return pivotIndex;
}

// Sorts the array arr[] by calling on the friend function MergesortHelper
// PRE: arr[n] is an array of Template class.
// POST: returns the number of barometer operations and mergesorts arr[n]
// PARAM:	arr = name of the given array
//			n   = size of arr.
template <class T>
int Mergesort(T arr[], int n)
{
	int count = 0;
	MergesortHelper(arr, 0, n - 1, n, count);
	return count;
}

// Helper function designed to sort the items in an array into ascending order
// by recursively divides array in left and right halves.
// PRE:   arr[low..high] is an array.
// POST:  arr[low..high] is sorted in ascending order.
// PARAM: arr = name of the given array
//		  low = The index of the first element to consider in arr[].
//		  mid = The index of the end of the first segment in arr[];
//				mid + 1 marks the beginning of the second segment.
//		  high = The index of the last element to consider in arr[].
//        n = size of arr
//		  counter = used to count and update barometer operations while the function is called.
template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
	if (low < high) // array has more than 1 element
	{
		int mid = low + (high - low) / 2;

		//sort the left half
		MergesortHelper(arr, low, mid, n, counter);

		//sort the right half
		MergesortHelper(arr, mid + 1, high, n, counter);

		//Merge the sorted halves
		Merge(arr, low, mid, high, n, counter);
	}
}

// Merge function merges two sorted array segments leftArray and rightArray back into array arr[]
// PRE:	
// POST:  two subarrays are merged into a single array
// PARAM: arr = name of the array
//		  low  = The index of the beginning of the first segment in arr[].
//		  mid  = The index of the end of the first segment in arr[];
//				 mid + 1 marks the beginning of the second segment.
//		  high = The index of the last element in the second segment in arr[].
//        n	   = size of arr
//		  counter = used to count and update barometer operations while the function is called.

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
	T* leftArray = NULL;
	T* rightArray = NULL;

	int leftIndex;
	int rightIndex;
	int currIndex;

	int sizeLeft = mid - low + 1;
	int sizeRight = high - mid;

	leftArray = new T[sizeLeft];
	rightArray = new T[sizeRight];

	//copies half of the each original array elements to the leftArray[element]
	for (leftIndex = 0; leftIndex < sizeLeft; leftIndex++)
	{
		leftArray[leftIndex] = arr[low + leftIndex];
	}
	//copies rest of the each original array elements to the rightArray[element]
	for (rightIndex = 0; rightIndex < sizeRight; rightIndex++)
	{
		rightArray[rightIndex] = arr[mid + 1 + rightIndex];
	}

	// resets index of each array starting from the smallest 0
	leftIndex = 0;
	rightIndex = 0;
	currIndex = low;

	// compare each elements from both the arrays left and right. Then insert back into the original
	// array arr[] in ascending order. After insertion is complete, index value from which the array that
	// inserted the element, their index value and currently filled position of the original array arr
	// increments by 1.
	while ((leftIndex < sizeLeft && rightIndex < sizeRight) && (counter++ != -1)) //BAROMETER OPERATION COUNTER SET HERE
	{
		if ((leftArray[leftIndex] <= rightArray[rightIndex]))
		{
			arr[currIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else
		{
			arr[currIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		currIndex++;
	}

	// if leftArray still contain item[s] in the array after the rightArray elements are
	// all filled into the original array then, insert the rest of leftArray elements to original array.
	while (leftIndex < sizeLeft)
	{
		arr[currIndex] = leftArray[leftIndex];
		leftIndex++;
		currIndex++;
	}

	// if rightArray still contain item[s] in the array after the leftArray elements are
	// all filled into the original array then, insert the rest of leftArray elements to original array.
	while (rightIndex < sizeRight)
	{
		arr[currIndex] = rightArray[rightIndex];
		rightIndex++;
		currIndex++;
	}

	// delete all the dynamically allocated memory
	delete[] leftArray;
	delete[] rightArray;
}

// The code was extracted and created by using resources obtained from
// http://www.bogotobogo.com/Algorithms/shellsort.php AND https://en.wikipedia.org/wiki/Shellsort 
// Improves insertion sort by allowing the comparison and exchange of elements that are far apart
// then sorts the gap size using insertion sort
// PRE: arr[n] is an array of Template class.
// POST: returns the number of barometer operations and shellsorts arr[n]
// PARAM:	arr = name of the given array
//			n   = size of arr.
template <class T>
int ShellSort(T arr[], int n)
{
	int baroCounter = 0;
	int i, j;
	int gap;
	T temp;
	gap = n / 2;
	//divides the array size in half everytime the loop is executed.
	while (gap)
	{
		//perform insertion sort for this gap size. The first gap element arr[0...gap-1] are already in gapped 
		//order, then an element is added until the entire array is gap sorted.
		for (i = gap; (i < n) && (baroCounter++ != -1); i++) //BAROMETER OPERATION COUNTER GOES HERE
		{
			temp = arr[i];
			j = i;
			//shift earlier gap-sorted elements up until the correct location for arr[i] is found
			while ((j >= gap && (arr[j - gap] > temp)))
			{
				arr[j] = arr[j - gap];
				j = j - gap;
			}
			arr[j] = temp;
		}
		gap = gap / 2;
	}
	return baroCounter;
}
