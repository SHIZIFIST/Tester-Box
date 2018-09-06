//******************************************************************************
// This function will continuously chase the 5 outputs when the TEST button
// pressed.  It uses the readPot function to get the delay value.

void testOutputs() 
{
  while (testButtonFlag == true)
  {
    gStepOutputValue++;
    if (gStepOutputValue > 5)
    {
      gStepOutputValue = 1;
    }
    stepOutputs();
    readButtons();
    readPot();
    delay (gDelayValue);
  }
}

// *******************************************************************************

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

// *******************************************************************************

// This will read the analog value of the pot, multiply it by 2 
// and add a minimum value to it. This is used for setting delay times.

void readPot()  // reads the pot and assigns its value to a variable to use for chase interval.
{
  gDelayValue = (analogRead ((ADJUSTMENT_POT)) * 2) + 100;
}

// ********************************************************************************

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


void readButtons()
{
  if (analogRead(TEST_BUTTON) >512)
  {
    testButtonPressedFlag = false;
  }
  
  if ((analogRead(TEST_BUTTON) < 512) && (testButtonPressedFlag == false))
  {
    testButtonPressedFlag = true;
    testButtonFlag = true;
    testOutputs();
    Serial.println ("TEST BUTTON PRESSED");
  }

if (digitalRead(STEP_BUTTON) == HIGH)
{
  stepButtonPressedFlag = false;
}

  if (digitalRead(STEP_BUTTON) == LOW && (stepButtonPressedFlag) == false)
  {
    stepButtonPressedFlag = true;
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




