# Controle de servomotor por PWM - Wokwi

Este projeto implementa o controle de um servomotor utilizando um Raspberry Pi Pico. O controle do servo é feito através de sinais PWM (Pulse Width Modulation), permitindo o posicionamento em diferentes ângulos.

## Vídeo da Prática

Segue o link do vídeo dos resultados obtidos durante a simulação:

[Assista ao vídeo demonstrativo. Clique aqui!](https://youtu.be/TIP_zPu6XiY)

## **Cálculo do Período PWM (Wrap Value)**

A definição correta do valor WRAP é essencial para garantir que o PWM opere na frequência desejada (50Hz). O cálculo foi realizado conforme mostrado abaixo:

- Frequência do clock: 125 MHz
- Frequência do PWM: 50 Hz
- Divisor do clock: 100
- Wrap: Valor a determinar

<img src="calculo-definir-wrap.jpg" alt="Cálculo do Wrap Value" height="300">

OBS: Para simplificação, o valor foi arredondado para 25000.

---

## 🚀 **Como Compilar e Executar**

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/adimael/u4-c7-controle-servomotor-pwm.git
   ````
2. **Entre na pasta do projeto**:
   ````
   cd u4-c7-controle-servomotor-pwm
   
   ````

### **1️⃣ Configurar o Ambiente de Desenvolvimento**
Certifique-se de ter instalado o **Raspberry Pi Pico SDK** e o **compilador C/C++**. Se ainda não configurou, siga as etapas abaixo:

### Passo 1: Baixar o Ninja
   1. Acesse a página oficial de releases do Ninja:  
   [Ninja Releases no GitHub](https://github.com/ninja-build/ninja/releases).
   2. Baixe o arquivo binário mais recente para Windows (geralmente um `.zip`).
   3. Extraia o conteúdo do arquivo `.zip` (haverá um arquivo `ninja.exe`).

   ---

   ### Passo 2: Adicionar o Ninja ao Path do sistema
   Para que o `ninja` seja reconhecido como um comando em qualquer terminal, siga estas etapas:

   1. Clique com o botão direito no botão **Iniciar** e selecione **Configurações**.
   2. Vá em **Sistema** → **Sobre** → **Configurações avançadas do sistema** (no lado direito).
   3. Na aba **Avançado**, clique em **Variáveis de Ambiente**.
   4. Na seção **Variáveis do Sistema**, localize a variável `Path` e clique em **Editar**.
   5. Clique em **Novo** e adicione o caminho completo para o diretório onde você extraiu o `ninja.exe`. Por exemplo:
      ````
      C:\Users\SeuUsuario\Downloads\ninja-win
      ````
   6. Clique em **OK** em todas as janelas.

   ---

   ### Passo 3: Verificar se o Ninja está funcionando
   1. Abra um terminal (PowerShell ou Prompt de Comando).
   2. Digite o comando abaixo para verificar a instalação:
      ```bash
      ninja --version
      ````

   ### Passo 4: Configurar e Compilar o Projeto

   1. Volte ao diretório do projeto e abra um terminal.
   2. Crie ou limpe a pasta `build`:
      ```bash
      rmdir /s /q build
      mkdir build
      cd build
      
   3. Configure o projeto com o CMake:
      ```bash
      cmake -G Ninja ..
      ````
   4. Compile o projeto:

      ```bash
         ninja
      ````

   5. Após isso, o arquivo main.elf será gerado na pasta build.

### Pré-requisitos
- **Placa BitDogLab** configurada e conectada.
- Ambiente de desenvolvimento configurado com **SDK do RP2040**.

   ou

- Use a extensão do Wokwi no VSCode [https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)