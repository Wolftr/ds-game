#ifndef VLF_RAND_H
#define VLF_RAND_H
namespace vlf_rand {
    int state;

    void setSeed(int seed) {
        state = seed;
    }

    int hash() {
        state ^= 2747636419u;
        state *= 2654435769u;
        state ^= state >> 16;
        state *= 2654435769u;
        state ^= state >> 16;
        state *= 2654435769u;
        return state;
    }
}
#endif