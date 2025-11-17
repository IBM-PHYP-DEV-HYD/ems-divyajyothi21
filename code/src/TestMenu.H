#ifndef _TESTMENU_H_
#define _TESTMENU_H_
//#include "XyzEmployeeManager.H"
//#include "Utils.H"

//Global Manager Instance/Object.
//class XyzEmployeeManager manager;

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
#endif
