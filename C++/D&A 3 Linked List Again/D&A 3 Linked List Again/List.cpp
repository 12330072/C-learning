#include "List.hpp"
#include <sstream>

list::list() {
    head = NULL;
    tail = NULL;
    _size = 0;
}

list::list(const data_type a[], int length) {
    if (length == 0) {
        head = NULL;
        tail = NULL;
        _size = 0;
    } else {
        _size = length;
        head = new node;
        node* p = head;
        node* pTemp = NULL;
        for (int i = 0 ; i < length - 1; i++) {
            p->data = a[i];
            pTemp = p;
            p->next = new node;
            p = p->next;
            p->prev = pTemp;
        }
        p->data = a[length - 1];
        tail = p;
    }
}

list::list(const list& othL) {
    head = NULL;
    tail = NULL;
    _size = 0;
    *this = othL;
}

list& list::operator=(const list& othL) {
    if (this != &othL) {
        clear();
    }
    if (othL.head != NULL) {
        _size = othL._size;
        head = new node;
        node* temp = head;
        node* pTemp = NULL;
        node* oTemp = othL.head;
        for (int i = 0 ; i < othL._size - 1; i++) {
            temp->data = oTemp->data;
            pTemp = temp;
            temp->next = new node;
            temp = temp->next;
            oTemp = oTemp->next;
            temp->prev = pTemp;
        }
        temp->data = oTemp->data;
        tail = temp;
    }
    return *this;
}

bool list::empty(void) const {
    return (_size == 0);
}

list::size_type list::size(void) const {
    return _size;
}

list::data_type& list::front(void) const {
    return head->data;
}

list::data_type& list::back(void) const {
    return tail->data;
}

std::string list::toString(void) const {
    std::ostringstream outP;
    if (_size == 0) {
        outP << "NULL";
    } else {
        outP << "NULL<-";
        node* temp = head;
        for (int i = 0; i < _size - 1; i++) {
            outP << temp->data << "<->";
            temp = temp->next;
        }
        outP << temp->data << "->NULL";
    }
    return outP.str();
}

void list::assign(const list& othL) {
    clear();
    *this = othL;
}

void list::assign(const data_type datas[], int length) {
    clear();
    if (length == 0) {
        head = NULL;
        tail = NULL;
        _size = 0;
    } else {
        _size = length;
        head = new node;
        node* p = head;
        node* pTemp = NULL;
        for (int i = 0 ; i < length - 1; i++) {
            p->data = datas[i];
            pTemp = p;
            p->next = new node;
            p = p->next;
            p->prev = pTemp;
        }
        p->data = datas[length - 1];
        tail = p;
    }
}

void list::push_front(const data_type& data) {
    insert(0, data);
}

void list::push_back(const data_type& data) {
    insert(_size, data);
}

void list::pop_front(void) {
    erase(0);
}

void list::pop_back(void) {
    erase(_size - 1);
}

void list::insert(int position, const data_type& data) {
    if (position < 0 || position > this->_size) {
        return;
    }
    else if (position == _size && _size > 0) {
        node* inS = new node(data, NULL, tail);
        inS->prev->next = inS;
        tail = inS;
    }
    else if (position == 0 && _size == 0) {
        node* inS = new node(data, NULL, NULL);
        head = inS;
        tail = inS;
    }
    else if (position == 0 && _size > 0) {
        node* inS = new node(data, head, NULL);
        inS->next->prev = inS;
        head = inS;
    } else {
        node* p = head;
        while (position--) {
            p = p->next;
        }
        node* inS = new node(data, p, p->prev);
        p->prev->next = inS;
        p->prev = inS;
    }
    _size++;
}

