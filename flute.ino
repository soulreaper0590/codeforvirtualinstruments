#include <SoftwareSerial.h>
SoftwareSerial BTserial(7,8);

int datlring,datlmiddle,datlindex,datrring,datrmiddle,datrindex,datablow;//datatouch;
int deg;
void setup(){
  Serial.begin(9600);
  BTserial.begin(38400);
}
void loop()
{
//A0-right hand little finger   
datrring = int(analogRead(A3));//analog is continous whereas digital is analog of discrete unit
//A1-left hand middle finger
datrmiddle = int(analogRead(A2)); 
//A2-left hand index finger
datrindex = int(analogRead(A1)); 
//A3-right hand ringfinger 
datlring = int(analogRead(A7)); 
//A4-right hand middlefinger 
datlmiddle = int(analogRead(A5)); 
//A5-right hand index finger 
datlindex = int(analogRead(A6)); 
//datatouch =int(analogRead(A3));
datablow=int(analogRead(A4));     
//Serial.println(datablow);
//bool highpitch=(datatouch>300);
//bool lowpitch=(datatouch<300);

//bool blow = (int(datablow)>600);


bool lringclosed=(datlring<=570);
bool lringhalfclosed=((datlring>570)  &&  (datlring<=630));
bool lringopen=(datlring>630);
//Serial.println(datlring);//  below 570 570 to 630 and above

bool lmiddleclosed=(datlmiddle<=570);
bool lmiddlehalfclosed=((datlmiddle>570)  &&  (datlmiddle<=630));
bool lmiddleopen=(datlmiddle>630);
//Serial.println(datlmiddle);// below 570 570 to 630 and above 

bool lindexclosed=(datlindex<=540);
bool lindexhalfclosed=((datlindex>540)  &&  (datlindex<=600));
bool lindexopen=(datlindex>600);
//Serial.println(datlindex);//working fine below 540 540 to 600 and above     

bool rringclosed=(datrring<=570);
bool rringhalfclosed=((datrring>570)  &&  (datrring<=640));
bool rringopen=(datrring>640);
//Serial.println(datrring);//  below570   570 to 640 and above

bool rmiddleclosed=(datrmiddle<=530);
bool rmiddlehalfclosed=((datrmiddle>530)  &&  (datrmiddle<=600));
bool rmiddleopen=(datrmiddle>600);
//Serial.println(datrmiddle);//working awesome below 530 530 to 600 and above

bool rindexclosed=(datrindex<=540);
bool rindexhalfclosed=((datrindex>540) && (datrindex<=600));
bool rindexopen=(datrindex>600);
//Serial.println(datrindex);//awesome below 540 540 to 600 and above

//Serial.print(datatouch);
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
//Serial.print(datablow);
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

if(datablow>=200)
{
  
if(  lmiddleclosed  &&  lindexclosed     &&  rmiddleopen  &&  rindexopen  )// && blow)
    {
     Serial.println("a");
     BTserial.write("a");
    }

else if(lindexclosed  &&  lmiddleopen  &&  rmiddleopen  &&  rindexopen )// && blow)
    {Serial.println("b");
     BTserial.write("b");
    } 

else if(lindexclosed  &&  lmiddleopen  &&  rmiddleclosed  &&  rindexclosed  )// && blow)
    {Serial.println("c");
     BTserial.write("c");
    }

else if(lindexopen  &&  lmiddleopen  &&    rmiddleclosed  &&  rindexclosed  )// && blow)
    {Serial.println("d");
     BTserial.write("d");
    }

else if(lindexclosed  &&  lmiddleclosed  &&    rmiddleclosed  &&  rindexclosed)// && blow)
    {Serial.println("e");
     BTserial.write("e");
    }

else if(lindexclosed  &&  lmiddleclosed    &&  rmiddleopen  &&  rindexclosed )// && blow)
    {Serial.println("f");
     BTserial.write("f");
    }
    
else if(  lmiddleclosed  &&  lindexopen   &&  rmiddleopen  &&  rindexclosed  )//&& blow)
    {Serial.println("g");
     BTserial.write("g");
    }

if( lmiddleopen &&  lindexopen &&   rmiddleopen  &&  rindexopen ) 
    {
     Serial.println("b");
     BTserial.write("b");
    }
}

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

