#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
#include <math.h>


using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz) {

	nx = _nx;
	ny = _ny;
	nz = _nz;

	v = new Voxel * *[nx]; // Alocacao dinamica

	for (int i = 0; i < nx; i++) {
		v[i] = new Voxel * [ny];
	}

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			v[i][j] = new Voxel[nz];

		}
	}

	for (int i = 0; i < nx; i++) { // Atribuindo valores
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				v[i][j][k].isOn = false;
				v[i][j][k].r = 0;
				v[i][j][k].g = 0;
				v[i][j][k].b = 0;
				v[i][j][k].a = 0;
			}
		}
	}
}

Sculptor::~Sculptor() {

	for (int i = 0; i < nx; i++) { // Liberando as memorias
		for (int j = 0; j < ny; j++) {
			delete[] v[i][j];
		}
	}
	for (int i = 0; i < nx; i++) {
		delete[] v[i];
	}
	delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha) {

	this->r = r/255; // Foi usado o this-> porque as variaveis dos parametros
	this->g = g/255; // são iguais as variaveis protegidas das classes.
	this->b = b/255;
	a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
	v[x][y][z].isOn = true;
	v[x][y][z].r = r;
	v[x][y][z].g = g;
	v[x][y][z].b = b;
	v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z) {
	v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {

	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; k < z1; k++) {
				putVoxel(i, j, k);
			}
		}
	}
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; k < z1; k++) {
				cutVoxel(i, j, k);
			}
		}
	}
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {

	int x, y, z;

	for (int x = -radius; x <= radius; x++)
		for (int y = -radius; y <= radius; y++)
			for (int z = -radius; z <= radius; z++)
				// limitando o tamanho da esfera, nao pode ser menor que 0 e nem maior que nx,ny,nz
				if (((xcenter + x) < 0 || (xcenter + x) >= nx) || ((ycenter + y) < 0 || (ycenter + y) >= ny) || ((zcenter + z) < 0 || (zcenter + z) >= nz)) {
				}
				else {
					if (x * x + y * y + z * z < radius * radius)
						putVoxel(xcenter + x, ycenter + y, zcenter + z);
				}
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {

	int x, y, z;

	for (int x = -radius; x <= radius; x++)
		for (int y = -radius; y <= radius; y++)
			for (int z = -radius; z <= radius; z++)
				// limitando o tamanho da esfera, nao pode ser menor que 0 e nem maior que nx,ny,nz
				if (((xcenter + x) < 0 || (xcenter + x) >= nx) || ((ycenter + y) < 0 || (ycenter + y) >= ny) || ((zcenter + z) < 0 || (zcenter + z) >= nz)) {
				}
				else {
					if (x * x + y * y + z * z < radius * radius)
						cutVoxel(xcenter + x, ycenter + y, zcenter + z);
				}
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

	double x, y, z;

	for (int i = 0; i < nx; i++)
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nz; k++) {
				x = ((double)(i - xcenter) * (double)(i - xcenter)) / (rx * rx);
				y = ((double)(j - ycenter) * (double)(j - ycenter)) / (ry * ry);
				z = ((double)(k - zcenter) * (double)(k - zcenter)) / (rz * rz);

				if ((x + y + z) < 1)
					putVoxel(i, j, k);
			}
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {

	double x, y, z;

	for (int i = 0; i < nx; i++)
		for (int j = 0; j < ny; j++)
			for (int k = 0; k < nz; k++) {
				x = ((double)(i - xcenter) * (double)(i - xcenter)) / (rx * rx);
				y = ((double)(j - ycenter) * (double)(j - ycenter)) / (ry * ry);
				z = ((double)(k - zcenter) * (double)(k - zcenter)) / (rz * rz);

				if ((x + y + z) < 1)
					cutVoxel(i, j, k);
			}
}

void Sculptor::writeOFF(char* filename) {
	ofstream outFile;
	outFile.open(filename);

	int Nvoxel = 0;

	for (int i = 0; i < nx; i++) { // Conta quantos voxels tem no desenho
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].isOn) {
					Nvoxel++;
				}
			}
		}
	}

	outFile << "OFF" << endl << Nvoxel * 8 << " " << Nvoxel * 6 << " " << 0 << endl; // Calcula a quantidade de vertices e faces


	for (int i = 0; i < nx; i++) { // Declarando os pontos centrais de cada voxel
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].isOn) {
					outFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
					outFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
					outFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
					outFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
				}
			}
		}
	}

	int vertice = 0;
	outFile << setiosflags(ios::fixed); // Fixa a saida das cores em decimal float <iomanip>

	for (int i = 0; i < nx; i++) { // Declarando as faces
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].isOn) {
					outFile << 4 << " " << vertice + 0 << " " << vertice + 3 << " " << vertice + 2 << " " << vertice + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 4 << " " << vertice + 5 << " " << vertice + 6 << " " << vertice + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 1 << " " << vertice + 5 << " " << vertice + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 0 << " " << vertice + 4 << " " << vertice + 7 << " " << vertice + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 3 << " " << vertice + 7 << " " << vertice + 6 << " " << vertice + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					outFile << 4 << " " << vertice + 1 << " " << vertice + 2 << " " << vertice + 6 << " " << vertice + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					vertice = vertice + 8;
				}
			}
		}
	}
	outFile.close();
}