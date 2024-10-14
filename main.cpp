#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Chuyển màu sang số
int colorToNumber(string color) {
    if (color == "do" || color == "đỏ") return 0;
    if (color == "trang" || color == "trắng") return 1;
    if (color == "xanh") return 2;
    return -1;
}

// Chuyển số sang màu
string numberToColor(int num) {
    switch (num) {
        case 0: return "đỏ";
        case 1: return "trắng";
        case 2: return "xanh";
        default: return "";
    }
}

// Sắp xếp theo thuật toán Dutch National Flag
void sortColors(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0: // Màu đỏ
                swap(arr[low++], arr[mid++]);
                break;
            case 1: // Màu trắng
                mid++;
                break;
            case 2: // Màu xanh
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong mau: ";
    cin >> n;

    vector<string> colors(n);
    vector<int> colorNumbers(n);

    cout << "Nhap cac mau (do, trang, xanh): ";
    for (int i = 0; i < n; i++) {
        cin >> colors[i];

        colorNumbers[i] = colorToNumber(colors[i]);
        if (colorNumbers[i] == -1) {
            cout << "Mau khong hop le, vui long nhap lai." << endl;
            return 1;
        }
    }

    sortColors(colorNumbers);

    cout << "Mau sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << numberToColor(colorNumbers[i]) << " ";
    }
    cout << endl;

    return 0;
}
