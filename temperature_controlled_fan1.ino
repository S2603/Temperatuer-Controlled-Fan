//including the library
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

float temp;
int tempPin=A1;
int speed;
#define fan 9

void setup()
{
  //Fan Pin 9 for output
  pinMode (fan,OUTPUT);
  //Setting Lcd rows and coloumns
  lcd.begin(16,3);
  int i,j;

  for(j=0;j<16;j++)
    {lcd.setCursor(j,0);
    lcd.print("Made By Shuvo");
     delay(200);
     lcd.clear();    
   }
  for(j=16;j>0;j--)
    {lcd.setCursor(j,1);
    lcd.print("Made By Shuvo");
     delay(100);
     lcd.clear();
    
   }
 lcd.clear();
   
}

void disp()
  
{	temp=analogRead(tempPin);
  	temp=temp*0.48828125-49.71;
 
 	lcd.setCursor(0,0);
 	lcd.print("Temp=");
 	lcd.setCursor(5,0);
 	lcd.print(temp);
    speed=temp/30*100;
 if(speed>100)
   speed=100;
 if(temp<0)
   speed=0;

 lcd.setCursor(0,1);
  lcd.print("Speed=");
 lcd.setCursor(6,1);
  lcd.print(speed);
 if(speed<100)
 {lcd.setCursor(8,1);
  lcd.print("% ");} 
 if(speed<10)
 {lcd.setCursor(7,1);
  lcd.print("%  ");} 
if(speed==100)
 {lcd.setCursor(9,1);
  lcd.print("%");} 
}
 



void loop()
{	disp();
  if (temp<20)
    digitalWrite(fan,LOW);
  else if(temp<=22)
    digitalWrite(fan,HIGH);
  else if(temp<=24)
      digitalWrite(fan,HIGH);//add pwm control for speed
  else if(temp<=26)
      digitalWrite(fan,HIGH);
  else if(temp<=28)
      digitalWrite(fan,HIGH);
  else if(temp>=30)
      digitalWrite(fan,HIGH);
  }
  
    