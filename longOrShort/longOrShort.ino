int buttonPin = 2;
int ledPin = 8;

int lastButtonState = LOW;
bool buttonReleased = false;

unsigned long buttonPressedAt;
unsigned long buttonPressedFor = 0;
unsigned long interval = 200;
unsigned long previousMillis = 0;

int ledState = LOW;
int ledSwitch = 0;
int ledMode = 0;
int on = false;

void setup(){
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  
}

void loop(){
  buttonDetection();
  //ledStateChange();
  modeSelector();
  on = true;
}

void buttonDetection(){
  int buttonState = !digitalRead(buttonPin);

  if (buttonState != lastButtonState){
    if (buttonState == HIGH){
      ledSwitch = 1;
      buttonReleased = false;
      buttonPressedAt = millis();
      ledMode += 1;
      Serial.println("Button pressed");
    } // end if
    else{
      buttonReleased = true;
    } // end else
    lastButtonState = buttonState;
  } // end if

  if (buttonReleased == true){
    buttonPressedFor = millis() - buttonPressedAt;
    buttonReleased = false;
    buttonPressedAt = 0;
    Serial.print("Button was pressed for ");
    Serial.print(buttonPressedFor);
    Serial.println(" millisekonds");
  }
} // end void

void ledStateChange(){
  if (buttonPressedFor > 0){
    if (buttonPressedFor >= 1000){
      //digitalWrite(ledPin, LOW);
      on = false;
    } // end if
    else{
      on = true;
    } // end else
  } // end if
} // end void

void ledBlink(){
  unsigned long currentMillis = millis();
  interval = buttonPressedFor;
  if (currentMillis - previousMillis >= interval){
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    previousMillis = currentMillis;
  } // end if	
} // end void

void modeSelector(){
  if (on == true){
    if (ledMode == 0){
      digitalWrite(ledPin, HIGH);
    } // end if

    else if (ledMode == 1){
      ledBlink();
    } // end else if

    else{
      ledMode = 0;
    } // end else
  }	// end if
  else{
    digitalWrite(ledPin, LOW);
  } // end else
} // end void
