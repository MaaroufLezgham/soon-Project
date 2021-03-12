#include <LedControl.h>
#include "RTClib.h"
RTC_DS1307 rtc;
//------------------
byte M[] = {66, 161, 149, 137, 129, 129, 129, 129};
byte N[] = {1, 97, 97, 145, 137, 134, 134, 128};
byte O[] = {60, 66, 129, 129, 129, 129, 66, 60};
byte R[] = {120, 132, 132, 136, 240, 136, 132, 130};
byte U[] = {129, 129, 129, 129, 129, 129, 129, 126};
byte F[] = {60, 64, 128, 128, 252, 128, 128, 128};
byte T[] = {124, 16, 16, 16, 16, 16, 16, 16};
byte H[] = {129, 129, 129, 129, 255, 129, 129, 129};
//-------------------------------------------------------------
byte ZERO[] = {60, 66, 70, 74, 82, 98, 66, 60};
byte UN[] = {24, 40, 72, 8, 8, 8, 8, 28};
byte DEUX[] = {124, 2, 2, 60, 60, 64, 64, 62};
byte TROIS[] = {60, 2, 2, 60, 60, 2, 2, 62};
byte QUATRE[] = {64, 66, 66, 66, 60, 2, 2, 2};
byte CINQ[] = {60, 64, 64, 64, 60, 2, 2, 124};
byte SIX[] = {60, 64, 64, 64, 60, 66, 66, 60};
byte SEPT[] = {112, 136, 8, 8, 28, 8, 8, 8};
byte HUIT[] = {60, 66, 66, 60, 60, 66, 66, 60};
byte NEUF[] = {60, 66, 66, 66, 62, 2, 2, 62};
//--------------------------------------------------------------------
byte ZEROS[] = {0x00,0x00,0x00,0x1C,0x22,0x22,0x22,0x1C};
byte UNS[] = {0x00,0x00,0x00,0x08,0x18,0x08,0x08,0x1C};
byte DEUXS[] = {0x00,0x00,0x00,0x38,0x08,0x38,0x20,0x38};
byte TROISS[] = {0x00,0x00,0x00,0x38,0x08,0x38,0x08,0x38};
byte QUATRES[] = {0x00,0x00,0x00,0x10,0x10,0x14,0x1C,0x04};
byte CINQS[] = {0x00,0x00,0x00,0x38,0x20,0x38,0x08,0x38};
byte SIXS[] = {0x00,0x00,0x00,0x38,0x20,0x38,0x28,0x38};
byte SEPTS[] = {0x00,0x00,0x00,0x38,0x08,0x1C,0x08,0x08};
byte HUITS[] = {0x00,0x00,0x00,0x38,0x28,0x38,0x28,0x38};
byte NEUFS[] = {0x00,0x00,0x00,0x38,0x28,0x38,0x08,0x38};
byte POINTS [] {0, 24, 24, 0, 0, 24, 24, 0};
//---------------------------------------------
int nowdays;
int u0,u1;
int DIN = 12;
int CLK =  11;
int CS = 10;
int up=6;
int down=5;
int exitt=4;
int buzzer=9;
int button =13;
int adresse;
float z;
int sp;
int ph,pm,ps;
uint32_t s,pr,sref;
byte y[8];
LedControl lc=LedControl(DIN,CLK,CS,8);
int seconds,minutes,hours,days,months,years,last_seconds;
int minutref,houref;

void setup() {
  Serial.begin(9600);
   pinMode(button,INPUT_PULLUP);
   pinMode(exitt,INPUT_PULLUP);
       pinMode(up,INPUT_PULLUP);
         pinMode(down,INPUT_PULLUP);
          pinMode(buzzer,OUTPUT);
          for(int adder=0;adder<8; adder++)
  {
   lc.shutdown(adder,false);
   lc.setIntensity(adder,8);
   lc.clearDisplay(adder);
  }
        sp=0;
      minutref=30;
    houref=1;
}


