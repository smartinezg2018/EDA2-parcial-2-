#include <iostream>
#include "Graph.h"
#include <chrono>

int main() {
    // Crear un grafo de ejemplo
    Graph graph;

    // Añadir los nodos y aristas (distancias) al grafo
    graph.agregarLocal("Bodega Norte",6.30000, -75.57000);
    graph.agregarLocal("D1 Laureles", 6.23457, -75.58132);
    graph.agregarLocal("D1 Centro", 6.24611, -75.56889);
    graph.agregarLocal("D1 Castilla", 6.28512, -75.55987);
    graph.agregarLocal("D1 Robledo", 6.29876, -75.58743);
    graph.agregarLocal("D1 Buenos Aires", 6.24032, -75.57561);
    graph.agregarLocal("D1 Manrique", 6.27394, -75.55203);
    graph.agregarLocal("D1 Aranjuez", 6.25817, -75.56128);
    graph.agregarLocal("D1 Floresta", 6.23019, -75.57845);
    graph.agregarLocal("D1 Estadio", 6.24931, -75.57014);
    graph.agregarLocal("D1 Belén", 6.26708, -75.56435);
    graph.agregarLocal("D1 Envigado", 6.17123, -75.58291);
    graph.agregarLocal("D1 Poblado", 6.20528, -75.56719);
    graph.agregarLocal("D1 Guayabal", 6.21854, -75.59320);
    graph.agregarLocal("D1 Itagüí", 6.16256, -75.60183);
    graph.agregarLocal("D1 Sabaneta", 6.14589, -75.61027);
    graph.agregarLocal("Bodega Sur",6.20000, -75.57000);
    graph.llenarAdyacencia();

    // std::cout << "\nRecorrido 2-opt: "<<std::endl;
    auto inicio = std::chrono::high_resolution_clock::now();
    graph.ejecutar();
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo de 2-opt: " << duracion.count() << " segundos" << std::endl;
    graph.imprimir();





    return 0;
}
