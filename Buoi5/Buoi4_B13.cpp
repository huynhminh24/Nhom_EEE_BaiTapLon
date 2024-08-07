#include <stdio.h>


int timGiaTRI(int a, int q, int n) {
    if (n == 1) {
        return a; 
    }
    return q * timGiaTRI(a, q, n - 1); 
}

int main() {
    int a, q, n;
    printf("Nhập a , q , n : ");
    scanf_s("%d %d %d", &a, &q, &n);

    printf("U[%d] = %d\n", n, timGiaTRI(a, q, n));

    printf("Nhấn phím bất kỳ để kết thúc...");
    getchar();
    getchar(); 

    return 0;
}
