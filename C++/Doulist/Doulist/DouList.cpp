#include "DouList.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::string;
using std::ostream;
using std::ostringstream;

int DouList::_error_sign = -1;

DouList::DouList() {
    m_head = NULL;
    m_tail = NULL;
}

DouList::DouList(const DouList &src) {
    if (src.m_head != NULL) {
        DouListNode* p1 = src.m_head;
        m_head = new DouListNode(p1->elem, NULL, NULL);
        DouListNode* p2 = m_head;
        while (p1->next != NULL) {
            p2->next = new DouListNode(p1->next->elem, p2, NULL);
            p1 = p1->next;
            p2 = p2->next;
        }
        m_tail = p2;
    } else {
        m_tail = NULL;
        m_head = NULL;
    }
}

DouList::~DouList() {
    if (m_head != NULL) {
        clear();
    }
}

void DouList::clear() {
    DouListNode *p = m_head;
    DouListNode *temp = NULL;
    while (p != NULL) {
        temp = p;
        p = p->next;
        delete temp;
    }
    m_head = NULL;
    m_tail = NULL;
}

bool DouList::empty() const {
    return m_tail == NULL;
}

std::string DouList::to_str() const {
    DouListNode *p = m_head;
    ostringstream out;
    out << '[';
    while (p != NULL) {
        out << p->elem;
        if (p->next != NULL) {
            out << ", ";
        }
        p = p->next;
    }
    out << ']';
    return out.str();
}

int DouList::front() const {
    if (m_head != NULL) {
        return m_head->elem;
    } else {
        return _error_sign;
    }
}

int DouList::back() const {
    if (m_tail != NULL) {
        return m_tail->elem;
    } else {
        return _error_sign;
    }
}

void DouList::push_front(const int &e) {
    DouListNode* temp = new DouListNode(e, NULL, m_head);
    if (m_head == NULL) {
        m_tail = m_head = temp;
    } else {
        m_head->prev = temp;
        m_head = temp;
    }
}

void DouList::push_back(const int &e) {
    DouListNode* temp = new DouListNode(e, m_tail, NULL);
    if (m_head == NULL) {
        m_tail = m_head = temp;
    } else {
        m_tail->next = temp;
        m_tail = temp;
    }
}

void DouList::pop_front() {
    if (m_head != NULL) {
        DouListNode *temp = m_head;
        if (m_head->next != NULL) {
            m_head = m_head->next;
            m_head->prev = NULL;
        } else {
            m_head = m_tail = NULL;
        }
        delete temp;
    }
}

void DouList::pop_back() {
    if (m_tail != NULL) {
        DouListNode *temp = m_tail;
        if (m_tail->prev != NULL) {
            m_tail = m_tail->prev;
            m_tail->next = NULL;
        } else {
            m_head = m_tail = NULL;
        }
        delete temp;
    }
}

void DouList::operator=(const DouList &other) {
    this->clear();
    if (other.m_head != NULL) {
        DouListNode* p1 = other.m_head;
        m_head = new DouListNode(p1->elem, NULL, NULL);
        DouListNode* p2 = m_head;
        while (p1->next != NULL) {
            p2->next = new DouListNode(p1->next->elem, p2, NULL);
            p1 = p1->next;
            p2 = p2->next;
        }
        m_tail = p2;
    } else {
        m_tail = NULL;
        m_head = NULL;
    }
}

std::ostream& operator<<(std::ostream &out,
                                const DouList &list) {
    out << list.to_str();
    return out;
}
// non-meaning static value
static int _error_sign;  // for illegal front()/back()



