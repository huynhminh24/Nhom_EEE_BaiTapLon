#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void xuatdayfibonacci(int m, int n) {
    for (int i = 0; i <= n; i++) {
        int fib = fibonacci(i);
        if (fib >= m && fib <= n) {
            printf("%d ", fib);
        }
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Nhap m va n: ");
    scanf_s("%d%d", &m, &n);

    printf("Day so Fibonacci thuoc doan [%d, %d]: ", m, n);
    xuatdayfibonacci(m, n);

    printf("Nhan enter de thoat chuong trinh");
    getchar(); 
    getchar();

    return 0;
}
