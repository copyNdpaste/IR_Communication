#include "IRSendRev.h"
void setup() {
Serial.begin(9600);
IR.Init();//.cpp에 있는 IR을 초기화한다.
}
String inc;//입력한 문자를 받는 문자열을 선언한다.
int len;//문자열의 길이를 받는 변수이다.
unsigned char d[15] = {0,70,70,20,60,0,0,0,0,0,0,0,0,0,0};//각 요소는 차례대로 보내질 데이터의 길이, start의 논리 high,low의 지속 시간, mark와 space의 길이, 보내질 데이터의 길이, 보내질 데이터이다.
void loop() {
  if(Serial.available()>0){//읽을 수 있는 byte의 수가 0보다 크면
    inc = Serial.readString();//입력된 문자를 읽는다.
    len = inc.length();//문자의 길이를 받는다.
    d[0]=len+5;//보내는데 필요한 전체 바이트 수를 입력한다.
    d[5]=len;//문자의 길이를 입력한다.
    for(int i=0; i<len; i++){//문자의 길이만큼
      d[i+6] = inc[i];//보낼 문자를 넣는다.
      }
      IR.Send(d,38);//38kHz의 주파수로 입력된 문자를 보낸다.
      }
}
