#include "customer.h"
#include "relation.h"
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
void deleteAllRelasiByCustomer(ListRelasi &LR, addressCustomer c) {
    addressRelasi R = LR.first, prec = NULL;
    while (R != NULL) {
        addressRelasi nextR = R->next;
        if (R->customer == c) {
            if (prec == NULL) LR.first = nextR;
            else prec->next = nextR;
            delete R;
        } else prec = R;
        R = nextR;
    }
}

void deleteAllRelasiByLaundry(ListRelasi &LR, addressLaundry l) {
    addressRelasi R = LR.first, prec = NULL;
    while (R != NULL) {
        addressRelasi nextR = R->next;
        if (R->laundry == l) {
            if (prec == NULL) LR.first = nextR;
            else prec->next = nextR;
            delete R;
        } else prec = R;
        R = nextR;
    }
}

void printAllRelasi(ListRelasi LR) {
    if (LR.first == NULL)
        cout << "Tidak ada relasi.\n";
    else {
        cout << "+------------------+--------------+--------------+" << endl;
        cout << "| Nama Customer    | ID Laundry   | Berat (kg)   |" << endl;
        cout << "+------------------+--------------+--------------+" << endl;
        addressRelasi R = LR.first;
        while (R != NULL) {
            cout << "| " << setw(16) << left << R->customer->info.nama
                 << " | " << setw(12) << left << R->laundry->info.idLaundry
                 << " | " << setw(12) << left << R->laundry->info.beratPakaian
                 << " |" << endl;
            R = R->next;
        }
        cout << "+------------------+--------------+--------------+" << endl;
    }
}

void printLaundryByCustomer(ListRelasi LR, addressCustomer c) {
    cout << "Pakaian laundry milik " << c->info.nama << ":\n";
    addressRelasi R = LR.first;
    bool found = false;
    while (R != NULL) {
        if (R->customer == c) {
            cout << "- ID: " << R->laundry->info.idLaundry
                 << " | Berat: " << R->laundry->info.beratPakaian << " kg" << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) cout << "Tidak ada pakaian laundry.\n";
}
