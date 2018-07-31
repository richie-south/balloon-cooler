#include <Servo.h>
Servo myservo;

int servo_pos = 180;
int button_pin = 7;
boolean valve_open_state = false;

void setup() {
  myservo.attach(8);
  myservo.write(servo_pos);

  pinMode(button_pin, INPUT);
  digitalWrite(button_pin, HIGH);

  delay(500);
}

boolean handle_button(int pin) {
  int button_pressed = !digitalRead(pin);
  return button_pressed;
}

void open_valve() {
  if (!valve_open_state) {
    myservo.write(70);
    valve_open_state = true;
    delay(300);
  }
}

void close_vale() {
  if (valve_open_state) {
    myservo.write(180);
    valve_open_state = false;
    delay(300);
  }
}

void loop() {
  boolean is_pressed = handle_button(button_pin);

  if (is_pressed) {
    open_valve();
  } else {
    close_vale();
  }
}
