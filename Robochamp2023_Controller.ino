#include "mapper.h"

Mapper mapper;
void setup () {
    Serial.begin(38400);
}

void loop () {
    mapper.updateValues();
    // Serial.print("J: "); Serial.print(mapper.bitmaskClass.getBitmaskValue(mapper.bitmaskComponentPointer, 0));
    // Serial.print("   A: "); Serial.print(mapper.bitmaskClass.getBitmaskValue(mapper.bitmaskComponentPointer, 1));
    // Serial.print("   B: "); Serial.print(mapper.bitmaskClass.getBitmaskValue(mapper.bitmaskComponentPointer, 2));
    // Serial.print("   C: "); Serial.print(mapper.bitmaskClass.getBitmaskValue(mapper.bitmaskComponentPointer, 3));
    // Serial.print("   D: "); Serial.print(mapper.bitmaskClass.getBitmaskValue(mapper.bitmaskComponentPointer, 4));
    // Serial.print("   E: "); Serial.print(mapper.bitmaskClass.getBitmaskValue(mapper.bitmaskComponentPointer, 5));
    // Serial.print("   F: "); Serial.print(mapper.bitmaskClass.getBitmaskValue(mapper.bitmaskComponentPointer, 6));
    // Serial.print("   ");
    Serial.print(mapper.bitmask);
    Serial.print("\n");

    delay(1000 / 10);
}
