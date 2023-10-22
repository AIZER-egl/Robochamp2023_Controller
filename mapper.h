#include <Arduino.h>
#include "bitmask.h"

#ifndef MAPPER_H
#define MAPPER_H

#define X_AXIS A0
#define Y_AXIS A1

#define MIDPOINT 512
#define DEADZONE 50

#define A_BUTTON 2
#define B_BUTTON 3
#define C_BUTTON 4
#define D_BUTTON 5
#define E_BUTTON 6
#define F_BUTTON 7

class Mapper {
    private:
        int controllerMap (int x, int y);
        int controllerMapY (int y);
        unsigned short getXAxis () { return analogRead(X_AXIS); };
        unsigned short getYAxis () { return analogRead(Y_AXIS); };
        bool getAButton () { return !digitalRead(A_BUTTON); };
        bool getBButton () { return !digitalRead(B_BUTTON); };
        bool getCButton () { return !digitalRead(C_BUTTON); };
        bool getDButton () { return !digitalRead(D_BUTTON); };
        bool getEButton () { return !digitalRead(E_BUTTON); };
        bool getFButton () { return !digitalRead(F_BUTTON); };

        uint8_t bitmaskComponentSize = 7;
        Bitmask::BitmaskComponent bitmaskComponent[7] {
            { getJoystick(), 0x0F, 6 },
            { getAButton(), 0x01, 5 },
            { getBButton(), 0x01, 4 },
            { getCButton(), 0x01, 3 },
            { getDButton(), 0x01, 2 },
            { getEButton(), 0x01, 1 },
            { getFButton(), 0x01, 0 },
        };
    public:
        Mapper ();
        Bitmask::BitmaskComponent * bitmaskComponentPointer = bitmaskComponent;

        int getJoystick ();

        void updateValues();
        
        unsigned short bitmask;
        Bitmask bitmaskClass;
};

#endif