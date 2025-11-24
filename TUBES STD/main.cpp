#include <iostream>
#include <iomanip>
#include "customer.h"
#include "laundry.h"
#include "relation.h"

using namespace std;

int main() {
    ListCustomer LC; createListCustomer(LC);
    ListLaundry LL; createListLaundry(LL);
    ListRelasi LR; createListRelasi(LR);

    int pilih;
    do {
        cout << "1. Tambah customer\n";
        cout << "2. Hapus customer\n";
        cout << "3. Tampil semua customer\n";
        cout << "4. Tambah laundry ke customer\n";
        cout << "5. Hapus laundry dari customer\n";
        cout << "6. Tampil semua laundry\n";
        cout << "7. Tampil semua relasi (customer -> laundry)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;

        if (pilih == 1) {
            infotypeCustomer cust;
            cout << "ID Customer: ";
            cin >> cust.idCustomer;
            cout << "Nama Customer: ";
            cin >> cust.nama;
            if (!cekDuplikatDataCustomer(LC, cust.idCustomer)) {
                addressCustomer pcust = createElmListCustomer(cust);
                insertLastCustomer(LC, pcust);
                cout << "Customer berhasil ditambah.\n";
            } else {
                cout << "Customer sudah ada!\n";
            }
        }
        else if (pilih == 2) {
            string id;
            cout << "ID Customer yang dihapus: ";
            cin >> id;
            addressCustomer prec = NULL, p = LC.first;
            while (p != NULL && p->info.idCustomer != id) {
                prec = p;
                p = p->next;
            }
            if (p != NULL) {
                if (prec == NULL) deleteFirstCustomer(LC, p);
                else deleteAfterCustomer(LC, prec, p);
                deleteAllRelasiByCustomer(LR, p); // hapus semua relasi customer ini
                delete p;
                cout << "Customer & relasi berhasil dihapus.\n";
            } else {
                cout << "Customer tidak ditemukan.\n";
            }
        }
        else if (pilih == 3) {
            printDataCustomer(LC);
        }
        else if (pilih == 4) {
            string idCust;
            cout << "ID Customer: ";
            cin >> idCust;
            addressCustomer pcust = searchCustomerByID(LC, idCust);
            if (pcust == NULL) {
                cout << "Customer tidak ditemukan!\n";
            } else {
                infotypeLaundry lw;
                cout << "ID Laundry: ";
                cin >> lw.idLaundry;
                cout << "Berat Pakaian (kg): ";
                cin >> lw.beratPakaian;
                if (!cekDuplikatDataLaundry(LL, lw.idLaundry)) {
                    addressLaundry plaundry = createElmListLaundry(lw);
                    insertLastLaundry(LL, plaundry);
                    addressRelasi r = createElmListRelasi(pcust, plaundry);
                    insertRelasi(LR, r);
                    cout << "Laundry berhasil ditambah ke customer.\n";
                } else {
                    cout << "Laundry sudah ada!\n";
                }
            }
        }
        else if (pilih == 5) {
            string idLaundry;
            cout << "ID Laundry yang dihapus: ";
            cin >> idLaundry;
            addressLaundry plaundry = searchLaundryByID(LL, idLaundry);
            if (plaundry != NULL) {
                // Hapus relasi
                deleteAllRelasiByLaundry(LR, plaundry);
                // Hapus laundry dari DLL
                if (plaundry == LL.first)
                    deleteFirstLaundry(LL, plaundry);
                else if (plaundry == LL.last)
                    deleteLastLaundry(LL, plaundry);
                else
                    deleteAfterLaundry(LL, plaundry->prev, plaundry);
                delete plaundry;
                cout << "Laundry & relasi berhasil dihapus.\n";
            } else {
                cout << "Laundry tidak ditemukan.\n";
            }
        }
        else if (pilih == 6) {
            // Tampil semua laundry
            printDataLaundry(LL);
        }
        else if (pilih == 7) {
            // Tampil semua relasi (customer -> laundry)
            printAllRelasi(LR);
        }

    } while (pilih != 0);

    cout << "Program selesai." << endl;
    return 0;
}
