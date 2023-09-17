# Laboratório de Estrutura de Dados - Trabalho 1º Bimestre

## Free Cell
O FreeCell é um popular jogo de cartas que faz parte da família dos jogos de paciência (solitário). Ele é conhecido por sua jogabilidade desafiadora e estratégica, onde o objetivo é organizar todas as cartas em quatro pilhas de saída, classificadas por naipe e em ordem crescente. O jogo se destaca por permitir que o jogador mova cartas livremente entre as colunas, desde que siga regras específicas. A habilidade de planejar e tomar decisões estratégicas é ampliada ao existir quatro células que permitem a movimentação de uma carta para dentro dela.

## Regras do jogo
#### Objetivo do jogo:
 Mover para as saidas as 52 cartas do jogo. Tera uma pilha para cada naipe do baralho e cada pilha deve ter as cartas movimentadas na ordem crescente do as ate o rei.

#### Visao geral do jogo:
* No canto superior ESQUERDO tera 4 espacos vazios (chamados tambem de FreeCells), onde voce podera armazenar qualquer carta temporariamente durante o jogo.
                                                                    
* No canto superior DIREITO tambem ha 4 espacos vazios. Estes sao as pilhas de saida.                                                    

* As cartas inicialmente sao dispostas em 8 colunas, sendo 7 cartas nas 4 primeiras e 6 cartas nas 4 ultimas.
                                                                    
#### Como jogar:                                                          
* Retire cartas da parte inferior de cada coluna e mova-as da        
seguinte maneira:                                                    
                                                                    
    * De uma coluna para uma free cell: As celulas vazias so podem conter uma carta de cada vez.                                        

    * De uma coluna para outra (ou de uma free cell para uma coluna). As cartas devem ser colocadas na coluna em ordem sequencial decrescente e e necessario alternar naipes vermelhos e pretos.       
                                                                    
    * De uma coluna para uma celula inicial. Cada pilha deve consistir de um unico naipe e comecar pelo as.                                 



### Informações importantes para uso:
- Para realizar o build do projeto, execute o seguinte comando, seguindo a estrutura indicada:
> Em ambientes baseado em Unix:
> 
>g++ -std=c++17 -Wall -Wextra -pedantic -o build/FreeCell FreeCell.cpp src/*.cpp 
- Digite os dados requeridos no terminal apenas quando forem solicitados, pois entrada de dados antes do momento correto pode resultar em comportamentos indeterminados na aplicação.

&nbsp;
### Autores:
- Carlos Sérgio Fernandes Júnior - 2157633 - <[carlos_fernandes.1@hotmail.com](https://github.com/Carlost65)>
- Matheus Paulino Ribeiro - 2143432 - <[mathpaulinor@gmail.com](https://github.com/Matheus2237)>
- Nicolas Fagundes Scarpa - 2093087 - <[bkscarpa@gmail.com](https://github.com/nicuis)>