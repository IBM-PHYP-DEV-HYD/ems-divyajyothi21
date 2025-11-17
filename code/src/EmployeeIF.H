#ifndef _EMPLOYEE_IF_H_
#define _EMPLOYEE_IF_H_
#include "string"
#include "iostream"
#include "EmployeeUtils.H"

class EmployeeIF
{
public:
    virtual ~EmployeeIF();
    virtual std::string GetEmployeeName() const = 0;
    virtual std::string GetEmployeeId() const = 0;
    virtual EmployeeType GetEmployeeType() const = 0;
    virtual EmployeeStatus GetEmployeeStatus() const = 0;
    virtual std::string GetEmployeeGender() const = 0;
    virtual std::string GetEmployeeDOB() const = 0;
    virtual std::string GetEmployeeDOJ() const = 0;
    virtual std::string GetEmployeeDOL() const = 0; // Date of leaving
   virtual void PrintEmployeeDetails() const = 0;
    // Pure virtual method for printing summary row (called by manager during summary print)
    virtual void PrintSummaryRow() const = 0;
};

#endif
