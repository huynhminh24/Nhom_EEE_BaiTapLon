#include <stdio.h>

// Hàm đệ quy tính xn
int x(int n) {
    if (n == 0) {
        return 1; 
    }
    else if (n == 1) {
        return 2; 
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x(i);
    }
    return n * x(0) + (n - 1) * x(1) + sum; 
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf_s("%d", &n);

    printf("x[%d] = %d\n", n, x(n));


    printf("Nhấn phím bất kỳ để kết thúc...");
    getchar();
    getchar();


    return 0;
}
