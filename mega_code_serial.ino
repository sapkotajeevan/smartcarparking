#include "LiquidCrystal.h"
#include <Keypad.h>
#include <Wire.h>

// initialize the library by providing the nuber of pins to it
LiquidCrystal lcd(14,15,16,17,18,19);

char statkey; char pkey1;  char pkey2;  char pkey3; 
char upkey1;  char upkey2;  char upkey3;
char parray1[5];  char parray2[5];
char uparray1[5];  char uparray2[5];
int count=0;  
char customKey;
int led1=52;
int led2=53;
int rled1=0;
int rled2=0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads

char hexaKeys[ROWS][COLS] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};

byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 5, 4, 3}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void resetcount()
{
  count=0;
}
void start()
{
    lcd.setCursor(0,0);
    lcd.print("Press any one:  ");
    Serial.println("Press any one:  ");

    lcd.setCursor(0,1);
    lcd.print("Park=A Unpark=B ");
    Serial.println("Park=A Unpark=B ");
    
    customKey=customKeypad.getKey();
    Serial.println(customKey);
    switch(customKey)
    {
      case NO_KEY:
      start();
      break;
      
      case '0': case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9': case 'C': case 'D':
      case '*': case '#':
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sorry! Try Again");
      Serial.println("Sorry! Try Again");
      delay(1000);
      start();
      break;
      
      case 'A':
      park();
      break;
      
      case 'B':
      unpark();
      break;
    }
    

}

void park()
{
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Station 1 or 2?");
    Serial.println("Station 1 or 2?");
    lcd.setCursor(0,1);
    lcd.print("Park to:");
    Serial.println("Park to:");
    do{
      statkey=customKeypad.getKey();
    }while(statkey == NO_KEY);
    lcd.setCursor(9,1);
    lcd.print(statkey);
    Serial.println(statkey);
    delay(1000);
    switch(statkey)
    {
      case '1':
              if(rled1==HIGH)
              {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Parking lot");
                Serial.println("Parking lot");
                lcd.setCursor(0,1);
                lcd.print("Occupied");
                Serial.println("Occupied");
                delay(1000);
                start();
              }
              
              lcd.clear(); 
              lcd.setCursor(0,0);
              lcd.print("Press your code ");
              Serial.println("Press your code ");
              do{
                  pkey1=customKeypad.getKey();   
                 }while(pkey1 == NO_KEY);
    
              parray1[0]=pkey1;
              lcd.setCursor(0,1);
              lcd.print(pkey1);
              Serial.println(pkey1);
              delay(1000);
    
              do{
                  pkey2=customKeypad.getKey();   
                  }while(pkey2 == NO_KEY);
    
               parray1[1]=pkey2;
               lcd.setCursor(1,1);
               lcd.print(pkey2);
               Serial.println(pkey2);
               delay(1000);

              do{
                 pkey3=customKeypad.getKey();   
                 }while(pkey3 == NO_KEY);
     
              parray1[2]=pkey3;
              lcd.setCursor(2,1);
              lcd.print(pkey3);
              Serial.println(pkey3);
              delay(1000);
  
              lcd.clear();
              lcd.setCursor(0,0);
              digitalWrite(led1,HIGH);
              rled1=digitalRead(led1);
              lcd.print("Thank you for   ");
              Serial.println("Thank you for   ");
              lcd.setCursor(0,1);
              lcd.print("Registering     ");
              Serial.println("Registering     ");
              delay(3000);
              
              //Motor code to park in lower station
              Wire.begin();
              Wire.beginTransmission(5);
              Wire.write('A');
              Wire.endTransmission();
              
              start(); 
              break;    
      
      
      case '2':
              if(rled2==HIGH)
              {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Parking lot");
                lcd.setCursor(0,1);
                lcd.print("Unavailable");
                Serial.println("Parking lot occupied");
                delay(1000);
                start();
              }
              
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Press your code ");
              Serial.println("Press your code ");
               do{
                  pkey1=customKeypad.getKey();   
                 }while(pkey1 == NO_KEY);
    
              parray2[0]=pkey1;
              lcd.setCursor(0,1);
              lcd.print(pkey1);
              Serial.println(pkey1);
              delay(1000);
    
              do{
                pkey2=customKeypad.getKey();   
                }while(pkey2 == NO_KEY);
    
             parray2[1]=pkey2;
             lcd.setCursor(1,1);
             lcd.print(pkey2);
             Serial.println(pkey2);
             delay(1000);

            do{
               pkey3=customKeypad.getKey();   
              }while(pkey3 == NO_KEY);
     
             parray2[2]=pkey3;
             lcd.setCursor(2,1);
             lcd.print(pkey3);
             Serial.println(pkey3);
             delay(1000);
  
            lcd.clear();
            lcd.setCursor(0,0);
            digitalWrite(led2,HIGH);
            rled2=digitalRead(led2);
            lcd.print("Thank you for   ");
            lcd.setCursor(0,1);
            lcd.print("Registering     ");
            Serial.println("Thank you for registering");
            delay(3000);
            
            //Motor code to park in lower station
              Wire.begin();
              Wire.beginTransmission(5);
              Wire.write('B');
              Wire.endTransmission();
            
            start();
            break;
           
      case 'A': case 'B': case '0': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9': case 'C': case 'D':
      case '*': case '#':
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sorry! Try Again");
      Serial.println("Sorry! Try Again");
      delay(1000);
      start();
      break;
       
    }
}

