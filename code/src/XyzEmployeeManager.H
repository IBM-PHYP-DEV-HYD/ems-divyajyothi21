#ifndef _XYZEMPLOYEE_MANAGER_H_
#define _XYZEMPLOYEE_MANAGER_H_
#include "Deque.H"
#include "TestMenu.H"
#include "EmployeeIF.H"
#include "Edll.H"
#include "EdllMock.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmloyee.H"
#include "EmployeeUtils.H"
#include <string>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std::chrono_literals;

class XyzEmployeeManager
{
    private:
        Edll<XyzEmployee*> ActiveInactiveEmployeeList; 
        Edll<XyzEmployee*> ResignedEmployeeList;
        XyzEmployee* pCreateRandomEmployee();
        XyzEmployee* pCreateManualEmployee();
        XyzEmployee* pFindEmployeeById(Edll<XyzEmployee*>&ListParm,
                                       const std::string& IdParm,
                                       int& IndexParm) const;//IndexParm The output variable to store the 0-based index if found
                     
        void pFindEmployeeByName(Edll<XyzEmployee*>& ListParm,
                                 const std::string& NameParm,
                                 Edll<XyzEmployee*>& ResultsParm) const;
        void pPrintEmployeeSummary(Edll<XyzEmployee*>& ListParm) const;
    public:
        XyzEmployeeManager();
        ~XyzEmployeeManager();
        void AddEmployee();
        void AddRandomEmployee();
        void RemoveEmployee(const std::string& EmpIdParm);
        void ResignEmployee(const std::string& EmpIdParm);
        void GetFullSummary();
        void GetEmployeeSummaryByType(EmployeeType TypeParm);
        void GetEmployeeSummaryByGender(Gender GenderParm);
        void GetEmployeeSummaryByStatus(EmployeeStatus StatusParm);
        void DisplayEmployeeDetails(const std::string& EmpIdParm);
        void AddLeavesToFullTime(int NumLeavesParm);
        void ConvertInternToFullTime(const std::string& InternIdParm);
        void SearchEmployeeByID(const std::string& EmpIdParm);
        void searchEmployeeByName(const std::string& NameParm);
};

XyzEmployee* XyzEmployeeManager::pCreateRandomEmployee()
{
        // Mock data
        std::string sMockNames[] = {"Divya", "Shahjahan", "Kumar", "Rohini", "Aditya", "Debashish", "Nitisha"};
        std::string sMockDOB = "1990-01-01";
        std::string sMockDOJ = "2024-01-01";
        std::string sMockDOL = "2025-12-25";
        std::string sEmpId;

        std::string sName = sMockNames[EmployeeUtils::getRandomInt(0, 6)];
        EmployeeType sType = EmployeeUtils::getRandomEnum<EmployeeType>(EMP_TYPE_COUNT);
        EmployeeStatus sStatus = EmployeeUtils::getRandomEnum<EmployeeStatus>(EMP_STATUS_COUNT);
        Gender sGender = EmployeeUtils::getRandomEnum<Gender>(GENDER_COUNT);
        std::string sGenderString = EmployeeUtils::GenderToString(sGender);        
        sEmpId = EmployeeUtils::generateEmployeeId(sType);        

        XyzEmployee* sEmp = nullptr;

        switch (sType)
        {
            case FULL_TIME:
            {
                int sLeaves = EmployeeUtils::getRandomInt(0, 22);
                sEmp = new XyzFullTimeEmployee(sName,sEmpId,sType, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL,sLeaves);
                break;
            }
            case CONTRACTOR:
            {
                Agency sAgency = EmployeeUtils::getRandomEnum<Agency>(AGENCY_COUNT);
                std::string sAgencyString = EmployeeUtils::AgencyToString(sAgency);
                sEmp = new XyzContractorEmployee(sName, sEmpId, sType, sGenderString, sMockDOJ, sMockDOB, sStatus, sMockDOL, sAgency);
                break;
            }
            case INTERN:
            {
                College sCollege = EmployeeUtils::getRandomEnum<College>(COLLEGE_COUNT);
                Branch sBranch = EmployeeUtils::getRandomEnum<Branch>(BRANCH_COUNT);
                sEmp = new XyzInternEmployee(sName, sEmpId, sType, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL, sCollege, sBranch);
                break;
            }
            default: break;
        }

        // Handle Resigned status assignment for random generation
        if (sEmp && sStatus == RESIGNED)
        {
            sEmp->setDOL("2026-1-30"); // Mock DOL for resigned
        }
        else if (sEmp && sStatus != RESIGNED)
        {
            // Interns automatically get set to Active/Inactive.
            // Contractor and Full-time status is set directly in the constructor.
        }
        return sEmp;
}

