#ifndef Timer_h
#define Timer_h
#define MAX_TIMER 5

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
using std::ostringstream;
using std::endl;
using std::cout;

static int _clock;
inline void clock_f() {
    _clock += 50;
}
inline double getTime();

namespace TIC_TOC {
    class timer {
    public:
        timer() {
            times = 0;
            sum = 0;
        }
        void tic_f(int n) {
            time[n] = _clock;
        }
        void toc_f(int n) {
            times = n;
            time[n - 1] = _clock - time[n - 1];
            sum += time[n - 1];
        }
        void tictoc(FILE* fuck) {
            for (int i = 0; i < times; i++) {
                ostringstream outP;
                double s = static_cast<double>(time[i]) / 1000;
                outP << "line " << i << " - " << i + 1 << ": "
                << std::setprecision(3) << std::fixed << s << "ms" << endl;
                cout << outP.str();
            }
        }
        int getSum() {
            return sum;
        }
    private:
        int sum;
        int times;
        int time[10000];
    };
    class timer_controller {
        timer timePiece[MAX_TIMER];
    public:
        timer_controller() {
            _clock = 0;
            timerN = 0;
        }
        void create(int n) {
            if (n > 0 && n <= MAX_TIMER) {
                timerN = n;
            }
        }
        timer& operator[](const int& n) {
            return timePiece[n];
        }
        void display(FILE* fuck) {
            for (int i = 0; i < timerN; i++) {
                double s = static_cast<double>(timePiece[i].getSum()) / 1000;
                cout << "#Timer_" << (i + 1) << ": " << std::setprecision(3)
                << std::fixed << s << "ms" << endl;
            }
        }
    private:
        int timerN;
    };
}   // namespace TIC_TOC

#endif /* Timer_h */
