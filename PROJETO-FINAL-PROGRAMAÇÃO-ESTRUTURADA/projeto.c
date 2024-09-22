#include <stdio.h>
#include <string.h>
 
struct Animal{
    char nome[30];
    char tipo[20];
    char porte[20];
    int idade;
    char condicao_especial[30];
};
 
struct Data{
    int dia;
    int mes;
    int ano;
};
 
struct Cliente{
    char nome[50];
    char numero_telefone[20];
    char email_de_contato[50];
    int numero_animais;
};
 
struct Consulta{
    struct Animal animal;
    struct Data data;
    struct Cliente cliente;
    char horario[10];
};

int listar_consultas(struct Consulta consulta[],int i,FILE *arquivo){

    printf("===================================\n");
    printf("a. Os 5 primeiros registros.\n");
    printf("b. Os 5 ultimos registros.\n");
    printf("c. Todos os registros\n");
    printf("===================================\n\n");

    char opcao;
    printf("Escolha a opcao desejada:\n");
    scanf(" %c", &opcao);

    if (opcao != 'a' && opcao != 'b' && opcao != 'c'){
        printf("Insira uma opcao valida!!\n");
    }

    arquivo = fopen("Consulta.txt", "w");

    if (arquivo == NULL){
        printf("nao foi possivel abrir arquivo.\n");
        fclose(arquivo);
        return 1;
    }

    if (opcao == 'a'){
        
        if (i >= 5){
            for (int j = 0; j < 5; j++){

                fprintf(arquivo, "- Nome do(a) cliente %d: %s", j+1, consulta[j].cliente.nome);

                fprintf(arquivo, "- Telefone do(a) cliente %d: %s", j+1, consulta[j].cliente.numero_telefone);

                fprintf(arquivo, "- Email do(a) cliente %d: %s", j+1, consulta[j].cliente.email_de_contato);

                fprintf(arquivo, "- Numero de animais do(a) cliente %d: %d\n", j+1, consulta[j].cliente.numero_animais);

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
    if (opcao == 'b'){
        if (i >= 5){
            
            for (int j = i-5; j < i; j++){

            fprintf(arquivo, "- Nome do(a) cliente %d: %s", j+1, consulta[j].cliente.nome);

            fprintf(arquivo, "- Telefone do(a) cliente %d: %s", j+1, consulta[j].cliente.numero_telefone);

            fprintf(arquivo, "- Email do(a) cliente %d: %s", j+1, consulta[j].cliente.email_de_contato);

            fprintf(arquivo, "- Numero de animais do(a) cliente %d: %d\n", j+1, consulta[j].cliente.numero_animais);

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
    if (opcao == 'c'){
        
        for (int j = 0; j < i; j++){

            fprintf(arquivo, "- Nome do(a) cliente %d: %s", j+1, consulta[j].cliente.nome);

            fprintf(arquivo, "- Telefone do(a) cliente %d: %s", j+1, consulta[j].cliente.numero_telefone);

            fprintf(arquivo, "- Email do(a) cliente %d: %s", j+1, consulta[j].cliente.email_de_contato);

            fprintf(arquivo, "- Numero de animais do(a) cliente %d: %d\n", j+1, consulta[j].cliente.numero_animais);

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

    fclose(arquivo);
    return 0;
}

void buscar_consulta(struct Consulta consulta[],int i){
    
    int UID;

    for (int j = 0; j < i; j++){

    printf("- UID da consulta: %d - Nome do(a) cliente: %s", (j+1)*1831, consulta[j].cliente.nome);

    }
    printf("\n");

    printf("Insira o UID da consulta desejada para ver as informacoes:\n");
    scanf("%d", &UID);
    getchar();
    printf("\n");

    printf("Informacoes da consulta requerida:\n");

    printf("- Nome do(a) cliente %d: %s", (UID/1831), consulta[(UID/1831)-1].cliente.nome);
    printf("- Numero de telefone do(a) cliente %d: %s", (UID/1831), consulta[(UID/1831)-1].cliente.numero_telefone);
    printf("- Email para contato do(a) cliente %d: %s", (UID/1831), consulta[(UID/1831)-1].cliente.email_de_contato);
    printf("- Numero de animais do(a) cliente %d: %d\n",(UID/1831), consulta[(UID/1831)-1].cliente.numero_animais);
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

void atualizar_consulta(struct Consulta consulta[],int i){

    int UID;

    for (int j = 0; j < i; j++){

        printf("- UID da consulta: %d - Nome do(a) cliente: %s", (j+1)*1831, consulta[j].cliente.nome);

    }
    printf("\n");

    printf("Insira o UID da consulta a ser atualizada:\n");
    scanf("%d", &UID);
    getchar();
    printf("\n");

    printf("Insira o nome do(a) cliente %d:\n", (UID/1831));
    fgets(consulta[(UID/1831)-1].cliente.nome, sizeof(consulta[(UID/1831)-1].cliente.nome), stdin);

    printf("Insira o numero de telefone do(a) cliente %d:\n", (UID/1831));
    fgets(consulta[(UID/1831)-1].cliente.numero_telefone, sizeof(consulta[(UID/1831)-1].cliente.numero_telefone), stdin);

    printf("Insira o email de contato do(a) cliente %d:\n", (UID/1831));
    fgets(consulta[(UID/1831)-1].cliente.email_de_contato, sizeof(consulta[(UID/1831)-1].cliente.email_de_contato), stdin);

    printf("Insira o numero de animais do(a) cliente %d:\n", (UID/1831));
    scanf("%d", &consulta[(UID/1831)-1].cliente.numero_animais);
    getchar();

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

void remover_cosulta(struct Consulta consulta[],int *i){
    
    int UID;

    for (int j = 0; j < *i; j++){

        printf("- UID da consulta: %d - Nome do(a) cliente: %s", (j+1)*1831, consulta[j].cliente.nome);

    }
    printf("\n");

    printf("Insira o UID da consulta a ser removida:\n");
    scanf("%d", &UID);
    getchar();
    printf("\n");

    if ((UID/1831)-1 >= 0 && (UID/1831)-1 < *i){

        for (int j = (UID/1831)-1; j < *i; j++){

            strcpy(consulta[j].cliente.nome, consulta[j+1].cliente.nome);

            strcpy(consulta[j].cliente.numero_telefone, consulta[j+1].cliente.numero_telefone);

            strcpy(consulta[j].cliente.email_de_contato, consulta[j+1].cliente.email_de_contato);

            consulta[j].cliente.numero_animais = consulta[j+1].cliente.numero_animais;

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
   
    struct Consulta consulta[100];
 
    FILE *arquivo;
    arquivo = fopen("Consulta.txt","w");
    if(arquivo == NULL){
        printf("nao foi possivel abrir arquivo.");
        fclose(arquivo);
        return 1;
    }
    fclose(arquivo);
 
    int escolha;
    int i = 0;
 
    while(1){
 
        printf("============================================\n");
        printf("1. Adicionar um novo registro.\n");
        printf("2. Listar registros.\n");
        printf("3. Buscar um registro.\n");
        printf("4. Atualizar um registro.\n");
        printf("5. Remover um registro.\n");
        printf("============================================\n\n");

        printf("Escolha uma das opcoes:(0 pra parar)\n");
        scanf("%d", &escolha);
        getchar();
        printf("\n");

        if (escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4 && escolha != 5 && escolha != 0){
            printf("Escolha um numero valido!!\n");
        }
        if (escolha == 0){
            printf("Sistema finalizado com sucesso!\n");
            break;
        }

        if (escolha == 1){

            char resposta;
            printf("Gostaria de adicionar as informacoes da nova consulta no inicio(i) ou no final(f) do arquivo?\n");
            scanf(" %c", &resposta);
            getchar();
            printf("\n");

            if (resposta == 'i'){
            
                for (int j = i+1; j > 0; j--){

                    strcpy(consulta[j].cliente.nome, consulta[j-1].cliente.nome);

                    strcpy(consulta[j].cliente.numero_telefone, consulta[j-1].cliente.numero_telefone);

                    strcpy(consulta[j].cliente.email_de_contato, consulta[j-1].cliente.email_de_contato);

                    consulta[j].cliente.numero_animais = consulta[j-1].cliente.numero_animais;

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


                printf("Insira o nome do(a) cliente %d:\n", i+1);
                fgets(consulta[0].cliente.nome, sizeof(consulta[0].cliente.nome), stdin);

                printf("Insira o numero de telefone do(a) cliente %d:\n", i+1);
                fgets(consulta[0].cliente.numero_telefone, sizeof(consulta[0].cliente.numero_telefone), stdin);
                
                printf("Insira o email de contato do(a) cliente %d:\n", i+1);
                fgets(consulta[0].cliente.email_de_contato, sizeof(consulta[0].cliente.email_de_contato), stdin);

                printf("Insira o numero de animais do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[0].cliente.numero_animais);
                getchar();

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
                i++;
            }

            else if (resposta == 'f'){
                
                printf("Insira o nome do(a) cliente %d:\n", i+1);
                fgets(consulta[i].cliente.nome, sizeof(consulta[i].cliente.nome), stdin);

                printf("Insira o numero de telefone do(a) cliente %d:\n", i+1);
                fgets(consulta[i].cliente.numero_telefone, sizeof(consulta[i].cliente.numero_telefone), stdin);
                
                printf("Insira o email de contato do(a) cliente %d:\n", i+1);
                fgets(consulta[i].cliente.email_de_contato, sizeof(consulta[i].cliente.email_de_contato), stdin);

                printf("Insira o numero de animais do(a) cliente %d:\n", i+1);
                scanf("%d", &consulta[i].cliente.numero_animais);
                getchar();

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
                i++;
            }
            else{
                printf("Insira uma resposta valida!!\n");
            }
        }
 
        if (escolha == 2){

            listar_consultas(consulta, i, arquivo);
            
        }
 
        if (escolha == 3){
 
            buscar_consulta(consulta, i);
 
        }
 
        if (escolha == 4){

           atualizar_consulta(consulta, i);
           
        }
 
        if (escolha == 5){

            remover_cosulta(consulta, &i);
           
        }
    }
}