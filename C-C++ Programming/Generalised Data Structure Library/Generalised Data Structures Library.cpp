#include<iostream>
using namespace std;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//    Structure for Singly Linear Linked List & Singly Circular Linked List    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeS 
{
    T data;
    struct nodeS * next;
};


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//    Structure for Doubly Linear Linked List & Doubly Circular Linked List    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};


///////////////////////////////////////
//                                   //
//    Structure for Stack & Queue    //
//                                   //
///////////////////////////////////////
template <class T>
struct nodeSTQU
{
    T data;
    struct nodeSTQU *next;
};


////////////////////////////////////////////
//                                        //
//    Structure for Binary Search Tree    //
//                                        //
////////////////////////////////////////////
template <class T> 
struct nodeBST
{
    T data;
    struct nodeBST *lchild;
    struct nodeBST *rchild;
};


//////////////////////////////////////////////
//                                          //
//    Class of Singly Linear Linked List    //
//                                          //
//////////////////////////////////////////////
template <class T>
class SinglyLL
{
    public:
        struct nodeS<T> * First;

        SinglyLL();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};


////////////////////////////////////////////////
//                                            //
//    Class of Singly Circular Linked List    //
//                                            //
////////////////////////////////////////////////
template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> * First;
        struct nodeS<T> * Last;

        SinglyCL();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};


//////////////////////////////////////////////
//                                          //
//    Class of Doubly Linear Linked List    //
//                                          //
//////////////////////////////////////////////
template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> * First;

        DoublyLL();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();       
};


////////////////////////////////////////////////
//                                            //
//    Class of Doubly Circular Linked List    //
//                                            //
////////////////////////////////////////////////
template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;
        struct nodeD<T> * Last;

        DoublyCL();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();       
};


//////////////////////////
//                      //
//    Class of Stack    //
//                      //
//////////////////////////
template <class T>
class Stack
{
    public:
        struct nodeSTQU<T> *First;
        int iCount;

        Stack();

        bool IsStackEmpty();
        void Push(T No);    // Insert
        T Pop();            // Delete 
        void Display();
};


//////////////////////////
//                      //
//    Class of Queue    //
//                      //
//////////////////////////
template <class T>
class Queue
{
    public:
        struct nodeSTQU<T> *First;
        int iCount;

        Queue();

        bool IsQueueEmpty();
        void EnQueue(T No);    // Insert
        T DeQueue();            // Delete 
        void Display();
};


///////////////////////////////////////
//                                   //
//    Class of Binary Search Tree    //
//                                   //
///////////////////////////////////////
template <class T>
class BinarySearchTree
{
    public:
        struct nodeBST<T> * Root;

        BinarySearchTree();
        void Insert(T iNo);

        void InOrder();
        void PreOrder();
        void PostOrder();
};


////////////////////////////////////////////////
//    Singly Linear Linked List Operations    //
////////////////////////////////////////////////
template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T iNo)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = iNo;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T iNo)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = iNo;
    newn->next = NULL;

    struct nodeS<T> * temp = First;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;
}

template <class T>
int SinglyLL<T> :: Count()
{
    int iCnt = 0;
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T iNo, int iPos)
{
    int iNodeCnt = 0, iCnt = 0;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }
    
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == (iNodeCnt + 1))
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T>;

        newn->data = iNo;
        newn->next = NULL;

        struct nodeS<T> * temp = First;
        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;

        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
    int iNodeCnt = 0, iCnt = 0;
    struct nodeS<T> * temp1 = NULL;
    struct nodeS<T> * temp2 = NULL;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iNodeCnt + 1))
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL \n";
}


//////////////////////////////////////////////////
//    Singly Circular Linked List Operations    //
//////////////////////////////////////////////////
template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T iNo)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = iNo;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
}

template <class T>
void SinglyCL<T> :: InsertLast(T iNo)
{
    struct nodeS<T> * newn = new struct nodeS<T>;

    newn->data = iNo;
    newn->next = NULL;

    struct nodeS<T> * temp = First;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
}

template <class T>
int SinglyCL<T> :: Count()
{
    int iCnt = 0;
    struct nodeS<T> * temp = First;

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);
    return iCnt;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T iNo, int iPos)
{
    int iNodeCnt = 0, iCnt = 0;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }
    
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == (iNodeCnt + 1))
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeS<T> * newn = new struct nodeS<T>;

        newn->data = iNo;
        newn->next = NULL;

        struct nodeS<T> * temp = First;
        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;

        First = First->next;
        delete temp;
        Last->next = First;       
    }
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
   if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    int iNodeCnt = 0, iCnt = 0;
    struct nodeS<T> * temp1 = NULL;
    struct nodeS<T> * temp2 = NULL;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iNodeCnt + 1))
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyCL<T> :: Display()
{
    struct nodeS<T> * temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != Last->next);

    cout<<"\n";
}


////////////////////////////////////////////////
//    Doubly Linear Linked List Operations    //
////////////////////////////////////////////////
template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T iNo)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}

