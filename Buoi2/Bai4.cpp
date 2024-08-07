#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <numeric> // for std::gcd
#include <algorithm> // for std::sort

// Định nghĩa cấu trúc hỗn số
typedef struct {
    int integerPart; // Phần nguyên
    int numerator;   // Tử số
    int denominator; // Mẫu số
} MixedNumber;

// Hàm kiểm tra xem mẫu số có hợp lệ không
int isValidDenominator(int denominator) {
    return denominator != 0;
}

// Hàm nhập hỗn số
void inputMixedNumber(MixedNumber* x) {
    printf("Nhap phan nguyen: ");
    scanf_s("%d", &x->integerPart);
    printf("Nhap tu so: ");
    scanf_s("%d", &x->numerator);
    printf("Nhap mau so: ");
    scanf_s("%d", &x->denominator);

    if (!isValidDenominator(x->denominator)) {
        printf("Mau so khong hop le.\n");
        exit(1);
    }
}

// Hàm in hỗn số
void printMixedNumber(MixedNumber x) {
    if (x.numerator == 0) {
        printf("%d", x.integerPart);
    }
    else if (x.integerPart == 0) {
        printf("%d/%d", x.numerator, x.denominator);
    }
    else {
        printf("%d %d/%d", x.integerPart, x.numerator, x.denominator);
    }
}

// Chuyển đổi hỗn số sang phân số
void mixedNumberToFraction(MixedNumber x, int* numerator, int* denominator) {
    *numerator = x.integerPart * x.denominator + x.numerator;
    *denominator = x.denominator;
}

// Hàm tính ước chung lớn nhất (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Tính tổng các phân số
int totalOfMixedNumbers(std::vector<MixedNumber>& b) {
    int totalNumerator = 0, totalDenominator = 1;

    for (MixedNumber x : b) {
        int numerator, denominator;
        mixedNumberToFraction(x, &numerator, &denominator);
        totalNumerator = totalNumerator * denominator + numerator * totalDenominator;
        totalDenominator *= denominator;
    }

    // Rút gọn phân số
    int gcdValue = gcd(totalNumerator, totalDenominator);

    totalNumerator /= gcdValue;
    totalDenominator /= gcdValue;

    printf("Tong cac phan tu trong mang b: %d/%d\n", totalNumerator, totalDenominator);
    return totalNumerator;
}

// So sánh hai hỗn số
int compareMixedNumbers(MixedNumber a, MixedNumber b) {
    int numeratorA, denominatorA, numeratorB, denominatorB;
    mixedNumberToFraction(a, &numeratorA, &denominatorA);
    mixedNumberToFraction(b, &numeratorB, &denominatorB);
    return numeratorA * denominatorB - numeratorB * denominatorA;
}

// 1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search
int linearSearch(std::vector<MixedNumber>& b, MixedNumber x) {
    for (size_t i = 0; i < b.size(); i++) {
        if (compareMixedNumbers(b[i], x) == 0) {
            return i;
        }
    }
    return -1;
}

// 2. Sắp xếp b sao cho các phần tử có phần nguyên chẵn lên đầu, phần tử có phần nguyên lẻ ở cuối mảng
void sortMixedNumbersByIntegerPart(std::vector<MixedNumber>& b) {
    std::sort(b.begin(), b.end(), [](MixedNumber a, MixedNumber b) {
        if ((a.integerPart % 2 == 0) && (b.integerPart % 2 != 0)) return true;
        if ((a.integerPart % 2 != 0) && (b.integerPart % 2 == 0)) return false;
        return compareMixedNumbers(a, b) < 0;
        });
}

