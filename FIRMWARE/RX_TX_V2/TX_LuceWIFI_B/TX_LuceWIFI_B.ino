/////////////////////////////////////////////////////////////////////
// Control Inalambrico para luces de carro/casilla rodante         //
// NOTA:TX Version 2 con Logica inversa de salida para SHIELD RELAY//
//       prof.martintorres@educ.ar - ETI PAtagonia                 //
/////////////////////////////////////////////////////////////////////

#include <esp_now.h>
#include <WiFi.h>

// ESTRUCTURA DE DATOS
typedef struct struct_message 
      {
       bool izq;
       bool der;
       bool pos;
       bool freno;
       bool Aux;
      } struct_message;

struct_message datosLuces;
uint8_t broadcastAddress[] = {0x84, 0xCC, 0xA8, 0xAD, 0x01, 0x04}; // <--PONER LA MAC ACÁ CON EL OTRO SKETCH QUE ARME

// PINES DE ENTRADA 
const int pinIzq = 14, pinDer = 12, pinPos = 13, pinFreno = 15, pinAux = 2;

void setup() 
    {
     Serial.begin(115200);
     WiFi.mode(WIFI_STA);

     if (esp_now_init() != ESP_OK) return;

     esp_now_peer_info_t peerInfo = {};
     memcpy(peerInfo.peer_addr, broadcastAddress, 6);
     esp_now_add_peer(&peerInfo);

     pinMode(pinIzq, INPUT_PULLUP);
     pinMode(pinDer, INPUT_PULLUP);
     pinMode(pinPos, INPUT_PULLUP);
     pinMode(pinFreno, INPUT_PULLUP);
     // pinMode(pinAux, INPUT_PULLUP);
    }

void loop() 
    {
     datosLuces.izq   = !digitalRead(pinIzq);
     datosLuces.der   = !digitalRead(pinDer);
     datosLuces.pos   = !digitalRead(pinPos);
     datosLuces.freno = !digitalRead(pinFreno);
     // datosLuces.Aux = !digitalRead(pinAux);
     esp_now_send(broadcastAddress, (uint8_t *) &datosLuces, sizeof(datosLuces));
     delay(50); 
    }
