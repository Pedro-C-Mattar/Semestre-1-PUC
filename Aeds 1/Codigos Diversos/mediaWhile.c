#include <stdio.h>

int main(){

    int idade = 0, contMulherSalario = 0, minIdade = 9999, maxIdade = 0, contPessoas = 0, salIdade = 0;
    char sexo, salSexo;
    double salario = 0, sumSalario = 0, media = 0, minSalario = 9999;

    while(idade >= 0){

        printf("Digite Idade: ");
        scanf(" %d", &idade);

        if(idade >= 0){

            printf("Digite Sexo (m/f): ");
            scanf(" %c", &sexo);
            printf("Digite Salario: ");
            scanf(" %lf", &salario);

            contPessoas ++;

            if(sexo == 'f' && salario <= 200){
                contMulherSalario ++;
            }

            if (salario < minSalario){
                minSalario = salario;
                salSexo = sexo;
                salIdade = idade;
            }

            if(idade > maxIdade){
                maxIdade = idade;
            }

            if(idade < minIdade){
                minIdade = idade;
            }

            sumSalario = sumSalario + salario;
        }
    }

    media = sumSalario / contPessoas;

    printf("Media dos Salarios: %.2lf", media);
    printf("\nMaior Idade: %d, Menor Idade: %d", maxIdade, minIdade);
    printf("\nMulheres com salario ate 200 reais: %d", contMulherSalario);
    printf("\nA pessoas com menor salario tem %d anos e sexo e %c", salIdade, salSexo);

}
