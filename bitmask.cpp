#include "bitmask.h"

Bitmask::Bitmask () {}

int Bitmask::generateBitmask (BitmaskComponent * values, int arraySize) {
    generatedBitmask = 0;
    for (int i = 0; i < arraySize; i++) {
        generatedBitmask |= (values[i].value << values[i].bitShift);
    }
    return generatedBitmask;
}

int Bitmask::getBitmaskValue (BitmaskComponent * values, int index) {
    return (generatedBitmask >> values[index].bitShift) & values[index].bitSize;
}