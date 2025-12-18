#include "customer.h"

void createListCustomer(ListCustomer &L) {
    L.first = nullptr;
}

bool isEmptyListCustomer(ListCustomer L) {
    return L.first == nullptr;
}

void insertFirstCustomer(ListCustomer &L, addressCustomer p) {
    p->next = L.first;
    L.first = p;
}

void insertAfterCustomer(ListCustomer &L, addressCustomer prec, addressCustomer p) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void insertLastCustomer(ListCustomer &L, addressCustomer p) {
    if (isEmptyListCustomer(L)) {
        L.first = p;
    } else {
        addressCustomer q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
    p->next = nullptr;
}

void printInfoCustomer(addressCustomer p) {
    if (p != nullptr) {
        cout << "ID Customer : " << p->info.idCustomer << endl;
        cout << "Nama        : " << p->info.nama << endl;
        cout << "No Telpon   : " << p->info.noTelepon << endl;
        cout << "Alamat      : " << p->info.alamat << endl;
    }
}

void printDataCustomer(ListCustomer L) {
    addressCustomer p = L.first;
    while (p != nullptr) {
        cout << "-------------------------" << endl;
        printInfoCustomer(p);
        p = p->next;
    }
}


