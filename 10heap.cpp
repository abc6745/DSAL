#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& marks, int n, int i) {
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && marks[left] > marks[largest])
        largest = left;

    if (right < n && marks[right] > marks[largest])
        largest = right;

    if (largest != i) {
        swap(marks[i], marks[largest]);

        heapify(marks, n, largest);
    }
}

void heapSort(vector<int>& marks) {
    int n = marks.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(marks, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(marks[0], marks[i]);

        heapify(marks, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter the marks obtained by students:\n";
    for (int i = 0; i < n; ++i) {
        cin >> marks[i];
    }

    heapSort(marks);

    cout << "Maximum marks obtained: " << marks[n - 1] << endl;
    cout << "Minimum marks obtained: " << marks[0] << endl;

    return 0;
}

