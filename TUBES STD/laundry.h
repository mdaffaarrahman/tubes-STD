#ifndef LAUNDRY_H_INCLUDED
#define LAUNDRY_H_INCLUDED

#include <iostream>
using namespace std;

struct laundry {
    string idLaundry;
    float beratPakaian;
};

typedef struct laundry infotypeLaundry;
typedef struct elmListLaundry *addressLaundry;
struct elmListLaundry {
    infotypeLaundry info;
    addressLaundry next;
    addressLaundry prev;
};

struct ListLaundry {
    addressLaundry first;
    addressLaundry last;
};

void createListLaundry(ListLaundry &L);
addressLaundry createElmListLaundry(infotypeLaundry dataLaundry);
bool isEmptyListLaundry(ListLaundry L);
void insertFirstLaundryListLaundry &L, addressLaundry p);
void insertAfterLaundry(ListLaundry &L, addressLaundry prec, addressLaundry p);
void insertLastLaundry(ListLaundry &L, addressLaundry p);
void deleteFirstLaundry(ListLaundry &L, addressLaundry &p);
void deleteAfterLaundry(ListLaundry &L, addressLaundry prec, addressLaundry &p);
void deleteLastLaundry(ListLaundry &L, addressLaundry &p);
addressLaundry searchLaundryByID(ListLaundry L, string idLaundry);
bool cekDuplikatDataLaundry(ListLaundry L, string idLaundry);
void printInfoLaundry(addressLaundry p);
void printDataLaundry(ListLaundry L);

#endif
