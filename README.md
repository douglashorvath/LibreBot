
# 🤖 LibreBot

**LibreBot** é uma plataforma de robótica **modular, sustentável e de baixo custo**, ideal para aplicações educacionais, prototipagem e projetos de automação. O projeto utiliza motores de vidro elétrico universais, componentes amplamente disponíveis, peças impressas em 3D e materiais reciclados — promovendo acessibilidade e reaproveitamento de recursos.

---

## 📦 Estrutura do Projeto


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

A plataforma é controlada remotamente usando o app [RoboRemo](https://roboremo.app/) (versão gratuita), configurado com:

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

## 🧩 Estrutura do Projeto

```
LIBREBOT/
├── 3D_models/
│   ├── Base Principal.stl
│   ├── Bracket Bateria 12v (v1).stl
│   ├── Bracket Bateria 12v (v2).stl
│   ├── Caixa Montagem (PowerButton).stl
│   ├── Engrenagem_eixo.stl
│   ├── Engrenagem_motor (fixa).stl
│   ├── Engrenagem_motor (inner_gear).stl
│   ├── Tampa Caixa Montagem (PowerConnector).stl
│   ├── Tampa Montagem Fusível.stl
├── images/
├── src/
│   └── LibreBot_Code.ino
├── LICENSE
└── README.md
```

---

## 📱 Controle Remoto com RoboRemo

Utilizamos o aplicativo **[RoboRemo](https://roboremo.app/)** para controle via Bluetooth, pela sua flexibilidade, leveza e facilidade de configuração.

### Configuração no App:

- **Slider de Velocidade (`s2`)**  
  - Vai de `-100` (ré) a `+100` (frente)  
  - Com retorno automático ao centro  
  - Controla a velocidade máxima dos motores  

- **Slider de Direção (`s1`)**  
  - Vai de `-100` (esquerda) a `+100` (direita)  
  - Com retorno automático ao centro  
  - Controla a diferença de velocidade entre os motores para curvas suaves  

- **Botão Engage**  
  - Texto: `Engage`  
  - Comando enviado: `eng`  
  - Liga/desliga o movimento do robô

Essa interface permite ao operador ter controle preciso e intuitivo do robô, sendo ideal para testes em campo e uso educacional.

---

## ⚙️ Funcionamento do Código

O arquivo `LibreBot_Code.ino` contém toda a lógica embarcada para o controle do robô:

- **Engage/Desengage**: sistema de segurança para evitar acionamentos indesejados.
- **Leitura dos comandos via Bluetooth**: leitura e interpretação dos sliders e botões do RoboRemo.
- **PWM inteligente com curva suave**: cálculo da velocidade dos motores baseado na soma de direção e velocidade.
- **Giro em eixo**: o robô gira no próprio eixo apenas quando está parado e há comando de direção.
- **Fine Tuning**: compensação programável para correção de desbalanceamento entre motores.

---

## 🧩 Impressão 3D

Os arquivos `.stl` localizados na pasta `3D_models/` foram projetados para facilitar a montagem e garantir boa fixação dos motores e componentes elétricos. Todas as peças foram pensadas para impressão com PLA ou PETG em impressoras FDM.

### Recomendações:
- **Resolução**: 0.2mm para engrenagens e suportes, 0,32mm para suportes da bateria
- **Infill**: 100% para engrenagens e 20% ou superior demais peças
- **Suportes**: Não é necessário
- **Nozzle**: As peças foram impressas com nozzle de 0,6mm

---

## 🔌 Esquema de Ligação

As ligações elétricas podem ser feitas de acordo com esquemático em:

```
images/
└── Esquema_de_ligação.png
```

---

## 🔋 Alimentação

O robô pode ser alimentado por:
- Fonte de 12V
- Bateria 12v (Li-ion ou chumbo)

Recomenda-se o uso de um fusível na entrada de alimentação para segurança.

---

## 🧪 Testes Realizados

- Controle remoto via Bluetooth
- Curvas suaves baseadas em diferencial de velocidade
- Giro estático no eixo
- Testes de precisão com motores de vidro elétrico de diferentes fabricantes
- Autonomia de controle e estabilidade
- Testes de carregamento de peso

---

## 📘 Licença

Distribuído sob a **Licença GPL3**. Isso significa que você pode usar, modificar e distribuir este projeto livremente, desde que preserve os devidos créditos.

---

## 👥 Colaboradores

- Douglas Horvath – Desenvolvedor  
- Rafael Seiji Nasso Moreira - Desenvolvedor 
- Rodrigo Vilela - Orientador
- Apoio técnico: FATEC Presidente Prudente  

---

## ✨ Objetivo

O objetivo principal do LibreBot é servir como uma **base de aprendizado, experimentação e utilização industrial** para estudantes, profissionais, hobbystas e entusiastas da robótica que desejam iniciar projetos maiores ou mais complexos a partir de uma fundação simples, robusta e bem documentada.

---

**LibreBot** — Democratizando a robótica com criatividade, sustentabilidade e acessibilidade.
