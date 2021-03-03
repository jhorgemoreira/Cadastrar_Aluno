#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DEFINIÇÃO DA ESTRUTURA ALUNO
typedef struct {

    int matricula;
    char nome[10];
    int idade;
    int notas[3];
    float media;

}ALUNO;

void Limpar_Tela() {

    system("cls");

}

void Menu() {

    printf("\t 1 - CADASTRAR ALUNOS \n ");
    printf("\t 2 - LISTAR ALUNOS \n ");
    printf("\t 3 - SAIR \n ");

}

void Cadastrar_Alunos() {

    FILE *arquivo; // CRIAR UMA VARIÁVEL DO TIPO ARQUIVO   
    ALUNO aluno;
        
    char nome[10];

    arquivo = fopen("aluno.txt", "ab"); // CRIAR O ARQUIVO ALUNO (CASO NÃO EXISTA) E ABRIR

    // VERIFICAR SE O ARQUIVO EXISTE
    if(arquivo == NULL) {

        printf("\t NÃO FOI POSSÍVEL ABRIR O ARQUIVO \n ");
        exit(0);

    }

    else {
                
        do {

            // INICIALIZAR A VARIÁVEL MÉDIA
            aluno.media = 0;

            printf("Informe a matrícula do aluno: \n ");
            scanf("%d", &aluno.matricula);
            fflush(stdin); // LIMPAR O BUFFER DO TECLADO APÓS DIGITAR O NOME
                        
            printf("Informe o nome do aluno: \n ");
            scanf("%s", nome);
            fflush(stdin);
            
            strcpy(aluno.nome, nome);

            printf("Informe a idade do aluno: \n ");
            scanf("%d", &aluno.idade);
            fflush(stdin);
            
            // INFORMAR AS TRÊS NOTAS DO ALUNO
            for(int j = 0; j < 3; j++) {

                printf("Informe a %d do aluno: \n ", (j+1));
                scanf("%d", &aluno.notas[j]);
                fflush(stdin);
                
                aluno.media += aluno.notas[j];

            }

            aluno.media = (aluno.media / 3);
            
            // GRAVAR OS DADOS INFORMADOS DO ALUNO NO ARQUIVO
            fwrite(&aluno, sizeof(ALUNO), 1, arquivo);

            printf("CADASTRAR OUTRO ALUNO (S/N) ? \n ");
                            
        }while(getchar() == 's'); // ENQUANTO O USUÁRIO DIGITAR A LETRA S SERÁ CADASTRADO UM NOVO ALUNO

    }

    //FECHAR O ARQUIVO
    fclose(arquivo);

}

void Listar_Alunos() {
    
    FILE *arquivo; // CRIAR UMA VARIÁVEL DO TIPO ARQUIVO
    ALUNO aluno;

    int j;

    arquivo = fopen("aluno.txt", "rb"); // ABRIR O ARQUIVO NO MODO LEITURA
    
    // VERIFICAR SE O ARQUIVO EXISTE
    if(arquivo == NULL) {

        printf("\t NÃO FOI POSSÍVEL ABRIR O ARQUIVO \n");
        exit(0);

    }

    else {
      
        printf("\t === LISTA DE ALUNOS === \n ");
        
        // LER O ARQUIVO ENQUANTO ELE NÃO ESTIVER VAZIO
        while(fread(&aluno, sizeof(ALUNO), 1, arquivo) != NULL) {
            
            // MOSTRAR OS DADOS DO ALUNO
            printf("\t MATRICULA: %d \n ", aluno.matricula);
            printf("\t NOME: %s \n ", aluno.nome);
            printf("\t IDADE: %d \n ", aluno.idade);

            // MOSTRAR AS TRÊS NOTAS
            for(j = 0; j < 3; j++) {

                printf("\t %d NOTA: %d \n ", (j+1), aluno.notas[j]);

            }

            // MOSTRAR A MÉDIA
            printf("\t MÉDIA: %.2f \n ", aluno.media);
            printf("\t ========================================== \n ");

        }

    }

    // FECHAR O ARQUIVO
    fclose(arquivo);

}

int main(void) {

    int opcao = 0;

    // CHAMADA DAS FUNÇÕES
    do {

        Menu();

        printf("Informe uma opção: \n ");
        scanf("%d", &opcao);
        
        Limpar_Tela();

        switch(opcao) {

            case 1:
            
                Cadastrar_Alunos();
                break;

            case 2:
            
                Listar_Alunos();
                break;
            
            case 3:

                exit(0);
                break;

            default:

                printf("\t OPÇÃO INVÁLIDA \n ");
                break;

        }
        
    }while(opcao != 0);

}

// DATA: 02/03/2021
// CRIADO POR: JORGE LUIS MOREIRA GOMES FILHO