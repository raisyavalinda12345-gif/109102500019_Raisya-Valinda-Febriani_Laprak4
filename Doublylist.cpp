/* file : Doublylist.cpp */
#include "Doublylist.h"

/* I.S. sembarang
   F.S. List kosong (First = Last = Nil) */
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

/* Mengalokasikan elemen baru berisi x, next dan prev = Nil */
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

/* Membebaskan memori elemen P */
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

/* Menampilkan isi list dari Last ke First (mundur lewat prev),
   sesuai contoh output Gambar 6-23 */
void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

/* Menyisipkan P di akhir list */
void insertLast(List &L, address P) {
    if (L.First == Nil) {              // list kosong
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

/* Mencari elemen berdasarkan nopol, Nil jika tidak ada */
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

/* Melepas elemen pertama, disimpan di P */
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;
    if (L.First == L.Last) {           // hanya satu elemen
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

/* Melepas elemen terakhir, disimpan di P */
void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;
    if (L.First == L.Last) {           // hanya satu elemen
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

/* Melepas elemen setelah Prec, disimpan di P */
void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    if (P == Nil) return;
    Prec->next = P->next;
    if (P->next != Nil) {
        P->next->prev = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}