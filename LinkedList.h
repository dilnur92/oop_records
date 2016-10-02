//  This linked list implementation is from
//  Starting Out with C++ (8th Edition) by Gaddis, Walters, and Muganda
//  Pages 1028-1034

#ifndef LinkedList_h
#define LinkedList_h
// A class template for holding a linked list.
// The node type is also a class template.

//*********************************************
// The ListNode class creates a type used to *
// store a node of the linked list. *
//*********************************************
#include <iostream>
#include <fstream>

using namespace std;
template <class T>
class ListNode
{
    public:
    T value; // Node value
    ListNode<T> *next; // Pointer to the next node
    
    // Constructor
    ListNode (T nodeValue)
    { value = nodeValue;
        next = NULL;}
};
    
//*********************************************
// LinkedList class *
//*********************************************
template <class T>
class LinkedList
{
    private:
    ListNode<T> *head; // List head pointer
    int size;
    public:
    // Constructor
    LinkedList()
    { head = NULL; size = 0;}
    
    // Destructor
    ~LinkedList();
    
    // Linked list operations
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    T SearchNode(T);
    int getSize();
    void displayList(ostream&) const;
};

//**************************************************
// appendNode appends a node containing the value *
// passed into newValue, to the end of the list. *
//**************************************************

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
    ListNode<T> *newNode; // To point to a new node
    ListNode<T> *nodePtr; // To move through the list
    
    // Allocate a new node and store newValue there.
    newNode = new ListNode<T>(newValue);
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (!head)
        head = newNode;
    else // Otherwise, insert newNode at end.
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;
        
        // Find the last node in the list.
        while (nodePtr->next)
            nodePtr = nodePtr->next;
        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
    size++;
}
template <class T>
int LinkedList<T>::getSize(){
    return size;
}


//**************************************************
// displayList shows the value stored in each node *
// of the linked list pointed to by head. *
//**************************************************

template <class T>
void LinkedList<T>::displayList(ostream& output) const
{
    ListNode<T> *nodePtr; // To move through the list
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr)
    {
        // Display the value in this node.
        output << nodePtr->value << endl;
        
        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

//**************************************************
// The insertNode function inserts a node with *
// newValue copied to its value member. *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
    ListNode<T> *newNode; // A new node
    ListNode<T> *nodePtr; // To traverse the list
    ListNode<T> *previousNode = NULL; // The previous node
    
    // Allocate a new node and store newValue there.
    newNode = new ListNode<T>(newValue);
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else // Otherwise, insert newNode.
    {
        // Position nodePtr at the head of list.
        nodePtr = head;
    
        // Initialize previousNode to NULL.
        previousNode = NULL;
    
        // Skip all nodes whose value is less than newValue.
        while (nodePtr != NULL && *nodePtr->value < *newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
    
        //If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else // Otherwise insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
    size++;
}

//*****************************************************
// The deleteNode function searches for a node *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory. *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
    ListNode<T> *nodePtr; // To traverse the list
    ListNode<T> *previousNode = NULL; // To point to the previous node
    
    // If the list is empty, do nothing.
    if (!head)
        return;
    
    // Determine if the first node is the one.
    if (head->value == searchValue)
        {
            nodePtr = head->next;
            delete head;
            head = nodePtr;
            }
    else
    {
        // Initialize nodePtr to head of list
        nodePtr = head;
        
        // Skip all nodes whose value member is
        // not equal to num.
        while (nodePtr != NULL && *nodePtr->value != *searchValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
    size--;
}

//**************************************************
// Search *
// This function searches for elements in the list by full name
// and returns the index of the element on the list
// and -1 if the element is not on the list
// Implemented by me as it is not found on the book
//*************************************************
template <class T>
T LinkedList<T>::SearchNode(T searchValue)
{
    cout<<"value: "<<searchValue<<endl;
    ListNode<T> *nodePtr; // To traverse the list
    nodePtr = head;
    
    // Find the last node in the list.
    while (nodePtr != NULL){
        //cout<<"searching: "<<nodePtr->value<<endl;
        if(*nodePtr->value == *searchValue){
            cout<<"true"<<endl;
            return nodePtr->value;
        }else{
            cout<<"false"<<endl;

            nodePtr = nodePtr->next;
        }
    }
    
    return searchValue;
}


//**************************************************
// Destructor *
// This function deletes every node in the list. *
//*************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T> *nodePtr; // To traverse the list
    ListNode<T> *nextNode; // To point to the next node
    
    // Position nodePtr at the head of the list.
    nodePtr = head;
    
    // While nodePtr is not at the end of the list...
    while (nodePtr != NULL)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;
        
        // Delete the current node.
        delete nodePtr;
    
        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
    size = 0;
}
#endif /* LinkedList_h */
