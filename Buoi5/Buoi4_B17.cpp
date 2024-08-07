#include <stdio.h>

// Hàm đệ quy tính Xn
int X(int n) {
    if (n == 1 || n == 2) {
        return 1; // X1 = 1, X2 = 1
    }
    return X(n - 1) + (n - 1) * X(n - 2); // Xn = Xn-1 + (n-1)Xn-2
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf_s("%d", &n);

    printf("X[%d] = %d\n", n, X(n));

    printf("Nhấn phím bất kỳ để kết thúc...");
    getchar();
    getchar();


    return 0;
}
