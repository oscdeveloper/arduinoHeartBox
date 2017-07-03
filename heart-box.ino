int heartLedsTransistorPin = 9;
int heartDelayTime = 50;
int heartFadeFrame = 1;
int heartMaxBrightness = 30;
int heartMinBrightness = 1;

int ringButtonPin = 3;
int ringLedPin = 2;

int mirrorLeftLedPin = 5;
int mirrorRightLedPin = 6;
int mirrorLedsMaxBrightness = 255;
int mirrorLedsMinBrightness = 0;
int mirrorLedsFadeFrame = 1;




void setup() {

  pinMode(ringButtonPin, INPUT_PULLUP);
  pinMode(ringLedPin, OUTPUT);
  pinMode(mirrorLeftLedPin, OUTPUT);
  pinMode(mirrorRightLedPin, OUTPUT);
  
}




void loop() {

  if ( digitalRead(ringButtonPin) == HIGH ) { // box is open, heart stops pulsing

    // stop heart animation
    analogWrite(heartLedsTransistorPin, 0);

    // pause for 1sec, to have time to fully open the box ;)
    delay(1000);

    // mirror leds fade in
    for (int fadeValue = mirrorLedsMinBrightness; fadeValue <= mirrorLedsMaxBrightness; fadeValue += mirrorLedsFadeFrame) {
      analogWrite(mirrorLeftLedPin, fadeValue);
      analogWrite(mirrorRightLedPin, fadeValue);      
    }

    // led in ring box is on
    digitalWrite(ringLedPin, HIGH);

  // box is closed, heart starts pulsing        
  } else {

    // led in ring box is off
    digitalWrite(ringLedPin, LOW);

    // swtich off mirror leds
    analogWrite(mirrorLeftLedPin, mirrorLedsMinBrightness);
    analogWrite(mirrorRightLedPin, mirrorLedsMinBrightness);

    // heart pulsing animation, fade in
    for (int fadeValue = heartMinBrightness; fadeValue <= heartMaxBrightness; fadeValue += heartFadeFrame) {
      analogWrite(heartLedsTransistorPin, fadeValue);
      delay(heartDelayTime);
    }

    // heart pulsing animation, fade out
    for (int fadeValue = heartMaxBrightness; fadeValue >= heartMinBrightness; fadeValue -= heartFadeFrame) {
      analogWrite(heartLedsTransistorPin, fadeValue);
      delay(heartDelayTime);
    }
      
  }

  // pause 100ms, it's not necessary
  delay(100);
  
}


