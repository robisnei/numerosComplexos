#include <stdio.h>
typedef struct{
	int real;
	int img;
}complex;

complex soma(complex a, complex b){
	complex resul;
	resul.real = a.real + b.real;
	resul.img = a.img + b.img;
	return resul;
}


complex mult(complex a, complex b){
	complex resul;
	resul.real = (a.real*b.real) + (a.img*b.img)*(-1);
	resul.img = ((a.img*b.real) + (a.real*b.img));
	return resul;
}

complex dif(complex a, complex b){
	complex resul;
	resul.real = a.real - b.real;
	resul.img = a.img - b.img;
	return resul;
}

complex div(complex a, complex b){
	complex resul;
	b.img= b.img*-1;
	resul = mult(a, b);
	
	return resul;
}


void main(){
	complex a;
	complex b;
	complex resul;
	int divi;
	int esc;
	
	
	printf("Digite os valores para o numero complexo A:\n");
	scanf("%d %d", &a.real, &a.img);
	
	
	printf("Digite os valores para o numero complexo B:\n");
	scanf("%d %d", &b.real, &b.img);
	
	printf("Digite qual operacao deseja fazer: (1-Soma, 2-Multiplicacao, 3-Diferenca, 4-divisao)\n");
	scanf("%d", &esc);
	

	if (esc == 4){
		resul = div(a,b);
		divi = b.real*b.real + b.img*b.img;
		if (resul.real%divi == 0){
			if (resul.real/divi != 0){
				printf("%d", resul.real/divi);
			}	
		}else{
			printf("%d/%d", resul.real, divi);
		}
		
		if (resul.img%divi == 0){
			if (resul.img/divi != 0){
				printf("%di", resul.img/divi);
			}
		}else{
			printf("%di/%d", resul.img, divi);
		}
		
	}else{
			if (esc == 1){
				resul= soma(a, b);
			}
			if (esc == 2){
				resul= mult(a, b);
			}
			if (esc == 3){
				resul= dif(a, b);
			}
			
			printf("%d,%di\n", resul.real, resul.img);
	}
}
