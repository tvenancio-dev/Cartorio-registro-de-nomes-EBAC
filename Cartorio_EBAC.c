#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string's

int registro() //cria��o de fun��o para cada op��o do menu para melhorar a performance do sistema
{
	char arquivo[40]; //defini��o de uma vari�vel/string local
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char email[100];
	char telefone[40];
	char cargo[40];
	
	printf("Digite abaixo os dados a serem cadastrados:\n\n- CPF: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string's
	
	FILE *file; //criando o arquivo: fun��o falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos criar um arquivo file
	file = fopen(arquivo, "w"); //criando o arquivo: aqui ir� criar um arquivo com o nome "cpf", pois foi definido na fun��o da linha 17. Como ser� um arquivo novo, foi usado o "w" (write)
	fprintf(file, cpf); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma v�rgula no arquivo
	fclose(file); //fechando o arquivo

	printf("- Primeiro nome: ");	
	fgets(nome, sizeof(nome), stdin); //L� uma linha inteira, incluindo espa�os em branco, do texto digitado atrav�s entrada padr�o, ou seja, do teclado (fun��o "stdin")
	scanf("%s", nome); //armazenando o nome digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, nome); //incluindo a vari�vel "nome" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma v�rgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- Sobrenome completo: ");
	fgets(sobrenome, sizeof(sobrenome), stdin); //L� uma linha inteira, incluindo espa�os em branco, do texto digitado atrav�s entrada padr�o, ou seja, do teclado (fun��o "stdin")
	scanf("%s", sobrenome); //armazenando o sobrenome digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, sobrenome); //incluindo a vari�vel "sobrenome" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma v�rgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- E-mail: ");
	scanf("%s", email); //armazenando o e-mail digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, email); //incluindo a vari�vel "email" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma v�rgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- Telefone: ");
	fgets(telefone, sizeof(telefone), stdin); //L� uma linha inteira, incluindo espa�os em branco, do texto digitado atrav�s entrada padr�o, ou seja, do teclado (fun��o "stdin")
	scanf("%s", telefone); //armazenando o telefone digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, telefone); //incluindo a vari�vel "telefone" no arquivo
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, ","); //incluindo uma v�rgula no arquivo
	fclose(file); //fechando o arquivo
	
	printf("- Cargo na institui��o: ");
	fgets(cargo, sizeof(cargo), stdin); //L� uma linha inteira, incluindo espa�os em branco, do texto digitado atrav�s entrada padr�o, ou seja, do teclado (fun��o "stdin")
	scanf("%s", cargo); //armazenando o cargo digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para alterar e/ou incluir uma informa��o, por isso foi usado o "a" (alter)
	fprintf(file, cargo); //incluindo a vari�vel "cargo" no arquivo
	fclose(file); //fechando o arquivo
	
	printf("\n### Usu�rio cadastrado com sucesso! ###\n\n");	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //defini��o da linguagem e que se pode usar acentos
	
	char cpf[40]; //defini��o de uma vari�vel/string local
	char conteudo[400];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	FILE *file; //fun��o falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos consultar um arquivo file
	file = fopen(cpf, "r"); //abrindo o arquivo para consultar/ler uma informa��o, por isso foi usado o "r" (read) 
	
	if(file == NULL) //fun��o para sinalizar o usu�rio quando digitar um CPF n�o existente no banco de dados (NULL = nulo)
	{
		system("cls"); //limpar as op��es do menu sempre que o usu�rio escolher alguma op��o
		printf("\n### Usu�rio n�o cadastrado ou CPF digitado incorretamente! ###\n\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		
		// Separar os campos do conte�do do arquivo a partir do elemento virgula
    	char *token = strtok(conteudo, ",");
    	printf("- CPF: %s\n", token);

    	token = strtok(NULL, ",");
    	printf("- Nome: %s\n", token);
    
    	token = strtok(NULL, ",");
     	printf("- Sobrenome: %s\n", token);

    	token = strtok(NULL, ",");
    	printf("- E-mail: %s\n", token);
    	
    	token = strtok(NULL, ",");
    	printf("- Telefone: %s\n", token); 	
    	    	
   		token = strtok(NULL, ",");
    	printf("- Cargo na institui��o: %s\n", token);
	
		printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; //defini��o de uma vari�vel/string local
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); //armazenando o cpf digitado pelo usu�rio (fun��o "leia") / %s refere-se a string
	
	remove(cpf); //fun��o para deletar o arquivo do "banco de dados"
	
	FILE *file; //fun��o falando pro sistema buscar nas bibliotecas alguma estrutura chamada "FILE" porque iremos consultar um arquivo file
	file = fopen(cpf, "r"); //abrindo o arquivo para consultar/ler uma informa��o, por isso foi usado o "r" (read)
	
	if(file == NULL) //fun��o para informar ao usu�rio que o arquivo foi deletado do banco de dados se o mesmo for "nulo"
	{
		system("cls"); //limpar as op��es do menu sempre que o usu�rio escolher alguma op��o
		printf("\n### Usu�rio deletado com sucesso! ###\n\n");
		system("pause");
	}
}


int main() //fun��o principal (main) do sistema
{
	int opcao = 0; //defini��o de uma vari�vel local
	int laco = 1;
	
	for(laco=1; laco=1;) //"macete" do operador de repeti��o para sempre retornar ao menu principal
	{
		system("cls"); //limpar as op��es do menu sempre que o usu�rio escolher alguma op��o
		setlocale(LC_ALL, "Portuguese"); //defini��o da linguagem e que se pode usar acentos
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes;\n");
		printf("\t2 - Consultar nomes;\n");
		printf("\t3 - Deletar nomes;\n");
		printf("\t4 - Sair do sistema.\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio (fun��o "leia")
	
		system("cls"); //deletar todas mensagens antes desta fun��o (limpar a tela)
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamando a fun��o criada
			break;
			
			case 2:
			consulta(); //chamando a fun��o criada
			break;
			
			case 3:
			deletar(); //chamando a fun��o criada
			break;
			
			case 4:
			printf("### At� logo! ###\n");
			return 0;
			break;
			
			default:
			printf("### Essa op��o n�o est� dipon�vel! ###\n");
			system("pause");
			break; //fim da sele��o		
		}
	}
}
