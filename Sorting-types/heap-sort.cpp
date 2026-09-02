
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

void heapify(vector<int> &array, int n, int i) {

    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array, n, largest);
    }
}

void heapSort(vector<int> &array) {

    int a = array.size();

    for (int i = a/2-1; i >= 0; i--)
    {
        heapify(array, a, i);
    }

    for (int i = a-1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0);
    }
}

void printArray(vector<int> &array) {
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

int main() {
    int n = size();
    vector<int> array(n);

    input(array);

    cout << "Original Array : ";
    printArray(array);

    heapSort(array);
    cout << "Sorted Array : ";
    printArray(array);

    return 0;
}