/////////////////////////////////////////////////////////////////////
// Control Inalambrico para luces de carro/casilla rodante         //
// NOTA:RX Version 1 con Logica directa para salida RELAY          //
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

struct_message datosRecibidos;
const int rAux = 2, rIzq = 14, rDer = 12, rPos = 13, rFreno = 15;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) 
    {
      memcpy(&datosRecibidos, incomingData, sizeof(datosRecibidos));
      digitalWrite(rIzq, datosRecibidos.izq);
      digitalWrite(rDer, datosRecibidos.der);
      digitalWrite(rPos, datosRecibidos.pos);
      digitalWrite(rFreno, datosRecibidos.freno);
      // digitalWrite(rAux, datosRecibidos.aux);
    }

void setup() 
    {
      WiFi.mode(WIFI_STA);
      if (esp_now_init() != ESP_OK) return;
      pinMode(rIzq, OUTPUT); 
      pinMode(rDer, OUTPUT);
      pinMode(rPos, OUTPUT); 
      pinMode(rFreno, OUTPUT);
      // pinMode(rAux, OUTPUT);
       esp_now_register_recv_cb(OnDataRecv);
    }

void loop() {}
