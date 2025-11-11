#ifndef _TESTMENU_H_
#define _TESTMENU_H_
#include "XyzEmployeeManager.H"
//Global Manager Instance/Object.
XyzEmployeeManager manager;

enum MainMenu
{
    ADD_EMPLOYEE=1,
    REMOVE_AN_EMPLOYEE,
    GET_EMPLOYEE_DETAILS,
    DO_SOMETHING_ELSE,
};

enum AddEmployee
{
    ADD_AN_EMPLOYEE_AT_RANDOM = 1,
    ADD_AN_EMPLOYEE_F_C_I =2,
};

enum GetEmployeeDetails
{
    ALL_EMPLOYEE_SUMMARY=1,
    EMPLOYEE_SUMMARY_F_C_I=2,
    EMPLOYEE_SUMMARY_M_F,
    EMPLOYEE_SUMMARY_A_I_R,
    EMPLOYEE_SUMMARY_BY_ID,
    
};

enum DoSomethingElse
{
    ADD_N_NUMBER_OF_LEAVES_TO_ALL_FULLTIME_EMPLOYEES = 1,
    CONVERT_INTERN_TO_FULL_TIME_EMPLOYEE,
    SEARCH_EMPLOYEE_DETAILS_BYID,
    SEARCH_EMPLOYEE_DETAILS_BYNAME,
};

class Menu
{
    public:
        static void DisplayMainMenuOptions();
        static void DisplayAddAnEmployeeMenu();
        static void DisplayGetEmployeeDetailsMenu();
        static void DisplayDoSomethingElseMenu();
        static void MainMenu();
        static void AddAnEmployee();
        static void GetEmployeeDetails();
        static void DoSomethingElse();
};

void Menu::DisplayMainMenuOptions()
{
    std::cout <<" ----------------------------------- "<< std::endl;
    std::cout <<" |     Employee Management System   | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<" |       1.Add an Employee          | "<< std::endl;
    std::cout <<" |       2.Remove an Employee       | "<< std::endl;
    std::cout <<" |       3.Get Employee Details     | "<< std::endl;
    std::cout <<" |       4.Do Something else        | "<< std:: endl;
    std::cout <<" |      -1 to Exit                  | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<"Enter Your Choice:";
} 

void Menu::DisplayAddAnEmployeeMenu()
{
    std::cout <<" ----------------------------------- "<< std::endl;
    std::cout <<" |     Employee Management System   | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<" | Add an Employee:                 | "<< std::endl;
    std::cout <<" |   1.Add an Employee at Random    | "<< std::endl;
    std::cout <<" |   2.Add an Employee(F/C/I)       | "<< std::endl;
    std::cout <<" |  -1.To go back to MainMenu       | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<" Enter Your Choice:";
}

void Menu::DisplayGetEmployeeDetailsMenu()
{
    std::cout <<" ----------------------------------- "<< std::endl;
    std::cout <<" |     Employee Management System   | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<" | Get Employee Details:            | "<< std::endl;
    std::cout <<" |    1.All Employees Summary       | "<< std::endl;
    std::cout <<" |    2.Employee Summary (F/C/I)    | "<< std::endl;
    std::cout <<" |    3.Employee Summary (M/F)      | "<< std::endl;
    std::cout <<" |    4.Employee Summary (A/I/R)    | "<< std::endl;
    std::cout <<" |    5.Display Employee Details    | "<< std::endl;
    std::cout <<" |   -1.To go back to Main Menu     | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<"Enter Your Choice:";
}

void Menu::DisplayDoSomethingElseMenu()
{
    std::cout <<" ----------------------------------- "<< std::endl;
    std::cout <<" |     Employee Management System   | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<" | Do Something else:               | "<< std::endl;
    std::cout <<" |    1.Add 'n' number leaves to    | "<< std::endl;
    std::cout <<" |      all the fulltime Employees  | "<< std::endl;
    std::cout <<" |    2.Convert and Intern to       | "<< std::endl;
    std::cout <<" |      full-time employee          | "<< std::endl;
    std::cout <<" |    3.Search Employee by ID       | "<< std::endl;
    std::cout <<" |    4.Search by Employee by Name  | "<< std::endl;
    std::cout <<" |   -1.To go back to Main Menu     | "<< std::endl;
    std::cout <<" -----------------------------------  "<< std::endl;
    std::cout <<"Enter Your Choice:";
}

void Menu::MainMenu()
{
    int sUserChoice;
    bool continueMainMenu = true;
    
    while(continueMainMenu)
    {
        Menu::DisplayMainMenuOptions();
        std::cin >> sUserChoice;
        switch(sUserChoice)
        {
            case ADD_EMPLOYEE:
            {
                AddAnEmployee();
                break;
            }
            case REMOVE_AN_EMPLOYEE:
            {
                std::string sEmpId;
                std::cout << "Enter Employee ID to be removed"<<std::endl;
                std::cin >> sEmpId;
                manager.RemoveEmployee(sEmpId);
                break;
            }
            case GET_EMPLOYEE_DETAILS:
            {
                 GetEmployeeDetails();
                 break;
            }
            case DO_SOMETHING_ELSE:
            {
                DoSomethingElse();
                break;
            }
            case EXIT:
            {
                std::cout << "you choose to exit! Good bye!" << std::endl;
                continueMainMenu = false;
                break;
            }
            default:
            {
                std::cout << "Invalid User Choice! Please try again" << std::endl;
            }
        }
    }
    return;
}

