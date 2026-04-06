#include "finders.h"
#include <stdio.h>

int main() {
    int structType = Village;  // or Outpost, Monument, etc.
    int mc = MC_1_18;
    Generator g;
    setupGenerator(&g, mc, 0);

    uint64_t lower48;
    for (lower48 = 0; ; lower48++) {
        Pos p;
        if (!getStructurePos(structType, mc, lower48, 0, 0, &p)) continue;
        if (p.x >= 16 || p.z >= 16) continue;  // Must be in origin chunk

        uint64_t upper16;
        for (upper16 = 0; upper16 < 0x10000; upper16++) {
            uint64_t seed = lower48 | (upper16 << 48);
            applySeed(&g, DIM_OVERWORLD, seed);
            if (isViableStructurePos(structType, &g, p.x, p.z, 0)) {
                printf("Seed %" PRId64 " has a structure at (%d, %d)\n", (int64_t)seed, p.x, p.z);
                return 0;
            }
        }
    }
}   
