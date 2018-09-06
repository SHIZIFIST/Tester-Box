//*******************************************************************
// This function reads the TEST & STEP buttons and sets flags for use 
// in other functons.  It also sets flags to insure an action happens
// only once if the button is held down.  Contact de-bounce is done
// by hardware on the PCB.

void readButtons()
{
  if (analogRead(TEST_BUTTON) >512) //  Read the button for one and only one
  {
    testButtonHeldFlag = false;  //  Remove the button held flag if the button has been released
  }
  
  if ((analogRead(TEST_BUTTON) < 512) && (testButtonHeldFlag == false))  //  Check for button pressed and not held down
  {
    testButtonHeldFlag = true;  //  Sets the button held flag
    testButtonFlag = true;  //  Sets the button pressed flag for the other functions
    testInputScan();  //  calls the Input scan function
    Serial.println ("TEST BUTTON PRESSED");
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
    manualInputs();

  }
  else
  {
    stepButtonFlag = true;
  }
}

//*************************************************************************************************************
//*************************************************************************************************************

void ScanConnectors()
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




