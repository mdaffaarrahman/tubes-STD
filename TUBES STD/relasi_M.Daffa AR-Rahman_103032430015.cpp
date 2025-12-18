#include "relation.h"

void createListRelasi(ListRelasi &LR) {
    LR.first = nullptr;
}

addressRelasi createElmListRelasi(addressCustomer c, addressLaundry l) {
    addressRelasi p = new elmListRelasi;
    p->customer = c;
    p->laundry = l;
    p->next = nullptr;
    return p;
}

void insertFirstRelasi(ListRelasi &LR, addressRelasi P) {
    P->next = LR.first;
    LR.first = P;
}

void deleteAfterRelasi(ListRelasi &LR, addressRelasi prec, addressRelasi &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        prec->next = P->next;
        P->next = nullptr;
    } else {
        P = nullptr;
    }
}

void deleteLastRelasi(ListRelasi &LR, addressRelasi &P) {
    if (isEmptyListRelasi(LR)) {
        P = nullptr;
    } else if (LR.first->next == nullptr) {
        P = LR.first;
        LR.first = nullptr;
        P->next = nullptr;
    } else {
        addressRelasi q = LR.first;
        while (q->next->next != nullptr) {
            q = q->next;
        }
        P = q->next;
        q->next = nullptr;
        P->next = nullptr;
    }
}

void deleteAllRelasiByCustomer(ListRelasi &LR, addressCustomer c) {
    addressRelasi p = LR.first, prev = nullptr, del;
    while (p != nullptr) {
        if (p->customer == c) {
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

void printLaundryByCustomer(ListRelasi LR, addressCustomer c) {
    addressRelasi p = LR.first;
    while (p != nullptr) {
        if (p->customer == c) {
            cout << "Laundry: " << p->laundry->info.idLaundry
                 << " (berat " << p->laundry->info.beratPakaian << " kg)" << endl;
        }
        p = p->next;
    }
}

addressRelasi findRelation(ListRelasi LR, addressCustomer c, addressLaundry l) {
    addressRelasi p = LR.first;
    while (p != nullptr) {
        if (p->customer == c && p->laundry == l) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void showChildOfParent(ListRelasi LR, addressCustomer c) {
    if (c == nullptr) {
        cout << "Parent tidak ditemukan." << endl;
        return;
    }
    cout << "Data child dari parent: "
         << c->info.idCustomer << " - " << c->info.nama << endl;
    cout << "No Telpon: " << c->info.noTelepon << endl;
    cout << "Alamat: " << c->info.alamat << endl;
    addressRelasi p = LR.first;
    bool ada = false;
    while (p != nullptr) {
        if (p->customer == c) {
            ada = true;
            cout << "- ID Laundry: " << p->laundry->info.idLaundry
                 << ", Berat: " << p->laundry->info.beratPakaian << " kg" << endl;
        }
        p = p->next;
    }
    if (!ada) {
        cout << "Parent ini belum memiliki child." << endl;
    }
}

void showAllChildWithParent(ListLaundry LL, ListRelasi LR) {
    addressLaundry l = LL.first;
    while (l != nullptr) {
        cout << "Child: " << l->info.idLaundry
             << ", Berat: " << l->info.beratPakaian << " kg" << endl;

        addressRelasi p = LR.first;
        bool ada = false;
        while (p != nullptr) {
            if (p->laundry == l) {
                ada = true;
                cout << "   -> Customer: " << p->customer->info.idCustomer
                     << " - " << p->customer->info.nama << endl;
                cout << "      No Telpon: " << p->customer->info.noTelepon << endl;
                cout << "      Alamat: " << p->customer->info.alamat << endl;
            }
            p = p->next;
        }
        if (!ada) {
            cout << "   (Tidak memiliki parent)" << endl;
        }
        cout << "-----------------------------" << endl;
        l = l->next;
    }
}

int countChildOfParent(ListRelasi LR, addressCustomer c) {
    int count = 0;
    addressRelasi p = LR.first;
    while (p != nullptr) {
        if (p->customer == c) {
            count++;
        }
        p = p->next;
    }
    return count;
}

int countChildWithoutParent(ListLaundry LL, ListRelasi LR) {
    int count = 0;
    addressLaundry l = LL.first;
    while (l != nullptr) {
        if (countParentOfChild(LR, l) == 0) {
            count++;
        }
        l = l->next;
    }
    return count;
}

void editRelationChangeParent(ListRelasi &LR, addressCustomer oldParent, addressCustomer newParent, addressLaundry l) {
    addressRelasi p = findRelation(LR, oldParent, l);
    if (p != nullptr) {
        p->customer = newParent;
    }
}
