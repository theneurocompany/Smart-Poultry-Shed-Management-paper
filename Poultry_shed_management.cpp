//email deepak414576@gmail.com.

//Your username is poultry_111

//Projectiot@2025

#include <ArduinoIoTCloud.h>



#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "ac22eab2-eca2-4074-9359-36268e04d175";

const char SSID[]               = "projectiot";    // Network SSID (name)

const char PASS[]               = "123456789";    // Network password (use for WPA, or use as key for WEP)

const char DEVICE_KEY[]  = "U40JaRP2ztN@KuRd3h5PrvZ9G";    // Secret device password



void onHumChange();

void onTempChange();

void onFanChange();

void onGasChange();

void onLightChange();



int hum;

int temp;

bool fan;

bool gas;

bool light;



void initProperties(){



  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);

  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

  ArduinoCloud.addProperty(hum, READWRITE, ON_CHANGE, onHumChange);

  ArduinoCloud.addProperty(temp, READWRITE, ON_CHANGE, onTempChange);

  ArduinoCloud.addProperty(fan, READWRITE, ON_CHANGE, onFanChange);

  ArduinoCloud.addProperty(gas, READWRITE, ON_CHANGE, onGasChange);

  ArduinoCloud.addProperty(light, READWRITE, ON_CHANGE, onLightChange);



}



WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);





void setup() {

  Serial.begin(9600);

  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);

  ArduinoCloud.printDebugInfo();

}



void loop() {

  ArduinoCloud.update(); // Update IoT Cloud



  if (Serial.available() > 0) {

    char identifier = Serial.read();

    //int value = Serial.parseInt(); // Read integer value







    switch (identifier) {

      case 'T': temp = Serial.parseInt(); break; // Grocery 1 level

      case 'H': hum = Serial.parseInt(); break; // Grocery 1 level

      case 'F': fan = true; break;

      case 'f': fan = false; break;

      case 'B': light = true; break;

      case 'b': light = false; break;      

      case 'g': gas = true; break;

      case 'G': gas = false; break;

    

     // default: Serial.println("Unknown identifier received.");

    }

  }

}



void onTempChange()  {}

void onHumChange()  {}

void onGasChange()  {}

void onFanChange()  {}

void onLightChange()  {}
