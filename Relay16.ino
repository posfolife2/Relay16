#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEC };   //physical mac address
byte ip[] = { 192, 168, 1, 241 };                      // ip in lan (that's what you need to use in your browser. ("192.168.1.240")
byte gateway[] = { 192, 168, 1, 1 };                   // internet access via router
byte subnet[] = { 255, 255, 255, 0 };                  //subnet mask

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

String readString;

int led1 = 22;
int led2 = 23;
int led3 = 24;
int led4 = 25;
int led5 = 26;
int led6 = 27;
int led7 = 28;
int led8 = 29;
int led9 = 30;
int led10 = 31;
int led11 = 32;
int led12 = 33;
int led13 = 34;
int led14 = 35;
int led15 = 36;
int led16 = 37;


void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(led14, OUTPUT);
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
  digitalWrite(led13, HIGH);
  digitalWrite(led14, HIGH);
  digitalWrite(led15, HIGH);
  digitalWrite(led16, HIGH);


// Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  dht.begin();

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() { 
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
        }
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
   client.println("Refresh: 30");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
           client.println("<br />");  
           client.println("<a href=\"/?button1on\"\">Hallway ON</a>");
           client.println("<a href=\"/?button1off\"\">Hallway OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button2on\"\">Bath Ceiling ON</a>");
           client.println("<a href=\"/?button2off\"\">Bath Ceiling OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button3on\"\">Bath Vanity ON</a>");
           client.println("<a href=\"/?button3off\"\">Bath Vanity OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button4on\"\">MJ's Closet ON</a>");
           client.println("<a href=\"/?button4off\"\">MJ's Closet OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button5on\"\">Kitchen S ON</a>");
           client.println("<a href=\"/?button5off\"\">Kitchen S OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button6on\"\">Kitchen N ON</a>");
           client.println("<a href=\"/?button6off\"\">Kitchen N OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button7on\"\">Up Bed S ON</a>");
           client.println("<a href=\"/?button7off\"\">Up Bed S OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button8on\"\">Up Bed N ON</a>");
           client.println("<a href=\"/?button8off\"\">Up Bed N OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button9on\"\">Livingroom ON</a>");
           client.println("<a href=\"/?button9off\"\">Livingroom OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button10on\"\">MJ's Projector ON</a>");
           client.println("<a href=\"/?button10off\"\">MJ's Projector OFF</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button11on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button11off\"\">Turn Off LED</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button12on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button12off\"\">Turn Off LED</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button13on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button13off\"\">Turn Off LED</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button14on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button14off\"\">Turn Off LED</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button15on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button15off\"\">Turn Off LED</a><br />");   
           client.println("<br />");     
           client.println("<br />");  
           client.println("<a href=\"/?button16on\"\">Turn On LED</a>");
           client.println("<a href=\"/?button16off\"\">Turn Off LED</a><br />");   
           client.println("<br />");     
           client.println("<p> Jacob D Johnson 03/20/2016</p>");  
           client.println("<br />"); 
           
                
         
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
               //controls the Arduino if you press the buttons
           if (readString.indexOf("?button1on") >0){
               digitalWrite(led1, LOW);
           }
           if (readString.indexOf("?button1off") >0){
               digitalWrite(led1, HIGH);
           }
           if (readString.indexOf("?button2on") >0){
               digitalWrite(led2, LOW);
           }
           if (readString.indexOf("?button2off") >0){
               digitalWrite(led2, HIGH);
           }
           if (readString.indexOf("?button3on") >0){
               digitalWrite(led3, LOW);
           }
           if (readString.indexOf("?button3off") >0){
               digitalWrite(led3, HIGH);
           }
           if (readString.indexOf("?button4on") >0){
               digitalWrite(led4, LOW);
           }
           if (readString.indexOf("?button4off") >0){
               digitalWrite(led4, HIGH);
           }
           if (readString.indexOf("?button5on") >0){
               digitalWrite(led5, LOW);
           }
           if (readString.indexOf("?button5off") >0){
               digitalWrite(led5, HIGH);
           }
           if (readString.indexOf("?button6on") >0){
               digitalWrite(led6, LOW);
           }
           if (readString.indexOf("?button6off") >0){
               digitalWrite(led6, HIGH);
           }
           if (readString.indexOf("?button7on") >0){
               digitalWrite(led7, LOW);
           }
           if (readString.indexOf("?button7off") >0){
               digitalWrite(led7, HIGH);
           }
           if (readString.indexOf("?button8on") >0){
               digitalWrite(led8, LOW);
           }
           if (readString.indexOf("?button8off") >0){
               digitalWrite(led8, HIGH);
           }
           if (readString.indexOf("?button9on") >0){
               digitalWrite(led9, LOW);
           }
           if (readString.indexOf("?button9off") >0){
               digitalWrite(led9, HIGH);
           }
           if (readString.indexOf("?button10on") >0){
               digitalWrite(led10, LOW);
           }
           if (readString.indexOf("?button10off") >0){
               digitalWrite(led10, HIGH);
           }
           if (readString.indexOf("?button11on") >0){
               digitalWrite(led11, LOW);
           }
           if (readString.indexOf("?button11off") >0){
               digitalWrite(led11, HIGH);
           }
           if (readString.indexOf("?button12on") >0){
               digitalWrite(led12, LOW);
           }
           if (readString.indexOf("?button12off") >0){
               digitalWrite(led12, HIGH);
           }
           if (readString.indexOf("?button13on") >0){
               digitalWrite(led13, LOW);
           }
           if (readString.indexOf("?button13off") >0){
               digitalWrite(led13, HIGH);
           }
           if (readString.indexOf("?button14on") >0){
               digitalWrite(led14, LOW);
           }
           if (readString.indexOf("?button14off") >0){
               digitalWrite(led14, HIGH);
           }
           if (readString.indexOf("?button15on") >0){
               digitalWrite(led15, LOW);
           }
           if (readString.indexOf("?button15off") >0){
               digitalWrite(led15, HIGH);
           }
           if (readString.indexOf("?button16on") >0){
               digitalWrite(led16, LOW);
           }
           if (readString.indexOf("?button16off") >0){
               digitalWrite(led16, HIGH);
           }
            //clearing string for next read
            readString="";  

  }
}
