## Roadmap de Contribuição

### Visão do Projeto
O Pico-SDK PT-BR teve origem como parte de um projeto da disciplina de Software Livre, no curso de Sistemas de Informação do IFMA - Campus Monte Castelo. A proposta da atividade era contribuir com um projeto open source, e como já utilizávamos o Pico SDK, identificamos a oportunidade de melhorar o acesso a esse ecossistema para falantes da língua portuguesa. O objetivo inicial foi tornar o uso do Pico SDK mais acessível a estudantes, educadores, hobbystas e desenvolvedores iniciantes que desejam explorar o desenvolvimento com o microcontrolador RP2040. Para isso, o projeto reúne traduções, exemplos comentados em português e guias de instalação e uso em diferentes sistemas operacionais.
No futuro, nossa intenção é que o Pico-SDK PT-BR se consolide como um recurso de referência em português para quem deseja trabalhar com o Pico SDK. Queremos que ele funcione como uma base acessível para aprendizado, pesquisa e experimentação, com documentação clara, exemplos funcionais e conteúdo atualizado.
Pretendemos que o repositório continue sendo mantido de forma colaborativa, com contribuições da comunidade, alinhado com o desenvolvimento do repositório oficial, mas sempre considerando o contexto local de quem está começando ou aprofundando seu conhecimento na área.
Essa é a direção que buscamos para o Pico-SDK PT-BR: um repositório acessível, atualizado e útil para a comunidade de desenvolvedores de sistemas embarcados em língua portuguesa.

### Desafios propostos:

Com base na experiência adquirida ao longo do desenvolvimento, listamos abaixo alguns desafios que consideramos importantes para a próxima turma. Eles estão divididos em três áreas principais: produção de conteúdo, documentação e desenvolvimento técnico.

### 1. Produção de Conteúdo Didático

- Criar uma **playlist de vídeos tutoriais** cobrindo os seguintes tópicos:
  - **Configuração do ambiente de desenvolvimento no Windows**: instalação das ferramentas necessárias, configuração de variáveis de ambiente e ajuste do `CMakeLists.txt`.
  - **Criação de bibliotecas com o Pico-SDK**: explicar como modularizar o código e reaproveitar funcionalidades em diferentes projetos. Incluir exemplos práticos.

### 2. Melhoria na Documentação

- Criar uma **seção de erros comuns** no repositório (ou um site simples) explicando problemas frequentes enfrentados pelos usuários, como erros de compilação, falhas de configuração do ambiente e uso incorreto de bibliotecas, acompanhados de suas soluções.

### 3. Tradução de Exemplos Oficiais

- Iniciar uma nova seção chamada `pico-examples-pt-br` com a **tradução dos comentários** dos códigos e arquivos `CMakeLists.txt` das seguintes pastas do repositório oficial `pico-examples`:
  - `blink`
  - `pwm`
  - `uart`
  - `dma`

### 4. Desenvolvimento de Novos Exemplos

- Criar exemplos práticos de uso de **novos periféricos**, incluindo:
  - Buzzer
  - Servo motor
  - Matriz de LEDs
  - Display LCD

Cada exemplo deve conter código funcional, bem comentado, além de instruções claras para a montagem dos circuitos.

### Como colaborar:

Se você chegou até aqui, é porque tem interesse em contribuir com o nosso projeto.

Este projeto é colaborativo e possui diversas formas de participação! Para enviar sua contribuição, siga os passos abaixo:

#### Para contribuições de código ou tradução:
- Faça um fork do projeto para realizar as modificações;
- Crie uma nova branch para a sua contribuição: `git checkout -b nome-da-sua-branch`;
- Faça as alterações desejadas e commite suas mudanças: `git commit -m "Descreva sua contribuição aqui"`;
- Envie as alterações para o seu fork: `git push origin nome-da-sua-branch`;
- Crie um Pull Request (PR) para o nosso repositório principal;
- Nos marque no PR para que possamos revisar sua contribuição!

#### Para contribuições de conteúdo, relatar bugs, etc.:
- Após finalizar sua contribuição, entre em contato via canal do [Discord](), para solicitar a revisão.

### Carta aos futuros Devs

[Link da nossa Carta Legado](https://github.com/Team-Two-Maker/pico-sdk-PT-BR-/blob/main/CARTA_LEGADO.md)

Se tiver dúvidas ou precisar de ajuda durante o processo, entre em contato com a gente no nosso canal do [Discord]()

