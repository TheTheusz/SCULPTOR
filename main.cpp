#include "sculptor.h"

int main() {
	Sculptor saturno(51, 51, 51);
	saturno.setColor(152, 50, 17, 1);
	saturno.putSphere(25, 25, 25, 25);
	saturno.setColor(135, 44, 12, 1);
	saturno.putSphere(25, 25, 25, 24);
	saturno.setColor(185, 62, 23, 1);
	saturno.putSphere(25, 25, 25, 23);
	saturno.setColor(152, 50, 17, 1);
	saturno.putSphere(25, 25, 25, 22);
	saturno.setColor(185, 62, 23, 1);
	saturno.putSphere(25, 25, 25, 21); // anel

	saturno.cutSphere(25, 25, 25, 20);
	saturno.cutBox(0, 51, 0, 51, 0, 25);
	saturno.cutBox(0, 51, 0, 51, 26, 51);

	saturno.setColor(215, 91, 15, 1); // cor saturno
	saturno.putSphere(25, 25, 25, 16);


	saturno.setColor(140, 140, 140, 1); // cor das pedras
	saturno.putSphere(10, 10, 21, 1); // pedras
	saturno.putSphere(10, 10, 20, 1);
	saturno.putSphere(10, 9, 21, 1);

	saturno.putSphere(11, 42, 21, 1);
	saturno.putSphere(11, 42, 20, 1);
	saturno.putSphere(10, 41, 21, 1);
	saturno.putSphere(10, 41, 22, 1);
	saturno.putSphere(11, 40, 22, 1);

	saturno.putSphere(41, 16, 21, 1);
	saturno.putSphere(40, 15, 22, 1);
	saturno.putSphere(41, 15, 21, 1);

	saturno.putSphere(40, 42, 21, 1);
	saturno.putSphere(39, 42, 21, 1);
	saturno.putSphere(40, 41, 21, 1);
	saturno.putSphere(40, 41, 22, 1);


	saturno.putSphere(9, 10, 29, 1);
	saturno.putSphere(9, 11, 28, 1);
	saturno.putSphere(10, 11, 29, 1);

	saturno.putSphere(11, 42, 29, 1);
	saturno.putSphere(10, 40, 28, 1);
	saturno.putSphere(10, 41, 29, 1);
	saturno.putSphere(9, 40, 30, 1);
	saturno.putSphere(11, 40, 30, 1);

	saturno.putSphere(45, 20, 29, 1);
	saturno.putSphere(44, 21, 30, 1);
	saturno.putSphere(45, 21, 29, 1);

	saturno.putSphere(35, 48, 29, 1);
	saturno.putSphere(36, 48, 29, 1);
	saturno.putSphere(35, 49, 29, 1);
	saturno.putSphere(34, 47, 29, 1);



	saturno.putSphere(25, 47, 21, 1);
	saturno.putSphere(25, 48, 20, 1);

	saturno.putSphere(3, 28, 21, 1);
	saturno.putSphere(3, 26, 20, 1);
	saturno.putSphere(3, 28, 21, 1);
	saturno.putSphere(2, 27, 22, 1);
	saturno.putSphere(2, 26, 22, 1);

	saturno.putSphere(24, 4, 21, 1);
	saturno.putSphere(24, 4, 22, 1);
	saturno.putSphere(23, 3, 21, 1);

	saturno.putSphere(46, 26, 21, 1);
	saturno.putSphere(46, 25, 21, 1);
	saturno.putSphere(47, 25, 21, 1);
	saturno.putSphere(47, 26, 22, 1);


	saturno.putSphere(25, 47, 29, 1);
	saturno.putSphere(25, 48, 30, 1);

	saturno.putSphere(3, 28, 29, 1);
	saturno.putSphere(3, 26, 30, 1);
	saturno.putSphere(3, 28, 29, 1);
	saturno.putSphere(2, 27, 28, 1);
	saturno.putSphere(2, 26, 28, 1);

	saturno.putSphere(24, 4, 28, 1);
	saturno.putSphere(24, 4, 29, 1);
	saturno.putSphere(23, 3, 28, 1);

	saturno.putSphere(46, 30, 30, 1);
	saturno.putSphere(46, 29, 30, 1);
	saturno.putSphere(47, 29, 29, 1);
	saturno.putSphere(47, 30, 29, 1);

	saturno.putSphere(38, 8, 29, 1);
	saturno.putSphere(38, 7, 29, 1); // fim pedras

	saturno.setColor(255, 255, 255, 1); // foguete - branco
	saturno.putBox(42, 45, 38, 45, 40, 43);
	saturno.setColor(255, 0, 0, 1); // vermelho
	saturno.putBox(42, 45, 39, 40, 40, 43);
	saturno.putBox(42, 45, 41, 42, 40, 43);

	saturno.putBox(42, 45, 45, 46, 40, 43); //bico
	saturno.putBox(43, 44, 46, 48, 41, 42);

	saturno.setColor(140, 140, 140, 1); // cinza
	saturno.putBox(40, 42, 39, 40, 41, 42);
	saturno.putBox(45, 47, 39, 40, 41, 42);
	saturno.putBox(43, 44, 39, 40, 38, 40);
	saturno.putBox(43, 44, 39, 40, 43, 45);

	saturno.putBox(40, 41, 36, 39, 41, 42);
	saturno.putBox(46, 47, 36, 39, 41, 42);
	saturno.putBox(43, 44, 36, 39, 38, 39);
	saturno.putBox(43, 44, 36, 39, 44, 45);

	saturno.setColor(0, 204, 255, 1); // azul
	saturno.putSphere(43, 43, 42, 1);
	saturno.putSphere(43, 43, 40, 1);
	saturno.putSphere(42, 43, 41, 1);
	saturno.putSphere(44, 43, 41, 1);

	saturno.setColor(167, 28, 9, 0.5); // fogo - vermelho
	saturno.putBox(42, 45, 37, 38, 40, 43);

	saturno.putBox(45, 46, 34, 37, 42, 43);
	saturno.putBox(41, 42, 34, 37, 42, 43);
	saturno.putBox(45, 46, 34, 37, 40, 41);
	saturno.putBox(41, 42, 34, 37, 40, 41);

	saturno.putBox(44, 45, 34, 37, 43, 44);
	saturno.putBox(42, 43, 34, 37, 43, 44);
	saturno.putBox(44, 45, 34, 37, 39, 40);
	saturno.putBox(42, 43, 34, 37, 39, 40);

	saturno.setColor(251, 231, 56, 0.5); // fogo - amarelo
	saturno.putBox(43, 44, 37, 38, 40, 43);
	saturno.putBox(42, 45, 37, 38, 41, 42);
	saturno.putBox(43, 44, 36, 37, 40, 43);
	saturno.putBox(42, 45, 36, 37, 41, 42);
	saturno.putSphere(43, 35, 41, 1);
	saturno.putSphere(43, 34, 41, 1);
	saturno.putSphere(43, 33, 41, 1);

	saturno.setColor(242, 106, 6, 0.5); // fogo - laranja
	saturno.putSphere(42, 33, 42, 1);
	saturno.putSphere(44, 33, 40, 1);
	saturno.putSphere(42, 33, 40, 1);
	saturno.putSphere(44, 33, 42, 1);

	saturno.putBox(43, 44, 31, 33, 42, 43);
	saturno.putBox(43, 44, 31, 33, 40, 41);
	saturno.putBox(42, 43, 31, 33, 41, 42);
	saturno.putBox(44, 45, 31, 33, 41, 42);
	saturno.putSphere(43, 30, 41, 1); // fim foguete


	saturno.writeOFF((char*)"escultura.off");
	return 0;
}