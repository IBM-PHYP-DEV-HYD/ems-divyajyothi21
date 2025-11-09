#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include "Node.H"
#include "Utils.H"

// Deque(Double ended queue) class with existing node structure. 
template <typename T>
class Deque 
{
protected:
    Node<T>* mHead;
    Node<T>* mTail;
    int mSize;
public:
    Deque(); // Default constructor to create empty dequeue
    Deque(uint32_t sizeParm, T dataParm); //Constructor to genarate dequeue with given size, value
    ~Deque(); //destructor for deque
    void push_back(T dataParm); //Create deque and add element from tail
    void push_front(T dataParm); //Create deque and add element from Head
    void pop_back(); //remove element from tail
    void pop_front(); //remove element from front
    T front();
    T back();
    bool empty();
    int size();
    T getElementAt(int indexParm);
    void clear();
    void print();
    void resize(int newSizeParm, int directionParm);
    T& operator[](int nParam);       // Operator overloading
    Node<T>* getHead() const
    {
        return mHead;
    }
    Node<T>* getTail() const
    { 
        return mTail;
    }
};

template<typename T>
Deque<T>::Deque():mHead(nullptr),mTail(nullptr),mSize(0)
{
    std::cout << "Empty Deque called from default constructor of Deque" <<std::endl;
}

template<typename T>
Deque<T>::Deque(uint32_t sizeParm, T dataParm):mHead(nullptr),mTail(nullptr),mSize(0)
{
    int sItr = 0;
    for (sItr = 0; sItr < sizeParm; ++sItr)
	{
        push_back(dataParm);
    }
    std::cout << "Deque created with " << sizeParm << " elements." << std::endl;
}

template<typename T>
Deque<T>::~Deque()
{
    clear();
}    

// creating queue
template<typename T>
void Deque<T>::push_back(T dataParm)
{
    Node<T>* sNewNode = new Node<T>(dataParm);
    if (mHead == nullptr)
    {
        mHead = sNewNode;
        mTail = sNewNode;
    } else
    {
        mTail->mNext = sNewNode;
        sNewNode->mPrev = mTail;
        mTail = sNewNode;
    }
    this->mSize++;
}

template<typename T>    
void Deque<T>::push_front(T dataParm)
{
    Node<T>* sNewNode = new Node<T>(dataParm);
    if (mHead == nullptr) 
    {
        mHead = mTail = sNewNode;
    }
    else
    {
        mHead->mPrev = sNewNode;
        sNewNode->mNext = mHead;
        mHead = sNewNode;
    }
    this->mSize++;
}

template<typename T>
void Deque<T>::pop_back()
{
    if (empty())
    {
        std::cout << "Deque is empty! Cannot perform POP operation!" << std::endl;
        return;
    }
    Node<T>* sTemp = mTail;
    if (mHead == mTail)
    {
        mHead = nullptr;
        mTail = nullptr;
    }
    else 
    {
        mTail = mTail->mPrev;
        mTail->mNext = nullptr;
    }
    delete sTemp;
    this->mSize--;
}

template<typename T>
void Deque<T>::pop_front()
{
    if (empty())
    {
        std::cout << "Deque is empty. Cannot remove." << std::endl;
        return;
    }
    Node<T>* sTemp = mHead;
    if (mHead == mTail)
    {
        mHead = nullptr;
        mTail = nullptr;
    }
    else 
    {
        mHead = mHead->mNext;
        mHead->mPrev = nullptr;
    }
    delete sTemp;
    this->mSize--;
}

template<typename T>
T Deque<T>::front() 
{
    if (empty())
    {
        throw std::out_of_range("Deque is empty");
    }
    return mHead->mData;
}

template<typename T>
T Deque<T>::back()
{
    if (Deque::empty())
    {
        throw std::out_of_range("Deque is empty");
    }
    return mTail->mData;
}

// UTILITY FUNCTIONS
template<typename T>
bool Deque<T>::empty()
{
    return (mSize == 0);
}

template<typename T>
int Deque<T>::size()
{
    return this->mSize;
}
    
template<typename T>
T Deque<T>::getElementAt(int indexParm)
{
    if (indexParm < 0 || indexParm >= mSize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    Node<T>* sCurrent = mHead;
    int sItr = 0;
    for (sItr = 0; sItr < indexParm; ++sItr)
    {
        sCurrent = sCurrent->mNext;
    }
    return sCurrent->mData;
}

template<typename T>
void Deque<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template<typename T>
void Deque<T>::print()
{
    if (empty())
    {
        std::cout << "Deque is empty." << std::endl;
        return;
    }
    Node<T>* sCurrent = mHead;
    while (sCurrent != nullptr)
    {
        std::cout << sCurrent->mData << " ";
        sCurrent = sCurrent->mNext;
    }
    std::cout << std::endl;
}

// RESIZE FUNCTION
template<typename T>
void Deque<T>::resize(int newSizeParm, int directionParm)
{
    if (newSizeParm == this->mSize)
    {
        std::cout << "You choose the size same as existing size!So not modifying" << std::endl;
        return;
    }
    else if (newSizeParm > this->mSize)
    {
        T defaultValParm;
        std::cout << "Enter the default value to add" << std::endl;
        Utils<T>::GetValidatedUserInput(defaultValParm);
        int sElementsToAdd = newSizeParm - mSize;
        int sItr = 0;
        for (sItr = 0; sItr < sElementsToAdd; ++sItr)
        {
            if (directionParm == Forward)
            {
                push_back(defaultValParm);
            }
            else 
            {
                push_front(defaultValParm);
            }
        }
     } 
     else
     { // newSizeParm < mSize
        int sElementsToRemove = this->mSize - newSizeParm;
        int sItr = 0;
        for (sItr = 0; sItr < sElementsToRemove; ++sItr)
        {
            if (directionParm == Forward)
            {
                pop_back();
            } 
            else 
            {
                pop_front();
            }
        }
        std::cout << "deque resized to "<< newSizeParm << std::endl;
    }
}

template<typename T>
T& Deque<T>::operator[](int indexParam)
{// Operator overloading
    int sQueue_size = this->mSize;
    int sCount = 0;
    if((indexParam > sQueue_size) || (indexParam < 0))
    {
        throw std::out_of_range("Trying to access OOB");
        return 0;           //Error Message
    }
    Node<T> *sPtr = this->mHead;
    while(sCount < indexParam )
    {
        sPtr = sPtr->mNext;
        sCount++;
    }
    return sPtr->mData;
}
#endif
