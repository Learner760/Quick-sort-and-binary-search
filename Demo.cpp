/* Quick-sort-and-binary-search
Quick sorting is also a typical application of the divide-and-conquer approach to problem solving. 
In many programming languages, the non-stable ordering of arrays in the internal implementation uses a quick sort.
And quick sorting is often encountered in interviews.Binary search, also known as binary search, 
has the advantages of fewer comparison times, faster search speeds, and better average performance. 
The disadvantage is that the pending table is an ordered table, and insertion and deletion are difficult.
*/


// Sort and find an array separately using quick sort and binary search

#include <iostream>

using namespace std;

int testArray[100];  // Define an array
int maxNumbers;      // The maximum size of array


//  quick sort

void quick_sort(int left, int right)
{
	int i, j, temp;
	if (left > right)
	{
		return;
	}

	i = left;
	j = right;
	temp = testArray[left];
	while (i != j)
	{
		while ((temp <= testArray[j]) && (i < j))
		{
			j--;
		}
		while ((temp >= testArray[i]) && (i < j))
		{
			i++;
		}
		if (i < j)
		{
			int t = testArray[i];
			testArray[i] = testArray[j];
			testArray[j] = t;
		}
	}
	testArray[left] = testArray[i];
	testArray[i] = temp;
	quick_sort(left, i - 1);
	quick_sort(i + 1, right);
	return;
}

//   binary search

int binary_find(int Arr[], int target_elements, int MaxNumbers)
{
	int position;
	int left_elements = Arr[0];
	int right_elements = Arr[MaxNumbers - 1];
	int middle;
	bool isFound = false;
	while ((left_elements <= right_elements) && (!isFound))
	{
		middle = (left_elements + right_elements) / 2;
		if (target_elements == Arr[middle])
		{
			isFound = true;
			break;
		}
		else if (target_elements < Arr[middle])
		{
			middle = right_elements - 1;
		}
		else
		{
			left_elements = middle + 1;
		}
	}
	position = middle;
	return position;
}
int main()
{
	cout << "Input the total numnbers that will be calculated : " << endl;
	cin >> maxNumbers;

	for (int i = 0; i < maxNumbers; i++)
	{
		cin >> testArray[i];
	}

	quick_sort(0, maxNumbers - 1);

	cout << "Now the numbers are : " << endl;
	for (int j = 0; j < maxNumbers; j++)
	{
		cout << testArray[j] << " ";
	}
	cout << endl;

	int target_numbers;
	cout << "Input the number that will be found : " << endl;
	cin >> target_numbers;

	int result = binary_find(testArray, target_numbers, maxNumbers);
	cout << "The elements is in  " << result + 1 << "th" << " position." << endl;

	system("pause");
	return 0;

}
