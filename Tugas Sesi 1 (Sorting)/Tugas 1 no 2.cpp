#include <iostream>
using namespace std;
int main(){
  int y;
  cout<<"masukan banyak buku:";
  cin>>y;
  string x[y];
  for(int i=0; i<y; i++){
    cout<<"masukan buku ke "<<i<<" :";
    cin>>x[i];
    cout<<endl;
    }
  for(int i=1; i<y; i++){
    string key = x[i];
    int j = i-1;
    while(j>=0 && x[j] > key){
      x[j+1] = x[j];
      j--;
      }
    x[j+1] = key;
    cout<<"Urutannya"<<endl;
    for(int m=0;m<y;m++){
      cout<<x[m]<<" ";
      }
    cout<<endl;
    }
  cout<<"hasil akhir"<<endl;
  for(int m=0;m<y;m++){
    cout<<x[m]<<" ";
    }
  }