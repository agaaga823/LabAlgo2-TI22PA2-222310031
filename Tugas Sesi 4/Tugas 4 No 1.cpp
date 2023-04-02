#include <iostream>
using namespace std;

const int MAX = 100;
int queue[MAX];
int front = -1;
int rear = -1; 

bool isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(int data){
    if (rear == MAX - 1){
        cout << "Antrian penuh!" << endl;
    } else if (isEmpty()) {
        front = rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
      rear == -1;
}
  front = (front)%MAX;
  front++;
}
int peek(){
  if(isEmpty() <= 0){
    cout << "Antrian Kosong" << endl;
    return-1;
  }
  return front;
}

void displayQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "Isi antrian: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
  int choice, data;
  
  cout << "LOKET TIKET" << endl;
  do {
    cout << "\nMenu: " << endl;
    cout << "1. Masukkan antrian" << endl;
    cout << "2. Hapus dari antrian" << endl;
    cout << "3. Tampilkan isi antrian" << endl;
    cout << "4. Keluar" << endl;
    awal:
    cout << "\nPilih: ";
    cin >> choice;
    
    switch (choice) {
      case 1:
        cout << "Masukkan nomor tiket: ";
        cin >> data;
        enqueue(data);
        break;
      case 2:
        cout << "Antrian : ";
        cin >> data;
        cout << "Bayar Tiket Sukses. Hapus dari antrian"<<endl;
            dequeue();
        break;
      case 3:
        displayQueue();
        break;
      case 4:
        cout << "Program selesai." << endl;
        goto akhir;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
        break;
    }
    goto awal;
  } while (choice != 4);
  akhir:
  return 0;
}