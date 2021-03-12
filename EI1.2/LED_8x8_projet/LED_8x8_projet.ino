#include <LedControl.h>
#include "RTClib.h"
#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11  
RTC_DS1307 rtc;
//----------------------------
byte ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte EX[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte A[] = {60, 66, 129, 129, 255, 129, 129, 129};
byte B[] = {240, 136, 132, 136, 240, 132, 136, 240};
byte C[] = {62, 64, 128, 128, 128, 128, 64, 62};
byte D[] = {240, 136, 132, 130, 130, 132, 136, 240};
byte E[] = {60, 64, 128, 128, 252, 128, 64, 60};
byte F[] = {60, 64, 128, 128, 252, 128, 128, 128};
byte G[] = {30, 34, 196, 192, 207, 207, 34, 30};
byte H[] = {129, 129, 129, 129, 255, 129, 129, 129};
byte I[] = {124, 16, 16, 16, 16, 16, 16, 124};
byte J[] = {14, 4, 4, 4, 4, 68, 68, 56};
byte K[] = {132, 136, 144, 160, 192, 160, 144, 136};
byte L[] = {64, 64, 64, 64, 64, 64, 64, 126};
byte M[] = {66, 161, 149, 137, 129, 129, 129, 129};
byte N[] = {1, 97, 97, 145, 137, 134, 134, 128};
byte O[] = {60, 66, 129, 129, 129, 129, 66, 60};
byte P[] = {24, 100, 66, 100, 88, 64, 64, 224};
byte Q[] = {60, 66, 129, 129, 66, 60, 17, 30};
byte R[] = {120, 132, 132, 136, 240, 136, 132, 130};
byte S[] = {30, 33, 32, 32, 62, 2, 66, 62};
byte T[] = {124, 16, 16, 16, 16, 16, 16, 16};
byte U[] = {129, 129, 129, 129, 129, 129, 129, 126};
byte V[] = {129, 129, 129, 129, 129, 66, 36, 24};
byte W[] = {129, 129, 129, 129, 137, 85, 34, 0};
byte X[] = {129, 66, 36, 24, 24, 36, 66, 1290};
byte Y[] = {68, 68, 68, 68, 40, 16, 16, 16};
byte Z[] = {124, 130, 4, 8, 16, 32, 65, 62};
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
byte flech[]={0, 8, 4, 2, 252, 2, 4, 8};
byte POINTS [] {0, 24, 24, 0, 0, 24, 24, 0};
byte APP [] {0, 0, 16, 16, 32, 0, 0, 0};
byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte PRCEN[8]={0x01,0x62,0x64,0x08,0x10,0x26,0x46,0x80};
byte TC[8]={0xC0,0xCE,0x10,0x10,0x10,0x10,0x0E,0x00};
byte PT[8]={0x00,0x00,0x00,0x00,0x00,0x10,0x38,0x10};
int nowdays;
int u0,u1,u2,u3;
int hx,teta,hum;
int DIN = 12;
int CS =  10;
int CLK = 11;
int up=6;
int down=5;
int exitt=4;
int next=3;
int buzzer=A1;
int led=A2;
int adresse;
int seconds,minutes,hours,days,months,years;
byte y[8];
int nub;
int sp,sw;
uint16_t cmp;
DHT dht(DHTPIN, DHTTYPE);
LedControl lc=LedControl(DIN,CLK,CS,8);

//------------
void dht11()
{
   hum = dht.readHumidity();
   teta = dht.readTemperature();
     
}
   //--------------------
void conv_to_bcd(uint32_t val)
{
  u0=val%10;
  val=val/10;
  u1=val%10;
  val=val/10;
 u2=val%10;
  val=val/10;
 u3=val%10;
 
}


//------------------------------------------
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
     void delate_leds()
   { 
        
    printByte7(EX);
    printByte6(EX);
     printByte5(EX);
    printByte4(EX);
    printByte3(EX);
     printByte2(EX);
     printByte1(EX);
     printByte0(EX);
         
   }
   //---------------------------
void setup()
{
   Serial.begin(9600);
    dht.begin();
  pinMode(down,INPUT_PULLUP);
  pinMode(up,INPUT_PULLUP);
   pinMode(exitt,INPUT_PULLUP);
    pinMode(next,INPUT_PULLUP);
      pinMode(led,OUTPUT);
     
    for(adresse=0;adresse<8;adresse++)
  {
              lc.shutdown(adresse,false);
               lc.setIntensity(adresse,8);
                lc.clearDisplay(adresse);
    }  
    
    sp=0;
    
         
}


void affiche_date1()
     {
               //-----------------------------
           switch(nowdays)
           {
            case 0:
 printByte7(D);
 printByte6(I);
 break;
 case 1:
  printByte7(L);
 printByte6(U);
      break;   
      case 2:
  printByte7(M);
 printByte6(A);
      break;  
        case 3:
  printByte7(M);
 printByte6(E);
      break;   
        case 4:
  printByte7(J);
 printByte6(E);
      break; 
        case 5:
  printByte7(V);
 printByte6(E);
      break; 
        case 6:
  printByte7(S);
 printByte6(A);
      break;           
           }
    printByte5(POINTS);  
    //----------------------------------------     
        conv_to_bcd(days);
        trans(u1);
        printByte4(y);
        trans(u0);
        printByte3(y);
        printByte5(POINTS);
        //--------------------------------
          switch(months)
           {
            case 1:
 printByte1(J);
 printByte0(A);
 break;
 case 2:
  printByte1(F);
 printByte0(E);
      break;   
      case 3:
  printByte1(M);
 printByte0(R);
      break;  
        case 4:
  printByte4(A);
 printByte1(P);
      break;   
        case 5:
  printByte1(M);
 printByte0(Y);
      break; 
        case 6:
  printByte1(J);
 printByte0(U);
      break; 
        case 7:
  printByte1(J);
 printByte0(L);
      break;  
       case 8:
  printByte1(A);
 printByte0(O);
      break;  
       case 9:
  printByte1(S);
 printByte0(P);
      break;  
       case 10:
  printByte1(O);
 printByte0(C);
      break;  
       case 11:
  printByte1(N);
 printByte0(V);
      break;  
       case 12:
  printByte1(D);
 printByte0(C);
      break;           
           }
                        
     }
     void affiche_date2()
     {
               //-----------------------------
        conv_to_bcd(years);
        trans(u0);
        printByte0(y);
        trans(u1);
        printByte1(y);
        printByte2(POINTS);
        //------------------------------
         conv_to_bcd(months);
        trans(u0);
        printByte3(y);
        trans(u1);
        printByte4(y);
        printByte5(POINTS);
        //------------------------
        conv_to_bcd(days);
        trans(u0);
        printByte6(y);
        trans(u1);
        printByte7(y);
                  
     }
      void affiche_time()
     {
               //-----------------------------
        conv_to_bcd(seconds);
        trans(u0);
        printByte0(y);
        trans(u1);
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
void affiche_temper()
{
 printByte7(EX);
  printByte6(EX);
  printByte5(EX);
    conv_to_bcd(teta);
        trans(u1);
           printByte4(y);
        trans(u0);
        printByte3(y);
        printByte2(TC);
          printByte1(EX);
            printByte0(EX);
}
 //------------------------------
void affiche_humitide()
{
    conv_to_bcd(hum);
    printByte7(EX);
  printByte6(EX);
  printByte5(EX);
   conv_to_bcd(hum);
        trans(u1);
           printByte4(y);
        trans(u0);
        printByte3(y);
        printByte2(PRCEN);
          printByte1(EX);
            printByte0(EX);
       
}
  



//----------------------------------------

    
    void affiche_text()
{
 
        printByte7(smile);
        printByte6(E);
        printByte5(I);
        printByte4(PT);
        printByte3(UN);
         printByte2(PT);
        printByte1(DEUX);
        printByte0(smile);
         
}
 void affiche_text1()
{
 
         printByte7(smile);
        printByte6(E);
        printByte5(N);
        printByte4(I);
        printByte3(S);
         printByte2(O);
        printByte1(EX);
        printByte0(smile);
         
}
 void affiche_text2()
{
 
          printByte7(A);
        printByte6(U);
         printByte5(PT);
        printByte4(DEUX);
        printByte3(ZERO);
         printByte2(PT);
        printByte1(DEUX);
        printByte0(UN);
         
}
//---------------------------------------------
void adjust_minutes()
{
       printByte7(M);
        printByte6(U);
        printByte5(N);
        printByte4(T);
        printByte3(EX);
         printByte2(EX);
      conv_to_bcd(minutes);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
}
//----
void adjust_hours()
{
       printByte7(H);
        printByte6(O);
        printByte5(U);
        printByte4(R);
        printByte3(EX);
         printByte2(EX);
      conv_to_bcd(hours);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
}
//----
void adjust_days()
{
       printByte7(D);
        printByte6(A);
        printByte5(Y);
        printByte4(S);
        printByte3(EX);
         printByte2(EX);
      conv_to_bcd(days);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
}
//----
void adjust_months()
{
       printByte7(M);
        printByte6(O);
        printByte5(T);
        printByte4(H);
        printByte3(EX);
         printByte2(EX);
      conv_to_bcd(months);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
}
void adjust_years()
{
       printByte7(Y);
        printByte6(E);
        printByte5(A);
        printByte4(R);
        printByte3(EX);
         printByte2(EX);
      conv_to_bcd(years);
        trans(u1);
        printByte1(y);
        trans(u0);
        printByte0(y);
}
   
void loop()
{
  rtc_time ();
  dht11();
  switch (sp)
  {
   case 0:
     affiche_time();
    cmp++;
     if (cmp >10)
     {
      cmp=0;
     sp=1;
     }
    else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;
     //-----------------------------------
     case 1:
       cmp++;
     affiche_date1();
      if (cmp >10)
     {
      cmp=0;
     sp=2;
     }
     else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;
 //--------------
  case 2:
       cmp++;
     affiche_date2();
      if (cmp >10)
     {
      cmp=0;
     sp=3;
     }
     else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;
     //------------------------------
      case 3:
       cmp++;
   affiche_temper();
      if (cmp >10)
     {
      cmp=0;
     sp=4;
     }
     else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;
     //--------------------------------------
 case 4:
       cmp++;
   affiche_humitide();
      if (cmp >10)
     {
      cmp=0;
     sp=5;
     }
     else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;

//---------------------------------------
     
     case 5:
       cmp++;
  affiche_text();
      if (cmp >10)
     {
      cmp=0;
     sp=6;
     }
     else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;
//---------------------------------
 case 6:
       cmp++;
  affiche_text1();
      if (cmp >10)
     {
      cmp=0;
     sp=7;
     }
     else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;

//--
 case 7:
       cmp++;
  affiche_text2();
      if (cmp >10)
     {
      cmp=0;
     sp=0;
     }
     else if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    sp=8;
    }
     break;

     
     //---- -------------------------
     case 8:
    adjust_minutes();
   if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
    sp=9;
    }
    else if (digitalRead(next)==LOW)
    {
    while( digitalRead(next)==LOW)
    {
    }
    
    sp=9;
    }
    else if (digitalRead(up)==LOW)
    {
    while( digitalRead(up)==LOW)
    {
    }
    
   minutes++;
    }
     else if (digitalRead(down)==LOW)
    {
    while( digitalRead(down)==LOW)
    {
    }
    
   minutes--;
    }
    
        break;
        //------------------------------------------------
  case 9:
   adjust_hours();
   if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
    sp=10;
    }
    else if (digitalRead(next)==LOW)
    {
    while( digitalRead(next)==LOW)
    {
    }
    
    sp=10;
    }
    else if (digitalRead(up)==LOW)
    {
    while( digitalRead(up)==LOW)
    {
    }
    
   hours++;
    }
     else if (digitalRead(down)==LOW)
    {
    while( digitalRead(down)==LOW)
    {
    }
    
  hours--;
    }
break;
//-------------------------------------------
case 10:
 adjust_days();
   if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
    sp=11;
    }
    else if (digitalRead(next)==LOW)
    {
    while( digitalRead(next)==LOW)
    {
    }
    
    sp=11;
    }
    else if (digitalRead(up)==LOW)
    {
    while( digitalRead(up)==LOW)
    {
    }
    
 days++;
    }
     else if (digitalRead(down)==LOW)
    {
    while( digitalRead(down)==LOW)
    {
    }
    
  days--;
    }
