// Demo with Font and icon Flash IC 
// (C) 2013 Coldtears electronics
// For use with  CTE 7.0" (800x480) LCD Module w/Font and Icon Flash IC
// in combination with CTE TFT/SD Shield for Arduino MEGA2560
// web: http://stores.shop.ebay.com/coldtears-electronics-store
//
// The first part of the demo is to show how to use the font IC to draw font to the LCD,
// The IC also include some commonly used and open source icons
// great for custom application development.
//
// Second part of the demo code is adapted from Henning Karlsen's demo
// Original by
// UTFT_Demo_800x480 (C)2012 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// This demo was made for modules with a screen resolution 
// of 800x480 pixels.
// This sketch requires the UTFT library by Henning Karlsen
// also requires the Flash_IC library by Coldtears electronics
//


#include <UTFT.h>
#include <UTFT_CTE.h>
#include "SPI.h"

extern uint8_t SmallFont[];

// Set up UTFT for CTE70 on Arduino Mega
UTFT myGLCD(CTE70,38,39,40,41);
UTFT_CTE CTE_LCD(&myGLCD);

void setup()
{
  delay(1000);
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(VGA_BLACK);
  CTE_LCD.SPI_Flash_init(FLASH_CS_PIN);
}

void loop()
{
  
  CTE_LCD.show_color_bar();
  delay(1000);
  myGLCD.clrScr();
  CTE_LCD.Load_image(0,0,287);
  myGLCD.setColor(255, 222, 111);  //Set font color
  myGLCD.setBackColor(0, 0, 0);  //Set background color
  CTE_LCD.Set_character_spacing(1); 
  CTE_LCD.Put_Text("Coldtears electronics",5,400,BVS_34);
  CTE_LCD.Put_Text("TFT LCD w/Font IC Demo",5,440,BVS_34);
  delay(1000);
  
  myGLCD.clrScr();
  CTE_LCD.Set_character_spacing(3); 
  CTE_LCD.Put_Text("Coldtears electronics",10,5,BVS_34);
  CTE_LCD.Set_character_spacing(1); 
  myGLCD.setColor(166, 256, 211);  myGLCD.setBackColor(0, 255, 0);
  CTE_LCD.Put_Text("5.0/7.0 TFT LCD Module w/Font IC Demo",10,40,BVS_22);
  myGLCD.setColor(255, 255, 255);  myGLCD.setBackColor(0, 0, 0); 
  CTE_LCD.Put_Text("123456789",10,65,BVS_15);  
  myGLCD.setColor(0, 255, 255);
  CTE_LCD.Put_Text("abcdefg",10,80,BVS_34);   
  myGLCD.setColor(255, 255, 0);
  CTE_LCD.Put_Text("hijklmnopgrstu",10,115,BVS_43);
  myGLCD.setColor(122, 122, 122);
  CTE_LCD.Put_Text("12345789",10,165,BVS_52);
  myGLCD.setColor(122,255, 255);
  CTE_LCD.Put_Text("!@#$%^&*()",10,217,BVS_52);   
  myGLCD.setColor(255,0, 255);
  CTE_LCD.Put_Text("ABCDEFGHIJKLMNO",10,269,BVS_74);  
  myGLCD.setColor(255,255, 255); 
  CTE_LCD.Put_Text("PQRSTUVWXYZ",10,343,BVS_112); 
  
  delay(1000);
  
  myGLCD.clrScr();   
  myGLCD.setColor(255, 255, 255);
  static char buff[33];
  for(unsigned char temp=32; temp<65; temp++)  { buff[temp-32]=temp; }  buff[33]=0;
   CTE_LCD.Put_Text_array(buff,0,0,BVS_52);
  for(unsigned char temp=65; temp<92; temp++)  { buff[temp-65]=temp; }  buff[27]=0;
  CTE_LCD.Put_Text_array(buff,0,60,BVS_52); 
  for(unsigned char temp=92; temp<127; temp++)  { buff[temp-92]=temp; }  buff[33]=0;
  CTE_LCD.Put_Text_array(buff,0,120,BVS_52); 
  for(unsigned char temp=127; temp<154; temp++)  { buff[temp-127]=temp; }  buff[27]=0;
  CTE_LCD.Put_Text_array(buff,0,180,BVS_52);   
  for(unsigned char temp=154; temp<181; temp++)  { buff[temp-154]=temp; }  buff[27]=0;
  CTE_LCD.Put_Text_array(buff,0,240,BVS_52); 
   for(unsigned char temp=181; temp<204; temp++)  { buff[temp-181]=temp; }  buff[23]=0;
  CTE_LCD.Put_Text_array(buff,0,300,BVS_52);   
  for(unsigned char temp=204; temp<227; temp++)  { buff[temp-204]=temp; }  buff[23]=0;
  CTE_LCD.Put_Text_array(buff,0,360,BVS_52); 
   for(unsigned char temp=227; temp<255; temp++)  { buff[temp-227]=temp; }  buff[27]=0;
  CTE_LCD.Put_Text_array(buff,0,420,BVS_52);  
  delay(1000);
  
  
unsigned int k=2,location=1;
while(k>0)
{ 
  myGLCD.clrScr(); 
  for (unsigned temp1 =0; temp1<11; temp1++)
  {
    for (unsigned temp2 =0; temp2<18; temp2++)
    {
      CTE_LCD.Load_image(temp2*44,temp1*44,location); 
      location++; 
      if(location==236) break;
    }
  if(location==236) break; 
  }
  delay(1000);
  k--;
}

myGLCD.clrScr();
CTE_LCD.Put_Text("Countdown for LCD Display",0,0,BVS_74);
CTE_LCD.Put_Text("Demo by Henning Karlsen",0,75,BVS_74);
myGLCD.setColor(150, 222, 255);
k=50;
while(k>0)
{  
  k--;
  String test_string = String(k);
  test_string = "000"+ test_string + "       "; 
  CTE_LCD.Put_Text(test_string,200,210,BVS_112);
  int temp;
  if (k%3==2) temp=275;  else if (k%3==1) temp=277;  else temp=279;
  CTE_LCD.Load_image(50,400,temp); CTE_LCD.Load_image(150,400,temp+6);
  delay(100);
}




int buf[798];
  int x, x2;
  int y, y2;
  int r;

// Clear the screen and draw the frame
  myGLCD.clrScr();

  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(0, 0, 799, 13);
  myGLCD.setColor(64, 64, 64);
  myGLCD.fillRect(0, 466, 799, 479);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("* Universal Color TFT Display Library *", CENTER, 1);
  myGLCD.setBackColor(64, 64, 64);
  myGLCD.setColor(255,255,0);
  myGLCD.print("<http://electronics.henningkarlsen.com>", CENTER, 467);

  myGLCD.setColor(0, 0, 255);
  myGLCD.drawRect(0, 14, 799, 465);

// Draw crosshairs
  myGLCD.setColor(0, 0, 255);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.drawLine(399, 15, 399, 464);
  myGLCD.drawLine(1, 239, 798, 239);
  for (int i=9; i<790; i+=10)
    myGLCD.drawLine(i, 237, i, 242);
  for (int i=19; i<470; i+=10)
    myGLCD.drawLine(397, i, 402, i);

// Draw sin-, cos- and tan-lines  
  myGLCD.setColor(0,255,255);
  myGLCD.print("Sin", 5, 15);
  for (int i=1; i<798; i++)
  {
    myGLCD.drawPixel(i,239+(sin(((i*1.13)*3.14)/180)*200));
  }
  
  myGLCD.setColor(255,0,0);
  myGLCD.print("Cos", 5, 27);
  for (int i=1; i<798; i++)
  {
    myGLCD.drawPixel(i,239+(cos(((i*1.13)*3.14)/180)*200));
  }

  myGLCD.setColor(255,255,0);
  myGLCD.print("Tan", 5, 39);
  for (int i=1; i<798; i++)
  {
    myGLCD.drawPixel(i,239+(tan(((i*0.9)*3.14)/180)));
  }

  delay(2000);

  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);
  myGLCD.setColor(0, 0, 255);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.drawLine(399, 15, 399, 464);
  myGLCD.drawLine(1, 239, 798, 239);

