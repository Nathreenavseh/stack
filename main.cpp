#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* nextNode;

    Node(const T& value) : value {value},  nextNode{ nullptr } {

    }
};

template <typename T>
class List{
public:
    Node<T>* headNode;

    List() : headNode{nullptr}{
    }

    void addFront (const T& value){
        Node <T>* newNode = new Node <T> (value);
        newNode->nextNode = this->headNode;
        this->headNode = newNode;
        newNode = nullptr;
    }

    T head(){
        return headNode->value;
    }

    void deleteOnce() {
        if (isEmpty()) {
            cout << "Stack is empty !" << endl;
            return;
        }
        Node<T>* oldNode = this->headNode;
        this->headNode = oldNode->next;
        delete oldNode;
    }

    bool isEmpty(){
        return headNode == nullptr;
    }
    void clear() {
        while (!isEmpty()) {
            deleteOnce();
        }
    }

    List<T> clone() const {
        List<T> cloneNode;
        Node<T>* currentNode = headNode;

        while (currentNode!=nullptr) {
            cloneNode.addFront(currentNode->value);
            currentNode = currentNode->nextNode;
        }
        return cloneNode;
    }
    List<T> operator+(const List<T>& other) {
        List<T> results = clone();
        Node<T>* currentNode = other.headNode;

        while (currentNode != nullptr) {
            results.addFront(currentNode->value);
            currentNode = currentNode->nextNode;
        }
        return results;
    }

    List<T> operator*(const List<T>& other){
        List<T> results;
        Node<T>* currentNode = headNode;

        while (currentNode!=nullptr) {
            Node<T>* currentNode2 = other.headNode;
            while (currentNode2!=nullptr) {
                if (currentNode->value == currentNode2->value) {
                    results.addFront(currentNode->value);
                    break;
                }
                currentNode2 = currentNode2->nextNode;
            }
            currentNode = currentNode->nextNode;
        }
        return results;
    }

    void show() {
        auto currentNode = headNode;
        while (true) {
            if (currentNode != nullptr) {
                cout << "Value: " << currentNode->value << endl;
                if (currentNode->nextNode != nullptr) {
                    currentNode = currentNode->nextNode;
                }
                else {break;}
            }
            else {break;}
        }
    }
};

int main() {
    List <int> numbers;
    numbers.addFront(5);
    numbers.addFront(6);
    numbers.addFront(7);
    numbers.addFront(8);
    numbers.addFront(9);

    List <int> numbers1;
    numbers1.addFront(1);
    numbers1.addFront(1);
    numbers1.addFront(1);
    numbers1.addFront(1);
    numbers1.addFront(1);

//    numbers.show();
    List <int> numbers2;
    numbers2 = numbers+numbers1;
    numbers2.show();
    cout<<endl<<endl;

    List <int> numbers3;
    numbers3 = numbers*numbers1;
    numbers3.show();
    cout<<endl<<endl;


    List <int> newClone = numbers.clone();
    newClone.show();
    cout<<endl<<endl;


}