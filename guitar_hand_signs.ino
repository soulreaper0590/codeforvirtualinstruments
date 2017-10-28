  int fingerStatus(float finger);
void setup(){
  
  Serial.begin(9600);
  }

 void loop(){
  
  float finger1 = analogRead(3);
  float finger2 = analogRead(2);
  float finger3 = analogRead(1);
  float finger4 = analogRead(0);
  int finger11 = fingerStatus(finger1);
    int finger22 = fingerStatus(finger2);
      int finger33 = fingerStatus(finger3);
        int finger44 = fingerStatus(finger4);


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
     
    if(finger<=630&&finger>=600){
      fingerReturn=1;
      }
      if(finger>630){
        fingerReturn = 2;
        }
    
    
    return fingerReturn;
    }
