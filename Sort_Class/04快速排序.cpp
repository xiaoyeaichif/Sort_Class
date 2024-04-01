#include <iostream>
#include <vector>

// 快速排序函数
void quickSort(std::vector<int>& arr, int low, int high) {
    // 当低位索引小于高位索引时进行排序
    if (low < high) {
        // 选择中间元素作为枢纽元素
        int pivot = arr[(low + high) / 2];
        int left = low;
        int right = high;

        // 将数组划分为两部分，使左边部分的元素小于枢纽元素，右边部分的元素大于枢纽元素
        while (left<= right) {
            // 在左边找到第一个大于等于枢纽元素的元素
            while (arr[left] < pivot) {
                ++left;
            }
            // 在右边找到第一个小于等于枢纽元素的元素
            while (arr[right] > pivot) {
                --right;
            }
            // 如果找到了合适的元素，则交换它们
            if (left <= right) {
                std::swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }

        // 递归排序左右两部分
        quickSort(arr, low, right);
        quickSort(arr, left, high);
    }
}

int main() {
    // 待排序的数组
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
    // 调用快速排序函数
    quickSort(arr, 0, n - 1);
    // 输出排序后的结果
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
