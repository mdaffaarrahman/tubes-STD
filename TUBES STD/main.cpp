#include <iostream>
#include "customer.h"
#include "laundry.h"
#include "relation.h"

using namespace std;

void menu() {
    cout << "===== MENU =====" << endl;
    cout << "a. Insert element parent" << endl;
    cout << "b. Insert element child" << endl;
    cout << "c. Insert element relation" << endl;
    cout << "d. Delete element parent" << endl;
    cout << "e. Delete element child" << endl;
    cout << "f. Delete element relation" << endl;
    cout << "g. Find element parent" << endl;
    cout << "h. Find element child" << endl;
    cout << "i. Find apakah parent dan child tertentu memiliki relasi" << endl;
    cout << "j. Show all data di List Parent" << endl;
    cout << "k. Show all data di List Child" << endl;
    cout << "l. Show data child dari parent tertentu" << endl;
    cout << "m. Show data parent dari child tertentu" << endl;
    cout << "n. Show setiap data parent beserta data child yang berelasi dengannya" << endl;
    cout << "o. Show setiap data child beserta data parent yang berelasi dengannya" << endl;
    cout << "p. Count jumlah child dalam parent tertentu" << endl;
    cout << "q. Count jumlah parent yang dimiliki oleh child tertentu" << endl;
    cout << "r. Count element child yang tidak memiliki parent" << endl;
    cout << "s. Count element parent yang tidak memiliki child" << endl;
    cout << "t. Edit relasi (ganti child/parent)" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    ListCustomer LC;
    ListLaundry LL;
    ListRelasi LR;
    createListCustomer(LC);
    createListLaundry(LL);
    createListRelasi(LR);

    char pilih;
    do {
        menu();
        cin >> pilih;
        cout << endl;

        if (pilih == 'a') {
            infotypeCustomer c;
            cout << "ID Customer: ";
            cin >> c.idCustomer;
            if (cekDuplikatDataCustomer(LC, c.idCustomer)) {
                cout << "ID sudah ada!" << endl;
            } else {
                cout << "Nama: ";
                cin >> c.nama;
                cout << "No Telpon: ";
                cin >> c.noTelepon;
                cout << "Alamat: ";
                cin >> c.alamat;
                addressCustomer p = createElmListCustomer(c);
                insertLastCustomer(LC, p);
                cout << "Parent berhasil ditambah." << endl;
            }

        } else if (pilih == 'b') {
            infotypeLaundry l;
            cout << "ID Laundry: ";
            cin >> l.idLaundry;
            if (cekDuplikatDataLaundry(LL, l.idLaundry)) {
                cout << "ID laundry sudah ada!" << endl;
            } else {
                cout << "Berat pakaian (kg): ";
                cin >> l.beratPakaian;
                addressLaundry p = createElmListLaundry(l);
                insertLastLaundry(LL, p);
                cout << "Child berhasil ditambah." << endl;
            }

        } else if (pilih == 'c') {
            string idC, idL;
            cout << "ID Customer: ";
            cin >> idC;
            cout << "ID Laundry: ";
            cin >> idL;
            addressCustomer pc = searchCustomerByID(LC, idC);
            addressLaundry pl = searchLaundryByID(LL, idL);
            if (pc == nullptr || pl == nullptr) {
                cout << "Parent/Child tidak ditemukan." << endl;
            } else if (isParentChildRelated(LR, pc, pl)) {
                cout << "Relasi sudah ada." << endl;
            } else {
                addressRelasi pr = createElmListRelasi(pc, pl);
                insertLastRelasi(LR, pr);
                cout << "Relasi berhasil ditambah." << endl;
            }

        } else if (pilih == 'd') {
            string idC;
            cout << "ID Customer yang akan dihapus: ";
            cin >> idC;
            addressCustomer pc = searchCustomerByID(LC, idC);
            if (pc == nullptr) {
                cout << "Parent tidak ditemukan." << endl;
            } else {
                deleteAllRelasiByCustomer(LR, pc);
                addressCustomer q = LC.first, prec = nullptr, del;
                while (q != nullptr && q != pc) {
                    prec = q;
                    q = q->next;
                }
                if (q != nullptr) {
                    if (prec == nullptr) {
                        deleteFirstCustomer(LC, del);
                    } else if (q->next == nullptr) {
                        deleteLastCustomer(LC, del);
                    } else {
                        deleteAfterCustomer(LC, prec, del);
                    }
                    delete del;
                    cout << "Parent dan semua relasinya dihapus." << endl;
                }
            }

        } else if (pilih == 'e') {
            string idL;
            cout << "ID Laundry yang akan dihapus: ";
            cin >> idL;
            addressLaundry pl = searchLaundryByID(LL, idL);
            if (pl == nullptr) {
                cout << "Child tidak ditemukan." << endl;
            } else {
                deleteAllRelasiByLaundry(LR, pl);
                addressLaundry q = LL.first, del;
                if (LL.first == pl) {
                    deleteFirstLaundry(LL, del);
                } else if (LL.last == pl) {
                    deleteLastLaundry(LL, del);
                } else {
                    while (q != nullptr && q->next != pl) {
                        q = q->next;
                    }
                    if (q != nullptr) {
                        deleteAfterLaundry(LL, q, del);
                    }
                }
                delete del;
                cout << "Child dan semua relasinya dihapus." << endl;
            }

        } else if (pilih == 'f') {
            string idC, idL;
            cout << "ID Customer: ";
            cin >> idC;
            cout << "ID Laundry: ";
            cin >> idL;
            addressCustomer pc = searchCustomerByID(LC, idC);
            addressLaundry pl = searchLaundryByID(LL, idL);
            if (pc == nullptr || pl == nullptr) {
                cout << "Parent/Child tidak ditemukan." << endl;
            } else {
                addressRelasi target = findRelation(LR, pc, pl);
                if (target == nullptr) {
                    cout << "Relasi tidak ditemukan." << endl;
                } else {
                    addressRelasi p = LR.first, prec = nullptr, del;
                    while (p != nullptr && p != target) {
                        prec = p;
                        p = p->next;
                    }
                    if (p != nullptr) {
                        if (prec == nullptr) {
                            deleteFirstRelasi(LR, del);
                        } else if (p->next == nullptr) {
                            deleteLastRelasi(LR, del);
                        } else {
                            deleteAfterRelasi(LR, prec, del);
                        }
                        delete del;
                        cout << "Relasi berhasil dihapus." << endl;
                    }
                }
            }

        } else if (pilih == 'g') {
            string idC;
            cout << "ID Customer: ";
            cin >> idC;
            addressCustomer pc = searchCustomerByID(LC, idC);
            if (pc == nullptr) {
                cout << "Parent tidak ditemukan." << endl;
            } else {
                printInfoCustomer(pc);
            }

        } else if (pilih == 'h') {
            string idL;
            cout << "ID Laundry: ";
            cin >> idL;
            addressLaundry pl = searchLaundryByID(LL, idL);
            if (pl == nullptr) {
                cout << "Child tidak ditemukan." << endl;
            } else {
                printInfoLaundry(pl);
            }

        } else if (pilih == 'i') {
            string idC, idL;
            cout << "ID Customer: ";
            cin >> idC;
            cout << "ID Laundry: ";
            cin >> idL;
            addressCustomer pc = searchCustomerByID(LC, idC);
            addressLaundry pl = searchLaundryByID(LL, idL);
            if (pc == nullptr || pl == nullptr) {
                cout << "Parent/Child tidak ditemukan." << endl;
            } else if (isParentChildRelated(LR, pc, pl)) {
                cout << "Parent dan child tersebut MEMILIKI relasi." << endl;
            } else {
                cout << "Parent dan child tersebut TIDAK memiliki relasi." << endl;
            }

        } else if (pilih == 'j') {
            if (isEmptyListCustomer(LC)) {
                cout << "List parent kosong." << endl;
            } else {
                printDataCustomer(LC);
            }

        } else if (pilih == 'k') {
            if (isEmptyListLaundry(LL)) {
                cout << "List child kosong." << endl;
            } else {
                printDataLaundry(LL);
            }

        } else if (pilih == 'l') {
            string idC;
            cout << "ID Customer: ";
            cin >> idC;
            addressCustomer pc = searchCustomerByID(LC, idC);
            showChildOfParent(LR, pc);

        } else if (pilih == 'm') {
            string idL;
            cout << "ID Laundry: ";
            cin >> idL;
            addressLaundry pl = searchLaundryByID(LL, idL);
            showParentOfChild(LR, pl);

        } else if (pilih == 'n') {
            showAllParentWithChild(LC, LR);

        } else if (pilih == 'o') {
            showAllChildWithParent(LL, LR);

        } else if (pilih == 'p') {
            string idC;
            cout << "ID Customer: ";
            cin >> idC;
            addressCustomer pc = searchCustomerByID(LC, idC);
            if (pc == nullptr) {
                cout << "Parent tidak ditemukan." << endl;
            } else {
                int jumlah = countChildOfParent(LR, pc);
                cout << "Jumlah child untuk parent ini: " << jumlah << endl;
            }

        } else if (pilih == 'q') {
            string idL;
            cout << "ID Laundry: ";
            cin >> idL;
            addressLaundry pl = searchLaundryByID(LL, idL);
            if (pl == nullptr) {
                cout << "Child tidak ditemukan." << endl;
            } else {
                int jumlah = countParentOfChild(LR, pl);
                cout << "Jumlah parent untuk child ini: " << jumlah << endl;
            }

        } else if (pilih == 'r') {
            int jumlah = countChildWithoutParent(LL, LR);
            cout << "Jumlah child yang tidak memiliki parent: " << jumlah << endl;

        } else if (pilih == 's') {
            int jumlah = countParentWithoutChild(LC, LR);
            cout << "Jumlah parent yang tidak memiliki child: " << jumlah << endl;

                } else if (pilih == 't') {
            char sub;
            cout << "1. Ganti child dari parent tertentu" << endl;
            cout << "2. Ganti parent dari child tertentu" << endl;
            cout << "Pilih: ";
            cin >> sub;

            if (sub == '1') {
                string idC, idOldL, idNewL;
                cout << "ID Customer (parent): ";
                cin >> idC;
                cout << "ID Laundry lama (old child): ";
                cin >> idOldL;
                cout << "ID Laundry baru (new child): ";
                cin >> idNewL;

                addressCustomer pc = searchCustomerByID(LC, idC);
                addressLaundry oldL = searchLaundryByID(LL, idOldL);
                addressLaundry newL = searchLaundryByID(LL, idNewL);

                if (pc == nullptr || oldL == nullptr || newL == nullptr) {
                    cout << "Parent/child lama/child baru tidak ditemukan." << endl;
                } else if (!isParentChildRelated(LR, pc, oldL)) {
                    cout << "Relasi parent dengan child lama tidak ada." << endl;
                } else {
                    editRelationChangeChild(LR, pc, oldL, newL);
                    cout << "Relasi berhasil diubah (child diganti)." << endl;
                }

            } else if (sub == '2') {
                string idOldC, idNewC, idL;
                cout << "ID Customer lama (old parent): ";
                cin >> idOldC;
                cout << "ID Customer baru (new parent): ";
                cin >> idNewC;
                cout << "ID Laundry (child): ";
                cin >> idL;

                addressCustomer oldC = searchCustomerByID(LC, idOldC);
                addressCustomer newC = searchCustomerByID(LC, idNewC);
                addressLaundry pl = searchLaundryByID(LL, idL);

                if (oldC == nullptr || newC == nullptr || pl == nullptr) {
                    cout << "Parent lama/baru atau child tidak ditemukan." << endl;
                } else if (!isParentChildRelated(LR, oldC, pl)) {
                    cout << "Relasi parent lama dengan child tersebut tidak ada." << endl;
                } else {
                    editRelationChangeParent(LR, oldC, newC, pl);
                    cout << "Relasi berhasil diubah (parent diganti)." << endl;
                }
            } else {
                cout << "Sub-menu tidak dikenal." << endl;
            }

        } else if (pilih == '0') {
            cout << "Keluar program." << endl;

        } else {
            cout << "Menu tidak dikenal." << endl;
        }

        cout << endl;
    } while (pilih != '0');

    return 0;
}
