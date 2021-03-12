#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
//LiquidCrystal_I2C lcd(0x3F, 20, 4);
LiquidCrystal_I2C lcd(0x27,20, 4);
#include "RTClib.h"
RTC_DS1307 rtc;
int n;
char key;
int n4=4;
uint8_t data_pcf;
bool key_pad;
String data,smonth,sday;
int sp;
int led =13;
int serrure=12;
int alarm=11;
int buzzer=10;
int seconds,hours,minutes,months,years,days,daysOfTheWeek;
uint32_t user_password,admin_password,alarm_password;
bool last_key_pad_state, current_key_pad_state;
int k;
bool  var_alarm,var_user,var_admin,b_alrm;
void setup() {
    Serial.begin(9600);
  lcd.begin();
   Wire.begin();
   pinMode(led,OUTPUT);
     pinMode(alarm,OUTPUT);
       pinMode(serrure,OUTPUT);
        pinMode(buzzer,OUTPUT);
       digitalWrite(alarm,LOW);
       digitalWrite(led,LOW);
       digitalWrite(serrure,LOW);
         digitalWrite(buzzer,LOW);
     Wire.setClock(100000); 
        pinMode(n4,INPUT);
       key_pad=false;
       last_key_pad_state=LOW;
        var_alarm=false;
   var_user= false;
   var_admin=false;
   b_alrm=false;
    sp=0;
    EEPROM.get(0,user_password);
    EEPROM.get(200,admin_password);
      EEPROM.get(300,alarm_password);
      //--
     
  //----
  
   
//----
}
//----------------------------------------------------

void pcf_read_cap()
{
Wire.requestFrom(0x20,1);
 data_pcf=Wire.read();
  data_pcf= data_pcf&0xF0;
   if(data_pcf!=240 && b_alrm==true)
  {
        digitalWrite(alarm,HIGH);
           }
  else if(data_pcf==240|| b_alrm==false)
  {
     digitalWrite(alarm,LOW);
  }
}
//---------------------------------------------------------
void rtc_time ()
{
DateTime now = rtc.now();
hours=now.hour();
minutes=now.minute();
seconds=now.second();
days=now.day();
months=now.month();
years=now.year();
daysOfTheWeek=now.dayOfTheWeek();
switch (daysOfTheWeek)
  {
    case 0:
    sday="Dimanche";
    break;
     case 1:
    sday="Lundi";
    break;
     case 2:
    sday="Mardi";
    break;
     case 3:
    sday="Mercredi";
    break;
     case 4:
    sday="Jeudi";
    break;
     case 5:
    sday="Vendredi";
    break;
     case 6:
    sday="samedi";
    break;
  }
  switch (months)
  {
    case 1:
    smonth="Jan";
    break;
   case 2:
    smonth="Fev";
    break;
     case 3:
    smonth="Mar";
    break;
     case 4:
    smonth="Avr";
    break;
     case 5:
    smonth="Mai";
    break;
     case 6:
    smonth="Jui";
    break;
     case 7:
    smonth="Jul";
    break;
     case 8:
     smonth="Aou";
    break;
     case 9:
    smonth="Sep";
    break;
    case 10:
    smonth="Oct";
    break;
     case 11:
    smonth="Nov";
    break;
     case 12:
    smonth="Déc";
    break;
  }
  
}
 
//---
void keypad_read_pcf()
{
  Wire.requestFrom(0x20,1);//
 data_pcf=Wire.read();
  data_pcf= data_pcf&0x0F;
    switch (data_pcf)
   {
  case 1:
  key='#';
  break;
  case 2:
  key='0';
  break;
  case 3:
  key='*';
  break;
  //-----------------------------------
   case 5:
  key='9';
  break;
   case 6:
  key='8';
  break;
   case 7:
  key='7';
  break;
  //--------------------------------
  case 9:
  key='6';
  break;
  //-------
   case 10:
  key='5';
  break;
  case 11:
  key='4';
  break;
  //----------------------------------
   case 13:
  key='3';
  break;
  //----------------
  case 14:
  key='2';
  break;
  case 15:
  key='1';
  break;
  
}
}
void key_read()
{
current_key_pad_state=digitalRead(n4);
if (last_key_pad_state!=current_key_pad_state)
{
  last_key_pad_state=current_key_pad_state;
      if(current_key_pad_state==HIGH)
    {
                key_pad=true;
    }
 
}
  
} 

