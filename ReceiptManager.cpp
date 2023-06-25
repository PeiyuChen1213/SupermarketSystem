//
// Created by 29844 on 6/24/2023.
//

#include "ReceiptManager.h"

vector<Receipt> ReceiptManager::Receipt_LIST;

vector<Receipt> ReceiptManager::sortReceipt() {

    int len = Receipt_LIST.size();
    int minIndex;
    for (int i = 0; i < len - 1; i++) {
        minIndex = i;                     //最小下标
        for (int j = i + 1; j < len; j++) //访问未排序的元素
        {
            if (Receipt_LIST[j].getReceiptNumber() < Receipt_LIST[minIndex].getReceiptNumber())
                minIndex = j; //找到最小的
        }
        swap(Receipt_LIST[i], Receipt_LIST[minIndex]);
    }
    return Receipt_LIST;
}

void ReceiptManager::addReceipt(Receipt receipt) {
    Receipt_LIST.push_back(receipt);
}

void ReceiptManager::ShowReceipt() {
    vector<Receipt> list = sortReceipt();
    // 设置列宽
    const int columnWidth = 15;
    //Sun Jun 25 10:48:25 2023
    //ReceiptNumber                 Date                                              TotalAmount                   initial Pa
    // 输出表头
    //输出数据
    cout << setw(columnWidth) << left << "ReceiptNumber"
         << setw(columnWidth) << left << "TotalAmount"
         << setw(columnWidth + 5) << left << "initial Payment"
         << setw(columnWidth) << left << "change"
         << setw(columnWidth) << left << "Date" << endl;
    for (const auto &receipt: list) {
        cout << setw(columnWidth) << left << receipt.getReceiptNumber()
             << setw(columnWidth) << left << receipt.getTotalAmount()
             << setw(columnWidth + 5) << left << receipt.getInitialPayment()
             << setw(columnWidth) << left << receipt.getChange()
             << setw(columnWidth) << left << receipt.getDate();
    }
}
