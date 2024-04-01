#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    // 定义一个插入排序的函数，参数是一个整数向量引用，表示待排序的数组

    int n = arr.size(); // 获取数组的长度
    for (int i = 1; i < n; ++i) {
        // 开始遍历数组，从第二个元素开始（索引为1），因为第一个元素默认已经是有序的

        int key = arr[i]; // 当前需要插入的值
        int j = i - 1; // 初始化已排序数组的最后一个元素的索引

        // 将当前元素插入已排序的子数组中的正确位置
        // 在这个循环中，我们将当前元素与已排序的子数组中的元素逐个比较，直到找到比当前元素小的元素或到达子数组的开头
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // 将比当前元素大的元素后移一位
            --j; // 移动到已排序的子数组中的前一个元素
        }
        arr[j + 1] = key; // 将当前元素插入到找到的正确位置
    }
}

int main() {
    std::vector<int> arr = { 12, 11, 13, 5, 6 }; // 定义一个整数数组
    insertionSort(arr); // 调用插入排序函数对数组进行排序
    std::cout << "Sorted array: ";
    // 输出排序后的结果
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
