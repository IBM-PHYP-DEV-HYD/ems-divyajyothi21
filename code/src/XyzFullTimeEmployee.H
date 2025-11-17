#ifndef _XYZFULLTIMEEMPLOYEE_H_
#define _XYZFULLTIMEEMPLOYEE_H_
#include "XyzEmployee.H"
#include "XyzEmployeeSummaryBuilder.H"

class XyzFullTimeEmployee:public XyzEmployee
{
    private:
    int mLeavesAvailed; // 0 to 22
    public:
    XyzFullTimeEmployee();
    XyzFullTimeEmployee(std::string NameParm,
             std::string IdParm,
             EmployeeType EmployeeTypeParm,
             std::string GenderParm,
             std::string DojParm,
             std::string DobParm,
             EmployeeStatus EmployeeStatusParm,
             std::string DolParm,
             uint8_t AvailedLeavesParm);
    ~XyzFullTimeEmployee();
    void AddLeaves(int nParam);
    int GetLeavesAvailed();
    void PrintEmployeeDetails() const;
    void PrintSummaryRow() const;  // Override virtual method for polymorphic printing
};

#endif
