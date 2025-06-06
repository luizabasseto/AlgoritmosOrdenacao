# Avaliação 2 - Trabalho Prático - Algoritmos de Ordenação e Busca

Trabalho feito como avaliação da parcial 2 (P2) feito para a disciplina de Algoritmos e Estrutura de Dados 1

**Aluna:** Luiza Batista Basseto  
**R.A.:** 2251825  

Este projeto tem como objetivo comparar o desempenho de diferentes algoritmos de ordenação e busca em vetores de diferentes tamanhos e configurações.

##  Algoritmos Implementados

- Bubble Sort (Puro e Otimizado)
- Selection Sort (Puro e Otimizado)
- Insertion Sort
- Busca Linear
- Busca Binária

##  Metodologia

- Foram utilizados vetores pequenos para testes iniciais de corretude.
- Para análise de desempenho, vetores grandes foram gerados com números aleatórios e salvos em arquivos binários.
- O tempo de execução, número de trocas e comparações foram medidos.

##  Gráficos

Gráficos foram gerados para comparar o tempo de execução em diferentes tamanhos de entrada. Os arquivos deles podem serem acessados clicando neste [Link](Grafico) aqui. Onde o `graficos.py` contém o modelo utilizado para montar os gráficos dos algoritmos de ordenação e o arquivo `graficosBuscas.py` mostra como foi gerado os gráficos para as buscas (Linear e Binária). A imagem gerada está disponível no [Relatório](https://github.com/luizabasseto/AlgoritmosOrdenacao/blob/main/Relat%C3%B3rio%20P2%20-%20ED1%20-%20Algoritmos%20Ordena%C3%A7%C3%A3o%20e%20Buscas%20com%20Arquivo%20Bin%C3%A1rio.pdf) disponível em pdf. 

## Configuração Inicial

  ### 1. Clone o Repositório
          gh repo clone luizabasseto/AlgoritmosOrdenacao
  ### 2. Entre na pasta Codigos
          cd Codigos
  ### 3. Execute o arquivo Makefile
          make
  ### 4. Entre na pasta build
          cd build
  ### 5. Execute o comando para inicializar o main.cpp
          ./main
          
Seguindo esses passos o código deverá ser executado no terminal Windows.

## Configuração para gerar os gráficos

  ### 1. Entre na pasta Grafico
        cd Grafico
  ### 2. Execute o arquivo graficos.py
        Python graficos.py

Assim será gerado uma imagem disponível para download com os 3 gráficos solicitados dos algoritmos, para cada um dos tempos.

## Configuração para gerar os gráficos das buscas

  ### 1. Entre na pasta Grafico
        cd Grafico
  ### 2. Execute o arquivo graficos.py
        Python graficosBuscas.py

Assim será gerado uma imagem disponível para download com os tempos de buscas para os vetores de tamanho n1 e n2, antes e após a ordenação.
