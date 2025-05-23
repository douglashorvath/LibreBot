#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Definição dos pinos dos motores
#define RPWM_M1 14  // Motor 1: Horário
#define LPWM_M1 27  // Motor 1: Anti-horário
#define RPWM_M2 12  // Motor 2: Horário
#define LPWM_M2 13  // Motor 2: Anti-horário

String inputString = "";
bool engage = false;
int velocidade = 0;
int direcao = 0;

// Fine tuning dos motores
float correcaoMotorEsq = 1.00;
float correcaoMotorDir = 1.00;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Robo");

  pinMode(RPWM_M1, OUTPUT);
  pinMode(LPWM_M1, OUTPUT);
  pinMode(RPWM_M2, OUTPUT);
  pinMode(LPWM_M2, OUTPUT);

  stopMotors();
  Serial.println("Sistema iniciado com lógica corrigida.");
}

void loop() {
  while (SerialBT.available()) {
    char c = SerialBT.read();
    if (c == '\n' || c == '\r') {
      processCommand(inputString);
      inputString = "";
    } else {
      inputString += c;
    }
  }

  if (engage) {
    moveRobo(velocidade, direcao);
  } else {
    stopMotors();
  }
}

void processCommand(String cmd) {
  cmd.trim();
  if (cmd.startsWith("s1 ")) {
    direcao = constrain(cmd.substring(3).toInt(), -100, 100);
    Serial.print("Direção: ");
    Serial.println(direcao);
  } else if (cmd.startsWith("s2 ")) {
    velocidade = constrain(cmd.substring(3).toInt(), -100, 100);
    Serial.print("Velocidade: ");
    Serial.println(velocidade);
  } else if (cmd == "eng") {
    engage = !engage;
    Serial.print("Engage: ");
    Serial.println(engage ? "ATIVADO" : "DESATIVADO");
  } else {
    Serial.print("Comando desconhecido: ");
    Serial.println(cmd);
  }
}

void moveRobo(int vel, int dir) {
  int pwmEsq = 0;
  int pwmDir = 0;

  if (vel != 0) {
    int pwmBase = map(abs(vel), 0, 100, 0, 255);
    float fator = constrain(abs(dir) / 100.0, 0.0, 1.0);

    pwmEsq = pwmBase;
    pwmDir = pwmBase;

    if (dir > 0) {
      // Virando pra direita → reduz lado DIREITO (motor M2)
      pwmDir = pwmBase * (1.0 - fator);
    } else if (dir < 0) {
      // Virando pra esquerda → reduz lado ESQUERDO (motor M1)
      pwmEsq = pwmBase * (1.0 - fator);
    }

    // Aplicando o sentido (frente ou ré)
    pwmEsq *= (vel > 0 ? 1 : -1);
    pwmDir *= (vel > 0 ? 1 : -1);
  }

  else if (dir != 0) {
    // Giro no próprio eixo (velocidade = 0, direção ≠ 0)
    int pwmGiro = map(abs(dir), 0, 100, 0, 255);
    if (dir > 0) {
      pwmEsq = -pwmGiro; // M1: ré
      pwmDir = pwmGiro;  // M2: frente
    } else {
      pwmEsq = pwmGiro;  // M1: frente
      pwmDir = -pwmGiro; // M2: ré
    }
  }

  // Fine tuning
  pwmEsq *= correcaoMotorEsq;
  pwmDir *= correcaoMotorDir;

  // Aplicar nos motores
  setMotor(RPWM_M1, LPWM_M1, pwmEsq);
  setMotor(RPWM_M2, LPWM_M2, pwmDir);
}

void setMotor(int pinHor, int pinAnti, int pwm) {
  pwm = constrain(pwm, -255, 255);
  if (pwm > 0) {
    analogWrite(pinHor, pwm);
    analogWrite(pinAnti, 0);
  } else if (pwm < 0) {
    analogWrite(pinHor, 0);
    analogWrite(pinAnti, -pwm);
  } else {
    analogWrite(pinHor, 0);
    analogWrite(pinAnti, 0);
  }
}

void stopMotors() {
  setMotor(RPWM_M1, LPWM_M1, 0);
  setMotor(RPWM_M2, LPWM_M2, 0);
}
