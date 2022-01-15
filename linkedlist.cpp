#include <iostream>

using namespace std;

struct Node {
    int payload;
    struct Node *next;
};

class LinkedList {
    private:
        Node *head, *tail;

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void add(int payload) {
            Node *node = new Node;

            node->payload = payload;

            if(this->head == nullptr) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                this->tail = node;
            }
        }

        void show() {
            Node *current = head;

            while (current != nullptr) {
                cout << current->payload << endl;

                current = current->next;
            }

            cout << "EOF" << endl;
        }

        void rm(int payload) {
            Node *current = head, *previous = head;

            if (current->payload == payload) {
                head = current->next;

                delete current;
            }

            while (current->next != nullptr) {
                previous = current;
                current = current->next;

                if (current->payload == payload) {
                    if (current == this->tail) {
                        this->tail = previous;
                        this->tail->next = nullptr;
                    } else previous->next = current->next;

                    delete current; break;
                }
            }
        }

        void size() {
            int size = 0;
            Node *current = head;

            while (current != nullptr) {
                size++;

                current = current->next;
            }

            cout << size << endl;
        }
};

int main() {
    LinkedList *list = new LinkedList();

    list->add(7);
    list->add(5);
    list->add(9);
    list->rm(5);
    list->add(6);

    list->size();
    list->show();

    return EXIT_SUCCESS;
}
