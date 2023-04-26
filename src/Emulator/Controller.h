//
// Created by User on 30.11.2022.
//

#ifndef SORTANDFIND_CONTROLLER_H
#define SORTANDFIND_CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "../Double_Linked_List/Node.h"
#include "../Double_Linked_List/Lists.h"
using namespace std;

// QuantityOfData == QuantityOfRequests > 1000;
// QuantityOfData > QuantityOfRequests > 1000;
// 1000 < QuantityOfData < QuantityOfRequests;

class Controller
{
    // or without inheriting
    // Lists list;
    // Singleton

private:
    char s1;                // Scenario 1
    char s2;                // Scenario 2

    static int count;

    int result;
    Lists *list = nullptr;

    int quantityOfData;
    int quantityOfRequests;

    float percentageAppendQuantity;
    float percentageRemoveQuantity;                   // a + r + s == 1
    float percentageSearchQuantity;

public:
    Controller();
    Controller(int data, int requests, float append, float remove, float search);
    Controller(char s1, char s2);
    // int quantity_data, int quantity_requests, int append_quantity, int remove_quantity, int search_quantity

    void rebootDataBase();
    void setScenario(char s1, char s2);
    void runScenario();
    void printList();

    static int getCount();
    int getListCount();

    ~Controller();
};


#endif //SORTANDFIND_CONTROLLER_H
