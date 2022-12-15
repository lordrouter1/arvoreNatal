// system() e rand()
#include <stdlib.h>
// scanf() e printf()
#include <stdio.h>
// time()
#include <time.h>

// Função que cria os espaços para centralizar a arvore, recebe o parametro _tam que define os espaços a serem aplicados
void espaco(int _tam)
{
    for(int i = 0; i < _tam; i++)
        printf(" ");
}

int main(void)
{
    // Cria as variáveis 
    int aTam;
    int aLargura;
    int aMetade;
    int nFolha = 1;
    
    // Define a hora como a semente para os numeros aleatórios 
    srand(time(NULL));

    // Inicia laço para verificar se o usuário vai informar um número menor que 6
    do
    {
        // Limpa a tela;
        system("clear");
        // Mensagem para o usuário
        printf("Informe um numero (<=6) para a arvore:");
        // Aguarda retorno do usuário
        scanf("%i",&aTam);
        // Se o número for maior que 6 repete o laço
    }while(aTam > 6);

    // Define a largura total da árvore
    aLargura = 5+(aTam*2);
    // Define o indice do meio da árvore
    aMetade = (aLargura/2)+1;

    // Define o espaço e imprime a estrela da arvore
    espaco(aMetade-1);
    printf("X\n");

    // Inicia loop para desenhar a árvore
    for(int i = 0; i < (3*aTam); i++)
    {
        // Define o espaço para alinhar a árvore
        espaco(aMetade-((nFolha/2)+1));

        // Inicia loop para desenhar as folhas
        for(int j = 0; j < nFolha; j++)
        {
            // Gera um número aleatório, se esse número for igual a 2 ele imprime uma bola de natal, caso contrario imprime a folha
            if(rand()%10+1 == 2)
                printf("o");
            else
                printf("*");

        }

        // Aumenta em 2 o tamanhos das folhas
        nFolha += 2;

        // A cada 3 Linhas reduz o numero de folhas da linha anterior em 2
        if((i+1) % 3 == 0)
            nFolha -= 4;
        // Aplica a quebra de linha para iniciar a nova linha de folhas
        printf("\n");
    }

    // Desenha o tronco da árvore
    espaco(aMetade-2);
    printf("| |\n");
    espaco(aMetade-2);
    printf("| |\n");
    espaco(aMetade-2);
    printf("---\n");

    return 0;
}