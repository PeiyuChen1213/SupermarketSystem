//
// Created by 29844 on 6/23/2023.
//

#ifndef SUPERMARKETSYSTEM_RECEIPT_H
#define SUPERMARKETSYSTEM_RECEIPT_H

#include "string"
#include <vector>
#include "PurchasedProduct.h"
#include <iomanip>
#include <iostream>

using namespace std;

class Receipt {

private:
    int receiptNumber;
    string date;
    vector<PurchasedProduct> productList;
    double totalAmount;
    double initialPayment;
    double change;

    int partition(vector<PurchasedProduct> &products, int low, int high);

    void quickSort(vector<PurchasedProduct> &products, int low, int high);

    void selectionSort(vector<PurchasedProduct> &products);

public:

    Receipt();

    Receipt(int receiptNumber, const string &date, const vector<PurchasedProduct> &productList, double totalAmount,
            double initialPayment, double change);

    virtual ~Receipt();

    int getReceiptNumber() const;

    void setReceiptNumber(int receiptNumber);

    const string &getDate() const;

    void setDate(const string &date);

    const vector<PurchasedProduct> &getProductList() const;

    void setProductList(const vector<PurchasedProduct> &productList);

    double getTotalAmount() const;

    void setTotalAmount(double totalAmount);

    double getInitialPayment() const;

    void setInitialPayment(double initialPayment);

    double getChange() const;

    void setChange(double change);

    // quicksort
    void sortProductsByID();

    //selection sort
    void sortProductsByPrice();

    void printReceipt();

    void printInvoice();

    void addProduct(PurchasedProduct product);
};


#endif //SUPERMARKETSYSTEM_RECEIPT_H
