  int fingerStatus(float finger);
  int region(float stretch);
 
void setup(){
  
  Serial.begin(9600);
  }

 void loop(){
  float stretch1=analogRead(0);
  int stretch11=region(stretch1);//gives the 3 different regions 3:no stretch to 1:full stretch
  //Serial.println(stretch11);
  int finger11 = 0;
  float finger1 = analogRead(1);
  float finger2 = analogRead(2);
  float finger3 = analogRead(3);
  float finger4 = analogRead(4);
  finger11 = fingerStatus(finger1);
    int finger22 = fingerStatus(finger2);
      int finger33 = fingerStatus(finger3);
        int finger44 = fingerStatus(finger4);
  Serial.print(finger1);
  
  Serial.print(" "); Serial.print(finger2);
  Serial.print(" ");  Serial.print(finger3);
   Serial.print(" "); Serial.println(finger4);

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
  
  
  
  
  
  delay(10);
  
  
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

  int region(float stretch)
  {
    int regionReturn=0;
    if(stretch<630)
      regionReturn=1;
    else if(stretch>=630&&stretch<690)
      regionReturn=2;
    else ()
      regionReturn=3;
    return regionReturn;
  }

