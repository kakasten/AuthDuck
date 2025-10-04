# **AuthDuck** 

## **🦆 O Que é o AuthDuck?**

O **AuthDuck** é um dispositivo de segurança e conveniência inspirado na técnica de Rubber Duck Debugging, mas com uma função prática: ser um **keystroke injector** (injetor de teclas) seguro e configurável.

Construído em torno de uma **Raspberry Pi Pico**, o AuthDuck armazena múltiplas credenciais de acesso de forma local e as digita automaticamente em um computador host, simulando um teclado, ao pressionar de um botão.

O sistema de **LEDs codificados por cores (RGB)** atua como um seletor visual, permitindo ao usuário saber qual senha será digitada antes da ação.

### **Por que "AuthDuck"?**

1. **"Auth"** (Authentication): Por gerenciar e digitar credenciais de acesso.
2. **"Duck"**: Pela técnica utilizada para o desenvolvimento do projeto.

## **🛠️ Especificações Técnicas e Funcionalidades**

| Recurso  | Detalhe |
| ------------- | ------------- |
| **Microcontrolador**  | Raspberry Pi Pico |
| **Firmware** | C/C++ SDK (para Raspberry Pi Pico) |
| **Interface** | USB (para simulação de teclado - HID) |
| **Armazenamento** | Configuração via arquivo .json na memória |
| **Indicação Visual** | LED RGB para indicar a senha ativa. |
| **Interação** | Botão(ões) de acionamento para "digitar" a senha. |

## **Diagrama de Fluxo**

1. O **AuthDuck** é conectado via USB (emula um teclado HID).
2. Um **LED RGB** exibe a cor associada à senha ativa (ex: 🟢 **VERDE = Senha do GitHub**).
3. O usuário pressiona o **Botão de Ação**.
4. O **AuthDuck** "digita" a sequência de teclas configurada (usuário, tecla Tab/Enter, e senha) na máquina.

## **💻 Técnicas e Tecnologias Utilizadas**

Este projeto combina desenvolvimento de firmware de baixo nível com técnicas de simulação de periféricos:

- **SDK (Software Development Kit) C/C++ do Raspberry Pi Pico:** Utilizado para desenvolver o firmware otimizado que opera diretamente no microcontrolador RP2040.
- **USB-HID (Human Interface Device) Simulation:** A técnica central do projeto, onde a Pico é programada para se apresentar ao computador host como um **teclado USB padrão**, permitindo que ela digite as credenciais.
- **JSON Parsing:** Uso de uma biblioteca C/C++ para **ler e interpretar o arquivo** `passwords.json` armazenado na memória flash, permitindo a configuração flexível das senhas, usuários e cores de LED.
- **Controle de LED RGB:** Implementação do **WS2812B**  para garantir que a cor do LED corresponda exatamente ao perfil de senha ativo.

## ⚙️ **Como Funciona a Configuração**

A configuração das senhas e suas cores de LED associadas é feita através de um arquivo `.json` que deve ser incluído na memória flash da Raspberry Pi Pico durante o processo de gravação do firmware.

### **Exemplo de Estrutura do `passwords.json`**

``` json
[
  {
    "nome": "github",
    "usuario": "meu_usuario_github",
    "senha": "minha_senha_super_secreta_123",
    "cor_led": [0, 255, 0]
  },
  {
    "nome": "email_trabalho",
    "usuario": "profissional@empresa.com",
    "senha": "senha_do_email_456",
    "cor_led": [255, 0, 0]
  }
]
```

## 🚀 **Guia de Início Rápido**

**Pré-requisitos**

1. **Raspberry Pi Pico**
2. **Cabo Micro USB** (com capacidade de dados)
3. **Botão de Ação** (e possivelmente um botão de seleção)
4. **LED RGB**
5. **Ambiente de Desenvolvimento C/C++** (Configurado para o SDK do Pico)

#### 1. **Preparação do Arquivo de Configuração**
  1. Crie o seu arquivo `passwords.json` seguindo o formato de exemplo acima, com todas as suas credenciais.

#### 2. **Compilação e Gravação do Firmware**
  1. Certifique-se de que o seu projeto C/C++ está configurado para incluir o `passwords.json` na flash memory.
  2. Compile o projeto, gerando o arquivo `.uf2`.
  3. Pressione o botão **BOOTSEL** da Pico, conecte-o ao PC, e solte o botão.
  4. Arraste e solte o arquivo `.uf2` para a unidade de disco `RPI-RP2` que apareceu.

#### 3. **Uso**
  1. Conecte o **AuthDuck** ao computador.
  2. Verifique a cor do LED. Use o botão de seleção (se implementado) para alternar até a cor correta aparecer.
  3. Clique no campo de login e pressione o **Botão de Ação** para o AuthDuck digitar a credencial completa.

## **📝 Próximos Passos (To-Do)**

Aqui estão as tarefas e recursos planejados para o desenvolvimento futuro do **AuthDuck**:

- [ ] Implementar a lógica de leitura do arquivo `passwords.json` a partir da memória flash.
- [ ] Configurar a )**alternância de perfis)** de senha via um segundo botão ou lógica de clique (simples/duplo).
- [ ] Adicionar suporte para )**criptografia AES)** no arquivo `passwords.json` para maior segurança.
- [ ] Desenvolver um case (caixa/estrutura) )**impresso em 3D)** para o hardware.
- [ ] Criar um )**guia detalhado de build)** (montagem) do hardware.
- [ ] Criar **testes unitário** para o Software

## 👨‍💻 **Desenvolvedores**

| [<img src="https://avatars.githubusercontent.com/u/109047608?s=96&v=4" width=115><br><sub>Kakasten</sub>](https://github.com/kakasten) |
| :---: |

## 🤝 **Contribuições**

Contribuições são muito bem-vindas! Se você tiver sugestões para segurança, otimização de código C++, ou novos recursos, por favor, abra uma *Issue* ou envie um *Pull Request*.