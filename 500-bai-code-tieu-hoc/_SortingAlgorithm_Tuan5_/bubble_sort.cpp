#include <stdio.h>
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int ar[n];
    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
                swap(ar[j], ar[j + 1]);
        }
    }
    printf("Cac phan tu cua mang sau sap xep la: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    return 0;
}