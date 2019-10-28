#include <Servo.h>

class Pez
{
  public:
    Pez(uint8_t head_pin, uint8_t tail_pin);

    void move_head(int time, int wait, int max_angle=90);
    void move_tail(int time, int wait, int max_angle=90);
    void move_head_and_tail(int time, int wait, int head_max_angle=90, int tail_max_angle=90);

  private:
    uint8_t head_pin, tail_pin;
    uint8_t head_pos, tail_pos;
    Servo head_servo, tail_servo;
};
