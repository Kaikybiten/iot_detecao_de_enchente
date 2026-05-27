# 🌊 Sistema IoT para Detecção de Enchentes com ESP32

Sistema desenvolvido utilizando o microcontrolador ESP32, sensor ultrassônico HC-SR04 e protocolo MQTT para monitoramento do nível da água em tempo real. O projeto tem como objetivo detectar possíveis enchentes e gerar alertas automáticos em situações críticas.

---

# 📌 Objetivo

O projeto foi desenvolvido com foco em aplicações de Internet das Coisas (IoT), permitindo:

- Monitoramento contínuo do nível da água;
- Envio de dados em tempo real utilizando MQTT;
- Acionamento de alerta sonoro em situações críticas;
- Simulação completa em ambiente virtual utilizando Wokwi.

---

# 🛠 Tecnologias Utilizadas

- ESP32
- HC-SR04
- MQTT
- HiveMQ
- Arduino IDE
- Linguagem C/C++
- Wokwi Simulator

---

# 📡 Funcionamento do Sistema

O sensor HC-SR04 realiza medições contínuas da distância entre o sensor e a superfície da água.

O ESP32 processa os dados obtidos e:

- publica as medições no tópico MQTT `enchente/nivel`;
- verifica se o nível está crítico;
- aciona um buzzer caso a distância seja inferior ao limite definido;
- envia um alerta no tópico MQTT `enchente/alerta`.

---

# 📂 Estrutura MQTT

## Tópicos utilizados

| Tópico | Função |
|---|---|
| `enchente/nivel` | Envio contínuo do nível da água |
| `enchente/alerta` | Envio de alertas críticos |

## Exemplo de mensagens

### Tópico: `enchente/nivel`

```text
127 centimetros
28 centimetros
14 centimetros

# ⚙️ Hardware Utilizado

| Componente | Quantidade |
|---|---|
| ESP32 DevKit V4 | 1 |
| HC-SR04 | 1 |
| Buzzer | 1 |
| Resistores 1kΩ | 2 |

---

# 🔌 Ligações do Circuito

## HC-SR04 → ESP32

| HC-SR04 | ESP32 |
|---|---|
| TRIG | GPIO 13 |
| ECHO | GPIO 27 |
| VCC | 5V |
| GND | GND |

---

## Buzzer → ESP32

| Buzzer | ESP32 |
|---|---|
| Positivo | GPIO 23 |
| Negativo | GND |

> O pino ECHO do HC-SR04 foi conectado ao ESP32 utilizando divisor de tensão para adequação do sinal de 5V para 3,3V.

---

# ▶️ Como Executar

## 1. Clone o repositório

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
```

---

## 2. Instale as bibliotecas necessárias

Biblioteca utilizada:

```text
PubSubClient
```

Na Arduino IDE:

```text
Sketch > Include Library > Manage Libraries
```

Pesquise por:

```text
PubSubClient
```

---

## 3. Configure a rede Wi-Fi

No código:

```cpp
const char* ssid = "Wokwi-GUEST";
const char* password = "";
```

Substitua pelos dados da sua rede caso utilize hardware físico.

---

## 4. Execute no Wokwi

Importe:
- o arquivo `.ino`;
- o arquivo `diagram.json`.

---

# 🚨 Critério de Alerta

| Distância medida | Situação |
|---|---|
| > 50 cm | Seguro |
| 20–50 cm | Alerta |
| < 20 cm | Crítico |

---

# 🌐 Broker MQTT

Broker utilizado:

```text
broker.hivemq.com
```

Porta:

```text
1883
```
