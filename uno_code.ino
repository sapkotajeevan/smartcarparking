#include<Wire.h>
#define EN        8  
#define X_DIR     5 
#define Y_DIR     6
#define X_STP     2
#define Y_STP     3 
int delayTime=500; //Delay between each pause (uS)
int stps=200;// Steps to move
int value;

void setup()
{
    pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
    pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
    pinMode(EN, OUTPUT);
    Wire.begin(5);
    Wire.onReceive(receiveEvent);
    
}

void loop()
{}

void step(boolean dir, byte dirPin, byte stepperPin, int steps)

{

  digitalWrite(dirPin, dir);

  delay(100);

  for (int i = 0; i < steps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(delayTime); 

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(delayTime); 

  }

}

void receiveEvent(int bytes)
{
    while(Wire.available())
    {
     char c= Wire.read();
     //Lower station no:1   //Upper station no:2 //true:both outward  //false:both inward
       if(c=='A')//park1
        { 
          
          for(int j=0;j<3;j++)
            {
               step(true, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
            }
          for(int j=0;j<18;j++)
            {
               step(true, X_DIR, X_STP, stps); //X, Clockwise 
               delay(400);
            }
          for(int j=0;j<3;j++)
            {
               step(false, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
            }
            for(int j=0;j<18;j++)
            {
               step(false, X_DIR, X_STP, stps); //X, Clockwise 
               delay(400);
            }
        }
            
            else if(c=='B')//park2
         { 
          
              for(int j=0;j<35;j++)
           {
               step(true, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
           }
            
              for(int j=0;j<18;j++)
           {
               step(true, X_DIR, X_STP, stps); //X, Clockwise //tala gayo
               delay(400);
           }
             for(int j=0;j<3;j++)
           {
               step(false, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
           }
            for(int j=0;j<18;j++)
           {
               step(false, X_DIR, X_STP, stps); //X, Clockwise //tala gayo
               delay(400);
           }
            for(int j=0;j<32;j++)
           {
               step(false, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
           }
            
         }   
            
            
            
            else if(c=='C')//unpark1
        {
            
           for(int j=0;j<18;j++)
             {
               step(true, X_DIR, X_STP, stps); //X, Clockwise //tala gayo
               delay(400);
             }
           for(int j=0;j<4;j++)
             {
               step(true, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
             }
           for(int j=0;j<18;j++)
             {
               step(false, X_DIR, X_STP, stps); //X, Clockwise //tala gayo
               delay(400);
             }
           for(int j=0;j<4;j++)
             {
               step(false, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
             }
             
             }
            else if(c=='D')//unpark1
        { 
          
          for(int j=0;j<30;j++)
            {
               step(true, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
            }
          for(int j=0;j<18;j++)
            {
               step(true, X_DIR, X_STP, stps); //X, Clockwise 
               delay(400);
            }
          for(int j=0;j<6;j++)
            {
               step(true, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
            }
            for(int j=0;j<18;j++)
            {
               step(false, X_DIR, X_STP, stps); //X, Clockwise 
               delay(400);
            }
            for(int j=0;j<35;j++)
            {
               step(false, Y_DIR, Y_STP, stps); //X, Clockwise //tala gayo
               delay(400);
            }
            
        }
             
           }
            
 }

