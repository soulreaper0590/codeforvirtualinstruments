float pro = analogRead(0);
if(pre==0&&pro!=0){
  Serial.println("B");
  count++;
  //Serial.println(count);
}
// Serial.println(pro);



delay(10);

 pre = pro;
