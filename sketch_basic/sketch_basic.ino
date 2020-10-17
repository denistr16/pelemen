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



void setup() 
{ 
//  int baud_rate = 9600;  
//  Serial.begin(baud_rate);
//  

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
//forward();
//delay(ONE_SECOND*2);
//stop();
//delay(ONE_SECOND*0.5);
//backward();
//delay(ONE_SECOND);
//stop();
right();
delay(ONE_SECOND*0.5);

  
//  while (Serial.available())
//  { 
//      char in_byte = Serial.read();
//    
//      if(in_byte == 'F' )
//      {
//        car_forward_step();
//      }
//       
//      if (in_byte == 'B')
//      {
//        car_backward_step();
//      }
//         
//      if(in_byte == 'S')
//      {
//            car_full_stop();
//      }
//    
//      if(in_byte == 'L')
//      {
//        car_turn_left_90();
//      }
//  
//      if(in_byte == 'R')
//      {
//        car_turn_right_90();
//      }
//  }
}   
