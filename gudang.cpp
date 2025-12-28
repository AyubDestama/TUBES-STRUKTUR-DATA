#include "gudang.h"
void createList(List &L) {
    L.first = NULL;
}

adrCategory createElmCategory(string catName) {
    adrCategory P = new ElmCategory;
    P->catName = catName;
    P->next = NULL;
    P->child = NULL;
    return P;
}

adrProduct createElmProduct(string nama, int harga, int stok) {
    adrProduct P = new ElmProduct;
    P->info.nama = nama;
    P->info.harga = harga;
    P->info.stok = stok;
    P->next = NULL;
    return P;
}

void insertCategory(List &L, adrCategory P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrCategory Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrCategory findCategory(List L, string catName) {
    adrCategory P = L.first;
    while (P != NULL) {
        if (P->catName == catName) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void insertProductSorted(adrCategory P, adrProduct C) {
    if (P->child == NULL || C->info.harga < P->child->info.harga) {
        C->next = P->child;
        P->child = C;
    } else {
        adrProduct Q = P->child;
        while (Q->next != NULL && Q->next->info.harga < C->info.harga) {
            Q = Q->next;
        }
        C->next = Q->next;
        Q->next = C;
    }
}

void deleteProduct(adrCategory P, string namaProduk) {
    if (P->child == NULL) {
        cout << "Barang tidak ditemukan di kategori ini." << endl;
        return;
    }

    adrProduct Q = P->child;
    adrProduct temp;

    if (Q->info.nama == namaProduk) {
        P->child = Q->next;
        delete Q;
        cout << "Barang berhasil dihapus." << endl;
    } else {
        while (Q->next != NULL && Q->next->info.nama != namaProduk) {
            Q = Q->next;
        }

        if (Q->next != NULL) {
            temp = Q->next;
            Q->next = temp->next;
            delete temp;
            cout << "Barang berhasil dihapus." << endl;
        } else {
            cout << "Barang tidak ditemukan." << endl;
        }
    }
}

void updateProduct(adrCategory P, string namaProduk) {
    adrProduct Q = P->child;
    while (Q != NULL) {
        if (Q->info.nama == namaProduk) {
            cout << "Barang ditemukan! Masukkan data baru." << endl;
            cout << "Masukkan Stok Baru: ";
            cin >> Q->info.stok;
            int hargaBaru;
            cout << "Masukkan Harga Baru: ";
            cin >> hargaBaru;
            int stokBaru = Q->info.stok;
            string n = Q->info.nama;
            Q->info.harga = hargaBaru;
            cout << "Data berhasil diupdate (Catatan: Urutan harga diperbarui saat view berikutnya jika menggunakan re-sort logic)." << endl;
            return;
        }
        Q = Q->next;
    }
    cout << "Barang tidak ditemukan." << endl;
}

void showAll(List &L) {
    if (L.first == NULL) {
        cout << "Gudang Kosong." << endl;
        return;
    }

    adrCategory P = L.first;
    while (P != NULL) {
        cout << "-----------------------------------" << endl;
        cout << "Kategori: " << P->catName << endl;
        cout << "-----------------------------------" << endl;

        adrProduct Q = P->child;
        if (Q == NULL) {
            cout << "  (Tidak ada barang)" << endl;
        } else {
            int i = 1;
            while (Q != NULL) {
                cout << "  " << i << ". " << Q->info.nama
                     << " | Harga: Rp" << Q->info.harga
                     << " | Stok: " << Q->info.stok << endl;
                Q = Q->next;
                i++;
            }
        }
        P = P->next;
    }
    cout << "-----------------------------------" << endl;
}
