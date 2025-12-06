#include "customer.h"

addressCustomer createElmListCustomer(infotypeCustomer dataCustomer) {
    addressCustomer p = new elmListCustomer;
    p->info = dataCustomer;
    p->next = nullptr;
    return p;
}

void deleteFirstCustomer(ListCustomer &L, addressCustomer &p) {
    if (!isEmptyListCustomer(L)) {
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteAfterCustomer(ListCustomer &L, addressCustomer prec, addressCustomer &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}

void deleteLastCustomer(ListCustomer &L, addressCustomer &p) {
    if (isEmptyListCustomer(L)) {
        p = nullptr;
    } else if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        addressCustomer q = L.first;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

addressCustomer searchCustomerByID(ListCustomer L, string idCustomer) {
    addressCustomer p = L.first;
    while (p != nullptr && p->info.idCustomer != idCustomer) {
        p = p->next;
    }
    return p;
}

bool cekDuplikatDataCustomer(ListCustomer L, string idCustomer) {
    return searchCustomerByID(L, idCustomer) != nullptr;
}
