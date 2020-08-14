/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 * Augusto Lourenço de Faria      RA: 194447
 * Como o código do cifrador a main apenas pega a string e imprime, logo a função de codificar faz tudo, decidi apenas trocar ela para uma que 	* decifra, no caso reverse_crypto
 */

#include <stdio.h>

#define TAM_BUFFER 50
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

int reverse_crypto (char x, char y){
	char i;
	
	//Caso seja algum char menor que 65 na tabela ASCII, assim volta o caracter enviado, exemplos: '!', '?', ':', esse modo não cobre alguns sinais maiores que 65 na tabela
	if(x < 65)
		return x;
	//Pega a diferença do char mandado para o começo 'A' assim sabendo o tamanho do shift
	x = x - 'A';	
	//Inicia o for no char 'A'=65, e vai andando pelo alfabeto
	//Pego o char que estou andando pelo alfabeto e somo a y que é o char da minha key, se o resto da divisão for igual ao shift, encontrei meu char o qual foi cryptado
	for(i=65; (i+y)%26 != x; i++);
	
	return i; 
}

int main() {
  int j=0;
  int i=0;

  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);


  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {

    buffer_saida[i] = reverse_crypto(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';


  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
