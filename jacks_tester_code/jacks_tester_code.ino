#define INPUT_CONNECTORS     14  // Scan for connector number
#define INPUT_PINS           15  // Scan for pins & Outputs
#define OUTPUT_1             16  // +12V
#define OUTPUT_2             17  // -12V
#define OUTPUT_3             18  // +24V
#define OUTPUT_4             19  // -24V
#define OUTPUT_5             7   // Shield
#define TEST_BUTTON         A6   // TEST Button ---ANALOG PIN---
#define ADJUSTMENT_POT      A7   // Pot for whatever ---ANALOG PIN---
#define MUX_1                2   // Multiplex scan 1
#define MUX_2                3   // Multiplex scan 2
#define MUX_3                4   // Multiplex scan 4
#define MUX_4                5   // Multiplex scan 8
#define MUX_5                6   // Multiplex scan 16
#define STEP_BUTTON          9   // SCAN button
//#define CONNSTATE_ARRAY 24       //size of connector array
//#define PINSTATE_ARRAY 10        //size of pin array

//**************************************************************************************
//  CONSTANTS & VARIABLES
int gScanNumber;
int gConnectorNumber = 0;
int gCableDefinition;
unsigned long gDelayValue = 1000;
unsigned long gPotValue;
int gOutputNumber = 1;
bool testButtonFlag = false;
bool stepButtonFlag = false;
bool testButtonHeldFlag = false;
bool stepButtonHeldFlag = false;
int gStepOutputValue = 0;
//int connStateArray[CONNSTATE_ARRAY];  //this array will hold active connector numbers
//int pinStateArray[PINSTATE_ARRAY];    //this array will hold active pin numbers

int cpStateArray [10][24]; //2D array 
//**********************************************************************************************
//
void setup() 
{
  Serial.begin(9600);
  pinMode (OUTPUT_1, OUTPUT);
  pinMode (OUTPUT_2, OUTPUT);
  pinMode (OUTPUT_3, OUTPUT);
  pinMode (OUTPUT_4, OUTPUT);
  pinMode (OUTPUT_5, OUTPUT);
  pinMode (MUX_1, OUTPUT);
  pinMode (MUX_2, OUTPUT);
  pinMode (MUX_3, OUTPUT);
  pinMode (MUX_4, OUTPUT);
  pinMode (MUX_5, OUTPUT);
  pinMode (INPUT_CONNECTORS, INPUT);
  pinMode (INPUT_PINS, INPUT);
  pinMode (TEST_BUTTON, INPUT);
  pinMode (STEP_BUTTON, INPUT);
  pinMode (ADJUSTMENT_POT, INPUT);
  digitalWrite(MUX_1, LOW); //ARD pin D2 to MUXs data select input S0
  digitalWrite(MUX_2, LOW); //ARD pin D3 to MUXs data select input S1
  digitalWrite(MUX_3, LOW); //ARD pin D4 to MUXs data select input S2
  digitalWrite(MUX_4, HIGH); //ARD pin D5 to deMUXs data select input A0
  digitalWrite(MUX_5, HIGH); //ARD pin D6 to deMUXs data select input A1.  A2 always LOW to GND.
}

