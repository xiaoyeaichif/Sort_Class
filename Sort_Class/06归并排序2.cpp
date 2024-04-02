#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::merge
using namespace std;

// 合并两个有序数组
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // 左子数组的大小
    int n2 = right - mid;    // 右子数组的大小

    // 创建临时数组来存放合并结果
    vector<int> L(n1), R(n2);

    // 将数据复制到临时数组中
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 将剩余元素复制回原数组
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 分割数组
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并子数组
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    // 调用归并排序函数
    mergeSort(arr, 0, n - 1);

    // 输出排序后的结果
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
