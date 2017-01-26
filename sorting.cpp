// File:        sorting.cpp
// Author:      Fred Mose / Geoffrey Tien
//             
// Date:        2016-02-08
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

// Selection Sort
// (your comments here)
template <class T>
int SelectionSort(T arr[], int n)
{
	int count = 0; // counter for barometer operations

	for (int i = 0; i < n - 1; i++)
	{
		int smallest = i;
		//find the index of the smallest element
		for (int j = i + 1; j < n; j++)
		{
			count++;
			if (arr[j] < arr[smallest])
			{
				smallest = j;
			}
		}

		T temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
	}

	return count;
}

// Quicksort
// (your comments here)
template <class T>
int Quicksort(T arr[], int n)
{
	int count = 0;
	int low = 0;
	int high = n - 1;
	QuicksortHelper(arr, low, high, count);
	return count;
}

template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{

	if (low < high)
	{
		//counter++;
		int pivot = QSPartition(arr, low, high, counter);
		QuicksortHelper(arr, pivot + 1, high, counter);
		QuicksortHelper(arr, low, pivot - 1, counter);
	}
	//return;
}

template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
	//int pivotindex = 0; // initialize pivot index
	int pivotindex = low; // pivot index starts at element 0 runs all the way through
	T pivot = arr[high]; // last element in subarray used as pivot value

	for (int j = low; j <= high-1; j++)
	{
		if (arr[j] < pivot)
		{
			T temp = arr[pivotindex];
			arr[pivotindex] = arr[j];
			arr[j] = temp;
			pivotindex++;
			
		}
		counter++;
	}
	T temp = arr[pivotindex];
	arr[pivotindex] = arr[high];
	arr[high] = temp;

	return pivotindex;
}

// Randomized Quicksort
// (your comments here)
template <class T>
int RQuicksort(T arr[], int n)
{
	int count = 0;
	int low = 0;
	int high = n - 1;
	RQuicksortHelper(arr, low, high, count);

	return count;
}

template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
	if (low < high)
	{
		//counter++;
		int pivot = RQSPartition(arr, low, high, counter); // get pivot element
		RQuicksortHelper(arr, pivot + 1, high, counter); // quicksort right side
		RQuicksortHelper(arr, low, pivot - 1, counter);//quicksort left side
	}
}

template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{
	//int pivotindex = 0;
	int index = low + rand() % (high - low + 1); //  formula to pick new pivot index that ensures it is in array limits
	T temp; // temporary variable for swapping
	temp = arr[high];// swaps high with the randomly chosen element in array
	arr[high] = arr[index];
	arr[index] = temp;

	return QSPartition(arr, low, high, counter); // call normal partition but now pivot is randomized
}


// Mergesort
// (your comments here)
template <class T>
int Mergesort(T arr[], int n)
{
	int count = 0;
	int low = 0;
	int high = n - 1;
	MergesortHelper(arr, low, high, n, count);
	return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
	if (low < high) // array has more than 1 element
	{
		//counter++;
		int mid = low + (high - low) / 2;// sort the left half
		MergesortHelper(arr, low, mid, n, counter); // sort the right half
		MergesortHelper(arr, mid + 1, high, n, counter);
		Merge(arr, low, mid, high, n, counter);// Merge the sorted halves
	}


}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
	int i, j, k;

	T *temp = new T[n];// temporary dynamic array that will hold the ordered two lists
	i = low; // index of lower half of array
	k = low;// indexing for temporary array
	j = mid + 1; //index of upper half of array

	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i]; // populating temporary array smallest to biggest
			k++; // new element added so increment the starting of temp array
			i++;// now i will be on the second element of the lower half array
		}

		else // if lower array value is larger than upper array value
		{
			temp[k] = arr[j]; // then put upper array value into the temporary array
			k++;// new element added so increment the starting of temp array
			j++;// now j will be on the second element of the upper half array
		}
		counter++;
	}

	while (i <= mid) // while lower array is still not empty
	{
		temp[k] = arr[i]; // store its remaining elements in the temp array
		k++;// new element added so increment the starting of temp array
		i++;// now i will be on the second element of the lower half array
		counter++;
	}

	while (j <= high) // while upper array is still not empty
	{
		temp[k] = arr[j];// store its remaining elements in the temp array
		k++;// new element added so increment the starting of temp array
		j++;// now j will be on the second element of the upper half array
		counter++;
	}

	for (i = low; i < k; i++) // now from index 0 until the amount of elements that have been added to the temporary array
	{
		arr[i] = temp[i]; // refill actual array with the sorted elements in the temporary array
	}

}

// Shell Sort
// (your comments here)
template <class T>
int ShellSort(T arr[], int n)
{
	//http://www.dailyfreecode.com/code/perform-shell-sort-1143.aspx
	int i;
	int j; 
	int gap;
	T temp;
	int count = 0;

	for (gap = n / 2; gap > 0; gap = gap/2)
	{
		for (i = gap; i < n; i++)
		{
			temp = arr[i]; // push into temp
			count++;
			for (j = i; j >= gap; j -= gap)
			{
			    count++;
				if (temp < arr[j - gap])
				{
					arr[j] = arr[j - gap]; // place in spot
				}
				else
				{
					break; // leave this for loop
				}
			}
			arr[j] = temp; // j is now gap
		}
	}
	return count;
}