break;
//-------------------------------------
case 11:
 adjust_months();
   if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
    sp=12;
    }
    else if (digitalRead(next)==LOW)
    {
    while( digitalRead(next)==LOW)
    {
    }
    
    sp=12;
    }
    else if (digitalRead(up)==LOW)
    {
    while( digitalRead(up)==LOW)
    {
    }
    
   months++;
    }
     else if (digitalRead(down)==LOW)
    {
    while( digitalRead(down)==LOW)
    {
    }
    
   months--;
    }

    
       break;
       //--
       case 12:
        adjust_years();
   if (digitalRead(exitt)==LOW)
    {
    while( digitalRead(exitt)==LOW)
    {
    }
    rtc.adjust(DateTime(years, months, days, hours, minutes, seconds));
    sp=0;
    }
    else if (digitalRead(next)==LOW)
    {
    while( digitalRead(next)==LOW)
    {
    }
    
    sp=0;
    }
    else if (digitalRead(up)==LOW)
    {
    while( digitalRead(up)==LOW)
    {
    }
    
   years++;
    }
     else if (digitalRead(down)==LOW)
    {
    while( digitalRead(down)==LOW)
    {
    }
    
   years--;
    } 
    break;
          }


}

  

 
//----------------------------------------------------------
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
   //------------------------------------------------------------------------------

   
   
   //------------
 
