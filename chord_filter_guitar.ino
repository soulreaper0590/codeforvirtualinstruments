void setup() {
  Serial.begin(9600);

}
int chord_filter(float);

void loop() {
  float a = analogRead(0);
  Serial.println(a);
  int chord = chord_filter(a);
  if(chord==1){
    Serial.println("Chord_high");
    }
    if(chord == 2){
      Serial.println("Chord_very_high");
      }
      if(chord==0){
        Serial.println("Chord_normal");
        }
  delay(100);
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
  }yhyyyyyyyyyyyyyyyyyh
