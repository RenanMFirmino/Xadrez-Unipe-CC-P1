#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include "pecas.h"//Biblioteca criada para printar,colocar as regras de cada peça e mostrar a movimentação do tabuleiro;

using namespace std;
typedef struct jogador
{
    char nome[20];
    int cont;
} Jogador;

int main()
{
    FILE*file;
    int linOri, linDes, colOri, colDes;
    int l1, l2, c1, c2, total=0, resultado;
    int xeque_mate = 0;
    char resp;
    Jogador jog1, jog2;
    setlocale(LC_ALL, "portuguese");
    printf("\tXADREZ\n");
    printf("Informe o nome do Jogador 1:\n");
    fflush(stdin);
    fgets(jog1.nome, 20, stdin);
    jog1.nome[strlen(jog1.nome) - 1] = '\0';
    printf("Informe o nome do Jogador 2:\n");
    fflush(stdin);
    fgets(jog2.nome, 20, stdin);
    jog2.nome[strlen(jog2.nome) - 1] = '\0';
    jog1.cont = 0;
    jog2.cont = 0;
    do // Mover Peças e mostrar as Mudanças Ocorridas no Tabuleiro
    {
        Printar_tabuleiro();//função da biblioteca(biblio.h) para mostrar o tabuleiro e as mudanças ocorridas no jogo;
        if (total %2 == 0)
        {
            printf("Vez de %s\n", jog1.nome);
        }
        else
        {
            printf("Vez de %s\n", jog2.nome);
        }
        printf("Informe a linha original da peça desejada:(1 a 8)\n");
        scanf("%d", &l1);
        printf("Informe a coluna original da peça desejada:(1 a 8)\n");
        scanf("%d", &c1);
        printf("Informe a linha de destino da peça desejada:(1 a 8)\n");
        scanf("%d", &l2);
        printf("Informe a coluna de destino da peça desejada:(1 a 8)\n");
        scanf("%d", &c2);
        linOri = l1 - 1;
        colOri = c1 - 1;
        linDes = l2 - 1;
        colDes = c2 - 1;
        resultado = mover_peca(linOri, colOri, linDes, colDes);
        if (resultado != 1)//possiveis respostas quanto a movimentação das peças
        {
            switch (resultado)
            {
            case 0:
            {
                printf("Coordenadas inválidas,Destino ou Entrada Para fora do Tabuleiro:\n");
                scanf(" %c",&resp);
                continue;
                break;
            }
            case 1:{
                break;
            }
            case 2:
            {
                printf("Checkmate\n");
                scanf(" %c",&resp);
                break;
            }
            case 8:
            {
                printf("Movimento Invalido,Peça Tentando Fazer Movimento Fora de seu Parametro:\n");
                scanf(" %c",&resp);
                continue;
                break;
            }
            case 9:
            {
                printf("A Peça Não Pode realizar esse Movimento,Pois Tem Uma Peça em Seu Percurso:\n");
                scanf(" %c",&resp);
                continue;
                break;
            }
            }
        }
        mover_peca(linOri, colOri, linDes, colDes);//movimentação de peça aceita
        if (total%2==0)
        {
            jog1.cont++;
        }
        else
        {
            jog2.cont++;
        }
        total ++;
        if (resultado == 2)//xequemate;
        {
            file=fopen("rank.txt","a");
            if (total%2==0)
            {
                printf("O Vencedor é %s com %d jogadas do total %d;\n", jog2.nome, jog2.cont, total);
                fprintf(file,"O Vencedor é %s com %d jogadas do total %d;\n", jog2.nome, jog2.cont, total);
                scanf(" %c",&resp);
            }
            else
            {
                printf("O Vencedor é %s com %d jogadas do total %d;\n", jog1.nome, jog1.cont, total);
                fprintf(file,"O Vencedor é %s com %d jogadas do total %d;\n", jog1.nome, jog1.cont, total);
                scanf(" %c",&resp);
            }
            fclose(file);
            xeque_mate=1;
        }
        printf("\n\n\n");
    }while (xeque_mate==0);
    return 0;
}