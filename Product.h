//
// Created by 298448 on 6/23/2023.
//

#ifndef SUPERMARKETSYSTEM_PRODUCT_H
#define SUPERMARKETSYSTEM_PRODUCT_H

#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    double discountPercentage;
    double priceAfterDiscount;
public:
    Product(int id, const string &name, double price, double discountPercentage);

    Product();

    virtual ~Product();

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    double getPrice() const;

    void setPrice(double price);

    double getDiscountPercentage() const;

    void setDiscountPercentage(double discountPercentage);

    double getPriceAfterDiscount() const;

    void setPriceAfterDiscount(double priceAfterDiscount);
};


#endif //SUPERMARKETSYSTEM_PRODUCT_H
