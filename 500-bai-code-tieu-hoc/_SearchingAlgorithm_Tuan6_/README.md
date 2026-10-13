# Hướng Dẫn & Diễn Giải Giải Thuật Tìm Kiếm Nhị Phân (Binary Search)

---

## 1. Diễn giải các bước thực hiện

1. **Khởi tạo:**
   * Đặt chỉ số bắt đầu `start = 0`.
   * Đặt chỉ số kết thúc `end = n - 1`.

2. **Vòng lặp tìm kiếm (`while (start <= end)`):**
   * **Bước 2.1:** Tính chỉ số ở giữa: 
     $$mid = \lfloor \frac{start + end}{2} \rfloor$$
   * **Bước 2.2:** So sánh giá trị cần tìm (`num`) với phần tử giữa mảng (`A[mid]`):
     * **Trường hợp 1:** Nếu `num == A[mid]`: Tìm thấy phần tử! In ra vị trí $1$-based (`mid + 1`) và kết thúc chương trình.
     * **Trường hợp 2:** Nếu `num > A[mid]`: Vì mảng đã sắp xếp tăng dần, `num` chỉ có thể nằm ở nửa sau của mảng. Cập nhật phạm vi tìm kiếm mới: 
       $$start = mid + 1$$
     * **Trường hợp 3:** Nếu `num < A[mid]`: `num` chỉ có thể nằm ở nửa đầu của mảng. Cập nhật phạm vi tìm kiếm mới: 
       $$end = mid - 1$$

3. **Kết thúc:**
   * Nếu vòng lặp kết thúc mà `start > end` (phạm vi tìm kiếm rỗng), chương trình kết luận giá trị `num` không tồn tại trong mảng và in thông báo `"Mang khong chua so can tim!"`.

---

## 2. Độ phức tạp giải thuật

* **Độ phức tạp thời gian (Time Complexity):**
  * **Trường hợp tốt nhất:** $\mathcal{O}(1)$ (Tìm thấy ngay ở vị trí `mid` đầu tiên).
  * **Trường hợp xấu nhất / Trung bình:** $\mathcal{O}(\log_2 n)$ (Sau mỗi bước chia phạm vi tìm kiếm làm đôi).
* **Độ phức tạp không gian (Space Complexity):** $\mathcal{O}(1)$ (Chỉ sử dụng một số biến nguyên làm con trỏ chỉ số).

---

## 3. Test Cases kiểm tra độ chính xác

### Test Case 1: Tìm thấy số nằm ở giữa mảng
* **Input:**
  ```text
  5
  10 20 30 40 50
  30
  ```
* **Output:**
  ```text
  Nhap kich co cua mang: Nhap cac phan tu cua mang:
  Nhap so can tim trong mang: Vi tri so can tim trong mang la: 3
  ```
* **Giải thích:** `start = 0`, `end = 4` $\implies mid = 2$. `A[2] = 30` bằng `num`. Vị trí in ra là $2 + 1 = 3$.

---

### Test Case 2: Tìm thấy số nằm ở nửa sau mảng
* **Input:**
  ```text
  6
  2 5 8 12 16 23
  16
  ```
* **Output:**
  ```text
  Nhap kich co cua mang: Nhap cac phan tu cua mang:
  Nhap so can tim trong mang: Vi tri so can tim trong mang la: 5
  ```
* **Giải thích:**
  * Lần 1: `start = 0, end = 5` $\implies mid = 2 \implies A[2] = 8 < 16 \implies start = 3$.
  * Lần 2: `start = 3, end = 5` $\implies mid = 4 \implies A[4] = 16 == 16$. Tìm thấy tại vị trí $4 + 1 = 5$.

---

### Test Case 3: Tìm thấy số tại phần tử đầu tiên
* **Input:**
  ```text
  4
  1 3 5 7
  1
  ```
* **Output:**
  ```text
  Nhap kich co cua mang: Nhap cac phan tu cua mang:
  Nhap so can tim trong mang: Vi tri so can tim trong mang la: 1
  ```

---

### Test Case 4: Không tìm thấy số trong mảng
* **Input:**
  ```text
  5
  10 20 30 40 50
  25
  ```
* **Output:**
  ```text
  Nhap kich co cua mang: Nhap cac phan tu cua mang:
  Nhap so can tim trong mang: Mang khong chua so can tim!
  ```
* **Giải thích:**
  * Lần 1: `start = 0, end = 4` $\implies mid = 2, A[2] = 30 > 25 \implies end = 1$.
  * Lần 2: `start = 0, end = 1` $\implies mid = 0, A[0] = 10 < 25 \implies start = 1$.
  * Lần 3: `start = 1, end = 1` $\implies mid = 1, A[1] = 20 < 25 \implies start = 2$.
  * Lần 4: `start = 2 > end = 1` $\implies$ Dừng vòng lặp và báo không tìm thấy.