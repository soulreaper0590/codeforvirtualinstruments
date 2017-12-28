 int fingerStatus(float finger);
 
  int sfingerStatus (float sfinger);
  
 #include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);
  
 
void setup(){
  
  Serial.begin(9600);
  BTserial.begin(38400);
  }

 void loop(){
  int cool = 1;
  float pL = analogRead(11); 
  float pR = analogRead(0);
  int strechL = chord_filter(pL);
  int strechR = chord_filter1(pR);
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
          int finger55 = sfingerStatus(finger5);
             int  finger66 = fingerStatus(finger1t);
                 int finger77 = sfingerStatus(finger2t);
                     int finger88 = fingerStatus(finger3t);
                        int finger99 = fingerStatus(finger4t);
                          int finger1010 = fingerStatus(finger5t);

  
 //Serial.println(finger1t);
 /* Serial.print("left: ");
  Serial.print(pL);
  Serial.print("ryt: ");
  Serial.println(pR);*/
 // Serial.println(pR);
 strechL = 1;
  strechR = 3;
  if(strechL==1){
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
     {   Serial.print('D');
         BTserial.write('A');
         cool = 0;
        //delay(500);
         }
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('C');
         BTserial.write('B');
         
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('B');
         BTserial.write('C');
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {
        Serial.print('A');
         BTserial.write('D');
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.print('E');
         BTserial.write('E');
         cool = 0;
        // delay(500);
       }
        
    
    }

  if(strechL==2){
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Ch");
         BTserial.write("Ch");
         cool = 0;
        // delay(500);
         }
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("C#h");
         BTserial.write("C#h");
         delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Dh");
         BTserial.write("Dh");
         delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("D#h");
         BTserial.write("D#h");
         delay(500);
       }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Eh");
         BTserial.write("Eh");
      delay(500);
       }
    
    }
     if(strechL==3){
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Chh");
        BTserial.write("Chh");}
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("C#hh");
        BTserial.write("C#hh");}
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Dhh");
        BTserial.write("Dhh");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("D#hh");
        BTserial.write("D#hh");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Ehh");
        BTserial.write("Ehh");}
        
    
    }
  if(strechR==2){
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Fh");
         BTserial.write('F');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Gh");
         BTserial.write('G');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.println("Ah");
         BTserial.write('H');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
       { Serial.println("A#h");
         BTserial.write('I');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
       { Serial.println("Bh");
        BTserial.write('J');}
    
    }

 if(strechR==3){
       if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.print("K");
        BTserial.write('A');
         cool = 0;
     //   delay(500);
        }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
        {Serial.print("G");
        BTserial.write('B');
         cool = 0;
        //delay(500);
        }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.print("J");
        BTserial.write('C');
         cool = 0;
       // delay(500);
        }
     if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
       { Serial.print("I");
        BTserial.write('D');
         cool = 0;
     //   delay(500);
        }
     if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
      {  Serial.print("H");
        BTserial.write('E');
         cool = 0;
      //  delay(500);
        }
    
 }
   if(strechR==1){
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
        {Serial.println("Fhh");
         BTserial.write('K');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Ghh");
        BTserial.write('L');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.println("Ahh");
          BTserial.write('M');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
        {Serial.println("A#hh");
         BTserial.write('N');}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
       { Serial.println("Bhh");
         BTserial.write('O');}
    
    }
    if(cool == 1){
      Serial.print('0');
      }

   delay(50);
}

  int chord_filter(float p){
    int chord_filtered;
  if(p>340){
    chord_filtered = 1;
    }
 else if(p<=340&&p>=330){
    chord_filtered = 2;
    }
   else
    chord_filtered = 3;
  return chord_filtered;
  }
   int chord_filter1(float p){
    int chord_filtered;
  if(p>650){
    chord_filtered = 1;
    }
 else if(p<=650 && p>600){
    chord_filtered = 2;
    }
    else
    chord_filtered = 3;
  return chord_filtered;
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
