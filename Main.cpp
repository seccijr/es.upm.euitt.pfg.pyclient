#include "Arduino.h"

char buff[255];
int n_bytes, i;

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;
    }
}

void loop() {
    i = 0;
    n_bytes = Serial.available();
    if (n_bytes > 0) {
        memset(buff, '\0', 255);
        while (i < n_bytes && i < 255) {
            buff[i++] = (char)Serial.read();
        }

        Serial.print(buff);
    }
}
