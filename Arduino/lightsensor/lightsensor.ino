/*
光敏电阻检测环境光
[url]http://www.arduino.cn/[/url]
*/
 
void setup()
{
  // 初始化串口
  Serial.begin(9600);
}
void loop() 
{
// 读出当前光线强度，并输出到串口显示
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);
}
