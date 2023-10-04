int buttonPin = 2;
int ledPin = 8;

int lastButtonState = LOW;
bool buttonReleased = false;

unsigned long buttonPressedAt;
unsigned long buttonPressedFor = 0;

int ledState = LOW;
int ledSwitch = 0;

void setup(){
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);

    Serial.begin(9600);
}

void loop(){
    buttonDetection();
    ledStateChange();

}

void buttonDetection(){
    int buttonState = !digitalRead(buttonPin);
    
    if (buttonState != lastButtonState){
        if (buttonState == HIGH){
            ledSwitch = 1;
            buttonReleased = false;
            buttonPressedAt = millis();
            
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
        Serial.print("Button was pressed for");
        Serial.print(buttonPressedFor);
        Serial.println("millisekonds");
    }
} // end void

void ledStateChange(){
    if (ledSwitch == 1){
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        ledSwitch = 0;
    }
}