void trans2(byte(n))
{
   switch(n)
  {
  case 0:
  for(int i=0;i<8;i++)
  y[i]=ZEROS[i];
  break;
  case 1:
  for(int i=0;i<8;i++)
  y[i]=UNS[i];
  break;
  case 2:
  for(int i=0;i<8;i++)
    y[i]=DEUXS[i];
  break;
  case 3:
  for(int i=0;i<8;i++)
   y[i]=TROISS[i];
  break;
  case 4:
  for(int i=0;i<8;i++)
   y[i]=QUATRES[i];
  break;
  case 5:
  for(int i=0;i<8;i++)
   y[i]=CINQS[i];
  break;
  case 6:
  for(int i=0;i<8;i++)
    y[i]=SIXS[i];
  break;
  case 7:
  for(int i=0;i<8;i++)
   y[i]=SEPTS[i];
   break;
   case 8:
   for(int i=0;i<8;i++)
    y[i]=HUITS[i];
  break;
  case 9:
  for(int i=0;i<8;i++)
   y[i]=NEUFS[i];
    break;
  }
}
//--------
void trans(byte(n))
{
   switch(n)
  {
  case 0:
  for(int i=0;i<8;i++)
  y[i]=ZERO[i];
  break;
  case 1:
  for(int i=0;i<8;i++)
  y[i]=UN[i];
  break;
  case 2:
  for(int i=0;i<8;i++)
    y[i]=DEUX[i];
  break;
  case 3:
  for(int i=0;i<8;i++)
   y[i]=TROIS[i];
  break;
  case 4:
  for(int i=0;i<8;i++)
   y[i]=QUATRE[i];
  break;
  case 5:
  for(int i=0;i<8;i++)
   y[i]=CINQ[i];
  break;
  case 6:
  for(int i=0;i<8;i++)
    y[i]=SIX[i];
  break;
  case 7:
  for(int i=0;i<8;i++)
   y[i]=SEPT[i];
   break;
   case 8:
   for(int i=0;i<8;i++)
    y[i]=HUIT[i];
  break;
  case 9:
  for(int i=0;i<8;i++)
   y[i]=NEUF[i];
    break;
  }
}
//------------
void conv_to_bcd(int val)
{
  u0=val%10;
  val=val/10;
  u1=val%10;
   }

//--------------------------------------------------
void  rtc_time ()
{
    DateTime now = rtc.now();
    hours=now.hour();
    minutes=now.minute();
    seconds=now.second();
    days=now.day();
    months=now.month();
    years=now.year();
    nowdays=now.dayOfTheWeek();
       
        
}
//----------------------------------

 void affiche_time()
     {

         //-----------------------------
        conv_to_bcd(seconds);
        trans2(u0);
        printByte0(y);
        trans2(u1);
        printByte1(y);
        printByte2(POINTS);
        //------------------------------
         conv_to_bcd(minutes);
        trans(u0);
        printByte3(y);
        trans(u1);
        printByte4(y);
        printByte5(POINTS);
        //------------------------
        conv_to_bcd(hours);
        trans(u0);
        printByte6(y);
        trans(u1);
        printByte7(y);
             
    
     }



