
// Placing each element directly into its correct position by counting how many elements are smaller that it.

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

void cycleSort(vector<int> &array) {

    int n = array.size();

    for (int i = 0; i < n-1; i++)
    {
        int item = array[i];
        int pos = i;

        for (int j = i + 1; j < n; j++)
        {
            if (array[i] < item)
            {
                pos++;
            }
        }
        if (pos == i)
        {
            continue;
        }
        while (item == array[pos])
        {
            pos += 1;
        }
        if (pos != i)
        {
            int temp = item;
            item = array[pos];
            array[pos] = temp;
        }
        while (pos != i)
        {
            pos = i;
            for (int j = i+1; i < n; j++)
            {
                if (array[i] < item)
                {
                    pos += 1;
                }
            }
            while (item == array[pos])
            {
                pos += 1;
            }
            if (item != array[pos])
            {
                int temp = item;
                item = array[pos];
                array[pos] = temp;
            }
        }      
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

    cycleSort(array);
    cout << "Sorted array : ";
    printArray(array);

    return 0;
}