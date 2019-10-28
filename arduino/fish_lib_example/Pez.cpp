#include <Arduino.h>
#include "Pez.h"

Pez::Pez(uint8_t head_pin, uint8_t tail_pin)
{
  this->head_pin = head_pin;
  this->tail_pin = tail_pin;

  head_servo.attach(head_pin);
  tail_servo.attach(tail_pin);

  head_pos = 90;
  tail_pos = 90;

  head_servo.write(head_pos);
  tail_servo.write(tail_pos);
}

void Pez::move_head(int time, int wait, int max_angle)
{
  int current_time = 0;

  //-- Check limits
  uint8_t dir = 1; // 1 positive, -1 negative

  while (current_time < time)
  {
    head_pos += dir;

    if (head_pos > 90+max_angle)
    {
      head_pos = 90+max_angle;
      dir = -1;
    }
    else if (head_pos < -(90+max_angle))
    {
      head_pos = -(90+max_angle);
      dir = 1;
    }

    head_servo.write(head_pos);
    delay(wait);
    current_time+=wait;
  }
}

void Pez::move_tail(int time, int wait, int max_angle)
{
  int current_time = 0;

  //-- Check limits
  uint8_t dir = 1; // 1 positive, -1 negative

  while (current_time < time)
  {
    tail_pos += dir;

    if (tail_pos > 90+max_angle)
    {
      tail_pos = 90+max_angle;
      dir = -1;
    }
    else if (tail_pos < -(90+max_angle))
    {
      tail_pos = -(90+max_angle);
      dir = 1;
    }

    tail_servo.write(tail_pos);
    delay(wait);
    current_time+=wait;
  }
}

void Pez::move_head_and_tail(int time, int wait, int head_max_angle, int tail_max_angle)
{
  int current_time = 0;

  //-- Check limits
  uint8_t head_dir = 1, tail_dir = 1; // 1 positive, -1 negative

  while (current_time < time)
  {
    head_pos += head_dir;
    tail_pos += tail_dir;

    if (head_pos > 90+head_max_angle)
    {
      head_pos = 90+head_max_angle;
      head_dir = -1;
    }
    else if (head_pos < -(90+head_max_angle))
    {
      head_pos = -(90+head_max_angle);
      head_dir = 1;
    }

    if (tail_pos > 90+tail_max_angle)
    {
      tail_pos = 90+tail_max_angle;
      tail_dir = -1;
    }
    else if (tail_pos < -(90+tail_max_angle))
    {
      tail_pos = -(90+tail_max_angle);
      tail_dir = 1;
    }

    head_servo.write(head_pos);
    tail_servo.write(tail_pos);
    delay(wait);
    current_time+=wait;
  }
}
