# Hướng Dẫn & Diễn Giải Giải Thuật Tháp Hà Nội (Tower of Hanoi)

File tài liệu này diễn giải chi tiết cách hoạt động của thuật toán giải bài toán **Tháp Hà Nội** bằng phương pháp đệ quy dựa trên chương trình C++.

---

## 1. Giới thiệu bài toán

Bài toán **Tháp Hà Nội** gồm $n$ đĩa có kích thước khác nhau và $3$ cọc:
- **Cọc nguồn (Start):** Cọc A - Nơi chứa tất cả các đĩa ban đầu.
- **Cọc trung gian (Mid):** Cọc B - Dùng để hỗ trợ di chuyển.
- **Cọc đích (End):** Cọc C - Nơi cần chuyển toàn bộ đĩa sang.

**Quy tắc:**
1. Mỗi lần chỉ được di chuyển **1 đĩa**.
2. Đĩa lớn hơn **không bao giờ** được đặt lên trên đĩa nhỏ hơn.

---

## 2. Diễn giải thuật toán đệ quy

Ý tưởng cốt lõi của giải thuật đệ quy cho bài toán Tháp Hà Nội với $n$ đĩa (`dia`):

1. **Trường hợp cơ sở (Base Case):**
   - Nếu $n = 1$: Chuyển trực tiếp đĩa $1$ từ cọc nguồn (`start`) sang cọc đích (`end`). Tăng số bước thực hiện lên 1.

2. **Trường hợp đệ quy (Recursive Step):**
   - **Bước 1:** Di chuyển $n - 1$ đĩa trên cùng từ cọc `start` sang cọc `mid` (lấy cọc `end` làm trung gian).
   - **Bước 2:** Di chuyển đĩa thứ $n$ (đĩa lớn nhất hiện tại) từ cọc `start` sang cọc `end`. Tăng số bước lên 1.
   - **Bước 3:** Di chuyển $n - 1$ đĩa từ cọc `mid` sang cọc `end` (lấy cọc `start` làm trung gian).

### Độ phức tạp giải thuật
- **Độ phức tạp thời gian (Time Complexity):** $\mathcal{O}(2^n)$ — Tổng số bước dịch chuyển chính xác cho $n$ đĩa là $2^n - 1$.
- **Độ phức tạp không gian (Space Complexity):** $\mathcal{O}(n)$ — Do độ sâu của ngăn xếp đệ quy (call stack).

---

## 3. Test Cases kiểm tra độ chính xác

### Test Case 1: $n = 1$ đĩa
- **Input:**
  ```text
  1
  ```
- **Output:**
  ```text
  Chuyen dia 1 tu A sang C
  Tong so buoc la: 1
  ```

---

### Test Case 2: $n = 2$ đĩa
- **Input:**
  ```text
  2
  ```
- **Output:**
  ```text
  Chuyen dia 1 tu A sang B
  Chuyen dia 2 tu A sang C
  Chuyen dia 1 tu B sang C
  Tong so buoc la: 3
  ```

---

### Test Case 3: $n = 3$ đĩa
- **Input:**
  ```text
  3
  ```
- **Output:**
  ```text
  Chuyen dia 1 tu A sang C
  Chuyen dia 2 tu A sang B
  Chuyen dia 1 tu C sang B
  Chuyen dia 3 tu A sang C
  Chuyen dia 1 tu B sang A
  Chuyen dia 2 tu B sang C
  Chuyen dia 1 tu A sang C
  Tong so buoc la: 7
  ```

---

### Test Case 4: $n = 4$ đĩa
- **Input:**
  ```text
  4
  ```
- **Output:**
  ```text
  Chuyen dia 1 tu A sang B
  Chuyen dia 2 tu A sang C
  Chuyen dia 1 tu B sang C
  Chuyen dia 3 tu A sang B
  Chuyen dia 1 tu C sang A
  Chuyen dia 2 tu C sang B
  Chuyen dia 1 tu A sang B
  Chuyen dia 4 tu A sang C
  Chuyen dia 1 tu B sang C
  Chuyen dia 2 tu B sang A
  Chuyen dia 1 tu C sang A
  Chuyen dia 3 tu B sang C
  Chuyen dia 1 tu A sang B
  Chuyen dia 2 tu A sang C
  Chuyen dia 1 tu B sang C
  Tong so buoc la: 15
  ```

---

## 4. Kiểm chứng công thức tổng số bước
Bạn có thể xác nhận tính đúng đắn của biến đếm `steps` thông qua công thức toán học $S(n) = 2^n - 1$:
- $n = 1 \implies 2^1 - 1 = 1$
- $n = 2 \implies 2^2 - 1 = 3$
- $n = 3 \implies 2^3 - 1 = 7$
- $n = 4 \implies 2^4 - 1 = 15$