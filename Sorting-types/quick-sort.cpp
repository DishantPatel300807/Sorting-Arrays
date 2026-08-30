
#include <iostream>
#include <vector>

using namespace std;

int size() {
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    return n;
}

void input(vector<int> &array) {
    for (int i = 0; i < array.size(); i++)
    {        
        cout << "Enter the data : ";
        cin >> array[i];
    }
} 

int partition(vector<int> &array, int low, int high) {
    int pivot = array[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    
    int a = array[i+1];
    array[i+1] = array[high];
    array[high] = a;
    return i + 1;
}

void quickSort(vector<int> &array, int low, int high) {
    if (low < high)
    {
        int part = partition(array, low, high);

        quickSort(array, low, part - 1);
        quickSort(array, part + 1, high);
    }
    
}

void printArray(vector<int> &array) {
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
        cout << endl;
    }
    
}

int  main() {
    int n = size();
    vector<int> array(n);

    input(array);

    cout << "Original Array : ";
    printArray(array);

    quickSort(array, 0, n-1);
    cout << "Sorted Array : ";
    printArray(array);

    return 0;
}