#include <iostream>
#include <queue>
#include <vector>
// Program dimulai dengan inklusi beberapa header file yang diperlukan, yaitu
// iostream, vector, dan queue.//
#define M 1000
// Kemudian, ada definisi konstan M yang merepresentasikan nilai tak terhingga
// dalam graf.//
using namespace std;

const int N = 5; // Variabel global N didefinisikan sebagai ukuran graf.//

void dijkstra(int graph[N][N], int source, int destination) {
  vector<pair<int, int>>
      adj[N]; // Fungsi dijkstra digunakan untuk menghitung lintasan terpendek
              // menggunakan algoritma Dijkstra. Fungsi ini menerima parameter
              // graph yang merupakan representasi matriks adjacency dari graf,
              // source yang merupakan node asal, dan destination yang merupakan
              // node tujuan.//
  // Di dalam fungsi dijkstra, terdapat inisialisasi vektor adj yang
  // merepresentasikan adjacency list dari graf berdasarkan matriks adjacency
  // graph.//
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (graph[i][j] != M) {
        adj[i].push_back(make_pair(j, graph[i][j]));
      }
    }
  } // Selanjutnya, array Q dan R diinisialisasi. Array Q menyimpan jarak
    // terpendek dari node asal ke semua node lainnya, sedangkan array R
    // menyimpan node sebelumnya dalam lintasan terpendek.//
  int Q[N], R[N];
  for (int i = 0; i < N; i++) {
    Q[i] = M;
    R[i] = -1;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq; // Digunakan priority queue pq untuk menyimpan pasangan node dan
          // jaraknya. Pasangan tersebut diurutkan berdasarkan jaraknya dalam
          // urutan menaik (dalam hal ini, digunakan greater<pair<int, int>>).//
  pq.push(make_pair(
      0,
      source - 1)); // Node asal dimasukkan ke dalam pq dengan jarak awal 0.//
  Q[source - 1] = 0;
  while (!pq.empty()) { // Selama pq tidak kosong, node dengan jarak terpendek
                        // diambil dari pq menggunakan pq.top(), dan elemen
                        // tersebut dihapus dari pq dengan pq.pop().//
    int u = pq.top().second;
    pq.pop();
    // Untuk setiap tetangga node yang diambil, jarak dari node asal ke tetangga
    // tersebut diperbarui jika jarak baru lebih kecil dari jarak sebelumnya.//
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      int w = adj[u][i].second;
      if (Q[v] > Q[u] + w) {
        pq.push(make_pair(Q[v], v));
      }
    }
  }
  cout << "Beban = "; // Setelah perhitungan jarak terpendek selesai,
                      // nilai-nilai dalam array Q dan R dicetak.//
  for (int i = 0; i < N; i++) {
    cout << Q[i] << " ";
  }
  cout << endl;
  cout << "Rute = ";
  for (int i = 0; i < N; i++) {
    cout << R[i] << " ";
  }
  cout << endl;
}

int main() { // Di dalam fungsi main, graf diinisialisasi menggunakan matriks
             // adjacency graph.//
  int graph[N][N] = {{0, 1, 3, M, M},
                     {M, 0, 1, M, 5},
                     {3, M, 0, 2, M},
                     {M, M, M, 0, 1},
                     {M, M, M, M, 0}};
  int source, destination;
  cout << "Masukkan node asal: "; // Pengguna diminta untuk memasukkan node asal
                                  // dan node tujuan.//
  cin >> source;
  cout << "Masukkan node tujuan : ";
  cin >> destination;

  dijkstra(
      graph, source,
      destination); // Fungsi dijkstra dipanggil dengan parameter yang sesuai.//
  return 0;         // Program diakhiri dengan mengembalikan nilai 0.//
}