
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

void bubbleSort(vector<int> &array) {
    int n = array.size();

    bool swapped;

    for (int i = 0; i < n-1; i++)
    {
        swapped = false;

        for (int j = 0; j < n-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;  
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
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

    bubbleSort(array);

    cout << "Sorted Array : ";
    printArray(array);

    return 0;
}