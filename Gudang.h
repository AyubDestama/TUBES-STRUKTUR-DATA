#ifndef GUDANG_H_INCLUDED
#define GUDANG_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

   //STRUCT PRODUCT Double Linked List
struct Product {
    string nama;
    int harga;
    int stok;
};

typedef struct ElmProduct* adrProduct;

struct ElmProduct {
    Product info;
    adrProduct next;
    adrProduct prev;
};

   //STRUCT CATEGORY Single Linked List
typedef struct ElmCategory* adrCategory;

struct ElmCategory {
    string catName;
    adrCategory next;
    adrProduct child;
};

   //LIST
struct List {
    adrCategory first;
};

   //FUNCTION PROTOTYPE

void createList(List &L);

adrCategory createElmCategory(string catName);
adrProduct createElmProduct(string nama, int harga, int stok);

void insertCategory(List &L, adrCategory P);
adrCategory findCategory(List L, string catName);

void insertProductSorted(adrCategory P, adrProduct C);
void deleteProduct(adrCategory P, string namaProduk);
void updateProduct(adrCategory P, string namaProduk);

void showAll(List L);

#endif
