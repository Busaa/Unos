# Ano Unos
Repository for our implementaion of an Uno style game using raylib library for C.

Uno: https://pt.wikipedia.org/wiki/Uno_(jogo_de_cartas)

WorkFlow:

Para criar um jogo Uno simples em C usando a biblioteca raylib, você pode seguir este fluxo de trabalho básico:

1. **Definição das Estruturas de Dados:**
   - Crie estruturas de dados para representar o baralho, a mão dos jogadores, a pilha de descarte e a ordem das jogadas. Use TADs para modelar essas entidades de forma genérica e modular.

2. **Implementação da Interface de Texto:**
   - Use a raylib para criar uma interface de texto simples que apresente o menu do jogo e o espaço de jogo.
   - Implemente funções para mostrar o menu, exibir o estado atual do jogo e capturar entrada do jogador.

3. **Implementação da Lógica do Jogo:**
   - Desenvolva a lógica do jogo Uno, incluindo regras para distribuição de cartas, jogadas dos jogadores, compra de cartas, etc.
   - Utilize as estruturas de dados definidas anteriormente para representar o estado do jogo e manipular as jogadas dos jogadores.

4. **Interação com o Usuário:**
   - Permita que o jogador interaja com o jogo através da interface de texto, realizando jogadas, escolhendo cartas, etc.
   - Valide as jogadas do jogador de acordo com as regras do Uno.

5. **Implementação de Recursos Extras (Opcionais):**
   - Se desejar, adicione recursos extras como efeitos sonoros, salvamento de estado do jogo, interface gráfica simples, etc.
   - Utilize a raylib para adicionar elementos gráficos ao jogo, como cores e formas básicas.
  
   
Requisitos Basicos Gerais ´
• Deve-se usar os conceitos de tipos abstratos de dados (TADs). Tanto as estruturas de dados gen´ericas (que
modelam colec¸oes de dados) quanto outras entidades modeladas devem ser representadas por TADs. Estruture ˜
os TADs de forma adequada em arquivos de implementac¸ao e interface. ˜
• Deve-se implementar uma interface (textual) intuitiva que apresenta um menu e o espac¸o de jogo. O menu deve
ter, no m´ınimo, opc¸oes para iniciar um jogo, voltar ao jogo corrente e encerrar o jogo. Voc ˜ ˆes poderao pesquisar ˜
a utilizac¸ao de bibliotecas para cria ˜ c¸ao de uma interface amig ˜ avel para o jogo. Jogabilidade ´ ´e fundamental.
A escolha da biblioteca ´e responsabilidade dos grupos. Algumas bibliotecas sugeridas sao a ˜ conio2 e a ncurses,
usadas para desenvolver interfaces em modo texto, para Windows e para Linux respectivamente.
• Deve-se documentar e modularizar adequadamente o codigo do jogo. Legibilidade tamb ´ ´em ´e fundamental.

Requisitos Basicos Individuais ´
Al´em dos requisitos basicos gerais, cada opc¸ ´ ao de jogo tem um conjunto espec ˜ ´ıfico de requisitos basicos: ´
Requisitos Basicos para a implementac¸ ´ ao do jogo Uno ˜
• O monte de cartas (baralho) deve ser representado por uma pilha.
• A ordenac¸ao das jogadas deve ser representada por uma lista circular dupla. ˜
• As cartas da mesa devem ser representadas por uma pilha.
• As cartas de cada jogador devem ser representada por uma lista (simples ou dupla).

Lembre-se de nao infringir os protocolos associados a estruturas de dados como pilhas, filas e deques ao implementar ˜
novas operac¸oes (ex., embaralhamento). Os jogos podem ser implementados em formato ˜ multiplayer ou contra um ou
mais jogadores. controlados pelo computador. Nesse caso, o computador deve realizar jogadas coerentes.

Extras
A pontuac¸ao associada aos extras pode extrapolar a nota 10 do Trabalho Final. ˜
• Os grupos sao encorajados a implementar estruturas de dados realmente gen ˜ ´ericas (com uso de void* e callbacks).
(0,85 ponto)
• Os grupos sao encorajados a implementar seu jogo com uma interface gr ˜ afica (GUI) simples. Algumas bibliotecas ´
que poderiam ser utilizadas sao: a ˜ Allegro, a raylib e a sdl2. A raylib ´e altamente recomendada. A Figura 1
ilustra uma interface inicial em raylib para o jogo Uno. (1,15 ponto)
• Os grupos sao encorajados a implementar efeitos sonoros em diferentes ac¸ ˜ oes do jogo. ( ˜ 0,1 ponto)
• Os grupos sao encorajados a implementar outras op ˜ c¸oes no menu, como carregamento e armazenamento do ˜
estado do jogo da/para memoria secund ´ aria. ( ´ 0,1 ponto)
• Os grupos sao encorajados a implementar o controle das maiores pontua ˜ c¸oes do jogo ( ˜ ranking) – se for cab´ıvel
(para jogos em que isso nao˜ ´e cab´ıvel, pode-se criar um ranking baseado no tempo decorrido at´e vencer o jogo).
Deve-se registrar o nome do jogador vencedor ao final de cada partida para concorrer ao podio. ( ´ 0,1 ponto)
• Os grupos sao encorajados a implementar um algoritmo “esperto” para jogadas do computador e/ou autom ˜ atica. ´
(0,1 ponto)
• Os grupos podem propor a utilizac¸ao de outras estruturas de dados para resolver os problemas de cada jogo. ˜
Contatem o professor antes de implementar essas estruturas. (0,5 ponto)

