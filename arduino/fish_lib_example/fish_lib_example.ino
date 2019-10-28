#include "Pez.h"

Pez myFish(8, 9);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  //-- Move head 1s from -90º to 90º, then wait for 1s
  myFish.move_head(1000, 20, 45);
  delay(1000);

  //-- Move tail 2s from -45º to 45º, then wait for 1s
  myFish.move_tail(2000, 30, 45);
  delay(1000);

  //-- Move both 3s, then wait for 1s
  myFish.move_head_and_tail(3000, 30, 90, 45);
  delay(1000);

}
