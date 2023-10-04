int buttonPin = 2;
int ledPin = 8;
int potmeter = A0;
int redPin = 6;
int greenPin = 5;
int bluePin = 3;

int buttonState;
int lastButtonState;

int mode = 0;
int lastLedState = LOW;

int redValue = 0;
int greenValue = 150;
int blueValue = 150;

unsigned long previousMillis;
const long interval = 500;



void buttonControl(){
    buttonState = !digitalRead(buttonPin);

    if (buttonState != lastButtonState){
        if (buttonState == HIGH){
            mode +=1;
        } // end if
    } // end if
    lastButtonState = buttonState;
} // end loop

void blinkFunction(){
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval){
        digitalWrite(ledPin, lastLedState);
        lastLedState = !lastLedState;
        previousMillis = currentMillis;
    } // end if
} // end loop

void sensorControledRGB(){
    int potmeterReading = analogRead(potmeter);

    redValue = map(potmeterReading, 0, 1023, 0, 255);

    analogWrite(redPin, redValue);
    alanlogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
}

void setup(){
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    pinMode(potmeter, INPUT);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    Serial.begin(9600);
} // end loop


void loop(){

} // end loop