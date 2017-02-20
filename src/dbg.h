#pragma once
#include <stdio.h>

#define DEBUG 1
//#undef DEBUG

#define DBG_NEWLINE "\n"

#ifdef ESP8266
	#include <HardwareSerial.h>
	#define INFO(...) Serial.printf(__VA_ARGS__); Serial.println();
	#define INFOX(...); Serial.printf(__VA_ARGS__);
	#define ERR(...) Serial.printf(__VA_ARGS__); Serial.println();
#else
	#define INFO(...) printf(__VA_ARGS__); printf(DBG_NEWLINE);
	#define INFOX(...); printf(__VA_ARGS__);
	#define ERR(...) printf(__VA_ARGS__); printf(DBG_NEWLINE);
#endif

#ifdef DEBUG
	#ifdef ESP8266
		#define DBG(...) Serial.printf("%s:%d ",__FILE__,__LINE__); Serial.printf(__VA_ARGS__); Serial.println();
		#define DBGX(...) Serial.printf(__VA_ARGS__);
		#define DBGLX(...) Serial.printf("%s:%d ",__FILE__,__LINE__); Serial.printf(__VA_ARGS__);
		#define DBG_PDU() printBin();
	#else
		#define DBG(...) fprintf(stderr,"%s:%d ",__FILE__,__LINE__); fprintf(stderr,__VA_ARGS__); fprintf(stderr,"\r\n");
		#define DBGX(...) fprintf(stderr,__VA_ARGS__);
		#define DBGLX(...) fprintf(stderr,"%s:%d ",__FILE__,__LINE__); fprintf(stderr,__VA_ARGS__);
		#define DBG_PDU() printBin();
	#endif
#else
	#define DBG(...) {};
	#define DBGX(...) {};
	#define DBGLX(...) {};
	#define DBG_PDU() {};
#endif