void loop()
{
   rtc_time ();
  switch(sp)
  {
    case 0:
     
    affiche_time();

        if (digitalRead(button)==LOW)
    {
      digitalWrite(buzzer,HIGH);
       while (digitalRead(button)==LOW)
       {
        }
      digitalWrite(buzzer,LOW);
        sp=1;
    }
    else if (digitalRead(exitt)==LOW)
    {
       digitalWrite(buzzer,HIGH);
       while (digitalRead(exitt)==LOW)
       {
        }
      digitalWrite(buzzer,LOW);
        sp=3;
    }
  
    break;
    //-------------------------------------------------------
    case 1:
    houref=houref+hours;
    minutref=minutref+minutes;
    sref=houref*3600+minutref*60+seconds;
     sp=2;
    break;
    //-----------------------------------------------------
    case 2:
    aff_time2();
    if (s==0)
    {
    digitalWrite(buzzer,LOW);
    sp=0;
    }
    else if (digitalRead(button)==LOW)
    {
      digitalWrite(buzzer,HIGH);
       while (digitalRead(button)==LOW)
       {
               }
      digitalWrite(buzzer,LOW);
        sp=0;
    }
    break;
    //------------------------------------
    case 3:
        printByte7(M);
        printByte6(U);
        printByte5(N);
        printByte4(T);
        printByte3(POINTS);
        //------------------------------
         conv_to_bcd(minutes);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
        //------------------------
          
 conv_to_bcd(minutes);
 
     if (digitalRead(up)==LOW)
    {
        while (digitalRead(up)==LOW)
       {
        
       }
   minutes++;
    rtc.adjust(DateTime(years, months, days, hours, minutes, 0));
}
  else if (digitalRead(down)==LOW)
    {
        while (digitalRead(down)==LOW)
       {
        
       }
   minutes--;
    rtc.adjust(DateTime(years, months, days, hours, minutes, 0));
}
 else if (digitalRead(exitt)==LOW)
    {
        while (digitalRead(exitt)==LOW)
       {
        
       }
   
    sp=4;
    
}
break;
//----------------------------------------------------------
 case 4:
       printByte7(H);
        printByte6(O);
        printByte5(U);
        printByte4(R);
        printByte3(POINTS);
        //------------------------------
         conv_to_bcd(hours);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
        //------------------------
      if (digitalRead(up)==LOW)
    {
        while (digitalRead(up)==LOW)
       {
        
       }
   hours++;
    rtc.adjust(DateTime(years, months, days, hours, minutes, 0));
}
  else if (digitalRead(down)==LOW)
    {
        while (digitalRead(down)==LOW)
       {
        
       }
   hours--;
    rtc.adjust(DateTime(years, months, days, hours, minutes, 0));
}
 else if (digitalRead(exitt)==LOW)
    {
        while (digitalRead(exitt)==LOW)
       {
        
       }
   
    sp=5;
    
}
break;
//----------------------------------------------------------
case 5:
conv_to_bcd(minutref);
       printByte7(R);
        printByte6(F);
        printByte5(M);
        printByte4(U);
        printByte3(POINTS);
        //------------------------------
         conv_to_bcd(minutref);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
        //------------------------
  
     if (digitalRead(up)==LOW)
    {
        while (digitalRead(up)==LOW)
       {
        
       }
   minutref++;
}
  else if (digitalRead(down)==LOW)
    {
        while (digitalRead(down)==LOW)
       {
        
       }
   minutref--;
}

else if (digitalRead(exitt)==LOW)
    {
        while (digitalRead(exitt)==LOW)
       {
        
       }
    
    sp=6;
    }

break;
//---------------------------------------
case 6:
conv_to_bcd(houref);
  printByte7(R);
        printByte6(F);
        printByte5(H);
        printByte4(O);
        printByte3(POINTS);
        //------------------------------
         conv_to_bcd(houref);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
        //------------------------
  
     if (digitalRead(up)==LOW)
    {
        while (digitalRead(up)==LOW)
       {
        
       }
houref++;
}
  else if (digitalRead(down)==LOW)
    {
        while (digitalRead(down)==LOW)
       {
        
       }
  houref--;
}

else if (digitalRead(exitt)==LOW)
    {
        while (digitalRead(exitt)==LOW)
       {
        
       }
    
    sp=0;
    }

break;
  }
}





void aff_time2()
{

     s=sref- (hours*3600+minutes*60+seconds);
 
  z=s/3600.0;
    z=z-0.5;
  ph=round(z);
   //------------------------------------------
 pr=s-ph*3600;
    z=pr/60.0;
  z=z-0.5;
  pm=round(z);
 //-------------
 if (s<60)
 {
  digitalWrite(buzzer,!digitalRead(buzzer));
 }
 //----------------
 ps=s-((ph*3600)+(pm*60));
conv_to_bcd(ps);
        trans2(u0);
        printByte0(y);
        trans2(u1);
        printByte1(y);
        printByte2(POINTS);
 conv_to_bcd(pm);
  trans(u0);
        printByte3(y);
        trans(u1);
        printByte4(y);
        printByte5(POINTS);
  conv_to_bcd(ph);
   trans(u0);
        printByte6(y);
        trans(u1);
        printByte7(y);
  

  
}
//--
void printByte0(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
   }

//--------------------------------------------
void printByte1(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(1,i,character[i]);
  }
   }
   //-----------------------------------------------------
   void printByte2(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(2,i,character[i]);
  }
   }
   //--------------
   void printByte3(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(3,i,character[i]);
  }
   }
   //--------------
   void printByte4(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(4,i,character[i]);
  }
   }
   //------
    void printByte5(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(5,i,character[i]);
  }
   }
   //---
    void printByte6(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(6,i,character[i]);
  }
   }
   //--
    void printByte7(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(7,i,character[i]);
  }
   }
   void printByte8(byte character [])
{
  int i = 0;
  
  for(i=0;i<8;i++)
  {
    lc.setRow(8,i,character[i]);
  }
   }
