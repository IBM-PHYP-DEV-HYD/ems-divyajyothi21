#include <iostream>
#include "TestMenu.H"
#include "XyzEmployeeManager.H"

int main()
{
   #if 0
   /* int sUserChoice;
    int sAddEmployeeChoice;
    do
    {
        Menu::DisplayMainMenuOptions();
        std::cin >> sUserChoice;
        switch(sUserChoice)
        {
            case ADD_EMPLOYEE:
            {    do
                 {
                    Menu::DisplayAddAnEmployeeMenu();
                    std::cin >> sAddEmployeeChoice;
                    switch(sAddEmployeeChoice)
                    {
                        case ADD_AN_EMPLOYEE_AT_RANDOM:
                        { 
                            /* Add Employee at random */
                            XyzEmployeeManager::AddRandomEmployee();                             
                            Menu::DisplayMainMenu2Options();
                            break;
                        }
                        case ADD_AN_EMPLOYEE_F_C_I:
                        {
                            break;
                        }
                        case EXIT:
                        {
                            std::cout <<"Going back to MainMenu" << std::endl;
                            break;
                        }
                        default:
                        {
                            std::cout << "You choose a wrong choice to add employee!try again!!" << std::endl;
                            break;
                        } 
                    }
                 }while(sAddEmployeeChoice!=-1);                 
                 break;
            }
            case EXIT:
            {
                std::cout << "you choose to exit! Goo bye!";
                break;
            }
            default:
            {
                std::cout << "Invalid Unser Choice!Please retry again" << std::endl;
            }
        }
    }while(sUserChoice != -1);*/
#endif
    Menu::MainMenu();
    return 0;
}
