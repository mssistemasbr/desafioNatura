/*
  FONTE EKOS - ESP8266
  Compile no NodeMCU 1.0
  01/10/2020 as 11:04h
  - Versão 1.0
  [+] - Ajuste no timer da frase, na hora do apertar o botão...
 
 
  [+]0001.mp3 -- 0005.mp3
   Descrição do Produto
   
  [+]0006.mp3 => Obrigado pela Compra
  [+]0007.mp3 => Aparelho Iniciado
  [+]0008.mp3 => Produto 1
  [+]0009.mp3 => Produto 2
  [+]0010.mp3 => Produto 3
  [+]0011.mp3 => Produto 4
  [+]0012.mp3 => Produto 5
  [+]0013.mp3 => Obrigado e volte sempre
  [+]0014.mp3 => Você comprou
  
*/
#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>  //ESP8266 Core WiFi Library         
#else
#include <WiFi.h>      //ESP32 Core WiFi Library    
#endif

//needed for library
#include <DNSServer.h> //Local DNS Server used for redirecting all requests to the configuration portal ( https://github.com/zhouhan0126/DNSServer---esp32 )
#if defined(ESP8266)
#include <ESP8266WebServer.h> //Local WebServer used to serve the configuration portal
#else
#include <WebServer.h> //Local WebServer used to serve the configuration portal ( https://github.com/zhouhan0126/WebServer-esp32 )
#endif
#include <WiFiManager.h>   // WiFi Configuration Magic ( https://github.com/zhouhan0126/WIFIMANAGER-ESP32 ) >> https://github.com/tzapu/WiFiManager (ORIGINAL)


#define pinChaveCompra 0
#define pinChave01 2 
#define pinChave02 14 
#define pinChave03 12
#define pinChave04 13
#define pinChave05 3


SoftwareSerial mp3Serial(D1, D2); // RX, TX



bool shouldSaveConfig = false;

const char* ssid = "Netfacil_5GHz";
const char* pass = "*******";

const char* host = "www.mssistemasbr.com.br";

float sensor1 = 0;
float sensor2 = 0;
float sensor3 = 0;
String line, line2;

bool  armazena_1 = false;
bool  armazena_2 = false;
bool bContinue = true;
bool bDeuCerto = false;
char input= 0;
int cnt=10;

String nomewifi = "Vendine_natura";
String ipLocal="";
String idMachine = "65";

void setup() {
  Serial.begin(9600);
  
    //declaração do objeto wifiManager
  WiFiManager wifiManager;
  //utilizando esse comando, as configurações são apagadas da memória
  //caso tiver salvo alguma rede para conectar automaticamente, ela é apagada.
  //  wifiManager.resetSettings();
  
  //--------------------------------------------------------------------------------------------

  //por padrão as mensagens de Debug vão aparecer no monitor serial, caso queira desabilitá-la
  //utilize o comando setDebugOutput(false);
  //  wifiManager.setDebugOutput(false);

  //--------------------------------------------------------------------------------------------

  //caso queira iniciar o Portal para se conectar a uma rede toda vez, sem tentar conectar 
  //a uma rede salva anteriormente, use o startConfigPortal em vez do autoConnect
  //  wifiManager.startConfigPortal(char const *apName, char const *apPassword = NULL);

  //--------------------------------------------------------------------------------------------

  //setar IP fixo para o ESP (deve-se setar antes do autoConnect)
  //  setAPStaticIPConfig(ip, gateway, subnet);
  //  wifiManager.setAPStaticIPConfig(IPAddress(192,168,16,2), IPAddress(192,168,16,1), IPAddress(255,255,255,0)); //modo AP

  //--------------------------------------------------------------------------------------------

  //  setSTAStaticIPConfig(ip, gateway, subnet);
  //  wifiManager.setSTAStaticIPConfig(IPAddress(192,168,0,99), IPAddress(192,168,0,1), IPAddress(255,255,255,0)); //modo estação

  //callback para quando entra em modo de configuração AP
  wifiManager.setAPCallback(configModeCallback); 
  //callback para quando se conecta em uma rede, ou seja, quando passa a trabalhar em modo estação
  wifiManager.setSaveConfigCallback(saveConfigCallback); 

  wifiManager.autoConnect("Vendine_natura","mUd@r@@159753.456"); //cria uma rede sem senha
  //wifiManager.autoConnect(); //gera automaticamente o SSID com o chip ID do ESP e sem senha

  //  wifiManager.setMinimumSignalQuality(10); // % minima para ele mostrar no SCAN

  //wifiManager.setRemoveDuplicateAPs(false); //remover redes duplicadas (SSID iguais)

  //wifiManager.setConfigPortalTimeout(10); //timeout para o ESP nao ficar esperando para ser configurado para sempre
  
  mp3Serial.begin (9600);
  
  pinMode(pinChave01, INPUT_PULLUP);
  pinMode(pinChave02, INPUT_PULLUP);
  pinMode(pinChave03, INPUT_PULLUP);
  pinMode(pinChave04, INPUT_PULLUP);
  pinMode(pinChave05, INPUT_PULLUP);
  pinMode(pinChaveCompra, INPUT_PULLUP);
   
  // Mp3
  mp3_set_serial(mp3Serial);  
  delay(100); 
  mp3_set_volume(25);
  
  mp3_play(7);
  
  
  
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("");
    Serial.println("WiFi conectado!");
    Serial.println("Endereco IP: ");
    Serial.println(WiFi.localIP());  
    ipLocal= String(WiFi.localIP().toString());
  }

}

