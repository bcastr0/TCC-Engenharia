//O arduino iraenviar continuamente os valores dossensores após receber o comando de strat '$' e irá para de enviar quando receber o comando de stop '&'
int sensorPin0 = A0;    // Mínimo
int sensorPin1 = A1;    // Anelar
int sensorPin2 = A2;    // Médio
int sensorPin3 = A3;    // Indicador
int sensorPin4 = A4;    // Polegar

int sensorHALL1 = 2;    // Hall do Polegar
int sensorHALL2 = 3;    // Hall do Polegar

int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

int int_arrayValues[7];
int int_buffer[13];

int int_quadro=0;

int in_buf;
String str;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

  pinMode(sensorPin0, INPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);

  pinMode(sensorHALL1, INPUT);
  pinMode(sensorHALL2, INPUT);
  //Serial.begin(115200);

  //inicializaçãodo buffer
  int_buffer[0]='$';//inicio do quadro
  int_buffer[12]='&';//fim do quadro

  //Inicializando Serial
  Serial.end();
  Serial.begin(38400);
}

void loop() {

  //leitura dos sensores
//  int_arrayValues[0] = analogRead(sensorPin0);
//  int_arrayValues[1] = analogRead(sensorPin1);
//  int_arrayValues[2] = analogRead(sensorPin2);
//  int_arrayValues[3] = analogRead(sensorPin3);
//  int_arrayValues[4] = analogRead(sensorPin4);
//  int_arrayValues[5] = digitalRead(sensorHALL1);
//  int_arrayValues[6] = digitalRead(sensorHALL2);
  Serial.println("Inicio");
  Serial.println(analogRead(sensorPin0));
  Serial.println(analogRead(sensorPin1));
  Serial.println(analogRead(sensorPin2));
  Serial.println(analogRead(sensorPin3));
  Serial.println(analogRead(sensorPin4));
  Serial.println(digitalRead(sensorHALL1));
  Serial.println(digitalRead(sensorHALL2));
  Serial.println("");
  //Serial.println(int_arrayValues[6]);
  delay(5000);
}
