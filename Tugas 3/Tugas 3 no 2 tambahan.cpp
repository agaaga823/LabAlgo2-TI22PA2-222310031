#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi binary search
int binarySearch(vector<string> arr, string x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    // Daftar rak buku
    vector<string> Selingkuh = {"Aku", "Kamu", "Dia"};
    vector<string> Sopan = {"Saya", "Anda", "Kalian"};
    vector<string> Kecewa = {"Usai", "Tidak Cinta", "Hancur Lebur"};
    vector<string> Cinta = {"Kisah Kita", "Penyesalan", "Akhir Semua Ini"};
    vector<string> Usaha = {"Sakit", "Melawan Restu", "Mantan"};
    vector<string> rak[] = {Selingkuh, Sopan, Kecewa, Cinta, Usaha};

    // Input judul buku yang ingin dicari
    string judulBuku;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, judulBuku);
    int posisiRak = -1;

    for (int i = 0; i < 5; i++) {
        int posisi = binarySearch(rak[i], judulBuku);
        if (posisi != -1) {
            posisiRak = i;
            break;
        }
    }

    if (posisiRak == -1)
        cout << "Buku tidak ditemukan di perpustakaan." << endl;
    else
        cout << "Buku ditemukan di rak " << posisiRak << rak << endl;

    return 0;
}