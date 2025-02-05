Configura o temporizador de hardware para chamar a função de callback a cada 1 segundo.

    Inicialmente, as bibliotecas necessárias são declaradas: a stdio.h, biblioteca padrão da linguagem C, pico/stdlib.h, biblioteca
    padrão da Raspberry Pi Pico e o microcontrolador RP2040, e hardware/timer.h, necessária para a utilização de temporizadores de hardware na Raspberry Pi Pico.

    Após isso, foram definidos os pinos dos LEDs utilizados na tarefa: vermelho (pino 11), amarelo (pino 12) e verde (pino 13). Além disso, foi necessária uma variável chamada state para rastrear o estado atual dos LEDs e facilitar ligar eles na ordem correta na função de callback.

    Na função repeating_timer_callback, todos os LEDs são desligados, e a variável state define a ordem da ligação dos LEDS (Vermelho: state == 0; Amarelo: state == 1; Verde: state == 2 ) com o retorno true para garantir que continuasse se repetindo.

    No int main, a função stdio_init_all() inicializa a comunicação, e todos os pinos dos LEDs são inicializados e definidos como sáidas, a estrutura de temporizador de repetição é declarada e o temporizador é configurado para chamar a função de callback a cada 3 segundos. No loop infinito, foi definido que toda vez que 1 segundo se passase, a mensagem "1 segundo" aparecesse no monitor serial.