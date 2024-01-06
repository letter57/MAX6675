// this example is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/

#include "Arduino.h"
#include "max6675.h"
#include <Adafruit_TinyUSB.h>

/**
 * @brief       MAX6675 GPIO definition
 * 
 * @details     thermoDO = 17  ->  P0.17
 *              thermoCS = 21  ->  P0.21
 *              thermoCLK = 14 ->  P0.14
 */
int thermoDO = 17;
int thermoCS = 21;
int thermoCLK = 14;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

/**
 * @brief       Register Definition.
*/
static float Celsius;

/**
 * @brief       
 * 
 */
void setup()
{
    Serial.begin(9600); 
    Serial.println("MAX6675 test");
    // wait for MAX chip to stabilize
    delay(500);
}

/**
 * @brief       
 * 
 */
void loop()
{
    // basic readout test, just print the current temp
  
    Serial.print("C = "); 
    Serial.println(thermocouple.readCelsius());
    
    Serial.print("F = ");
    Serial.println(thermocouple.readFahrenheit());
 
    // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
    delay(1000);
}