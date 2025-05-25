# Avaliação 2 - Trabalho Prático - Algoritmos de Ordenação e Busca

Trabalho feito como avaliação da parcial 2 (P2) feito para a disciplina de Algoritmos e Estrutura de Dados 1

**Aluna:** Luiza Batista Basseto  
**R.A.:** 2251825  

Este projeto tem como objetivo comparar o desempenho de diferentes algoritmos de ordenação e busca em vetores de diferentes tamanhos e configurações.

##  Algoritmos Implementados

- Bubble Sort (Puro e Otimizado)
- Selection Sort
- Insertion Sort (Puro e com Busca Binária)
- Busca Linear
- Busca Binária

##  Metodologia

- Foram utilizados vetores pequenos para testes iniciais de corretude.
- Para análise de desempenho, vetores grandes foram gerados com números aleatórios e salvos em arquivos binários.
- O tempo de execução, número de trocas e comparações foram medidos com alta precisão.

##  Gráficos

Gráficos foram gerados para comparar o tempo de execução em diferentes tamanhos de entrada.  
Exemplo: `Tempo de Execução × Tamanho do Vetor`.

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

Assim será gerado uma imagem disponível para download com os 3 gráficos solicitados, para cada um dos tempos.
