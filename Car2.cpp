#define in1 3

#define in2 5

#define in3 6

#define in4 11

#define LEDF 9

#define LEDB 8

#define HORN 7

#define LEDP 4

//DBZ

int command; //Int to store app command state.

int Speed 204; //0 255.

int Speedsec;

int buttonState 0;

int lastButtonState = 0;

int Turnradius = 0; //Set the radius of a turn, 0 255 Note: the robot will malfunction if this is higher than int Speed.

int brakeTime = 45; 

int brkonoff 1; //1 for the electronic braking system, B for normal.

void setup() {

pinMode(inl, OUTPUT);

pinMode(in2, OUTPUT);

pinMode(in3, OUTPUT);

pinMode(in4, OUTPUT);

pinMode (LEDF, OUTPUT); //Set the LED pin.

pinMode (LEDB, OUTPUT);

pinMode (HORN, OUTPUT);

pinMode(LEDP, OUTPUT);

Serial.begin(9600); //Set the baud rate to your Bluetooth module.

}

void loop() {

if (Serial.available() > 0) {

command Serial.read();

Stop(); //Initialize with motors stoped.
int brkonoff 1; //1 for the electronic braking system, B for normal.

void setup() {

pinMode(inl, OUTPUT);

pinMode(in2, OUTPUT);

pinMode(in3, OUTPUT);

pinMode(in4, OUTPUT);

pinMode (LEDF, OUTPUT); //Set the LED pin.

pinMode (LEDB, OUTPUT);

pinMode (HORN, OUTPUT);

pinMode(LEDP, OUTPUT);

Serial.begin(9600); //Set the baud rate to your Bluetooth module.

}

void loop() {

if (Serial.available() > 0) {

command Serial.read();

Stop(); //Initialize with motors stoped.

forwardright();

break;

case 'H':

backleft();

break;

case '':

backright();

break;

case 'W':

frontledon();

break;

case 'w':

frontledoff();

break;

case 'U':

backledon();

break;

case 'u':

backledoff();

break;

case 'V':

hornon();

break;

case 'v':

hornoff();

break;

case 'X':

parkledon();

break;

case 'x':

parkledoff();

break;

case '0':

Speed = 100;

break;

case '1':

Speed 140;

break;

case '2':

Speed 153;

break;

case '3':

Speed 165;

break;

case '4':

Speed 178;

break;

case '5':

Speed 191;

break;

case '6':

Speed 204;

break;

case '7':

Speed 216;

break;

case '8':

Speed 229;

break;

case '9':

Speed 242;

break;

case 'q':

Speed = 255;

break;

}

Speedsec Turnradius;

if (brkonoff == 1) {

brakeon();

} else {

brakeoff();

}

}

}

void forward() {

analogWrite(inl, Speed);

analogWrite(in3, Speed);

}

void back() {

analogWrite(in2, Speed);

analogWrite(in4, Speed);

}

void left() {

analogWrite(in3, Speed);

analogWrite(in2, Speed);

}

void right() {

analogWrite(in4, Speed);

analogWrite(inl, Speed);

}

void forwardleft() {

analogWrite(inl, Speedsec);

analogWrite(in3, Speed);

}

void forwardright() {

analogWrite(inl, Speed);

analogWrite(in3, Speedsec);

}

void backright() {

analogWrite(in2, Speed);

analogWrite(in4, Speedsec);

}

void backleft() {

analogWrite(in2, Speedsec);

analogWrite(in4, Speed);

}

void Stop() {

analogWrite(inl, 0);

analogWrite(in2, 0);

analogWrite(in3, 0);

analogWrite(in4, 0);

}

void frontledon() { //turn Front led on or off)

digitalWrite(9, HIGH);

}

void frontledoff() { //turn Front led on or off)

digitalWrite(9, LOW);

}

void backledon() { //turn Back led on or off)

digitalWrite(8, HIGH);

}

void backledoff() { //turn Back led on or off)

digitalWrite(8, LOW);

}

void hornon()

{

digitalWrite(7, HIGH);

}

void hornoff()

{

digitalWrite(7, LOW);

}

void parkledon()

{

digitalWrite(4, HIGH);

}

void parkledoff()

{

digitalWrite(4, LOW);

}

void brakeOn() {

buttonState command;

if (buttonState != lastButtonState) {

if (buttonState == 'S') {

if (lastButtonState ! buttonState) {

digitalWrite(inl, HIGH);

digitalWrite(in2, HIGH);

digitalWrite(in3, HIGH);

digitalWrite(in4, HIGH);

delay (brakeTime);

Stop();

}

}

lastButtonState buttonState;

}

}

void brakeOff() {

}
