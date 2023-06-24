//
// Created by 29844 on 6/23/2023.
//

#ifndef SUPERMARKETSYSTEM_STOCKMANAGER_H
#define SUPERMARKETSYSTEM_STOCKMANAGER_H

#include "Product.h"
#include <vector>
#include <iomanip>
#include <iostream>

class StockManager {
private:
    // shared stock
    static vector<Product> PRODUCT_LIST;

    static void mergeSort(vector<Product> &a, vector<Product> &T, int left, int right);

public:
    //暴露操作库存的接口
    static void addProduct(Product product);

    static int searchProductByBinarySearch(long productID);

    static int searchProductByLinearSearch(long productID);

    static void editProduct(int index, const string &name, double price, double discountPercentage);

    static void deleteProduct(long productID);

    static void showProductsUnsorted();

    static vector<Product> sortProductsByID();

    static vector<Product> sortProductsByPrice();

    //暴露一个当前库存list的函数
    static const vector<Product> &currStock();

    static int currStockSize();


};


#endif //SUPERMARKETSYSTEM_STOCKMANAGER_H
