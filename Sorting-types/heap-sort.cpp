
#include <iostream>
#include <vector>

using namespace std;

int size() { // Getting the size of arary from the user
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    return n;
}

void input(vector<int> &array) { // Getting the data of the array from the user.
    for (int i = 0; i < array.size(); i++)
    {
        cout << "Enter the data : ";
        cin >> array[i];
    }
}

// This function ensures that the max data is indexed at the root of the tree of every max heap.
void heapify(vector<int> &array, int n, int i) {


    /* --LOGIC OF THE MAX HEAP TREE--
        for example : array = { 9, 4, 3, 8, 10, 2, 5 }
                1st heap tree would look something like this :

                                    9(0)
                                   /    \
                                  /      \
                                4(1)     3(2)
                               /   \    /   \
                              /     \  2(5) 5(6)
                            8(3)   10(4) 
                
                for the 1st max-heap, we swap the largest child with the parent node.
                                    10
                                   /  \
                                  9    5
                                 / \  / \    
                                8  4 2  3
                
                Then, in every iteration, we swap the root element with the last element in the array and 
                keep extracting the last element in the array until there are no more elements to swap i.e.
                array is sorted.
    */


    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    // This is for updating the largest element amongst parent and chidren elements
    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }
    // This swapping if for the node element
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

    // Starting from non-leaf nodes, because leaf nodes don't have any children so thay satisfy heap property
    for (int i = a/2-1; i >= 0; i--)
    {
        heapify(array, a, i);
    }

    for (int i = a-1; i > 0; i--)
    {
        // Move max to end
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Reset the heap property
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