# Raspberry Pi Pico SDK

O Raspberry Pi Pico SDK (daqui em diante SDK) fornece os cabeçalhos, bibliotecas e o sistema de construção necessários para escrever programas para dispositivos baseados em microcontroladores da série RP, como o Raspberry Pi Pico ou Raspberry Pi pico 2, utilizando as liguagens C, C++ ou em linguagem assembly.

O SDK é projetado para oferecer uma API e um ambiente de programação que sejam  familiares tanto para os desenvolvedores de sistemas embarcados em C quanto para desenvolvedores de C no geral. Um único programa é executado em um dispositivo por vez e começa com um método `main()` convencional. As bibliotecas padrão em C/C++ são compatíveis, assim como as bibliotecas e APIs de baixo nível em C para acessar todo o hardware dos microcontroladores da série RP, incluindo PIO(IO Programável).

Além disso, o SDK disponibiliza bibliotecas de alto nível para lidar com temporizadores, sincronzação, conectividade Wi-Fi e Bluetooth, USB e programação multinúcleo. Essas bibliotecas são abrangentes o suficiente para que o código da sua aplicação raramente, somente se for o caso, precise acessar os registradores do hardware diretamente. Entretanto, se você precisar ou preferir acessar os registradores de hardware diretamente. No entanto, se você precisar ou preferir acessar os registradores de hardware de forma direta, você encontrará também cabeçalhos de definição de registradores completos e totalmente comentados no SDK, sem a necessidade de consultar o datasheet.

O SDK pode ser utilizado para criar desde aplicações simples, ambientes de execução completos como o MicroPython, até softwares de baixo nível, como o prórpio bootrom on-chip do microcontrolador da série RP.

O objetivo do design de todo o SDK é ser simples, mas poderoso.

The design goal for entire SDK is to be simple but powerful.

