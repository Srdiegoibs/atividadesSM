/*
 * UTFPR - UNIVERSIDADE TECNOLÓGICA FEDERAL DO PARANÁ - CAMPUS TOLEDO
 *
 * Alunos: Diego da Silva, Kassiano Shiguematsu
 * Professor: LUIS CARLOS MATHIAS
 * 
 * 
 * E2 - Testar o E1 em alguma linguagem de baixo nível como o C
 */ 
#include <stdio.h>

int main()
{
    // atribuir valores do dividendo e do divisor
    unsigned char dividendo = 17;
    unsigned char divisor = 5;

    // entradas do usuario 
    // printf ("\nDenominador:\n>> ");
    // scanf ("%ld", &N);
    // printf ("\nDivisor:\n>> ");
    // scanf ("%ld", &d);

    // A    -> complemento do dividendo 
    // N    -> dividendo
    // d    -> divisor
    // cont -> numero de bits do divisor
    unsigned char A = 0;
    unsigned char N = dividendo;
    unsigned char d = divisor;

    for (int cont = 0; cont < 8; cont++)
    {
        // printf("teste aqui");
        // Passo 1: deslocar complemento do dividendo (A) 
        // eo dividendo (N) uma posição para a esquerda
        int AN = (A << 8) + N;
        AN <<= 1;
        A = (AN >> 8) & 0xFF;
        N = AN & 0xFF;

        // Passo 2: complemento (A) recebe subtração do  
        // divisor (d) do próprio complemento (A)
        A -= d;

        if (A & (1 << 7))
        {
            // se o complemento (A) menor que o dividendo (N)
            // ou seja se o bit de sinal de (A) for 1, adicionamos
            // um 0 a esquerda do dividendo N_0
            N &= ~1;

            // e soma o complemento (A) com o divisor
            A += d;
        } 
        else
        {
            // caso contrário, adicionar 1 a esquerda de N_0 
            N |= 1;
        } 
    }

    unsigned char quociente = N;
    unsigned char resto = A;

    printf ("%d / %d = %d\n", dividendo, divisor, quociente);
    printf ("%d %% %d = %d\n", dividendo, divisor, resto);
    

    return 0;
}