#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iterator>
#include <queue>
using namespace std;

struct Proprety {
    bool visit;
    int imp;
    Proprety(bool _visit = true, int _imp = -1) : visit(_visit), imp(_imp) {}
};

void BFS(map<string, set<string>> *social_tree, map<string, Proprety> *social_imp);

int main(int argc, const char * argv[]) {
    map<string, set<string>> social_tree;
    map<string, Proprety> social_imp;
    int n;
    string str1, str2, str3;
    cin >> n;
    while (n--) {
        cin >> str1 >> str2 >> str3;
        social_tree[str1].insert(str2);
        social_tree[str1].insert(str3);
        social_tree[str2].insert(str1);
        social_tree[str2].insert(str3);
        social_tree[str3].insert(str1);
        social_tree[str3].insert(str2);
    }
    BFS(&social_tree, &social_imp);
}

void BFS(map<string, set<string>> *social_tree, map<string, Proprety> *social_imp) {
    queue<string> q;
    //  iter: social_tree
    //  iter1: social_imp
    //  iter2: set
    map<string, set<string>>::iterator iter;
    map<string, Proprety>::iterator iter1;
    set<string>::iterator iter2;
    for (iter = social_tree->begin(); iter != social_tree->end(); iter++) {
        Proprety temp(true, -1);
        social_imp->insert(pair<string, Proprety>(iter->first, temp));
    }
    if (social_tree->find("Isenbaev") != social_tree->end()) {
        while (!q.empty()) q.pop();
        string now_step = "Isenbaev";
        iter1 = social_imp->find(now_step);
        iter1->second.imp = 0;
        iter1->second.visit = false;
        q.push(now_step);
        while (!q.empty()) {
            now_step = q.front();
            q.pop();
            iter = social_tree->find(now_step);
            for (iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++) {
                iter1 = social_imp->find(*iter2);
                if (iter1->second.visit == true) {
                    iter1->second.visit = false;
                    q.push(*iter2);
                    iter1->second.imp = social_imp->find(now_step)->second.imp + 1;
                }
            }
        }
    }
    for (iter1 = social_imp->begin(); iter1 != social_imp->end(); iter1++) {
        cout << iter1->first << ' ';
        if (iter1->second.imp == -1) {
            cout << "undefined" << endl;
        } else {
            cout << iter1->second.imp << endl;
        }
    }
}