Bibliotecas/API adicionais que ainda não estão prontas para inclusão no SDK podem ser encontradas no repositório [pico-extras](https://github.com/raspberrypi/pico-extras).

# Documentação

Consulte [Instrodução ao Raspberry Pi Pico-Series](https://rptl.io/pico-get-started) para obter informações sobre como configurar seu hardware, IDE/ambiente e como criar e depurar software para a Raspberry Pi Pico e outros dispositivos baseados em microcontroladores da série RP.

Consulte [Conectando-se à Internet com o Raspberry Pi Pico W](https://rptl.io/picow-connect) para saber mais sobre como escrever aplicativos para seu Raspberry Pi Pico W que conectam à internet.

Consulte [o Raspberry Pi Pico-Series C/C++ SDK](https://rptl.io/pico-c-sdk) para saber mais sobre programação usando o SDK, explorar recursos mais avançados e obter a documentação completa da API em PDF.

Consulte [a documentação da API do Raspberry Pi Pico SDK online](https://rptl.io/pico-doxygen) para obter a documentação da API baseada em HTML.

# Código de exemplo

Consulte [pico-examples](https://github.com/raspberrypi/pico-examples) para exemplos de código que você pode compilar.

# Obtendo o código SDK mais recente

A ramificação [master](https://github.com/raspberrypi/pico-sdk/tree/master/) do `pico-sdk` no GitHub contém a _versão mais estável recente_ do SDK. Se precisar ou quiser testar recursos futuros, você pode experimentar a ramificação [develop](https://github.com/raspberrypi/pico-sdk/tree/develop/).

# Inicie seu próprio projeto

## Usando Visual Studio Code

Você pode instalar a [extensão Raspberry Pi Pico Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico) no VSCode.

## Linha de comando Unix

Essas instruções são extremamente concisas e baseadas apenas em Linux. Para etapas detalhadas, instruções para outras plataformas e informações gerais, recomendamos que você consulte [o SDK C/C++ da série Raspberry Pi Pico](https://rptl.io/pico-c-sdk).

1. Instale o CMake (pelo menos a versão 3.13), Python 3, um compilador nativo e um compilador cruzado GCC.
   ```
   sudo apt install cmake python3 build-essential gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
   ```
2. Configure o seu projeto para usar o Raspberry Pi Pico SDK

   * Você pode clonar o SDK localmente (opção mais comum) :
      1. `git clone` o repositório do Raspberry Pi Pico SDK
      2. Copy [pico_sdk_import.cmake](https://github.com/raspberrypi/pico-sdk/blob/master/external/pico_sdk_import.cmake)
         do SDK para o diretório do seu projeto.
      3. Defina `PICO_SDK_PATH` para o local do SDK em seu ambiente ou passe (`-DPICO_SDK_PATH=`) para o cmake depois.
      4. Configure um `CMakeLists.txt` como:

          ```cmake
          cmake_minimum_required(VERSION 3.13...3.27)

          # initialize the SDK based on PICO_SDK_PATH
          # note: this must happen before project()
          include(pico_sdk_import.cmake)

          project(my_project)

          # initialize the Raspberry Pi Pico SDK
          pico_sdk_init()

          # rest of your project

          ```

   * Ou com o Raspberry Pi Pico SDK como um submódulo :
      1. Clone o SDK como um submódulo chamado `pico-sdk`
      1. Configure um `CMakeLists.txt` como:

          ```cmake
          cmake_minimum_required(VERSION 3.13...3.27)

          # initialize pico-sdk from submodule
          # note: this must happen before project()
          include(pico-sdk/pico_sdk_init.cmake)

          project(my_project)

          # initialize the Raspberry Pi Pico SDK
          pico_sdk_init()

          # rest of your project

          ```

   * Ou com o download automático do GitHub :
      1. Copie [pico_sdk_import.cmake](https://github.com/raspberrypi/pico-sdk/blob/master/external/pico_sdk_import.cmake)
         do SDK para o diretório do seu projeto.
      1. Configure a `CMakeLists.txt` como:

          ```cmake
          cmake_minimum_required(VERSION 3.13)

          # initialize pico-sdk from GIT
          # (note this can come from environment, CMake cache etc)
          set(PICO_SDK_FETCH_FROM_GIT on)

          # pico_sdk_import.cmake is a single file copied from this SDK
          # note: this must happen before project()
          include(pico_sdk_import.cmake)

          project(my_project)

          # initialize the Raspberry Pi Pico SDK
          pico_sdk_init()

          # rest of your project

          ```

   * Ou clonando o SDK localmente, mas sem copiar `pico_sdk_import.cmake`:
       1. `git clone` o repositório do Raspberry Pi Pico SDK.
       2. Configure um `CMakeLists.txt` como:

           ```cmake
           cmake_minimum_required(VERSION 3.13)
 
           # initialize the SDK directly
           include(/path/to/pico-sdk/pico_sdk_init.cmake)
 
           project(my_project)
 
           # initialize the Raspberry Pi Pico SDK
           pico_sdk_init()
 
           # rest of your project
 
           ```
1. Escreva seu código (veja [pico-examples](https://github.com/raspberrypi/pico-examples) ou a documentação do [Raspberry Pi Pico-Series C/C++ SDK](https://rptl.io/pico-c-sdk) para mais informações).

   O mais simples que você pode fazer é um único arquivo fonte (por exemplo, hello_world.c):
   ```c
   #include <stdio.h>
   #include "pico/stdlib.h"

   int main() {
       stdio_init_all();
       printf("Hello, world!\n");
       return 0;
   }
   ```
   E adicione o seguinte ao seu `CMakeLists.txt`:

   ```cmake
   add_executable(hello_world
       hello_world.c
   )

   # Add pico_stdlib library which aggregates commonly used features
   target_link_libraries(hello_world pico_stdlib)

   # create map/bin/hex/uf2 file in addition to ELF.
   pico_add_extra_outputs(hello_world)
   ```

   Observe que este exemplo usa o UART padrão para stdout;
   se você quiser usar o USB padrão, veja o exemplo hello-usb. [hello-usb](https://github.com/raspberrypi/pico-examples/tree/master/hello_world/usb).

1. Configure um diretório de construção CMake.
      Por exemplo, se não estiver usando um IDE:
      ```
      $ mkdir build
      $ cd build
      $ cmake ..
      ```   
   
   Ao compilar para uma placa diferente da Raspberry Pi Pico, você deve passar  `-DPICO_BOARD=board_name` para o comando `cmake` acima, por exemplo `cmake -DPICO_BOARD=pico2 ..` ou `cmake -DPICO_BOARD=pico_w ..` para configurar o SDK e as opções de compilação de acordo com essa placa específica.

   Especificar `PICO_BOARD=<boardname>` configura várias definições de compilador (por exemplo, números de pinos padrão para UART e outros hardwares) e, em certos casos, também habilita o uso de bibliotecas adicionais (por exemplo, suporte sem fio ao compilar para `PICO_BOARD=pico_w`), que não podem ser construídas sem uma placa que forneça a funcionalidade de hardware necessária.
   
   Para uma lista de placas definidas no SDK, consulte [este diretório](src/boards/include/boards) que possui um cabeçalho para cada placa nomeada.

1. Compile seu alvo a partir do diretório de construção que você criou.
      ```sh
      $ make hello_world
      ```

1. Agora você tem `hello_world.elf` para carregar via um depurador, ou `hello_world.uf2` que pode ser instalado e executado em seu dispositivo da série Raspberry Pi Pico via arrastar e soltar.

# RISC-V support on RP2350

Consulte [Raspberry Pi Pico-series C/C++ SDK](https://rptl.io/pico-c-sdk) para informações sobre como configurar um ambiente de construção para RISC-V no RP2350.
