#ifndef _EDLL_H_ //Extended Doble Linked list
#define _EDLL_H_
#include "Deque.H"

template<typename T>
class Edll:public Deque<T>
{
public:
    Edll();
    Edll(uint32_t sizeParm, T dataParm);//Create a Parameterized constructor
    ~Edll();
    void AddElementAtGivenIndex(int indexParm, T dataParm); // to Add element at given index
    void DeleteElementAtGivenIndex(int indexParm); // to remove element at given index
}; 

template<typename T>
Edll<T>::Edll():Deque<T>()
{
    std::cout << "Default Extended Double Linked List" << std::endl;
}

template<typename T>
Edll<T>::Edll(uint32_t sizeParm, T dataParm):Deque<T>(sizeParm, dataParm)
{
    std::cout << "Parameterized constructor for Edll called" << std::endl;
}

template<typename T>
Edll<T>::~Edll()
{
    std::cout << "Edll Destructor Created" << std::endl;
}

template<typename T>
void Edll<T>::AddElementAtGivenIndex(int indexParm, T dataParm)
{
    if (indexParm < 0 || indexParm > this->mSize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    else
    {
        if (indexParm == 0)
        {
            this->push_front(dataParm);
            return;
        }
        else if(indexParm == this->mSize)
        {
            this->push_back(dataParm);
            return;
        }
        else
        {
            Node<T>* sCurrent = this->mHead;
            int sItr = 0;
            for (sItr = 0; sItr < indexParm ; ++sItr)
            {
                sCurrent = sCurrent->mNext;
            }
            //Node before the insertion point
            Node<T>* sPrevNode = sCurrent->mPrev;

            //Create new node
            Node<T>* sNewNode = new Node<T>(dataParm);

            //Update new node with surrounded nodes info
            sNewNode->mNext = sCurrent;
            sNewNode->mPrev = sPrevNode;

            //Update surounded nodes with new node
            sPrevNode->mNext = sNewNode;
            sCurrent->mPrev = sNewNode;
            this->mSize++;
        }
    }
}

template<typename T>
void Edll<T>::DeleteElementAtGivenIndex(int indexParm)
{
    if (indexParm < 0 || indexParm >= this->mSize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    else
    {
        if (indexParm == 0)
        {
            this->pop_front();
            return;
        }
        else if (indexParm == (this->mSize - 1))
        {
           this->pop_back();
           return;
        }
        else
        {
            Node<T>* sCurrent = this->mHead;
            int sItr = 0;
            for(sItr = 0; sItr < indexParm ; ++sItr)
            {
                sCurrent = sCurrent->mNext;
            }
            //get the surroundig nodes of given index
            Node<T>* sPrevNode = sCurrent->mPrev;
            Node<T>* sNextNode = sCurrent->mNext;

            //
            sPrevNode->mNext = sNextNode;
            sNextNode->mPrev = sPrevNode;

            delete sCurrent;
            this->mSize--;
        }
    }
}
#endif
