#include "mapper.h"

Mapper::Mapper () {
    pinMode(X_AXIS, INPUT);
    pinMode(Y_AXIS, INPUT);
    pinMode(A_BUTTON, INPUT);
    pinMode(B_BUTTON, INPUT);
    pinMode(C_BUTTON, INPUT);
    pinMode(D_BUTTON, INPUT);
    pinMode(E_BUTTON, INPUT);
    pinMode(F_BUTTON, INPUT);
}

void Mapper::updateValues() {
    bitmaskComponent[0].value = getJoystick();
    bitmaskComponent[1].value = getAButton();
    bitmaskComponent[2].value = getBButton();
    bitmaskComponent[3].value = getCButton();
    bitmaskComponent[4].value = getDButton();
    bitmaskComponent[5].value = getEButton();
    bitmaskComponent[6].value = getFButton();

    bitmask = bitmaskClass.generateBitmask(bitmaskComponentPointer, bitmaskComponentSize);
}

int Mapper::getJoystick () {
    return controllerMap(getXAxis(), getYAxis());
}

int Mapper::controllerMap(int x, int y) {
    if (x < (MIDPOINT + DEADZONE) && x > (MIDPOINT - DEADZONE)) return 0 + controllerMapY(y);
    else if (x > (MIDPOINT + DEADZONE)) return 3 + controllerMapY(y);
    return 6 + controllerMapY(y);
}

int Mapper::controllerMapY(int y) {
    if (y < (MIDPOINT + DEADZONE) && y > (MIDPOINT - DEADZONE)) return 1;
    else if (y > (MIDPOINT + DEADZONE)) return 2;
    return 3;
}