void loop() {

      switch(sp)
  {  
   
      case 0:
    rtc_time ();
   pcf_read_cap();
     digitalWrite(led,b_alrm);
     lcd.setCursor(0,0);
     lcd.print("enter password");
lcd.setCursor(0,2); 
lcd.print(sday);
lcd.print("/");
lcd.print(days);
lcd.print("/");
lcd.print(smonth);
lcd.print("/");
lcd.print(years);
  chek_password();
   lcd.setCursor(0,3);
   lcd.print("*: exit");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   if(var_user==true)
  {
    var_user=false;
     lcd.clear();
    delay(100);
   
sp=1;
   }   
  else if(var_alarm==true)
  {
    var_alarm=false;
lcd.clear();
delay(100);
sp=2;
  } 
 else if( var_admin==true)
  {
    var_admin=false;
     lcd.clear();
    delay(100);
   
sp=3;
   
  }    
  break;
  //-----------------------------------------
    case 1:
   lcd.setCursor(0,0);
   lcd.print("door opned");
    digitalWrite(led,LOW);
       digitalWrite(serrure,HIGH);
        digitalWrite(buzzer,HIGH);
   delay(1000);
         digitalWrite(serrure,LOW);
        digitalWrite(buzzer,LOW);
        sp=0;
   lcd.clear();
   break;
   //--------------------------------------
   case 2:
   lcd.setCursor(0,0);
   b_alrm=!b_alrm;
   if (b_alrm==true)
   {
   lcd.print("alarm  activé");
   }
   if (b_alrm==false)
   {
   lcd.print("alarm  déactivé");
   }
   delay(1000);
   lcd.clear();
     sp=0;
   break;
   //-------------------------------------
   case 3:
      adjsut_user_password();
   break;
   //--------------------------------------------
  case 4:
     adjsut_admin_password();
    break;
    //--------------------------------

    case 5:
     adjsut_alarm_password();
    break;
    case 6:
     adjsut_hours();
    break;
//--------------
  case 7:
     adjsut_minutes();
    break;
    case 8:
     adjsut_days();
    break;
     case 9:
     adjsut_months();
    break;
    case 10:
     adjsut_years();
    break;
  }
 
 }
 //--------------------------------------------------------------------
void chek_password()
{
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   
if (key=='#')
   {
      if (data.toInt()==user_password)
    {
   var_alarm=false;
   var_user= true;
   var_admin=false;
        }
  
   else if (data.toInt()==admin_password)
 
   {
   var_alarm=false;
   var_user= false;
   var_admin=true;
    
       }
   else if ( data.toInt()==1234)
 
   {
   var_alarm=false;
   var_user= false;
   var_admin=true;
  
       }
       else if (data.toInt()==alarm_password)
       {
   var_alarm=true;
   var_user= false;
   var_admin=false;
    
       }
       else 
       {
     lcd.clear();
     lcd.setCursor(0,0);
    lcd.print("error!!!");
    delay(1000);
    lcd.clear();
     var_alarm=false;
   var_user= false;
   var_admin=false;
       }
       
         k=0;
       data=' ';   
       }
     else if (key=='*')
   {
    k=0;
    data=' ';
   var_alarm=false;
   var_user= false;
   var_admin=false;
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("error!!!");
    delay(1000);
    lcd.clear();
       }
 else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print('*');
    k++;
    }
     }
     
 }
 //----------------------------------------------------
