#ifndef NODE_H
#define NODE_H

// Node as double linked list for genaric data type
template <typename T>
struct Node {
    T mData;
    Node* mNext;
    Node* mPrev;

    Node(T dataParm) : mData(dataParm), mNext(nullptr), mPrev(nullptr)
    {
        //std::cout << "Creating node with value" << dataParm << std::endl;
    }
};

#endif
