#include "XyzInternEmployee.H"

XyzInternEmployee::XyzInternEmployee():XyzEmployee()
{
    std::cout << "Creating a XyzInternEmployee Default Constructor" << std::endl;
}

XyzInternEmployee::XyzInternEmployee(std::string NameParm,
             std::string IdParm,
             EmployeeType EmpTypeParm,
             std::string GenderParm,
             std::string DojParm,
             std::string DobParm,
             EmployeeStatus EmployeeStatusParm,
             std::string DolParm,
             College CollegeParm,
             Branch BranchParm):XyzEmployee(NameParm,
                       IdParm,
                       EmpTypeParm,
                       GenderParm,
                       DojParm,
                       DobParm,
             EmployeeStatusParm,
             DolParm),mCollege(CollegeParm),mBranch(BranchParm)
{
    std::cout << "Creating a XyzInternEmployee Parameterized Constructor" << std::endl;
}

XyzInternEmployee::~XyzInternEmployee()
{
    std::cout << "Destrcuting the XyzInternEmployee" << std::endl;
}

College XyzInternEmployee::GetCollegeName()
{
    return this->mCollege;
}

Branch XyzInternEmployee::GetBranch()
{
    return this->mBranch;
}

void XyzInternEmployee::PrintEmployeeDetails() const
{
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Employee Name  : " << this->mName << std::endl;
        std::cout << "Employee ID    : " << this->mEmployeeId << std::endl;
        std::cout << "Employee Type  : Intern" << std::endl;
        std::cout << "Employee Status: " << EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus) << std::endl;
        std::cout << "Gender         : " << this->mGender << std::endl;
        std::cout << "Date of Birth  : " << this->mDateOfBirth << std::endl;
        std::cout << "Date of Joining: " << this->mDateOfJoining << std::endl;
        std::cout << "Date of Leaving: " << this->mDateOfLeaving << std::endl;
        std::cout << "College        : " << EmployeeUtils::CollegeToString(this->mCollege) << std::endl;
        std::cout << "Branch         : "  << EmployeeUtils::BranchToString(this->mBranch) << std::endl;
        std::cout << "-----------------------------------------" << std::endl;

}

void XyzInternEmployee::PrintSummaryRow() const
{
    XyzEmployeeSummaryBuilder()
        .setName(this->mName)
        .setId(this->mEmployeeId)
        .setType("Intern")
        .setStatus(EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus))
        .setGender(this->mGender)
        .setDOB(this->mDateOfBirth)
        .setDOJ(this->mDateOfJoining)
        .setDOL(this->mDateOfLeaving)
        .setCollege(EmployeeUtils::CollegeToString(this->mCollege))
        .setBranch(EmployeeUtils::BranchToString(this->mBranch))
        .printRow((this->mEmployeeStatus?0:1));
}
