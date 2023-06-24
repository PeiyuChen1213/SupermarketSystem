//
// Created by 29844 on 6/24/2023.
//

#ifndef SUPERMARKETSYSTEM_RECEIPTMANAGER_H
#define SUPERMARKETSYSTEM_RECEIPTMANAGER_H

#include "Receipt.h"
#include <vector>
#include <iomanip>
#include <iostream>

class ReceiptManager {
private:
    static vector<Receipt> Receipt_LIST;
public:
    static vector<Receipt> sortReceipt(); //use selectionSort
    static void ShowReceipt();

    static void addReceipt(Receipt receipt);
};


#endif //SUPERMARKETSYSTEM_RECEIPTMANAGER_H
