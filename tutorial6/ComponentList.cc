#include "ComponentList.h"

// Constructors
ComponentList::ComponentList(): head(nullptr), tail(nullptr), size(0){
}

// Destructor
ComponentList::~ComponentList(){
    // while (size > 0){
    //     remove(0);
    // }
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->getNext();
        current->setNext(nullptr);  // Disconnect the node (avoid dangling pointers)
        current->setPrev(nullptr);  
        delete current->getData(); // Delete the component
        delete current; // Delete the node
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;

    cout << "ComponentList destructor called~" << endl;
}

// Getters
Component* ComponentList::get(int index) const{
    if (index < 0 || index >= size){
        return nullptr;
    }

    Node* current = head;

    for (int i = 0; i < index; i++){
        current = current->getNext();
    }

    return current->getData();
}

Component* ComponentList::get(const string& id) const{
    Node* current = head;

    while (current != nullptr){
        if (current->getData()->getId() == id){
            return current->getData();
        }

        current = current->getNext();
    }

    return nullptr;
}

int ComponentList::getSize() const{
    return size;
}

// Setters

// Methods
bool ComponentList::add(Component* comp){   // Add to the back
    return add(comp, size);
}

bool ComponentList::add(Component* comp, int index){
    if (index < 0 || index > size){
        return false;
    }

    Node* newNode = new Node(comp);

    if (size == 0){
        head = newNode;
        tail = newNode;
    }else if (index == 0){
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }else if (index == size){
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }else{
        Node* current = head;
        for (int i = 0; i < index; i++){
            current = current->getNext();
        }
        newNode->setNext(current);
        newNode->setPrev(current->getPrev());
        current->getPrev()->setNext(newNode);
        current->setPrev(newNode);
    }
    size++;
    return true;
}

Component* ComponentList::remove(int index){
    if (index < 0 || index >= size){
        return nullptr;
    }
    Node* current = head;
    for (int i = 0; i < index; i++){
        current = current->getNext();
    }
    Component* data = current->getData();
    if (size == 1){
        head = nullptr;
        tail = nullptr;
    }else if (current == head){
        head = current->getNext();
        head->setPrev(nullptr);
    }else if (current == tail){
        tail = current->getPrev();
        tail->setNext(nullptr);
    }else{
        current->getPrev()->setNext(current->getNext());
        current->getNext()->setPrev(current->getPrev());
    }
    // delete current;
    size--;
    return data;
}

Component* ComponentList::remove(const string& id){
    Node* current = head;
    while (current != nullptr){
        if (current->getData()->getId() == id){
            Component* data = current->getData();
            if (size == 1){
                head = nullptr;
                tail = nullptr;
            }else if (current == head){
                head = current->getNext();
                head->setPrev(nullptr);
            }else if (current == tail){
                tail = current->getPrev();
                tail->setNext(nullptr);
            }else{
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
            }
            // delete current;
            size--;
            return data;
        }
        current = current->getNext();
    }
    return nullptr;
}