#include <stdio.h>
#include <string.h>

// ---------- Typedef e structs ----------

// Struct para datas
typedef struct
{
   int dia;
   int mes;
   int ano;
} Data;

// Struct principal Pessoa
typedef struct
{
   char nome[50];
   int idade;
   float altura;
   Data nascimento; // Struct aninhada
} Pessoa;

// ---------- Funções que manipulam structs ----------

// Passagem por valor (cópia)
void imprimePessoaValor(Pessoa p)
{
   printf("Por valor -> Nome: %s, Idade: %d, Altura: %.2f, Nascimento: %02d/%02d/%d\n",
          p.nome, p.idade, p.altura, p.nascimento.dia, p.nascimento.mes, p.nascimento.ano);
}

// Passagem por referência (mais eficiente)
void imprimePessoaRef(Pessoa *p)
{
   printf("Por referência -> Nome: %s, Idade: %d, Altura: %.2f, Nascimento: %02d/%02d/%d\n",
          p->nome, p->idade, p->altura, p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
}

// ---------- Função principal ----------
int main()
{
   // Inicialização direta
   Pessoa p1 = {"Vinicius", 19, 1.75, {18, 1, 2006}};

   // Alterando campos
   p1.idade = 20;
   p1.altura = 1.76;

   // Imprimindo
   imprimePessoaValor(p1);
   imprimePessoaRef(&p1);

   // Inicialização com designated initializers
   Pessoa p2 = {.idade = 22, .nome = "Ana", .altura = 1.68, .nascimento = {25, 12, 2003}};

   imprimePessoaRef(&p2);

   // Array de structs
   Pessoa turma[2];
   turma[0] = p1;
   turma[1] = p2;

   printf("\nTurma:\n");
   for (int i = 0; i < 2; i++)
   {
      printf("Aluno %d: %s, %d anos\n", i + 1, turma[i].nome, turma[i].idade);
   }

   // Copiando structs com memcpy
   Pessoa p3;
   memcpy(&p3, &p1, sizeof(Pessoa));
   printf("\nCópia de p1 -> p3: %s, %d anos\n", p3.nome, p3.idade);

   // Constantes
   const Pessoa p4 = {"Carlos", 30, 1.80, {10, 5, 1995}};
   printf("Pessoa constante -> %s, %d anos\n", p4.nome, p4.idade);
   // p4.idade = 31; // ERRO! Não pode modificar

   // Tamanho da struct e alinhamento
   printf("Tamanho da struct Pessoa: %lu bytes\n", sizeof(Pessoa));

   return 0;
}
