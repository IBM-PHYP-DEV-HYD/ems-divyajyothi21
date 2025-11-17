#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include "EmployeeIF.H"

// Base Employee Class
class XyzEmployee:public EmployeeIF
{
protected:
    std::string mName;
    std::string mEmployeeId;
    EmployeeType mEmployeeType;
    std::string mGender;
    std::string mDateOfJoining;
    std::string mDateOfBirth;
    EmployeeStatus mEmployeeStatus;
    std::string mDateOfLeaving;//For Perminate NA, for Temp DOJ+1 year, for Contarctor DOJ+6months
public:
    XyzEmployee(); //default constructor
    XyzEmployee(std::string NameParm,
             std::string IdParm,
             EmployeeType EmpTypeParm,
             std::string GenderParm,
             std::string DojParm,
             std::string DobParm,
             EmployeeStatus EmployeeStatusParm,
             std::string DolParm); //Parameterized constructor
    virtual ~XyzEmployee(); //Destructor

    //Getters
    std::string GetEmployeeName() const;
    std::string GetEmployeeId() const;
    EmployeeType GetEmployeeType() const;
    EmployeeStatus GetEmployeeStatus() const;
    std::string GetEmployeeGender() const;
    std::string GetEmployeeDOB() const;
    std::string GetEmployeeDOJ() const;
    std::string GetEmployeeDOL() const;
    void PrintEmployeeDetails() const;
    // Pure virtual method for printing summary row (called by manager during summary print)
    void PrintSummaryRow() const;    
    //Setters
    void setStatus(EmployeeStatus newStatusParm);
    void setDOL(const std::string& dateParm);

    // Overload the << operator to allow easy printing
   // friend std::ostream& operator<<(std::ostream& osParm, const XyzEmployee& EmployeeParm);
   // friend std::istream& operator>>(std::istream& isParm, XyzEmployee& EmployeeParm);
};
#endif
