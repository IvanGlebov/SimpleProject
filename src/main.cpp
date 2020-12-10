// Данная строка нужна только если вы собираетесь компилировать 
// данный код в Visual Studio Code с расширением PlatformIO
#include <Arduino.h>
// ---------------------//


// Библиотеки для работы Blynk
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


// Таймер для отправки данных
BlynkTimer send1;


// Аутентификационный ключ для конкретного приложения Blynk(смотрится в настройках устройства в Blynk)
char auth[] = "";
// Имя точки доступа, к которой будет совершаться подключение
char ssid[] = ""; 
// Пароль точки доступа, к которой будет совершаться подключение
char pass[] = "";


// Получение значения с платформы Blynk
BLYNK_WRITE(V1){
  int a = param.asInt();
  Serial.println("V1 value : " + String(a));
}


// Прототип функции отправки данных
void sendData();


void setup() {
  // Скорость Serial-подключения ставим равной 115200 бод
  Serial.begin(115200);
  // Настраиваем таймер на срабатывание каждую секунду
  send1.setInterval(1000L, sendData);
  // Покдлючаемся к публичному серверу Blynk через указанную выше WiFi точку доступа
  Blynk.begin(auth, ssid, pass);
}


void loop() {
  // Запускаем работу Blynk
  Blynk.run();
  // Запуск отправки данных по таймеру каждую секунду
  send1.run();
}


// Тело функции отправки данных на Blynk
void sendData(){
  // Отправляем на порт V2 значение 1122
  Blynk.virtualWrite(V2, 1122);
}