void loop() 
{//binary 0 or CASE 1
  int delayPeriod=2000;
  delay (delayPeriod);
  digitalWrite(A2,HIGH);
  digitalWrite(MUX_1, LOW); //ARD pin D2 to U10 MUX data select input S0 1/3 condition to select D0
  digitalWrite(MUX_2, LOW); //ARD pin D3 to U10 MUX data select input S1 2/3 condition to select D0
  digitalWrite(MUX_3, LOW); //ARD pin D4 to U10 MUX data select input S2 3/3 condition to select D0
  digitalWrite(MUX_4, LOW); //ARD pin D5 to U15 deMUX data select input A0 1/3 condition to enable Y0 
  digitalWrite(MUX_5, LOW); //ARD pin D6 to U15 deMUX data select input A1 2/3 condition to enable Y0 
                            //A2 grounded   U15 demux data select input A2 3/3 condition to enable Y0
  digitalRead (INPUT_CONNECTORS[]);
  cpStateArray[0] = digitalRead (INPUT_CONNECTORS)
  //digitalRead (INPUT_CONNECTORS[connStateArray]); //reads high or low condition from U10 U11 U12 
  //connStateArray[0] = digitalRead (INPUT_CONNECTORS); //assigns value into array
  delay (delayPeriod);
  //digitalRead (INPUT_PINS[pinStateArray]); //reads high or low condition from U13
  //pinStateArray[0] = (digitalRead (INPUT_PINS)*12); //assigns value into array
    //Serial.print("conn state array 1st element: ");
    //Serial.println(connStateArray[0]);
    //Serial.print("pin state array 1st element: ");
    //Serial.println(pinStateArray[0]);
    //Serial.println();
//*****************
//
//binary 1 or CASE 2
  delay (delayPeriod);
  digitalWrite(A2,HIGH);
  digitalWrite(MUX_1, HIGH); //ARD pin D2 to U10 MUX data select input S0 1/3 condition to select D1
  digitalWrite(MUX_2, LOW); //ARD pin D3 to U10 MUX data select input S1 2/3 condition to select D1
  digitalWrite(MUX_3, LOW); //ARD pin D4 to U10 MUX data select input S2 3/3 condition to select D1
  digitalWrite(MUX_4, LOW); //ARD pin D5 to U15 deMUX data select input A0 1/3 condition to enable Y0 
  digitalWrite(MUX_5, LOW); //ARD pin D6 to U15 deMUX data select input A1 2/3 condition to enable Y0 
                            //A2 grounded   U15 demux data select input A2 3/3 condition to enable Y0
  digitalRead (INPUT_CONNECTORS[connStateArray]); //reads high or low condition from U10 U11 U12 
  connStateArray[1] = digitalRead (INPUT_CONNECTORS); //assigns value into array
  delay (delayPeriod);
  digitalRead (INPUT_PINS[pinStateArray]); //reads high or low condition from U13
  pinStateArray[1] = (digitalRead (INPUT_PINS)*12); //assigns value into array
  
    Serial.print("conn state array 2nd element: ");
    Serial.println(connStateArray[1]);
    Serial.print("pin state array 2nd element: ");
    Serial.println(pinStateArray[1]);
    Serial.println();
//*****************
//
//binary 2 or CASE 3
  delay (delayPeriod);
  digitalWrite(A2,HIGH);
  digitalWrite(MUX_1, LOW); //ARD pin D2 to U10 MUX data select input S0 1/3 condition to select D1
  digitalWrite(MUX_2, HIGH); //ARD pin D3 to U10 MUX data select input S1 2/3 condition to select D1
  digitalWrite(MUX_3, LOW); //ARD pin D4 to U10 MUX data select input S2 3/3 condition to select D1
  digitalWrite(MUX_4, LOW); //ARD pin D5 to U15 deMUX data select input A0 1/3 condition to enable Y0 
  digitalWrite(MUX_5, LOW); //ARD pin D6 to U15 deMUX data select input A1 2/3 condition to enable Y0 
                            //A2 grounded   U15 demux data select input A2 3/3 condition to enable Y0
  digitalRead (INPUT_CONNECTORS[connStateArray]); //reads high or low condition from U10 U11 U12 
  connStateArray[2] = digitalRead (INPUT_CONNECTORS); //assigns value into array
  delay (delayPeriod);
  digitalRead (INPUT_PINS[pinStateArray]); //reads high or low condition from U13
  pinStateArray[2] = (digitalRead (INPUT_PINS)*12); //assigns value into array
  
    Serial.print("conn state array 3RD element: ");
    Serial.println(connStateArray[2]);
    Serial.print("pin state array 3RD element: ");
    Serial.println(pinStateArray[2]);
    Serial.println();
    
 digitalWrite(A2, LOW);
 
//*******-12v scan*********************************************************************************
//

//binary 0 or CASE 1
  delay (delayPeriod);
  digitalWrite(A3, HIGH);
  digitalWrite(MUX_1, LOW); //ARD pin D2 to U10 MUX data select input S0 1/3 condition to select D0
  digitalWrite(MUX_2, LOW); //ARD pin D3 to U10 MUX data select input S1 2/3 condition to select D0
  digitalWrite(MUX_3, LOW); //ARD pin D4 to U10 MUX data select input S2 3/3 condition to select D0
  digitalWrite(MUX_4, LOW); //ARD pin D5 to U15 deMUX data select input A0 1/3 condition to enable Y0 
  digitalWrite(MUX_5, LOW); //ARD pin D6 to U15 deMUX data select input A1 2/3 condition to enable Y0 
                            //A2 grounded   U15 demux data select input A2 3/3 condition to enable Y0
  digitalRead (INPUT_CONNECTORS[connStateArray]); //reads high or low condition from U10 U11 U12 
  connStateArray[0] = digitalRead (INPUT_CONNECTORS); //assigns value into array
  delay (delayPeriod);
  digitalRead (INPUT_PINS[pinStateArray]); //reads high or low condition from U13
  pinStateArray[0] = (digitalRead (INPUT_PINS)*(-12)); //assigns value into array
  
    Serial.print("conn state array 1st element: ");
    Serial.println(connStateArray[0]);
    Serial.print("pin state array 1st element: ");
    Serial.println(pinStateArray[0]);
    Serial.println();

digitalWrite(A3, LOW);
}

