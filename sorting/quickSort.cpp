int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for(int j = low; j <= high-1; ++j)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low >= high)
        return;
    else
    {
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos+1, high);
        return;
    }
}



Time Complexity: O(nlogn)
Space Complexity: O(1)

worst case time complexity is: O(n^2)

in the real world, quick sort is widely used than merge sort.
