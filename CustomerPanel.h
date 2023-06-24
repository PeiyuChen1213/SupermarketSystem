//
// Created by 29844 on 6/23/2023.
//

#ifndef SUPERMARKETSYSTEM_CUSTOMERPANEL_H
#define SUPERMARKETSYSTEM_CUSTOMERPANEL_H

#include "Product.h"
#include "Receipt.h"
#include "StockManager.h"
#include "ReceiptManager.h"
#include "Product.h"
#include "Receipt.h"
#include <iostream>

class CustomerPanel {
public:
    void runPanel();

private:
    void buyProduct();

    void makePayment(double totalPrice, Receipt &receipt);
};


#endif //SUPERMARKETSYSTEM_CUSTOMERPANEL_H
