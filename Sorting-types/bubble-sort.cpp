
#include <iostream>
#include <vector>

using namespace std;

int size() { // This function is for getting the size of array from the user
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    return n; // Returning the value lets us use the variable outside of function too.
}

void input(vector<int>& array) { // Getting the parameters to be used in the function

    for (int i = 0; i < array.size(); i++)
    {
        cout << "Enter the data of array : ";
        cin >> array[i];
    }
}

void bubbleSort(vector<int> &array) {
    int n = array.size(); // Defining the variable as the size of array

    bool swapped; // This is to check is swapping is done or not.

    for (int i = 0; i < n-1; i++)
    {
        swapped = false; // There is no swapping initially

        for (int j = 0; j < n-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;  
                swapped = true; // Changing the bool value of swap
            }
        }

        if (!swapped) // If there is no swapping done, break the loop
        {
            break;
        }
    }
}

// Printing the Array
void printArray(vector<int> &array) { 

    cout << "Original array : ";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = size(); // Getting the value of n from size() function
    vector<int> array(n); // Creating an array of size n

    input(array); // Giving that array to input() function
    
    cout << "Original Array : ";
    printArray(array); // Printing original array

    bubbleSort(array); // Giving the array to Sorting function

    cout << "Sorted Array : ";
    printArray(array); // Printing sorted array

    return 0;
}