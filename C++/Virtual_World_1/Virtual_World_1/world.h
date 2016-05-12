#ifndef world_h
#define world_h
#include <iostream>
#define MAX_NUM 50
using std::cout;
using std::endl;

struct person {
    int _id;
    person() {
        static int p_num = 0;
        _id = p_num++;
    }
};

class group {
  public:
    explicit group(bool a) {
        ini = a;
        gp_num = 0;
        for (int i = 0; i < MAX_NUM; i++) {
            for (int j = 0; j < MAX_NUM; j++) {
                socialNet[i][j] = -1;
            }
        }
    }
    void displayGroup() {
        int i, j;
        for (i = 0; i < MAX_NUM; i++) {
            if (socialNet[i][0] >= 0) {
                cout << "Person_" << i << ": ";
                if (socialNet[i][0] == 0) {
                    cout << "null";
                } else {
                    j = 1;
                    while (j < MAX_NUM) {
                        if (socialNet[i][j] != -1) {
                            cout << socialNet[i][j];
                            j++;
                            break;
                        }
                        j++;
                    }
                    while (j < MAX_NUM) {
                        if (socialNet[i][j] != -1) {
                            cout << ", "<< socialNet[i][j];
                        }
                        j++;
                    }
                }
                cout << endl;
            }
        }
    }
    bool addMember(const person &p) {
        if (socialNet[p._id][0] >= 0 || gp_num == MAX_NUM) {
            return false;
        }
        socialNet[p._id][0] = 0;
        gp_num++;
        if (ini == 1) {
            for (int i = 0; i < MAX_NUM; i++) {
                if (socialNet[i][0] >= 0 && i != p._id) {
                    socialNet[i][0]++;
                    socialNet[i][socialNet[i][0]] = p._id;
                    socialNet[p._id][0]++;
                    socialNet[p._id][socialNet[p._id][0]] = i;
                }
            }
        }
        return true;
    }
    bool deleteMember(const person &p) {
        if (socialNet[p._id][0] == -1) {
            return false;
        }
        socialNet[p._id][0] = -1;
        gp_num--;
        return true;
    }
    bool makeFriend(const person &p1, const person &p2) {
        if (socialNet[p1._id][0] == -1 && socialNet[p2._id][0] == -1) {
            return false;
        }
        for (int i = 0; i < socialNet[p1._id][0]; i++) {
            if (socialNet[p1._id][i] == p2._id) return false;
        }
        for (int i = 0; i < socialNet[p2._id][0]; i++) {
            if (socialNet[p2._id][i] == p1._id) return false;
        }
        socialNet[p1._id][0]++;
        socialNet[p2._id][0]++;
        socialNet[p1._id][socialNet[p1._id][0]] = p2._id;
        socialNet[p2._id][socialNet[p2._id][0]] = p1._id;
        return true;
    }
    bool breakRelation(const person &p1, const person &p2) {
        unsigned check = 0;
        if (socialNet[p1._id][0] == -1 && socialNet[p2._id][0] == -1) {
            return false;
        }
        for (int i = 1; i <= socialNet[p1._id][0]; i++) {
            if (socialNet[p1._id][i] == p2._id) {
                check++;
                socialNet[p1._id][i] = -1;
                socialNet[p1._id][0]--;
            }
        }
        for (int i = 1; i <= socialNet[p2._id][0]; i++) {
            if (socialNet[p2._id][i] == p1._id) {
                check++;
                socialNet[p2._id][i] = -1;
                socialNet[p2._id][0]--;
            }
        }
        if (check == 2) return true;
        else return false;
    }
  private:
    int socialNet[MAX_NUM][MAX_NUM];
    unsigned gp_num;
    bool ini;
};

#endif /* world_h */
