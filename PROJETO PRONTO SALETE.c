#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Biblioteca para acentua��o
#include <string.h> // Biblioteca de string.
#include <ctype.h>  // Biblioteca para manipular caracteres.

int main(void) {
    ///VARIAVEIS PARA O CADASTRO DE EXAMES
    int i, j, opcao, quantidadedevagas[50], quantidadedeexames = 0, totalvagas = 0, opcaoCliente, cartaoSus[50], totalClientes = 0, cadastrado, encontradosMedicos, totalMedicos = 0, existe,examesRealizados[50]={0},consultasRealizadas[50]={0};
    char nomedoexame[50][50], useradm[10], senhaadm[10], user[10] = "adm", senha[10] = "1234", tabelaexame[50][50], nomecliente[50][50], exameEscolhido[50][50], exameMedicos[50][50];

    /// VARIAVEIS PARA O CADASTRO DE CONSULTAS
    int opcaoadm, quantidadedemedicos = 0, quantidadedevagasconsultas[50], totalvagasconsultas = 0, cartaoSusconsulta[50], totalclienteconsulta = 0, opcaoMedico, especialidadeEncontrada, pacientesEncontrados ;
    char nomemedico[50], especialidade[50], armazenaespecialidade[50][50], armazenanomemedicos[50][50], nomeclienteconsulta[50][50], consultaEscolhida[50][50], usermedico[50],especialidademedico[50];

    ///ACEITAR CARCTERES EM PORTUGUES
    setlocale(LC_ALL, "Portuguese");

    do {
        /// Menu de op��es para o usu�rio.
        printf("\n\x1B[38;5;14m--------------------------------------------");
        printf("\x1B[38;5;14m\n[1] - Adm\n[2] - Cliente\n[3] - M�dico\n[0] - Relat�rio do dia / finalizar\n");
        printf("\x1B[38;5;14m--------------------------------------------\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ///USER E SENHA DE ADM PARA ACESSAR, SER� PR� DEFINIDA
                printf("\x1B[38;5;208mDigite seu user: ");
                scanf("%s", useradm);
                printf("\x1B[38;5;208mDigite sua senha: ");
                scanf("%s", senhaadm);
                if (strcmp(useradm, user) == 0 && strcmp(senhaadm, senha) == 0) {
                    ///MENU DE OP��ES PARA O ADM
                    printf("\x1B[32mBem-vindo.");
                    printf("\x1B[38;5;208m\n[1] - Cadastrar exame\n[2] - Cadastrar especialidade\n[0] - Voltar\n");
                    scanf("%d", &opcaoadm);

                    switch (opcaoadm) {
                        case 1:
                            /// PERMITIR O CADASTRO DE EXAMES
                            while (1) {
                                printf("\x1B[38;5;208mDigite o nome do exame ou 'sair' para voltar ao menu inicial: ");
                                scanf(" %[^\n]", nomedoexame[quantidadedeexames]);
                                ///SE DIGITAR SAIR QUEBRA O LOOP, RETORNANDO AO MENU INICIAL
                                if (strcasecmp(nomedoexame[quantidadedeexames], "sair") == 0) {
                                    printf("\x1B[33mSaindo...");
                                    break;
                                }

                                ///INICIALIZA EXISTE COMO
                                existe = 0;
                                for (i = 0; i < quantidadedeexames; i++) {
                                    if (strcasecmp(nomedoexame[quantidadedeexames], tabelaexame[i]) == 0) {
                                        ///VERIFICA SE EXAME J� FOI CADASTRADO
                                        printf("\x1B[31mExame j� cadastrado.");
                                        ///SE EXISTE, N�O PERMITE CADASTRAR NOVAMENTE
                                        existe = 1;
                                        break;
                                    }
                                }

                                ///SE EXISTE, N�O PERMITE CADASTRAR NOVAMENTE
                                if (existe != 1) {
                                    printf("\x1B[38;5;208mQuantidade de vagas dispon�veis: ");
                                    scanf("%d", &quantidadedevagas[quantidadedeexames]); ///Recebe quantidade de vagas
                                    if (quantidadedevagas[quantidadedeexames] == 0) {
                                        printf("\x1B[31mQuantidade precisa ser maior que 0");
                                    } else {
                                        ///COPIA PARA TABELA DE EXAMES O NOME DO EXAME DIGITADO CASO PASSE POR TODAS AS VERIFICA��ES
                                        strcpy(tabelaexame[quantidadedeexames], nomedoexame[quantidadedeexames]);
                                        ///Total de vagas de exames incrementado
                                        totalvagas += quantidadedevagas[quantidadedeexames];
                                         ///Quantidade de exames incrementada
                                        quantidadedeexames++;
                                    }
                                }
                            } /// Fim do loop de cadastro
                            break;

                        case 2:
                            while (1) {
                                printf("\x1B[38;5;208mDigite o nome do m�dico ou 'sair': ");
                                scanf("%s", nomemedico);
                                ///SALVA NOME DO MEDICO QUE SER� USADO PARA VERIFICAR OS DADOS DOS PACIENTES QUE SER�O ATENDIDOS
                                if (strcasecmp(nomemedico, "sair") == 0) {
                                    ///Se digitar sair, sai do loop e volta ao menu inicial
                                    printf("\x1B[33mSaindo...");
                                    break;
                                }

                                printf("\x1B[38;5;208mDigite a especialidade do m�dico ou 'sair': ");
                                scanf("%s", especialidade);
                                ///SALVA ESPECIALIDADE DO MEDICO QUE SER� USADO PARA VERIFICAR OS DADOS DOS PACIENTES QUE SER�O ATENDIDOS
                                if (strcasecmp(especialidade, "sair") == 0) {
                                    ///Se digitar sair, sai do loop e volta ao menu inicial
                                    printf("\x1B[33mSaindo...");
                                    break; ///Se digitar sair, sai do loop
                                }

                                ///INICIALIZA EXISTE COMO 0 PARA VERIFICAR E EVITAR O CADASTRO DA MESMA ESPECIALIDADE
                                existe = 0;
                                for(i=0; i < quantidadedemedicos;i++){
                                    if(strcasecmp(especialidade, armazenaespecialidade[i])==0){
                                        printf("\x1B[31mEspecialidade j� cadastrada.\n");
                                        existe = 1;
                                        break;
                                    }
                                }

                                if(existe !=1){
                                    ///SE POSS�VEL SER� A QUANTIDADE DE ATENDIMENTOS POSS�VEIS
                                    printf("\x1B[38;5;208mDigite a quantidade de atendimentos ele poder� fazer: ");
                                    scanf("%d", &quantidadedevagasconsultas[quantidadedemedicos]);
                                    ///SE A QUANTIDADE DE ATENDIMENTOS FOR 0, N�O PERMITE CADASTRAR
                                    if(quantidadedevagasconsultas[quantidadedemedicos] == 0){
                                        printf("\x1B[31mQuantidade precisa ser maior que 0.\n");
                                    }else{
                                        strcpy(armazenaespecialidade[quantidadedemedicos], especialidade);
                                        strcpy(armazenanomemedicos[quantidadedemedicos], nomemedico);
                                        totalvagasconsultas += quantidadedevagasconsultas[quantidadedemedicos];
                                        quantidadedemedicos++;
                                    }

                                }
                            } //fim do loop de m�dicos
                            break;

                        case 0:
                            printf("\x1B[33mSaindo...");
                            break;

                        default:
                            printf("\x1B[31mOp��o inv�lida");
                            /// Adicionado para tratar o fim do default corretamente
                            break;
                    }
                } else {
                    ///Caso a senhaesteja errada mostra essa mensagem
                    printf("\x1B[31mSenha errada.\nContate o administrador de Banco de Dados para verificar sua situa��o.");
                }
                break;

            case 2:
                ///MENU CLIENTE
                printf("\x1B[32mBem-vindo Cliente.\n");
                printf("\x1B[38;5;12m[1] - Exames dispon�veis\n[2] - Marcar exame\n[3] - Mostrar consultas do dia\n[4] - Marcar consultas\n[5] - Menu Principal\n");
                scanf("%d", &opcaoCliente); ///Recebe as op��es do cliente

                switch (opcaoCliente) {
                    case 1:
                        if (quantidadedeexames == 0) {
                            printf("\x1B[31mN�o h� exames cadastrados."); ///Verifica se h� exames cadastrados
                        } else {
                            printf("\x1B[38;5;10mExames do dia:"); ///Mostra exames ainda dispon�veis.
                            for (i = 0; i < quantidadedeexames; i++) {
                                printf("\x1B[38;5;10m\n%s : %d vagas.", tabelaexame[i], quantidadedevagas[i]);
                            }
                            if (totalvagas == 0) {
                                printf("\x1B[31m\nN�o h� vagas dispon�veis."); /// Verifica vagas de exame
                            }
                        }
                        break; ///Fim do caso 1 de cliente "Exames dispon�veis

                    case 2:
                        if (quantidadedeexames == 0) {
                            printf("\x1B[31mN�o h� exames cadastrados.");
                            break;
                        }
                        printf("\n\x1B[38;5;10mDigite seu nome: ");
                        scanf(" %[^\n]", nomecliente[totalClientes]);
                        printf("\x1B[38;5;10mInforme seu cart�o do SUS: ");
                        scanf("%d", &cartaoSus[totalClientes]);

                        /// Verifica se o cliente j� est� cadastrado
                        existe = 0;
                        for (i = 0; i < totalClientes; i++) {
                            if (cartaoSus[totalClientes] == cartaoSus[i]) {
                                printf("\x1B[31mVoc� j� se cadastrou com este cart�o do SUS!\n");
                                existe = 1;
                                break;
                            }
                        }

                        if (existe) break;

                        /// Recebe o nome do exame escolhido
                        printf("Qual exame: ");
                        scanf(" %[^\n]", exameEscolhido[totalClientes]);

                        /// Verifica se o exame existe e tem vagas
                        for (i = 0; i < quantidadedeexames; i++) {
                            if (strcasecmp(exameEscolhido[totalClientes], tabelaexame[i]) == 0) {
                                if (quantidadedevagas[i] > 0) {
                                    printf("Voc� foi cadastrado com sucesso.\n");
                                    ///DECREMENTA QUANTIDADE DE VAGS DO EXAME
                                    quantidadedevagas[i]--;
                                    ///INCREMENTA EXAMES REALIZADO
                                    examesRealizados[i]++;
                                    ///DECREMENTA O TOTAL DE VAGAS DE EXAMES
                                    totalvagas--;
                                    ///Adiciona o cliente ao cadastro
                                    totalClientes++;

                                    /// Armazena as informa��es do paciente
                                    strcpy(nomecliente[totalClientes - 1], nomecliente[totalClientes - 1]);
                                    cartaoSus[totalClientes - 1] = cartaoSus[totalClientes - 1];
                                    strcpy(exameEscolhido[totalClientes - 1], exameEscolhido[totalClientes - 1]);
                                } else {
                                    ///SE QUANTIDADE DE VAGAS FOR 0, OU N�O HAVER EXAME EXIBE A MENSAGEM ABAIXO
                                    printf("\033[31mN�o h� vagas dispon�veis para o exame %s.\n", tabelaexame[i]);
                                }
                                break;
                            }
                        }

                        if (i == quantidadedeexames) {
                            /// Verifica se o exame escolhido est� disponivel
                            printf("\033[31mO exame %s n�o est� dispon�vel hoje.\n", exameEscolhido[totalClientes]);
                        }
                        break;

                    case 3:
                        if(quantidadedemedicos == 0){
                            printf("\nN�o h� vagas dispon�veis.");
                            break;
                        }else{
                            printf("Consultas do dia:");
                            for(i = 0; i < quantidadedemedicos;i++){
                                printf("\nM�dico: %s\nEspecialidade: %s\nVagas: %d.", armazenanomemedicos[i], armazenaespecialidade[i], quantidadedevagasconsultas[i]);

                            }
                        }
                        break;
                    case 4:
                        if (totalvagasconsultas == 0) {
                            for(i = 0; i < quantidadedemedicos;i++){
                                printf("\nM�dico: %s\nEspecialidade: %s\nVagas: %d.", armazenanomemedicos[i], armazenaespecialidade[i], quantidadedevagasconsultas[i]);

                            }
                            printf("\x1B[31mN�o h� consultas cadastradas.\n");
                            break;
                        }

                        /// Solicita o nome do cliente
                        printf("Digite seu nome: ");
                        scanf(" %[^\n]", nomeclienteconsulta[totalclienteconsulta]);

                        /// Solicita o cart�o do SUS
                        printf("Informe seu cart�o do SUS: ");
                        scanf("%d", &cartaoSusconsulta[totalclienteconsulta]);

                        /// Verifica se o cliente j� est� cadastrado
                        existe = 0;
                        for (i = 0; i < totalclienteconsulta; i++) {
                            if (cartaoSusconsulta[totalclienteconsulta] == cartaoSusconsulta[i]) {
                                printf("\x1B[31mVoc� j� se cadastrou com este cart�o do SUS!\n");
                                existe = 1;
                                break;
                            }
                        }

                        if (existe) break;

                        /// Solicita a especialidade desejada
                        printf("Digite a especialidade que quer marcar: ");
                        scanf(" %[^\n]", consultaEscolhida[totalclienteconsulta]);

                        /// Verifica se a especialidade est� cadastrada e se h� vagas
                        especialidadeEncontrada = 0;
                        for (i = 0; i < quantidadedemedicos; i++) {
                            if (strcasecmp(consultaEscolhida[totalclienteconsulta], armazenaespecialidade[i]) == 0) {
                                especialidadeEncontrada = 1;  /// Marca que a especialidade foi encontrada

                                /// Verifica se h� vagas dispon�veis para a consulta
                                if (quantidadedevagasconsultas[i] > 0) {
                                    printf("Consulta cadastrada com sucesso.");
                                    consultasRealizadas[i]++;
                                    /// Decrementa o n�mero de vagas para a especialidade
                                    quantidadedevagasconsultas[i]--;
                                     /// Decrementa o total de vagas dispon�veis
                                    totalvagasconsultas--;
                                     /// Incrementa o total de clientes cadastrados
                                    totalclienteconsulta++;

                                    /// Armazena as informa��es do cliente e da consulta
                                    strcpy(nomeclienteconsulta[totalclienteconsulta - 1], nomeclienteconsulta[totalclienteconsulta - 1]);
                                    cartaoSusconsulta[totalclienteconsulta - 1] = cartaoSusconsulta[totalclienteconsulta - 1];
                                    strcpy(consultaEscolhida[totalclienteconsulta - 1], consultaEscolhida[totalclienteconsulta - 1]);
                                } else {
                                    printf("\x1B[31mN�o h� vagas dispon�veis para a especialidade %s\n", armazenaespecialidade[i]);
                                }
                                break;  /// Encerra o loop ap�s encontrar a especialidade
                            }
                        }

                        /// Se a especialidade n�o foi encontrada
                        if (!especialidadeEncontrada) {
                            printf("\x1B[31mEspecialidade n�o encontrada.\n");
                        }

                        break;
                    case 5:
                        printf("Saindo");
                        break;
                }
                break;

            case 3:
                printf("Bem vindo(a) Doutor.\n");
                printf("Digite seu nome: ");
                scanf(" %s", usermedico);
                printf("Digite sua especiaidade: ");
                scanf("%s", especialidademedico);

                for(i=0;i<quantidadedemedicos;i++){
                    if(strcmp(usermedico,armazenanomemedicos[i])== 0 && strcmp(especialidademedico, armazenaespecialidade[i]) == 0){
                        while(1){
                            printf("\x1B[38;5;12m[1] - Verificar pacientes dos exames\n[2] - Verificar pacientes das consultas\n[0] - Retornar ao menu\n");
                            scanf("%d", &opcaoMedico);

                            switch (opcaoMedico){
                                case 1:
                                if (quantidadedeexames == 0) {
                                    printf("\x1B[31mN�o h� exames cadastrados.\n");
                                    break;
                                }
                                printf("\x1B[38;5;12mVoc� � m�dico de responsavel por quais exames:");
                                scanf(" %[^\n]", exameMedicos[totalMedicos]);

                                existe = 0;  /// Inicializa com 0 , pois nenhum exame foi encotrado.
                                for (i = 0; i < quantidadedeexames; i++) {
                                if (strcasecmp(exameMedicos[totalMedicos], tabelaexame[i]) == 0) {///Utilizar totalMedicos com indice do vetor , permite leituras de v�rias strings.
                                    printf("Exame existe.");///TALVEZ PRECISE APAGAR
                                    existe = 1;///Se for encontrado , passa ser 1, ou seja, (true). Verdadeiro.
                                    break;

                                }
                                }

                                if (existe != 1) { /// Se for diferente de 1 , siginifica que o exame n�o foi encontrado.

                                printf("Exame n�o encontrado.");
                                break;

                                }

                                /// Imprime as informa��es dos pacientes cadastrados para o exame
                                printf("Pacientes cadastrados para o exame %s:\n", exameMedicos[totalMedicos]);
                                for (i = 0; i < totalClientes; i++) {
                                if (strcasecmp(exameEscolhido[i], exameMedicos[totalMedicos]) == 0) {
                                    printf("Nome: %s\n", nomecliente[i]);
                                    printf("Cart�o do SUS: %d\n", cartaoSus[i]);
                                    printf("\n");
                                }
                                }

                                break;
                                case 2:
                                    if (quantidadedemedicos == 0) {
                                        printf("\x1B[31mN�o h� m�dicos cadastrados.");
                                        break;
                                    }

                                    /// Solicita a especialidade para a qual o m�dico � respons�vel
                                    printf("\x1B[38;5;12mVoc� � respons�vel por qual especialidade: ");
                                    scanf(" %[^\n]", especialidade);

                                    existe = 0;  /// Inicializa com 0, significa que a especialidade ainda n�o foi encontrada

                                    /// Verifica se a especialidade existe entre os m�dicos cadastrados
                                    for (i = 0; i < quantidadedemedicos; i++) {
                                        if (strcasecmp(especialidade, armazenaespecialidade[i]) == 0) {  /// Verifica se a especialidade existe
                                            printf("\x1B[32mEspecialidade encontrada.\n");
                                            existe = 1;  /// Marca como verdadeira (1), a especialidade foi encontrada
                                            break;
                                        }
                                    }

                                    if (existe != 1) {  /// Se a especialidade n�o for encontrada
                                        printf("\x1B[31mEspecialidade n�o encontrada.");
                                        break;
                                    }

                                    /// Imprime as informa��es dos pacientes cadastrados para a especialidade
                                    /// Verifica se o paciente escolheu essa especialidade
                                    pacientesEncontrados = 0;
                                    for (i = 0; i < totalclienteconsulta; i++) {
                                        if (strcasecmp(consultaEscolhida[i], especialidade) == 0) {
                                            printf("\x1B[38;5;12mNome: %s\n", nomeclienteconsulta[i]);
                                            printf("Cart�o do SUS: %d\n", cartaoSusconsulta[i]);
                                            pacientesEncontrados = 1;
                                        }
                                    }


                                    if (pacientesEncontrados == 0) {
                                        printf("\x1B[31mNenhum paciente cadastrado para a especialidade %s.\n", especialidade);
                                    }

                                    break;


                                case 0:
                                    printf("\x1B[33mSaindo.\n");
                                    break;
                                default:
                                    printf("\x1B[31mOp��o inv�lida.\n");

                            }
                            break;
                        }
                    }else{
                        printf("\x1B[31mNome ou especialidade incorretos.\n");
                    }
                }


            break;
            case 0:
                /// Mostra o relat�rio final.
                printf("Relat�rio final do dia...\n");
                printf("\033[1;35mExames realizados hoje e vagas ocupadas\n");
                for (i = 0; i < quantidadedeexames; i++) {

                    printf("\n%s : %d vagas.", tabelaexame[i], examesRealizados[i]);
                }
                printf("\nConsultas realizadas e vagas ocupadas");
                for (i = 0; i < quantidadedemedicos; i++) {
                    printf("\n%s : %d consultas.", armazenaespecialidade[i], consultasRealizadas[i]);
                }

                printf("\n\033[3m\x1B[33mSaindo..\n");
                printf("\n\033[33m--------------------------------------------");
        }
    } while (opcao != 0);

    return 0;
}
