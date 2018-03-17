#ifndef __pair_max_min_h__
#define __pair_max_min_h__

#include <climits>

class pair_min_max {
    public:
    int min;
    int max;
    pair_min_max(): min(INT_MIN), max(INT_MAX) {}
};

#endif
