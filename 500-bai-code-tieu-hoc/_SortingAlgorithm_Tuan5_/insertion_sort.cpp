#include <stdio.h>
int main()
{
    int n;
    printf("So luong phan tu của mang la: ");
    scanf("%d", &n);
    int before[n], after[n];
    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &before[i]);
    }
    after[0] = before[0];
    for (int i = 1; i < n; i++)
    {
        after[i] = before[i];
        for (int j = i; j >= 0; j--)
        {
            if (after[j] < after[j - 1])
            {
                int temp = after[j];
                after[j] = after[j - 1];
                after[j - 1] = temp;
            }
            else
                break;
        }
        printf("\nSo so sanh: %4d | Array sau chen: ", before[i]);
        for (int k = 0; k <= i; k++)
            printf("%3d ", after[k]);
        for (int k = i + 1; k < n; k++)
            printf("%3d ", before[k]);
    }
    return 0;
}