/**
* @brief Helper to generate sEmployee data manually from user input.
* @param type The type of sEmployee to create.
* @return XyzEmployee* pointer to a new dynamically allocated sEmployee object.
*/
XyzEmployee* XyzEmployeeManager::pCreateManualEmployee()
{
        std::string sName, sEmpId, sGenderString;
        int sChoice;
        std::string sDOJ,sDOB,sDOL;
        XyzEmployee* sEmp = NULL;

        std::cout << "Enter Employee Name: ";
        std::cin.ignore();
        std::getline(std::cin, sName);

        std::cout << "Enter Date of Birth (YYYY-MM-DD): ";
        std::cin >> sDOB;
        
        std::cout << "Enter Date of Joining (YYYY-MM-DD): ";
        std::cin >> sDOJ;
        
       // std::cout << "Enter Date of Leaving (YYYY-MM-DD): ";
       // std::cin >> sDOL;
        
        // Get Gender
        std::cout << "Select Gender (0: Male, 1: Female, 2: Other): ";
        std::cin >> sChoice;
        Gender sGender = static_cast<Gender>(sChoice);
        sGenderString = EmployeeUtils::GenderToString(sGender);

        std::cout << "Select EmployeeStatus(0:ACTIVE, 1:INACTIVE, 2:RESIGNED):";
        std::cin >> sChoice;
        EmployeeStatus sStatus = static_cast<EmployeeStatus>(sChoice);

        // sType
        std::cout << "Select EmployeeType(0:FULL_TIME, 1:CONTRACTOR, 2:INTERN):";
        std::cin >> sChoice;
        EmployeeType sType = static_cast<EmployeeType>(sChoice); 
        sEmpId = EmployeeUtils::generateEmployeeId(sType);
        if (sType == FULL_TIME)
        {
            int sLeaves;
            std::cout << "Enter No of Leaves availed for fulltime employee (0-22):";
            std::cin >> sLeaves;
            if (sStatus == RESIGNED)
            {
                std::cout << "Enter Date of Leaving (YYYY-MM-DD):";
                std::cin >> sDOL;
            }
            else
            {
                sDOL = "NA";
            } 
            sEmp = new XyzFullTimeEmployee(sName, sEmpId, sType, sGenderString, sDOJ, sDOB, sStatus, sDOL, sLeaves);
        }
        else if (sType == CONTRACTOR)
        {
            std::cout << "Select External Agency (0: Avengers, 1: Justice League, 2: X-Men): ";
            std::cin >> sChoice;
            Agency sAgency = static_cast<Agency>(sChoice);
            sDOL = sDOJ;
            sEmp = new XyzContractorEmployee(sName, sEmpId, sType, sGenderString, sDOJ, sDOB, sStatus, sDOL, sAgency);
        }
        else if (sType == INTERN)
        {
            std::cout << "Select College (0: IIT Kanpur, 1: IIT Hyderabad, 2: NIT Warangal, 3: NIT Truchi): ";
            std::cin >> sChoice;
            College sCollege = static_cast<College>(sChoice);

            std::cout << "Select Branch (0: CSE, 1: CSIT, 2: ECE): ";
            std::cin >> sChoice;
            Branch sBranch = static_cast<Branch>(sChoice);
            sDOL = sDOJ; 
            sEmp = new XyzInternEmployee(sName, sEmpId, sType, sGenderString, sDOJ,sDOB,sStatus,sDOL, sCollege, sBranch);
        }
        return sEmp;
}

/**
* @brief Iterates through a list and finds an employee by ID.
* @param list The list to search in.
* @param id The Employee ID string to match.
* @param index The output variable to store the 0-based index if found.
* @return XyzEmployee* The pointer to the found employee, or nullptr if not found.
*/
XyzEmployee* XyzEmployeeManager::pFindEmployeeById(Edll<XyzEmployee*>& listPtrParm, const std::string& IdParm, int& IndexParm) const
{
    Node<XyzEmployee*>* sCurrent = listPtrParm.getHead();
    IndexParm = 0;
    while (sCurrent != nullptr)
    {
       if (sCurrent->mData->GetEmployeeId() == IdParm)
       {
            return sCurrent->mData;
       }
       sCurrent = sCurrent->mNext;
       ++IndexParm;
    }
    IndexParm = -1; // Not found
    return nullptr;
}

