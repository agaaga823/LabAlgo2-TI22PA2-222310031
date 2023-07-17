#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
protected:
    string status;
    string nama;
    int umur;
    string jurusan;
    string fakultas;

public:
    Mahasiswa(string _nama, int _umur, string _jurusan, string _fakultas) {
        nama = _nama;
        umur = _umur;
        jurusan = _jurusan;
        fakultas = _fakultas;
    }

    virtual void displayStatus() {
        cout << "Status Mahasiswa: " << status << endl;
    }

    virtual void displayInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << " tahun" << endl;
        cout << "Jurusan: " << jurusan << endl;
        cout << "Fakultas: " << fakultas << endl;
    }
};

class Alumni : public Mahasiswa {
public:
    Alumni(string _nama, int _umur, string _jurusan, string _fakultas) : Mahasiswa(_nama, _umur, _jurusan, _fakultas) {
        status = "Alumni";
    }

    void displayStatus() override {
        cout << "Status Mahasiswa: " << status << endl;
    }
};

class MahasiswaAktif : public Mahasiswa {
public:
    MahasiswaAktif(string _nama, int _umur, string _jurusan, string _fakultas) : Mahasiswa(_nama, _umur, _jurusan, _fakultas) {
        status = "Mahasiswa Aktif";
    }

    void displayStatus() override {
        cout << "Status Mahasiswa: " << status << endl;
    }
};

int main() {
    Mahasiswa* mahasiswa1 = new Alumni("John Doe", 25, "Teknik Informatika", "Fakultas Ilmu Komputer");
    Mahasiswa* mahasiswa2 = new MahasiswaAktif("Jane Smith", 20, "Manajemen", "Fakultas Ekonomi");

    mahasiswa1->displayStatus();
    mahasiswa1->displayInfo();

    cout << endl;

    mahasiswa2->displayStatus();
    mahasiswa2->displayInfo();

    delete mahasiswa1;
    delete mahasiswa2;

    return 0;
}
