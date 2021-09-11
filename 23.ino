int state;
int flag=0;


int LeftMotorForward = 9;
int LeftMotorReverse = 8; 

int LeftMotor2Forward = 5;
int LeftMotor2Reverse = 4; 

int RightMotorForward = 7;
int RightMotorReverse = 6; 


int RightMotor2Forward = 3;
int RightMotor2Reverse = 2; 

int BrushMotorForward = 10;
int BrushMotorReverse = 11;



  
void setup()
{

  
  pinMode(RightMotorForward, OUTPUT);  
  pinMode(RightMotorReverse, OUTPUT);  
  pinMode(LeftMotorForward, OUTPUT);  
  pinMode(LeftMotorReverse, OUTPUT);  

  pinMode(RightMotor2Forward, OUTPUT);  
  pinMode(RightMotor2Reverse, OUTPUT);  
  pinMode(LeftMotor2Forward, OUTPUT);  
  pinMode(LeftMotor2Reverse, OUTPUT);

  pinMode(BrushMotorForward, OUTPUT);
  pinMode(BrushMotorReverse, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  if(Serial.available()> 0 ){
    state = Serial.read();
    flag=0;
    
    }

   digitalWrite(BrushMotorForward, HIGH);
   digitalWrite(BrushMotorReverse, LOW);

  if(state == '1'){
  
   // Forward
   digitalWrite(RightMotorForward, HIGH); 
   digitalWrite(LeftMotorForward, HIGH);
   digitalWrite(RightMotorReverse, LOW); 
   digitalWrite(LeftMotorReverse, LOW); 


   digitalWrite(RightMotor2Forward, HIGH); 
   digitalWrite(LeftMotor2Forward, HIGH);
   digitalWrite(RightMotor2Reverse, LOW); 
   digitalWrite(LeftMotor2Reverse, LOW);

    if(flag == 0){
    Serial.println("Go Forward!");
    flag=1;
    }
   delay(1500);
  }
    
 
   else if (state == '2'){
   // Right turn
   digitalWrite(LeftMotorForward, HIGH); 
   digitalWrite(LeftMotorReverse, LOW);  
   digitalWrite(RightMotorForward, LOW);
   digitalWrite(RightMotorReverse, HIGH); 


  digitalWrite(RightMotor2Forward, HIGH); 
   digitalWrite(RightMotor2Reverse, LOW);
   digitalWrite(LeftMotor2Forward, LOW);
   digitalWrite(LeftMotor2Reverse, HIGH); 
        if(flag == 0){
          Serial.println("Turn Right");
          flag=1;
          }
    delay(1500);
            
      }
   

   
 
    else if (state == '3'){
   // Left Turn
   digitalWrite(RightMotorForward, HIGH); 
   digitalWrite(RightMotorReverse, LOW);
   digitalWrite(LeftMotorForward, LOW);
   digitalWrite(LeftMotorReverse, HIGH);  


  digitalWrite(RightMotor2Forward, HIGH); 
   digitalWrite(RightMotor2Reverse, LOW);
   digitalWrite(LeftMotor2Forward, LOW);
   digitalWrite(LeftMotor2Reverse, HIGH);

      if(flag == 0){
          Serial.println("Turn Left");
          flag=1;
          }
           delay(1500);
     
    }
   
   
    else if (state == '4'){
   // Reverse
   digitalWrite(RightMotorReverse, HIGH); 
   digitalWrite(LeftMotorReverse, HIGH);   
   digitalWrite(RightMotorForward, LOW);
   digitalWrite(LeftMotorForward, LOW);  

   digitalWrite(RightMotor2Forward, LOW); 
   digitalWrite(RightMotor2Reverse, HIGH);
   digitalWrite(LeftMotor2Forward, LOW);
   digitalWrite(LeftMotor2Reverse, HIGH); 

        if(flag == 0){
          Serial.println("Reverse Back");
          flag=1;
          }
        delay(1500);
    } 
   

    else if (state == '5'){
   // Stop
   digitalWrite(LeftMotorReverse, LOW);  
   digitalWrite(RightMotorReverse, LOW); 
   digitalWrite(LeftMotorForward, LOW);   
   digitalWrite(RightMotorForward, LOW);

   digitalWrite(RightMotor2Forward, LOW); 
   digitalWrite(RightMotor2Reverse, LOW);
   digitalWrite(LeftMotor2Forward, LOW);
   digitalWrite(LeftMotor2Reverse, LOW);  

       if(flag == 0){
          Serial.println("STOP");
          flag=1;
          }
     delay(1500);
       }
   
}
