//
// Created by 29844 on 6/23/2023.
//

#include "StockManager.h"

// initial the staic value
vector<Product> StockManager::PRODUCT_LIST;

void StockManager::addProduct(Product product) {
    PRODUCT_LIST.push_back(product);

}

int StockManager::searchProductByBinarySearch(long productID) {
    vector<Product> sortedList = sortProductsByID();
    int len = sortedList.size();
    int left = 0, right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedList[mid].getId() < productID) {
            left = mid + 1;
        } else if (sortedList[mid].getId() > productID) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    //没找到返回-1
    return -1;
}

int StockManager::searchProductByLinearSearch(long productID) {
    int len = PRODUCT_LIST.size();
    for (int i = 0; i < len; ++i) {
        if (productID == PRODUCT_LIST[i].getId()) {
            return i;
        }
    }
    //没找到返回-1
    return -1;
}


void StockManager::editProduct(int index, const string &name, double price, double discountPercentage) {
    //重新set属性
    PRODUCT_LIST[index].setName(name);
    PRODUCT_LIST[index].setPrice(price);
    PRODUCT_LIST[index].setDiscountPercentage(discountPercentage);
}

void StockManager::deleteProduct(long productID) {
    //search the product
    int index = searchProductByBinarySearch(productID);
    if (index != -1) {
        // remove the product with the index
        PRODUCT_LIST.erase(PRODUCT_LIST.begin() + index);
        cout << "delete successfully !";
    }
    cout << "This product does not exist !";
}

void StockManager::showProductsUnsorted() {

    // 设置列宽
    const int columnWidth = 15;
    cout << setw(columnWidth) << left << "id"
         << setw(columnWidth) << left << "name"
         << setw(columnWidth) << left << "price"
         << setw(columnWidth) << left << "discount"
         << setw(columnWidth + 10) << left << "PriceAfterDiscount" << endl;
    for (const auto &product: PRODUCT_LIST) {
        cout << setw(columnWidth) << left << product.getId()
             << setw(columnWidth) << left << product.getName()
             << setw(columnWidth) << left << product.getPrice()
             << setw(columnWidth) << left << product.getDiscountPercentage()
             << setw(columnWidth + 10) << left << product.getPriceAfterDiscount() << endl;
    }
}

vector<Product> StockManager::sortProductsByPrice() {
    int len = PRODUCT_LIST.size();
    for (int i = 0; i < len - 1; i++) //需要循环次数
    {
        for (int j = 0; j < len - 1 - i; j++) //每次需要比较个数
        {
            if (PRODUCT_LIST[j].getPrice() > PRODUCT_LIST[j + 1].getPrice()) {
                swap(PRODUCT_LIST[j], PRODUCT_LIST[j + 1]); //不满足偏序，交换
            }
        }
    }
    return PRODUCT_LIST;
}

vector<Product> StockManager::sortProductsByID() {
    //merge sort
    int len = PRODUCT_LIST.size();
    if (len == 1) {
        return PRODUCT_LIST;
    }
    vector<Product> T(len);
    mergeSort(PRODUCT_LIST, T, 0, len);
    return T;
}

void StockManager::mergeSort(vector<Product> &V, vector<Product> &T, int left, int right) {
    if (right - left == 1)
        return;
    int mid = left + right >> 1, tmid = left + right >> 1, tleft = left, i = left;
    mergeSort(V, T, left, mid), mergeSort(V, T, mid, right);
    while (tleft < mid || tmid < right) {
        if (tmid >= right || (tleft < mid && V[tleft].getId() <= V[tmid].getId())) {
            T[i++] = V[tleft++];
        } else {
            T[i++] = V[tmid++];
        }
    }
    for (int i = left; i < right; i++)
        V[i] = T[i];
}

int StockManager::currStockSize() {
    return (int) PRODUCT_LIST.size();
}

// 一个暴露当前库存的接口
const vector<Product> &StockManager::currStock() {
    return PRODUCT_LIST;
}


