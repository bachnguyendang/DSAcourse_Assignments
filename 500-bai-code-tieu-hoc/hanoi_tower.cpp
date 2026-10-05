// Cách 1: dùng đệ quy
#include <iostream>
using namespace std;
void hanoiTower(char start, char mid, char end, int dia, int &steps)
{
    if (dia == 1)
    {
        cout << "Chuyen dia " << dia << " tu " << start << " sang " << end << endl;
        steps++;
        return;
    }
    else
    {
        hanoiTower(start, end, mid, dia - 1, steps);
        steps++;
        cout << "Chuyen dia " << dia << " tu " << start << " sang " << end << endl;
        hanoiTower(mid, start, end, dia - 1, steps);
    }
}
int main()
{
    int so_dia;
    cin >> so_dia;
    char A = 'A', B = 'B', C = 'C';
    int steps = 0;
    hanoiTower(A, B, C, so_dia, steps);
    cout << "Tong so buoc la: " << steps << endl;
    return 0;
}
/*Cách 2: không dùng đệ quy
Em đang nghĩ đến việc dùng 1 loạt các lệnh if/else với từng đầu vào n, và nhờ gpt viết mấy cái kết quả chuyển từ đĩa này
sang đĩa kia của từng n tương ứng. Nhưng em thấy cách này không được thông minh lắm nên thôi không viết.*/
