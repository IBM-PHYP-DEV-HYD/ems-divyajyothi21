#ifndef _XYZ_CORPORATION_
#define _XYZ_CORPORATION_

enum 
{
    FULL_TIME_EMPLOYESS = 0,
    CONTRACTORS, //parttime employess
    INTERNS, // Colleage Interns hired for 6 months
    EMPLOYEETYPE_MAX
}EmployeeType;

enum
{
    ACTIVE_EMPLOYEES = 0,
    INACTIVE_EMPLOYEES,
    RESIGNED_EMPLOYESS,
    EMPLOYEE_STATUS_MAX
}EmployeeStatus;

template<typename T>
class XYZCorporation
{
    private:
        Edll<T>* EmployeeArr[EMPLOYEE_TYPE_MAX][EMPLOYEE_STATUS_MAX] = {{NULL, NULL, NULL},
                                                                     {NULL, NULL, NULL},
                                                                     {NULL, NULL, NULL}};
    public:
        void UpdateEmployeeObjectPtr(EmployeeType, EmployeeStatus,Edll<T>* EdllPtrParm);
        Edll<T>* GetCreatedEmployeeObject(EmployeeType, EmployeeStatus);
        
};
#endif
