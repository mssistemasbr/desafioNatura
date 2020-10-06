/*
####################################################################
## Simple Mqtt Client Code for connecting to Eugenio.io IoT platform
####################################################################
##
##################################################
## Author: Artur Sarlo
## Copyright:
## License:
## Version: 0.0.0
## Maintainer: Artur Sarlo
## Email: artur.sarlo@la.logicalis.com
## Status: demo
##################################################
*/

#ifndef SECRETS
#define SECRETS

/*
 #########################################################################################
 # CHANGE HERE
 #########################################################################################
*/
#define WIFI_SSID "nome de sua rede"
#define WIFI_PASSWORD "sua senha"

#define DEVICE_ID "df165c2e-"

// Copy contents from CA certificate here ▼
static const char cacert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDdzCCAl+gAwIBAgIEAgAAuTANBgkqhkiG9w0BAQUFADBaMQswCQYDVQQGEwJJ\n" \
"RTESMBAGA1UEChMJQmFsdGltb3JlMRMwEQYDVQQLEwpDeWJlclRydXN0MSIwIAYD\n" \
"VQQDExlCYWx0aW1vcmUgQ3liZXJUcnVzdCBSb290MB4XDTAwMDUxMjE4NDYwMFoX\n" \
"DTI1MDUxMjIzNTkwMFowWjELMAkGA1UEBhMCSUUxEjAQBgNVBAoTCUJhbHRpbW9y\n" \
"ZTETMBEGA1UECxMKQ3liZXJUcnVzdDEiMCAGA1UEAxMZQmFsdGltb3JlIEN5YmVy\n" \
"VHJ1c3QgUm9vdDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKMEuyKr\n" \
"mD1X6CZymrV51Cni4eiVgLGw41uOKymaZN+hXe2wCQVt2yguzmKiYv60iNoS6zjr\n" \
"IZ3AQSsBUnuId9Mcj8e6uYi1agnnc+gRQKfRzMpijS3ljwumUNKoUMMo6vWrJYeK\n" \
"mpYcqWe4PwzV9/lSEy/CG9VwcPCPwBLKBsua4dnKM3p31vjsufFoREJIE9LAwqSu\n" \
"XmD+tqYF/LTdB1kC1FkYmGP1pWPgkAx9XbIGevOF6uvUA65ehD5f/xXtabz5OTZy\n" \

"R9I4LtD+gdwyah617jzV/OeBHRnDJELqYzmp\n" \
"-----END CERTIFICATE-----\n";

// Copy contents from cert.pem here ▼
static const char client_cert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDCTCCAfGgAwIBAgIUSJ9/VXozZP7C02iTgUzUfZ1vjf4wDQYJKoZIhvcNAQEL\n" \
"BQAwFDESMBAGA1UEAwwJbG9jYWxob3N0MB4XDTIwMTAwNDEyNDgwOVoXDTIxMTAw\n" \
"NDEyNDgwOVowFDESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEF\n" \
"AAOCAQ8AMIIBCgKCAQEAw6jNSsJ1wlLbGy6BYiN04KKIPUOSd2MEPfhmJEySuRUJ\n" \
"QT+UdSAudPgVtTw5VVZTiXWgEcPmngAZ89mo5ZVnqUWYDXtm3D6T9kqRK8+jgWc/\n" \
"xeZ3vQj0A1B1mQCFFlMOLmn+FLRDpNwxq955XTkpM3IWjiQKGk+wthKsMKPRFBuy\n" \
"lQ97gDh/6etQ7MIP1rqpj5WLLXANEDtd1A0OOSjrKWr7afk/SIn1sqPH8Eob+ntZ\n" \
 

"-----END CERTIFICATE-----\n";

// Copy contents from  key.pem here ▼
static const char privkey[] PROGMEM = \
"-----BEGIN PRIVATE KEY-----\n" \
"MIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQDDqM1KwnXCUtsb\n" \
"LoFiI3Tgoog9Q5J3YwQ9+GYkTJK5FQlBP5R1IC50+BW1PDlVVlOJdaARw+aeABnz\n" \
"2ajllWepRZgNe2bcPpP2SpErz6OBZz/F5ne9CPQDUHWZAIUWUw4uaf4UtEOk3DGr\n" \
"3nldOSkzchaOJAoaT7C2Eqwwo9EUG7KVD3uAOH/p61Dswg/WuqmPlYstcA0QO13U\n" \
"DQ45KOspavtp+T9IifWyo8fwShv6e1lKJLcXceIrtO13vzGjeDglvT4Mt+iEjA3t\n" \
"VaKZlmZFF8gf6ILUCQQc/r82xY4GIfsAQqpDVNQPMUzP29ZJ8GqK+oldofDSNsSF\n" \
"xBvy7V7BAgMBAAECggEAP8puPDyQVi3bX85Wwp9awM5c6tR4EVKIFIhDDPymLY+t\n" \
"N8e56EH4w4wKz871xlvh2oQuDvy22Lahv34sccW3SVn2TBb6nz4L0ZXYJNeKsGrw\n" \
"QN52FXywyc/Wt26S9YdYrUtDWo63Ky3bR/S9zuYPB8XfkrIvVQq8S3BlEWqnhQ08\n" \
 

"-----END PRIVATE KEY-----\n";
/*
#########################################################################################
#########################################################################################
*/

// NTP related
#define UTC_TIME_ZONE_BRAZIL_HOURS -3
#define UTC_TIME_ZONE_BRAZIL_SECONDS UTC_TIME_ZONE_BRAZIL_HOURS * 3600
//#define USE_SUMMER_TIME_DST  //uncomment to use DST
#define DST_HOURS 0
#define DST_SECONDS DST_HOURS * 3600
#define CURRENT_TIME_APROXIMATION_AS_EPOCH_SECONDS 1510592825
#define NTP_SERVER_0 "pool.ntp.org"
#define NTP_SERVER_1 "time.nist.gov"

// MQTT related
#define MQTT_BROKER "logicalis-eugeniostg-iothub.azure-devices.net"
#define MQTT_PORT 8883
#define MQTT_USER "logicalis-eugeniostg-iothub.azure-devices.net/" DEVICE_ID "/api-version=2019-03-30"

#define MQTT_SUB_CLOUD_TO_DEVICE_TOPIC "devices/" DEVICE_ID "/messages/devicebound/#"
#define MQTT_SUB_INVOKE_BASE_TOPIC "$iothub/methods/POST/"
#define MQTT_SUB_INVOKE_TOPIC "$iothub/methods/POST/#"

#define MQTT_PUB_INVOKE_REPLY_TOPIC "$iothub/methods/res/{status_code}/?$rid={rid}"
#define MQTT_PUB_DEVICE_TO_CLOUD_TOPIC "devices/" DEVICE_ID "/messages/events/"

// #define USE_ARDUINO_JSON_LIB

#endif
