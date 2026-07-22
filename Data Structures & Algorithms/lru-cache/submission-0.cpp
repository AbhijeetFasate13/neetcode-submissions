class Node {
   public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
   public:
    Node* head;
    Node* tail;

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    void insertFront(Node* node) {
        node->prev = nullptr;
        node->next = head;

        if (head)
            head->prev = node;
        else
            tail = node;

        head = node;
    }

    void insertBack(Node* node) {
        node->next = nullptr;
        node->prev = tail;

        if (tail)
            tail->next = node;
        else
            head = node;

        tail = node;
    }

    void remove(Node* node) {
        if (!node) return;

        if (node->prev)
            node->prev->next = node->next;
        else
            head = node->next;

        if (node->next)
            node->next->prev = node->prev;
        else
            tail = node->prev;

        node->prev = nullptr;
        node->next = nullptr;
    }

    void moveToFront(Node* node) {
        remove(node);
        insertFront(node);
    }

    Node* getTail() { return tail; }

    bool empty() { return head == nullptr; }
};
class LRUCache {
    DLL* list;
    unordered_map<int, Node*> addr;
    int n;

   public:
    LRUCache(int capacity) {
        n = capacity;
        list = new DLL();
    }

    int get(int key) {
        if (n == 0 or !addr.count(key)) return -1;
        Node* curr = addr[key];
        list->moveToFront(curr);
        return curr->value;
    }

    void put(int key, int value) {
        if (addr.count(key)) {
            Node* curr = addr[key];
            curr->value = value;
            list->moveToFront(curr);
            return;
        }
        if (addr.size() == n) {
            Node* newTail = list->tail->prev;
            addr.erase(list->tail->key);
            list->remove(list->tail);
            list->tail = newTail;
        }
        Node* curr = new Node(key, value);
        addr[key] = curr;
        list->insertFront(curr);
    }
};
