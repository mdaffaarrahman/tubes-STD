#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
using namespace std;

struct customer {
    string idCustomer;
    string nama;
    string noTelepon;
    string alamat;
};

typedef struct customer infotypeCustomer;
typedef struct elmListCustomer *addressCustomer;
struct elmListCustomer {
    infotypeCustomer info;
    addressCustomer next;
};

struct ListCustomer {
    addressCustomer first;
};

void createListCustomer(ListCustomer &L);
addressCustomer createElmListCustomer(infotypeCustomer dataCustomer);
bool isEmptyListCustomer(ListCustomer L);
void insertFirstCustomer(ListCustomer &L, addressCustomer p);
void insertAfterCustomer(ListCustomer &L, addressCustomer prec, addressCustomer p);
void insertLastCustomer(ListCustomer &L, addressCustomer p);
void deleteFirstCustomer(ListCustomer &L, addressCustomer &p);
void deleteAfterCustomer(ListCustomer &L, addressCustomer prec, addressCustomer &p);
void deleteLastCustomer(ListCustomer &L, addressCustomer &p);
addressCustomer searchCustomerByID(ListCustomer L, string idCustomer);
bool cekDuplikatDataCustomer(ListCustomer L, string idCustomer);
void printInfoCustomer(addressCustomer p);
void printDataCustomer(ListCustomer L);

#endif
