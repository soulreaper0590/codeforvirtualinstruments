  int fingerStatus(float finger);
void setup(){
  
  Serial.begin(9600);
  }

 void loop(){
  int finger11 = 0;
//  float finger1 = analogRead(3);
  float finger2 = analogRead(2);
  float finger3 = analogRead(1);
  float finger4 = analogRead(0);
 // int finger11 = fingerStatus(finger1);
    int finger22 = fingerStatus(finger2);
      int finger33 = fingerStatus(finger3);
        int finger44 = fingerStatus(finger4);
  // Serial.println(finger1);
  
  Serial.print("A"); Serial.println(finger22);
  Serial.print("B");  Serial.println(finger33);
   Serial.print("C"); Serial.println(finger44);

  if(finger11==2&&finger22==1&&finger33==1&&finger44==2){
    Serial.println("Gmajor");
  }
  
  if(finger11==2&&finger22==2&&finger33==1){
    Serial.println("Cmajor");
  }
  if(finger11==2&&finger22==2&&finger33==2&&finger44==0){
    Serial.println("Dmajor");
  }
  if(finger11==2&&finger22==2&&finger33==1&&finger44==1){
    Serial.println("Fmajor");
  }
  if(finger11==2&&finger22==1&&finger33==1&&finger44==1){
    Serial.println("Emajor");
  }
  if(finger11==2&&finger22==2&&finger33==2&&finger44==1){
    Serial.println("Amajor");
  }
  
  
  
  
  
  delay(1000);
  
  
  }
  int fingerStatus(float finger){
    int fingerReturn= 0;
     
    if(finger<=550&&finger>=565){
      fingerReturn=1;
      }
      if(finger>575){
        fingerReturn = 2;
        }
    
    
    return fingerReturn;
    }
