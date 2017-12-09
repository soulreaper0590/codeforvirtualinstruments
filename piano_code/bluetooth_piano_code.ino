 int fingerStatus(float finger);
 
  int sfingerStatus (float sfinger);
  
 #include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);
  
 
void setup(){
  
  Serial.begin(9600);
  BTserial.begin(38400);
  }

 void loop(){
  float pL = analogRead(0); 
  float pR = analogRead(11);
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
 int  finger11 = sfingerStatus(finger1);
    int finger22 = fingerStatus(finger2);
      int finger33 = fingerStatus(finger3);
        int finger44 = fingerStatus(finger4);
          int finger55 = fingerStatus(finger5);
             int  finger66 = sfingerStatus(finger1t);
                 int finger77 = fingerStatus(finger2t);
                     int finger88 = fingerStatus(finger3t);
                        int finger99 = fingerStatus(finger4t);
                          int finger1010 = fingerStatus(finger5t);

  
  //Serial.print(finger5t);
 /* Serial.print("left: ");
  Serial.print(pL);
  Serial.print("ryt: ");
  Serial.println(pR);*/
  Serial.println(finger3t);
  if(strechL==1){
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
     {   Serial.println("Cl");
         BTserial.write("Cl");
        // delay(500);
         }
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("C#l");
         BTserial.write("C#l");
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Dl");
         BTserial.write("Dl");
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {
        Serial.println("D#l");
         BTserial.write("D#l");
         //delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("El");
         BTserial.write("El");
       //  delay(500);
       }
        
    
    }

  if(strechL==2){
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Ch");
         BTserial.write("El");
       //  delay(500);
         }
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("C#h");
         BTserial.write("El");
        // delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Dh");
         BTserial.write("El");
       //  delay(500);
         }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("D#h");
         BTserial.write("El");
      //   delay(500);
       }
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Eh");
         BTserial.write("El");
   //    delay(500);
       }
    
    }
     if(strechL==3){
      if(finger11==1 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Chh");
        BTserial.write("El");}
      if(finger11==0 && finger22==1 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("C#hh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==1 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Dhh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==1 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("D#hh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==1 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Ehh");
        BTserial.write("El");}
        
    
    }
  if(strechR==2){
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Fh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Gh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.println("Ah");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
       { Serial.println("A#h");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
       { Serial.println("Bh");
        BTserial.write("El");}
    
    }

 if(strechR==3){
       if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
      {  Serial.println("Fl");
        BTserial.write("El");}
      else if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
        {Serial.println("Gl");
        BTserial.write("El");}
    else   if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.println("Al");
        BTserial.write("El");}
     else  if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
       { Serial.println("A#l");
        BTserial.write("El");}
     else if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
      {  Serial.println("Bl");
        BTserial.write("El");}
    else { 
      Serial.println("oops");
      }
 }
   if(strechR==1){
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==1 && finger77==0 && finger88==0 && finger99==0 && finger1010==0)
        {Serial.println("Fhh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==1 && finger88==0 && finger99==0 && finger1010==0)
       { Serial.println("Ghh");
       BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==1 && finger99==0 && finger1010==0)
       { Serial.println("Ahh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==1 && finger1010==0)
        {Serial.println("A#hh");
        BTserial.write("El");}
      if(finger11==0 && finger22==0 && finger33==0 && finger44==0 && finger55==0 && finger66==0 && finger77==0 && finger88==0 && finger99==0 && finger1010==1)
       { Serial.println("Bhh");
        BTserial.write("El");}
    
    }

   delay(50);
}

  int chord_filter(float p){
    int chord_filtered;
  if(p>400){
    chord_filtered = 1;
    }
 else if(p<=400&&p>=360){
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
 
