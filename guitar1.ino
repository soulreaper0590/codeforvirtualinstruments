  int fingerStatus1(float finger);
  int fingerStatus2(float finger);
  int fingerStatus3(float finger);
  int fingerStatus4(float finger);
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
  finger11 = fingerStatus1(finger1);
    int finger22 = fingerStatus2(finger2);
      int finger33 = fingerStatus3(finger3);
        int finger44 = fingerStatus4(finger4);
  Serial.print(finger1);
  
  Serial.print(" "); Serial.print(finger2);
  Serial.print(" ");  Serial.print(finger3);
   Serial.print(" "); Serial.println(finger4);

  if(finger11==2&&finger22==1&&finger33==1&&finger44==2){
    Serial.println("G");
  }
  
  if(finger11==2&&finger22==2&&finger33==1){
    Serial.println("C");
  }
  if(finger11==2&&finger22==2&&finger33==2&&finger44==0){
    Serial.println("D");
  }
  if(finger11==2&&finger22==2&&finger33==1&&finger44==1){
    Serial.println("F");
  }
  if(finger11==2&&finger22==1&&finger33==1&&finger44==1){
    Serial.println("E");
  }
  if(finger11==2&&finger22==2&&finger33==2&&finger44==1){
    Serial.println("A");
  }
  
  
  
  
  
  delay(10);
  
  
  }
  int fingerStatus1(float finger){
    int fingerReturn= 0;
     
    if(finger>=350){
      fingerReturn=0;
      }
      if(finger<350&&finger>=250){
        fingerReturn = 1;
        }
       if(finger<250)
       fingerReturn=2;
    
    
    return fingerReturn;
    }
    int fingerStatus2(float finger){
    int fingerReturn= 0;
     
    if(finger>=450){
      fingerReturn=0;
      }
      if(finger<450&&finger>=370){
        fingerReturn = 1;
        }
       if(finger<370)
       fingerReturn=2;
    
    
    return fingerReturn;
    }
int fingerStatus3(float finger){
    int fingerReturn= 0;
     
    if(finger>=370){
      fingerReturn=0;
      }
      if(finger<370&&finger>=337){
        fingerReturn = 1;
        }
       if(finger<337)
       fingerReturn=2;
    
    
    return fingerReturn;
    }
int fingerStatus4(float finger){
    int fingerReturn= 0;
     
    if(finger>=430){
      fingerReturn=0;
      }
      if(finger<430&&finger>=340){
        fingerReturn = 1;
        }
       if(finger<340)
       fingerReturn=2;
    
    
    return fingerReturn;
    }

    

  int region(float stretch)
  {
    int regionReturn=0;
    if(stretch<630)
      regionReturn=1;
    else if(stretch>=630&&stretch<690)
      regionReturn=2;
    else 
      regionReturn=3;
    return regionReturn;
  }
