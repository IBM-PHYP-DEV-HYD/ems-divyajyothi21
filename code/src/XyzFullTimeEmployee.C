#include "XyzFullTimeEmployee.H"

XyzFullTimeEmployee::XyzFullTimeEmployee():XyzEmployee()
{
    std::cout << "Creating a Default XyzFullTimeEmployee Constructor" << std::endl;
}

XyzFullTimeEmployee::XyzFullTimeEmployee(std::string NameParm,
                                         std::string IdParm,
                                         EmployeeType EmployeeTypeParm,
                                         std::string GenderParm,
                                         std::string DojParm,
                                         std::string DobParm,
                                         EmployeeStatus EmployeeStatusParm,
                                         std::string DolParm,
                                         uint8_t AvailedLeavesParm):XyzEmployee(NameParm,
                                                                       IdParm,
                                                                       EmployeeTypeParm,
                                                                       GenderParm,
                                                                       DojParm,
                                                                       DobParm,
                                                                       EmployeeStatusParm,
                                                                       DolParm),mLeavesAvailed(AvailedLeavesParm)
{
    std::cout << "Creating a FullTimeEmployee Parameterized Constructor" << std::endl;
}

void XyzFullTimeEmployee::AddLeaves(int Nparm)
{
        if(Nparm > 22 || Nparm <= 0)
        {
            std::cout << "Noting to get added to as invalid value" << std::endl;
        }
        this->mLeavesAvailed += Nparm;
        if (this->mLeavesAvailed > 22) this->mLeavesAvailed = 22; // Max leaves is 22
}

int XyzFullTimeEmployee::GetLeavesAvailed()
{
    return this->mLeavesAvailed;
}

void XyzFullTimeEmployee::PrintEmployeeDetails() const
{
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Employee Name  : " << this->mName << std::endl;
        std::cout << "Employee ID    : " << this->mEmployeeId << std::endl;
        std::cout << "Employee Type  : Full-Time" << std::endl;
        std::cout << "Employee Status: " << EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus) << std::endl;
        std::cout << "Gender         : " << this->mGender << std::endl;
        std::cout << "Date of Birth  : " << this->mDateOfBirth << std::endl;
        std::cout << "Date of Joining: " << this->mDateOfJoining << std::endl;
        std::cout << "Date of Leaving: " << this->mDateOfLeaving << std::endl;
        std::cout << "Leaves Availed : " << this->mLeavesAvailed << std::endl;
        std::cout << "Leaves Left    : " << (22 - this->mLeavesAvailed) << std::endl;
        std::cout << "-----------------------------------------" <<std::endl;
}

void XyzFullTimeEmployee::PrintSummaryRow() const
{
        XyzEmployeeSummaryBuilder()
        .setName(this->mName)
        .setId(this->mEmployeeId)
        .setType("Full-Time")
        .setStatus(EmployeeUtils::EmployeeStatusToString(this->mEmployeeStatus))
        .setGender(this->mGender)
        .setDOB(this->mDateOfBirth)
        .setDOJ(this->mDateOfJoining)
        .setDOL(this->mDateOfLeaving)
        .setLeaves(this->mLeavesAvailed)
        .printRow((this->mEmployeeStatus?0:1));
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
    std::cout << "Destructor of XyzFullTimeEmployee" << std::endl;
}
