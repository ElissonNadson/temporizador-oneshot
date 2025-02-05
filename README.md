# Temporizador One Shot - Disparo Único

Este projeto demonstra o uso de um temporizador de disparo único com o Pico SDK, utilizando a função `add_alarm_in_ms()`. Ao pressionar um botão, os LEDs são acionados e, em sequência, desligados com intervalos de 3 segundos.

## Funcionalidades

- **Acionamento por Botão:**  
  Ao pressionar o botão (GPIO 5), os 3 LEDs são imediatamente ligados.

- **Sequência de Desligamento:**  
  Após a ativação:
  - **3 s:** Desliga o LED azul;
  - **6 s:** Desliga o LED vermelho;
  - **9 s:** Desliga o LED verde, finalizando a sequência.

- **Controle de Reentrada:**  
  A variável de controle (`is_running`) garante que uma nova sequência só possa ser iniciada após a conclusão da anterior.

- **Debounce de Software:**  
  Implementado um delay de 50 ms para evitar múltiplos acionamentos indesejados do botão.

- **Feedback Serial com Ícones:**  
  Mensagens ilustradas (ex.: "🔵", "🔴", "🟢") são impressas no terminal para indicar o estado de cada LED.

- **Experimento com LED RGB:**  
  O circuito utiliza um LED RGB (conectado aos GPIOs 11, 12 e 13) e o botão A (GPIO 05) conforme a simulação sugerida.

## Componentes Utilizados

- **Microcontrolador:** Raspberry Pi Pico W
- **LEDs:** 3 LEDs (no diagrama representados como azul, vermelho e verde)
- **Resistores:** 3 resistores de 330 Ω
- **Botão:** Pushbutton
- **Simulador:** Wokwi integrado ao VS Code

## Requisitos e Ambiente

- Ambiente de desenvolvimento: VS Code com integração ao simulador Wokwi.
- Pico SDK configurado corretamente.
- Repositório versionado no GitHub.

## Instruções de Uso


1. **Clone o Repositório:**

   ```bash
   git clone https://github.com/ElissonNadson/temporizador-oneshot.git
   cd temporizador-oneshot
Abra o Projeto no VS Code:
Verifique a integração com o simulador Wokwi.

Compile e Simule:
Compile o código em C e inicie a simulação.
Inicialmente, os LEDs permanecem apagados. Ao pressionar o botão (simulado no circuito), os LEDs se acenderão e serão desligados gradualmente conforme os intervalos de 3 segundos, com mensagens na porta serial indicando cada mudança.

Verificação:
Utilize o Serial Monitor para acompanhar os prints e a sequência de acionamento dos LEDs.

Fluxo do projeto

![Untitled Diagram (9)](https://github.com/user-attachments/assets/42dc3e2d-3ff3-47ee-875a-36b1ea0b04ab)

