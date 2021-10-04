#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiUdp.h>

#define N 1024

WiFiMulti wifiMulti;
WiFiUDP udp;

const int port = 2222;

boolean mtg_flag;

void setup_wifi(){
    wifiMulti.addAP("SSID", "Password");

    if(wifiMulti.run() == WL_CONNECTED) {
    }else{
        M5.lcd.print("Not Connect");
        delay(1000);
    }

    udp.begin(port);
}

void setup()
{
    M5.begin();
    M5.Power.begin();

    mtg_flag = false;
    setup_wifi();
}

void loop()
{
    M5.update();

    // pythonからきたものを受信する
    char packetBuffer[N];
	int packetSize = udp.parsePacket();
 
	if (packetSize){
        int len = udp.read(packetBuffer, packetSize);
        if (len > 0){
			packetBuffer[len] = '\0'; // end
		}

		M5.Lcd.clear(BLACK);
  		M5.Lcd.setCursor(3, 3);
       

        if(packetBuffer[0] == 'm'){
            mtg_flag = true;
        }else{
            mtg_flag = false;
        }

        if(mtg_flag){
            M5.Lcd.fillScreen(RED);
            M5.Lcd.drawPngFile(SD, "/img/animal_quiz_neko_batsu.png");
        }else{
            M5.Lcd.fillScreen(M5.Lcd.color565(16, 154, 229));
            M5.Lcd.drawPngFile(SD, "/img/animal_quiz_neko_maru.png");
        }
	}
}
