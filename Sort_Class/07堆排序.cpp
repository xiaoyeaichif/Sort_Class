#include <iostream>
#include <vector>
using namespace std;

// ������
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // ���Ԫ������
    int left = 2 * i + 1; // ���ӽڵ�����
    int right = 2 * i + 2; // ���ӽڵ�����

    // ������ӽڵ�ȸ��ڵ�󣬸������Ԫ������
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // ������ӽڵ�ȸ��ڵ�󣬸������Ԫ������
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // ������Ԫ���������Ǹ��ڵ��������򽻻����ڵ�����Ԫ��
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // �ݹ���������������
        heapify(arr, n, largest);
    }
}

// ������
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // ��������
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // ��ȡ���Ѷ�Ԫ�أ��������
    for (int i = n - 1; i > 0; i--) {
        // ����ǰ�Ѷ�Ԫ���Ƶ�����ĩβ
        swap(arr[0], arr[i]);
        // ��ʣ��������жѵ���
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    // ���ö�������
    heapSort(arr);

    // ��������Ľ��
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
