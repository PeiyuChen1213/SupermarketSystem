//
// Created by 29844 on 6/24/2023.
//

#ifndef SUPERMARKETSYSTEM_PURCHASEDPRODUCT_H
#define SUPERMARKETSYSTEM_PURCHASEDPRODUCT_H

#include "Product.h"

class PurchasedProduct : public Product {
private:
    int qty;
public:
    PurchasedProduct(int id, const string &name, double price, double discountPercentage, int qty);

    PurchasedProduct(const Product &product, int qty);

    ~PurchasedProduct() override;

    int getQty() const;

    void setQty(int qty);
};


#endif //SUPERMARKETSYSTEM_PURCHASEDPRODUCT_H
