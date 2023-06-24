cmake_minimum_required(VERSION 3.24)
project(SupermarketSystem)

set(CMAKE_CXX_STANDARD 11)

add_executable(SupermarketSystem main.cpp SystemPanel.cpp SystemPanel.h AdminPanel.cpp AdminPanel.h CustomerPanel.cpp CustomerPanel.h Product.cpp Product.h Receipt.cpp Receipt.h StockManager.cpp StockManager.h ReceiptManager.cpp ReceiptManager.h PurchasedProduct.cpp PurchasedProduct.h)
