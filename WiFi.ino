

//#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "cH8Dy-LJcBSbE8CV8qHr2RuElVP1Hzx1";
char ssid[] = "Note10";
char pass[] = "xxwk9503";

char cmd_arr1[100];
int cmd_count1;

int BPM;
float Temp;

//*****************************************************************
void serial_get_command()
{
  char inchar=0;
  if(Serial.available() > 0)
  {
    inchar = Serial.read();    
    if(inchar == '<')
    {
      cmd_count1=0;
      while(inchar != '>' && cmd_count1<80)
      {
        if(Serial.available() > 0)
        {
          inchar = Serial.read();
          cmd_arr1[cmd_count1++] = inchar;
          cmd_arr1[cmd_count1] = '\0';
        }        
      }
      if(inchar == '>')
      {
        cmd_count1--;
        cmd_arr1[cmd_count1] = '\0';
        
        if(cmd_arr1[0]=='A')
        {cmd_arr1[0]='0';BPM = atoi(cmd_arr1);Blynk.virtualWrite(V0, BPM);}
        else if(cmd_arr1[0]=='B')
        {cmd_arr1[0]='0';Temp = atof(cmd_arr1);Blynk.virtualWrite(V1, Temp);}
        else
        {
          
        }
      }
    }
  }
}
//*****************************************************************
BLYNK_CONNECTED()
{
  digitalWrite(2, HIGH);
}
//*****************************************************************
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);digitalWrite(2, LOW);
  Blynk.begin(auth, ssid, pass);
  delay(2000);
  
}
//*****************************************************************
void loop()
{
  if(!Blynk.connected())
  {
    Serial.println("Reconnecting ... ");
    digitalWrite(2, LOW);
    Blynk.connect();
  }
  Blynk.run();
  serial_get_command();
}
//*****************************************************************
