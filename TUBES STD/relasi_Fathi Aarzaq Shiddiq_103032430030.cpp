#include "relation.h"

bool isEmptyListRelasi(ListRelasi LR) {
    return LR.first == nullptr;
}

void insertLastRelasi(ListRelasi &LR, addressRelasi P) {
    if (isEmptyListRelasi(LR)) {
        LR.first = P;
        P->next = nullptr;
    } else {
        addressRelasi q = LR.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = P;
        P->next = nullptr;
    }
}

void insertAfterRelasi(ListRelasi &LR, addressRelasi prec, addressRelasi P) {
    if (prec != nullptr) {
        P->next = prec->next;
        prec->next = P;
    }
}

void deleteFirstRelasi(ListRelasi &LR, addressRelasi &P) {
    if (!isEmptyListRelasi(LR)) {
        P = LR.first;
        LR.first = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void deleteAllRelasiByLaundry(ListRelasi &LR, addressLaundry l) {
    addressRelasi p = LR.first, prev = nullptr, del;
    while (p != nullptr) {
        if (p->laundry == l) {
            if (prev == nullptr) {
                LR.first = p->next;
            } else {
                prev->next = p->next;
            }
            del = p;
            p = p->next;
            del->next = nullptr;
            delete del;
        } else {
            prev = p;
            p = p->next;
        }
    }
}

bool isParentChildRelated(ListRelasi LR, addressCustomer c, addressLaundry l) {
    return findRelation(LR, c, l) != nullptr;
}

void showParentOfChild(ListRelasi LR, addressLaundry l) {
    if (l == nullptr) {
        cout << "Child tidak ditemukan." << endl;
        return;
    }
    cout << "Data parent dari child: "
         << l->info.idLaundry << " (berat " << l->info.beratPakaian << " kg)" << endl;
    addressRelasi p = LR.first;
    bool ada = false;
    while (p != nullptr) {
        if (p->laundry == l) {
            ada = true;
            cout << "- ID Customer: " << p->customer->info.idCustomer
                 << ", Nama: " << p->customer->info.nama << endl;
            cout << "  No Telpon: " << p->customer->info.noTelepon << endl;
            cout << "  Alamat: " << p->customer->info.alamat << endl;
        }
        p = p->next;
    }
    if (!ada) {
        cout << "Child ini belum memiliki parent." << endl;
    }
}

void showAllParentWithChild(ListCustomer LC, ListRelasi LR) {
    addressCustomer c = LC.first;
    while (c != nullptr) {
        cout << "Parent: " << c->info.idCustomer
             << " - " << c->info.nama << endl;
        cout << "No Telpon: " << c->info.noTelepon << endl;
        cout << "Alamat: " << c->info.alamat << endl;

        addressRelasi p = LR.first;
        bool ada = false;
        while (p != nullptr) {
            if (p->customer == c) {
                ada = true;
                cout << "   -> Laundry: " << p->laundry->info.idLaundry
                     << ", Berat: " << p->laundry->info.beratPakaian << " kg" << endl;
            }
            p = p->next;
        }
        if (!ada) {
            cout << "   (Tidak memiliki child)" << endl;
        }
        cout << "-----------------------------" << endl;
        c = c->next;
    }
}

int countParentOfChild(ListRelasi LR, addressLaundry l) {
    int count = 0;
    addressRelasi p = LR.first;
    while (p != nullptr) {
        if (p->laundry == l) {
            count++;
        }
        p = p->next;
    }
    return count;
}

int countParentWithoutChild(ListCustomer LC, ListRelasi LR) {
    int count = 0;
    addressCustomer c = LC.first;
    while (c != nullptr) {
        if (countChildOfParent(LR, c) == 0) {
            count++;
        }
        c = c->next;
    }
    return count;
}

void editRelationChangeChild(ListRelasi &LR, addressCustomer c, addressLaundry oldChild, addressLaundry newChild) {
    addressRelasi p = findRelation(LR, c, oldChild);
    if (p != nullptr) {
        p->laundry = newChild;
    }
}

void printAllRelasi(ListRelasi LR) {
    addressRelasi p = LR.first;
    while (p != nullptr) {
        cout << "Customer: " << p->customer->info.idCustomer
             << " - " << p->customer->info.nama
             << " | Laundry: " << p->laundry->info.idLaundry
             << " (berat " << p->laundry->info.beratPakaian << " kg)" << endl;
        p = p->next;
    }
}




