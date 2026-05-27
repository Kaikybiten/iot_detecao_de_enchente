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
