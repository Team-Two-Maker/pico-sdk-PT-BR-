# Preparando o ambiente de programação

## Requisitos mínimos

- Ubuntu versão 24.04
- Python versão 3.10

## 1º passo: Instalação do Git

A instalação do git é necessária para clonar o repositório do pico-sdk
e do picotool.

Primeiro precisamos atualizar o sistema, para isso, abra o terminal
(atalho: Ctrl+alt+t) e digite o seguinte comando:

```
sudo apt update && sudo apt upgrade -y
```

Depois de executar as atualizações, continue no terminal para instalar o Git:

```
sudo apt install git -y
```

Após a instalação, digite o comando abaixo para verificar se realmente foi instalado e também a versão:

```
git --version
```

## 2º passo: Instalação do pico-sdk

Agora que o Git está instalado, é hora de fazer o clone do pico-sdk e suas devidas instalações.

Primeiro crie um diretório para armazenar o pico-sdk. Abra o terminal e digite os seguintes comandos:

```
mkdir pico
```

Obs: o comando mkdir serve para criar uma nova pasta, e o nome que vem posteriormente é o nome que será dado a essa pasta, no exemplo será a pasta pico.

Agora, selecione a pasta que você acabou de criar:

```
cd pico
```

Com a pasta selecionada, agora vamos fazer o clone do repositório do pico-sdk:

```
git clone -b master https://github.com/raspberrypi/pico-sdk.git
```

Após concluir a clonagem do repositório, selecione o diretório do
pico-sdk:

```
cd pico-sdk
```

Inicialize os submódulos:

```
git submodule update --init
```

## 3º passo: Instalação do picotoo

Além do pico-sdk, também é necessário baixar e configurar o
picotool, para isso, continue no terminal.

Antes de iniciar o próximo passo, é importante voltar para a pasta
raiz, para isso, digite o comando:

```
cd ~/
```

Agora, vamos instalar as dependências do ARM GCC:

```
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi buildessential -y
```

Depois de instalar as dependências do ARM GCC, vamos voltar para o
diretório onde estamos instalando as bibliotecas, para isso,
selecione a pasta que criamos anteriormente (pico):

```
cd pico
```

Após selecionar a pasta, vamos fazer o clone do repositório do
picotool:

```
git clone https://github.com/raspberrypi/picotool.git
```

Selecione a pasta do picotool:

```
cd picotool
```

Depois vamos criar uma outra pasta:

```
mkdir build
```

Agora vamos voltar para o diretório raiz:

```
cd ~/
```

Para configurar o cmake, antes precisamos configurar alguns
caminhos para que o linux os reconheça na instalação.

Procure o caminho para a pasta pico-sdk no seu dispositivo e copie.

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/caminho%20pastas.png "caminho para a pasta pico-sdk")

Digite no terminal:

```
export PICO_SDK_PATH=cole-o-caminho-aqui
```

Obs: Copie o caminho para a pasta do pico-sdk do seu dispositivo
e cole no lugar de “`cole-o-caminho-aqui`”

Para encontrar o caminho da pasta, acesse com o terminal até
entrar na sua pasta pico-sdk com os comandos cd. Depois que
estiver na pasta do pico-sdk, digite o comando pwd e copie o
caminho.

Ex.: ![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/caminho.png "caminho para a pasta")

Após copiar o caminho volte para a pasta raiz:

```
cd ~/
```

Ainda na pasta raiz digite:

```
echo 'export PICO_SDK_PATH=/home/nomeDeUsuario/pico/pico-sdk'>> ~/.bashrc
```

Para salvar as alterações, digite:

```
source ~/.bashrc
```

Com o caminho configurado, vamos voltar para a pasta do picotool.
Para isso, digite:

```
cd pico
```

Depois:

```
cd picotool
```

Depois selecione a pasta que criamos anteriormente:

```
cd build
```

Depois vamos configurar o cmake:

```
cmake ..
```

Agora digite:

```
make
```

Instale o picotool:

```
sudo cp picotool /usr/local/bin
```

Por último, verifique se o picotool está configurado corretamente:

```
picotool version
```

## 4 º passo: Instalação do Visual Studio Code + Extensões

