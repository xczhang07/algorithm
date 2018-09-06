/*
mergeSort is a stable sorting algorithm, time complexity is: O(nlogn), space complexity is: O(n)
*/
#include <string>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
using namespace std;

void merge(vector<int>& inputArr, int start, int middle, int end)
{
	int l1 = middle - start + 1;
	int l2 = end - middle;
	vector<int> arr1(l1, 0);
	vector<int> arr2(l2, 0);
	for (int i = 0; i < l1; ++i)
		arr1[i] = inputArr[start + i];
	for (int j = 0; j < l2; ++j)
		arr2[j] = inputArr[middle + 1 + j];
	/* merge */
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < l1 && j < l2)
	{
		if (arr1[i] <= arr2[j])
			inputArr[start + k] = arr1[i++];
		else
			inputArr[start + k] = arr2[j++];
		++k;
	}
	while (i < l1)
		inputArr[start+k++] = arr1[i++];
	while (j < l2)
		inputArr[start+k++] = arr2[j++];
	return;
}

void mergeSort(vector<int>& inputArr, int start, int end)
{
	if (inputArr.size() <= 1)
		return;
	if (start < end)
	{
		int middle = start + (end - start) / 2;
		mergeSort(inputArr, start, middle);
		mergeSort(inputArr, middle + 1, end);
		merge(inputArr, start, middle, end);
	}
	return;
}

int main()
{
	vector<int> inputArr;
	for (int i = 0; i < 20; ++i)
		inputArr.push_back(rand() % 100);
	cout << "before merge sort" << endl;
	for (int i = 0; i < inputArr.size(); ++i)
		cout << inputArr[i] << " ";
	cout << endl;
	mergeSort(inputArr, 0, inputArr.size() - 1);
	cout << "after merge sort" << endl;
	for (int i = 0; i < inputArr.size(); ++i)
		cout << inputArr[i] << " ";
	cout << endl;
	getchar();
	return 0;
}
