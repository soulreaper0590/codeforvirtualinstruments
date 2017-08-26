void setup(){
  Serial.begin(9600);
}
int pre = 0;
int count = 0;
void loop(){
 float pro = analogRead(0);
 pre = pro-pre;
 int fof = pro/800;
 //if(fof)
   //Serial.println("hit");
 if(pre>100){
  Serial.println("hitup");
  Serial.println(count);
  delay(100);
 }
 //Serial.println(pro);



delay(10);
count++;
 pre = pro;
}
