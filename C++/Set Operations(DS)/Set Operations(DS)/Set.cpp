#include "Set.hpp"

Set::Set() {
    size = 0;
}

Set::Set(int* m, int s) {
    size = 0;
    for (int i = 0; i < s ; i++) {
        if (!isInSet(m[i])) {
            members[size++] = m[i];
        }
        if (size == MAX_MEMBERS) break;
    }
}

Set::Set(Set const &s) {
    size = s.size;
    for (int i = 0; i < size; i++) {
        members[i] = s.members[i];
    }
}

bool Set::append(int e) {
    for (int i = 0; i < size; i++) {
        if (members[i] == e)
            return 0;
    }
    members[size] = e;
    size++;
    return 1;
}

bool Set::remove(int e) {
    int check = -1;
    int i;
    for (i = 0; i < size; i++) {
        if (members[i] == e) {
            check = i;
            break;
        }
    }
    if (check != -1) {
        if (check == size - 1) {
            members[size - 1] = 0;
            size--;
            return 1;
        } else {
            for (i = check; i < size - 1; i++) {
                members[i] = members[i + 1];
            }
            members[size - 1] = 0;
            size--;
            return 1;
        }
    } else {
        return 0;
    }
}

bool Set::isEmptySet() {
    return (size == 0) ? 1 : 0;
}

int* Set::getMembers() {
    return members;
}

int Set::getSize() {
    return size;
}

bool Set::isInSet(int e) {
    for (int i = 0; i < size; i++) {
        if (members[i] == e) {
            return 1;
        }
    }
    return 0;
}

Set Set::operator&(const Set &s) {
    Set interSect = Set(*this);
    interSect = interSect - (interSect - s);
    return interSect;
}

Set Set::operator|(const Set &s) {
    Set u = Set(*this);
    for (int i = 0; i < s.size; i++) {
        if (isInSet(s.members[i]) == 0) {
            u.append(s.members[i]);
        }
    }
    return u;
}

Set Set::operator-(const Set &s) {
    Set sym = Set(*this);
    for (int i = 0; i < s.size; i++) {
        if (isInSet(s.members[i])) {
            sym.remove(s.members[i]);
        }
    }
    return sym;
}

Set Set::operator+(const Set &s) {
    Set a1 = Set(*this);
    Set a2 = Set(s);
    return ((a1 - a2) | (a2 - a1));
}
















