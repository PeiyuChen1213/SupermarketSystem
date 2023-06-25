//
// Created by 29844 on 6/23/2023.
//


#include "AdminPanel.h"

#define ADMINNAME "user"
#define PASSWORD "123456"
using namespace std;

void AdminPanel::runPanel() {
    string username, password;
    cout << "Admin Control Panel" << endl;
    cout << "Please enter your username:";
    cin >> username;
    cout << "Please enter your password:";
    cin >> password;

    if (username == ADMINNAME && password == PASSWORD) {
        int choice;
        while (true) {
            cout << endl;
            cout << "Admin Control Panel" << endl;
            cout << "1. Add Product" << endl;
            cout << "2. Search Product" << endl;
            cout << "3. Edit Product" << endl;
            cout << "4. Delete Product" << endl;
            cout << "5. Show Products (unsorted)" << endl;
            cout << "6. Show Products Sorted by ID" << endl;
            cout << "7. Show Products Sorted by Price" << endl;
            cout << "8. Show Receipts" << endl;
            cout << "9. Go Back" << endl;
            cout << "Enter your choice:";
            cin >> choice;

            switch (choice) {
                case 1:
                    addProduct();
                    system("pause");
                    break;
                case 2:
                    searchProduct();
                    system("pause");
                    break;
                case 3:
                    editProduct();
                    system("pause");
                    break;
                case 4:
                    deleteProduct();
                    system("pause");
                    break;
                case 5:
                    showProductsUnsorted();
                    system("pause");
                    break;
                case 6:
                    showProductsByID();
                    system("pause");
                    break;
                case 7:
                    showProductsByPrice();
                    system("pause");
                    break;
                case 8:
                    showReceipts();
                    system("pause");
                    break;
                case 9:
                    cout << "Going back to the main control panel..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } else {
        cout << "Invalid username or password." << endl;
    }
}

void AdminPanel::addProduct() {
    string name;
    double price, discountPercentage;
    cout << endl;
    cout << "Add Product" << endl;
    cin.ignore();
    cout << "Enter product name:";
    getline(cin, name);
    cout << "Enter product price:";
    cin >> price;
    cout << "Enter discount percentage:";
    cin >> discountPercentage;
    int stock = StockManager::currStockSize();
    Product newProduct(stock + 1, name, price, discountPercentage);
    StockManager::addProduct(newProduct);
    cout << "add successfully!" << endl;

}

void AdminPanel::searchProduct() {
    int id;
    cout << endl;
    cout << "Search Product" << endl;
    cout << "Enter product ID to search:";
    cin >> id;
    int index = StockManager::searchProductByBinarySearch(id);
    if (index != -1) {
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
    }
}

void AdminPanel::editProduct() {
    int id, index;
    string name;
    double price, discountPercentage;
    cout << endl;
    cout << "Edit Product" << endl;
    cout << "Enter product ID to edit:";
    cin >> id;
    cin.ignore();
    //check whether this product exists
    index = StockManager::searchProductByBinarySearch(id);
    if (index == -1) {
        cout << "This product does not exist" << endl;
        return;
    }
    cout << "found!" << endl;
    cout << "Enter product name:";
    getline(cin, name);
    cout << "Enter product price:";
    cin >> price;
    cout << "Enter discount percentage:";
    cin >> discountPercentage;
    StockManager::editProduct(index, name, price, discountPercentage);
    cout << "edit successfully!" << endl;
}

void AdminPanel::deleteProduct() {
    int id;
    cout << endl;
    cout << "Delete Product" << endl;
    cout << "Enter product ID to delete:";
    cin >> id;
    StockManager::deleteProduct(id);
}

void AdminPanel::showProductsUnsorted() {
    cout << endl;
    cout << "Show Products (unsorted)" << endl;
    StockManager::showProductsUnsorted();
}

void AdminPanel::showProductsByID() {
    cout << endl;
    cout << "Show Products Sorted by ID" << endl;
    vector<Product> list = StockManager::sortProductsByID();
    // 设置列宽
    const int columnWidth = 15;
    // 输出表头
    cout << setw(columnWidth) << left << "id"
         << setw(columnWidth) << left << "name"
         << setw(columnWidth) << left << "price"
         << setw(columnWidth) << left << "discount"
         << setw(columnWidth) << left << "PriceAfterDiscount" << endl;
    for (const auto &item: list) {

        cout << setw(columnWidth) << left << item.getId()
             << setw(columnWidth) << left << item.getName()
             << setw(columnWidth) << left << item.getPrice()
             << setw(columnWidth) << left << item.getDiscountPercentage()
             << setw(columnWidth) << left << item.getPriceAfterDiscount() << endl;
    }
}

void AdminPanel::showProductsByPrice() {
    cout << endl;
    cout << "Show Products Sorted by Price" << endl;
    vector<Product> list = StockManager::sortProductsByPrice();
    // 设置列宽
    const int columnWidth = 15;
    // 输出表头
    cout << setw(columnWidth) << left << "id"
         << setw(columnWidth) << left << "name"
         << setw(columnWidth) << left << "price"
         << setw(columnWidth) << left << "discount"
         << setw(columnWidth) << left << "PriceAfterDiscount" << endl;
    for (const auto &item: list) {
        cout << setw(columnWidth) << left << item.getId()
             << setw(columnWidth) << left << item.getName()
             << setw(columnWidth) << left << item.getPrice()
             << setw(columnWidth) << left << item.getDiscountPercentage()
             << setw(columnWidth) << left << item.getPriceAfterDiscount() << endl;
    }
}

void AdminPanel::showReceipts() {
    cout << endl;
    cout << "Show Receipts" << endl;
    ReceiptManager::ShowReceipt();
}


