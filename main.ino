#define button 13
#define redLED 11
#define greenLED 10
#define blueLED 9
int state = 0;
int old = 0;
int buttonPoll = 0;
long randOn = 0;                  // Initialize a variable for the ON time
long randOff = 0;                 // Initialize a variable for the OFF time
void setup() {
 pinMode(button,INPUT);
 randomSeed (analogRead (0));    // randomize

 //RGB LED set as output
 pinMode(redLED,OUTPUT);
 pinMode(greenLED,OUTPUT);
 pinMode(blueLED,OUTPUT);

 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,LOW);
}

void loop() {
 buttonPoll = digitalRead(button);
 if(buttonPoll == 1) {
 delay(100);
 buttonPoll = digitalRead(button);
 if(buttonPoll == 0) {
 state = old + 1;
 }
 }
 else {
 delay(250);
}

switch (state) {
 case 1: //Red color
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,LOW);
 old = state;
 break;
 case 2: //Green color
 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,HIGH);
 digitalWrite(blueLED,LOW);
 old = state;
 break;
 case 3: //Blue color
 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,HIGH);
 old = state; 
 break;
 case 4: //Purple color
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,HIGH);
 old = state; 
 break;
 case 5: //White color
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,HIGH);
 digitalWrite(blueLED,HIGH);
 old = state; 
 break;
 case 6: //Yellow color
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,HIGH);
 digitalWrite(blueLED,LOW);
 old = state;
 break;
 case 7: //Flicker like a broken flourescent
 randOn = random (0, 1000);    
 randOff = random (0, 10);
 digitalWrite(redLED,HIGH);
 digitalWrite(greenLED,HIGH);
 digitalWrite(blueLED,HIGH);
   delay(randOn);                // waits for a random time while ON
 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,LOW);
   delay(randOff);               // waits for a random time while OFF
 old = state; 
 break;
  default:
 digitalWrite(redLED,LOW);
 digitalWrite(greenLED,LOW);
 digitalWrite(blueLED,LOW);
 old = 0;
 break;
 }
}
