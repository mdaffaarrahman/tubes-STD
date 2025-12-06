#include "laundry.h"

void createListLaundry(ListLaundry &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyListLaundry(ListLaundry L) {
    return L.first == nullptr;
}

void insertFirstLaundry(ListLaundry &L, addressLaundry p) {
    if (isEmptyListLaundry(L)) {
        L.first = L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertAfterLaundry(ListLaundry &L, addressLaundry prec, addressLaundry p) {
    if (prec != nullptr) {
        p->next = prec->next;
        p->prev = prec;
        if (prec->next != nullptr) {
            prec->next->prev = p;
        } else {
            L.last = p;
        }
        prec->next = p;
    }
}

void insertLastLaundry(ListLaundry &L, addressLaundry p) {
    if (isEmptyListLaundry(L)) {
        L.first = L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void printInfoLaundry(addressLaundry p) {
    if (p != nullptr) {
        cout << "ID Laundry     : " << p->info.idLaundry << endl;
        cout << "Berat Pakaian  : " << p->info.beratPakaian << " kg" << endl;
    }
}

void printDataLaundry(ListLaundry L) {
    addressLaundry p = L.first;
    while (p != nullptr) {
        cout << "-------------------------" << endl;
        printInfoLaundry(p);
        p = p->next;
    }
}
