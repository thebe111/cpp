#include <iostream>

class Node  {
    private:
        int payload;

    public:
        Node *right,
             *left;

        Node(int payload) {
            this->payload = payload;
        }

        int getPayload() {
            return this->payload;
        }
};

class Btree {
    private:
        Node *root;

    public:
        Btree(int payload) {
            this->root = new Node(payload);
        }

        Node *getRoot() {
            return this->root;
        }

        void add(int payload) {
            Node *node = this->root,
                 *parent;

            while (node != nullptr) {
                parent = node;

                if(node->getPayload() > payload) node = node->left;
                else node = node->right;
            }

            node = new Node(payload);

            if(parent->getPayload() > payload) parent->left = node;
            else parent->right = node;
        }

        Node *min(Node *node = nullptr) {
            if (node == nullptr) node = this->root;

            while (node->left != nullptr) {
                node = node->left;
            }

            return node;
        }

        Node *max(Node *node = nullptr) {
            if (node == nullptr) node = this->root;

            while (node->right != nullptr) {
                node = node->right;
            }

            return node;
        }

        int height(Node *node = nullptr) {
            int hleft = 0,
                hright = 0;

            if (node == nullptr) node = this->root;

            if (node->left != nullptr) hleft = this->height(node->left);
            if (node->right != nullptr) hright = this->height(node->right);

            return hleft > hright ? hleft + 1 : hright + 1;
        }

        Node *search(int payload, Node *node = nullptr) {
            if (node == nullptr) node = this->root;

            if (node->getPayload() == payload) return node;

            if (node->getPayload() > payload) return search(payload, node->left);
            return search(payload, node->right);
        }
};

template <typename T>
void 
print(T out);

int
main() {
    Btree *btree = new Btree(8);
    btree->add(4);
    btree->add(5);
    btree->add(7);
    btree->add(6);
    btree->add(9);

    print(btree->search(7)->getPayload());

    return EXIT_SUCCESS;
}

template <typename T>
void
print(T out) {
    std::cout << out << std::endl;
}

