#include "XyzEmployee.H"
#include "XyzEmployeeSummaryBuilder.H"

//default constructor
XyzEmployee::XyzEmployee():mName("Divya"),mEmployeeId("XYZ0001F"),mGender("Female"),mDateOfJoining("14May2014"),mDateOfBirth("04Sep1992"),
                     mEmployeeStatus(EmployeeStatus::ACTIVE),mDateOfLeaving("NA")
{
    std::cout << "Default Employee Constructor is called" << std::endl;
}

//Parameterized Constructor
XyzEmployee::XyzEmployee(std::string NameParm,
                   std::string IdParm,
                   EmployeeType EmpTypeParm,
                   std::string GenderParm,
                   std::string DojParm,
                   std::string DobParm,
                   EmployeeStatus EmployeeStatusParm,
                   std::string DolParm):mName(NameParm),
                                        mEmployeeId(IdParm),
                                        mEmployeeType(EmpTypeParm),
                                        mGender(GenderParm),
                                        mDateOfJoining(DojParm),
                                        mDateOfBirth(DobParm),
                                        mEmployeeStatus(EmployeeStatusParm),
                                        mDateOfLeaving(DolParm)
{
    std::cout << "Parameterized Constructor got created" << std::endl;
}

XyzEmployee::~XyzEmployee()
{
    std::cout << "Employee Destructor got called" <<std::endl;
}

std::string XyzEmployee::GetEmployeeName() const
{
    return this->mName;
}

std::string XyzEmployee::GetEmployeeId() const
{
    return this->mEmployeeId;
}

EmployeeType XyzEmployee::GetEmployeeType() const
{
    return this->mEmployeeType;
}

EmployeeStatus XyzEmployee::GetEmployeeStatus() const
{
    return mEmployeeStatus;
}

std::string XyzEmployee::GetEmployeeGender() const
{
    return this->mGender;
}

std::string XyzEmployee::GetEmployeeDOB() const
{
    return this->mDateOfBirth;
}
std::string XyzEmployee::GetEmployeeDOJ() const
{
    return this->mDateOfJoining;
}

std::string XyzEmployee::GetEmployeeDOL() const
{
    return this->mDateOfLeaving;
}

void XyzEmployee::setStatus(EmployeeStatus newStatusParm)
{
    this->mEmployeeStatus = newStatusParm;
}

void XyzEmployee::setDOL(const std::string& dateParm)
{
    this->mDateOfLeaving = dateParm;
}

/*std::ostream& operator<<(std::ostream& osParm, const XyzEmployee& EmployeeParm)
{
        osParm << "Name:" << EmployeeParm.mName <<" "<< "EmpId:" <<EmployeeParm.mEmployeeId;
        return osParm;
}

std::istream& operator>>(std::istream& isParm, XyzEmployee& EmployeeParm)
{
    std::cout << "Enter Employee name: ";
    // Use std::getline to read the entire line, including spaces
    // The std::ws manipulator skips any leading whitespace
    std::getline(isParm >> std::ws, EmployeeParm.mName);
    std::cout << "Enter Employee ID: ";
    isParm >> EmployeeParm.mEmployeeId;
    return isParm;
}*/

void XyzEmployee::PrintEmployeeDetails() const
{
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Employee Name  : " << this->mName << std::endl;
        std::cout << "Employee ID    : " << this->mEmployeeId << std::endl;
        std::cout << "Employee Type  : " << EmployeeUtils::EmployeeTypeToString(this->mEmployeeType) << std::endl;
        std::cout << "Employee Status: " << EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus) << std::endl;
        std::cout << "Gender         : " << this->mGender << std::endl;
        std::cout << "Date of Birth  : " << this->mDateOfBirth << std::endl;
        std::cout << "Date of Joining: " << this->mDateOfJoining << std::endl;
        std::cout << "Date of Leaving: " << this->mDateOfLeaving << std::endl;
        std::cout << "-----------------------------------------" <<std::endl;
}

void XyzEmployee::PrintSummaryRow() const
{
        XyzEmployeeSummaryBuilder()
        .setName(this->mName)
        .setId(this->mEmployeeId)
        .setType(EmployeeUtils::EmployeeTypeToString(this->mEmployeeType))
        .setStatus(EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus))
        .setGender(this->mGender)
        .setDOB(this->mDateOfBirth)
        .setDOJ(this->mDateOfJoining)
        .setDOL(this->mDateOfLeaving)
        .printRow((this->mEmployeeStatus?0:1));
}
