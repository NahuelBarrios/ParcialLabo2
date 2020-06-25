/*
 ============================================================================
 Name        : main.c
 Author      : Nahuel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);

	LinkedList* pArrayArticulos = ll_newLinkedList();
	int option = 0;
	char path[51];

	while(option != 7)
	{
		printf("\n1-Cargar un archivo y abrirlo\n2-Ordenar\n3-Listar\n4-Realizar descuento\n5-Save datos\n6-Informe\n7-Salir");
		fflush(stdin);
		utn_getInt(&option,"\nElija una opcion: " ,"\nError\n",1,10,3);

		switch(option)
		{
		case 1:
			fflush(stdin);

			if(utn_getTexto("\nIngrese el nombre del archivo: ","\nError\n",3,51,3,path)==0)
			{
				if(controller_loadData(path,pArrayArticulos)==0)
					printf("\nSe cargo los datos correctamente\n");
				else
					printf("\nNo se cargo los datos correctamente\n");
			}
			break;
		case 2:
			if(controller_sortArticulos(pArrayArticulos)==0)
				printf("\nSe orden� por articulo y de manera ascendente con exito.\n");
			else
				printf("\nNo se pudo ordenar\n");
			break;
		case 3:
			controller_listArticulos(pArrayArticulos);
			break;
		case 4:
			if(controller_descuentoLimpieza(pArrayArticulos)==0)
				printf("\nSe realizo el descuento\n");
			else
				printf("\nNo se realizo el descuento\n");
			break;
		case 5:
			if(controller_saveData("mapeado.csv",pArrayArticulos)==0)
				printf("\nSe guardo el archivo con exito\n");
			else
				printf("\nNo se guardo el archivo con exito\n");
			break;
		case 6:
			if(controller_informe(pArrayArticulos)==0)
				printf("\nSe realizo el informe con exito\n");
			else
				printf("\nNo se realizo el informe con exito\n");
			break;
		case 7:
			printf("\nSali�.\n");
			break;
		default: printf("\nIngrese un valor del men�\n");
		}
	}
	return 0;
}
