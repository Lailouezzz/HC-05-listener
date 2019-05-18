/*
 Name:		HC_05_listener.ino
 Created:	18/05/2019 16:03:52
 Author:	AlzoxX76
*/
#include <SoftwareSerial.h>

#define HC05_TX 13 // TODO : select your TX pin
#define HC05_RX 12 // TODO : select your RX pin
#define DEBUG
#ifdef DEBUG
#define printD(...) Serial.print(__VA_ARGS__)
#define printlnD(...) Serial.println(__VA_ARGS__)
#else
#define printD(x)
#define printlnD(x)
#endif

SoftwareSerial HC05(HC05_RX, HC05_TX);


void setup()
{
	pinMode(HC05_RX, INPUT);
	pinMode(HC05_TX, OUTPUT);
	HC05.begin(9600);
	Serial.begin(9600);
}


void loop() {
	
	uint8_t buffer[1024]; // BUFFER

	if (HC05.available())
	{
		size_t readed = HC05.readBytes(buffer, sizeof(buffer)); // read data from HC-05
		Serial.print("BYTE READED : ");
		Serial.println(readed); // show how many bytes has been readed
		Serial.println("DATA (HEX) : ");

		// Loop for show the content of the buffer in hex
		for (uint16_t i = 0; i < readed; i++)
		{
			if(i != 0)
				Serial.print(", ");
			Serial.print("0x");
			if (buffer[i] < 16)
				Serial.print("0");
			Serial.print(buffer[i], HEX);
		}
		Serial.println("");
	}

}
