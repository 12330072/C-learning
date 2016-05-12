#ifndef random_my_h
#define random_my_h

namespace RAND_GEN {
    class mod_my {
    public:
        long long m, a, c;
        mod_my(long long _m, long long _a, long long _c) : m(_m), a(_a), c(_c) {}
        long long calc(long long x) {
            if (a == 1) {
                x%=m;
            } else {
                long long q = m / a;
                long long r = m % a;
                x = a * (x % q) - r * (x / q);
                if (x < 0) x += m;
            }
            x += c;
            if (x > m) x -= m;
            return x;
        }
    };
    class linear_congruential_engine_my {
    public:
        long long multiplier, increment, modulus;
        unsigned long long default_seed_my, seed_my;
        mod_my mod_temp;
        linear_congruential_engine_my() : multiplier(16807), increment(1), modulus(2147483647), mod_temp(modulus, multiplier, increment) {
            seed_my = default_seed_my = 1u;
        }
        linear_congruential_engine_my(long long _m, long long _a, long long _c, long long _s) :
        multiplier(_a), increment(_c), modulus(_m), default_seed_my(_s), mod_temp(modulus, multiplier, increment) {
            seed_my = default_seed_my;
        }
        void seed(unsigned long long _s) {
            seed_my = _s;
        }
        long long min() {
            if (increment == 0u) {
                return 1u;
            } else {
                return 0u;
            }
        }
        long long max() {
            return modulus - 1u;
        }
        void discard(unsigned long long _x) {
            while (_x--) {
                (*this)();
            }
        }
        long long operator()() {
            seed_my = mod_temp.calc(seed_my);
            return seed_my;
        }
    };
}  // namespace RAND_GEN


#endif /* random_my_h */
