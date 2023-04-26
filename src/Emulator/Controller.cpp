//
// Created by User on 30.11.2022.
//

#include "Controller.h"

int Controller::count = 0;
#define DEBUG

Controller::Controller()
{
    quantityOfData           = 10000;
    quantityOfRequests       = 10000;

    percentageAppendQuantity = 0.4f;
    percentageRemoveQuantity = 0.2f;
    percentageSearchQuantity = 0.4f;

    std::cout << "Enter the number of scenario:\n1)Bubble Sort.\n2)Quick Sort.\nEnter the number:";
    std::cin >> s1;
    std::cout  << "Enter the number of scenario:\n1)Full Search.\n2)Binary Search.\nEnter the number:";
    std::cin >> s2;

    list = new Lists('0', '0');
}

Controller::Controller(int data, int requests, float append, float remove, float search)
{
    quantityOfData           = data;
    quantityOfRequests       = requests;

    percentageAppendQuantity = append;
    percentageRemoveQuantity = remove;
    percentageSearchQuantity = search;
}

Controller::Controller(char s1, char s2)
{
    quantityOfData           = 10000;
    quantityOfRequests       = 10000;

    percentageAppendQuantity = 0.4f;
    percentageRemoveQuantity = 0.2f;
    percentageSearchQuantity = 0.4f;


    list = new Lists(s1, s2);


}

void Controller::setScenario(char s1, char s2) {
    this->s1 = s1;
    this->s2 = s2;
}

void Controller::runScenario() {
    std::srand(std::time(0));

    list = new Lists(s1, s2);



    for (int i = 0; i < quantityOfData; ++i) {
        int *tmp = new int[2];
        tmp[0] = rand() % 10000;
        tmp[1] = i;

        list->push_back(tmp);
    }

    if (s1 == '1' && s2 != '2') {
        list->bubbleSort();
        list->setSorted(true);
    }
    else if (s1 == '2' && s2 != '2') {
        list->quickSort(0, (int)list->getList().size() - 1 );
        list->setSorted(true);
    }

    for (int i = 0; i < quantityOfRequests; i++)
    {

        int randomNumber = rand() % 100;
        cout << "Random number = " << randomNumber << endl;

        if (randomNumber < (int)(percentageAppendQuantity * 100))
        {
#ifdef DEBUG
            std::cout << " In append" << std::endl;
#endif

            list->push_back(rand () % 10000 + quantityOfData + i, rand() % quantityOfData + i);
            count++;
        }

        else if (randomNumber < (int)((percentageAppendQuantity + percentageRemoveQuantity) * 100) && list->getList().empty() )
        {
#ifdef DEBUG
            std::cout << " In remove" << std::endl;
#endif
            // remove mid or try to find the id, if it's exist, then delete. I believe in second.
            list->remove_by_ID(rand() % (int) list->getList().size() );
            count++;

        }

        else if (randomNumber < 100)
        {
#ifdef DEBUG
            std::cout << " In search" << std::endl;
#endif
            switch(s2)
            {
                case '1':
#ifdef DEBUG
                std::cout << " In Full search" << std::endl;
#endif
                    if (list->getList().empty()) {


                        result = list->fullSearch(rand() % (int) list->getList().size() - 1);
                        count++;
                        if (result != -1) {
                            cout << "Found the number by index : " << result << endl;
                            result = -1;
                        } else {
                            cout << "Not Founded or Non Exist" << endl;
                        }
                    }
                    else {
                        cout << "The Vector is Empty " << endl;
                    }
                    break;
                case '2':
#ifdef DEBUG
                std::cout << "In Binary Search" << std::endl;
#endif
                    if (list->getList().empty()) {
                        result = list->binarySearch(0, (int) list->getList().size() - 1,
                                                    (int)(rand() % 10000));

                        count++;

                        if (result != -1) {
                            cout << "Found the number by index : " << result << endl;
                            result = -1;
                        } else {
                            cout << "Not Founded or Non Exist" << endl;
                        }
                    }
                    else
                    {
                        cout << "The Vector is Empty " << endl;
                    }
                    break;
            }

        }

    }

    // if you found it then you need to know that I didn't find the solution to do binary search for insert
    if (s1 == '1' && s2 == '2')
    {
        list->bubbleSort();
        list->setSorted(true);
    }

    if (s1 == '2' && s2 == '2') {
        list->quickSort(0, (int)list->getList().size() - 1 );
        list->setSorted(true);
    }
}

void Controller::printList()
{
    std::vector<int*> v = list->getList();

    for (auto it = v.begin(); it < v.end(); it++)
    {
        std::cout << "Id = " << (*it)[0] << " Value = " << (*it)[1] << std::endl;
    }
}

void Controller::rebootDataBase()
{
    count = 0;
    result = 0;
    s1 = s2 = 0;
    list->~Lists();
    list = nullptr;
}

int Controller::getCount() { return count; }
int Controller::getListCount() { return list->getCount(); }

Controller::~Controller()
{
    list->~Lists();
    list = nullptr;
    count = 0;
    result = 0;
    s1 = s2 = 0;
    quantityOfRequests = quantityOfData = 0;
    percentageAppendQuantity = percentageRemoveQuantity = percentageSearchQuantity = 0;
}