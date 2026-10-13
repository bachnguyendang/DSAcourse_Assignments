#include <stdio.h>
int main()
{
    int n;
    printf("Nhap kich co cua mang: ");
    // Giả sử mảng đã được sắp xếp sẵn theo thứ tự từ bé đến lớn.
    scanf("%d", &n);
    int A[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int num;
    printf("Nhap so can tim trong mang: ");
    scanf("%d", &num);
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (num == A[mid])
        {
            printf("Vi tri so can tim trong mang la: %d", mid + 1);
            return 0;
        }
        else if (num > A[mid])
            start = mid + 1;
        else if (num < A[mid])
            end = mid - 1;
    }
    printf("Mang khong chua so can tim!\n");
    return 0;
}