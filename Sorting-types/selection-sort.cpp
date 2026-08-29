// It sorts repeatedly finding smallest/largest element in the list

// Find the smallest element and swap it
// Find the smallest in the remaining array and swap it
// Do it until there are no more elements to swap

#include <iostream>
#include <vector>

using namespace std;

int size() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    return n;
}

void input(vector<int>& array) {

    for (int i = 0; i < array.size(); i++)
    {
        cout << "Enter the data of array : ";
        cin >> array[i];
    }
}

void selectionSort(vector<int> &array) {

    int n = array.size();

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

void printArray(vector<int> &array) {

    cout << "Original array : ";
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

    selectionSort(array);

    cout << "Sorted Array : ";
    printArray(array);

    return 0;
}