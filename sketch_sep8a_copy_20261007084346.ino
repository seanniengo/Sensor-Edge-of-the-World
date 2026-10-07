
const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  // With the sensor pointing down towards the core of the earth, if the distance is greater than 10 cm (height the sensor measures when on a rover)
  // then it will print "STOP!" to stop the rover before it drives over the edge
  
  if (distance > 10)
  {
    Serial.println("STOP!");
    
  }
  
  else
  {
    Serial.print("Distance: ");
    Serial.println(distance);
  }

  // --------------------------------------------------------
}