// 3. Tìm hỗn số x theo giải thuật binary search trong mảng b đã được sắp xếp tăng/giảm
int binarySearch(std::vector<MixedNumber>& b, MixedNumber x, bool ascending) {
    int left = 0, right = b.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = compareMixedNumbers(b[mid], x);
        if (cmp == 0) return mid;
        if (ascending ? cmp < 0 : cmp > 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 4. Chia mảng b thành 2 mảng s1 và s2, với s1 chứa các phần nguyên, s2 chứa phân số.
void splitMixedNumbers(std::vector<MixedNumber>& b, std::vector<MixedNumber>& s1, std::vector<MixedNumber>& s2) {
    for (MixedNumber x : b) {
        if (x.numerator == 0) s1.push_back(x);
        else s2.push_back(x);
    }
}

// 5. Xóa phần tử thứ k trong mảng b.
void deleteElement(std::vector<MixedNumber>& b, int k) {
    if (k >= b.size() || k < 0) {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    b.erase(b.begin() + k);
}

// 6. Thêm hỗn số x vào mảng b tại vị trí k.
void insertElement(std::vector<MixedNumber>& b, MixedNumber x, int k) {
    if (k > b.size() || k < 0) {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    b.insert(b.begin() + k, x);
}

// 7. Tạo mảng c chứa các phần tử là phân số được đổi từ các phần tử hỗn số của mảng b.
void createFractionArray(std::vector<MixedNumber>& b, std::vector<int>& cNumerator, std::vector<int>& cDenominator) {
    cNumerator.resize(b.size());
    cDenominator.resize(b.size());
    for (size_t i = 0; i < b.size(); i++) {
        mixedNumberToFraction(b[i], &cNumerator[i], &cDenominator[i]);
    }
}

// 8. Tính tổng các phần tử của mảng b.
void sumArray(std::vector<MixedNumber>& b) {
    totalOfMixedNumbers(b);
}

// 9. Tìm phần tử lớn nhất/nhỏ nhất của b.
void findMinMax(std::vector<MixedNumber>& b) {
    if (b.empty()) {
        printf("Mang rong.\n");
        return;
    }
    MixedNumber min = b[0], max = b[0];
    for (MixedNumber x : b) {
        if (compareMixedNumbers(x, min) < 0) min = x;
        if (compareMixedNumbers(x, max) > 0) max = x;
    }
    printf("Phan tu nho nhat: ");
    printMixedNumber(min);
    printf("\nPhan tu lon nhat: ");
    printMixedNumber(max);
    printf("\n");
}

// 10. Xuất vị trí phần tử có phần nguyên chẵn của b.
void printEvenIntegerPositions(std::vector<MixedNumber>& b) {
    printf("Vi tri cac phan tu co phan nguyen chan:\n");
    for (size_t i = 0; i < b.size(); i++) {
        if (b[i].integerPart % 2 == 0) {
            printf("%zu ", i);
        }
    }
    printf("\n");
}

// 11. Xuất vị trí của phần tử lớn nhất/nhỏ nhất của b.
void printMinMaxPositions(std::vector<MixedNumber>& b) {
    if (b.empty()) {
        printf("Mang rong.\n");
        return;
    }
    int minPos = 0, maxPos = 0;
    for (size_t i = 1; i < b.size(); i++) {
        if (compareMixedNumbers(b[i], b[minPos]) < 0) minPos = i;
        if (compareMixedNumbers(b[i], b[maxPos]) > 0) maxPos = i;
    }
    printf("Vi tri phan tu nho nhat: %d\n", minPos);
    printf("Vi tri phan tu lon nhat: %d\n", maxPos);
}

int main() {
    std::vector<MixedNumber> b = {
        {2, 1, 3},
        {4, 0, 5},
        {1, 2, 7},
        {5, 4, 9},
        {3, 1, 2}
    };

    // Test các hàm
    MixedNumber x;
    printf("Nhap hoan so x:\n");
    inputMixedNumber(&x);

    // 1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search
    int index = linearSearch(b, x);
    if (index != -1) {
        printf("Hoan so x xuat hien tai vi tri %d trong mang b\n", index);
    }
    else {
        printf("Hoan so x khong xuat hien trong mang b\n");
    }

    // 2. Sắp xếp b sao cho các phần tử có phần nguyên chẵn lên đầu, phần tử có phần nguyên lẻ ở cuối mảng
    sortMixedNumbersByIntegerPart(b);
    printf("2. Mang b sau khi sap xep:\n");
    for (MixedNumber num : b) {
        printMixedNumber(num);
        printf(" ");
    }
    printf("\n");

    // 3. Tìm hỗn số x theo giải thuật binary search trong mảng b đã được sắp xếp tăng/giảm
    int binIndex = binarySearch(b, x, true);
    if (binIndex != -1) {
        printf("Hoan so x xuat hien tai vi tri %d trong mang b (binary search)\n", binIndex);
    }
    else {
        printf("Hoan so x khong xuat hien trong mang b (binary search)\n");
    }

    // 4. Chia mảng b thành 2 mảng s1 và s2, với s1 chứa các phần nguyên, s2 chứa phân số.
    std::vector<MixedNumber> s1, s2;
    splitMixedNumbers(b, s1, s2);
    printf("4. Mang s1 (phan nguyen):\n");
    for (MixedNumber num : s1) {
        printMixedNumber(num);
        printf(" ");
    }
    printf("\n4. Mang s2 (phan so):\n");
    for (MixedNumber num : s2) {
        printMixedNumber(num);
        printf(" ");
    }
    printf("\n");

    // 5. Xóa phần tử thứ k trong mảng b.
    int k = 2;
    deleteElement(b, k);
    printf("5. Mang b sau khi xoa phan tu thu %d:\n", k);
    for (MixedNumber num : b) {
        printMixedNumber(num);
        printf(" ");
    }
    printf("\n");

    // 6. Thêm hỗn số x vào mảng b tại vị trí k.
    insertElement(b, x, k);
    printf("6. Mang b sau khi chen hoan so x vao vi tri %d:\n", k);
    for (MixedNumber num : b) {
        printMixedNumber(num);
        printf(" ");
    }
    printf("\n");

    // 7. Tạo mảng c chứa các phần tử là phân số được đổi từ các phần tử hỗn số của mảng b.
    std::vector<int> cNumerator, cDenominator;
    createFractionArray(b, cNumerator, cDenominator);
    printf("7. Mang c (phan so):\n");
    for (size_t i = 0; i < cNumerator.size(); i++) {
        printf("%d/%d ", cNumerator[i], cDenominator[i]);
    }
    printf("\n");

    // 8. Tính tổng các phần tử của mảng b.
    sumArray(b);

    // 9. Tìm phần tử lớn nhất/nhỏ nhất của b.
    findMinMax(b);

    // 10. Xuất vị trí phần tử có phần nguyên chẵn của b.
    printEvenIntegerPositions(b);

    // 11. Xuất vị trí của phần tử lớn nhất/nhỏ nhất của b.
    printMinMaxPositions(b);

    return 0;
}
