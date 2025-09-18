#pragma once

inline long long clamp(long long x, long long min, long long max);
inline long long map(long long x, long long in_min, long long in_max, long long out_min, long long out_max);
inline long long lerp(long long a, long long b, double t);
inline long long distance(long long x1, long long y1, long long x2, long long y2);
inline long long wrap(long long x, long long min, long long max);