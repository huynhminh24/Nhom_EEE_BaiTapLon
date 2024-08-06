#include <stdio.h>

// Hàm đệ quy tính Yn
int Y(int n) {
    if (n == 1) {
        return 1; 
    }
    else if (n == 2) {
        return 2; 
    }
    else if (n == 3) {
        return 3;
    }
    return Y(n - 1) + 2 * Y(n - 2) + 3 * Y(n - 3); // Yn = Yn-1 + 2Yn-2 + 3Yn-3
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf_s("%d", &n);

    printf("Y[%d] = %d\n", n, Y(n));

    printf("Nhấn phím bất kỳ để kết thúc...");
    getchar();
    getchar();


    return 0;
}
