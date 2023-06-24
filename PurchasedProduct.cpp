//
// Created by 29844 on 6/24/2023.
//

#include "PurchasedProduct.h"

PurchasedProduct::PurchasedProduct(int id, const string &name, double price, double discountPercentage, int qty)
        : Product(id, name, price, discountPercentage), qty(qty) {}

PurchasedProduct::PurchasedProduct(const Product &product, int qty)
        : Product(product.getId(), product.getName(), product.getPrice(),
                  product.getDiscountPercentage()), qty(qty) {}

PurchasedProduct::~PurchasedProduct() {

}

int PurchasedProduct::getQty() const {
    return qty;
}

void PurchasedProduct::setQty(int qty) {
    PurchasedProduct::qty = qty;
}



