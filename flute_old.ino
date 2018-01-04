#include <SoftwareSerial.h>
SoftwareSerial BTserial(7,8);
//A1,2,3 RH;A4 PS;A5,6,7 LH
int datlring,datlmiddle,datlindex,datrring,datrmiddle,datrindex,datablow;//datatouch;
int deg;
void setup(){
  Serial.begin(9600);
  BTserial.begin(38400);
}
void loop()
{
  int cool =0;

  
//A0-right hand little finger   
datrring = int(analogRead(3));//analog is continous whereas digital is analog of discrete unit
//A1-left hand middle finger
datrmiddle = int(analogRead(2)); 
//A2-left hand index finger
datrindex = int(analogRead(1)); 
//A3-right hand ringfinger 
datlring = int(analogRead(7)); 
//A4-right hand middlefinger 
datlmiddle = int(analogRead(5)); 
//A5-right hand index finger 
datlindex = int(analogRead(6)); 
//datatouch =int(analogRead(A3));
datablow=int(analogRead(4));     
//Serial.println(datablow);
//bool highpitch=(datatouch>300);
//bool lowpitch=(datatouch<300);
 // Serial.println(datablow);

//bool blow = (int(datablow)>600);


bool lringclosed=(datlring<=490);
bool lringhalfclosed=((datlring>490)  &&  (datlring<=550));
bool lringopen=(datlring>550);
//Serial.println(datlring);//  below 570 570 to 630 and above

bool lmiddleclosed=(datlmiddle<=480);
//bool lmiddlehalfclosed=((datlmiddle>510)  &&  (datlmiddle<=650));
bool lmiddleopen=(datlmiddle>480);
//Serial.println(datlmiddle);// below 570 570 to 630 and above 

bool lindexclosed=(datlindex<=470);
//bool lindexhalfclosed=((datlindex>510)  &&  (datlindex<=620));
bool lindexopen=(datlindex>470);
//Serial.println(datlindex);//working fine below 540 540 to 600 and above     

bool rringclosed=(datrring<=510);
//bool rringhalfclosed=((datrring>570)  &&  (datrring<=645));
bool rringopen=(datrring>510);
//Serial.println(datrring);//  below570   570 to 640 and above

bool rmiddleclosed=(datrmiddle<=550);
bool rmiddlehalfclosed=((datrmiddle>550)  &&  (datrmiddle<=630));
bool rmiddleopen=(datrmiddle>610);
//Serial.println(datrmiddle);//working awesome below 530 530 to 600 and above

bool rindexclosed=(datrindex<=550);
bool rindexhalfclosed=((datrindex>550) && (datrindex<=620));
bool rindexopen=(datrindex>600);
//Serial.println(datrindex);//awesome below 540 540 to 600 and above
bool blow=(datablow>100);
//Serial.print(blow);
//for calibration
/*Serial.print(datlring);
Serial.print("\t");
Serial.print(datlmiddle);
Serial.print("\t");
Serial.print(datlindex);
Serial.print("\t");
Serial.print(datrring);
Serial.print("\t");
Serial.print(datrmiddle);
Serial.print("\t");
Serial.print(datrindex);
Serial.print("\t");
Serial.print(datatouch);

//Serial.print("\n");

/*if(lringclosed)
{
Serial.print("lringclosed");
Serial.print("\t");
}
if(lmiddleclosed)
{Serial.print("lmiddleclosed");
Serial.print("\t");
}
if(lindexclosed)
{Serial.print("lindexclosed");
Serial.print("\t");
}
if(rringclosed)
{Serial.print("rringclosed");
Serial.print("\t");
}
if(rmiddleclosed)
{Serial.print("rmiddleclosed");
Serial.print("\t");
}
if(rindexclosed)
{Serial.print("rindexclosed");
Serial.print("\t");


}if(lringhalfclosed)
{Serial.print("lringhalfclosed");
Serial.print("\t");
}if(lmiddlehalfclosed)
{Serial.print("lmiddlehalfclosed");
Serial.print("\t");
}if(lindexhalfclosed)
{Serial.print("lindexhalfclosed");
Serial.print("\t");
}if(rringhalfclosed)
{Serial.print("rringhalfclosed");
Serial.print("\t");
}if(rmiddlehalfclosed)
{Serial.print("rmiddlehalfclosed");
Serial.print("\t");
}

if(lringopen)
{
  Serial.print("lringopen");
Serial.print("\t");
}
if(lmiddleopen)
{
  Serial.print("lmiddleopen");
Serial.print("\t");
}
if(lindexopen)
{
  Serial.print("lindexopen");
Serial.print("\t");
}
if(rringopen)
{
  Serial.print("rringopen");
Serial.print("\t");
}
if(rmiddleopen)
{
Serial.print("rmiddleopen");
Serial.print("\t");
}
if(rindexopen)
{Serial.print("rindexopen");
Serial.print("\t");
}

if(highpitch)
Serial.print("highpitch");
else
Serial.print("lowpitch");
Serial.print("\n");*/

/*Serial.print(lindexclosed);
Serial.print(lmiddleclosed);
Serial.print(lringclosed);
Serial.print(rindexclosed);
Serial.print(rmiddleclosed);
Serial.print(rringopen);
Serial.println(blow);*/
int blow1 = 1;
if(blow==1)
  blow1=0;
  
if(  lmiddleclosed  &&  lindexclosed     &&  rmiddleopen  &&  rindexopen&& lringclosed && rringopen && blow1 )//sa-2
    {
     Serial.print("s");
     BTserial.write("s");
     cool =1;
    }

else if(lindexclosed  &&  lmiddleclosed  &&  rmiddleopen  &&  rindexopen&& lringopen && rringopen )//re-3
    {Serial.print("r");
     BTserial.write("r");
     cool =1;
    } 

else if(lindexclosed  &&  lmiddleopen  &&  rmiddleopen  &&  rindexopen&& rringopen&&lringopen  )//ga-r
    {Serial.print("g");
     BTserial.write("g");
     cool =1;
    }

else if(lindexopen  &&  lmiddleopen  &&    rmiddleopen  &&  rindexopen&&rringopen&&lringopen  )//ma-5
    {Serial.print("m");
     BTserial.write("m");
     cool =1;
    }

else if(lindexclosed  &&  lmiddleclosed  &&    rmiddleclosed  &&  rindexclosed  &&lringclosed &&rringclosed && blow)//paa-6
    {Serial.print("e");
     BTserial.write("e");
     cool =1;
    }
    else if(lindexclosed  &&  lmiddleclosed  &&    rmiddleclosed  &&  rindexclosed  &&lringclosed &&rringclosed){
      Serial.print("y");
      }

else if(lindexclosed  &&  lmiddleclosed    &&  rmiddleclosed  &&  rindexclosed  && rringopen && lringclosed && blow)//dha-7
    {Serial.print("f");
     BTserial.write("f");
     cool =1;
    }
    else if(lindexclosed  &&  lmiddleclosed    &&  rmiddleclosed  &&  rindexclosed  && rringopen && lringclosed){
      Serial.print("z");
      }
    
else if(  lmiddleclosed  &&  lindexclosed   &&  rmiddleopen  &&  rindexclosed   &&rringopen && lringclosed && blow)//ni-i
    {Serial.print("a");
     BTserial.write("a");
     cool =1;
    }
    else if( lmiddleclosed  &&  lindexclosed   &&  rmiddleopen  &&  rindexclosed   &&rringopen && lringclosed){
      
      Serial.print("x");
      }

else if(lmiddleclosed  &&  lindexclosed     &&  rmiddleopen  &&  rindexopen&& lringclosed && rringopen  && blow)//saa high -9
    {
     Serial.print("b");
     BTserial.write("b");
     cool =1;
    }
    else{
      Serial.println("0");}


/*else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringhalfclosed  &&  rmiddleclosed  &&  rindexclosed && highpitch)// && blow)
Serial.print("i ");//D1

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringopen  &&  rmiddleclosed  &&  rindexclosed && highpitch)// && blow)
Serial.print("j ");//D2/N1

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rindexclosed  &&  rmiddlehalfclosed  &&  rringopen && highpitch)// && blow)
Serial.print("k ");//N2/D3

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringopen  &&  rmiddleopen  &&  rindexclosed && highpitch)// && blow)
Serial.print("l ");//N3




//low pitch



else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringopen  &&  rmiddleopen  &&  rindexopen && lowpitch)
Serial.print("m ");//S

else if(lindexclosed  &&  lmiddleclosed  &&  lringhalfclosed  &&  rringopen  &&  rmiddleopen  &&  rindexopen && lowpitch)
Serial.print("n ");//R1

else if(lindexclosed  &&  lmiddleclosed  &&  lringopen  &&  rringopen  &&  rmiddleopen  &&  rindexopen && lowpitch)
Serial.print("o ");//R2/G1

else if(lindexclosed  &&  lmiddlehalfclosed  &&  lringopen  &&  rringopen  &&  rmiddleopen  &&  rindexopen && lowpitch)
Serial.print("p ");//G2/R3

else if(lindexclosed  &&  lmiddleopen  &&  lringopen  &&  rringopen  &&  rmiddleopen  &&  rindexopen && lowpitch)
Serial.print("q ");//G3

else if(lindexhalfclosed  &&  lmiddleopen  &&  lringopen  &&  rringopen  &&  rmiddleopen  &&  rindexopen && lowpitch)
Serial.print("r ");//M1

else if(lringopen  &&  lmiddleopen  &&  lindexopen  &&  rringopen  &&  rmiddleopen  &&  rindexopen && lowpitch)
Serial.print("s ");//M2

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringclosed  &&  rmiddleclosed  &&  rindexclosed && lowpitch)
Serial.print("t ");//P

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringhalfclosed  &&  rmiddleclosed  &&  rindexclosed && lowpitch)
Serial.print("u ");//D1

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringopen  &&  rmiddleclosed  &&  rindexclosed && lowpitch)
Serial.print("v ");//D2/N1

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rindexclosed  &&  rmiddlehalfclosed  &&  rringopen && lowpitch)
Serial.print("w ");//N2/D3

else if(lringclosed  &&  lmiddleclosed  &&  lindexclosed  &&  rringopen  &&  rmiddleopen  &&  rindexclosed && lowpitch )
Serial.print("x ");//N3
else
Serial.println("z");
//}
//else
//Serial.print("z ");



if(lringopen && rindexopen && lmiddleclosed && lindexclosed && rmiddleclosed && rringclosed && lowpitch)
Serial.print("a ");
else if(lringopen && rindexopen && lmiddleopen && lindexclosed && rmiddleclosed && rringclosed && lowpitch)
Serial.print("b ");
else if(lringopen && rindexopen && lmiddleopen && lindexopen && rmiddleclosed && rringclosed && lowpitch)
Serial.print("c ");
else if(lringclosed && rindexclosed && lmiddleclosed && lindexopen && rmiddleclosed && rringclosed && lowpitch)
Serial.print("d ");
else if(lringclosed && rindexclosed && lmiddleclosed && lindexclosed && rmiddleclosed && rringopen && lowpitch)
Serial.print("e ");
else if(lringclosed && rindexclosed && lmiddleclosed && lindexclosed && rmiddleopen && rringopen && lowpitch)
Serial.print("f ");
else if(lringclosed && rindexopen && lmiddleclosed && lindexclosed && rmiddleopen && rringopen && lowpitch)
Serial.print("g ");
else if(lringopen && rindexopen && lmiddleclosed && lindexclosed && rmiddleopen && rringopen && lowpitch)
Serial.print("h ");

else if(lringopen && rindexopen && lmiddleclosed && lindexclosed && rmiddleclosed && rringclosed && highpitch)
Serial.print("h ");
else if(lringopen && rindexopen && lmiddleopen && lindexclosed && rmiddleclosed && rringclosed && highpitch)
Serial.print("i ");
else if(lringopen && rindexopen && lmiddleopen && lindexopen && rmiddleclosed && rringclosed && highpitch)
Serial.print("j ");
else if(lringclosed && rindexclosed && lmiddleclosed && lindexopen && rmiddleclosed && rringclosed && highpitch)
Serial.print("k ");
else if(lringclosed && rindexclosed && lmiddleclosed && lindexclosed && rmiddleclosed && rringopen && highpitch)
Serial.print("l ");
else if(lringclosed && rindexclosed && lmiddleclosed && lindexclosed && rmiddleopen &&g rringopen && highpitch)
Serial.print("m ");
else if(lringclosed && rindexopen && lmiddleclosed && lindexclosed && rmiddleopen && rringopen && highpitch)
Serial.print("n ");
else
Serial.print("z ");

Serial.flush();*/
delay(100);

//pvalue1=datablow;
//pvalue2=pvalue1;
  
}
