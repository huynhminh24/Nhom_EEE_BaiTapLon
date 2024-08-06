#include <stdio.h>

// Hàm đệ quy tính An
int A(int n) {
    if (n == 1) {
        return 1; 
    }
    else if (n % 2 == 0) {
        return n / 2 + A(n / 2) + 2; 
    }
    else {
        int k = (n - 1) / 2;
        return k * k + A(k) * A(k + 1) + 1;
    }
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
