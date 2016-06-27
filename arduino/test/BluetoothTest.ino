#include <SoftwareSerial.h>
// the setup routine runs once when you press reset:

SoftwareSerial BTSerial(2, 3);
char buffer[1024];
int bufferPosition;

void setup() {
    Serial.begin(9600);
    Serial.println("Hello");
    BTSerial.begin(9600);
    for (int a = 0; a < 1024; a++) {
        buffer[a] = NULL;
    }
    bufferPosition = 0;
}

// the loop routine runs over and over again forever:
void loop() {
    while (BTSerial.available()) {
        buffer[bufferPosition++] = BTSerial.read();
    }
    int number = atoi(buffer);
    if (number != 0) {
        Serial.print("input data: ");
        Serial.println(number);

        int plus = number + 50;
        Serial.print("plus 50 : ");
        Serial.println(plus);

    }
    delay(100);
    for (int a = 0; a < 1024; a++) {
        buffer[a] = NULL;
    }
    bufferPosition = 0;

}
