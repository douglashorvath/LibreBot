# 🤖 LibreBot

**LibreBot** é uma plataforma de robótica de baixo custo, modular e sustentável, ideal para projetos educacionais, prototipagem e desenvolvimento de sistemas autônomos. Desenvolvida com materiais recicláveis, motores de fácil aquisição (como motor de vidro elétrico universal) e componentes eletrônicos amplamente disponíveis, a LibreBot busca democratizar o acesso à robótica e incentivar a criatividade no desenvolvimento de soluções mecatrônicas.

---

## 🚀 Visão Geral

LibreBot é apenas o começo. Esta plataforma foi pensada como **uma base versátil** sobre a qual outros projetos podem ser desenvolvidos. Seja para um robô seguidor de linha, autônomo, controlado por app ou sensor, o LibreBot oferece um chassi robusto e facilmente personalizável com componentes acessíveis.

---

## 🛠️ Componentes Utilizados

- **ESP32** – Microcontrolador principal
- **Motores de vidro elétrico** (modelo universal)
- **Drivers de motor (Ponte H ou módulo customizado)**
- **Engrenagens e suportes impressos em 3D**
- **Rodas recicladas de brinquedos ou carrinhos**
- **Materiais estruturais reaproveitados (ex: MDF, acrílico, alumínio)**
- **Módulo Bluetooth (integrado ao ESP32)**
- **Fonte 12V ou bateria**

---

## 📱 Controle via App RoboRemo

A plataforma é controlada remotamente usando o app [RoboRemo](https://play.google.com/store/apps/details?id=com.hardcoded.roboremo) (versão Joy), configurado com:

- **Slider de Velocidade** (`s2`):  
  - Intervalo: `-100` (ré) a `+100` (frente)  
  - Autoreturn to mid: ativado  
  - Envia comando ao ser movido  

- **Slider de Direção** (`s1`):  
  - Intervalo: `-100` (esquerda) a `+100` (direita)  
  - Autoreturn to mid: ativado  
  - Envia comando ao ser movido  

- **Botão Engage**:  
  - Texto: `Engage`  
  - Ação: `Remote`  
  - Comando enviado: `eng` (ativa/desativa os motores)

---

## 🧠 Funcionamento do Código

O código desenvolvido em C++ para ESP32 possui as seguintes características:

- **Engage**: só permite o movimento quando ativado.
- **Movimentação**:
  - Movimentos frontais/tras em linha reta ou com curva suave.
  - O robô só gira no próprio eixo quando está parado.
- **Compensação** (*Fine Tuning*): permite ajuste de RPM entre os motores para manter trajetória reta.
- **Controle PWM**: os sliders são convertidos em sinais PWM individualizados para cada motor, de acordo com o valor de direção e velocidade recebidos.

---

## 📂 Estrutura do Projeto

```bash
LibreBot/
├── src/
│   └── main.cpp         # Código principal do robô (ESP32)
├── 3D_models/
│   └── engrenagens.stl  # Arquivos de impressão 3D
├── images/
│   └── esquema_bb.png   # Esquema de ligação (Fritzing)
├── README.md            # Você está aqui!
