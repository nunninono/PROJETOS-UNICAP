// Importando as duas bibliotecas "stdio.h" e "string.h"
#include <stdio.h> 
#include <string.h>
 
struct Animal{      // Definindo o struct dos animais 
    char nome[30];
    char tipo[20];
    char porte[20];
    int idade;
    char condicao_especial[30];
};
 
struct Data{        // Definindo o struct da data
    int dia;
    int mes;
    int ano;
};
 
struct Cliente{     // Definindo o struct do cliente
    char nome[50];
    char numero_telefone[20];
    char email_de_contato[50];
    int numero_animais;
};
 
struct Consulta{    // Definindo o struct da consulta
    struct Animal animal;
    struct Data data;
    struct Cliente cliente;
    char horario[10];
};

// Definindo a função para printar as consultas no arquivo
int listar_consultas(struct Consulta consulta[],int i,FILE *arquivo){

    // Printando o menu interativo no terminal com as opções a, b, c
    printf("===================================\n");
    printf("a. Os 5 primeiros registros.\n");
    printf("b. Os 5 ultimos registros.\n");
    printf("c. Todos os registros\n");
    printf("===================================\n\n");

    // Criando e lendo a variavel opção
    char opcao;   
    printf("Escolha a opcao desejada:\n");
    scanf(" %c", &opcao);

    // Verificar se a resposta é uma das 3 válidas
    if (opcao != 'a' && opcao != 'b' && opcao != 'c'){
        printf("Insira uma opcao valida!!\n");
    }


    arquivo = fopen("Consulta.txt", "w");   // Abrindo arquivo no formato de escrita

    // Verificar se o arquivo existe
    if (arquivo == NULL){
        printf("nao foi possivel abrir arquivo.\n");
        fclose(arquivo);
        return 1;
    }

    // Condicional caso a escolha seja a 'a'
    if (opcao == 'a'){
        
        // Condicional para verificar se o arquivo possui ao menos 5 registros
        if (i >= 5){    

            // Laço de repetição para printar os 5 primeiros registros no arquivo 
            for (int j = 0; j < 5; j++){

                fprintf(arquivo, "- Nome do(a) cliente %d: %s", j+1, consulta[j].cliente.nome);

                fprintf(arquivo, "- Telefone do(a) cliente %d: %s", j+1, consulta[j].cliente.numero_telefone);

                fprintf(arquivo, "- Email do(a) cliente %d: %s", j+1, consulta[j].cliente.email_de_contato);

                fprintf(arquivo, "- Numero de animais do(a) cliente %d: %d\n", j+1, consulta[j].cliente.numero_animais);

                // Laço de repetição para printar os dados dos animais com base na quantidade 
                for (int k = 0; k < consulta[j].cliente.numero_animais; k++){
                    
                    fprintf(arquivo, "- Nome do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.nome);

                    fprintf(arquivo, "- Tipo(especie) do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.tipo);
                
                    fprintf(arquivo, "- Porte do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.porte);
                
                    fprintf(arquivo, "- Idade do animal %d do(a) cliente %d: %d\n", k+1, j+1, consulta[j].animal.idade);
                
                    fprintf(arquivo, "- Condicao especial do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.condicao_especial);
                
                }

                fprintf(arquivo, "- Data consulta do(a) cliente %d: %d\\%d\\%d as %s", j+1, consulta[j].data.dia, consulta[j].data.mes, consulta[j].data.ano, consulta[j].horario); 
                fprintf(arquivo, "\n");
            
            }
        }
        else{
            printf("\nNao tem registros suficientes! Insira outra opcao\n\n");
        }

    }

    // Condicional caso a escolha seja a 'b'
    if (opcao == 'b'){

        // Condicional para verificar se o arquivo possui ao menos 5 registros
        if (i >= 5){
            
            // Laço de repetição para printar os 5 ultimos registros no arquivo 
            for (int j = i-5; j < i; j++){

            fprintf(arquivo, "- Nome do(a) cliente %d: %s", j+1, consulta[j].cliente.nome);

            fprintf(arquivo, "- Telefone do(a) cliente %d: %s", j+1, consulta[j].cliente.numero_telefone);

            fprintf(arquivo, "- Email do(a) cliente %d: %s", j+1, consulta[j].cliente.email_de_contato);

            fprintf(arquivo, "- Numero de animais do(a) cliente %d\n: %d", j+1, consulta[j].cliente.numero_animais);

            // Laço de repetição para printar os dados dos animais com base na quantidade
            for (int k = 0; k < consulta[j].cliente.numero_animais; k++){
                
                fprintf(arquivo, "- Nome do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.nome);

                fprintf(arquivo, "- Tipo(especie) do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.tipo);
                
                fprintf(arquivo, "- Porte do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.porte);
                
                fprintf(arquivo, "- Idade do animal %d do(a) cliente %d: %d\n", k+1, j+1, consulta[j].animal.idade);
                
                fprintf(arquivo, "- Condicao especial do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.condicao_especial);
            
            }

            fprintf(arquivo, "- Data consulta do(a) cliente %d: %d\\%d\\%d as %s", j+1, consulta[j].data.dia, consulta[j].data.mes, consulta[j].data.ano, consulta[j].horario); 
            fprintf(arquivo, "\n");

            }

        }
        else{
            printf("\nNao tem registros suficientes! Insira outra opcao\n\n");
        }
    }

    // Condicional caso a escolha seja a 'c'
    if (opcao == 'c'){
        
        // Laço de repetição para printar todos os registros no arquivo 
        for (int j = 0; j < i; j++){

            fprintf(arquivo, "- Nome do(a) cliente %d: %s", j+1, consulta[j].cliente.nome);

            fprintf(arquivo, "- Telefone do(a) cliente %d: %s", j+1, consulta[j].cliente.numero_telefone);

            fprintf(arquivo, "- Email do(a) cliente %d: %s", j+1, consulta[j].cliente.email_de_contato);

            fprintf(arquivo, "- Numero de animais do(a) cliente %d: %d\n", j+1, consulta[j].cliente.numero_animais);

            // Laço de repetição para printar os dados dos animais com base na quantidade
            for (int k = 0; k < consulta[j].cliente.numero_animais; k++){
                
                fprintf(arquivo, "- Nome do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.nome);

                fprintf(arquivo, "- Tipo(especie) do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.tipo);
                
                fprintf(arquivo, "- Porte do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.porte);
                
                fprintf(arquivo, "- Idade do animal %d do(a) cliente %d: %d\n", k+1, j+1, consulta[j].animal.idade);
                
                fprintf(arquivo, "- Condicao especial do animal %d do(a) cliente %d: %s", k+1, j+1, consulta[j].animal.condicao_especial);
            
            }

            fprintf(arquivo, "- Data consulta do(a) cliente %d: %d\\%d\\%d as %s", j+1, consulta[j].data.dia, consulta[j].data.mes, consulta[j].data.ano, consulta[j].horario); 
            fprintf(arquivo, "\n");

        }
        printf("\n");
    }

    // Fechar o arquivo e retornar 0 para finalizar a função
    fclose(arquivo);
    return 0;
}

// Definindo função para buscar um registro específico
void buscar_consulta(struct Consulta consulta[],int i){
    
    int UID;    // Definindo a variável UID

    // Laço de repetição para printar todas as consultas com seu respectivo UID
    for (int j = 0; j < i; j++){

    // calculo usado no UID (numero da consulta*1831)
    printf("- UID da consulta: %d - Nome do(a) cliente: %s", (j+1)*1831, consulta[j].cliente.nome);

    }
    printf("\n");

    // Pedir ao usuário para inserir o UID da consulta desejada
    printf("Insira o UID da consulta desejada para ver as informacoes:\n");
    scanf("%d", &UID);
    getchar();
    printf("\n");

    // Printando no terminal todos os dados da consulta escolhida
    printf("Informacoes da consulta requerida:\n");

    printf("- Nome do(a) cliente %d: %s", (UID/1831), consulta[(UID/1831)-1].cliente.nome);

    printf("- Numero de telefone do(a) cliente %d: %s", (UID/1831), consulta[(UID/1831)-1].cliente.numero_telefone);

    printf("- Email para contato do(a) cliente %d: %s", (UID/1831), consulta[(UID/1831)-1].cliente.email_de_contato);

    printf("- Numero de animais do(a) cliente %d: %d\n",(UID/1831), consulta[(UID/1831)-1].cliente.numero_animais);

    // Laço de repetição para printar os dados dos animais com base na quantidade
    for (int k = 0; k < consulta[(UID/1831)-1].cliente.numero_animais; k++){

        printf("- Nome do animal %d do(a) cliente %d: %s", k+1, (UID/1831), consulta[(UID/1831)-1].animal.nome);

        printf("- Tipo(especie) do animal %d do(a) cliente %d: %s", k+1, (UID/1831), consulta[(UID/1831)-1].animal.tipo);

        printf("- Porte do animal %d do(a) cliente %d: %s", k+1, (UID/1831), consulta[(UID/1831)-1].animal.porte);

        printf("- Idade do animal %d do(a) cliente %d: %d\n", k+1, (UID/1831), consulta[(UID/1831)-1].animal.idade);

        printf("- Condicao especial do animal %d do(a) cliente %d: %s", k+1, (UID/1831), consulta[(UID/1831)-1].animal.condicao_especial);
    
    }
    printf("- Data da consulta do(a) cliente %d: %d//%d/%d as %s",(UID/1831), consulta[(UID/1831)-1].data.dia, consulta[(UID/1831)-1].data.mes, consulta[(UID/1831)-1].data.ano, consulta[(UID/1831)-1].horario);
    
    printf("\n");
}

// Definindo função para 
void atualizar_consulta(struct Consulta consulta[],int i){

    int UID;    // Definindo a variável UID

    // Laço de repetição para printar todas as consultas com seu respectivo UID
    for (int j = 0; j < i; j++){

        // calculo usado no UID (numero da consulta*1831)
        printf("- UID da consulta: %d - Nome do(a) cliente: %s", (j+1)*1831, consulta[j].cliente.nome);

    }
    printf("\n");

    // Pedir ao usuário para inserir o UID da consulta a ser atualizada
    printf("Insira o UID da consulta a ser atualizada:\n");
    scanf("%d", &UID);
    getchar();
    printf("\n");

    // Pede ao usuário os novos valores da consulta a ser substituida
    printf("Insira o nome do(a) cliente %d:\n", (UID/1831));
    fgets(consulta[(UID/1831)-1].cliente.nome, sizeof(consulta[(UID/1831)-1].cliente.nome), stdin);

    printf("Insira o numero de telefone do(a) cliente %d:\n", (UID/1831));
    fgets(consulta[(UID/1831)-1].cliente.numero_telefone, sizeof(consulta[(UID/1831)-1].cliente.numero_telefone), stdin);

    printf("Insira o email de contato do(a) cliente %d:\n", (UID/1831));
    fgets(consulta[(UID/1831)-1].cliente.email_de_contato, sizeof(consulta[(UID/1831)-1].cliente.email_de_contato), stdin);

    printf("Insira o numero de animais do(a) cliente %d:\n", (UID/1831));
    scanf("%d", &consulta[(UID/1831)-1].cliente.numero_animais);
    getchar();

    // Laço de repetição para pedir os dados dos animais com base na quantidade
    for (int j = 0; j < consulta[(UID/1831)-1].cliente.numero_animais; j++){
        printf("Insira o nome do animal %d do(a) cliente %d:\n", j+1, (UID/1831));
        fgets(consulta[(UID/1831)-1].animal.nome, sizeof(consulta[(UID/1831)-1].animal.nome), stdin);

        printf("Insira o tipo(especie) do animal %d do(a) cliente %d:\n", j+1, (UID/1831));
        fgets(consulta[(UID/1831)-1].animal.tipo, sizeof(consulta[(UID/1831)-1].animal.tipo), stdin);

        printf("Insira o porte do animal %d do(a) cliente %d: (grande ou pequeno)\n", j+1, (UID/1831));
        fgets(consulta[(UID/1831)-1].animal.porte, sizeof(consulta[(UID/1831)-1].animal.porte), stdin);

        printf("Insira a idade do animal %d do(a) cliente %d:\n", j+1, (UID/1831));
        scanf("%d", &consulta[(UID/1831)-1].animal.idade);
        getchar();

        printf("Insira a condicao especial(caso tenha) do animal %d do(a) cliente %d:\n", j+1, (UID/1831));
        fgets(consulta[(UID/1831)-1].animal.condicao_especial, sizeof(consulta[(UID/1831)-1].animal.condicao_especial), stdin);
    }
        
    printf("Insira o ano da consulta do(a) cliente %d:\n", (UID/1831));
    scanf("%d", &consulta[(UID/1831)-1].data.ano);
    getchar();

    printf("Insira o mes da consulta do(a) cliente %d:\n", (UID/1831));
    scanf("%d", &consulta[(UID/1831)-1].data.mes);
    getchar();

    printf("Insira o dia da consulta do(a) cliente %d:\n", (UID/1831));
    scanf("%d", &consulta[(UID/1831)-1].data.dia);
    getchar();

    printf("Insira o horario da consulta do(a) cliente %d (hh:mm):\n", (UID/1831));
    fgets(consulta[(UID/1831)-1].horario, sizeof(consulta[(UID/1831)-1].horario), stdin);

    printf("\n");
}

// Definir função para remover um registro
void remover_cosulta(struct Consulta consulta[],int *i){
    
    int UID;    // Definindo a variável UID

    // Laço de repetição para printar todas as consultas com seu respectivo UID
    for (int j = 0; j < *i; j++){

        // calculo usado no UID (numero da consulta*1831)
        printf("- UID da consulta: %d - Nome do(a) cliente: %s", (j+1)*1831, consulta[j].cliente.nome);

    }
    printf("\n");

    // Pedir ao usuário para inserir o UID da consulta a ser removido
    printf("Insira o UID da consulta a ser removida:\n");
    scanf("%d", &UID);
    getchar();
    printf("\n");

    // Condicional para verificar se há consultas no arquivo/registro
    if ((UID/1831)-1 >= 0 && (UID/1831)-1 < *i){
        
        // Laço de repetição para passar a informação da consulta seguinte para a consulta anterior 
        for (int j = (UID/1831)-1; j < *i; j++){

            strcpy(consulta[j].cliente.nome, consulta[j+1].cliente.nome);

            strcpy(consulta[j].cliente.numero_telefone, consulta[j+1].cliente.numero_telefone);

            strcpy(consulta[j].cliente.email_de_contato, consulta[j+1].cliente.email_de_contato);

            consulta[j].cliente.numero_animais = consulta[j+1].cliente.numero_animais;

            // Laço de repetição para passar os dados dos animais com base na quantidade
            for (int k = 0; k < consulta[j+1].cliente.numero_animais; k++){

                strcpy(consulta[j].animal.nome, consulta[j+1].animal.nome);

                strcpy(consulta[j].animal.tipo, consulta[j+1].animal.tipo);

                strcpy(consulta[j].animal.porte, consulta[j+1].animal.porte);

                consulta[j].animal.idade = consulta[j+1].animal.idade;

                strcpy(consulta[j].animal.condicao_especial, consulta[j+1].animal.condicao_especial);

            }
            
            consulta[j].data.ano = consulta[j+1].data.ano;

            consulta[j].data.mes = consulta[j+1].data.mes;

            consulta[j].data.dia = consulta[j+1].data.dia;

            strcpy(consulta[j].horario, consulta[j+1].horario);

        }
        (*i)--; // Diminuir 1 do valor apontado pelo ponteiro de i
    }
    else{
        printf("Nao tem consultas!! Insira alguma no item 2.\n");
    }
}


int main(){
   
    struct Consulta consulta[100];  // Definindo um struct com 100 posições
    
    // Cria o arquivo "Consulta.txt" no formato de escrita e o fecha logo em seguida
    FILE *arquivo;
    arquivo = fopen("Consulta.txt","w");
    if(arquivo == NULL){
        printf("nao foi possivel abrir arquivo.");
        fclose(arquivo);
        return 1;
    }
    fclose(arquivo);
 
    // Definir variaveis usadas nas funções
    int escolha;    //  Escolha do usuário no menu interativo
    int i = 0;      //  Numero de consultas
 
    //  Definindo um loop infinito para a função main 
    while(1){
        
        //  Printando um menu interativo com opções de 1 a 5
        printf("============================================\n");
        printf("1. Adicionar um novo registro.\n");
        printf("2. Listar registros.\n");
        printf("3. Buscar um registro.\n");
        printf("4. Atualizar um registro.\n");
        printf("5. Remover um registro.\n");
        printf("============================================\n\n");

        //  Pede ao usuário que insira uma das opções
        printf("Escolha uma das opcoes:(0 pra parar)\n");
        scanf("%d", &escolha);
        getchar();
        printf("\n");

        // Condicional para verificar se a escolha do usuário é uma das opções permitidas
        if (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4 && escolha != 5 && escolha != 0){
            printf("Escolha um numero valido!!\n");
        }
        // Condicional para encerrar o programa
        if (escolha == 0){
            printf("Sistema finalizado com sucesso!\n");
            break;
        }

        //  Condicional para caso a escolha tenha sido 1
        if (escolha == 1){
            
            // Define e pede ao usuário que insira onde vai ser inserida a nova consulta
            char resposta;      //  Resposta do usuário de onde vai ser inserida a nova consulta

            printf("Gostaria de adicionar as informacoes da nova consulta no inicio(i) ou no final(f) do arquivo?\n");
            scanf(" %c", &resposta);
            getchar();
            printf("\n");

            //  Condicional para caso a resposta tenha sido 'i'
            if (resposta == 'i'){
                
                //  Laço de repetição para fazer as consultas "pularem" um termo pra frente
                for (int j = i+1; j > 0; j--){

                    strcpy(consulta[j].cliente.nome, consulta[j-1].cliente.nome);

                    strcpy(consulta[j].cliente.numero_telefone, consulta[j-1].cliente.numero_telefone);

                    strcpy(consulta[j].cliente.email_de_contato, consulta[j-1].cliente.email_de_contato);

                    consulta[j].cliente.numero_animais = consulta[j-1].cliente.numero_animais;

                    // Laço de repetição para passar os dados dos animais com base na quantidade
                    for (int k = 0; k < consulta[j-1].cliente.numero_animais; k++){

                        strcpy(consulta[j].animal.nome, consulta[j-1].animal.nome);

                        strcpy(consulta[j].animal.tipo, consulta[j-1].animal.tipo);

                        strcpy(consulta[j].animal.porte, consulta[j-1].animal.porte);

                        consulta[j].animal.idade = consulta[j-1].animal.idade;

                        strcpy(consulta[j].animal.condicao_especial, consulta[j-1].animal.condicao_especial);

                    }
                    
                    consulta[j].data.ano = consulta[j-1].data.ano;

                    consulta[j].data.mes = consulta[j-1].data.mes;

                    consulta[j].data.dia = consulta[j-1].data.dia;

                    strcpy(consulta[j].horario, consulta[j-1].horario);

                }

                // Pede ao usuário os dados da consulta que será inserida na posição 0 do arquivo
                printf("Insira o nome do(a) cliente %d:\n", i+1);
                fgets(consulta[0].cliente.nome, sizeof(consulta[0].cliente.nome), stdin);

                printf("Insira o numero de telefone do(a) cliente %d:\n", i+1);
                fgets(consulta[0].cliente.numero_telefone, sizeof(consulta[0].cliente.numero_telefone), stdin);
                
                printf("Insira o email de contato do(a) cliente %d:\n", i+1);
                fgets(consulta[0].cliente.email_de_contato, sizeof(consulta[0].cliente.email_de_contato), stdin);

                printf("Insira o numero de animais do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[0].cliente.numero_animais);
                getchar();

                // Laço de repetição para pedir os dados dos animais com base na quantidade
                for (int j = 0; j < consulta[0].cliente.numero_animais; j++){
                    printf("Insira o nome do animal %d do(a) cliente %d:\n", j+1, i+1);
                    fgets(consulta[0].animal.nome, sizeof(consulta[0].animal.nome), stdin);

                    printf("Insira o tipo(especie) do animal %d do(a) cliente %d:\n", j+1, i+1);
                    fgets(consulta[0].animal.tipo, sizeof(consulta[0].animal.tipo), stdin);

                    printf("Insira o porte do animal %d do(a) cliente %d: (grande ou pequeno)\n", j+1, i+1);
                    fgets(consulta[0].animal.porte, sizeof(consulta[0].animal.porte), stdin);

                    printf("Insira a idade do animal %d do(a) cliente %d:\n", j+1, i+1);
                    scanf("%d", &consulta[0].animal.idade);
                    getchar();

                    printf("Insira a condicao especial(caso tenha) do animal %d do(a) cliente %d:\n", j+1, i+1);
                    fgets(consulta[0].animal.condicao_especial, sizeof(consulta[0].animal.condicao_especial), stdin);
                }

                printf("Insira o ano da consulta do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[0].data.ano);
                getchar();

                printf("Insira o mes da consulta do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[0].data.mes);
                getchar();

                printf("Insira o dia da consulta do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[0].data.dia);
                getchar();

                printf("Insira o horario da consulta do(a) cliente %d (hh:mm):\n", i+1);
                fgets(consulta[0].horario, sizeof(consulta[0].horario), stdin);

                printf("\n");
                i++;    // Adiciona 1 para o numero de consultas
            }

            //  Condicional para caso a resposta tenha sido 'f'
            else if (resposta == 'f'){
                
                //  Pede ao usuário as informações da nova consulta
                printf("Insira o nome do(a) cliente %d:\n", i+1);
                fgets(consulta[i].cliente.nome, sizeof(consulta[i].cliente.nome), stdin);

                printf("Insira o numero de telefone do(a) cliente %d:\n", i+1);
                fgets(consulta[i].cliente.numero_telefone, sizeof(consulta[i].cliente.numero_telefone), stdin);
                
                printf("Insira o email de contato do(a) cliente %d:\n", i+1);
                fgets(consulta[i].cliente.email_de_contato, sizeof(consulta[i].cliente.email_de_contato), stdin);

                printf("Insira o numero de animais do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[i].cliente.numero_animais);
                getchar();

                // Laço de repetição para pedir os dados dos animais com base na quantidade
                for (int j = 0; j < consulta[i].cliente.numero_animais; j++){
                    printf("Insira o nome do animal %d do(a) cliente %d:\n", j+1, i+1);
                    fgets(consulta[i].animal.nome, sizeof(consulta[i].animal.nome), stdin);

                    printf("Insira o tipo(especie) do animal %d do(a) cliente %d:\n", j+1, i+1);
                    fgets(consulta[i].animal.tipo, sizeof(consulta[i].animal.tipo), stdin);

                    printf("Insira o porte do animal %d do(a) cliente %d: (grande ou pequeno)\n", j+1, i+1);
                    fgets(consulta[i].animal.porte, sizeof(consulta[i].animal.porte), stdin);

                    printf("Insira a idade do animal %d do(a) cliente %d:\n", j+1, i+1);
                    scanf("%d", &consulta[i].animal.idade);
                    getchar();

                    printf("Insira a condicao especial(caso tenha) do animal %d do(a) cliente %d:\n", j+1, i+1);
                    fgets(consulta[i].animal.condicao_especial, sizeof(consulta[i].animal.condicao_especial), stdin);
                }

                printf("Insira o ano da consulta do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[i].data.ano);
                getchar();

                printf("Insira o mes da consulta do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[i].data.mes);
                getchar();

                printf("Insira o dia da consulta do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[i].data.dia);
                getchar();

                printf("Insira o horario da consulta do(a) cliente %d (hh:mm):\n", i+1);
                fgets(consulta[i].horario, sizeof(consulta[i].horario), stdin);

                printf("\n");
                i++;    //  Soma um no total de consultas
            }
            //  Pede ao usuário uma nova resposta caso a inputada seja considerada inválida
            else{
                printf("Insira uma resposta valida!!\n");
            }
        }

        //  Condicional para caso a escolha tenha sido 2
        if (escolha == 2){
            
            //  Chama a função "listar_consultas" com os parametros necessários
            listar_consultas(consulta, i, arquivo);
            
        }

        //  Condicional para caso a escolha tenha sido 3
        if (escolha == 3){
            
            //  Chama a função "buscar_consulta" com os parametros necessários
            buscar_consulta(consulta, i);
 
        }

        //  Condicional para caso a escolha tenha sido 4
        if (escolha == 4){
            
            //  Chama a função "atualizar_consulta" com os parametros necessários
            atualizar_consulta(consulta, i);
           
        }

        //  Condicional para caso a escolha tenha sido 5
        if (escolha == 5){
            
            //  Chama a função "remover_cosulta" com os parametros necessários
            remover_cosulta(consulta, &i);
           
        }
    }
}