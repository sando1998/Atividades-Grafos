# Atividade Grafos


## Bellman Ford algorithm
### Entrada: 
  A entrada consiste que os dois primeiros dígitos serão a quantidade de vértices (n) e arestas (m) respectivamente, seguido de n linhas compostas de vértice 1, vértice 2 e peso.
  ###### Entrada padrão, "[graph.in](https://github.com/sando1998/Atividades-Grafos/blob/main/Bellman%20Ford%20algorithm/graph.in)":
  ```
  5 10
  0 1 6
  0 2 7
  1 2 8
  1 4 -4
  1 3 5
  2 4 9
  2 3 -3
  3 1 -2
  4 3 7
  4 0 2
  ```
### Saída: 
  A saída consiste em n linhas onde cada uma representa a distancia de um dos vértices para o vértice de partida, como padrão tomamos o 0 como vértice de partida.
  ##### Saída para a entrada padrão:
  ```
  Distance from vertex 0 to vertex source = 0
  Distance from vertex 1 to vertex source = 2
  Distance from vertex 2 to vertex source = 7
  Distance from vertex 3 to vertex source = 4
  Distance from vertex 4 to vertex source = -2
  ```
## FordFulkerson algorithm
### Entrada: 
  A entrada consiste numa matriz de adjacencia (5 x 5), para receber outra matriz na entrada com valor diferente de 5, basta atribuir um valor "n" diferente na variável 'constant' na [linha 8](https://github.com/sando1998/Atividades-Grafos/blob/main/FordFulkerson%20algorithm/Ford_Fulkerson.cpp#L8), definir o número de variaveis da [linha 75](https://github.com/sando1998/Atividades-Grafos/blob/main/FordFulkerson%20algorithm/Ford_Fulkerson.cpp#L75) para o valor desejado e modificar o `for(controll = 0;controll<constant;controll++)` na [linha 76](https://github.com/sando1998/Atividades-Grafos/blob/main/FordFulkerson%20algorithm/Ford_Fulkerson.cpp#L76) para conseguir atribuir o número de vértices desejado.
  ##### Entrada padrão, "[graph.in](https://github.com/sando1998/Atividades-Grafos/blob/main/FordFulkerson%20algorithm/graph.in)":
  ```
  0 6 5 2 2
  0 0 0 3 0
  0 0 0 2 0
  0 0 0 0 7
  0 0 0 0 0
  ```
### Saída: 
  A saída consiste em n linhas onde cada uma representa o fluxo máximo de um dos vértices para o vértice de partida, como padrão tomamos o 0 como vértice de partida. 
  ##### Saída para a entrada padrão:
  ```
  Maximum flow between the vertex 1 and the source: 6
  Maximum flow between the vertex 2 and the source: 5
  Maximum flow between the vertex 3 and the source: 7
  Maximum flow between the vertex 4 and the source: 9
  ```
## Dijkstra algorithm
### Entrada: 
  A entrada consiste em que os dois primeiros dígitos serão a quantidade de vértices (n) e arestas (m) respectivamente, seguido de n linhas compostas de vértice 1, vértice 2 e peso.
  ##### Entrada padrão, "[graph.in](https://github.com/sando1998/Atividades-Grafos/blob/main/Dijkstra%20algorithm/graph.in)":
  ```
  4 6
  0 1 5
  0 2 3
  1 3 3
  2 1 2
  3 2 9
  3 0 3
  ```
### Saída: 
  A saída consiste em n linhas onde cada uma representa a distancia com menor custo de um dos vértices para o vértice de partida, como padrão tomamos o 0 como vértice de partida.
  ##### Saída para a entrada padrão:
  ```
  Shortest distance from vertex 0 to vertex source = 0 
  Shortest distance from vertex 1 to vertex source = 5 
  Shortest distance from vertex 2 to vertex source = 3 
  Shortest distance from vertex 3 to vertex source = 8 
  ```
## Prim algorithm
### Entrada: 
  A entrada consiste em que os dois primeiros dígitos serão a quantidade de vértices (n) e arestas (m) respectivamente, seguido de n linhas compostas de vértice 1, vértice 2 e peso.
  ##### Entrada padrão, "[graph.in](https://github.com/sando1998/Atividades-Grafos/blob/main/Prim%20algorithm/graph.in)":
  ```
  6 9
  0 1 100
  0 2 50 
  1 2 40
  1 3 5
  2 3 3
  2 4 1
  2 5 7
  3 5 15
  4 5 2
  ```
### Saída:
  A saída consiste em n linhas onde cada linha representa uma aresta para formar árvore geradora mínima.
  ##### Saída para a entrada padrão:
  ```
  3 --- 1
  0 --- 2
  2 --- 3
  2 --- 4
  4 --- 5
  ```
