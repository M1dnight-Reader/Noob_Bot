#define Trig 8
#define Echo 9
const int in1 = 2; // IN4 pin 2
const int in2 = 4; // IN3 pin 4
const int in3 = 5; // IN2 pin 5
const int in4 = 7; // IN1 pin 7
int ENB1 = 3;
int ENA2 = 6;
void setup()
{
pinMode(Trig, OUTPUT); // выход
pinMode(Echo, INPUT); // вход
pinMode(in1, OUTPUT); // выход на L298n
pinMode(in2, OUTPUT); // выход на L298n
pinMode(in3, OUTPUT); // выход на L298n
pinMode(in4, OUTPUT); // выход на L298n
pinMode (ENB1, OUTPUT);
pinMode (ENA2, OUTPUT);
}
unsigned int impulseTime=0;
unsigned int distance_sm=0;
void loop()
{
digitalWrite(Trig, HIGH);
delayMicroseconds(10); // 10 микросекунд
digitalWrite(Trig, LOW);
impulseTime=pulseIn(Echo, HIGH); // замеряем длину импульса
distance_sm=impulseTime/58; // переводим в сантиметры
if (distance_sm>20) // если расстояние более 20 сантиметров
{
digitalWrite(in1, HIGH);
delay(300);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
delay(300);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(ENB1,250);
analogWrite(ENA2,250);
}
else
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
delay(500);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(ENB1,250);
analogWrite(ENA2,250);
delay(200);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(ENB1,250);
analogWrite(ENA2,250);
delay(100);
}
delay(50);
}