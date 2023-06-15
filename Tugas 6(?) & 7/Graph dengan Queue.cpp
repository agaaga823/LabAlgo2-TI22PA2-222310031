#include <bits/stdc++.h> //preprocessor directive #include <bits/stdc++.h>, yang mengikutsertakan semua header file standar dari C++.
#define MAX 100005
//"Selanjutnya, ada beberapa definisi konstan yang diperlukan dalam program ini.
//MAX adalah ukuran maksimum dari array adj dan dist//
#define INF INT_MAX
// sedangkan INF adalah nilai tak terhingga yang digunakan untuk inisialisasi
// jarak awal.//
using namespace std;

vector<pair<int, int>> adj[MAX];
bool vis[MAX];
int dist[MAX];
// Dilanjutkan dengan pendefinisian variabel global adj yang merupakan
// representasi adjacency list dari graf//
void dijkstra(int start) {
  memset(vis, false,
         sizeof vis); // Variabel boolean vis digunakan untuk melacak apakah
                      // suatu node sudah dikunjungi atau belum.//
  for (int i = 0; i < MAX;
       i++) // Setiap elemen adj[i] adalah vektor pasangan integer (int) yang
            // menunjukkan node tujuan dan bobotnya dari node i.//
    dist[i] = INF; // Array dist menyimpan jarak terpendek dari node awal ke
                   // semua node lainnya.//
  dist[start] =
      0; // Fungsi ini menerima parameter start yang merupakan node awal dari
         // perhitungan jarak terpendek// Fungsi dijkstra digunakan untuk
         // menghitung jarak terpendek menggunakan algoritma Dijkstra. //
         // Pertama, semua node diinisialisasi sebagai belum dikunjungi (vis
         // diatur sebagai false) dan jarak awal dari node awal (start) diatur
         // menjadi 0, sedangkan jarak ke semua node lain diatur menjadi tak
         // terhingga (INF).//
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq; // Kemudian, digunakan priority queue (pq) untuk menyimpan pasangan
          // node dan jaraknya. Pasangan tersebut diurutkan berdasarkan jaraknya
          // dalam urutan menaik (dalam hal ini, digunakan greater<pair<int,
          // int>>).//
  pq.push({0, start});
  // Loop utama dijalankan selama pq tidak kosong. Pada setiap iterasi, pasangan
  // node dengan jarak terpendek diambil dari pq menggunakan pq.top(), dan
  // elemen tersebut dihapus dari pq dengan pq.pop().//
  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();

    int x = p.second; // Node yang diambil disimpan dalam variabel x. Jika node
                      // x sudah dikunjungi sebelumnya, maka iterasi dilewati.//
    if (vis[x])
      continue;
    vis[x] = true; // Jika node x belum dikunjungi, maka node tersebut ditandai
                   // sebagai dikunjungi (vis[x] diatur sebagai true).//

    for (int i = 0; i < adj[x].size(); i++) {
      int e =
          adj[x][i]
              .first; // Dilakukan iterasi melalui semua tetangga node x
                      // menggunakan loop for. Variabel e dan w mewakili node
                      // tujuan dan bobotnya dari node x ke tetangganya.//
      int w = adj[x][i].second;
      if (dist[x] + w < dist[e]) {
        dist[e] = dist[x] + w;
        pq.push({dist[e], e});
      }
    }
  }
}
// Jika jarak dari node start ke node x, ditambah dengan bobot w, lebih kecil
// dari jarak terpendek saat ini ke node e, maka jarak terpendek tersebut
// diperbarui dengan jarak baru. Kemudian, pasangan {dist[e], e} dimasukkan ke
// dalam pq untuk diproses selanjutnya.// Setelah loop selesai, perhitungan
// jarak terpendek selesai.//
int main() {
  // Di dalam fungsi main, dilakukan inisialisasi graf dengan menambahkan edge
  // dan bobotnya ke dalam adj.//
  adj[1].push_back({2, 3}); // Kemudian, fungsi dijkstra dipanggil dengan
                            // parameter node awal (1).//
  adj[2].push_back({1, 3});
  adj[2].push_back({3, 2});
  adj[3].push_back({2, 2});
  adj[3].push_back({4, 4});
  adj[3].push_back({5, 5});
  adj[4].push_back({3, 4});
  adj[5].push_back({3, 5});

  dijkstra(1);
  // Setelah itu, jarak terpendek dari node 1 ke node 5 dicetak menggunakan
  // cout.//
  cout << "Jarak terpendek dari node 1 ke node 5 adalah " << dist[5] << endl;

  return 0; // Program diakhiri dengan mengembalikan nilai 0.//
}