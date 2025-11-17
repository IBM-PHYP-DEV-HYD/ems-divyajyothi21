#ifndef _EMPLOYEE_SUMMARY_BUILDER_H_
#define _EMPLOYEE_SUMMARY_BUILDER_H_

#include <string>
#include <cstdio>
#include <iostream>

/**
 * @brief Builder pattern for constructing formatted employee summary rows.
 * Supports fluent API (method chaining) and flexible field composition.
 * Each employee mType builds its summary by setting relevant fields; blank fields
 * are automatically filled with "NA" or empty string.
 */
struct EmployeeSummaryBuilder
{
private:
    std::string mName;
    std::string mId;
    std::string mType;
    std::string mStatus;
    std::string mGender;
    std::string mDob;
    std::string mDoj;
    std::string mDol;
    std::string mLeaves;       // For Full-Time employees
    std::string mAgency;       // For Contractor employees
    std::string mCollege;      // For Intern employees
    std::string mBranch;       // For Intern employees

public:
    EmployeeSummaryBuilder()
        : mName(""), mId(""), mType(""), mStatus(""), mGender(""),
          mDob(""), mDoj(""), mDol(""), mLeaves(""), mAgency(""),
          mCollege(""), mBranch("")
    {}

    // Fluent API: each setter returns *this for method chaining
    EmployeeSummaryBuilder& setName(const std::string& nameParm) {
        mName = nameParm;
        return *this;
    }

    EmployeeSummaryBuilder& setId(const std::string& idParm) {
        mId = idParm;
        return *this;
    }

    EmployeeSummaryBuilder& setType(const std::string& typeParm) {
        mType = typeParm;
        return *this;
    }

    EmployeeSummaryBuilder& setStatus(const std::string& statusParm) {
        mStatus = statusParm;
        return *this;
    }

    EmployeeSummaryBuilder& setGender(const std::string& genderParm) {
        mGender = genderParm;
        return *this;
    }

    EmployeeSummaryBuilder& setDOB(const std::string& dobParm) {
        mDob = dobParm;
        return *this;
    }

    EmployeeSummaryBuilder& setDOJ(const std::string& dojParm) {
        mDoj = dojParm;
        return *this;
    }

    EmployeeSummaryBuilder& setDOL(const std::string& dolParm) {
        mDol = dolParm;
        return *this;
    }

    EmployeeSummaryBuilder& setLeaves(int leavesParm) {
        mLeaves = std::to_string(leavesParm);
        return *this;
    }

    EmployeeSummaryBuilder& setAgency(const std::string& agencyParm) {
        mAgency = agencyParm;
        return *this;
    }

    EmployeeSummaryBuilder& setCollege(const std::string& collegeParm) {
        mCollege = collegeParm;
        return *this;
    }

    EmployeeSummaryBuilder& setBranch(const std::string& branchParm) {
        mBranch = branchParm;
        return *this;
    }

    // Print the formatted row with all fields set
    void printRow(bool isActiveInactive) const
    {
        if (isActiveInactive)
        {
        printf("|%-16s | %-9s | %-11s | %-9s | %-7s | %-12s | %-17s | %-12s | %-4s | %-14s | %-8s | %-8s |\n",
               mName.c_str(),
               mId.c_str(),
               mType.c_str(),
               mStatus.c_str(),
               mGender.c_str(),
               mDob.c_str(),
               mDoj.c_str(),
               mDol.c_str(),
               (mLeaves.empty() ? "NA" : leaves.c_str()),
               (mAgency.empty() ? "NA" : agency.c_str()),
               (mCollege.empty() ? "NA" : college.c_str()),
               (mBranch.empty() ? "NA" : .c_str()));
        }
        else
        {
        }

    // Print header for the summary table
    static void printHeader()
    {
        if (mStatus != RESIGNED)
        {
        std::cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        std::cout << "|Employee Name    | ID        | Type        | Status    | Gender | Date of Birth | Date of Joining | Date of Leaving| Leaves | Agency | College| Branch|\n";
        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        }
        else
        {
    
        }
    }

    // Print footer for the summary table
    static void printFooter()
    {

        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
};

#endif

