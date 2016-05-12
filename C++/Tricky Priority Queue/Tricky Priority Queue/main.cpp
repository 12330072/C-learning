#include <iostream>
#include <deque>

int main(int argc, const char * argv[]) {
    using namespace std;
    int temp;
    int n, my_pos;
    int maxPri;
    int maxPos;
    unsigned time = 0;
    cin >> n >> my_pos;
    deque<int> print_queue;
    while (n--) {
        cin >> temp;
        print_queue.push_back(temp);
    }
    while (1) {
        maxPri = 0;
        maxPos = 0;
        for (int i = 0; i < print_queue.size(); i++) {
            if (print_queue[i] > maxPri) {
                maxPri = print_queue[i];
                maxPos = i;
            }
        }
        while (maxPos--) {
            print_queue.push_back(print_queue[0]);
            print_queue.pop_front();
            if (my_pos != 0) {
                my_pos--;
            } else {
                my_pos = print_queue.size() - 1;
            }
        }
        time++;
        if (my_pos == 0) {
            break;
        }
        my_pos--;
        print_queue.pop_front();
    }
    cout << time << endl;
}
