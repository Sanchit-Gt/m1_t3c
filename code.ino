#define PIR_PIN 2
#define BUTTON_PIN 3  
#define MOTION_LED_PIN 12
#define BUTTON_LED_PIN 13  

volatile bool motionDetected = false;
volatile bool buttonPressed = false;

void pirInterrupt() {
    motionDetected = true;
}

void buttonInterrupt() {
    buttonPressed = true;
}

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);  
    pinMode(MOTION_LED_PIN, OUTPUT);
    pinMode(BUTTON_LED_PIN, OUTPUT);
    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(PIR_PIN), pirInterrupt, RISING);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterrupt, FALLING);
}

void loop() {
    if (motionDetected) {
        digitalWrite(MOTION_LED_PIN, HIGH);
        Serial.println("Motion detected! Turning on Motion LED.");
        motionDetected = false;
    } else {
        digitalWrite(MOTION_LED_PIN, LOW);
    }

    if (buttonPressed) {
        digitalWrite(BUTTON_LED_PIN, HIGH);
        Serial.println("Button pressed! Turning on Button LED.");
        buttonPressed = false;
    } else {
        digitalWrite(BUTTON_LED_PIN, LOW);
    }

    delay(1000);
}
