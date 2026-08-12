#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void){
    Carrito c;
    const double descuento = 0.90;

    carrito_init(&c);
    Producto p = {"Pan",200,3};
    carrito_agregar(&c,p);
    Producto q = {"Leche",350,2};
    carrito_agregar(&c,q);

    ASSERT_IGUAL(1300, carrito_total(&c));
    
    double precioDescuento; 
    precioDescuento = carrito_total(&c) * descuento;

    ASSERT_IGUAL(1170,precioDescuento);

}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(void){
    Carrito c;
    carrito_init(&c);

    Producto catalogo [] = {
        {"Leche",200,2},
        {"Tomate",400,6},
        {"Gaseosa",200,3},
        {"Chocolinas",150,1}
    };
    
    for(int i = 0; i < 4 ; i++){
        carrito_agregar(&c,catalogo[i]);
    }

    ASSERT_IGUAL(MAX_ITEMS,carrito_contar(&c));
    
    ASSERT_IGUAL(0,carrito_agregar(&c,catalogo[0]));
    ASSERT_IGUAL(0,carrito_agregar(&c,catalogo[3]));
    
    ASSERT_IGUAL(MAX_ITEMS,carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
