#include "laundry.h"

addressLaundry createElmListLaundry(infotypeLaundry dataLaundry) {
    addressLaundry p = new elmListLaundry;
    p->info = dataLaundry;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void deleteFirstLaundry(ListLaundry &L, addressLaundry &p) {
    if (isEmptyListLaundry(L)) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = L.last = nullptr;
        p->next = p->prev = nullptr;
    } else {
        p = L.first;
        L.first = p->next;
        L.first->prev = nullptr;
        p->next = p->prev = nullptr;
    }
}

void deleteAfterLaundry(ListLaundry &L, addressLaundry prec, addressLaundry &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        if (p->next != nullptr) {
            p->next->prev = prec;
        } else {
            L.last = prec;
        }
        p->next = p->prev = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteLastLaundry(ListLaundry &L, addressLaundry &p) {
    if (isEmptyListLaundry(L)) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = L.last = nullptr;
        p->next = p->prev = nullptr;
    } else {
        p = L.last;
        L.last = p->prev;
        L.last->next = nullptr;
        p->next = p->prev = nullptr;
    }
}

addressLaundry searchLaundryByID(ListLaundry L, string idLaundry) {
    addressLaundry p = L.first;
    while (p != nullptr && p->info.idLaundry != idLaundry) {
        p = p->next;
    }
    return p;
}

bool cekDuplikatDataLaundry(ListLaundry L, string idLaundry) {
    return searchLaundryByID(L, idLaundry) != nullptr;
}
