#include<ESP8266WiFi.h>
#include<WiFiClient.h>
extern "C" {
#include<user_interface.h>
};
char ssid[]="AW";
char password[]="hellofriend";
String strLine1="";
String strLine2="";
WiFiServer server(80);
int count=1;

char ssid2[] = "AndroidAP_9664";
char password2[] = "helloworld";
char server2[] = "192.168.43.251";
WiFiClient client2;







void setup() {                             //required for making the node as a server
Serial.begin(115200);
WiFi.mode(WIFI_AP);
WiFi.softAP(ssid,password);
IPAddress ip=WiFi.softAPIP();
Serial.println(ip);
server.begin();
}

void seperation(String s){                //now required to remove the excess part and collect the main part and provide it to serial monitor
 char str[50];
 s.toCharArray(str,50);
 char *str_begin; 
 char *str_end;
 str_begin=strstr(str,"=");
 str_begin+=1;
 str_end=strstr(str_begin,"&");
 Serial.print("Name:");
 while(*str_begin!=*str_end){
  strLine1+=*str_begin;
  str_begin+=1;
  }
  Serial.print(strLine1);
  Serial.println("");
  Serial.print("Roll:");
  str_begin=strstr(str_begin,"=");
  str_end=strstr(str_begin,"&");
  str_begin+=1;
  while(*str_begin!=*str_end){
  strLine2+=*str_begin;
  str_begin+=1;
  }
  Serial.print(strLine2);
  Serial.println("");
  server_connection();
}

void server_connection(){                                  //to connect to the serial monitor and get a server connection and provide the details to my_sql
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid2,password2);
  while ( WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println("Connected to network");
  Serial.println("Starting a connection to server");
  client2.connect(server2,80);
  delay(200);
  if(client2.connected()){
    Serial.println("connected to server");
    delay(5000);
    String url="/mysql_server/insert.php?name="+strLine1+"&roll="+strLine2;
    client2.println("GET /"+url+ " HTTP/1.1");
    client2.println("Host:192.168.43.251");
    client2.println("Connection: close");
    client2.println();
  }
  while(client2.available())
  {
    char c=client2.read();
  }
  delay(5000);
  if(!client2.connected()){
    Serial.println("disconnecting from server.....");
    client2.stop();
    delay(200);
    Serial.println();
  }
}




void loop(){                                      //to get your mobile details and request form http
   WiFiClient client=server.available();
  if(!client){
    return ;
  }
  if(client.connected()){
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<script>");
  client.println("strLine1 = \"\";strLine2 = \"\";");
  client.println("function SendText()");
  client.println("{");
  client.println("nocache = \"&nocache=\" + Math.random() * 1000000;");
  client.println("var request = new XMLHttpRequest();");
  client.println("strLine1 = \"&L1=\" + document.getElementById(\"txt_form\").nam.value;");/*Created by Soun*/client.println("strLine2 = \"&L2=\" + document.getElementById(\"txt_form\").roll.value;");
  client.println("request.open(\"GET\", \"ajax_inputs\" + strLine1 + strLine2 + nocache,true);");
  client.println("request.send(null);");
  client.println("document.write(\"Your request has been processed\");");
  client.println("}");
  client.println("</script>");
  client.println("<html><br><br>");
  client.println("<h4><center>Form Fill up</center></h4></br>");
  client.println("<form id=\"txt_form\" name=\"frmText\">");
  client.println("<label>Name:<input type=\"text\" name=\"nam\" size=\"16\" maxlength=\"16\" /></label></br>");
  client.println("<label> Roll:<input type=\"text\" name=\"roll\" size=\"16\" maxlength=\"16\" /></label>");
  client.println("</form>");
  client.println("<input type=\"submit\" value=\"Send details\" onclick=\"SendText()\" />");
  client.println("</html>");
  String request = client.readStringUntil('\r');
  Serial.print(count);
  Serial.println("."+request);
  count++;
  if(count%2==0&&count!=2)
  {
    seperation(request);
    client.stop();
    setup();
    count=1;
  }
  }
  }

