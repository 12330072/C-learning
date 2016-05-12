template<typename T>
class Stack {
public:
    Stack() {
        top_node = NULL;
        node_num = 0;
    }
    Stack(const Stack &stack) {
        if (stack.top_node != NULL) {
            Node* p1 = stack.top_node;
            top_node = new Node(stack.top_node->element, NULL);
            Node *p2 = top_node;
            while (p1->next != NULL) {
                p2->next = new Node(p1->next->element, NULL);
                p2 = p2->next;
                p1 = p1->next;
            }
            node_num = stack.node_num;
        } else {
            top_node = NULL;
            node_num = 0;
        }
    }
    ~Stack() {
        clear();
    }
    bool empty() {
        if (node_num == 0) return 1;
        else return 0;
    }
    size_t size() const {
        return node_num;
    }
    T top() const {
        return top_node->element;
    }
    void push(T element) {
        if (top_node == NULL) {
            top_node = new Node(element);
        } else {
            Node *temp = new Node(element);
            temp->next = top_node;
            top_node = temp;
            temp->element = element;
        }
        node_num++;
    }
    void pop() {
        if (empty()) {
            return;
        }
        if (size() == 1) {
            delete top_node;
            top_node = NULL;
        }
        else if (size() > 1){
            Node *ptr = top_node->next;
            delete top_node;
            top_node = ptr;
        }
        node_num--;
    }
    void swap(Stack& stack) {
        int old_size = size();
        while (!empty()) {
            stack.push(top());
            pop();
        }
        while (stack.size() > old_size) {
            push(stack.top());
            stack.pop();
        }
    }
    void reverse() {
        T* a = new T[node_num];
        int i;
        size_t b = node_num;
        for (i = 0; i < b; i++) {
            a[i] = top_node->element;
            pop();
        }
        for (i = 0; i < b; i++) {
            push(a[i]);
        }
        delete []a;
    }
    void clear() {
        Node *ptr = NULL;
        while (top_node != NULL) {
            ptr = top_node->next;
            delete top_node;
            top_node = ptr;
        }
        node_num = 0;
        top_node = NULL;
    }
private:
    struct Node {
        T element;
        Node* next;
        Node(T ele, Node *n = NULL) {
            element = ele;
            next = n;
        }
    };
    Node *top_node;
    size_t node_num;
};