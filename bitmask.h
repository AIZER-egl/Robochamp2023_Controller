#include <Arduino.h>

#ifndef BITMASK_H
#define BITMASK_H

class Bitmask {
    private:
        int generatedBitmask;

    public:
        Bitmask ();
        
        struct BitmaskComponent {
            int value;
            int bitSize;
            int bitShift;
        };

        int generateBitmask (BitmaskComponent * values, int arraySize);
        int getBitmaskValue (BitmaskComponent * values, int index);
};

#endif