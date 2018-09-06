// This sketch is for scanning the inputs.  


/*
 **************************************************************************************
  Cable_Tester_Test_Program

  For Panavision

  Written by Tom Kinyon - June 2018
  tom.kinyon@panavision.com
  424-558-0801‬

  A description of what the program does could go here.

  It compiles now. I found two problems:

  1) "define"s are compiler directives, and must go before the functions.

  2) The rows of asterisks were not "commented out".


  Coding Conventions:
  Local variables begin with "l" for "local", or "t" for "temp"
  Local static variables begin with "s"
  Global variables begin with "g"
  Global arrays begin with "ga"
  Constants begin with "c"
  Constant arrays begin with "ca"
  Booleans have "flag" or "state" in the name
  Passed parameter variable names begin with "the"
  Function names are verbs that describe what they do
  Loop indeces are "i" or begin with "i"
  Compiler derective #defines are in ALL_CAPS
  Otherwise, most everything uses camelCase


 **************************************************************************************
*/


#define INPUT_CONNECTORS     14  // Scan for connector number
#define INPUT_PINS           15  // Scan for pins & Outputs
#define OUTPUT_1             16  // +12V
#define OUTPUT_2             17  // -12V
#define OUTPUT_3             18  // +24V
#define OUTPUT_4             19  // -24V
#define OUTPUT_5              7   // Shield
#define TEST_BUTTON           A6   // TEST Button ---ANALOG PIN---
#define ADJUSTMENT_POT        A7   // Pot for whatever ---ANALOG PIN---
#define MUX_1                 2   // Multiplex scan 1
#define MUX_2                 3   // Multiplex scan 2
#define MUX_3                 4   // Multiplex scan 4
#define MUX_4                 5   // Multiplex scan 8
#define MUX_5                 6   // Multiplex scan 16
#define STEP_BUTTON           9   // SCAN button

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

//*************************************************************************************

void setup()
{
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

  Serial.begin(57600);

}

void loop()
{
  readButtons();

}
