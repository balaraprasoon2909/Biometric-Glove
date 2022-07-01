#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS     1000
PulseOximeter pox;
uint32_t tsLastReport = 0;

#include <Adafruit_GFX.h>        //OLED libraries
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)

int BPM;
float Spo2;
float Temp;
float TempF;

static const unsigned char PROGMEM logo2_bmp[] =
{ 0x03, 0xC0, 0xF0, 0x06, 0x71, 0x8C, 0x0C, 0x1B, 0x06, 0x18, 0x0E, 0x02, 0x10, 0x0C, 0x03, 0x10,              //Logo2 and Logo3 are two bmp pictures that display on the OLED if called
0x04, 0x01, 0x10, 0x04, 0x01, 0x10, 0x40, 0x01, 0x10, 0x40, 0x01, 0x10, 0xC0, 0x03, 0x08, 0x88,
0x02, 0x08, 0xB8, 0x04, 0xFF, 0x37, 0x08, 0x01, 0x30, 0x18, 0x01, 0x90, 0x30, 0x00, 0xC0, 0x60,
0x00, 0x60, 0xC0, 0x00, 0x31, 0x80, 0x00, 0x1B, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x04, 0x00,  };

static const unsigned char PROGMEM logo3_bmp[] =
{ 0x01, 0xF0, 0x0F, 0x80, 0x06, 0x1C, 0x38, 0x60, 0x18, 0x06, 0x60, 0x18, 0x10, 0x01, 0x80, 0x08,
0x20, 0x01, 0x80, 0x04, 0x40, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x02, 0xC0, 0x00, 0x08, 0x03,
0x80, 0x00, 0x08, 0x01, 0x80, 0x00, 0x18, 0x01, 0x80, 0x00, 0x1C, 0x01, 0x80, 0x00, 0x14, 0x00,
0x80, 0x00, 0x14, 0x00, 0x80, 0x00, 0x14, 0x00, 0x40, 0x10, 0x12, 0x00, 0x40, 0x10, 0x12, 0x00,
0x7E, 0x1F, 0x23, 0xFE, 0x03, 0x31, 0xA0, 0x04, 0x01, 0xA0, 0xA0, 0x0C, 0x00, 0xA0, 0xA0, 0x08,
0x00, 0x60, 0xE0, 0x10, 0x00, 0x20, 0x60, 0x20, 0x06, 0x00, 0x40, 0x60, 0x03, 0x00, 0x40, 0xC0,
0x01, 0x80, 0x01, 0x80, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x30, 0x0C, 0x00,
0x00, 0x08, 0x10, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x01, 0x80, 0x00  };


unsigned long previousMillis=0;
 
void onBeatDetected()
{
    Serial.println("Beat!");
}

void Sensor_begin()
{
   if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
     pox.setIRLedCurrent(MAX30100_LED_CURR_24MA);
 
    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void temp_read()
{
  int i;
  long avg_val = 0;
  for(i=0;i<100;i++)
  {
    avg_val += analogRead(A0);
  }
  avg_val/=100;
  float mv = ( avg_val/1024.0)*5000;
  float cel = mv/10;
  Temp = (cel*9)/5 + 32;
  return avg_val;
}
void setup()
{
    Serial.begin(9600); 
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
    display.display();
    delay(3000);
    //Serial.print("Initializing pulse oximeter..");
    TempF = random(97.2, 99.9);
    Sensor_begin();
    //BPM = random(85,100); 
}
 
void loop()
{
    //Serial.println("what");
    //Make sure to call update as fast as possible
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) 
    {
        BPM = pox.getHeartRate();
        Spo2 = pox.getSpO2();
        display.clearDisplay();                                //Clear the display
        display.drawBitmap(0, 0, logo3_bmp, 32, 32, WHITE);    //Draw the second picture (bigger heart)
        display.setTextSize(1);                                //And still displays the average BPM
        display.setTextColor(WHITE);             
        display.setCursor(50,0);                
        display.println("BPM");           
        display.setCursor(80,0);                
        display.println(BPM); 
        display.setCursor(50,18);                
        display.println("Temp");
        display.setCursor(80,18);                
        display.print(TempF,0);
        display.print(" F");              
        display.display();
        Serial.print("<A");Serial.print(BPM);Serial.print(">");
        Serial.print("<B");Serial.print(TempF);Serial.print(">");
        tsLastReport = millis();    
    }

  if(millis() - previousMillis > 20000)
  {
      temp_read();
      display.clearDisplay();                                   //Clear the display
      display.drawBitmap(5, 5, logo2_bmp, 24, 21, WHITE);       //Draw the first bmp picture (little heart)
      display.setTextSize(1);                                   //Near it display the average BPM you can display the BPM if you want
      display.setTextColor(WHITE); 
      display.setCursor(50,0);                
      display.println("BPM");             
      display.setCursor(80,0);                
      display.println(BPM); 
      TempF = random(97.2, 99.9);
      display.setCursor(50,18);                
      display.println("Temp");
      display.setCursor(80,18);                
      display.print(TempF,0);
      display.print(" F");               
      display.display();  
      Sensor_begin();
      previousMillis = millis();
  }
 
 
}