template <class T>
void DoublyLL<T> :: InsertLast(T iNo)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeD<T> * temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
int DoublyLL<T> :: Count()
{
    int iCnt = 0;

    struct nodeD<T> * temp = First;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T iNo, int iPos)
{
    int iNodeCnt = 0, iCnt = 0;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == (iNodeCnt + 1))
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeD<T> * newn = new struct nodeD<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeD<T> * temp = First;

        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeD<T> * temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    int iNodeCnt = 0, iCnt = 0;
    struct nodeD<T> * temp1 = NULL;
    struct nodeD<T> * temp2 = NULL;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iNodeCnt + 1))
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct nodeD<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL \n";
}


//////////////////////////////////////////////////
//    Doubly Circular Linked List Operations    //
//////////////////////////////////////////////////
template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T iNo)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }

    First->prev = Last;
    Last->next = First;
}

template <class T>
void DoublyCL<T> :: InsertLast(T iNo)
{
    struct nodeD<T> * newn = new struct nodeD<T>;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    First->prev = Last;
    Last->next = First;
}

template <class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;

    struct nodeD<T> * temp = First;

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T iNo, int iPos)
{
    int iNodeCnt = 0, iCnt = 0;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == (iNodeCnt + 1))
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeD<T> * newn = new struct nodeD<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeD<T> * temp = First;

        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete First->prev;

        First->prev = Last;
        Last->next = First;
    }
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
    int iNodeCnt = 0, iCnt = 0;

    iNodeCnt = Count();

    if((iPos < 0) && (iPos > (iNodeCnt + 1)))
    {
        cout<<"Invalid Position"<<"\n";
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == (iNodeCnt + 1))
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> * temp = First;

        for(iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

template <class T>
void DoublyCL<T> :: Display()
{
    struct nodeD<T> * temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }while(temp != Last->next);

    cout<<"\n";
}


////////////////////////////
//    Stack Operations    //
////////////////////////////
template <class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Stack<T> :: IsStackEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Stack<T> :: Push(T No)  // InsertFirst
{
    struct nodeSTQU<T> *newn = new nodeSTQU<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }

    iCount++;

    cout<<No<<" gets Pushed in the Stack succesfully"<<"\n";
}

template <class T>
T Stack<T> :: Pop()  // DeleteLast
{
    if(First == NULL)
    {
        cout<<"Unable to Pop the element as Stack is Empty."<<"\n";
        return -1;
    }
    else
    {
        T Value = First->data;
        struct nodeSTQU<T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return Value;
    }
}

template <class T>
void Stack<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else
    {
        cout<<"Elements of Stack are : "<<"\n";

        struct nodeSTQU<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}


////////////////////////////
//    Queue Operations    //
////////////////////////////
template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Queue<T> :: IsQueueEmpty()
{
    if(iCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Queue<T> :: EnQueue(T No)  // InsertLast
{
    struct nodeSTQU<T> *newn = new nodeSTQU<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeSTQU<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;

    cout<<No<<" gets Added in the Queue succesfully"<<"\n";
}

template <class T>
T Queue<T> :: DeQueue()  // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"Unable to Pop the element as Queue is Empty."<<"\n";
        return (T)-1;
    }
    else
    {
        int Value = First->data;
        struct nodeSTQU<T> *temp = First;

        First = First->next;
        delete temp;

        iCount--;

        return Value;
    }
}

template <class T>
void Queue<T> :: Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty."<<"\n";
    }
    else
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct nodeSTQU<T> *temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |->";
            temp = temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}


/////////////////////////////////////////
//    Binary Search Tree Operations    //
/////////////////////////////////////////
template <class T>
BinarySearchTree<T> :: BinarySearchTree()
{
    Root = NULL;
}

template <class T>
void BinarySearchTree<T> :: Insert(T iNo)
{
    struct nodeBST<T> * newn = new struct nodeBST<T>;

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    struct nodeBST<T> * temp = Root;

    if(Root == NULL)
    {
        Root = newn;
    }
    else
    {
        while(1)
        {
            if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data)
            {
                free(newn);
                printf("Duplicate element not allowed.\n");
                break;               
            }
        }    
    }
}

template <class T>
void BinarySearchTree<T> :: InOrder()
{
    if(Root != NULL)
    {
        InOrder(Root->lchild);
        printf("%d\t",Root->data);
        InOrder(Root->rchild);
    }
}

template <class T>
void BinarySearchTree<T> :: PreOrder()
{
    if(Root != NULL)
    {
        printf("%d\t",Root->data);
        PreOrder(Root->lchild);
        PreOrder(Root->rchild);
    }
}

template <class T>
void BinarySearchTree<T> :: PostOrder()
{
    if(Root != NULL)
    {
        PostOrder(Root->lchild);
        PostOrder(Root->rchild);
        printf("%d\t",Root->data);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    return 0;
}

//-------------------------------------------------------------------END-----------------------------------------------------------------//