#ifndef DEQUEMOCK_H
#define DEQUEMOCK_H
#include "Edll.H"
//#include "Student.H"
#include "Utils.H"

template<typename T>
class EdllMock : public Edll<T> 
{
public:
    EdllMock();
    EdllMock(uint32_t numberOfElementsParm, T DefaultvalueParm);
    ~EdllMock();
    static void ProcessEdll(Edll<T>* dequeParm);
};

template<typename T>
EdllMock<T>::EdllMock()
{
    std::cout << "EdllMock default Constructor" << std::endl;
}

template<typename T>
EdllMock<T>::EdllMock(uint32_t numberOfElementsParm, T DefaultvalueParm)
{
    Edll<T>::Edll(numberOfElementsParm, DefaultvalueParm);
    std::cout << "Edll created with " << numberOfElementsParm << " elements." << std::endl;
}

template<typename T>
EdllMock<T>::~EdllMock()
{
    std::cout << "EdllMock destructor created" << std::endl;
}

template<typename T>
void EdllMock<T>::ProcessEdll(Edll<T>* dequeParm)
{
    int sChoice;
    do 
    {
        Utils<T>::displayMenuForDequeOperations();
        std::cout << "Your Choice: ";
        Utils<int>::GetValidatedUserInput(sChoice);
        switch(sChoice)
        {
            case ADD_ELEMENT_AT_END:
            { // Add at end
                T sData;
                std::cout << "Enter value to add: ";
                Utils<T>::GetValidatedUserInput(sData);
                dequeParm->push_back(sData);
                break;
            }
            case ADD_ELEMENT_AT_BEGINING:
            { // Add at beginning
                T sData;
                std::cout << "Enter value to add: ";
                Utils<T>::GetValidatedUserInput(sData);
                dequeParm->push_front(sData);
                break;
            }   
            case REMOVE_ELEMENT_FROM_END:
            { // Remove from end
                dequeParm->pop_back();
                break;
            }
            case REMOVE_ELEMENT_FROM_BEGINING:
            { // Remove from beginning
                dequeParm->pop_front();
                break;
            }
            case GET_FIRST_ELEMENT: 
            { // Get first element
                if (!dequeParm->empty())
                {
                    std::cout << "First element: " << dequeParm->front() << std::endl;
                } 
                else
                {
                    std::cout << "Edll is empty." << std::endl;
                }
                break;
            }
            case GET_LAST_ELEMENT:
            { // Get last element
                if (!dequeParm->empty())
                {
                    std::cout << "Last element: " << dequeParm->back() << std::endl;
                }
                else
                {
                    std::cout << "Edll is empty." << std::endl;
                }
                break;
            }
            case GET_SIZE_OF_QUEUE:
            { // Get size
                std::cout << "Current size: " << dequeParm->size() << std::endl;
                break;
            }
            case RESIZE_QUEUE:
            { // Resize
                int sNewSize;
                int sDirection;
                std::cout << "Enter new size: ";
                Utils<int>::GetValidatedUserInput(sNewSize);
                std::cout << "Enter direction (1 for Forward, -1 for Backward): ";
                Utils<int>::GetValidatedUserInput(sDirection);
                if (sNewSize >= 0 && (sDirection == -1 || sDirection == 1))
                { 
                    dequeParm->resize(sNewSize,sDirection);
                }
                else
                {
                    std::cout << "invalid resize or Direction retry again!" << std::endl;
                }
                break;
            }
            case CLEAR_ALL_ELEMENTS:
            { // Clear
                dequeParm->clear();
                std::cout << "Edll cleared." << std::endl;
                break;
            }
            case PRINT_ALL_ELEMENTS:
            { // Print
                dequeParm->print();
                break;
            }
            case GET_ELEMENT_AT_INDEX:
            {
                int sIndex;
                std::cout << "Enter index you want to get element from(0-n)"<<std::endl;
                Utils<int>::GetValidatedUserInput(sIndex);
                std::cout << dequeParm->getElementAt(sIndex) << std::endl;
                break;
            }
            case EXIT:
            {
                std::cout << "Exiting from Edll Process Menu" << std::endl;
                break;
            }
            default:
            {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }while(sChoice != EXIT);
}
#endif
