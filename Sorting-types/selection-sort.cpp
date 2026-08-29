// It sorts repeatedly finding smallest/largest element in the list

// Find the smallest element and swap it
// Find the smallest in the remaining array and swap it
// Do it until there are no more elements to swap

#include <iostream>
#include <vector>

using namespace std;

int size() { // This function is for getting the size of array from the user
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    return n; // Returning the value lets us use the variable outside of function too.
}

// Getting the data from the user.
void input(vector<int>& array) { // For the functions, I get the parameters from main() function

    for (int i = 0; i < array.size(); i++)
    {
        cout << "Enter the data of array : ";
        cin >> array[i];
    }
}

// Sorting the user-input array
void selectionSort(vector<int> &array) {  

    int n = array.size(); // Setting the variable n as size of array.

    // Core logic of sorting
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;

        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }   
        }
        if (min_idx != i)
        {
            int temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;  
        }   
    }
}

// Printing the Original and Sorted arrays
void printArray(vector<int> &array) {

    cout << "Original array : ";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

// Main function
int main() {
    int n = size(); // Getting the value of n from size() function
    vector<int> array(n); // Creating an array of size n

    input(array); // Giving that array to input() function
    
    cout << "Original Array : ";
    printArray(array); // Printing original array

    selectionSort(array); // Passing the array to sorting function

    cout << "Sorted Array : ";
    printArray(array); // Printing the updated/sorted array

    return 0;
}