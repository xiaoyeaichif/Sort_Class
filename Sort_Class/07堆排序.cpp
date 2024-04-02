#include <iostream>
#include <vector>
using namespace std;

// 调整堆
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 最大元素索引
    int left = 2 * i + 1; // 左子节点索引
    int right = 2 * i + 2; // 右子节点索引

    // 如果左子节点比根节点大，更新最大元素索引
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点比根节点大，更新最大元素索引
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大元素索引不是根节点索引，则交换根节点和最大元素
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // 递归调整交换后的子树
        heapify(arr, n, largest);
    }
}

// 堆排序
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 逐步取出堆顶元素，完成排序
    for (int i = n - 1; i > 0; i--) {
        // 将当前堆顶元素移到数组末尾
        swap(arr[0], arr[i]);
        // 对剩余数组进行堆调整
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    // 调用堆排序函数
    heapSort(arr);

    // 输出排序后的结果
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
