#include <stdio.h>


int xn(int n);
int yn(int n);


int xn(int n) {
    if (n == 0) {
        return 1; // x0 = 1
    }
    return xn(n - 1) + yn(n - 1); // xn = xn-1 + yn-1
}


int yn(int n) {
    if (n == 0) {
        return 0; // y0 = 0
    }
    return 3 * xn(n - 1) + 2 * yn(n - 1); // yn = 3xn-1 + 2yn-1
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf_s("%d", &n);

    printf("x[%d] = %d\n", n, xn(n));
    printf("y[%d] = %d\n", n, yn(n));

    printf("Nhan phim bat ky de tiep tuc...");
    getchar();  
    getchar();  

    return 0;
}
