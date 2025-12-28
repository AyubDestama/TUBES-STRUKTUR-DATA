#include <iostream>
#include "gudang.h"

using namespace std;

int main() {
    List Gudang;
    createList(Gudang);

    int pilihan;
    string catName, prodName;
    int harga, stok;

    do {
        cout << "\n=== MENU GUDANG ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Hapus Barang" << endl;
        cout << "3. Update Barang" << endl;
        cout << "4. View All (Sorted by Price)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "\n--- Tambah Barang ---" << endl;
            cout << "Masukkan Kategori: ";
            cin.ignore();
            getline(cin, catName);
            adrCategory catNode;
            catNode = findCategory(Gudang, catName);
            if (catNode == NULL) {
                catNode = createElmCategory(catName);
                insertCategory(Gudang, catNode);
            }
            cout << "Nama Barang: ";
            getline(cin, prodName);
            cout << "Harga: ";
            cin >> harga;
            cout << "Stok: ";
            cin >> stok;

            insertProductSorted(catNode, createElmProduct(prodName, harga, stok));
            cout << "Barang berhasil ditambahkan!" << endl;
            break;

        case 2:
            cout << "\n--- Hapus Barang ---" << endl;
            cout << "Masukkan Kategori: ";
            cin.ignore();
            getline(cin, catName);

            catNode = findCategory(Gudang, catName);
            if (catNode != NULL) {
                cout << "Nama Barang yang dihapus: ";
                getline(cin, prodName);
                deleteProduct(catNode, prodName);
            } else {
                cout << "Kategori tidak ditemukan." << endl;
            }
            break;

        case 3:
            cout << "\n--- Update Barang ---" << endl;
            cout << "Masukkan Kategori: ";
            cin.ignore();
            getline(cin, catName);

            catNode = findCategory(Gudang, catName);
            if (catNode != NULL) {
                cout << "Nama Barang yang diedit: ";
                getline(cin, prodName);
                updateProduct(catNode, prodName);
            } else {
                cout << "Kategori tidak ditemukan." << endl;
            }
            break;

        case 4:
            cout << "\n--- Daftar Barang Gudang ---" << endl;
            showAll(Gudang);
            break;

        case 5:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }

    } while (pilihan != 5);

return 0 ;
}