/**
 * @brief Finds an employee by name (or part of name).
 * @param ListPtrParm The list to search in.
 * @param NameParm The name or part of the name to search for.
 * @param ResultParm The list to store found employees.
 */
void XyzEmployeeManager::pFindEmployeeByName(Edll<XyzEmployee*>& ListPtrParm, const std::string& NameParm, Edll<XyzEmployee*>& ResultParm) const
{
    // 1. Prepare search term for case-insensitivity
    std::string lower_NameParm = NameParm;
    std::transform(lower_NameParm.begin(), lower_NameParm.end(), lower_NameParm.begin(), 
                   ::tolower);

    // Clear any previous results from the output parameter
    ResultParm.clear(); 

    // 2. Iterate using the public index access (assuming Edll/Deque supports it)
    for (int sIdx = 0; sIdx < ListPtrParm.size(); ++sIdx)
    {
        // Get the employee POINTER at the current index (T is XyzEmployee*)
        XyzEmployee* currentEmployee = ListPtrParm.getElementAt(sIdx);
        
        // Safety check
        if (!currentEmployee) {
            continue; 
        }

        // 3. Get employee name and prepare it for case-insensitivity
        std::string emp_name = currentEmployee->GetEmployeeName();
        std::string lower_emp_name = emp_name;
        std::transform(lower_emp_name.begin(), lower_emp_name.end(), lower_emp_name.begin(), 
                       ::tolower);

        // 4. Perform substring search
        if (lower_emp_name.find(lower_NameParm) != std::string::npos)
        {   
            // Add the matching employee pointer to the result list
            ResultParm.push_back(currentEmployee);
        }
    }
}

/**
 * @brief Prints a summary of all employees in a given list.
 */
void XyzEmployeeManager::pPrintEmployeeSummary(Edll<XyzEmployee*>& ListParm) const
{
    if (ListParm.empty()) {
        std::cout << "No employees in this list.\n";
        return;
    }
    std::cout << "\n----------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "Employee Name      | ID        | Type        | Status    | Gender | Date of Birth | Date of Joining | Date of Leaving\n";
    std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
    Node<XyzEmployee*>* sCurrent = ListParm.getHead();
    while (sCurrent != nullptr)
    {
        XyzEmployee* emp = sCurrent->mData;
        printf("%-18s | %-9s | %-11s | %-9s | %-6s | %-13s | %-15s | %s\n",
               emp->GetEmployeeName().c_str(), emp->GetEmployeeId().c_str(),
               EmployeeUtils::EmployeeTypeToString(emp->GetEmployeeType()).c_str(),
               EmployeeUtils::EmployeeStatusToString(emp->GetEmployeeStatus()).c_str(),
               (emp->GetEmployeeGender()).c_str(),
               emp->GetEmployeeDOB().c_str(), emp->GetEmployeeDOJ().c_str(), emp->GetEmployeeDOL().c_str());
        sCurrent = sCurrent->mNext;
    }
    std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
}


XyzEmployeeManager::XyzEmployeeManager()
{
    // Seed random number generator only once
    std::srand(std::time(0));
}

// Destructor must free all dynamically allocated employee objects
XyzEmployeeManager::~XyzEmployeeManager()
{
    // 1. Delete all employees in the active/inactive list
    Node<XyzEmployee*>* current = ActiveInactiveEmployeeList.getHead();
    while (current != nullptr)
    {
        delete current->mData; // Delete the employee object
        current = current->mNext;
    }
    // 2. Delete all employees in the resigned list
    current = ResignedEmployeeList.getHead();
    while (current != nullptr)
    {
        delete current->mData; // Delete the employee object
        current = current->mNext;
    }
    std::cout << "\n[Manager] All employee objects successfully deleted.\n";
    // The DLL destructors handle node cleanup automatically.
}

void XyzEmployeeManager::AddEmployee()
{
    XyzEmployee* newEmp = pCreateManualEmployee();
    if (newEmp)
    {
        if (newEmp->GetEmployeeStatus() == RESIGNED)
        {
            // If Given Em,ployee status as resigned, put in resigned list
            ResignedEmployeeList.push_back(newEmp);
        } else
        {
            ActiveInactiveEmployeeList.push_back(newEmp);
        }
        std::cout << "Employee " << newEmp->GetEmployeeName() << " (" << newEmp->GetEmployeeId() << ") added successfully.\n";

    }
    else
    {
        std::cout << "Error creating employee.\n";
    }
}

