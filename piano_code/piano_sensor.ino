  int fingerStatus1(float finger);
  int fingerStatus2(float finger);
  int fingerStatus3(float finger);
  int fingerStatus4(float finger);
  int region(float stretch);
 
void setup(){
  
  Serial.begin(9600);
  }

 void loop(){
  float p = analogRead(0); 
  int strech = chord_filter(p);
  float finger1 = analogRead(1);
  float finger2 = analogRead(2);
  float finger3 = analogRead(3);
  float finger4 = analogRead(4);
  float finger5 = analogRead(5);
  float finger1t = analogRead(6);
  float finger2t = analogRead(7);
  float finger3t = analogRead(8);
  float finger4t = analogRead(9);
  float finger5t = analogRead(10);
 int  finger11 = fingerStatus(finger1);
    int finger22 = fingerStatus(finger2);
      int finger33 = fingerStatus(finger3);
        int finger44 = fingerStatus(finger4);
          int finger55 = fingerStatus(finger5);
             int  finger66 = fingerStatus(finger1t);
                 int finger77 = fingerStatus(finger2t);
                     int finger88 = fingerStatus(finger3t);
                        int finger99 = fingerStatus(finger4t);
                          int finger1010 = fingerStatus(finger5t);

  
  
  
  
  delay(10);
  
  
  }
  int chord_filter(float p){
  int chord_filtered  = 0;
  if(p<330){
    chord_filtered = 2;
    }
  if(p>330&&p<360){
    chord_filtered = 1;
    }
  return chord_filtered;
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
 