// Draw a moving sinewave
  x=1;
  for (int i=1; i<(798*20); i++) 
  {
    x++;
    if (x==799)
      x=1;
    if (i>799)
    {
      if ((x==399)||(buf[x-1]==239))
        myGLCD.setColor(0,0,255);
      else
        myGLCD.setColor(0,0,0);
      myGLCD.drawPixel(x,buf[x-1]);
    }
    myGLCD.setColor(0,255,255);
    y=239+(sin(((i*1.65)*3.14)/180)*(200-(i / 100)));
    myGLCD.drawPixel(x,y);
    buf[x-1]=y;
  }

  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

// Draw some random filled rectangles
  for (int i=0; i<50; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(746);
    y=16+random(397);
    x2=x+50;
    y2=y+50;
    myGLCD.fillRect(x, y, x2, y2);
  }

  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

// Draw some random filled, rounded rectangles
  for (int i=0; i<50; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(746);
    y=16+random(397);
    x2=x+50;
    y2=y+50;
    myGLCD.fillRoundRect(x, y, x2, y2);
  }
  
  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

// Draw some random filled circles
  for (int i=0; i<50; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=27+random(746);
    y=41+random(397);
    myGLCD.fillCircle(x, y, 25);
  }
  
  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

// Draw some lines in a pattern
  myGLCD.setColor (255,0,0);
  for (int i=15; i<463; i+=5)
  {
    myGLCD.drawLine(1, i, (i*1.66)-10, 463);
  }
  myGLCD.setColor (255,0,0);
  for (int i=463; i>15; i-=5)
  {
    myGLCD.drawLine(798, i, (i*1.66)+30, 15);
  }
  myGLCD.setColor (0,255,255);
  for (int i=463; i>15; i-=5)
  {
    myGLCD.drawLine(1, i, 770-(i*1.66), 15);
  }
  myGLCD.setColor (0,255,255);
  for (int i=15; i<463; i+=5)
  {
    myGLCD.drawLine(798, i, 810-(i*1.66), 463);
  }
  
  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

