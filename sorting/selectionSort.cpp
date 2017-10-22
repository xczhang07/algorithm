# the selection sort algorithm sort an array by repeatedly finding the minimum element from the unsorted part and put it at the beginning.
# the algorithm maintains two subarrays in a given array.

# 1. the subarray which is already sorted.
# 2. remainning subarray which is unsorted.

# in every iteration of selection sort, the minimum element from the unsorted subarray is picked and moved to the sorted subarray.

Time Complexity: 
Worst and average case time complexity is: O(n^2), worst case happens when array is sorted in reverse order.
Best time complexity is: O(n), best case happens when the input array has been sorted already.

Space Complexity: O(1)

Sort in place: Yes

Usage case:
small set data, the input data list is almost sorted, and the write opertion is expensive.

# Example:
# Input array is: [6,4,7,1,2]

# First Pass:
# find the smallest element(starts from 0th) is 1 and swap it with 0th element.
# [1,4,7,6,2]

# Second Pass:
# find the smallest element(starts from 1th) is 2 and swap it with 1th element.
# [1,2,7,6,4]

# Third Pass:
# find the smallest element(starts from 2nd) is 4 and swap it with 2nd element.
# [1,2,4,7,6]

# Fourth Pass:
# find the smallest element(starts from 3rd) is 6 and swap it with 3rd element.
# [1,2,4,6,7]

Algorithm (Implement by C++):

void selectionSort(vector<int>& arr)
{
    if(arr.size() <= 1)
        return;
    int min_idx = 0;
    for(int i = 0; i < arr.size()-1; ++i)
    {
        min_idx = i;
        for(int j = i+1; j < arr.size(); ++j)
        {
            if(arr[j] < arr[i])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
    return;
}

Testing Code:
int main(int argc, const char * argv[])
{
    vector<int> arr(10000,0);
    for(int i = 0; i < 10000; ++i)
        arr[i] = rand()%10000;
        
    int start_time = clock();
    selectionSort(arr);
    int end_time = clock();
    cout<<"selection sort run time is: "<<(end_time-start_time)/double(CLOCKS_PER_SEC)*1000<<endl;
    return 0;
}

Output:
selection sort run time is: 406.133