void Menu::AddAnEmployee()
{
   int sUserChoice = 0;
   bool continueAddMenu = true;
   
   while(continueAddMenu) 
   {
       DisplayAddAnEmployeeMenu();
       std::cin >> sUserChoice;
       
       switch(sUserChoice)
       {
            case ADD_AN_EMPLOYEE_AT_RANDOM:
                {
                    manager.AddRandomEmployee();
                    break;
                }
            case ADD_AN_EMPLOYEE_F_C_I:
                {
                    manager.AddEmployee();
                    break;
                }
            case EXIT:
                {
                    std::cout << "Going back to main Menu" <<std::endl;
                    continueAddMenu = false;
                    break;
                }
            default:
                {
                    std::cout <<"Invalid User choice! Please try again!" <<std::endl;
                }
       }
   }
   return;
}


void Menu::GetEmployeeDetails()
{
    int sUserChoice;
    DisplayGetEmployeeDetailsMenu();
    std::cin >> sUserChoice;
    while(sUserChoice != -1)
    {
        switch(sUserChoice)
        {
            case ALL_EMPLOYEE_SUMMARY:
                {
                 manager.GetFullSummary();
                 break;
                }
            case EMPLOYEE_SUMMARY_F_C_I:
                {
                 int sTypeChoice;
                 std::cout << "Select Type (0: Full-Time, 1: Contractor, 2: Intern): "<< std::endl;
                 //Add validation logic
                 std::cin >> sTypeChoice;
                 manager.GetEmployeeSummaryByType(static_cast<EmployeeType>(sTypeChoice));
                 break;
                }
            case EMPLOYEE_SUMMARY_M_F:
                {
                 std::cout << "Select Gender (0: Male, 1: Female, 2: Other): " << std::endl;
                 int sGender;
                 std::cin >> sGender;
                 manager.GetEmployeeSummaryByGender(static_cast<Gender>(sGender));
                 break;
                }
            case EMPLOYEE_SUMMARY_A_I_R:
                {
                 std::cout << "Select Status (0: Active, 1: Inactive, 2: Resigned): ";
                 int sStatus;
                 std::cin >> sStatus;
                 manager.GetEmployeeSummaryByStatus(static_cast<EmployeeStatus>(sStatus));
                 break;
                }
            case EMPLOYEE_SUMMARY_BY_ID:
                {
                 std::string sEmpId;
                 std::cout << "Enter Employee ID (e.g., XYZ0001F): ";
                 std::cin >> sEmpId;
                 manager.DisplayEmployeeDetails(sEmpId);
                 break;
                }
            case EXIT:
                {
                std::cout << "Going Back to Main Menu " << std::endl; 
                break;
                }
            default:
                {
                std::cout << "Invalid User Choice!Try Again!" << std::endl;
                }
        }
        DisplayGetEmployeeDetailsMenu();
        std::cin >> sUserChoice;
    }
    return;
}

void Menu::DoSomethingElse()
{
    int sUserChoice = 0;
    do
    {
        DisplayDoSomethingElseMenu();
        std::cin >> sUserChoice;
        switch(sUserChoice)
        {
            case ADD_N_NUMBER_OF_LEAVES_TO_ALL_FULLTIME_EMPLOYEES:
                {
                int sLeaves;
                std::cout << "Enter number of leaves to add: ";
                std::cin >> sLeaves;
                manager.AddLeavesToFullTime(sLeaves);
                break;
                }
            case CONVERT_INTERN_TO_FULL_TIME_EMPLOYEE:
                {
                std::string sEmpId;
                std::cout << "Enter Intern Employee ID: ";
                std::cin >> sEmpId;
                manager.ConvertInternToFullTime(sEmpId);
                break;
                }
            case SEARCH_EMPLOYEE_DETAILS_BYID:
                {
                std::string sEmpId;
                std::cout << "Enter Employee ID (e.g., XYZ0001F): ";
                std::cin >> sEmpId;
                manager.SearchEmployeeByID(sEmpId);
                break;
                }
            case SEARCH_EMPLOYEE_DETAILS_BYNAME:
                {
                std::string sName;
                std::cout << "Enter Name / part of the name: ";
                std::cin.ignore();
                std::getline(std::cin, sName);
                manager.searchEmployeeByName(sName);
                break;
                }
           case EXIT:
                {
                std::cout << "You choose to Exit" << std::endl;
                break;
                }
            default:
                {
                std::cout << "Enterred invalid entry try again!" << std::endl;                 
                }
        }
    }while(sUserChoice != -1);
    return;
}
#endif
