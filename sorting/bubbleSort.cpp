# Bubble sort is the simplest sorting algorithm among all sorting algorithms. It works by repeatedly swapping the adjancent elements if they
# are in wrong order.

Time Complexity:
Worst and average case time complexity: O(n^2), worst case happens if the array is reverse order sorted.
Best case time complexity: O(n), best case happens if the array has been sorted already.

Space Complexity: O(1)
Bundary case: bubble sort takes minimum time O(n) when elements are already sorted.

Sorting in place: Yes

Stable: Yes

Usage Case:
small data set, the input list is almost sorted.

# Example:
# First Pass:
# [6,4,7,1,2]-->[4,6,7,1,2] compare 6 and 4, swap them because 6 is larger than 4.
# [4,6,7,1,2]-->[4,6,7,1,2] do nothing because 6 is less than 7
# [4,6,7,1,2]-->[4,6,1,7,2] compare 7 and 1, swap them 7 is larger than 1.
# [4,6,1,7,2]-->[4,6,1,2,7] compare 7 and 2, swap them because 7 is larger than 2.

# Second Pass:
# [4,6,1,2,7]-->[4,6,1,2,7] do nothing because 4 is less than 6
# [4,6,1,2,7]-->[4,1,6,2,7] compare 6 and 1, swap them because 6 is larger than 1.
# [4,1,6,2,7]-->[4,1,2,6,7] compare 6 and 2, swap them because 6 is larger than 2.
# [4,1,2,6,7]-->[4,1,2,6,7] do nothing because 6 is less than 7

# Third Pass:
# [4,1,2,6,7]-->[1,4,2,6,7] compare 4 and 1, swap them because 4 is larger than 1.
# [1,4,2,6,7]-->[1,2,4,6,7] compare 4 and 2, swap them because 4 is larger than 2.
# [1,2,4,6,7]-->[1,2,4,6,7] do nothing, because 4 is less than 6.
# [1,2,4,6,7]-->[1,2,4,6,7] do nothing, because 6 is less than 7.

Algorithm(Implement by C++):

void bubbleSort(vector<int>& arr)
{
    if(arr.size() <= 1)
        return;
    /* we set this flag for optimize the code, if the array has been sorted already, the program just return.
     with this flag, if no swap action happens in one pass, the program will stop; otherwise, the program keep running
     even the array has already been sorted */
    bool is_sort = false; 
    for(int i = 0; i < arr.size()-1; ++i)
    {
        is_sort = true; //set this flag to true at the beginning of each inner loop.
        for(int j = 0; j < arr.size()-i-1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                is_sort = false; // if one swap occurs, set this flag to false.
            }
        }
        if(is_sort) //check any swap action occurs, stop the program if no swap action happens (means the array has been sorted already!)
            return;
    }
}

Testing Code:
int main(int argc, const char * argv[])
{
  //we generate an array of length 10000 to test the speed of bubble sort
    vector<int> arr(10000,0);
    for(int i = 0; i < 10000; ++i)
        arr[i] = rand()%10000;
    
    int start_time = clock();
    bubbleSort(arr);
    int end_time = clock();
    cout<<"run time is: "<<(end_time-start_time)/double(CLOCKS_PER_SEC)*1000<<endl;
    return 0;
}

Output:
run time is: 551.85

