#include "XyzEmployeeManager.H"
#include "XyzEmployee.H"

XyzEmployee* XyzEmployeeManager::pCreatEmployeeBasedonType(EmployeeType TypeParm)
{
        std::string sMockNames[] = {"Divya", "Shahjahan", "Kumar", "Rohini", "Aditya", "Debashish", "Nitisha", "lakshmi",
                                    "karthik","aniketh","surya","Dilip","veeramani","arun","isha","priyanka","jagan",
                                    "gnani", "jaswith", "Prathima","Teja","Prasanna"};

        std::string sMockDOB = EmployeeUtils::genDate(1970, 2005);
        std::string sMockDOJ = EmployeeUtils::genDate(2015, 2025);
        std::string sMockDOL = EmployeeUtils::genDate(2026, 2026);

        std::string sEmpId;

        std::string sName = sMockNames[EmployeeUtils::getRandomInt(0, 21)];
        EmployeeStatus sStatus = EmployeeUtils::getRandomEnum<EmployeeStatus>(EMP_STATUS_COUNT);
        Gender sGender = EmployeeUtils::getRandomEnum<Gender>(GENDER_COUNT);
        std::string sGenderString = EmployeeUtils::GenderToString(sGender);
        sEmpId = EmployeeUtils::generateEmployeeId(TypeParm);

        XyzEmployee* sEmp = nullptr;

        switch (TypeParm)
        {
            case FULL_TIME:
            {
                int sLeaves = EmployeeUtils::getRandomInt(0, 22);
                if (sStatus != RESIGNED)
                {
                    sMockDOL = "NA";
                    sEmp = new XyzFullTimeEmployee(sName,sEmpId,TypeParm, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL, sLeaves);
                }
                else
                {
                    std::string sTodaysDate = EmployeeUtils::GetTodaysDate();
                    sMockDOL = EmployeeUtils::CalculateFutureDate(sTodaysDate, 3, 0);
                    sEmp = new XyzEmployee(sName,sEmpId,TypeParm, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL);
                }
                break;
            }
            case CONTRACTOR:
            {
                Agency sAgency = EmployeeUtils::getRandomEnum<Agency>(AGENCY_COUNT);
                if(sStatus != RESIGNED)
                {
                    std::string sAgencyString = EmployeeUtils::AgencyToString(sAgency);
                    sMockDOL =  EmployeeUtils::CalculateFutureDate(sMockDOJ, 6, 0);
                    if (sMockDOL < EmployeeUtils::GetTodaysDate())
                    {
                        sStatus = RESIGNED;
                        sEmp = new XyzEmployee(sName,sEmpId,TypeParm, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL);
                    }
                    else
                    {
                        sEmp = new XyzContractorEmployee(sName, sEmpId, TypeParm, sGenderString, sMockDOJ, sMockDOB, sStatus, sMockDOL, sAgency);
                    }
                }
                else
                {
                    sMockDOL = EmployeeUtils::CalculateFutureDate(sMockDOJ, 6, 0);
                    sEmp = new XyzEmployee(sName,sEmpId,TypeParm, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL);
                }
                break;
            }
            case INTERN:
            {
                if(sStatus != RESIGNED)
                {
                    College sCollege = EmployeeUtils::getRandomEnum<College>(COLLEGE_COUNT);
                    Branch sBranch = EmployeeUtils::getRandomEnum<Branch>(BRANCH_COUNT);
                    sMockDOL = EmployeeUtils::CalculateFutureDate(sMockDOJ, 0, 1);
                    if (sMockDOL < EmployeeUtils::GetTodaysDate())
                    {
                        sStatus = RESIGNED;
                        sEmp = new XyzEmployee(sName,sEmpId,TypeParm, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL);
                    }
                    else
                    {
                        sEmp = new XyzInternEmployee(sName, sEmpId, TypeParm, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL, sCollege, sBranch);
                    }
                }
                else
                {
                    
                    sEmp = new XyzEmployee(sName,sEmpId,TypeParm, sGenderString, sMockDOJ,sMockDOB,sStatus,sMockDOL);
                }
                break;
            }
            default: break;
        }
        return sEmp;
}

