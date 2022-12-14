// Functions for Battery Monitoring

int batterySensor = 34; // Battery Sensor is located to GPIO 34
float bHigh = 905.0;      // Analog Value read at 5.0 volts
float bLow = 450.0;       // Analog Value read at 3.0 volts
float vHigh = 5.0;      // Test volts at 5.0 volts
float vLow = 3.0;       // Test volts at 3.0 volts
float chargeMax = 4.2;  // Fully Charged Battery
float chargeMin = 3.2;  // Fully Depleted Battery
int lastCharge = 100;   // Keep Track of Last Charge

// initBattery() declares the battery sensor as an input
void initBattery(){

  pinMode(batterySensor, INPUT);
  
}

// voltsBattery reads the battery sensor and returns the voltage of the battery
float voltsBattery(){

  float bRead = analogRead(batterySensor);

  float mappedVolt = mapFloat(bRead, bLow, bHigh, vLow, vHigh);

  return mappedVolt;
  
}

// percentBattery reads the battery sensor and returns the % remaining in the battery
float percentBattery(){

  float battPercent = mapFloat(voltsBattery(), chargeMin, chargeMax, 0.0, 100.0);

  return battPercent;
  
}


// updateBattery gets the current percent of charge remaining. It then compares that value to the last known % charge
// of the battery. If they have changed, it updates the last known charge as well as updates the bleKeyboard library
// using the bleKeyboard.setBatteryLevel(curCharge) function
void updateBattery(){

  float currentCharge = percentBattery();

  if (currentCharge != lastCharge){
    bleKeyboard.setBatteryLevel(currentCharge);
    lastCharge = currentCharge;
  }

//  Serial.println(currentCharge);
  
}

// The normal Arduino float( ) function only works with integers. 
// This special function works with floating numbers for more precision
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