int bTocando01=0;
int bTocando02=0;
int bTocando03=0;
int bTocando04=0;
int bTocando05=0;
int bTocando06=0;

bool bCompra1=false;
bool bCompra2=false;
bool bCompra3=false;
bool bCompra4=false;
bool bCompra5=false;

int vcontainer_01=1;
int vcontainer_02=1;
int vcontainer_03=1;
int vcontainer_04=1;
int vcontainer_05=1;
int vstatusbotao=1;

void loop() {

   WiFiManager wifiManager;
  ////////////////////////////////////////////////////////////////
  // pino1 - Sensor 1 - j
  ////////////////////////////////////////////////////////////////
  if (digitalRead(pinChave01) == LOW)
  {
    Serial.println("Não tem produto - pinchave01");
    
    if (bTocando01==0)
    {
    mp3_play(1);
    bTocando01=1;
    }

    bCompra1=true;
    vcontainer_01=0;
  }
  else
  {
    Serial.println("tem produto - pinchave01");
    bTocando01=0;
    bCompra1=false;
	vcontainer_01=1;
  }


    ////////////////////////////////////////////////////////////////
    // pino2 - Sensor 2 - k
  ////////////////////////////////////////////////////////////////
  if (digitalRead(pinChave02) == LOW)
  {
    Serial.println("Não tem produto - pinchave02");
    
    if (bTocando02==0)
    {
    mp3_play(2);
    bTocando02=1;
    }
    bCompra2=true;
    vcontainer_02=0;
  }
  else
  {
    Serial.println("tem produto - pinchave02");
    bTocando02=0;
    bCompra2=false;
    vcontainer_02=1;
  }
  
 

  ////////////////////////////////////////////////////////////////
    // pino3 - Sensor 3 - l
  ////////////////////////////////////////////////////////////////
  if (digitalRead(pinChave03) == LOW)
  {
    Serial.println("Não tem produto - pinchave03");

    if (bTocando03==0)
    {
    mp3_play(3);
    bTocando03=1;
    }
  
    bCompra3=true;
    vcontainer_03=0;
  }
  else
  {
    Serial.println("tem produto - pinchave03");
    bTocando03=0;
    bCompra3=false;
	vcontainer_03=1;
  }
   
  
  ////////////////////////////////////////////////////////////////
    // pino4 - Sensor 4 - m
  ////////////////////////////////////////////////////////////////
  if (digitalRead(pinChave04) == LOW)
  {
    Serial.println("Não tem produto - pinchave04");
    
    
    if (bTocando04==0)
    {
    mp3_play(4);
    bTocando04=1;
    }
    bCompra4=true;
	vcontainer_04=0;
    
  }
  else
  {
    Serial.println("tem produto - pinchave04");
    bTocando04=0;
    bCompra4=false;
	vcontainer_04=1;
  }
    
  
  if (digitalRead(pinChave05) == LOW)
  {
    Serial.println("Não tem produto - pinchave05");
    
    
    if (bTocando05==0)
    {
    mp3_play(5);
    bTocando05=1;
    }
    bCompra5=true;
	vcontainer_05=0;
  }
  else
  {
    Serial.println("tem produto - pinchave05");
    bTocando05=0;
    bCompra5=false;
	vcontainer_05=1;
  }
  
  
  if (digitalRead(pinChaveCompra) == LOW)
  {
    Serial.println("Não tem produto - pinchave06");
    vstatusbotao=0;
    
    if (bTocando06==0)
    {
  
    if ( (bCompra1==true) || (bCompra2==true) || (bCompra3==true) || (bCompra4==true) || (bCompra5==true) )
    {
      mp3_play(14);
    delay(3800);
    if (bCompra1==true)
    {
      mp3_play(8);
      delay(4000);
    }
    if (bCompra2==true)
    {
      mp3_play(9);
      delay(4000);
    }
    if (bCompra3==true)
    {
      mp3_play(10);
      delay(4000);
    }
    if (bCompra4==true)
    {
      mp3_play(11);
      delay(4000);
    }
    if (bCompra5==true)
    {
      mp3_play(12);
      delay(7000);
    }
    mp3_play(13);
    delay(2000);

    }
    bTocando06=1;
    }
	
	enviaInformacao();
  
  }
  else
  {
    Serial.println("tem produto - pinchave06");
    bTocando06=0;
	vstatusbotao=1;
  }
  
  delay(100);
}


