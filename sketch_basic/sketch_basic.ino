#define ONE_SECOND 1000

#define LEFT_REAR_FORWARD 3
#define LEFT_REAR_BACKWARD 4
#define LEFT_REAR_CONTROLLER 2

#define LEFT_FRONT_FORWARD 6
#define LEFT_FRONT_BACKWARD 5 
#define LEFT_FRONT_CONTROLLER 7

#define RIGHT_FRONT_FORWARD 11
#define RIGHT_FRONT_BACKWARD 12 
#define RIGHT_FRONT_CONTROLLER 13

#define RIGHT_REAR_FORWARD 10
#define RIGHT_REAR_BACKWARD 9
#define RIGHT_REAR_CONTROLLER 8

#define RXD 7
#define TXD 8

#include <SoftwareSerial.h> // TX RX software library for bluetooth


const unsigned short bluetoothRx = 7;
const unsigned short bluetoothTx = 8;
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);

char command;

void setup() 
{ 
//    const unsigned short baud_rate = 115200;  
//    Serial.begin(115200);  
    bluetooth.begin(9600);

    pinMode(LEFT_REAR_FORWARD, OUTPUT);
    pinMode(LEFT_REAR_BACKWARD, OUTPUT);
    pinMode(LEFT_REAR_CONTROLLER, OUTPUT);
    
    pinMode(LEFT_FRONT_FORWARD, OUTPUT);
    pinMode(LEFT_FRONT_BACKWARD, OUTPUT);
    pinMode(LEFT_FRONT_CONTROLLER, OUTPUT);

    pinMode(8, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    
  
    digitalWrite(LEFT_FRONT_CONTROLLER, HIGH);
    digitalWrite(LEFT_REAR_CONTROLLER, HIGH);

    digitalWrite(RIGHT_REAR_CONTROLLER, HIGH);
    digitalWrite(RIGHT_FRONT_CONTROLLER, HIGH);
 }





void forward()
{
  digitalWrite(LEFT_FRONT_FORWARD, HIGH);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  digitalWrite(RIGHT_FRONT_FORWARD, HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  
}

void backward()
{
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD,  HIGH);
  digitalWrite(RIGHT_FRONT_BACKWARD,HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD, HIGH); 
}

void stop()
{
  digitalWrite(LEFT_FRONT_FORWARD, LOW);
  digitalWrite(LEFT_REAR_FORWARD,  LOW);
  digitalWrite(RIGHT_FRONT_FORWARD,LOW);
  digitalWrite(RIGHT_REAR_FORWARD, LOW);

  digitalWrite(LEFT_FRONT_BACKWARD, LOW);
  digitalWrite(LEFT_REAR_BACKWARD,  LOW);
  digitalWrite(RIGHT_FRONT_BACKWARD,LOW);
  digitalWrite(RIGHT_REAR_BACKWARD, LOW); 
}



void left()
{
  digitalWrite(RIGHT_FRONT_FORWARD,HIGH);
  digitalWrite(RIGHT_REAR_FORWARD, HIGH);
  
  digitalWrite(LEFT_FRONT_BACKWARD, HIGH);
  digitalWrite(LEFT_REAR_BACKWARD,  HIGH);
}


void right()
{
  digitalWrite(LEFT_FRONT_FORWARD,HIGH);
  digitalWrite(LEFT_REAR_FORWARD, HIGH);
  
  digitalWrite(RIGHT_FRONT_BACKWARD, HIGH);
  digitalWrite(RIGHT_REAR_BACKWARD,  HIGH);
}


void loop() 
{   
  if(bluetooth.available() > 0)  //Checking if there is some data available or not
  { 
    command = bluetooth.read();   //Storing the data in the 'command' variable
//    Serial.println(command);

    switch(command)
    {
      case 'F': 
      {
        forward();
        break;
      }
      default:
       backward();  
        break;
    }
  }
}  




 