void list::erase(int position) {
    node* temp;
    if (position < 0 || position >= this->_size) {
        return;
    }
    else if (position == 0 && _size == 1) {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else if (position == _size - 1 && _size > 1) {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    else if (position == 0 && _size > 1) {
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    } else {
        node* p = head;
        while (position--) {
            p = p->next;
        }
        temp = p;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete temp;
    }
    _size--;
}

void list::clear(void) {
    if (this->head != NULL) {
        node* p = head;
        while (p != NULL) {
            node* temp = p;
            p = p->next;
            delete temp;
        }
    }
    head = NULL;
    tail = NULL;
    _size = 0;
}

list::~list() {
    clear();
}

void list::split(int position, list* des1, list* dest2) {
    des1->clear();
    dest2->clear();
    node*p = head;
    int i;
    for (i = 0; i < _size; i++) {
        if (i < position) {
            des1->insert(des1->_size, p->data);
        } else {
            dest2->insert(dest2->_size, p->data);
        }
        p = p->next;
    }
}

list& list::merge(const list& src1, const list& src2) {
    list cpyL = src1;
    node* p = src2.head;
    while (p != NULL) {
        cpyL.insert(cpyL._size, p->data);
        p = p->next;
    }
    *this = cpyL;
    return *this;
}

list& list::remove_if(bool (*condition)(list::listPointer)) {
    node* p = head;
    node* temp = NULL;
    int _i = 0;
    int i = 0;
    while (p != NULL) {
        temp = p;
        p = p->next;
        if (condition(temp)) {
            erase(_i);
            _i--;
        }
        _i++;
        i++;
    }
    return *this;
}

list& list::unique(void) {
    list cK = *this;
    int cKCount, i;
    node* p1 = head;
    node* p2;
    while (p1 != NULL) {
        p2 = cK.head;
        cKCount = 0;
        for (i = 0; i < cK._size; i++) {
            if (p1->data == p2->data) {
                cKCount++;
            }
            if (cKCount > 1) {
                p2 = p2->next;
                cK.erase(i);  //    此处已经erase了，下面不能再p = p->next,要提前
                i--;
                cKCount--;
            } else {
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
    this->clear();
    *this = cK;
    return *this;
}

list& list::reverse(void) {
    node* p = head;
    node* temp;
    node* laP;
    temp = head;
    head = tail;
    tail = temp;
    while (p != NULL) {
        laP = p;
        p = p->next;
        temp = laP->next;
        laP->next = laP->prev;
        laP->prev = temp;
    }
    return *this;
}

list::data_type& list::operator[](int index) {
    node*p = head;
    while (index--) {
        p = p->next;
    }
    return p->data;
}

list& list::operator+=(const list& othL) {
    node* p = othL.head;
    while (p != NULL) {
        insert(_size, p->data);
        p = p->next;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const list& li) {
    os << li.toString();
    return os;
}

//list cpy = *this;
//des1->clear();
//dest2->clear();
//    node* oTemp = this->head;
//    if (position > 0) {
//        des1->_size = position;
//        des1->head = new node;
//        node* temp1 = des1->head;
//        node* pTemp1 = NULL;
//        for (i = 0 ; i < position - 1; i++) {
//            temp1->data = oTemp->data;
//            pTemp1 = temp1;
//            temp1->next = new node;
//            temp1 = temp1->next;
//            oTemp = oTemp->next;
//            temp1->prev = pTemp1;
//        }
//        temp1->data = oTemp->data;
//        des1->tail = temp1;
//        oTemp = oTemp->next;
//    }
//    if (_size - position > 0) {
//        dest2->_size = _size - position;
//        dest2->head = new node;
//        node* temp2 = dest2->head;
//        node* pTemp2 = NULL;
//        for (i = 0 ; i < position - 1; i++) {
//            temp2->data = oTemp->data;
//            pTemp2 = temp2;
//            temp2->next = new node;
//            temp2 = temp2->next;
//            oTemp = oTemp->next;
//            temp2->prev = pTemp2;
//        }
//        temp2->data = oTemp->data;
//        dest2->tail = temp2;
//    }
//    for (i = 0; i < position; i++) {
//        des1->insert(des1->_size, cpy[i]);
//    }
//    for (i = position; i < _size; i++) {
//        dest2->insert(dest2->_size, cpy[i]);
//    }


//list& list::merge(const list& src1, const list& src2) {
//    list cpyL = src1;
//    list catL = src2;
//    cpyL.tail->next = catL.head;
//    catL.head->prev = cpyL.tail;
//    cpyL._size += catL._size;
//    cpyL.tail = catL.tail;
//    this->clear();
//    *this = cpyL;
//    return *this;
//}

//    list othL = list();
//    node* p = head;
//    while (p != NULL) {
//        insert(0, p->data);
//        p = p->next;
//    }
//    *this = othL;
//    return *this;

//list& list::unique(void) {
//    list cK = *this;
//    int cKCount;
//    node* p1 = head;
//    while (p1 != NULL) {
//        cKCount = 0;
//        for (int i = 0; i < cK._size; i++) {
//            if (p1->data == cK[i]) {
//                cKCount++;
//            }
//            if (cKCount > 1) {
//                cK.erase(i);
//                i--;
//                cKCount--;
//            }
//        }
//        p1 = p1->next;
//    }
//    *this = cK;
//    return *this;
//}






