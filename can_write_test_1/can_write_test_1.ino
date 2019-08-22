#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;
struct can_frame canMsg2;
struct can_frame canMsg3;
MCP2515 mcp2515(10);


void setup() {

  canMsg1.can_id  = 1522;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0x0;
  canMsg1.data[1] = 0x0;
  canMsg1.data[2] = 0x0;
  canMsg1.data[3] = 0x0;
  canMsg1.data[4] = 0x0;
  canMsg1.data[5] = 0x0;
  canMsg1.data[6] = 0x0;
  canMsg1.data[7] = 0x0;

  canMsg2.can_id  = 1521;
  canMsg2.can_dlc = 8;
  canMsg2.data[0] = 0x00;
  canMsg2.data[1] = 0x00;
  canMsg2.data[2] = 0x00;
  canMsg2.data[3] = 0x00;
  canMsg2.data[4] = 0x00;
  canMsg2.data[5] = 0x00;
  canMsg2.data[6] = 0x00;
  canMsg2.data[7] = 0x00;
   
  canMsg3.can_id  = 1520;
  canMsg3.can_dlc = 8;
  canMsg3.data[0] = 0x00;
  canMsg3.data[1] = 0x00;
  canMsg3.data[2] = 0x00;
  canMsg3.data[3] = 0x00;
  canMsg3.data[4] = 0x00;
  canMsg3.data[5] = 0x00;
  canMsg3.data[6] = 0x00;
  canMsg3.data[7] = 0x00;
  
  while (!Serial);
  Serial.begin(9600);
  SPI.begin();
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_1000KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("Example: Write to CAN");
}

void loop() {
  mcp2515.sendMessage(&canMsg3);
  mcp2515.sendMessage(&canMsg2);
  mcp2515.sendMessage(&canMsg1);
 // mcp2515.sendMessage(&canMsg2);

  Serial.println("Messages sent");
  
  delay(20);

}
