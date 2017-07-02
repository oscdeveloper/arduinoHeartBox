int ledPin = 9;   
int delayTime = 50;
int fadeFrame = 1;
int maxBrightness = 30;
int minBrightness = 1;

int button = 3;
boolean buttonAlreadyPressed = false;

int ringLed = 2;
int mirrorLeftLed = 5;
int mirrorRightLed = 6;
int mirrorLedBrightness = 255;

void setup() {
  
  //Serial.begin(9600);

  pinMode(button, INPUT_PULLUP);
  pinMode(ringLed, OUTPUT);
  
}

void loop() {

  if ( digitalRead(button) == HIGH ) {

    analogWrite(ledPin, 0);
    
    digitalWrite(ringLed, HIGH);
    analogWrite(mirrorLeftLed, mirrorLedBrightness);
    analogWrite(mirrorRightLed, mirrorLedBrightness);
    
  } else {
    
    digitalWrite(ringLed, LOW);
    analogWrite(mirrorLeftLed, 0);
    analogWrite(mirrorRightLed, 0);

    for (int fadeValue = minBrightness; fadeValue <= maxBrightness; fadeValue += fadeFrame) {
      analogWrite(ledPin, fadeValue);
      //Serial.println(fadeValue);
      delay(delayTime);
    }
  
    for (int fadeValue = maxBrightness; fadeValue >= minBrightness; fadeValue -= fadeFrame) {
      analogWrite(ledPin, fadeValue);
      //Serial.println(fadeValue);
      delay(delayTime);
    }
      
  }
  
}


