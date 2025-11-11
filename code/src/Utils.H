#ifndef UTILS_H
#define UTILS_H

enum DequeDataType
{
    INTEGER = 1,
    STRING,
    CLASS,
};

enum DequeOperations
{
    CREATE_EMPTY_QUEUE = 1,
    CREATE_DEQUE_N_ELEMENTS,
    ADD_ELEMENT_AT_END,
    ADD_ELEMENT_AT_BEGINING,
    REMOVE_ELEMENT_FROM_END,
    REMOVE_ELEMENT_FROM_BEGINING,
    GET_FIRST_ELEMENT,
    GET_LAST_ELEMENT,
    GET_SIZE_OF_QUEUE,
    RESIZE_QUEUE,
    CLEAR_ALL_ELEMENTS,
    PRINT_ALL_ELEMENTS,
    GET_ELEMENT_AT_INDEX,
    EXIT = -1,
};

// Enum for Deque resize direction
enum DequeResizeDirection
{
    Forward = 1,
    Backward = -1
};

template<typename T>
class Utils{
public:
    Utils();
    ~Utils();
    static void displayMenuForDataTypeChoice();
    static void displayMenuForDequeCreation();
    static void GetValidatedUserInput(T& UserInputParm);
    static int validate_DataTyepChoice(int DataTypeChoiceParm);
    static int ValidateDequeCreationChoice(int DequeCreationChoiceParm);
    static void displayMenuForDequeOperations();
};

template<typename T>
int Utils<T>::ValidateDequeCreationChoice(int DequeCreationChoiceParm)
{
    switch(DequeCreationChoiceParm)
    {
    case CREATE_EMPTY_QUEUE:
        break;
    case CREATE_DEQUE_N_ELEMENTS:
        break;
    case EXIT:
        std::cout<< "Choose to go to Main menu!" << std::endl;
        return 0;
    default:
        std::cout <<"Invalid choice! Try again! "<<std::endl;
        return 0;
    }
    return 1;
}

//Menu for Deque creation
template<typename T>
void Utils<T>::displayMenuForDequeCreation()
{
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "|         Deque Creation                  |" << std::endl;
    std::cout << " -----------------------------------------" << std::endl;
    std::cout << "| 1. Create an empty deque                |" << std::endl;
    std::cout << "| 2. Create a deque with 'n' elements     |" << std::endl;
    std::cout << "| Enter -1 to goto main menu.             |" << std::endl;
    std::cout << " ----------------------------------------" << std::endl;
}

//For input validation
template<typename T>
void Utils<T>::GetValidatedUserInput(T& UserInputParm)
{
    while (1)
    {
        std::cin >> UserInputParm;
        if (std::cin.fail())
        {
            std::cin.clear(); // Clearing error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clearing input buffer
            std::cout << "Please give a valid input." << std::endl;
        }
        else
        {
            break;
        }
    }
}

template<typename T>
int Utils<T>::validate_DataTyepChoice(int DataTypeChoiceParm)
{
    switch(DataTypeChoiceParm)
    {
        case INTEGER:
        break;

        case STRING:
        break;
        
        case CLASS:
        break;
        
        case EXIT:
                std::cout << "you choose to Exit!Good bye!!" <<std::endl;
                return 0;

        default:
                std::cout << "Entered invalid choice of Datatype!" << std::endl;
                return 0;
     }
     return 1;
}

template<typename T>
void Utils<T>::displayMenuForDataTypeChoice()
{
        std::cout << "What type of deque you want to create:" << std::endl;
        std::cout << "1. Integer" << std::endl;
        std::cout << "2. String" << std::endl;
        std::cout << "3. User defined (Student Class)" << std::endl;
        std::cout << "-1. to Exit" << std::endl;
        std::cout << "Enter Your Choice: " << std::endl;
}

template<typename T>
void Utils<T>::displayMenuForDequeOperations()
{
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "|           Deque Operations              |" << std::endl;
    std::cout << " -----------------------------------------" << std::endl;
    std::cout << "| 3. Add an element at end                |" << std::endl;
    std::cout << "| 4. Add an element at the beginning      |" << std::endl;
    std::cout << "| 5. Remove an element from end           |" << std::endl;
    std::cout << "| 6. Remove an element from beginning     |" << std::endl;
    std::cout << "| 7. Get the first element                |" << std::endl;
    std::cout << "| 8. Get the last element                 |" << std::endl;
    std::cout << "| 9. Get the size of deque                |" << std::endl;
    std::cout << "| 10. Resize the deque                    |" << std::endl;
    std::cout << "| 11. Clear all the elements in the deque |" << std::endl;
    std::cout << "| 12. Print all the elements in the deque |" << std::endl;
    std::cout << "| 13.Get element at given index in deque  |" << std::endl;
    std::cout << "| Enter -1 to goto Deque Creation menu.   |" << std::endl;
    std::cout << " ----------------------------------------" << std::endl;
}
#endif
