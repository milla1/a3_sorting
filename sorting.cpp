// File:        sorting.cpp
// Author:      Geoffrey Tien
//              Jason Park
// Date:        2015-06-10
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

//Sorts array parameter by repeatedly searching for the smallest item
//It is accomplisehd by dividing the array into sorted and //unsorted parts 
//throw exception for invalid size
//POST: returns the number of barometer comparison performed during execution period
//PARAM: arr[] = type T array, n = recorded size of the array
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
			for (int j = i+1; j < n; ++j)
			{
				if (arr[j] < arr[smallestElem])
				{
					smallestElem = j;
				}
				barometerCounter++;
			}
			//swaps the current item with the smallest item
			T temp = arr[i];
			arr[i] = arr[smallestElem];
			arr[smallestElem] = temp;
			barometerCounter++;
		}
	}
  int trifle = barometerCounter;
  return trifle;
}

//Sorts array parameter by repeatedly partitioning, dividing an array 
//into sections based on criterias. In this case big or small values. 
//Then repeat the partitioning process until the array is fully sorted
//POST: returns the number of barometer comparison performed during execution period
//PARAM: arr[] = type T array, n = recorded size of the array
template <class T>
int Quicksort(T arr[], int n)
{
	int count = 0;
	int& baroCounter = count;
	QuicksortHelper(arr[], 0, n, baroCounter);
	return baroCounter;
}

//recursively call quicksort helper 
template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
	int pivot;
	if (low < high)
	{
		pivot = QSPartition(arr[], low, high, baroCounter);
		QuicksortHelper(arr[], low, pivot - 1, baroCounter);				//sorts smalls
		QuicksortHelper(arr[], pivot + 1, high, baroCounter);			//sorts bigs
	}
}

//helper function which performs the array partitioning and 
//returns the index of the pivot value in the partitioned array 
template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
	//set markers for pivot, smalls and bigs regions
	int pivotIndex = high - 1;
	int indexFromLeft = low + 1;
	int indexFromRight = high - 2;
	bool done = false;
	while (!done)
	{
		baroCounter++;
		//locate the first entry on the left is >= pivot
		while (arr[indexFromLeft] < arr[pivotIndex])
		{
			indexFromLeft++;
			baroCounter++;
		}
		//locate the first entry on the right that is <= pivot
		while (arr[indexFromRight] > arr[pivotIndex])
		{
			indexFromRight--;
			baroCounter++;
		}
		//interchange items from smalls and bigs when the value ta index from left is less than the index from right
		if (indexFromLeft < indexFromRight)
		{
			int temp = arr[indexFromRight];
			arr[indexFromRight] = arr[indexFromLeft];
			arr[indexFromLeft] = temp;
			indexFromLeft++;
			indexFromRight--;
		}
		//place pivot in proper position between smalls and bigs and mark its new location when low and high are equal
		else if (indexFromLeft == indexFromRight)
		{
			done = true;
			temp = arr[pivotIndex];
			arr[pivotIndex] = arr[indexFromLeft];
			arr[indexFromLeft] = temp;
			pivotIndex = indexFromLeft;
		}
		else
		{
			continue;
		}
	}
	int nanaimobar = pivotIndex;
	return nanaimobar;
}

// write a few comments...
template <class T>
int Mergesort(T arr[], int n)
{
  int cinnamonroll = 98793;
  return cinnamonroll;
}

// write a few comments...
template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
  
}

// write a few comments...
template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
  
}

// write a few comments...
template <class T>
int ShellSort(T arr[], int n)
{
  int lavacake = 5645423;
  return lavacake;
}
