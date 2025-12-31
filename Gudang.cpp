#include "Gudang.h"

    //LIST
void createList(List &L) {
    L.first = nullptr;
}

   //CREATE ELEMENT
adrCategory createElmCategory(string catName) {
    adrCategory P = new ElmCategory;
    P->catName = catName;
    P->next = nullptr;
    P->child = nullptr;
    return P;
}

adrProduct createElmProduct(string nama, int harga, int stok) {
    adrProduct P = new ElmProduct;
    P->info.nama = nama;
    P->info.harga = harga;
    P->info.stok = stok;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

   //CATEGORY (SINGLE LL)
void insertCategory(List &L, adrCategory P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrCategory Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrCategory findCategory(List L, string catName) {
    adrCategory P = L.first;
    while (P != nullptr) {
        if (P->catName == catName) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

  // PRODUCT (DOUBLE LL) SORT BY PRICE
void insertProductSorted(adrCategory P, adrProduct C) {
    if (P->child == nullptr) {
        P->child = C;
    }
    else if (C->info.harga < P->child->info.harga) {
        C->next = P->child;
        P->child->prev = C;
        P->child = C;
    }
    else {
        adrProduct Q = P->child;
        while (Q->next != nullptr && Q->next->info.harga < C->info.harga) {
            Q = Q->next;
        }
        C->next = Q->next;
        C->prev = Q;
        if (Q->next != nullptr) {
            Q->next->prev = C;
        }
        Q->next = C;
    }
}

/* =====================
   DELETE PRODUCT
   ===================== */
void deleteProduct(adrCategory P, string namaProduk) {
    adrProduct Q = P->child;

    while (Q != nullptr && Q->info.nama != namaProduk) {
        Q = Q->next;
    }

    if (Q == nullptr) {
        cout << "Barang tidak ditemukan." << endl;
        return;
    }

    if (Q->prev != nullptr) {
        Q->prev->next = Q->next;
    } else {
        P->child = Q->next;
    }

    if (Q->next != nullptr) {
        Q->next->prev = Q->prev;
    }

    delete Q;
    cout << "Barang berhasil dihapus." << endl;
}

/* =====================
   UPDATE PRODUCT
   ===================== */
void updateProduct(adrCategory P, string namaProduk) {
    adrProduct Q = P->child;

    while (Q != nullptr) {
        if (Q->info.nama == namaProduk) {
            cout << "Masukkan stok baru: ";
            cin >> Q->info.stok;
            cout << "Masukkan harga baru: ";
            cin >> Q->info.harga;
            cout << "Data berhasil diupdate." << endl;
            return;
        }
        Q = Q->next;
    }
    cout << "Barang tidak ditemukan." << endl;
}

   //SHOW ALL
void showAll(List L) {
    adrCategory P = L.first;

    if (P == nullptr) {
        cout << "Gudang kosong." << endl;
        return;
    }

    while (P != nullptr) {
        cout << "\nKategori: " << P->catName << endl;
        adrProduct Q = P->child;
        int i = 1;

        while (Q != nullptr) {
            cout << i++ << ". "
                 << Q->info.nama
                 << " | Harga: " << Q->info.harga
                 << " | Stok: " << Q->info.stok << endl;
            Q = Q->next;
        }
        P = P->next;
    }
}
