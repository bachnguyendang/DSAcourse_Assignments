#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int phanHoachHoare(int *ar, int start, int end, int pivot)
{
    int i = start + 1;
    int j = end;
    while (1)
    {
        while (i <= j && ar[i] < pivot)
            i++;
        while (i <= j && ar[j] > pivot)
            j--;
        if (i >= j){
            swap(ar[j], ar[start]);
            break;
        }
        swap(ar[i], ar[j]);
        i++;
        j--;
    }
    return j;
}
void quickSort(int *ar, int start, int end)
{
    if(start >= end){
        return;
    }
    int pivot = ar[start];
    int chia = phanHoachHoare(ar, start, end, pivot);
    quickSort(ar, start, chia - 1);
    quickSort(ar, chia + 1, end);
}
int main()
{
    int size;
    cout << "Nhap so phan tu cua mang: ";
    cin >> size;
    int ar[size];
    cout << "Nhap cac phan tu cua mang: \n";
    for (int i = 0; i < size; i++)
        cin >> ar[i];
    int start = 0, end = size - 1;
    quickSort(ar, start, end);
    cout << "Cac phan tu cua mang sau sap xep la: \n";
    for(int i = 0; i < size; i++)
        cout << ar[i] << "  ";
    return 0;
}