Agora que já temos todos os arquivos necessários para executar o projeto, vamos instalar a IDE e também as Extensões responsáveis por transformar nossos projetos na linguagem específica para a placa Raspberry PI PICO W.

Primeiramente, acesse a loja de aplicativos do Ubuntu, depois digite na barra de pesquisas por Visual Studio Code e instale.

EX: <br>

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/vscode.png "instalação do vscode")

Após instalar o Visual Studio Code, abra a IDE e acesse a campo de extensões presente no canto esquerdo da tela.

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/extens%C3%B5es.png "extensões")

Na barra de pesquisa, busque por **C/C++ Extension Pack** e faça a instalação da extensão.

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/c_C%2B%2B%20extensoes.png "extensão c/c++")

Essa extensão fará a instalação de todas as extensões necessárias para a configuração, como a CMake, CMake Tools, C/C++, etc.

Faça também a instalação da Extensão **Raspberry Pi Pico**, é através dela que vamos criar, compilar e executar nossos projetos.

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/extensao%20raspberry.png "extensão pico-sdk")

Caso ainda não apareça no seu campo de extensões, também faça a instalação da Extensão Serial Monitor:

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/serial%20monitor%20extensao.png "extensão monitor serial")

Agora que temos nossas extensões, é hora de configurar a extensão **CMake Tools** corretamente. Para isso, vá até o campo de extensões e procure pela extensão CMake Tools e selecione o ícone de engrenagem.

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/cmake%20tools%20extensao.png "configuração cmake tools")

Selecione a opção de configurações:

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/cmake%20tools%20extensao%20grande.png "configuração cmake tools")

Na barra de pesquisas, procure por **Configure Environment**, depois configure o item como **PICO_SDK_PATH** e o valor como o caminho para essa pasta como no exemplo abaixo:

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/configure%20environments.png "configure environment")

Para encontrar o caminho, você pode utilizar o seguinte atalho no terminal:

Abra o terminal, selecione a pasta novamente com o comando _cd_:

```
cd pico/pico-sdk
```

Depois que estiver na pasta do pico-sdk, digite o comando `pwd` e copie o caminho.

EX:
![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/caminho.png "pegar caminho")

Feche o terminal e volte para o vscode para continuar com as configurações.

Depois pesquise por **cmake path**, procure pelo campo abaixo e preencha com **cmake**:

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/cmake%20path.png "cmake path")

Ainda na barra de pesquisa, procure por **Generator** e preencha com **NMake Makefiles** igual a imagem abaixo:

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/generator.png "generator")

## 5 º passo: Adicionar Usuário ao Grupo dialout

Para carregar os códigos na placa através da Extensão do Raspberry PI Pico no Visual Studio Code, é necessário ainda adicionar o seu usuário ao grupo dialout, para que o sistema operacional reconheça a placa e consiga carregar o código sem precisar da senha do administrador.

Para isso, abra o terminal e insira o seguinte comando:

```
sudo usermod -aG dialout $USER
```

Após dar enter, **reinicie** o computador.

Agora vamos configurar o sistema para reconhecer a placa, abra o terminal e digite os seguintes comandos:

```
sudo nano /etc/udev/rules.d/99-pico.rules
```

Após dar Enter sua senha será solicitada, digite e aparecerá uma tela
semelhante a essa:

![alt text](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/img/parte%20critica.png "parte crítica")

Insira a linha de comando:

```
SUBSYSTEM=="usb", ATTRS{idVendor}=="2e8a", MODE="0666"
```

Pressione as teclas **Ctrl + X** para iniciar a operação de salvar, depois
digite **Y** (ou **S**, dependendo do idioma do sistema) para confirmar a
alteração, e por fim, pressione **Enter** para salvar e sair.

Quando finalizar a operação, abra o terminal e digite:

```
sudo udevadm control --reload-rules
```

Depois:

```
sudo udevadm trigger
```

Após finalizar todas as etapas reinicie novamente o seu computador para salvar todas as configurações que foram feitas. Pronto! Agora seu ambiente Linux está completamente configurado e pronto para utilizar o Raspberry PI PICO na placa BitDogLab.

# Conclusão

Estamos certos de que, com o auxílio deste manual, você terá todas as ferramentas necessárias para configurar o ambiente de programação no Ubuntu e explorar as possibilidades da Raspberry Pi Pico W.
