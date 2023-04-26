//
// Created by User on 30.11.2022.
//

#ifndef SORTANDFIND_LISTS_H
#define SORTANDFIND_LISTS_H

#include <cmath>
#include <vector>
#include <ctime>

#include "Node.h"


// With or without STL;
// This with STL;

class Lists {
private:
    static int count;
    bool sorted;
    char* scenario;

    std::vector<int*> v;

public:
    Lists();
    Lists(char s1, char s2);

    int* &begin();
    int* &end();


    void push_back(int* &arr);
    void push_back(int id, int value);                       // Appending a value into nodes
    int remove_by_ID(const int &id);                         // remove by ID

    void setScenario(char s1, char s2);
    void setSorted(bool flag);
    void bubbleSort();
    void quickSort(int start, int end);

    int fullSearch(const int &id);
    int binarySearch(int l, int r, const int &id);

    int fullSearch_insert(const int &id);
    int binarySearch_insert(int l, int r, const int &id);

    static int getCount();

    std::vector<int*> &getList();

    ~Lists();

private:
    int partition(int start, int end);
};



#endif //SORTANDFIND_LISTS_H
