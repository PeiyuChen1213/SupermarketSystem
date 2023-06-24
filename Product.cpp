//
// Created by 29844 on 6/23/2023.
//

#include "Product.h"

Product::Product(int id, const string &name, double price, double discountPercentage) : id(
        id), name(name), price(price), discountPercentage(discountPercentage), priceAfterDiscount(
        price * discountPercentage) {}

Product::Product() {}

Product::~Product() {
}

int Product::getId() const {
    return id;
}

void Product::setId(int id) {
    Product::id = id;
}

const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = name;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double price) {
    Product::price = price;
}

double Product::getDiscountPercentage() const {
    return discountPercentage;
}

void Product::setDiscountPercentage(double discountPercentage) {
    Product::discountPercentage = discountPercentage;
}

double Product::getPriceAfterDiscount() const {
    return priceAfterDiscount;
}

void Product::setPriceAfterDiscount(double priceAfterDiscount) {
    Product::priceAfterDiscount = priceAfterDiscount;
}