// Draw some random circles
  for (int i=0; i<250; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=32+random(736);
    y=45+random(386);
    r=random(30);
    myGLCD.drawCircle(x, y, r);
  }

  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

// Draw some random rectangles
  for (int i=0; i<250; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(796);
    y=16+random(447);
    x2=2+random(796);
    y2=16+random(447);
    myGLCD.drawRect(x, y, x2, y2);
  }

  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

// Draw some random rounded rectangles
  for (int i=0; i<250; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(796);
    y=16+random(447);
    x2=2+random(796);
    y2=16+random(447);
    myGLCD.drawRoundRect(x, y, x2, y2);
  }

  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

  for (int i=0; i<250; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(796);
    y=16+random(447);
    x2=2+random(796);
    y2=16+random(447);
    myGLCD.drawLine(x, y, x2, y2);
  }

  delay(2000);
  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,464);

  for (int i=0; i<10000; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.drawPixel(2+random(796), 16+random(447));
  }

  delay(2000);

  myGLCD.fillScr(0, 0, 255);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(320, 190, 479, 289);
  
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("That's it!", CENTER, 213);
  myGLCD.print("Restarting in a", CENTER, 239);
  myGLCD.print("few seconds...", CENTER, 252);
  
  myGLCD.setColor(0, 255, 0);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("Runtime: (msecs)", CENTER, 450);
  myGLCD.printNumI(millis(), CENTER, 465);
  
  delay (10000);
}
