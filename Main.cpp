/* file : main.cpp */
#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P, D;

    CreateList(L);

    /* ===== Soal 1 : input 4 data kendaraan ===== */
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    /* ===== Soal 2 : cari elemen dengan findElm ===== */
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> x.nopol;
    cout << endl;
    P = findElm(L, x);
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << endl;

    /* ===== Soal 3 : hapus elemen berdasarkan nopol ===== */
    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    } else {
        if (P == L.First) {
            deleteFirst(L, D);
        } else if (P == L.Last) {
            deleteLast(L, D);
        } else {
            deleteAfter(P->prev, D);
        }
        dealokasi(D);
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
    }

    cout << endl << "DATA LIST 1" << endl << endl;
    P = L.Last;                        // cetak format Gambar 6-25
    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->prev;
    }

    /* bersihkan memori */
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    return 0;
}