void XyzEmployeeManager::AddRandomEmployee()
{
    XyzEmployee* newEmp = pCreateRandomEmployee();
    if (newEmp)
    {
        if (newEmp->GetEmployeeStatus() == RESIGNED)
        {
            // If randomly generated as resigned, put in resigned list
            ResignedEmployeeList.push_back(newEmp);
        } else
        {
            ActiveInactiveEmployeeList.push_back(newEmp);
        }
        std::cout << "Random Employee " << newEmp->GetEmployeeName() << " (" << newEmp->GetEmployeeId() << ") added successfully.\n";
    } 
    else
    {
        std::cout << "Error creating random employee.\n";
    }
}

void XyzEmployeeManager::RemoveEmployee(const std::string& empId)
{
    int index = -1;
    XyzEmployee* emp = pFindEmployeeById(ActiveInactiveEmployeeList, empId, index);

    if (emp && index != -1) {
        // Found in active list, remove it
        ActiveInactiveEmployeeList.DeleteElementAtGivenIndex(index);
        std::cout << "Employee " << emp->GetEmployeeName() << " (" << emp->GetEmployeeId() << ") removed and memory freed.\n";
        delete emp; // Free employee object memory immediately
        return;
    }

    // Check resigned list
    emp = pFindEmployeeById(ResignedEmployeeList, empId, index);
    if (emp && index != -1) {
        // Found in resigned list, remove it
        ResignedEmployeeList.DeleteElementAtGivenIndex(index);
        std::cout << "Employee " << emp->GetEmployeeName() << " (" << emp->GetEmployeeId() << ") removed from resigned list and memory freed.\n";
        delete emp; // Free employee object memory immediately
        return;
    }

    std::cout << "Error: Employee with ID " << empId << " not found in any list.\n";
}

void XyzEmployeeManager::ResignEmployee(const std::string& empId)
{
    int index = -1;
    XyzEmployee* sEmp = pFindEmployeeById(ActiveInactiveEmployeeList, empId, index);

    if (sEmp && index != -1)
    {
        // 1. Remove from active list
        ActiveInactiveEmployeeList.DeleteElementAtGivenIndex(index);

        // 2. Update status and DOL
        sEmp->setStatus(RESIGNED);
        // Mock Date of Leaving to be current year
        sEmp->setDOL("2025-10-03");

        // 3. Add to resigned list
        ResignedEmployeeList.push_back(sEmp);
        std::cout << "Employee " << sEmp->GetEmployeeName() << " (" << sEmp->GetEmployeeId() << ") resigned and moved to resigned list.\n";
        return;
    }
    std::cout << "Error: Employee with ID " << empId << " not found in active list.\n";
}



void XyzEmployeeManager::GetFullSummary()
{
    std::cout << "\n--- ALL EMPLOYEES SUMMARY (ACTIVE/INACTIVE) ---\n";
    pPrintEmployeeSummary(ActiveInactiveEmployeeList);
    std::cout << "\n--- RESIGNED EMPLOYEES SUMMARY ---\n";
    pPrintEmployeeSummary(ResignedEmployeeList);
}

void XyzEmployeeManager::GetEmployeeSummaryByType(EmployeeType EmployeeTypeParm)
{
    std::cout << "\n--- " << EmployeeUtils::EmployeeTypeToString(EmployeeTypeParm) << " EMPLOYEES SUMMARY ---\n";
    Edll<XyzEmployee*> temp;
    Node<XyzEmployee*>* current = ActiveInactiveEmployeeList.getHead();
    while (current != nullptr)
    {
        if (current->mData->GetEmployeeType() == EmployeeTypeParm)
        {
            temp.push_back(current->mData);
        }
        current = current->mNext;
    }
    pPrintEmployeeSummary(temp);
}

void XyzEmployeeManager::GetEmployeeSummaryByGender(Gender tarGetEmployeeGender)
{
    std::cout << "\n--- " << EmployeeUtils::GenderToString(tarGetEmployeeGender) << " EMPLOYEES SUMMARY ---\n";
    Edll<XyzEmployee*> temp;
    Node<XyzEmployee*>* current = ActiveInactiveEmployeeList.getHead();
    while (current != nullptr)
    {
        if (current->mData->GetEmployeeGender() == EmployeeUtils::GenderToString(tarGetEmployeeGender))
        {
            temp.push_back(current->mData);
        }
        current = current->mNext;
    }
    pPrintEmployeeSummary(temp);
}

