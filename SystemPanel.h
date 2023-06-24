//
// Created by 29844 on 6/23/2023.
//

#ifndef SUPERMARKETSYSTEM_SYSTEMPANEL_H
#define SUPERMARKETSYSTEM_SYSTEMPANEL_H

#include "AdminPanel.h"
#include "CustomerPanel.h"
#include "StockManager.h"
#include <string>
#include <iostream>
#include <vector>

class SystemPanel {
public:
    void runPanel();

    SystemPanel();

    virtual ~SystemPanel();
};


#endif //SUPERMARKETSYSTEM_SYSTEMPANEL_H
