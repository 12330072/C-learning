#ifndef counter1_h
#define counter1_h

class counter1 {
  public:
    static int counter;
    counter1() {
    }
    static void count() {
        counter++;
    }
    void operator()() {
        counter++;
    }
};

int counter1::counter = 0;

#endif /* counter1_h */
