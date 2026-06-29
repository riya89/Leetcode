class Node {
public:
    int key, value, cnt;
    Node *next, *prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = prev = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node* node) {
        Node* delPrev = node->prev;
        Node* delNext = node->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

        size--;
    }
};

class LFUCache {
public:

    int capacity;
    int currSize;
    int minFreq;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node* node) {

        keyNode.erase(node->key);

        List* oldList = freqList[node->cnt];
        oldList->removeNode(node);

        if(node->cnt == minFreq && oldList->size == 0)
            minFreq++;

        node->cnt++;

        if(freqList.find(node->cnt) == freqList.end())
            freqList[node->cnt] = new List();

        freqList[node->cnt]->addFront(node);

        keyNode[node->key] = node;
    }

    int get(int key) {

        if(keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];
        int ans = node->value;

        updateFreq(node);

        return ans;
    }

    void put(int key, int value) {

        if(capacity == 0)
            return;

        if(keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];
            node->value = value;

            updateFreq(node);

            return;
        }

        if(currSize == capacity) {

            List* list = freqList[minFreq];

            Node* node = list->tail->prev;

            keyNode.erase(node->key);

            list->removeNode(node);

            currSize--;
        }

        currSize++;

        minFreq = 1;

        Node* node = new Node(key,value);

        if(freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->addFront(node);

        keyNode[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */