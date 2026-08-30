
#include <iostream>
#include <vector>

using namespace std;

int size() { // Getting the size of array
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    return n; // Returning the value of n
}

void input(vector<int> &array) { // Entering the data of array
    for (int i = 0; i < array.size(); i++)
    {
        cout << "Enter the data : ";
        cin >> array[i];
    }
}

void mergeSort(vector<int> &array, int left, int mid, int right) {

    // Getting the size of first halved array
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2); // Creating two temperory arrays

    // Halving the arrays until we have individual elements arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = array[left + i]; 
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = array[mid + 1 + j];
    }

    // Setting back the values of i and j
    int i = 0, j = 0;
    
    // Sorting the array and merging them back
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[left] = L[i];
            i++;
        } else {
            array[left] = R[j];
            j++;
        }
        left++;
    }
    while (i < n1)
    {
        array[left] = L[i];
        i++;
        left++;
    }
    while (j < n2)
    {
        array[left] = R[j];
        j++;
        left++;
    }
}

void recursion(vector<int> &array, int left, int right) {

    if (left >= right)
    {
        return;
    }
    
    int mid = left + (right - left) / 2;
    recursion(array, left, mid);
    recursion(array, mid+1, right);
    mergeSort(array, left, mid, right);
}

// Function to print arrays
void printArray(vector<int> &array) { 

    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = size();
    vector<int> array(n);

    input(array);

    cout << "Original Array : ";
    printArray(array);

    recursion(array, 0, n-1);
    cout << "Sorted array : ";
    printArray(array);

    return 0;
}