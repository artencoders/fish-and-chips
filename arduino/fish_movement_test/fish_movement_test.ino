/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servo_head, servo_tail;


void move_head(int angle, int velocity, int duration, int offset=0)
{
  int repeat = ceil(duration/(4.0*velocity*angle));

  for (int i=0; i < repeat; i++)
  {
    for (int j=90-angle; j < 90+angle; j++)
    {
      servo_head.write(constrain(j+offset, 0, 180));
      delay(velocity);
    }
    for (int j=90+angle; j > 90-angle; j--)
    {
      servo_head.write(constrain(j+offset, 0, 180));
      delay(velocity);
    }
  }
}

void move_tail(int angle, int velocity, int duration, int offset=0)
{
  int repeat = ceil(duration/(4.0*velocity*angle));

  for (int i=0; i < repeat; i++)
  {
    for (int j=90-angle; j < 90+angle; j++)
    {
      servo_tail.write(constrain(j+offset, 0, 180));
      delay(velocity);
    }
    for (int j=90+angle; j > 90-angle; j--)
    {
      servo_tail.write(constrain(j+offset, 0, 180));
      delay(velocity);
    }
  }
}


void move_both(int angle, int velocity, int duration, int offset_head=0, int offset_tail=0)
{
  int repeat = ceil(duration/(4.0*velocity*angle));

  for (int i=0; i < repeat; i++)
  {
    for (int j=90-angle; j < 90+angle; j++)
    {
      servo_head.write(constrain(j+offset_head, 0, 180));
      servo_tail.write(constrain(j+offset_tail, 0, 180));
      delay(velocity);
    }
    for (int j=90+angle; j > 90-angle; j--)
    {
      servo_head.write(constrain(j+offset_head, 0, 180));
      servo_tail.write(constrain(j+offset_tail, 0, 180));
      delay(velocity);
    }
  }
}

void setup() 
{
  servo_head.attach(10);
  servo_tail.attach(9);
}

void loop() 
{
  move_head(45, 15, 6000);
  move_head(45,  7, 4000);

  move_both(45, 30, 5000);
  move_both(45,  7, 6000);
  move_both(45, 15, 4000);
  
  move_tail(45, 15, 6000);
  move_tail(45,  7, 4000);

  move_both(45, 30, 5000);
  move_both(45,  7, 6000);
  move_both(45, 15, 4000);

  move_tail(45, 15, 6000);
  move_tail(10,  5, 4000);

  move_both(15, 5, 5000);
  move_both(10,  6, 6000);
  move_both(10, 5, 4000);

  move_both(20, 5, 5000);
  move_both(25,  6, 6000);
  move_both(20, 5, 4000);

  move_head(45, 10, 3000, 45);
  move_head(45, 10, 3000, -45);

  move_tail(45, 10, 2000 +45);
  move_tail(45,  5, 3000 -45);
  
}
