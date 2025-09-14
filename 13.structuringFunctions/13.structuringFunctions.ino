/*
  Author: Samuel.H

  Intention: To create a system that will read when the button (Pretending it to be a doorbell) is pressed it will be read by the buzzer, 
which will make a sound, notifying the user someone is pressing the button (or at the door) this will then show 
on the OLED screen that the button has been pressed, as a state of ON or OFF. 
  
  Success Criteria:
    1. Make it Work

  Student Notes:
    Good luck
  Documentation:
      
*/

unsigned static int buzzer = 3;
unsigned static int button = 6;

Button mybutton;
button mybutton(button);

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

void setup() {
  pinMode(3, OUTPUT);
  pinMode(6, INPUT);

  OLED.begin();
  OLED.setFont(u8g2_font_6x12_tf);
}

void loop() {
  
}
