#include <iostream>
#include <string>
#include <limits> // Tambahkan library ini untuk numeric_limits
#include "Gudang.h"

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
        cout << "4. View All" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";

        // --- PERBAIKAN 1: Validasi Input Pilihan Menu ---
        if (!(cin >> pilihan)) {
            cout << "Input harus angka!" << endl;
            cin.clear(); // Hapus flag error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer
            pilihan = 0; // Set pilihan ke default agar tidak exit/salah case
            continue; // Ulangi loop
        }

        switch (pilihan) {
        case 1: {
            cout << "Kategori: ";
            // Gunakan ignore yg lebih kuat untuk memastikan buffer bersih
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, catName);

            adrCategory C = findCategory(Gudang, catName);
            if (C == nullptr) {
                C = createElmCategory(catName);
                insertCategory(Gudang, C);
            }

            cout << "Nama Barang: ";
            // Tidak perlu cin.ignore() di sini karena getline sebelumnya sudah makan enter
            getline(cin, prodName);

            cout << "Harga: ";
            cin >> harga;

            // --- PERBAIKAN 2: Validasi Harga ---
            while(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Harga harus angka! Masukkan ulang Harga: ";
                cin >> harga;
            }

            cout << "Stok: ";
            cin >> stok;

            // --- PERBAIKAN 3: Validasi Stok ---
            while(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Stok harus angka! Masukkan ulang Stok: ";
                cin >> stok;
            }

            insertProductSorted(C, createElmProduct(prodName, harga, stok));
            break;
        }

        case 2:
            cout << "Kategori: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, catName);
            if (findCategory(Gudang, catName) != nullptr) {
                cout << "Nama Barang: ";
                getline(cin, prodName);
                deleteProduct(findCategory(Gudang, catName), prodName);
            }
            break;

        case 3:
            cout << "Kategori: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, catName);
            cout << "Nama Barang: ";
            getline(cin, prodName);
            updateProduct(findCategory(Gudang, catName), prodName);
            break;

        case 4:
            showAll(Gudang);
            break;
        }

    } while (pilihan != 5);

    return 0;
}
