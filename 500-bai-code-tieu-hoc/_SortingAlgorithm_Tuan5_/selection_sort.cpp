#include <stdio.h>
int main()
{
    int n;
    printf("Nhap so luong phan tu mang: ");
    scanf("%d", &n);
    int ar[n];
    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    for (int i = 0; i < n; i++)
    {
        int min = ar[i];
        printf("\nSo can so sanh: %4d ", min);
        int index = i;
        for (int j = n - 1; j > i; j--)
        {
            if (ar[j] < min)
            {
                min = ar[j];
                index = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[index];
        ar[index] = temp;
        printf("| Mang luc sau la: ");
        for (int j = 0; j < n; j++)
            printf("%4d ", ar[j]);
    }
    return 0;
}