void unpark()
{
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Station 1 or 2?");
    Serial.println("Station 1 or 2?");
    lcd.setCursor(0,1);
    lcd.print("Unpark from:");
    Serial.println("Unpark from:");
    do{
      statkey=customKeypad.getKey();
    }while(statkey == NO_KEY);
    lcd.setCursor(13,1);
    lcd.print(statkey);
    Serial.println(statkey);
    delay(1000);
    switch(statkey)
    {
      case'1':
              if(rled1==LOW)
              {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Parking lot");
                lcd.setCursor(0,1);
                lcd.print("Vacant");
                Serial.println("Parking lot Vacant");
                delay(1000);
                start();
              }
             
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Press your code ");
             Serial.println("Press your code ");
             do{
                upkey1=customKeypad.getKey();   
               }while(upkey1 == NO_KEY);
    
             uparray1[0]=upkey1;
             lcd.setCursor(0,1);
             lcd.print(upkey1);
             Serial.println(upkey1);
             delay(1000);
    
              do{
                 upkey2=customKeypad.getKey();   
                 }while(upkey2 == NO_KEY);
    
              uparray1[1]=upkey2;
              lcd.setCursor(1,1);
              lcd.print(upkey2);
              Serial.println(upkey2);
              delay(1000);

              do{
                 upkey3=customKeypad.getKey();   
                 }while(upkey3 == NO_KEY);
    
              uparray1[2]=upkey3;
              lcd.setCursor(2,1);
              lcd.print(upkey3);
              Serial.println(upkey3);
              delay(1000);

     
             for(int i=0;i<3;i++)
           {
               if(parray1[i]==uparray1[i])
                 {
                    count++;
                 }
           }
             if(count==3)
           {
                 lcd.clear();
                 lcd.setCursor(0,0);
                 digitalWrite(led1,LOW);
                 rled1=digitalRead(led1);
                 lcd.print("     Matched    ");   
                 lcd.setCursor(0,1);
                 lcd.print("Retrieving car!!");
                 Serial.println("Matched ! Retrieving Car!!");
                 delay(2000);
                 
                 //Motor code to unpark in lower station
                  Wire.begin();
                  Wire.beginTransmission(5);
                  Wire.write('C');
                  Wire.endTransmission();
                 
                 resetcount();
                 start();
           }
               else
           {
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print("       Error!!  ");
                 lcd.setCursor(0,1);
                 lcd.print("Please try again");
                 Serial.println("Please try again");
                 delay(1000);
                 start();
            }
             break;
             
      case'2':
              if(rled2==LOW)
              {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("Parking lot");
                Serial.println("Parking lot");
                lcd.setCursor(0,1);
                lcd.print("Vacant");
                Serial.println("Vacant");
                delay(1000);
                start();
              }
             
             lcd.clear();
             lcd.setCursor(0,0);
             lcd.print("Press your code ");
             Serial.println("Press your code ");
             do{
                upkey1=customKeypad.getKey();   
               }while(upkey1 == NO_KEY);
    
             uparray2[0]=upkey1;
             lcd.setCursor(0,1);
             lcd.print(upkey1);
             Serial.println(upkey1);
             delay(1000);
    
              do{
                 upkey2=customKeypad.getKey();   
                 }while(upkey2 == NO_KEY);
    
              uparray2[1]=upkey2;
              lcd.setCursor(1,1);
              lcd.print(upkey2);
              Serial.println(upkey2);
              delay(1000);

              do{
                 upkey3=customKeypad.getKey();   
                 }while(upkey3 == NO_KEY);
    
              uparray2[2]=upkey3;
              lcd.setCursor(2,1);
              lcd.print(upkey3);
              Serial.println(upkey3);
              delay(1000);

     
             for(int i=0;i<3;i++)
           {
               if(parray2[i]==uparray2[i])
                 {
                    count++;
                 }
           }
             if(count==3)
           {
                 lcd.clear();
                 lcd.setCursor(0,0);
                 digitalWrite(led2,LOW);
                 rled2=digitalRead(led2);
                 lcd.print("     Matched    ");   
                 lcd.setCursor(0,1);
                 lcd.print("Retrieving car!!");
                 Serial.println("Matched!! Retrieving car!");
                 delay(2000);
                 
                 //Motor code to unpark in upper station
                  Wire.begin();
                  Wire.beginTransmission(5);
                  Wire.write('D');
                  Wire.endTransmission();
              
                 resetcount();
                 start();
           }
               else
           {
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print("       Error!!  ");
                 lcd.setCursor(0,1);
                 lcd.print("Please try again");
                 Serial.println("Please try again");
                 delay(1000);
                 resetcount();
                 start();
            }
             break;
      case 'A': case 'B': case '0': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9': case 'C': case 'D':
      case '*': case '#':
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sorry! Try Again");
      Serial.println("Sorry! Try Again");
      delay(1000);
      start();
      break;
    }
   
 }
    
void setup()
{
    Serial.begin(9600);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(rled1,INPUT);
    pinMode(rled2,INPUT);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    lcd.begin(16,2);
     lcd.setCursor(0,0);
    lcd.print("   SMART  CAR");
    Serial.println("SMART CAR PARKING PROJECT");
    lcd.setCursor(0,1);
    lcd.print("PARKING PROJECT");
    delay(4000);
    lcd.clear();
    start();
}

void loop()
{
   
}

