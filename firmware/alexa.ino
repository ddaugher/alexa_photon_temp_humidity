#include "DHT.h"

#define DHTPIN D5
#define DHTTYPE DHT11
#define DELAY 5000

DHT dht(DHTPIN, DHTTYPE);

double h;    // humidity
double tc;    // temperature c
double tf; // temperature f


// Returns temperature
double getTemperaturec(String args){
    return tc;
}

double getTemperaturef(String args){
    return tf;
}

// Returns humidity
double getHumidity(String args){
    return h;
}

// Turn on/off LEDs
int controlled(String args){
    int pos = args.indexOf(',');
    
    if(-1 == pos){
        return -1;
    }
    
    String strPin = args.substring(0, pos);
    String strValue = args.substring(pos + 1);
    
    Serial.println();
    Serial.print("Pin: ");
    Serial.print(strPin);
    Serial.print(" ");
    Serial.print("Value: ");
    Serial.print(strValue);
    Serial.println();
    
    int pin = D2;
    int value = HIGH;
    
    if(strPin.equalsIgnoreCase("D2")){
        pin = D2;
    }
    else if(strPin.equalsIgnoreCase("D6")){
        pin = D6;
    }
    else{
        return -2;
    }
    
    if(strValue.equalsIgnoreCase("HIGH")){
        value = HIGH;
    }
    else if(strValue.equalsIgnoreCase("LOW")){
        value = LOW;
    }
    else{
        return -3;
    }
    
    digitalWrite(pin, value);
    
    return 1;
}

void setup() {
    Serial.begin(115200);
    dht.begin();
    
    pinMode(D2, OUTPUT);
    pinMode(D6, OUTPUT);
    
    // Particle Functions
    Spark.function("gettmpc", getTemperaturec);
    Spark.function("gettmpf", getTemperaturef);
    Spark.function("gethmd", getHumidity);
    Spark.function("ctrlled", controlled);
    Spark.variable("temperaturec", &tc, DOUBLE);
    Spark.variable("temperaturef", &tf, DOUBLE);
    Spark.variable("humidity", &h, DOUBLE);

}

void loop() {
    // Get temperature and humidity
    h = dht.readHumidity();
    tc = dht.readTemperature(false);
    tf = dht.readTemperature(true);
    
    Serial.println();
    Serial.print("Temperature (c): ");
    Serial.println(tc);
    Serial.print("Temperature (f): ");
    Serial.println(tf);
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println();
    
    delay(DELAY);
}