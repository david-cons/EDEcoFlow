//WATER SENSOR
#define POWER_PIN_WATER_SENSOR  7
#define SIGNAL_PIN_WATER_SENSOR A5

//LED
#define PIN_LED 8

int value = 0; // variable to store the sensor value


void configure_water_sensor()
{
  pinMode(POWER_PIN_WATER_SENSOR, OUTPUT);   
  digitalWrite(POWER_PIN_WATER_SENSOR, LOW); 
}
void configure_led()
{
  pinMode(PIN_LED,OUTPUT);
}

void switch_sewage()
{
  // valves do not work
}
void switch_dispenser()
{
  // valves do not work
}

void register_button_input()
{
  // button never got implemented cause valves never worked 
}

bool is_tank_full()
{
  int threshold = 480;
  digitalWrite(POWER_PIN_WATER_SENSOR, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN_WATER_SENSOR); // read the analog value from sensor
  Serial.println(value);
  digitalWrite(POWER_PIN_WATER_SENSOR, LOW);   // turn the sensor OFF

  return value > threshold;
}
void flash_led()
{
  digitalWrite(PIN_LED, HIGH);
}
void stop_led()
{
  digitalWrite(PIN_LED, LOW);
}

void setup() {
  Serial.begin(9600);
  configure_water_sensor();
  configure_led();
}

void loop() {
  register_button_input();

  bool is_full = is_tank_full();
  if (is_full) {
    flash_led();
    switch_sewage();
  } else {
    stop_led();
  }

  if (is_dispenser) { // button toggles state of this global variable
    if (!is_full) {
      switch_dispenser();
    } else {
      // do nothing 
      }
  } else {
    switch_sewage();
  }
  
}
