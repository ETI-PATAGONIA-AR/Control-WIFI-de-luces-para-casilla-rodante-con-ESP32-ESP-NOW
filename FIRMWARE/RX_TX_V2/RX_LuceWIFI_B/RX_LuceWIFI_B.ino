/////////////////////////////////////////////////////////////////////
// Control Inalambrico para luces de carro/casilla rodante         //
// NOTA:RX Version 2 con Logica inversa de salida para SHIELD RELAY//
//       prof.martintorres@educ.ar - ETI PAtagonia                 //
/////////////////////////////////////////////////////////////////////

#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message 
      {
       bool izq, der, pos, freno, Aux;
      } struct_message;

struct_message datosRecibidos;
unsigned long últimaConexion = 0;

//const int rAux = 2; // D4 - Salida Aux
const int rIzq = 14; // D5
const int rDer = 12; // D6
const int rPos = 13; // D7
const int rFre = 15; // D8 

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) 
    {
     memcpy(&datosRecibidos, incomingData, sizeof(datosRecibidos));
     últimaConexion = millis(); // Reseteamos temporizador de seguridad
     // Lógica para Shield Relay (LOW = ON)
     digitalWrite(rIzq, datosRecibidos.izq ? LOW : HIGH);
     digitalWrite(rDer, datosRecibidos.der ? LOW : HIGH);
     digitalWrite(rPos, datosRecibidos.pos ? LOW : HIGH);
     digitalWrite(rFre, datosRecibidos.freno ? LOW : HIGH);
     // digitalWrite(rAux, datosRecibidos.Aux ? LOW : HIGH);
     }

void setup()
    {
     WiFi.mode(WIFI_STA);
     // Configurar pines como salida y apagarlos (HIGH = OFF)
     pinMode(rIzq, OUTPUT); digitalWrite(rIzq, HIGH);
     pinMode(rDer, OUTPUT); digitalWrite(rDer, HIGH);
     pinMode(rPos, OUTPUT); digitalWrite(rPos, HIGH);
     pinMode(rFre, OUTPUT); digitalWrite(rFre, HIGH);
     pinMode(rAux, OUTPUT); digitalWrite(rAux, HIGH);

     if (esp_now_init() == ESP_OK) 
       {
        esp_now_register_recv_cb(OnDataRecv);
       }
     }

void loop() 
    {
     // SEGURIDAD: Si no hay señal por más de 2 seg, apagar todo
     if (millis() - últimaConexion > 2000) 
       {
        digitalWrite(rIzq, HIGH);
        digitalWrite(rDer, HIGH);
        digitalWrite(rPos, HIGH);
        digitalWrite(rFre, HIGH);
       }
     }