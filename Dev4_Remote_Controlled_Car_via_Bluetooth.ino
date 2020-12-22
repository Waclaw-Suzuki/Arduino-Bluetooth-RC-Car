#define in1 4
#define in2 5
#define in3 6
#define in4 7
// В контроллере моторов L298 для активации моторов нужно подать сигналы на пины ena и enb либо поставить джамперы
// Аналоговые пины Arduino Uno, Nano, Mini - 3, 5, 6, 9, 10, 11
#define ena 9
#define enb 10

int val;
int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  analogWrite(ena, 60); // Установить начальную скорость мотора 1
  analogWrite(enb, 60); // Установить начальную скорость мотора 2

  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
  
  if (Serial.available())
  {
    val = Serial.read(); // Считывает сигнал Bluetooth
    Serial.write(val); // Пишет получаемый сигнал Bluetooth в Serial monitor
    
    // При символе "S" (Stop)
    if ( val == 'S')
    {
      digitalWrite(LED, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    // При символе "F" (Forward)
    if (val == 'F')
    {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    // При символе "B" (Backward)
    if (val == 'B')
    {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    // При символе "L" (Left)
    if (val == 'L')
    {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    // При символе "R" (Right)
    if (val == 'R')
    {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

    // SPEED CONTROL:
    // При символе "1"
    if ( val == '1')
    {
    analogWrite(ena, 60);
    analogWrite(enb, 60);
    }
    // При символе "2"
    if ( val == '2')
    {
    analogWrite(ena, 80);
    analogWrite(enb, 80);
    }
    // При символе "3"
    if ( val == '3')
    {
    analogWrite(ena, 100);
    analogWrite(enb, 100);
    }
    // При символе "4"
    if ( val == '4')
    {
    analogWrite(ena, 120);
    analogWrite(enb, 120);
    }
    // При символе "5"
    if ( val == '5')
    {
    analogWrite(ena, 140);
    analogWrite(enb, 140);
    }
    // При символе "6"
    if ( val == '6')
    {
    analogWrite(ena, 160);
    analogWrite(enb, 160);
    }
    // При символе "7"
    if ( val == '7')
    {
    analogWrite(ena, 180);
    analogWrite(enb, 180);
    }
    // При символе "8"
    if ( val == '8')
    {
    analogWrite(ena, 200);
    analogWrite(enb, 200);
    }
    // При символе "9"
    if ( val == '9')
    {
    analogWrite(ena, 220);
    analogWrite(enb, 220);
    }
    // При символе "q"
    if ( val == 'q')
    {
    analogWrite(ena, 240);
    analogWrite(enb, 240);
    }
}


// Данный цикл показывает 10 чисел с равным интервалом между ними из промежутка от 60 до 255
/*
float increment_float = (255-60)/10;
int increment = (int) increment_float; // Перевести число с плавающей точкой в целое
for (int code = 60; code < 255; code += increment) {
   Serial.println(code);
   delay(100);
}
*/

// Так по порядку от 32 до 126 показываются коды всех символов (а символы в остальном диапазоне не являются печатаемыми в ASCII )
/*   for (int code = 32; code < 126; code++) {
   Serial.print(code);
   Serial.write(" - ");
   Serial.write(code);
   Serial.write("\n");
   delay(100);
}
*/

}

// Motors control code for example
/*
void stopmotors () {
      digitalWrite(LED, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
void forward () {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
void backward () {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
void left () {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
void right () {
      digitalWrite(LED, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
*/
