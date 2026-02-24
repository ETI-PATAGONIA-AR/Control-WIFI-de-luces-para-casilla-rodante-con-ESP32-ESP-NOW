/////////////////////////////////////////////////////////////////////
// Control Inalambrico para luces de carro/casilla rodante         //
// NOTA:TX Version 1 con Logica directa para salida RELAY          //
//       prof.martintorres@educ.ar - ETI PAtagonia                 //
/////////////////////////////////////////////////////////////////////

#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message 
      {
        bool izq;
        bool der;
        bool pos;
        bool freno;
        bool aux;
      } struct_message;

struct_message datosLuces;
uint8_t broadcastAddress[] = {0x84, 0xCC, 0xA8, 0xAD, 0x01, 0x04}; // <-- PONER LA MAC ACA CON EL OTRO SKETCH QUE ARME

const int PINaUX = 2, pinIzq = 14, pinDer = 12, pinPos = 13, pinFreno = 15;

void setup() 
    {
      Serial.begin(115200);
      WiFi.mode(WIFI_STA);

      if (esp_now_init() != ESP_OK) return;

      esp_now_peer_info_t peerInfo = {};
      memcpy(peerInfo.peer_addr, broadcastAddress, 6);
      esp_now_add_peer(&peerInfo);

      pinMode(pinIzq, INPUT_PULLDOWN);
      pinMode(pinDer, INPUT_PULLDOWN);
      pinMode(pinPos, INPUT_PULLDOWN);
      pinMode(pinFreno, INPUT_PULLDOWN);
      // pinMode(pinaUX, INPUT_PULLDOWN);
    }

void loop() 
    {
      datosLuces.izq = digitalRead(pinIzq);
      datosLuces.der = digitalRead(pinDer);
      datosLuces.pos = digitalRead(pinPos);
      datosLuces.freno = digitalRead(pinFreno);
      // datosLuces.iaux = digitalRead(pinAux);
      esp_now_send(broadcastAddress, (uint8_t *) &datosLuces, sizeof(datosLuces));
      delay(50); 
    }
