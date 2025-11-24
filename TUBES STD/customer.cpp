#include "customer.h"
#include <iomanip>

void createListCustomer(ListCustomer &L) {
    L.first = NULL;
}

addressCustomer createElmListCustomer(infotypeCustomer dataCustomer) {
    addressCustomer p = new elmListCustomer;
    p->info = dataCustomer;
    p->next = NULL;
    return p;
}

bool isEmptyListCustomer(ListCustomer L) {
    return L.first == NULL;
}

void insertLastCustomer(ListCustomer &L, addressCustomer p) {
    if (isEmptyListCustomer(L)) {
        L.first = p;
    } else {
        addressCustomer q = L.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

void deleteFirstCustomer(ListCustomer &L, addressCustomer &p) {
    if (!isEmptyListCustomer(L)) {
        p = L.first;
        L.first = p->next;
        p->next = NULL;
    }
}

void deleteAfterCustomer(ListCustomer &L, addressCustomer prec, addressCustomer &p) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}

addressCustomer searchCustomerByID(ListCustomer L, string idCustomer) {
    addressCustomer p = L.first;
    while (p != NULL) {
        if (p->info.idCustomer == idCustomer)
            return p;
        p = p->next;
    }
    return NULL;
}

bool cekDuplikatDataCustomer(ListCustomer L, string idCustomer) {
    addressCustomer p = L.first;
    while (p != NULL) {
        if (p->info.idCustomer == idCustomer)
            return true;
        p = p->next;
    }
    return false;
}

void printInfoCustomer(addressCustomer p) {
    if (p != NULL) {
        cout << "| " << setw(12) << left << p->info.idCustomer
             << " | " << setw(16) << left << p->info.nama << " |" << endl;
    }
}

void printDataCustomer(ListCustomer L) {
    addressCustomer p = L.first;
    cout << "+--------------+------------------+" << endl;
    cout << "| ID Customer  | Nama Customer    |" << endl;
    cout << "+--------------+------------------+" << endl;
    while (p != NULL) {
        printInfoCustomer(p);
        p = p->next;
    }
    cout << "+--------------+------------------+" << endl;
}
