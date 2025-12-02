#ifndef STORE_RELATION_H_INCLUDED
#define STORE_RELATION_H_INCLUDED
#include <iostream>
#include "customer.h"
#include "laundry.h"
using namespace std;

typedef struct elmListRelasi *addressRelasi;
struct elmListRelasi {
    addressCustomer customer;
    addressLaundry laundry;
    addressRelasi next;
};

struct ListRelasi {
    addressRelasi first;
};

void createListRelasi(ListRelasi &LR);
addressRelasi createElmListRelasi(addressCustomer c, addressLaundry l);
bool isEmptyListRelasi(ListRelasi LR);
void insertFirstRelasi(ListRelasi &LR, addressRelasi P);
void insertLastRelasi(ListRelasi &LR, addressRelasi P);
void insertAfterRelasi(ListRelasi &LR, addressRelasi prec, addressRelasi P);
void deleteFirstRelasi(ListRelasi &LR, addressRelasi &P);
void deleteAfterRelasi(ListRelasi &LR, addressRelasi prec, addressRelasi &P);
void deleteLastRelasi(ListRelasi &LR, addressRelasi &P);
void deleteAllRelasiByCustomer(ListRelasi &LR, addressCustomer c);
void deleteAllRelasiByLaundry(ListRelasi &LR, addressLaundry l);
void printAllRelasi(ListRelasi LR);
void printLaundryByCustomer(ListRelasi LR, addressCustomer c);

#endif
