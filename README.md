# **SUBSTITUINDO REPLICAS**
### **PROPOSTA**
> Crie uma lista linear que consiga armazenar um conjunto de 100 nomes
quaisquer, os quais serão salvos de forma aleatória. Feito a estrutura crie a seguinte ação:
>- Uma função que consiga identificar replicações na lista, ou seja, nomes iguais. Remova
todas as réplicas sem mover os ”ponteiros“.
### **LOGICA**
1. Inicialmente, como forma da facilitar a constante leitura de nomes, foi criado um arquivo com a quantidade desejada de nomes para cada teste, sendo assim,
o primeiro passo envolvendo a logica do programa se da em ler o arquivo o qual contem os nomes.
   - Para tal tarefa, no arquivo **_main.cpp_** foi criada a funcao **_file_reading()_**, a qual recebe uma o endereco de memoria de uma lista.
      - Funcionamento da funcao **_file_reading()_**:
      1. Recebe o endereco de uma Lista anteriormente criada;
      2. Usando a biblioteca **<fstream>**, a leitura do arquivo é realizada da forma convencional;
      3. Para cada linha dor arquivo existe um, e somente um, nome, o qual é lido e salvo em uma variavel do tipo **Item**;
      4. O valor dessa variavel é usado como parametro a fim de ser inserido na lista, usando a funcao **_list_insert()_**;
      5. O laço se repete ate que o arquivo seja lido por completo.
2. Apos a leitura do arquivo, as funcoes usadas estarao presentes na funcao **main**, a qual sera utilizada como forma de "chamar" todos os recursos
necessarios a fim de, de fato, solucionar o problema.
    - Funcoes utilizadas na funcao **main**: 
       - **_create_empty_list()_**: cria uma lista vazia, estrutura utilizada como base para o funcionamento do programa;
       - **_file_reading()_**: realiza a leitura do arquivo e a insercao na lista anteriormente criada;
       - **_name_most_popsup()_**: informa ao usuario qual o nome com maior numero de aparicoes na lista;
       - **_list_print()_**: mostra ao usuario todas as informacoes armazenadas na lista;
       - **_replace_repeated_names()_**: responsavel por, de fato, realizar o que se é pedido.
3. A solucao do problema, como ja mencionado anteriormente, se da dentro da funcao **_replace_repeated_names()_**, a qual segue a seguinte logica:
    - Como forma de percorrer por toda a lista, comparando todos os nomes entre si, foi utilizado o metodo da bolha (for dentro de for);
    - No primeiro looping for, delimitado pela variavel **i** (comecando em 0,
    ou seja, a primeira posicao da lista, a qual contem o primeiro nome) é travada a posicao do nome que sera comparado com todos os outros. 
    Dentro do segundo looping for, delimitado pela variavel **j** (comecando sempre da a partir do valor **i + 1**, visando nao repetir nomes
    anteriormente comparados, nem mesmo comparar as mesmas posicoes) o qual percorrera toda a lista, efetuando comparacoes do nome atual em **j**
    com o nome travado em **i**;
    - Caso seja verdadeira a comparacao, isto é, ambos os nomes sendo iguais, o nome em **j** sera uma replica do nome que esta em **i**, portanto,
    ocorrera a remocao.
    - Visando o fato de serem usadas variaveis do tipo **_string_**, a fim de remover a replica, apenas eh substituido o valor por **"\0"**, o qual
    define uma **_string_** vazia.
### **OBSERVACOES**
1. Para correto funcionamento do programa:
   - A variavel global **MAXTAM** deve receber a quantidade total ou maior que a quantidade total de linhas presentes no arquivo;
   - Somente arquivos do tipo **.txt** sao aceitos;
   - Deve-se ter em mente que nomes em letras maiusculas e minusculas serao diferenciadas:
      - Exemplo: (Lucas == lucas) = false;
   - O nome do arquivo devera ser inserido na linha 8 do codigo, dentro da funcao **_file.open()_**:
      - Exemplo: file.open("nomedoarquivo.txt")
   - Nomes compostos sao aceitos;
   - Caso, em **_name_most_popsup()_** apareca mais de um nome pelo mesmo numero de vezes, apenas o primeiro a aparecer mais vezes sera mostrado.
### **COMPILACAO E EXECUCAO**
- A compilacao e execucao do arquivo se dao por meio do arquivo **Makefile** presente no repositorio, seguindo se seguinte ordem
de comandos, voce estara apto a compilar e executar o codigo.

| Comando | Resultado do comando |
| --- | --- |
| make clean | Apaga a ultima compilacao contida na pasta build. |
| make | Realiza uma nova compilacao utilizando g++, salvando-a na pasta build. |
| make run | Executa o programa caso a compilacao tenha sido concluida com exito. |

## **PERGUNTAS**
> Como você gerenciaria os espaços em branco para novas inserções?

- Resposta: Os espacos em branco seriam gerenciados como forma de informar ao programa que, naquela posicao, é possivel ser inserido um novo conteudo,
no caso, um novo nome, para isso, na funcao **_list_insert()_**, seria adicionada uma condicional e o atual metodo:
```c++
void list_insert(List *l, Item d) {
	if (l -> last >= MAXTAM) {
		printf("List is full!\n");
	} else {
		l -> vet[l->last] = d;
		l -> last++;
	}
}
```
se tornaria:
```c++
void list_insert(List *l, Item d) {
	int cont = 0;
    if (l -> last >= MAXTAM) {
		printf("List is full!\n");
	} else {
		for (int i = l -> first; i < l -> last; i++) {
            if (l -> vet[i].val == '\0') {
                l -> vet[i].val = d;
                cont++;
            }
        }
        
        if (cont == 0) {
            l -> vet[l->last] = d;
		    l -> last++;
        }
    }
}
// Podem haver problemas na identacao devido ao editor de codigo do GitHub.
```

> Qual seria o custo dessas novas inserções?

- O custo das novas insercoes podem variar e essa variacao pode ser analisada na tabela a seguir:

| Caso | Motivacao | Custo |
| --- | --- | --- |
| Melhor caso | Na hipotese de haver espaco em branco logo na segunda posicao da lista. | 2 |
| Caso medio | Caso somente haja espaco em branco somente no meio da lista. | n/2 |
| Pior caso | Caso haja espaco em branco somente na ultima posicao ou nao haja nenhum espaco. | n |

## SOCIAL MEDIA
- Twitter: @farinellizin
- Instagram: @farinellizin
- Telegram: @farinellizin
- E-mail: lucasfcpinho@gmail.com