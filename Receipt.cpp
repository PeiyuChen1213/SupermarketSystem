//
// Created by 29844 on 6/23/2023.
//

#include "Receipt.h"

void Receipt::printReceipt() {
    sortProductsByPrice();
    const int columnWidth = 15;
    cout << "---------------------------------------Receipt------------------------------------------\n";
    cout << "Supermarket Name:" << "XMUM SMALL MARKET" << endl;
    cout << "Receipt Number:" << receiptNumber << endl;
    cout << "date:" << date;
    cout << "totalAmount:" << totalAmount << endl;
    cout << "initial Payment:" << initialPayment << endl;
    cout << "change:" << change << endl;
    cout << "PurchasedProduct Info: " << endl;
    cout << setw(columnWidth) << left << "id"
         << setw(columnWidth) << left << "name"
         << setw(columnWidth) << left << "price"
         << setw(columnWidth) << left << "discount"
         << setw(columnWidth + 10) << left << "priceAfterDiscount"
         << setw(columnWidth) << left << "Total cost of each item" << endl;
    for (const auto &PurchasedProduct: productList) {
        cout << setw(columnWidth) << left << PurchasedProduct.getId()
             << setw(columnWidth) << left << PurchasedProduct.getName()
             << setw(columnWidth) << left << PurchasedProduct.getPrice()
             << setw(columnWidth) << left << PurchasedProduct.getDiscountPercentage()
             << setw(columnWidth + 10) << left << PurchasedProduct.getPriceAfterDiscount()
             << setw(columnWidth) << left << PurchasedProduct.getPriceAfterDiscount() * PurchasedProduct.getQty()
             << endl;
    }
}


void Receipt::printInvoice() {
    //sort first
    sortProductsByID();
    const int columnWidth = 15;
    double totalAmount = 0;
    cout << "---------------------------------------Invoice------------------------------------------\n";
    cout << "Your PurchasedProduct Info: " << endl;
    cout << setw(columnWidth) << left << "id"
         << setw(columnWidth) << left << "name"
         << setw(columnWidth) << left << "price"
         << setw(columnWidth) << left << "discount"
         << setw(columnWidth + 10) << left << "priceAfterDiscount"
         << setw(columnWidth) << left << "Qty" << endl;
    for (const auto &PurchasedProduct: productList) {
        // calculate the total amount;
        totalAmount = PurchasedProduct.getPriceAfterDiscount() * PurchasedProduct.getQty() + totalAmount;
        cout << setw(columnWidth) << left << PurchasedProduct.getId()
             << setw(columnWidth) << left << PurchasedProduct.getName()
             << setw(columnWidth) << left << PurchasedProduct.getPrice()
             << setw(columnWidth) << left << PurchasedProduct.getDiscountPercentage()
             << setw(columnWidth + 10) << left << PurchasedProduct.getPriceAfterDiscount()
             << setw(columnWidth) << left << PurchasedProduct.getQty() << endl;
    }
    //record the total amount
    setTotalAmount(totalAmount);
    cout << "Total amount:" << totalAmount << endl;
}


Receipt::Receipt() {}

Receipt::~Receipt() {

}

Receipt::Receipt(int receiptNumber, const string &date, const vector<PurchasedProduct> &productList, double totalAmount,
                 double initialPayment, double change) : receiptNumber(receiptNumber), date(date),
                                                         productList(productList), totalAmount(totalAmount),
                                                         initialPayment(initialPayment), change(change) {}

int Receipt::getReceiptNumber() const {
    return receiptNumber;
}

void Receipt::setReceiptNumber(int receiptNumber) {
    Receipt::receiptNumber = receiptNumber;
}

const string &Receipt::getDate() const {
    return date;
}

void Receipt::setDate(const string &date) {
    Receipt::date = date;
}

const vector<PurchasedProduct> &Receipt::getProductList() const {
    return productList;
}

void Receipt::setProductList(const vector<PurchasedProduct> &productList) {
    Receipt::productList = productList;
}

double Receipt::getTotalAmount() const {
    return totalAmount;
}

void Receipt::setTotalAmount(double totalAmount) {
    Receipt::totalAmount = totalAmount;
}

double Receipt::getInitialPayment() const {
    return initialPayment;
}

void Receipt::setInitialPayment(double initialPayment) {
    Receipt::initialPayment = initialPayment;
}

double Receipt::getChange() const {
    return change;
}

void Receipt::setChange(double change) {
    Receipt::change = change;
}

void Receipt::sortProductsByPrice() {
    selectionSort(productList);
}

void Receipt::selectionSort(vector<PurchasedProduct> &products) {
    int n = products.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((products[j].getPriceAfterDiscount()) * (products[j].getQty()) <
                (products[minIndex].getPriceAfterDiscount()) * (products[minIndex].getQty())) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(products[i], products[minIndex]);
        }
    }
}


void Receipt::sortProductsByID() {
    quickSort(productList, 0, productList.size() - 1);
}

int Receipt::partition(vector<PurchasedProduct> &products, int low, int high) {
    int pivot = products[high].getId();
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (products[j].getId() < pivot) {
            i++;
            swap(products[i], products[j]);
        }
    }
    swap(products[i + 1], products[high]);
    return (i + 1);
}

void Receipt::quickSort(vector<PurchasedProduct> &products, int low, int high) {
    if (low < high) {
        int pi = partition(products, low, high);
        quickSort(products, low, pi - 1);
        quickSort(products, pi + 1, high);
    }
}

void Receipt::addProduct(PurchasedProduct product) {
    productList.push_back(product);
}
