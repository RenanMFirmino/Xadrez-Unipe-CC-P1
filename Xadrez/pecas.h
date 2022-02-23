#ifndef pecas_h
#define pecas_h

#define TorrePreta 'T'
#define TorreBranca 't'
#define CavaloPreto 'C'
#define CavaloBranco 'c'
#define BispoPreto 'B'
#define BispoBranco 'b'
#define RainhaPreta 'Q'
#define RainhaBranca 'q'
#define ReiPreto 'K'
#define ReiBranco 'k'
#define PeaoPreto 'P'
#define PeaoBranco 'p'

char tabuleiro[9][9] = { // Posição inicial do tabuleiro e suas respectivas peças
    {'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T', '1'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '2'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '3'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '4'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '5'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '6'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '7'},
    {'t', 'c', 'b', 'q', 'k', 'b', 'c', 't', '8'},
    {'1', '2', '3', '4', '5', '6', '7', '8', ' '}};
int Printar_tabuleiro()
{ // pintando e espaçando os espaços do tabuleiro
    system("CLS");
    int lin, col, r;
    for (lin = 0; lin < 9; lin++)
    {
        for (r = 0; r < 3; r++)
        {
            for (col = 0; col < 9; col++)
            {
                char peca = tabuleiro[lin][col];
                char letra = ((lin + col) % 2 == 0) ? '\xB2' : ' ';
                letra = (r == 1 && peca != ' ') ? peca : letra; // operador ternário
                if ((lin + col) % 2 == 0)
                {
                    printf("\xB2\xB2%c\xB2\xB2", letra); // serve para pintar os espaços
                }
                else
                {
                    printf("  %c  ", letra);
                }          
            }
            printf("\n");
        }
    }
    return 0;
}
int mover_peca(int linOri, int colOri, int linDes, int colDes)
{ // mover as peças de forma certa// check_move_bispo serve para averiguar se o bispo está fazendo o movimento correto em seu percurso,sempre sendo 13 a soma;
    int mover = 0, i, j;
    int dV = abs(linDes - linOri); // Distancia Vertical Percorrida
    int dH = abs(colDes - colOri); // Distancia Horizontal Percorrida
    if ((linOri >= 0 && linOri < 8 && colOri >= 0 && colOri < 8) &&
        (linDes >= 0 && linDes < 8 && colDes >= 0 && colDes < 8))
    {
        if ((TorrePreta == tabuleiro[linOri][colOri]) && (dV == 0 || dH == 0)) // Movimento da Torre Preta
        {
            if (linOri < linDes)//Checando se linha de origem é menor que linha de destino
            {
                for (i = linOri; i <= linDes; i++) // Checagem de linha
                {
                    if (i==linDes)//Permite que coma peça do oponente
                    {
                        if ((tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)||(tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                        ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) ||(tabuleiro[i][j]==ReiBranco)||(tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {//garante que não pule peças
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if (linOri > linDes)//Checando se linha de origem é maior que linha de destino
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if (i==linDes)
                    {
                        if ((tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)||(tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else
                    {
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)||
                        (tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            if (colOri < colDes)//Checando se coluna de origem é menor que coluna de destino
            {
                for (j = colOri; j <= colDes; j++)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)||(tabuleiro[linDes][j] ==' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] ==ReiBranco) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if (colOri > colDes)//Checando se coluna de origem é menor que coluna de destino
            {
                for (j = colOri; j >= colDes; j--)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)||(tabuleiro[linDes][j] ==' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
        }
        if ((TorreBranca == tabuleiro[linOri][colOri]) && (dV == 0 || dH == 0)) // Movimento da Torre Branca
        {
            if (linOri < linDes)//Checando se linha de origem é menor que linha de destino
            {
                for (i = linOri; i <= linDes; i++) // Checagem de linha
                {
                    if (i==linDes)
                    {
                        if ((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)|| (tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                        ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if (linOri > linDes)//Checando se linha de origem é maior que linha de destino
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if (i==linDes)
                    {
                        if ((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)|| (tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else
                    {
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)||
                        (tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            if (colOri < colDes)//Checando se coluna de origem é menor que coluna de destino
            {
                for (j = colOri; j <= colDes; j++)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)|| (tabuleiro[linDes][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if (colOri > colDes)//Checando se coluna de origem é menor que coluna de destino
            {
                for (j = colOri; j >= colDes; j--)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)|| (tabuleiro[linDes][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
        }
        if ((BispoPreto == tabuleiro[linOri][colOri]) && (dV == dH)) // Movimento do Bispo Preto
        {
            j = colOri;
            if ((linOri < linDes) && (colOri < colDes))//Checando se linha de origem é menor que linha de destino e Checando se coluna de origem é menor que coluna de destino
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri < linDes) && (colOri > colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri > linDes) && (colOri < colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri > linDes) && (colOri > colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j--;
                }
            }
        }
        if ((BispoBranco == tabuleiro[linOri][colOri]) && (dV == dH)) // Movimento do Bispo Branco
        {
            j = colOri;
            if ((linOri < linDes) && (colOri < colDes))
            {
                j = colOri;
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri < linDes) && (colOri > colDes))
            {
                j = colOri;
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri > linDes) && (colOri < colDes))
            {
                j = colOri;
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri > linDes) && (colOri > colDes))
            {
                j = colOri;
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j--;
                }
            }
        }
        if ((CavaloPreto == tabuleiro[linOri][colOri]) && ((dV == 1 && dH == 2) || (dV == 2 && dH == 1))) // Movimento do Cavalo Preto
        {
            if ((tabuleiro[linDes][colDes] == TorrePreta) || (tabuleiro[linDes][colDes] == BispoPreto) || (tabuleiro[linDes][colDes] == RainhaPreta) || (tabuleiro[linDes][colDes] == ReiPreto) || (tabuleiro[linDes][colDes] == PeaoPreto) || (tabuleiro[linDes][colDes] == CavaloPreto))
            {
                return 8;
            }else if (tabuleiro[linDes][colDes] == ReiBranco)
            {
                mover=2;
            }
            else
            {
                mover = 1;
            }
        }
        if ((CavaloBranco == tabuleiro[linOri][colOri]) && ((dV == 1 && dH == 2) || (dV == 2 && dH == 1))) // Movimento do Cavalo Branco
        {
            if ((tabuleiro[linDes][colDes] == TorreBranca) || (tabuleiro[linDes][colDes] == BispoBranco) || (tabuleiro[linDes][colDes] == RainhaBranca) || (tabuleiro[linDes][colDes] == ReiBranco) || (tabuleiro[linDes][colDes] == PeaoBranco) || (tabuleiro[linDes][colDes] == CavaloBranco))
            {
                return 8;
            }else if (tabuleiro[linDes][colDes] == ReiPreto)
            {
                mover=2;
            }
            else
            {
                mover = 1;
            }
        }
        if ((RainhaPreta == tabuleiro[linOri][colOri]) && ((dV == dH) || (dV == 0) || (dH == 0))) // Movimento da Rainha Preta
        {
            j = colOri;
            if ((linOri < linDes) && (colOri < colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri < linDes) && (colOri > colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri > linDes) && (colOri < colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri > linDes) && (colOri > colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else 
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri == linDes) && (colOri > colDes))
            {
                for (j = colOri; j >= colDes; j--)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)|| (tabuleiro[linDes][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] ==ReiBranco) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if ((linOri == linDes) && (colOri < colDes))
            {
                for (j = colOri; j <= colDes; j++)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)|| (tabuleiro[linDes][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] ==ReiBranco) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if ((linOri > linDes) && (colOri == colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if (i==linDes)//Permite que coma peça do oponente
                    {
                        if ((tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)|| (tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                        ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) ||(tabuleiro[i][j]==ReiBranco)||(tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {//garante que não pule peças
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if ((linOri < linDes) && (colOri == colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if (i==linDes)//Permite que coma peça do oponente
                    {
                        if ((tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)|| (tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                        ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) ||(tabuleiro[i][j]==ReiBranco)||(tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {//garante que não pule peças
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
        }
        if ((RainhaBranca == tabuleiro[linOri][colOri]) && ((dV == dH) || (dV == 0) || (dH == 0))) // Movimento da Rainha Branca
        {
            j = colOri;
            if ((linOri < linDes) && (colOri < colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri < linDes) && (colOri > colDes))
            {
                j = colOri;
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri > linDes) && (colOri < colDes))
            {
                j = colOri;
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri > linDes) && (colOri > colDes))
            {
                j = colOri;
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)|| (tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == ReiBranco) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)
                        ||(tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)) && (tabuleiro[i][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri > linDes) && (colOri == colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if (i==linDes)//Permite que coma peça do oponente
                    {
                        if ((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)|| (tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                        ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) ||(tabuleiro[i][j]==ReiBranco)||(tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {//garante que não pule peças
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if ((linOri < linDes) && (colOri == colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if (i==linDes)//Permite que coma peça do oponente
                    {
                        if ((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)|| (tabuleiro[i][colDes] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][colDes] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }else
                    {
                        if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                        ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) ||(tabuleiro[i][j]==ReiBranco)||(tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                        {//garante que não pule peças
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if ((linOri == linDes) && (colOri > colDes))
            {
                for (j = colOri; j >= colDes; j--)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)|| (tabuleiro[linDes][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] ==ReiBranco) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
            else if ((linOri == linDes) && (colOri < colDes))
            {
                for (j = colOri; j <= colDes; j++)
                {
                    if(j == colDes)
                    {
                        if ((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)|| (tabuleiro[linDes][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[linDes][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    else{
                        if (((tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == ReiPreto) || (tabuleiro[linDes][j] == PeaoPreto) || (tabuleiro[linDes][j] == TorrePreta)
                        ||(tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] ==ReiBranco) || (tabuleiro[linDes][j] == PeaoBranco) || (tabuleiro[linDes][j] == TorreBranca)) && (tabuleiro[linDes][j] != tabuleiro[linOri][colOri]))
                        {
                            return 9;
                        }
                        else
                        {
                            mover = 1;
                        }
                    }
                }
            }
        }
        if ((ReiPreto == tabuleiro[linOri][colOri]) && ((dV >= 0 && dV <= 1) && (dH >= 0 && dH <= 1))) // Movimento do Rei Preto
        {
            j=colOri;
            if ((linOri < linDes) && (colOri < colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)||(tabuleiro[i][j]==' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri < linDes) && (colOri > colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)||(tabuleiro[i][j]==' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri > linDes) && (colOri < colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)||(tabuleiro[i][j]==' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri > linDes) && (colOri > colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco)||(tabuleiro[i][j]==' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri < linDes) && (colOri == colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((tabuleiro[i][colDes] == TorrePreta) || (tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == PeaoPreto))
                    {
                        return 9;
                    }else if (tabuleiro[i][colDes] == ReiBranco)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
            else if ((linOri > linDes) && (colOri == colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((tabuleiro[i][colDes] == TorrePreta) || (tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == PeaoPreto))
                    {
                        return 9;
                    }else if (tabuleiro[i][colDes] == ReiBranco)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover= 1;
                    }
                }
            }
            else if ((linOri == linDes) && (colOri < colDes))
            {
                for (j = colOri; j <= colDes; j++)
                {
                    if ((tabuleiro[linDes][j] == TorrePreta) || (tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == PeaoPreto))
                    {
                        return 9;
                    }else if (tabuleiro[linDes][j] == ReiBranco)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
            else if ((linOri == linDes) && (colOri > colDes))
            {
                for (j = colOri; j >= colDes; j--)
                {
                    if ((tabuleiro[linDes][j] == TorrePreta) || (tabuleiro[linDes][j] == BispoPreto) || (tabuleiro[linDes][j] == CavaloPreto) || (tabuleiro[linDes][j] == RainhaPreta) || (tabuleiro[linDes][j] == PeaoPreto))
                    {
                        return 9;
                    }else if (tabuleiro[linDes][j] == ReiBranco)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
        }
        if ((ReiBranco == tabuleiro[linOri][colOri]) && ((dV >= 0 && dV <= 1) && (dH >= 0 && dH <= 1))) // Movimento do Rei Branco
        {
            j=colOri;
            if ((linOri < linDes) && (colOri < colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)||(tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri > linDes) && (colOri < colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)||(tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j++;
                }
            }
            else if ((linOri < linDes) && (colOri > colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)||(tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri > linDes) && (colOri > colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto)||(tabuleiro[i][j] == ' '))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j--;
                }
            }
            else if ((linOri == linDes) && (colOri < colDes))
            {
                for (j = colOri; j <= colDes; j++)
                {
                    if ((tabuleiro[linDes][j] == TorreBranca) || (tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco))
                    {
                        return 9;
                    }else if (tabuleiro[linDes][j] == ReiPreto)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
            else if ((linOri == linDes) && (colOri > colDes))
            {
                for (j = colOri; j >= colDes; j--)
                {
                    if ((tabuleiro[linDes][j] == TorreBranca) || (tabuleiro[linDes][j] == BispoBranco) || (tabuleiro[linDes][j] == CavaloBranco) || (tabuleiro[linDes][j] == RainhaBranca) || (tabuleiro[linDes][j] == PeaoBranco))
                    {
                        return 9;
                    }else if (tabuleiro[linDes][j] == ReiPreto)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
            else if ((linOri < linDes) && (colOri == colDes))
            {
                for (i = linOri; i <= linDes; i++)
                {
                    if ((tabuleiro[i][colDes] == TorreBranca) || (tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco))
                    {
                        return 9;
                    }else if (tabuleiro[i][colDes] == ReiPreto)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
            else if ((linOri > linDes) && (colOri == colDes))
            {
                for (i = linOri; i >= linDes; i--)
                {
                    if ((tabuleiro[i][colDes] == TorreBranca) || (tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] == PeaoBranco))
                    {
                        return 9;
                    }else if (tabuleiro[i][colDes] == ReiPreto)
                    {
                        mover=2;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
        }
        if ((PeaoPreto == tabuleiro[linOri][colOri]) && (linDes - linOri == 1) && ((dH == 0)||(dV==dH))) // Movimento do Peão Preto
        {
            if (colOri < colDes)
            {
                j = colOri;
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiBranco)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j++;
                }
            }
            else if(colOri > colDes)
            {
                j = colOri;
                for (i = linOri; i <= linDes; i++)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorreBranca) || (tabuleiro[i][j] == CavaloBranco) || (tabuleiro[i][j] == RainhaBranca) || (tabuleiro[i][j] == PeaoBranco) || (tabuleiro[i][j] == BispoBranco))
                        {
                            mover=1;
                        }else if ((tabuleiro[i][j] == ReiBranco))
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j++;
                }
            }
            else
            {
                for ( i = linOri; i <= linDes; i++)
                {
                    if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                    ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] ==ReiBranco) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                    {
                        return 9;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
        }
        if ((PeaoBranco == tabuleiro[linOri][colOri]) && (linOri - linDes == 1) && ((dH == 0)||(dV==dH))) // Movimento do Peão Branco
        {
            if (colOri < colDes)
            {
                j = colOri;
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j++;      
                }
            }
            else if (colOri > colDes)
            {
                j = colOri;
                for (i = linOri; i >= linDes; i--)
                {
                    if ((i==linDes)&&(j==colDes))
                    {
                        if ((tabuleiro[i][j] == TorrePreta) || (tabuleiro[i][j] == CavaloPreto) || (tabuleiro[i][j] == RainhaPreta) || (tabuleiro[i][j] == PeaoPreto) || (tabuleiro[i][j] == BispoPreto))
                        {
                            mover=1;
                        }else if (tabuleiro[i][j] == ReiPreto)
                        {
                            mover=2;
                        }
                        else
                        {
                            return 8;
                        }
                    }
                    j--;
                }
            }
            else if(colOri==colDes)
            {
                for ( i = linOri; i >=linDes; i--)
                {
                    if (((tabuleiro[i][colDes] == BispoPreto) || (tabuleiro[i][colDes] == CavaloPreto) || (tabuleiro[i][colDes] == RainhaPreta) || (tabuleiro[i][colDes] == ReiPreto) || (tabuleiro[i][colDes] == PeaoPreto) || (tabuleiro[i][colDes] == TorrePreta)
                    ||(tabuleiro[i][colDes] == BispoBranco) || (tabuleiro[i][colDes] == CavaloBranco) || (tabuleiro[i][colDes] == RainhaBranca) || (tabuleiro[i][colDes] ==ReiBranco) || (tabuleiro[i][colDes] == PeaoBranco) || (tabuleiro[i][colDes] == TorreBranca)) && (tabuleiro[i][colDes] != tabuleiro[linOri][colOri]))
                    {
                        return 9;
                    }
                    else
                    {
                        mover = 1;
                    }
                }
            }
        }
    }
    else
    {
        return 0;
    }
    if (mover == 1) 
    {
        tabuleiro[linDes][colDes] = tabuleiro[linOri][colOri];
        tabuleiro[linOri][colOri] = ' ';
        return 1; // Movimento Aprovado
    }
    else if (mover == 2)
    {
        tabuleiro[linDes][colDes] = tabuleiro[linOri][colOri];
        tabuleiro[linOri][colOri] = ' ';
        return 2;//Checkmate
    }else{
        return 8;
    }
}
#endif