//*************************************************************************************************************
//*************************************************************************************************************

// This function reads the TEST & STEP buttons and sets flags for use
// in other functons.  It also sets flags to insure an action happens
// only once if the button is held down.  Contact de-bounce is done
// by hardware on the PCB.

void readButtons()
{
  if (analogRead(TEST_BUTTON) > 512) //  Read the button for one and only one
  {
    testButtonHeldFlag = false;  //  Remove the button held flag if the button has been released
  }


  if ((analogRead(TEST_BUTTON) < 512) && (testButtonHeldFlag == false))  //  Check for button pressed and not held down
  {
    testButtonHeldFlag = true;  //  Sets the button held flag
    testButtonFlag = true;  //  Sets the button pressed flag for the other functions
    Serial.println ("TEST BUTTON PRESSED");
    if (testButtonFlag == true)
    {
      testOutputs();  //  calls the output scan function
    }
  }
  if (testButtonFlag == true)
  {
    testOutputs();  //  calls the output scan function
  }
  if (digitalRead(STEP_BUTTON) == HIGH)  //  Reads the button for the button held
  {
    stepButtonHeldFlag = false;  //  Resets the button held
  }

  if (digitalRead(STEP_BUTTON) == LOW && (stepButtonHeldFlag) == false)
  {
    stepButtonHeldFlag = true;
    stepButtonFlag = true;
    testButtonFlag = false;
    Serial.println ("STEP BUTTON PRESSED");
    manualOutputs();

  }
  else
  {
    stepButtonFlag = true;
  }
}

//*************************************************************************************************************
//*************************************************************************************************************

// This is testing function to output the pin and connector numbers to the serial monitor.  The pin numbers will
// go from 1 to 16 with 1 thru 10 being pin mumbers, 11 thru 15 being the source voltages, and 16 is the
// connector panel for the device side.

void readConnectors()
{
  scanConnectors();  // calls the scan function

  if (digitalRead (INPUT_CONNECTORS) == HIGH)  // checks for a signal on the connector
  {
    Serial.print ("Connector Number ");  
    Serial.println (gScanNumber);
  }

  if (gScanNumber <= 16)  //  This will limit the output to the first 16 scans
  {
    if (digitalRead (INPUT_PINS) == HIGH)  // Checks for a signal on a pin
    {
      Serial.print ("Pin Number ");
      Serial.println (gScanNumber);
    }

  }
  gScanNumber ++ ;  // Increment to the next number

  if (gScanNumber > 24) // checks for the maximum number
  {
    gScanNumber = 1;
  }
}

//*************************************************************************************************************
//*************************************************************************************************************

// This is the coordinating function for checking the scanning hardware 

void testRead()
{
if (timeOutFlag == true)
{
  readConnectors();
  Serial.println ("Next Scan");
  timeOutFlag = false;
}

}

