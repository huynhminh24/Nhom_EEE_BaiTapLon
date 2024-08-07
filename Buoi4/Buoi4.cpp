#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Câu 1: Hàm kiểm tra chuỗi có chứa toàn ký số hay không
int cau1(char* s) {
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

// Câu 2: Hàm đổi ký tự đầu tiên của mỗi từ thành chữ in hoa và các ký tự còn lại thành chữ thường
void cau2(char* s) {
    int capitalize = 1;
    while (*s) {
        if (isspace(*s)) {
            capitalize = 1;
        }
        else if (capitalize && isalpha(*s)) {
            *s = toupper(*s);
            capitalize = 0;
        }
        else {
            *s = tolower(*s);
        }
        s++;
    }
}

// Câu 3: Hàm xóa khoảng trắng thừa trong chuỗi
void cau3(char* s) {
    char* d = s;
    int space = 0;
    while (*s) {
        if (!isspace(*s)) {
            if (space) {
                *d++ = ' ';
                space = 0;
            }
            *d++ = *s;
        }
        else {
            space = 1;
        }
        s++;
    }
    *d = '\0';
}

// Câu 4: Hàm tìm kiếm tên trong chuỗi họ tên
void cau4(char* fullName, char* name) {
    char* found = strstr(fullName, name);
    if (found) {
        printf("Ten '%s' ton tai trong chuoi ho ten '%s'.\n", name, fullName);
    }
    else {
        printf("Ten '%s' khong ton tai trong chuoi ho ten.\n", name);
    }
}

// Câu 5: Hàm cắt chuỗi họ tên thành họ lót và tên
void cau5(char* fullName, char* firstName, char* lastName) {
    char* lastSpace = strrchr(fullName, ' ');
    if (lastSpace) {
        strncpy_s(firstName, lastSpace - fullName + 1, fullName, lastSpace - fullName);
        firstName[lastSpace - fullName] = '\0';
        strcpy_s(lastName, strlen(lastSpace + 1) + 1, lastSpace + 1);
    }
    else {
        strcpy_s(firstName, 1, "");
        strcpy_s(lastName, strlen(fullName) + 1, fullName);
    }
}

// Câu 6: Nhập vào danh sách sinh viên và tìm kiếm chuỗi trong T
void cau6() {
    char T[100], P[50];
    printf("Nhap chuoi T: ");
    fgets(T, sizeof(T), stdin);
    T[strcspn(T, "\n")] = '\0';
    printf("Nhap chuoi P: ");
    fgets(P, sizeof(P), stdin);
    P[strcspn(P, "\n")] = '\0';

    char* found = strstr(T, P);
    if (found) {
        printf("Chuoi P tim thay tai vi tri: %ld\n", found - T);
    }
    else {
        printf("Chuoi P khong ton tai trong T.\n");
    }
}

// Câu 7: Kiểm tra chuỗi đối xứng
int cau7(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return 0;
    }
    return 1;
}

// Câu 8: Tìm vị trí xuất hiện của chuỗi s2 trong s1
void cau8(char* s1, char* s2) {
    char* found = strstr(s1, s2);
    if (found) {
        printf("Chuoi s2 xuat hien tai vi tri: %ld\n", found - s1);
    }
    else {
        strcat_s(s1, sizeof(s1), s2);
        printf("Chuoi s2 khong co trong s1. Chuoi s1 sau khi noi: %s\n", s1);
    }
}

// Câu 9: Chèn chuỗi strInsert vào str tại vị trí vt
void cau9(char* str, char* strInsert, int vt) {
    char result[200];
    strncpy_s(result, sizeof(result), str, vt);
    result[vt] = '\0';
    strcat_s(result, sizeof(result), strInsert);
    strcat_s(result, sizeof(result), str + vt);
    printf("Chuoi sau khi chen: %s\n", result);
}

// Câu 10: Xóa tất cả các ký tự k trong chuỗi
void cau10(char* str, char k) {
    char* read = str, * write = str;
    while (*read) {
        if (*read != k) {
            *write = *read;
            write++;
        }
        read++;
    }
    *write = '\0';
    printf("Chuoi sau khi xoa: %s\n", str);
}

// Câu 11: Tìm các chuỗi chứa toàn ký tự số trong mảng
void cau11(char arr[][50], int n) {
    for (int i = 0; i < n; i++) {
        if (cau1(arr[i])) {
            printf("Chuoi toan ky tu so: %s\n", arr[i]);
        }
    }
}

// Hàm dừng màn hình
void pause() {
    printf("Nhan phim bat ky de tiep tuc...");
    getchar();
    getchar();
}

// Hàm hiển thị menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Kiem tra chuoi co chua toan ky so\n");
    printf("2. Doi ky tu dau tien cua moi tu thanh chu in hoa\n");
    printf("3. Xoa khoang trang thua trong chuoi\n");
    printf("4. Tim kiem ten trong chuoi ho ten\n");
    printf("5. Cat chuoi ho ten thanh ho lot va ten\n");
    printf("6. Nhap danh sach sinh vien va tim kiem chuoi\n");
    printf("7. Kiem tra chuoi doi xung\n");
    printf("8. Tim vi tri xuat hien cua chuoi s2 trong s1\n");
    printf("9. Chen chuoi vao chuoi tai vi tri vt\n");
    printf("10. Xoa ky tu trong chuoi\n");
    printf("11. Tim chuoi toan ky tu so\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int choice;
    char str[100], str2[50], firstName[50], lastName[50];
    int vt, n;
    char arr[10][50];

    do {
        displayMenu();
        scanf_s("%d", &choice);
        getchar(); 

        switch (choice) {
        case 1:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            if (cau1(str)) {
                printf("Chuoi chua toan ky so.\n");
            }
            else {
                printf("Chuoi khong chua toan ky so.\n");
            }
            pause();
            break;

        case 2:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            cau2(str);
            printf("Chuoi sau khi doi: %s\n", str);
            pause();
            break;

        case 3:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            cau3(str);
            printf("Chuoi sau khi xoa khoang trang thua: %s\n", str);
            pause();
            break;

        case 4:
            printf("Nhap ho ten: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Nhap ten can tim: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            cau4(str, str2);
            pause();
            break;

        case 5:
            printf("Nhap ho ten: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            cau5(str, firstName, lastName);
            printf("Ho lot: %s\n", firstName);
            printf("Ten: %s\n", lastName);
            pause();
            break;

        case 6:
            cau6();
            pause();
            break;

        case 7:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            if (cau7(str)) {
                printf("Chuoi doi xung.\n");
            }
            else {
                printf("Chuoi khong doi xung.\n");
            }
            pause();
            break;

        case 8:
            printf("Nhap chuoi s1: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Nhap chuoi s2: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            cau8(str, str2);
            pause();
            break;

        case 9:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Nhap chuoi can chen: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            printf("Nhap vi tri can chen: ");
            scanf_s("%d", &vt);
            getchar();
            cau9(str, str2, vt);
            pause();
            break;

        case 10:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            char k;
            printf("Nhap ky tu can xoa: ");
            k = getchar();
            cau10(str, k);
            pause();
            break;

        case 11:
            printf("Nhap so luong chuoi: ");
            scanf_s("%d", &n);
            getchar();
            for (int i = 0; i < n; i++) {
                printf("Nhap chuoi thu %d: ", i + 1);
                fgets(arr[i], sizeof(arr[i]), stdin);
                arr[i][strcspn(arr[i], "\n")] = '\0';
            }
            cau11(arr, n);
            pause();
            break;

        case 0:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le.\n");
            pause();
            break;
        }
    } while (choice != 0);

    return 0;
}
