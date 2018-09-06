//******************************************************************************
// This function will continuously chase the 5 outputs when the TEST button
// pressed.  It uses the readPot function to get the delay value.

void testInputScan() 
{
  while (testButtonFlag == true)
  {
    gScanNumber ++;
    if (gScanNumber > 24)
    {
      gScanNumber = 1;
    }
    stepInputs();
    readButtons();
    readPot();
    delay (gDelayValue);
  }
}

// *******************************************************************************

// This function is used to increment the 5 outputs when pressed.

void manualInputs()
{
  if (testButtonFlag == false && stepButtonFlag == true)
  {
    gScanNumber ++;
  }

  if (gScanNumber > 24)
  {
    gScanNumber = 1;
  }
  Serial.print ("Scan Number ");
  Serial.println (gScanNumber);
  ScanConnectors();
  OutputLeds();
  
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

void stepInputs()  //  Function to step through the 5 test outputs based on a variable.
//  Used with the manual and timed step functions.
{
  if (gScanNumber > 24)
  {
    gScanNumber = 1;
  }
  ScanConnectors();
  OutputLeds();
}

void OutputLeds()
{
  switch(gScanNumber)
  {
    case 1:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, HIGH);
    break;
    
    case 2:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, LOW);
    break;
    
    case 3:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 4:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 5:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 6:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 7:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 8:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 9:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 10:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 11:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 12:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 13:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 14:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 15:
    digitalWrite (OUTPUT_1, LOW);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 16:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 17:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 18:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 19:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, HIGH);
    break;


   case 20:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 21:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 22:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, LOW);
    break;

    case 23:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, LOW);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, HIGH);
    break;

    case 24:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, LOW);
    digitalWrite (OUTPUT_4, LOW);
    digitalWrite (OUTPUT_5, LOW);
    break;

    default:
    digitalWrite (OUTPUT_1, HIGH);
    digitalWrite (OUTPUT_2, HIGH);
    digitalWrite (OUTPUT_3, HIGH);
    digitalWrite (OUTPUT_4, HIGH);
    digitalWrite (OUTPUT_5, HIGH);
    break;
    
  }
}