void XyzEmployeeManager::GetEmployeeSummaryByStatus(EmployeeStatus tarGetEmployeeStatus)
{
    std::cout << "\n--- " << EmployeeUtils::EmployeeStatusToString(tarGetEmployeeStatus) << " EMPLOYEES SUMMARY ---\n";
    Edll<XyzEmployee*>* listToSearch = (tarGetEmployeeStatus == RESIGNED) ? &ResignedEmployeeList : &ActiveInactiveEmployeeList;
    Edll<XyzEmployee*> temp;

    Node<XyzEmployee*>* current = listToSearch->getHead();
    while (current != nullptr)
    {
        if (current->mData->GetEmployeeStatus() == tarGetEmployeeStatus)
        {
            temp.push_back(current->mData);
        }
        current = current->mNext;
    }
    pPrintEmployeeSummary(temp);
}

void XyzEmployeeManager::DisplayEmployeeDetails(const std::string& empId)
{
    int index = -1;
    XyzEmployee* sEmp = pFindEmployeeById(ActiveInactiveEmployeeList, empId, index);
    if (!sEmp)
    {
        sEmp = pFindEmployeeById(ResignedEmployeeList, empId, index);
    }

    if (sEmp)
    {
        sEmp->PrintEmployeeDetails();
    } 
    else
    {
        std::cout << "Error: Employee with ID " << empId << " not found.\n";
    }
}

// --- Sub-Menu 3 Operations ---

void XyzEmployeeManager::AddLeavesToFullTime(int numLeaves)
{
    Node<XyzEmployee*>* current = ActiveInactiveEmployeeList.getHead();
    int count = 0;
    while (current != nullptr) {
        if (current->mData->GetEmployeeType() == FULL_TIME) {
            XyzFullTimeEmployee* ft_emp = dynamic_cast<XyzFullTimeEmployee*>(current->mData);
            if (ft_emp) {
                ft_emp->AddLeaves(numLeaves);
                count++;
            }
        }
        current = current->mNext;
    }
    std::cout << "Added " << numLeaves << " leaves to " << count << " Full-Time employees.\n";
}

void XyzEmployeeManager::ConvertInternToFullTime(const std::string& internIdParm)
{
    int sIndex = -1;
    XyzEmployee* emp = pFindEmployeeById(ActiveInactiveEmployeeList, internIdParm, sIndex);

    if (!emp || emp->GetEmployeeType() != INTERN) {
        std::cout << "Error: Intern with ID " << internIdParm << " not found in active list.\n";
        return;
    }

    // 1. Remove intern from active list
    ActiveInactiveEmployeeList.DeleteElementAtGivenIndex(sIndex);

    // 2. Create a new Full-Time Employee object using the intern's data
    XyzEmployee* newEmp = new XyzFullTimeEmployee(
        emp->GetEmployeeName(), EmployeeUtils::generateEmployeeId(FULL_TIME), FULL_TIME, emp->GetEmployeeGender(),emp->GetEmployeeDOJ()/*This need to modified as current/todaysdate*/, emp->GetEmployeeDOB(), ACTIVE,"NA", 2);

    // 3. Delete the old intern object
    delete emp;

    // 4. Add the new Full-Time Employee to the active list
    ActiveInactiveEmployeeList.push_back(newEmp);
    std::cout << "Intern " << internIdParm << " converted successfully to Full-Time Employee (" << newEmp->GetEmployeeId() << ").\n";
}

void XyzEmployeeManager::SearchEmployeeByID(const std::string& empId)
{
    int index = -1;
    XyzEmployee* emp = pFindEmployeeById(ActiveInactiveEmployeeList, empId, index);
    if (!emp)
    {
        emp = pFindEmployeeById(ResignedEmployeeList, empId, index);
    }

    if (emp)
    {
        std::cout << "\n--- Search Result ---\n";
        emp->PrintEmployeeDetails();
    }
    else
    {
        std::cout << "Employee with ID " << empId << " not found.\n";
    }
}

void XyzEmployeeManager::searchEmployeeByName(const std::string& namePart)
{
    Edll<XyzEmployee*> results;
    pFindEmployeeByName(ActiveInactiveEmployeeList, namePart, results);
    pFindEmployeeByName(ResignedEmployeeList, namePart, results);

    if (results.empty())
    {
        std::cout << "No employees found matching '" << namePart << "'.\n";
        return;
    }

    std::cout << "\n--- Search Results for '" << namePart << "' ---\n";
    Node<XyzEmployee*>* current = results.getHead();
    while (current != nullptr)
    {
        current->mData->PrintEmployeeDetails();
        current = current->mNext;
    }
    // The results list only contains pointers to existing employees, no deletion needed here.
}
#endif
