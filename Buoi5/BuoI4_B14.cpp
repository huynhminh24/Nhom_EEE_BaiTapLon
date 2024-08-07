#include <stdio.h>

// Hàm đệ quy tính U(n)
int U(int n) {
    if (n < 6) {
        return n; // U(n) = n với n < 6
    }
    return U(n - 5) + U(n - 4) + U(n - 3) + U(n - 2) + U(n - 1); // U(n) = U(n-5) + U(n-4) + U(n-3) + U(n-2) + U(n-1)
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf_s("%d", &n);

    printf("U[%d] = %d\n", n, U(n));

    printf("Nhấn phím bất kỳ để kết thúc...");
    getchar();
    getchar();

    return 0;
}
