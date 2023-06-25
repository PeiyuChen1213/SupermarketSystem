//
// Created by 29844 on 6/23/2023.
//

#include "CustomerPanel.h"
#include "ReceiptManager.h"

using namespace std;

void CustomerPanel::runPanel() {
    int choice;
    while (true) {
        cout << endl;
        cout << "Customer Control Panel" << endl;
        cout << "1. Buy Product" << endl;
        cout << "2. Go Back" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
                buyProduct();
                system("pause");
                break;
            case 2:
                cout << "Going back to the main control panel..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void CustomerPanel::buyProduct() {
    int id, quantity;
    Receipt receipt;
    cout << endl;
    while (true) {
        cout << "Buy Product" << endl;
        cout << "Enter product ID to buy:";
        cin >> id;
        int index = StockManager::searchProductByLinearSearch(id);
        if (index == -1) {
            cout << "This Product does not exists!" << endl;
            return;
        }
        cout << "search successfully! " << endl;
        vector<Product> currStock = StockManager::currStock();
        // 设置列宽
        const int columnWidth = 15;
        // 输出表头
        cout << setw(columnWidth) << left << "id"
             << setw(columnWidth) << left << "name"
             << setw(columnWidth) << left << "price"
             << setw(columnWidth) << left << "discount" << endl;
        cout << setw(columnWidth) << left << currStock[index].getId()
             << setw(columnWidth) << left << currStock[index].getName()
             << setw(columnWidth) << left << currStock[index].getPrice()
             << setw(columnWidth) << left << currStock[index].getDiscountPercentage() << endl;

        cout << "Enter quantity to buy:";
        cin >> quantity;
        // Process the product purchase
        PurchasedProduct product(currStock[index], quantity);
        receipt.addProduct(product);
        int addMoreProducts;
        cout << "Do you want to add more products? (YES/NO):" << endl;
        cout << "1. YES" << endl;
        cout << "2. NO" << endl;
        cin >> addMoreProducts;
        if (addMoreProducts == 2) {
            // Generate and display the invoice
            receipt.printInvoice();
            // Collect payment from the customer
            makePayment(receipt.getTotalAmount(), receipt);
            // Generate and display the receipt
            time_t now = time(0);
            string dateTime = ctime(&now);
            // 生成随机的收据号码
            srand(static_cast<unsigned int>(time(0)));
            int receiptNumber = rand() % 100000 + 1;
            receipt.setReceiptNumber(receiptNumber);
            //生成下单得时间
            receipt.setDate(dateTime);
            receipt.printReceipt();
            //add the receipt into the receipt list
            ReceiptManager::addReceipt(receipt);
            return;
        }
    }
}

void CustomerPanel::makePayment(double totalPrice, Receipt &receipt) {
    double payment;
    while (true) {
        cout << "Enter the amount tendered:";
        cin >> payment;
        receipt.setInitialPayment(payment);
        if (payment < totalPrice) {
            cout << "Money not enough, enter sufficient amount." << endl;
        } else {
            double change = payment - totalPrice;
            receipt.setChange(change);
            return;
        }
    }
}