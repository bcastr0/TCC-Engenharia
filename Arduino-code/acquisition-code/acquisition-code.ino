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
  int_arrayValues[0] = analogRead(sensorPin0);
  int_arrayValues[1] = analogRead(sensorPin1);
  int_arrayValues[2] = analogRead(sensorPin2);
  int_arrayValues[3] = analogRead(sensorPin3);
  int_arrayValues[4] = analogRead(sensorPin4);
  int_arrayValues[5] = digitalRead(sensorHALL1);
  int_arrayValues[6] = digitalRead(sensorHALL2);
  //Serial.println(int_arrayValues[5]);
  //Serial.println(int_arrayValues[6]);

//Montando o bufferpara envio
  int_buffer[1]=int_arrayValues[0]/256;
  int_buffer[2]=int_arrayValues[0]%256;
  int_buffer[3]=int_arrayValues[1]/256;
  int_buffer[4]=int_arrayValues[1]%256;
  int_buffer[5]=int_arrayValues[2]/256;
  int_buffer[6]=int_arrayValues[2]%256;
  int_buffer[7]=int_arrayValues[3]/256;
  int_buffer[8]=int_arrayValues[3]%256;
  int_buffer[9]=int_arrayValues[4]/256;
  int_buffer[10]=int_arrayValues[4]%256;
  
  //combinação de informações dos sensores de efeito hall
      if(int_arrayValues[5]==0 && int_arrayValues[6]==0){
            int_buffer[11]=0;
      }else{
            if(int_arrayValues[5]==1 && int_arrayValues[6]==0){
                  int_buffer[11]=1;
            }else{
                  if(int_arrayValues[5]==0 && int_arrayValues[6]==1){
                        int_buffer[11]=10;
                  }else{
                        if(int_arrayValues[5]==1 && int_arrayValues[6]==1){
                            int_buffer[11]=11;
                        }
                  }
          }
      }
 

//Verificando se recebeu sinal do mestre
    if(Serial.available()>0){
      in_buf=Serial.read();
        if(in_buf=='$'){//verifica se o sinal recebido é para inicio do envio do quadro
            int_quadro=1;
        }else{
            if(in_buf=='&'){//verifica se o sinal recebido é para fim do envio do quadro
                int_quadro=0;
                digitalWrite(ledPin, LOW);
            }
        }
        
    }
//Envio das informações dos sensores para o mestre
    if(int_quadro==1){
        digitalWrite(ledPin, HIGH);
        Serial.write(int_buffer[0]);
        Serial.flush();
        Serial.write(int_buffer[1]);
        Serial.flush();
        Serial.write(int_buffer[2]);
        Serial.flush();
        Serial.write(int_buffer[3]);
        Serial.flush();
        Serial.write(int_buffer[4]);
        Serial.flush();
        Serial.write(int_buffer[5]);
        Serial.flush();
        Serial.write(int_buffer[6]);
        Serial.flush();
        Serial.write(int_buffer[7]);
        Serial.flush();
        Serial.write(int_buffer[8]);
        Serial.flush();
        Serial.write(int_buffer[9]);
        Serial.flush();
        Serial.write(int_buffer[10]);
        Serial.flush();
        Serial.write(int_buffer[11]);
        Serial.flush();
        Serial.write(int_buffer[12]);
        Serial.flush();
        delay(1);
    }
    
}
