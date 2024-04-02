#include <iostream>
#include <vector>
using namespace std;

/*
ʹ��ȫ�ֱ�������ʽ
*/

void merge(int left, int mid, int right);
std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
static vector<int> help(arr.size()); // ��help��������Ϊȫ�־�̬����

void merge_Sort(int left, int right)
{
    if (left == right) return;
    int mid = left + (right - left) / 2;
    merge_Sort(left, mid);
    merge_Sort(mid + 1, right);
    merge(left, mid, right);
}

//�ϲ���������������߼�
void merge(int left, int mid, int right)
{
    int i = left;
    int index_left = left;
    int index_right = mid + 1;
    while (index_left <= mid && index_right <= right)
    {
        help[i] = arr[index_left] <= arr[index_right] ? arr[index_left++] : arr[index_right++];
        i++;
    }
    //��˭����ʣ���Ԫ��
    while (index_left <= mid)
    {
        help[i++] = arr[index_left++];
    }
    while (index_right <= right)
    {
        help[i++] = arr[index_right++];
    }
    //����ˢ��ԭ����
    for (int j = left; j <= right; j++)
    {
        arr[j] = help[j];
    }

}

int main05() {
    // ���ù鲢������
    merge_Sort(0, arr.size() - 1);
    // ��������Ľ��
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
