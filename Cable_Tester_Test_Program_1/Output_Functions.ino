//*************************************************************************************************************
//*************************************************************************************************************
// This function will continuously chase the 5 outputs when the TEST button
// pressed.  It uses the readPot function to get the delay value.

void testOutputs()
{
  if ((testButtonFlag == true) && (timeOutFlag == true)) // Looks for test mode and timer
  {
    gStepOutputValue++; // Increment the outputs
    if (gStepOutputValue > 5)  // Resets the count to 1
    {
      gStepOutputValue = 1;
    }
    timeOutFlag = false; // Resets the timeout flag
    stepOutputs(); // Calls the function to turn on the outputs


  }
}
//*************************************************************************************************************
//*************************************************************************************************************

// This function is used to increment the 5 outputs when pressed.

void manualOutputs()
{
  if (testButtonFlag == false && stepButtonFlag == true)
  {
    gStepOutputValue++;
  }

  if (gStepOutputValue > 5)
  {
    gStepOutputValue = 1;
  }
  stepOutputs();

}

//*************************************************************************************************************
//*************************************************************************************************************

// This will read the analog value of the pot, multiply it by 2
// and add a minimum value to it. This is used for setting delay times.

void readPot()  // reads the pot and assigns its value to a variable to use for chase interval.
{
  gDelayValue = (analogRead ((ADJUSTMENT_POT)) * 2) + 100;
}

//*************************************************************************************************************
//*************************************************************************************************************

// This is a replacement for the delay function that will not tie up the processor during the delay interval

void timeDelay()
{
  currentMillis = millis();
  readPot(); // Get the delay time

  if (currentMillis - previousMillis >= gDelayValue) //  check for timeout
  {
    previousMillis = currentMillis;  //  Reset the timer
    timeOutFlag = true; //  Set the timeout flag
    // Serial.println ("Timeout");
    // Serial.println (currentMillis);
  }

}

//*************************************************************************************************************
//*************************************************************************************************************
void shutDown()
{
  if ((testButtonFlag == true && (testButtonHeldFlag) == false))
  {
  if (currentMillis2 - previousMillis2 >= gShutDownValue) //  check for timeout
  {
    testButtonFlag = false;
  }
  }
  {
    currentMillis2 = millis();
  }
}



//*************************************************************************************************************
//*************************************************************************************************************

// This function is used to actually turn on and off the 5 outputs based on a
// variable gStepOutputValue.  The default case is all off.

void stepOutputs()  //  Function to step through the 5 test outputs based on a variable.
//  Used with the manual and timed step functions.
{
  if (gStepOutputValue > 5)
  {
    gStepOutputValue = 1;
  }
  switch (gStepOutputValue)
  {
    case 1:
      digitalWrite (OUTPUT_5, LOW);
      digitalWrite (OUTPUT_1, HIGH);
      Serial.println ("+12 VOLTS");
      break;

    case 2:
      digitalWrite (OUTPUT_1, LOW);
      digitalWrite (OUTPUT_2, HIGH);
      Serial.println ("-12 VOLTS");
      break;

    case 3:
      digitalWrite (OUTPUT_2, LOW);
      digitalWrite (OUTPUT_3, HIGH);
      Serial.println ("+24 VOLTS");
      break;

    case 4:
      digitalWrite (OUTPUT_3, LOW);
      digitalWrite (OUTPUT_4, HIGH);
      Serial.println ("-24 VOLTS");
      break;

    case 5:
      digitalWrite (OUTPUT_4, LOW);
      digitalWrite (OUTPUT_5, HIGH);
      Serial.println ("SHIELD");
      break;

    default:
      digitalWrite (OUTPUT_1, LOW);
      digitalWrite (OUTPUT_2, LOW);
      digitalWrite (OUTPUT_3, LOW);
      digitalWrite (OUTPUT_4, LOW);
      digitalWrite (OUTPUT_5, LOW);

  }
}

//*************************************************************************************************************
//*************************************************************************************************************

void scanConnectors()
// This function will take a number(gScanNumber) from 1 through 24 and output binary 0 thru 23.
// The default value is binary 0 for any other number
{
  switch (gScanNumber)
  {
    case 1:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;

    case 2:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;

    case 3:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;

    case 4:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;

    case 5:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;

    case 6:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, LOW);
      digitalWrite ( MUX_3, HIGH);
      digitalWrite (  MUX_4, LOW);
      digitalWrite (  MUX_5, LOW);
      break;

    case 7:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;

    case 8:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;

    case 9:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 10:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 11:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 12:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 13:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 14:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 15:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 16:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, HIGH);
      digitalWrite (MUX_5, LOW);
      break;

    case 17:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    case 18:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    case 19:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    case 20:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    case 21:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    case 22:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    case 23:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    case 24:
      digitalWrite (MUX_1, HIGH);
      digitalWrite (MUX_2, HIGH);
      digitalWrite (MUX_3, HIGH);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, HIGH);
      break;

    default:
      digitalWrite (MUX_1, LOW);
      digitalWrite (MUX_2, LOW);
      digitalWrite (MUX_3, LOW);
      digitalWrite (MUX_4, LOW);
      digitalWrite (MUX_5, LOW);
      break;
  }
}





