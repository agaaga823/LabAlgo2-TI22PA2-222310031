#include <iostream>
using namespace std;

int main() {
  int Input[] = {0, 6, 12, 18, 24};
  int jumlah = sizeof(Input)/sizeof(Input[0]);
  int dataDicari, tm = 0, R = jumlah-1, L = 0, Mid;

  // Input data yang dicari
  cout << "Masukkan data yang dicari: ";
  cin >> dataDicari;

  while (R >= L) {
    Mid = (L+R)/2;
    if (Input[Mid] == dataDicari) {
      cout << "Bilangan Ditemukan" << endl;
      return 0;
    } else if (Input[Mid] < dataDicari) {
      L = Mid+1;
    } else {
      R = Mid-1;
    }
  }

  cout << "Bilangan Tidak Ditemukan" << endl;
  return 0;
}