XyzEmployee* XyzEmployeeManager::pCreateRandomEmployee()
{
    EmployeeType sType = EmployeeUtils::getRandomEnum<EmployeeType>(EMP_TYPE_COUNT);
    XyzEmployee* sEmp = pCreatEmployeeBasedonType(sType);
    return sEmp;
}

/**
* @brief Helper to generate Employee data manually from user input.
* @return XyzEmployee* pointer to a new dynamically allocated sEmployee object.
*/
XyzEmployee* XyzEmployeeManager::pCreateManualEmployee()
{
        int sChoice;
        std::cout << "Select EmployeeType(0:FULL_TIME, 1:CONTRACTOR, 2:INTERN):";
        std::cin >> sChoice;
        EmployeeType sType = static_cast<EmployeeType>(sChoice);
        XyzEmployee* sEmp = pCreatEmployeeBasedonType(sType);
        return sEmp;
}

/**
* @brief Iterates through a list and finds an employee by ID.
* @param listPtrParm The list to search in.
* @param IdParm The Employee ID string to match.
* @param IndexParm The output variable to store the 0-based index if found.
* @return XyzEmployee* The pointer to the found employee, or nullptr if not found.
*/
XyzEmployee* XyzEmployeeManager::pFindEmployeeById(Edll<XyzEmployee*>& listPtrParm, const std::string& IdParm, int& IndexParm) const
{
    Node<XyzEmployee*>* sCurrent = listPtrParm.getHead();
    IndexParm = 0;
    while (sCurrent != NULL)
    {
       if (sCurrent->mData->GetEmployeeId() == IdParm)
       {
            return sCurrent->mData;
       }
       sCurrent = sCurrent->mNext;
       ++IndexParm;
    }
    IndexParm = -1; // Not found
    return NULL;
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
    //ResultParm.clear();

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
void XyzEmployeeManager::pPrintEmployeeSummary(Edll<XyzEmployee*>& ListParm, bool IsActiveEmpParm) const
{
    if (ListParm.empty()) {
        std::cout << "No employees in this list.\n";
        return;
    }

    // Use builder pattern for header and footer
    XyzEmployeeSummaryBuilder::printHeader(IsActiveEmpParm);

    Node<XyzEmployee*>* sCurrent = ListParm.getHead();
    while (sCurrent != nullptr)
    {
        // Polymorphic call to PrintSummaryRow() which uses builder internally
        sCurrent->mData->PrintSummaryRow();
        sCurrent = sCurrent->mNext;
    }

    XyzEmployeeSummaryBuilder::printFooter(IsActiveEmpParm);
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
    Node<XyzEmployee*>* sCurrentPtr = ActiveInactiveEmployeeList.getHead();
    while (!sCurrentPtr)
    {
        delete sCurrentPtr->mData; // Delete the employee object
        sCurrentPtr = sCurrentPtr->mNext;
    }
    // 2. Delete all employees in the resigned list
    sCurrentPtr = ResignedEmployeeList.getHead();
    while (sCurrentPtr)
    {
        delete sCurrentPtr->mData; // Delete the employee object
        sCurrentPtr = sCurrentPtr->mNext;
    }
    std::cout << "\n[Manager] All employee objects successfully deleted.\n";
    // The DLL destructors handle node cleanup automatically.
}

void XyzEmployeeManager::AddEmployee()
{
    XyzEmployee* sNewEmp = pCreateManualEmployee();
    if (sNewEmp)
    {
        if (sNewEmp->GetEmployeeStatus() == RESIGNED)
        {
            // If Given Employee status as resigned, put in resigned list
            ResignedEmployeeList.push_back(sNewEmp);
        }
        else
        {
            ActiveInactiveEmployeeList.push_back(sNewEmp);
        }
        std::cout << "Employee " << sNewEmp->GetEmployeeName() << " (" << sNewEmp->GetEmployeeId() << ") added successfully.\n";

    }
    else
    {
        std::cout << "Error creating employee.\n";
    }
}

void XyzEmployeeManager::AddRandomEmployee()
{
    XyzEmployee* sNewEmpPtr = pCreateRandomEmployee();
    if (sNewEmpPtr)
    {
        if (sNewEmpPtr->GetEmployeeStatus() == RESIGNED)
        {
            // If randomly generated as resigned, put in resigned list
            ResignedEmployeeList.push_back(sNewEmpPtr);
        }
        else
        {
            ActiveInactiveEmployeeList.push_back(sNewEmpPtr);
        }
        std::cout << "Random Employee " << sNewEmpPtr->GetEmployeeName() << " (" << sNewEmpPtr->GetEmployeeId() << ") added successfully.\n";
    }
    else
    {
        std::cout << "Error creating random employee.\n";
    }
}

void XyzEmployeeManager::RemoveEmployee(const std::string& empIdParm)
{
    ResignEmployee(empIdParm);
}

void XyzEmployeeManager::ResignEmployee(const std::string& empIdParm)
{
    int sIdx = -1;
    std::string sEmpDOl;
    XyzEmployee* sEmpPtr = pFindEmployeeById(ActiveInactiveEmployeeList, empIdParm, sIdx);

    if (sEmpPtr && sIdx != -1)
    {
        // 1. Remove from active list
        ActiveInactiveEmployeeList.DeleteElementAtGivenIndex(sIdx);

        // 2. Update status and DOL
        sEmpPtr->setStatus(RESIGNED);
        
        sEmpDOl = sEmpPtr->GetEmployeeDOL();
        std::string sTodaysDate = EmployeeUtils::GetTodaysDate();
        // Mock Date of Leaving to be current year
        if (sEmpDOl == "NA")
        {
            std::string sTodaysDate = EmployeeUtils::GetTodaysDate();
            sEmpDOl = EmployeeUtils::CalculateFutureDate(sTodaysDate, 3, 0);   
        }
        else if(sEmpDOl > EmployeeUtils::CalculateFutureDate(sTodaysDate, 3, 0))
        {
            sEmpDOl = EmployeeUtils::CalculateFutureDate(sTodaysDate, 3, 0);  
            
        }
        
        // 3. Add to resigned list
        ResignedEmployeeList.push_back(sEmpPtr);
        std::cout << "Employee " << sEmpPtr->GetEmployeeName() << " (" << sEmpPtr->GetEmployeeId() << ") resigned and moved to resigned list.\n";
        return;
    }
    std::cout << "Error: Employee with ID " << empIdParm << " not found in active list.\n";
}

void XyzEmployeeManager::GetFullSummary()
{
    std::cout << "\n====ACTIVE-INACTIVE EMPLOYEES SUMMARY====\n";
    pPrintEmployeeSummary(ActiveInactiveEmployeeList, 1);
    std::cout << "\n====RESIGNED EMPLOYEES SUMMARY====\n";
    pPrintEmployeeSummary(ResignedEmployeeList, 0);
}

void XyzEmployeeManager::GetEmployeeSummaryByType(EmployeeType EmployeeTypeParm)
{
    std::cout << "\n--- " << EmployeeUtils::EmployeeTypeToString(EmployeeTypeParm) << " EMPLOYEES SUMMARY ---\n";
    Edll<XyzEmployee*> sTemp;
    Node<XyzEmployee*>* sCurrentPtr = ActiveInactiveEmployeeList.getHead();
    while (!sCurrentPtr)
    {
        if (sCurrentPtr->mData->GetEmployeeType() == EmployeeTypeParm)
        {
            sTemp.push_back(sCurrentPtr->mData);
        }
        sCurrentPtr = sCurrentPtr->mNext;
    }
    pPrintEmployeeSummary(sTemp, 1);
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
    pPrintEmployeeSummary(temp, 1);
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
    pPrintEmployeeSummary(temp, (tarGetEmployeeStatus != RESIGNED));
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

void XyzEmployeeManager::AddLeavesToFullTime(int LeavesParm)
{
    Node<XyzEmployee*>* sCurrentPtr = NULL;
    int sCount = 0;
    if (LeavesParm >= 22 || LeavesParm <= 0)
    {
        std::cout << "Invalid number of leaves given" << std::endl;
        return;
    }
    sCurrentPtr = ActiveInactiveEmployeeList.getHead();
    while (sCurrentPtr != nullptr)
    {
        if (sCurrentPtr->mData->GetEmployeeType() == FULL_TIME)
        {
            XyzFullTimeEmployee* sFullEmpPtr = dynamic_cast<XyzFullTimeEmployee*>(sCurrentPtr->mData);
            if (sFullEmpPtr)
            {
                sFullEmpPtr->AddLeaves(LeavesParm);
                sCount++;
            }
        }
        sCurrentPtr = sCurrentPtr->mNext;
    }
    std::cout << "Added " << LeavesParm << " leaves to " << sCount << " Full-Time employees.\n";
}

void XyzEmployeeManager::ConvertInternToFullTime(const std::string& internIdParm)
{
    int sIndex = -1;
    // 1. Find the employee and its index
    XyzEmployee* sEmpPtr = pFindEmployeeById(ActiveInactiveEmployeeList, internIdParm, sIndex);

    // 2. Initial validation checks
    if (!sEmpPtr) {
        std::cout << "Error: Employee with ID " << internIdParm << " not found in active list.\n";
        return;
    }
    
    // Check if the employee is of the convertible type (INTERN or CONTRACTOR)
    if (sEmpPtr->GetEmployeeType() != INTERN && sEmpPtr->GetEmployeeType() != CONTRACTOR) {
        std::cout << "Error: Employee ID " << internIdParm << " is not an Intern or Contractor.\n";
        return;
    }

    // Check if tenure is complete
    if (EmployeeUtils::GetTodaysDate() < sEmpPtr->GetEmployeeDOL()) {
        std::cout << "Still Contractor/Intern tenure not completed to change to Fulltime Employee" << std::endl;
        return;
    }

    // 3. Create a new Full-Time Employee object using the intern's data
    // The data is accessed via the sEmpPtr getters. This is the correct way.
    XyzFullTimeEmployee* sNewEmpPtr = new XyzFullTimeEmployee(
        sEmpPtr->GetEmployeeName(),
        EmployeeUtils::generateEmployeeId(FULL_TIME), // New ID for the new type
        FULL_TIME,
        sEmpPtr->GetEmployeeGender(),
        EmployeeUtils::GetTodaysDate(), // New Start Date (or current date)
        sEmpPtr->GetEmployeeDOB(),
        ACTIVE,
        "NA",
        0
    );

    // 4. Delete the old object and its memory
    delete sEmpPtr;

    // 5. Remove the **old pointer** from the list
    ActiveInactiveEmployeeList.DeleteElementAtGivenIndex(sIndex);
    
    // 6. Add the new Full-Time Employee pointer to the list
    ActiveInactiveEmployeeList.push_back(sNewEmpPtr);

    std::cout << "Intern/Contarctor " << internIdParm << " converted successfully to Full-Time Employee (" << sNewEmpPtr->GetEmployeeId() << ").\n";
}

void XyzEmployeeManager::SearchEmployeeByID(const std::string& empIdParm)
{
    int sIdx = -1;
    XyzEmployee* sEmpPtr = pFindEmployeeById(ActiveInactiveEmployeeList, empIdParm, sIdx);
    if (!sEmpPtr)
    {
        sEmpPtr = pFindEmployeeById(ResignedEmployeeList, empIdParm, sIdx);
    }
    if (sEmpPtr)
    {
        std::cout << "\n--- Search Result ---\n";
        sEmpPtr->PrintEmployeeDetails();
    }
    else
    {
        std::cout << "Employee with ID " << empIdParm << " not found.\n";
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
