#include <iostream>
#include <vector>
#include <limits.h> // �? s? d?ng INT_MAX v� INT_MIN
using namespace std;

void nhapMaTran(vector<vector<int>> &mat, int n) {
    cout << "Nhap cac phan tu cua ma tran:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
}

// H�m t?m gi� tr? l?n nh?t v� nh? nh?t trong ma tr?n
void timMaxMin(const vector<vector<int>> &mat, int n, int &maxVal, int &minVal) {
    maxVal = INT_MIN;
    minVal = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > maxVal) maxVal = mat[i][j];
            if (mat[i][j] < minVal) minVal = mat[i][j];
        }
    }
}

// H�m t�nh t?ng c�c ph?n t? tr�n ��?ng ch�o ch�nh
int tongDuongCheoChinh(const vector<vector<int>> &mat, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += mat[i][i];
    }
    return tong;
}

// H�m t�nh t?ng c�c ph?n t? tr�n ��?ng ch�o ph?
int tongDuongCheoPhu(const vector<vector<int>> &mat, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += mat[i][n - 1 - i];
    }
    return tong;
}

// H�m t�nh t�ch c�c ph?n t? tr�n bi�n
int tichBienTren(const vector<vector<int>> &mat, int n) {
    int tich = 1;
    for (int j = 0; j < n; j++) {
        tich *= mat[0][j];
    }
    return tich;
}

int tichBienDuoi(const vector<vector<int>> &mat, int n) {
    int tich = 1;
    for (int j = 0; j < n; j++) {
        tich *= mat[n - 1][j];
    }
    return tich;
}

int tichBienTrai(const vector<vector<int>> &mat, int n) {
    int tich = 1;
    for (int i = 0; i < n; i++) {
        tich *= mat[i][0];
    }
    return tich;
}

int tichBienPhai(const vector<vector<int>> &mat, int n) {
    int tich = 1;
    for (int i = 0; i < n; i++) {
        tich *= mat[i][n - 1];
    }
    return tich;
}

// H�m t�nh t?ng c�c ph?n t? xung quanh bi�n
int tongXungQuanhBien(const vector<vector<int>> &mat, int n) {
    int tong = 0;
    // C?ng c�c ph?n t? ? bi�n tr�n
    for (int j = 0; j < n; j++) {
        tong += mat[0][j];
    }
    // C?ng c�c ph?n t? ? bi�n d�?i
    for (int j = 0; j < n; j++) {
        tong += mat[n - 1][j];
    }
    // C?ng c�c ph?n t? ? bi�n tr�i (tr? g�c tr�n v� d�?i)
    for (int i = 1; i < n - 1; i++) {
        tong += mat[i][0];
    }
    // C?ng c�c ph?n t? ? bi�n ph?i (tr? g�c tr�n v� d�?i)
    for (int i = 1; i < n - 1; i++) {
        tong += mat[i][n - 1];
    }
    return tong;
}

int main() {
    int n;
    cout << "Nhap kich thuoc ma tran (2 <= n <= 10): ";
    cin >> n;

    if (n < 2 || n > 10) {
        cout << "Kich thuoc ma tran khong hop le!" << endl;
        return 1;
    }

    vector<vector<int>> mat(n, vector<int>(n));

    nhapMaTran(mat, n);

    int maxVal, minVal;
    timMaxMin(mat, n, maxVal, minVal);

    int tongChinh = tongDuongCheoChinh(mat, n);
    int tongPhu = tongDuongCheoPhu(mat, n);

    int tichTren = tichBienTren(mat, n);
    int tichDuoi = tichBienDuoi(mat, n);
    int tichTrai = tichBienTrai(mat, n);
    int tichPhai = tichBienPhai(mat, n);

    int tongBien = tongXungQuanhBien(mat, n);

    cout << "Max: " << maxVal << ", Min: " << minVal << endl;
    cout << "Tong duong cheo chinh: " << tongChinh << endl;
    cout << "Tong duong cheo phu: " << tongPhu << endl;
    cout << "Tich bien tren: " << tichTren << endl;
    cout << "Tich bien duoi: " << tichDuoi << endl;
    cout << "Tich bien trai: " << tichTrai << endl;
    cout << "Tich bien phai: " << tichPhai << endl;
    cout << "Tong cac phan tu xung quanh bien: " << tongBien << endl;

    return 0;
}
