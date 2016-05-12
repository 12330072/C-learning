#ifndef Queue_h
#define Queue_h
template<class T>
class Queue {
 public:
    Queue() {
        front_node = NULL;
        back_node = NULL;
        node_num = 0;
    }
    Queue(const Queue &another) {
        node_num = another.node_num;
        Node* p1 = another.front_node;
        Node* p2 = NULL;
        if (p1 != NULL) {
            front_node = new Node(p1->element, NULL);
            p2 = front_node;
            while (p1 -> next != NULL) {
                p2->next = new Node(p1->next->element, NULL);
                p2 = p2->next;
                p1 = p1->next;
            }
            back_node = p2;
        }
    }
    void Qclear() {
        Node* p = front_node;
        Node* temp = NULL;
        while (p != NULL) {
            temp = p;
            p = p->next;
            delete temp;
        }
        node_num = 0;
        front_node = NULL;
        back_node = NULL;
    }
    ~Queue() {
        if (front_node != NULL) {
            Qclear();
        }
    }
    bool empty() {
        return node_num == 0;
    }
    int size() {
        return node_num;
    }
    T front() const {
        return back_node->element;
    }
    T back() const {
        return front_node->element;
    }
    void push(T element) {
        Node* p = new Node(element, front_node);
        front_node = p;
        if (node_num == 0) {
            back_node = p;
        }
        node_num++;
    }
    void pop() {
        Node* p = front_node;
        Node* temp = NULL;\
        if (front_node != NULL) {
            if (front_node->next == NULL) {
                delete front_node;
                front_node = NULL;
                back_node = NULL;
                node_num = 0;
                return;
            }
            else if (front_node->next != NULL) {
                while (p->next != NULL) {
                    temp = p;
                    p = p->next;
                }
                back_node = temp;
                back_node->next = NULL;
                node_num--;
                delete p;
                return;
            }
        } else {
            return;
        }
    }
    void assign(const Queue & q1) {
        Node* p1 = q1.front_node;
        Node* p2 = NULL;
        if (p1 != NULL) {
            front_node = new Node(p1->element, NULL);
            p2 = front_node;
            node_num++;
            while (p1 -> next != NULL) {
                p2->next = new Node(p1->next->element, NULL);
                p2 = p2->next;
                p1 = p1->next;
                node_num++;
            }
            back_node = p2;
        }
        return;
    }
    void swap(Queue &queue) {
        Queue temp(*this);
        this->Qclear();
        this->assign(queue);
        queue.Qclear();
        queue.assign(temp);
        temp.Qclear();
        return;
    }
 private:
    struct Node {
        T element;
        Node* next;
        Node(T ele, Node* n = NULL) {
            element = ele;
            next = n;
        }
    };
    Node* front_node;
    Node* back_node;
    int node_num;
};

#endif /* Queue_h */
