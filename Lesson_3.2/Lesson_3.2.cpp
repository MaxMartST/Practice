#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class MyList {
private:
    struct Node
    {
        string value;
        Node* next;

        Node(string value) : value(value), next(nullptr) {}
    };

    Node* first;
    Node* last;
    unsigned int length = 0;

    bool IsEmpty();
    void SetFirstAndLastNode(Node* node);
    void CheckPositionsCorrect(int position1, int position2);

public:
    MyList();
    void PushBack(string value);                    //Добавление элементов в конец списка
    void PushInception(string value);               //Добавление элементов в начало списка
    void Print();                                   //Вывод элементов списка
    unsigned int Length() const;                    //Получение количества элементов списка
    void SetItemToIndex(string value, int index);   //Вставление элемента на указанную позицию
    void DeleteFirstItem();                         //Удаление первого элемента списка
    void DeleteLastItem();                          //Удаление последнего элемента списка
    void DeleteAllItems();                          //Удаление всех элементов
    void DeletingItemSpecifiedPosition(int position);                           //Удаление элемента на указанной позиции
    void DeletesItemsRangeBetweenPositions(int position1, int position2);       //Удаление элементов в диапозоне между двумя указанными позициями
};

MyList::MyList() : first(nullptr), last(nullptr) {}

bool MyList::IsEmpty()
{
    return first == nullptr;
}

void MyList::SetFirstAndLastNode(Node* node)
{
    first = node;
    last = node;
}

void MyList::PushBack(string value)
{
    Node* node = new Node(value);
    length++;

    if (IsEmpty())
        SetFirstAndLastNode(node);
    else
    {
        last->next = node;
        last = node;
    }
}

void MyList::PushInception(string value)
{
    Node* node = new Node(value);
    length++;

    if (IsEmpty())
        SetFirstAndLastNode(node);
    else
    {
        node->next = first;
        first = node;
    }
}

void MyList::Print() 
{
    string result;

    if (!IsEmpty())
    {
        Node* node = first;

        while (node)
        {
            result = result + node->value + " ";
            node = node->next;
        }
    };

    cout << result << endl;
}

unsigned int MyList::Length() const
{
    return length;
}

void MyList::SetItemToIndex(string value, int index)
{
    if (IsEmpty())
        throw domain_error("List empty!");

    if (index <= 0 || index > Length())
    {
        string range = Length() > 1 ? ("Rang 1 to " + to_string(Length())) : "Rang 1 to 1";
        throw out_of_range("Incorrect positione! " + range);
    }   

    Node* newNode = new Node(value);
    Node* selectedNode = first;
    Node* temp = first;

    for (unsigned int indexNode = 0; indexNode < Length(); indexNode++)
    {
        if (index == 0)
        {
            PushInception(value);
            break;
        }

        if (indexNode == index)
        {
            temp->next = newNode;
            newNode->next = selectedNode;

            length++;
            break;
        }

        temp = selectedNode;
        selectedNode = selectedNode->next;
    }
}

void MyList::DeleteFirstItem()
{
    if (IsEmpty())
        throw domain_error("List empty!");

    Node* node = first;
    first = first->next;
    delete node;

    length--;
}

void MyList::DeleteLastItem()
{
    if (IsEmpty())
        throw domain_error("List empty!");

    if (first != last)
    {
        Node* node = first;

        while (node->next != last)
            node = node->next;

        node->next = nullptr;
        delete last;
        last = node;
    }
    else
        DeleteFirstItem();

    length--;
}

void MyList::DeleteAllItems()
{
    while (!IsEmpty()) DeleteFirstItem();
}

void MyList::CheckPositionsCorrect(int position1, int position2)
{
    if (IsEmpty())
        throw domain_error("List empty!");

    if (position1 >= Length() || position2 >= Length())
        throw out_of_range("Out of range!");

    if (position1 > position2)
        throw invalid_argument("Invalid argument!");
}

void MyList::DeletingItemSpecifiedPosition(int position)
{
    CheckPositionsCorrect(position, position);

    if (position == 0)
        DeleteFirstItem();

    if (position == Length() - 1 && Length() > 1)
        DeleteLastItem();

    if (position != 0 && position != Length() - 1)
    {
        Node* node = first;
        Node* temp = first;

        int deletePosition = 0;

        while (node)
        {
            if (deletePosition == position)
            {
                temp->next = node->next;
                delete node;
                length--;

                break;
            }

            temp = node;
            node = node->next;
            deletePosition++;
        }
    }
}

void MyList::DeletesItemsRangeBetweenPositions(int position1, int position2)
{
    CheckPositionsCorrect(position1, position2);

    for (size_t deletePosition = 0; deletePosition <= position2; deletePosition++)
    {
        if (deletePosition >= position1 && deletePosition <= position2)
            DeletingItemSpecifiedPosition(position1);
    }
}

int main()
{
    cout << "Hello! It's my list!\n";
    MyList myList;

    for (size_t i = 3; i < 11; i++)
        myList.PushBack(to_string(i));

    cout << "Length of list: " << myList.Length() << endl;
    cout << "Print: ";
    myList.Print();

    string item = "1";

    cout << "Add an item " << item << " to the beginning of the list" << endl;
    myList.PushInception(item);

    cout << "Length of list: " << myList.Length() << endl;
    cout << "Print: ";
    myList.Print();

    try
    {
        item = "2";
        int position1 = 1;

        cout << "Add an item " << item << " to a position with a number: " << position1 << endl;
        myList.SetItemToIndex(item, position1);

        cout << "Length of list: " << myList.Length() << endl;
        myList.Print();

        //Error!!!
        
        //cout << "Insert an element into an empty list" << endl;
        //MyList twoMyList;
        //twoMyList.SetItemToIndex("2", 1);

        cout << "Delete the first item in the list" << endl;
        myList.DeleteFirstItem();

        cout << "Length of list: " << myList.Length() << endl;
        cout << "Print: ";
        myList.Print();

        cout << "Delete the last item in the list" << endl;
        myList.DeleteLastItem();

        cout << "Length of list: " << myList.Length() << endl;
        cout << "Print: ";
        myList.Print();

        //cout << "Delete all items in the list" << endl;
        //myList.DeleteAllItems();

        //cout << "Length of list: " << myList.Length() << endl;
        //cout << "Print: ";
        //myList.Print();

        position1 = 1;
        cout << "Delete the item with the position number: "<< position1 << endl;
        myList.DeletingItemSpecifiedPosition(position1);

        cout << "Length of list: " << myList.Length() << endl;        
        cout << "Print: ";
        myList.Print();

        position1 = myList.Length() - 2;
        cout << "Delete the item with the position number: " << position1 << endl;
        myList.DeletingItemSpecifiedPosition(position1);

        cout << "Length of list: " << myList.Length() << endl;
        cout << "Print: ";
        myList.Print();

        position1 = 0;
        int position2 = 4;
        cout << "Remove items from the list in the range from " + to_string(position1) + " to " + to_string(position2) << endl;
        myList.DeletesItemsRangeBetweenPositions(position1, position2);

        cout << "Length of list: " << myList.Length() << endl;
        cout << "Print: ";
        myList.Print();

        position1 = 0;
        position2 = 0;
        cout << "Remove items from the list in the range from " + to_string(position1) + " to " + to_string(position2) << endl;
        myList.DeletesItemsRangeBetweenPositions(position1, position2);

        cout << "Length of list: " << myList.Length() << endl;
        cout << "Print: ";
        myList.Print();
    }
    catch (const exception& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}