void adjsut_user_password()
{

  lcd.setCursor(0,0);
  lcd.print("ajust_user_password");
   lcd.setCursor(0,2);
   lcd.print(user_password);
   lcd.setCursor(0,3);
   lcd.print("*:next");
   lcd.setCursor(8,3);
   lcd.print("#: save");
 
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
    lcd.clear();
    k=0;
   data=' ';
     sp=4;
       
   }
  else if (key=='#')
   {
        k=0;
   user_password=data.toInt();
  EEPROM.put(0,user_password);
  lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=4;
     lcd.clear();
         }
     else 
     {
    lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
  
}
     

 //----------------------------------------------------
 void adjsut_admin_password()
{

   lcd.setCursor(0,0);
  lcd.print("ajust_admin_password");
  lcd.setCursor(0,2);
   lcd.print(admin_password);
   lcd.setCursor(0,3);
   lcd.print("*:next");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
    
    lcd.clear();
    k=0;
   data=' ';
     sp=5;
    
   }
  else if (key=='#')
   {
    lcd.clear();
    k=0;
   admin_password=data.toInt();
  EEPROM.put(200,admin_password);
     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=5;
     lcd.clear();
       }
     else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
}
//-----------
void   adjsut_alarm_password()
{

   lcd.setCursor(0,0);
  lcd.print("ajust_alarm_password");
  lcd.setCursor(0,2);
   lcd.print(alarm_password);
   lcd.setCursor(0,3);
   lcd.print("*:next");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
   lcd.clear();
    k=0;
   data=' ';
     sp=6;
    
   }
  else if (key=='#')
   {
    lcd.clear();
    k=0;
   alarm_password=data.toInt();
  EEPROM.put(300,alarm_password);
     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=6;
     lcd.clear();
       }
     else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
}
   //--
   void adjsut_hours()
{

   lcd.setCursor(0,0);
  lcd.print("ajust_HOURS");
   lcd.setCursor(0,3);
   lcd.print("*:next");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
    lcd.clear();
    k=0;
   data=' ';
   sp=7;
   }
  else if (key=='#')
   {
    lcd.clear();
    k=0;
  hours=data.toInt();
     rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=7;
     lcd.clear();
       }
     else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
}  
//---
void adjsut_minutes()
{

   lcd.setCursor(0,0);
  lcd.print("ajust_minutes");
   lcd.setCursor(0,3);
   lcd.print("*:next");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
    lcd.clear();
    k=0;
   data=' ';
   sp=8;
   }
  else if (key=='#')
   {
    lcd.clear();
    k=0;
   minutes=data.toInt();
   rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=8;
     lcd.clear();
       }
     else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
}  
 //--
 void adjsut_days()
{

   lcd.setCursor(0,0);
  lcd.print("ajust_days");
   lcd.setCursor(0,3);
   lcd.print("*:next");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
    lcd.clear();
    k=0;
   data=' ';
   sp=9;
   }
  else if (key=='#')
   {
    lcd.clear();
    k=0;
   days=data.toInt();
      rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));

     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=9;
     lcd.clear();
       }
     else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
}  
//------
void adjsut_months()
{

   lcd.setCursor(0,0);
  lcd.print("ajust_months");
   lcd.setCursor(0,3);
   lcd.print("*:next");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
    lcd.clear();
    k=0;
   data=' ';
   sp=10;
   }
  else if (key=='#')
   {
    lcd.clear();
    k=0;
   months=data.toInt();
   rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=10;
     lcd.clear();
       }
     else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
}  
//--
void adjsut_years()
{

   lcd.setCursor(0,0);
  lcd.print("ajust_years");
   lcd.setCursor(0,3);
   lcd.print("*:back");
   lcd.setCursor(8,3);
   lcd.print("#: save");
   key_read();
if(key_pad==true)
   {
   key_pad=false;
   keypad_read_pcf();
   if (key=='*')
   {
    lcd.clear();
    k=0;
   data=' ';
   sp=0;
   }
  else if (key=='#')
   {
    lcd.clear();
    k=0;
years=data.toInt();
   rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
     lcd.setCursor(0,0);
     lcd.print("data saved");
     delay(1000);
     data=' ';
     sp=0;
     lcd.clear();
       }
     else 
     {
      lcd.setCursor(k,1);
    data=data+key;
    lcd.print(key);
    k++;
    }
     }
}  

 
