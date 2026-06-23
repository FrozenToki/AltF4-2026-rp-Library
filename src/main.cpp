#include <Arduino.h>
#include "app/ApplicationInnit.h"
#include "Main/Setup.h"
#include "Main/Loop.h"

ApplicationInnit app;


void setup(){
	Setup();
}


void loop() {
  Loop();
}
