# 🚢 Jogo de Batalha Naval em C

Este projeto foi desenvolvido como parte de um desafio de programação em linguagem C, com o objetivo de praticar:

- Manipulação de matrizes bidimensionais
- Lógica de posicionamento de elementos em grades
- Estruturas de controle aninhadas
- Criação de padrões geométricos em matrizes
- Organização e documentação de código

O programa simula um tabuleiro de batalha naval e gera diferentes padrões geométricos (cruz, cone e octaedro) em matrizes 10x10.

---

## 🧩 Estrutura do Projeto

O código é composto por 4 funções principais que demonstram diferentes conceitos de programação:

### ⚓ BatalhaNaval()
- Cria um tabuleiro 10x10 da Batalha Naval
- Posiciona 4 navios em diferentes orientações:
  - **Navio 1:** Horizontal na linha 3 (posições 3,4,5)
  - **Navio 2:** Vertical na coluna 8 (posições 6,7,8)
  - **Navio 3:** Diagonal da posição (1,7) até (4,10)
  - **Navio 4:** Diagonal da posição (7,3) até (10,6)
- Utiliza variáveis de controle para posicionamento diagonal

### ✝️ MatrizCruz()
- Gera um padrão em formato de cruz no tabuleiro
- Braço vertical: coluna 5, linhas 2 a 8
- Braço horizontal: linha 5, colunas 2 a 8
- Demonstra posicionamento simples com condições diretas

### 🔺 MatrizCone()
- Cria um padrão em formato de cone/árvore
- Vértice na posição (3,5)
- Expansão gradual: cada linha adiciona uma coluna em cada lado
- Utiliza variáveis auxiliares para controlar os limites do cone

### 💎 MatrizOctaedro()
- Tenta reproduzir um padrão em formato de octaedro (losango)
- Ponto central na posição (2,5)
- Implementa lógica de expansão (parte superior) e contração (parte inferior)
- Demonstra controle de fluxo mais complexo com múltiplas condições

---

## 🎯 Objetivo do Projeto

A proposta do desafio foi desenvolver um programa que fosse além de um simples tabuleiro de batalha naval, aplicando:

- **Manipulação avançada de matrizes:** Diferentes formas de percorrer e preencher estruturas bidimensionais
- **Lógica de posicionamento:** Algoritmos para criar padrões geométricos
- **Controle de fluxo complexo:** Uso de múltiplas condições aninhadas e variáveis de estado
- **Documentação:** Código comentado para facilitar manutenção e compreensão

---

## 📊 Representação Visual

Todos os tabuleiros seguem o mesmo formato de exibição:

- Linhas numeradas de 1 a 10
- Colunas identificadas por letras de A a J
- Valor **0** representa água/espaço vazio
- Valor **3** representa parte do navio/padrão geométrico

