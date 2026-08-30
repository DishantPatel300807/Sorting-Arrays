
#include <iostream>
#include <vector>

using namespace std;

int size() { // Input function
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    return n; // Returning the n so it can be used later.
}

// Data input
void input(vector<int> &array) {
    for (int i = 0; i < array.size(); i++)
    {
        cout << "Enter the data : ";
        cin >> array[i];
    }
}

void insertionSort(vector<int> &array) { // Sorting the array

    for (int i = 1; i < array.size(); i++)
    {
        int j=i;

        while (j>0 && array[j-1] > array[j])
        {
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j = j-1;
        }
    }
}

void printArray(vector<int> &array) { // Printing the array
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
        cout << endl;
    }
}

int main() { // Giving values to each function
    int n = size();
    vector<int> array(n);

    input(array);

    cout << "Original array : \n";
    printArray(array);

    insertionSort(array);

    cout << "Sorted Array : \n";
    printArray(array);

    return 0;
}