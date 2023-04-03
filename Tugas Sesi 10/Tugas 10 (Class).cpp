#include <iostream>
using namespace std;
class Perpustakaan {

private:
string peminjam;
string buku;
string x,y;

public:
void setPeminjam(string peminjam1){
  peminjam = peminjam1;
}
void setBuku (string buku1){
  buku = buku1;
}
string getPeminjam(){
  return peminjam;
}
string getBuku(){
  return buku;
}
};

int main(){
Perpustakaan perpus;
  string x,y;

cout << "Nama = ";
  cin >> x;
cout << "Judul buku yang dipinjam = ";
  cin >> y;
  
  perpus.setPeminjam(x);
  perpus.setBuku(y);
  cout << perpus.getPeminjam() << " meminjam Buku yang berjudul " << perpus.getBuku() << endl;
  return 0;
}