
void ScanConnectors()
// This function will take a number(gScanNumber) from 1 through 24 and output binary 0 thru 23.
// The default value is binary 0 for any other number
{
  switch (gScanNumber)
  {
    case 1:
      MUX_1, LOW;
      MUX_2, LOW;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 2:
      MUX_1, HIGH;
      MUX_2, LOW;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 3:
      MUX_1, LOW;
      MUX_2, HIGH;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 4:
      MUX_1, HIGH;
      MUX_2, HIGH;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 5:
      MUX_1, LOW;
      MUX_2, LOW;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 6:
      MUX_1, HIGH;
      MUX_2, LOW;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 7:
      MUX_1, LOW;
      MUX_2, HIGH;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 8:
      MUX_1, HIGH;
      MUX_2, HIGH;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, LOW;
      break;

    case 9:
      MUX_1, LOW;
      MUX_2, LOW;
      MUX_3, LOW;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 10:
      MUX_1, HIGH;
      MUX_2, LOW;
      MUX_3, LOW;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 11:
      MUX_1, LOW;
      MUX_2, HIGH;
      MUX_3, LOW;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 12:
      MUX_1, HIGH;
      MUX_2, HIGH;
      MUX_3, LOW;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 13:
      MUX_1, LOW;
      MUX_2, LOW;
      MUX_3, HIGH;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 14:
      MUX_1, HIGH;
      MUX_2, LOW;
      MUX_3, HIGH;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 15:
      MUX_1, LOW;
      MUX_2, HIGH;
      MUX_3, HIGH;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 16:
      MUX_1, HIGH;
      MUX_2, HIGH;
      MUX_3, HIGH;
      MUX_4, HIGH;
      MUX_5, LOW;
      break;

    case 17:
      MUX_1, LOW;
      MUX_2, LOW;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    case 18:
      MUX_1, HIGH;
      MUX_2, LOW;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    case 19:
      MUX_1, LOW;
      MUX_2, HIGH;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    case 20:
      MUX_1, HIGH;
      MUX_2, HIGH;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    case 21:
      MUX_1, LOW;
      MUX_2, LOW;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    case 22:
      MUX_1, HIGH;
      MUX_2, LOW;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    case 23:
      MUX_1, LOW;
      MUX_2, HIGH;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    case 24:
      MUX_1, HIGH;
      MUX_2, HIGH;
      MUX_3, HIGH;
      MUX_4, LOW;
      MUX_5, HIGH;
      break;

    default:
      MUX_1, LOW;
      MUX_2, LOW;
      MUX_3, LOW;
      MUX_4, LOW;
      MUX_5, LOW;
      break;
  }
}

