#include "laundry.h"
#include "relation.h"
#include <iomanip>

void createListLaundry(ListLaundry &L) {
    L.first = NULL;
    L.last = NULL;
}

addressLaundry createElmListLaundry(infotypeLaundry dataLaundry) {
    addressLaundry p = new elmListLaundry;
    p->info = dataLaundry;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

bool isEmptyListLaundry(ListLaundry L) {
    return L.first == NULL;
}

void insertLastLaundry(ListLaundry &L, addressLaundry p) {
    if (isEmptyListLaundry(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void deleteFirstLaundry(ListLaundry &L, addressLaundry &p) {
    if (!isEmptyListLaundry(L)) {
        p = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = p->next;
            L.first->prev = NULL;
            p->next = NULL;
        }
    }
}

void deleteAfterLaundry(ListLaundry &L, addressLaundry prec, addressLaundry &p) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        if (p->next != NULL)
            p->next->prev = prec;
        else
            L.last = prec;
        p->next = NULL;
        p->prev = NULL;
    }
}

void deleteLastLaundry(ListLaundry &L, addressLaundry &p) {
    if (!isEmptyListLaundry(L)) {
        p = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = p->prev;
            L.last->next = NULL;
            p->prev = NULL;
        }
    }
}

addressLaundry searchLaundryByID(ListLaundry L, string idLaundry) {
    addressLaundry p = L.first;
    while (p != NULL) {
        if (p->info.idLaundry == idLaundry)
            return p;
        p = p->next;
    }
    return NULL;
}

bool cekDuplikatDataLaundry(ListLaundry L, string idLaundry) {
    addressLaundry p = L.first;
    while (p != NULL) {
        if (p->info.idLaundry == idLaundry)
            return true;
        p = p->next;
    }
    return false;
}

void printInfoLaundry(addressLaundry p) {
    if (p != NULL) {
        cout << "| " << setw(10) << left << p->info.idLaundry
             << " | " << setw(12) << left << p->info.beratPakaian << " |" << endl;
    }
}

void printDataLaundry(ListLaundry L) {
    addressLaundry p = L.first;
    cout << "+------------+--------------+" << endl;
    cout << "| ID Laundry | Berat (kg)   |" << endl;
    cout << "+------------+--------------+" << endl;
    while (p != NULL) {
        cout << "| " << setw(10) << left << p->info.idLaundry
             << " | " << setw(12) << left << p->info.beratPakaian << " |" << endl;
        p = p->next;
    }
    cout << "+------------+--------------+" << endl;
}


void createListRelasi(ListRelasi &LR) {
    LR.first = NULL;
}

addressRelasi createElmListRelasi(addressCustomer c, addressLaundry l) {
    addressRelasi R = new elmListRelasi;
    R->customer = c;
    R->laundry = l;
    R->next = NULL;
    return R;
}

bool isEmptyListRelasi(ListRelasi LR) {
    return LR.first == NULL;
}

void insertRelasi(ListRelasi &LR, addressRelasi P) {
    P->next = LR.first;
    LR.first = P;
}

void deleteRelasi(ListRelasi &LR, addressCustomer c, addressLaundry l) {
    addressRelasi R = LR.first, prec = NULL;
    while (R != NULL) {
        if (R->customer == c && R->laundry == l) {
            if (prec == NULL) LR.first = R->next;
            else prec->next = R->next;
            delete R;
            return;
        }
        prec = R;
        R = R->next;
    }
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
