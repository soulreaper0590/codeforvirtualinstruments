 int fingerStatus(float finger);
 int fingerStatus1(float finger);
 int afingerStatus(float finger);
  int sfingerStatus (float sfinger);
  
 #include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);
  
 
void setup(){
  
  Serial.begin(9600);
  BTserial.begin(38400);
  }

 void loop(){
  int cool = 1;

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
          int finger55 = afingerStatus(finger5);
             int  finger66 = fingerStatus1(finger1t);
                 int finger77 = sfingerStatus(finger2t);
                     int finger88 = fingerStatus(finger3t);
                        int finger99 = fingerStatus(finger4t);
                          int finger1010 = fingerStatus(finger5t);


int foot = analogRead(0);

  if(foot<300){
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
     {   Serial.print('D');
         BTserial.write('D');
         cool = 0;
        //delay(500);
         }
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('C');
         BTserial.write('C');
         
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('B');
         BTserial.write('B');
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {
        Serial.print('A');
         BTserial.write('A');
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('E');
         BTserial.write('E');
         cool = 0;
        // delay(500);
       }

         if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.print("K");
        BTserial.write('K');
         cool = 0;
     //   delay(500);
        }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
        {Serial.print("G");
        BTserial.write('G');
         cool = 0;
        //delay(500);
        }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.print("J");
        BTserial.write('J');
         cool = 0;
       // delay(500);
        }
     if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
       { Serial.print("I");
        BTserial.write('I');
         cool = 0;
     //   delay(500);
        }
     if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
      {  Serial.print("H");
        BTserial.write('H');
         cool = 0;
      //  delay(500);
        }
    
        
    
    }

  else{
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
     {   Serial.print('d');
         BTserial.write('d');
         cool = 0;
        //delay(500);
         }
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('c');
         BTserial.write('c');
         
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('b');
         BTserial.write('b');
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {
        Serial.print('a');
         BTserial.write('a');
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('e');
         BTserial.write('e');
         cool = 0;
        // delay(500);
       }

         if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.print("k");
        BTserial.write('k');
         cool = 0;
     //   delay(500);
        }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
        {Serial.print("g");
        BTserial.write('g');
         cool = 0;
        //delay(500);
        }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.print("j");
        BTserial.write('j');
         cool = 0;
       // delay(500);
        }
     if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
       { Serial.print("i");
        BTserial.write('i');
         cool = 0;
     //   delay(500);
        }
     if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
      {  Serial.print("h");
        BTserial.write('h');
         cool = 0;
      //  delay(500);
        }
    
    }
  
    if(cool == 1){
      Serial.print('0');
      BTserial.write('0');
      }

   delay(50);
}


  int fingerStatus(float finger){
    
     int fingerReturn;
    if(finger>360){
      fingerReturn=0;
      }
    if(finger<=360){
        fingerReturn = 1;
        }
   
    return fingerReturn;
    }

    int fingerStatus1(float finger){
    
     int fingerReturn;
    if(finger>220){
      fingerReturn=0;
      }
    if(finger<=220){
        fingerReturn = 1;
        }
   
    return fingerReturn;
    }
int sfingerStatus(float sfinger){
      int sfingerReturn;    
      if(sfinger>150){
      sfingerReturn=0;
      }
      if(sfinger<=150){
        sfingerReturn = 1;
        }
   
    return sfingerReturn;
  
  }

  int afingerStatus(float afinger){
    int afingerReturn;    
      if(afinger>175){
      afingerReturn=0;
      }
      if(afinger<=175){
        afingerReturn = 1;
        }
   
    return afingerReturn;
  
  }
  
