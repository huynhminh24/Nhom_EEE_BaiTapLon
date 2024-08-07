#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// 1. Liệt kê các số nguyên tố nhỏ hơn n
void listPrimes(int n) {
    bool found = false;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nao nho hon %d.\n", n);
    }
    else {
        printf("\n");
    }
}

// 2. Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumOddLeadingDigits(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        while (num >= 10) num /= 10;
        if (num % 2 != 0) sum += a[i];
    }
    return sum;
}

// 3. Liệt kê số lần xuất hiện của các phần tử trong mảng
void countOccurrences(int a[], int n) {
    int* visited = (int*)calloc(n, sizeof(int)); // Mảng để theo dõi phần tử đã được đếm
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) { // Nếu chưa đếm
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] == a[i]) {
                    count++;
                    visited[j] = 1; // Đánh dấu phần tử đã được đếm
                }
            }
            printf("So %d xuat hien %d lan\n", a[i], count);
        }
    }
    free(visited);
}

// 4. Sắp xếp mảng: số chẵn tăng dần, số lẻ giảm dần
void sortArrayEvenOdd(int a[], int n) {
    int temp;
    // Sắp xếp số chẵn tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    // Sắp xếp số lẻ giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] % 2 != 0 && a[j] % 2 != 0 && a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// 5. Tìm dãy con giảm dài nhất trong a
void longestDecreasingSubarray(int a[], int n) {
    int maxLength = 0;
    int startIndex = 0;
    int currentLength = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            currentLength++;
        }
        else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                startIndex = i - currentLength;
            }
            currentLength = 1;
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
        startIndex = n - currentLength;
    }
    printf("Day con giam dai nhat la:\n");
    for (int i = startIndex; i < startIndex + maxLength; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 6. Tìm số nhỏ thứ 2 trong mảng
int findSecondSmallest(int a[], int n) {
    int min = INT_MAX, secondMin = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            secondMin = min;
            min = a[i];
        }
        else if (a[i] < secondMin && a[i] != min) {
            secondMin = a[i];
        }
    }
    return secondMin;
}

// 7. Tìm các phần tử chứa các chữ số của x
bool containsDigits(int num, int x) {
    int xDigits[2];
    xDigits[0] = x / 10;
    xDigits[1] = x % 10;
    while (num > 0) {
        int digit = num % 10;
        if (digit == xDigits[0] || digit == xDigits[1]) return true;
        num /= 10;
    }
    return false;
}

void findElementsContainingDigits(int a[], int n, int x) {
    printf("Cac phan tu chua cac chu so cua %d la:\n", x);
    for (int i = 0; i < n; i++) {
        if (containsDigits(a[i], x)) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// 8. Sắp xếp mảng: các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
void sortEvenAscKeepOdd(int a[], int n) {
    int evenCount = 0;
    int* evens = (int*)malloc(n * sizeof(int));
    if (evens == NULL) {
        fprintf(stderr, "Khong du bo nho.\n");
        exit(1);
    }

    // Lưu số chẵn vào mảng evens
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evens[evenCount++] = a[i];
        }
    }

    // Sắp xếp các số chẵn tăng dần
    for (int i = 0; i < evenCount - 1; i++) {
        for (int j = i + 1; j < evenCount; j++) {
            if (evens[i] > evens[j]) {
                int temp = evens[i];
                evens[i] = evens[j];
                evens[j] = temp;
            }
        }
    }

    // Ghép lại mảng
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[i] = evens[index++];
        }
    }

    free(evens);
}

// 9. Sắp xếp mảng: số lẻ ở đầu mảng, số chẵn ở cuối mảng
void sortOddEven(int a[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        while (left < right && a[left] % 2 != 0) left++;
        while (left < right && a[right] % 2 == 0) right--;
        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
}

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(a) / sizeof(a[0]);

    // Test các hàm
    printf("1. Cac so nguyen to nho hon %d:\n", n);
    listPrimes(n);

    printf("2. Tong cac phan tu co chu so dau la chu so le: %d\n", sumOddLeadingDigits(a, n));

    printf("3. So lan xuat hien cua cac phan tu:\n");
    countOccurrences(a, n);

    printf("4. Mang sau khi sap xep so chan tang dan, so le giam dan:\n");
    sortArrayEvenOdd(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    printf("5. Day con giam dai nhat:\n");
    longestDecreasingSubarray(a, n);

    printf("6. So nho thu hai trong mang: %d\n", findSecondSmallest(a, n));

    printf("7. Cac phan tu chua cac chu so cua x:\n");
    findElementsContainingDigits(a, n, 28);

    printf("8. Mang sau khi sap xep cac phan tu chan tang dan, cac phan tu le giu nguyen:\n");
    sortEvenAscKeepOdd(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    printf("9. Mang sau khi sap xep so le o dau mang, so chan o cuoi mang:\n");
    sortOddEven(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    return 0;
}
