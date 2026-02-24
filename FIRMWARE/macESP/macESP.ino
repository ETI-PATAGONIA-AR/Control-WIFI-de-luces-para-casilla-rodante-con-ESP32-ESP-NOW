/////////////////////////////////////////////////////////////////////
// Control Inalambrico para luces de carro/casilla rodante         //
// NOTA:                                                           //
// Para poder emparejar el TX y RX Obtener la Dirección MAC del    //
// del Receptor. Cargar este sketch y abre el Monitor Serie para   //
// anotar su dirección (ej: 84:CC:A8:AD:01:04)                     //
//                                                                 //
//         prof.martintorres@educ.ar - ETI PAtagonia               //
/////////////////////////////////////////////////////////////////////

#include <WiFi.h> // tambien sirve la libreria ESP8266WiFi.h
void setup()
    {
      Serial.begin(115200);
      WiFi.mode(WIFI_STA);
      Serial.print("MAC del Receptor: ");
      Serial.println(WiFi.macAddress());
    }
    
void loop(){}
