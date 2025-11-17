#ifndef _XYZEMPLOYEE_MANAGER_H_
#define _XYZEMPLOYEE_MANAGER_H_
#include "Deque.H"
#include "TestMenu.H"
#include "EmployeeIF.H"
#include "Edll.H"
#include "EdllMock.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractorEmployee.H"
#include "XyzInternEmployee.H"
#include "EmployeeUtils.H"
#include "XyzEmployeeSummaryBuilder.H"
#include <string>
#include <iostream>
#include <chrono>
#include <cstdio>

class XyzEmployeeManager
{
    private:
        Edll<XyzEmployee*> ActiveInactiveEmployeeList; 
        Edll<XyzEmployee*> ResignedEmployeeList;
        XyzEmployee* pCreatEmployeeBasedonType(EmployeeType TypeParm);
        XyzEmployee* pCreateRandomEmployee();
        XyzEmployee* pCreateManualEmployee();
        XyzEmployee* pFindEmployeeById(Edll<XyzEmployee*>&ListParm,
                                       const std::string& IdParm,
                                       int& IndexParm) const;//IndexParm The output variable to store the 0-based index if found
                     
        void pFindEmployeeByName(Edll<XyzEmployee*>& ListParm,
                                 const std::string& NameParm,
                                 Edll<XyzEmployee*>& ResultsParm) const;
        void pPrintEmployeeSummary(Edll<XyzEmployee*>& ListParm,  bool IsActiveEmpParm) const;
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
#endif
