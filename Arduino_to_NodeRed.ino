#define trig 3
#define echo 4

long duration = 0;
int dist = 0;
int accl = 0, fuel_cap = 100, spd = 0, distance = 0;
double battery_charge = 100.0;
byte state=0;
long prev_t, curr_t, del_t;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  prev_t = millis();
}

void loop() {
  long curr_t = millis();
  del_t = curr_t - prev_t;
  prev_t = curr_t;
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  
  accl = duration * 0.034/ 2;
  //byte val = map(dist,0,1024.0,0,255);
  //accl = map(dist,0,1024.0,0,50);
  //Serial.println(accl);
  accl = (accl>100 ? 30-(accl/10) : 0-(accl/10));                       //Make chart

  //spd = ((spd + 0.001*accl*del_t)>0 ? spd + 0.0001*accl*del_t : 0);       //Make gauge
  if(battery_charge>10)
  {
    if(spd<100)
    {
      spd = ((spd + 0.001*accl*del_t)>0 ? spd + 0.0001*accl*del_t : 0);
    }
    else
    spd = 100;
  }
  else
  {
    spd = spd>10 ? spd-10 : 0;
  }

  distance = distance + 0.001*spd*del_t;                           //Make chart

  battery_charge = battery_charge - 0.01*spd;                 //Make bar graph
  
  /*Serial.print(accl);
  Serial.print(",");
  Serial.print(accl);
  Serial.print(",");
  Serial.print(accl);
  Serial.print(",");
  Serial.print(spd);
  Serial.print(",");
  Serial.print(spd);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",");
  Serial.print(battery_charge);
  Serial.print(",");
  Serial.print(battery_charge);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",");
  Serial.print(spd);
  Serial.print(",");
  Serial.print(spd);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",");
  Serial.print(distance);*/


  Serial.print(accl);
  Serial.print(",");
  Serial.print(spd);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",");
  Serial.print(battery_charge);
  Serial.print(",");
  Serial.print("0");
  Serial.print(",");
  Serial.print("1");
  Serial.print(",");
  Serial.print("0");
  Serial.print(",");
  Serial.println("0");
  
  delay(1000);

}
