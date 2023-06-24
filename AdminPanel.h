//
// Created by 29844 on 6/23/2023.
//

#ifndef SUPERMARKETSYSTEM_ADMINPANEL_H
#define SUPERMARKETSYSTEM_ADMINPANEL_H

#include "AdminPanel.h"
#include "Product.h"
#include "Receipt.h"
#include "StockManager.h"
#include "ReceiptManager.h"
#include <iostream>
#include "string"


class AdminPanel {
public:
    void runPanel();


private:

    void addProduct();

    void searchProduct();

    void editProduct();

    void deleteProduct();

    void showProductsUnsorted();

    void showProductsByID();

    void showProductsByPrice();

    void showReceipts();
};


#endif //SUPERMARKETSYSTEM_ADMINPANEL_H
