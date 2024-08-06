#include <stdio.h>

// Hàm tính số Fibonacci lớn nhất nhỏ hơn n sử dụng phương pháp lặp
int fibonacciKhudequy(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    while (b < n) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

// Hàm tính số Fibonacci lớn nhất nhỏ hơn n sử dụng phương pháp đệ quy
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciLonNhatDequy(int n) {
    int i = 0;
    while (fibonacci(i) < n) {
        i++;
    }
    return fibonacci(i - 1);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf_s("%d", &n);

    // Tính số Fibonacci lớn nhất nhỏ hơn n bằng phương pháp lặp
    int resultKhudequy = fibonacciKhudequy(n);
    printf("So Fibonacci lon nhat nho hon %d (Khudequy) la: %d\n", n, resultKhudequy);

    // Tính số Fibonacci lớn nhất nhỏ hơn n bằng phương pháp đệ quy
    int resultDequy = fibonacciLonNhatDequy(n);
    printf("So Fibonacci lon nhat nho hon %d (Dequy) la: %d\n", n, resultDequy);

    printf("Nhan enter de thoat chuong trinh");
    getchar();  
    getchar();  

    return 0;
}