//callback que indica que o ESP entrou no modo AP
void configModeCallback (WiFiManager *myWiFiManager) {  
  //  Serial.println("Entered config mode");
  Serial.println("Entrou no modo de configuração");
  Serial.println(WiFi.softAPIP()); //imprime o IP do AP
  Serial.println(myWiFiManager->getConfigPortalSSID()); //imprime o SSID criado da rede
}

//callback que indica que salvamos uma nova rede para se conectar (modo estação)
void saveConfigCallback () {
  //  Serial.println("Should save config");
  Serial.println("Configuração salva");
  Serial.println(WiFi.softAPIP()); //imprime o IP do AP
}

void enviaInformacao(){


    Serial.print("connectado com ");
    Serial.println(host);

    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("Falha na conexao...");
      return;    
    } 
    else
    {
    bDeuCerto=true;
     
    }
	  
    String url = "/xxxx/webservice.php?";      
	  url += "&vcontainer_01=";
      url += vcontainer_01;      
	  url += "&vcontainer_02=";
      url += vcontainer_02;	  
	  url += "&vcontainer_03=";
      url += vcontainer_03;	  
	  url += "&vcontainer_04=";
      url += vcontainer_04;	  
	  url += "&vcontainer_05=";
      url += vcontainer_05;	  
	  url += "&vstatusbotao=";
      url += vstatusbotao;
	      
    
    Serial.print("Request URL...");
    Serial.println(url);
    
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
           "Host: " + host + "\r\n" +
           "Connection: close\r\n\r\n");


  
    unsigned long timeout = millis();
    while (client.available() == 0) 
  {
    if (millis() - timeout > 5000) 
    {
      Serial.println(" >>> Client TimeOUT!!!");
      client.stop();
      return;
    }
  }
    
    
    while (client.available()) 
  {
    //line = client.readStringUntil('\r');
    //Serial.print(line); 
    
    char ch = static_cast<char>(client.read());
    Serial.print(ch);
    }
  
  
    Serial.println();
    Serial.println("Fechando conexao....");
  client.stop();
}