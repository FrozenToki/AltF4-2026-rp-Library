#include "Teensy.h"

Teensy::Teensy(UART& serial, String n) : OutputBase(n), serialConnection(serial) {
	serialConnection.begin(115200);
}

void Teensy::send(String text) {
	serialConnection.println(text);
}

void Teensy::send(float text) {
	serialConnection.println(text);
}