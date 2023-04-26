#include <iostream>
#include "../Double_Linked_List/Lists.h"
#include "../Emulator/Controller.h"



int main()
{
    char s1;
    char s2;
    char Choice;

    Controller *controller = new Controller(5000, 10000, 0.5, 0.2, 0.3);

//    controller.runScenario();
//    controller.printList();

    std::cout  << "Welcome to the Emulator of Data Base\n";
    while (true)
    {
        std::cout << "Write the number of operations\n1)Bubble Sort.\n2)Quick Sort.\n3)No Sort, then it will only be a Full Search\nEnter the number:";
        std::cin >> s1;
        std::cout << "Write the number of operations\n1)Full Search.\n2)Binary Search.\nEnter the number:";
        std::cin >> s2;

        switch(s1)
        {
            case '1':
                switch(s2)
                {
                    case '1': {
                        controller->setScenario('1','1');
                        controller->runScenario();
                        std::cout << "Controller's count = " << controller->getCount() << "\nList's count = "
                                  << controller->getListCount() << endl;
                        break;
                    }

                    case '2': {
                        controller->setScenario('1','2');
                        controller->runScenario();
                        std::cout << "Controller's count = " << controller->getCount() << "\nList's count = "
                                  << controller->getListCount() << endl;
                        break;
                    }
                    default:
                        break;
                }
                break;
            case '2':
                switch(s2)
                {
                    case '1':
                        controller->setScenario('2','1');
                        controller->runScenario();
                        std::cout << "Controller's count = " << controller->getCount() <<
                                     "\nList's count = " << controller->getListCount() << endl;
                        break;
                    case '2':
                        controller->setScenario('2','2');
                        controller->runScenario();
                        std::cout << "Controller's count = " << controller->getCount() <<
                                     "\nList's count = "<< controller->getListCount() << endl;

                        break;
                    default:
                        break;
                }
                break;
            case '3':
                controller->setScenario('3', '1');
                controller->runScenario();
                std::cout << "Controller's count = " << controller->getCount() << "\nList's count = " << controller->getListCount() << endl;
                break;
            default:
                break;
        }

        std::cout << "Do you want to print Data base?\n1.Yes\n2.No\nWrite the number: ";
        std::cin >> Choice;

        if (Choice == '1')
        {
            controller->printList();
        }

        controller->rebootDataBase();

        std::cout << "Do you want to exit? \n1.Yes\n2.No\nWrite the number:";
        std::cin >> Choice;

        if (Choice == '1' || Choice == 'Y')
        {
            break;
        }
    }

//    controller->~Controller();
//    controller = nullptr;

    return 0;
}
