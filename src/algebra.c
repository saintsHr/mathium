#include "mathium/algebra.h"
#include "mathium/helpers.h"

inline long long clamp(long long x, long long min, long long max){
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

inline long long map(long long x, long long in_min, long long in_max, long long out_min, long long out_max) {
    if (in_max == in_min) return out_min;
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

inline long long lerp(long long a, long long b, double t){
    if (t >= 1.0) return b;
    if (t <= 0.0) return a;

    return a + (b - a) * t;
}

inline long long distance(long long x1, long long y1, long long x2, long long y2){
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    return sqrt_h(dx*dx + dy*dy);
}

inline long long wrap(long long x, long long min, long long max){
    if (max == min) return min;
    long long range = max - min;
    return ((x - min) % range + range) % range + min;
}