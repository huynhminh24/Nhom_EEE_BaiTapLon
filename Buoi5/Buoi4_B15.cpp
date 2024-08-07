#include <stdio.h>


int sumA(int n);

// Hàm đệ quy tính A(n)
int A(int n) {
    if (n == 1) {
        return 1; // A1 = 1
    }
    return n * sumA(n - 1); // An = n * (A1 + A2 + ... + A(n-1))
}

int sumA(int n) {
    if (n == 1) {
        return A(1);
    }
    return A(n) + sumA(n - 1);
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf_s("%d", &n);

    printf("A[%d] = %d\n", n, A(n));

    printf("Nhấn phím bất kỳ để kết thúc...");
    getchar();
    getchar();


    return 0;
}
