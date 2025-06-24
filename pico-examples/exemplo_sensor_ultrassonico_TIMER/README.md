# 📡 Sensor Ultrassônico HC-SR04 com Raspberry Pi Pico W

Este projeto mede a distância de objetos utilizando um sensor ultrassônico **HC-SR04** conectado ao **Raspberry Pi Pico W**, utilizando o **Pico SDK em C**.

---

## 🧠 Funcionamento

- O Raspberry Pi Pico W envia um pulso de **10 µs** ao pino TRIG do sensor HC-SR04.  
- O sensor retorna um pulso no pino ECHO com duração proporcional à distância do objeto.  
- O tempo é convertido em centímetros e exibido no terminal a cada **500 ms**.

---

## 🧩 Funções Principais

- `enviar_pulso_ultrassonico()`: dispara o pulso de 10 µs no pino TRIG.  
- `medir_tempo_echo()`: mede a duração do pulso ECHO em microssegundos.  
- `medir_distancia_cm()`: converte o tempo em distância (cm), baseado na velocidade do som.

---

## 🔌 Conexões

| Sensor HC-SR04 | Pico GPIO |
|----------------|-----------|
| VCC            | 5V        |
| GND            | GND       |
| TRIG           | GP28      |
| ECHO           | GP27      |

---

## 🔧 Circuito

### Simulação no Wokwi

![Circuito do projeto em simulação no WOKWI](Simulacao.png)
