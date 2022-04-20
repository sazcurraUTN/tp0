#include "client.h"
#include "utils.h"


int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;


	/* ---------------- LOGGING ---------------- */


	logger = iniciar_logger();

	logger = log_create("tp0.log","TP0",true,LOG_LEVEL_INFO);

	log_info(logger, "Hola! Soy un log :) Punto 1");



	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config


	config = config_create("cliente.config");

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	valor = config_get_string_value(config, "CLAVE");


	//log_info(logger,"Punto 2" ,valor);

	//log_info(logger,"Extra para verificar el PUERTO -> ", puerto);

	// log_info(logger,"Extra para verificar IP ->" , ip);



	/* ---------------- LEER DE CONSOLA ---------------- */

	// Punto 2B
//	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto); // socket_cliente

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(valor, conexion);

	// Armamos y enviamos el paquete
	paquete(conexion);

	log_destroy(logger);
	config_destroy(config);
	liberar_conexion(conexion);

//	terminar_programa(conexion, logger, config);



	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = NULL;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = NULL;

	return nuevo_config;
}


void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa

	do{

	leido = readline("Prueba > ");
	log_info(logger, leido);


	} while( strcmp(leido, "" ) != 0 );

	free(leido);


	// El resto, las vamos leyendo y logueando hasta recibir un string vacío

	// ¡No te olvides de liberar las lineas antes de regresar!

}


void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;


	// Leemos y esta vez agregamos las lineas al paquete
	paquete = crear_paquete();


	do{

	leido = readline("Mensaje ->");
	agregar_a_paquete(paquete,leido,strlen(leido) + 1);


	}while(strcmp(leido, "" ) != 0 );

	free(leido);

	enviar_paquete(paquete,conexion);

	eliminar_paquete(paquete);

	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}



void terminar_programa(int conexion, t_log* logger, t_config* config)
{


}


