#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <cmath>
#include <chrono> 
#include "Graph.h"
#include <thread>



void Graph::agregarLocal(std::string local, float lat, float lon){
    initial_tour.push_back(local);
    std::vector<float> ubicacion = {lat,lon};
    locales[local] = ubicacion;
}

float Graph::calcularDistancia(std::string origen, std::string destino){

    // float x1 = locales[origen][0];
    // float y1 = locales[origen][1];
    // float x2 = locales[destino][0];
    // float y2 = locales[destino][1];

    // float distancia = std::sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    // return distancia;


    double lat1_rad = locales[origen][0] * M_PI / 180.0;
    double lon1_rad = locales[origen][1] * M_PI / 180.0;
    double lat2_rad = locales[destino][0] * M_PI / 180.0;
    double lon2_rad = locales[destino][1]* M_PI / 180.0;

    double lat = lat2_rad - lat1_rad;
    double lon = lon2_rad - lon1_rad;


    double a = std::sin(lat / 2) * std::sin(lat / 2) +
               std::cos(lat1_rad) * std::cos(lat2_rad) *
               std::sin(lon / 2) * std::sin(lon / 2);

    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));


    double distancia = 6371.0 * c;

    return distancia;


}



void Graph::llenarAdyacencia() {
    locales_sur.push_back("Bodega Sur");
    locales_norte.push_back("Bodega Norte");

    for (const auto& pair : locales) {
        std::unordered_map<std::string, float> aristas; 
        for (const auto& pair2 : locales) {
            if (pair.first != pair2.first) {
                float distancia = calcularDistancia(pair.first, pair2.first);
                aristas[pair2.first] = distancia; 
            }
        }
        nodes[pair.first] = aristas;
        
        if(pair.first != "Bodega Sur" && pair.first != "Bodega Norte"){
        if(calcularDistancia("Bodega Sur",pair.first)<calcularDistancia("Bodega Norte", pair.first) && locales_sur.size()<(std::round(locales.size())/2)) locales_sur.push_back(pair.first);
        else locales_norte.push_back(pair.first);
        }
        
    }
    
}







void Graph::imprimirAdyacencia() const{
    for (const auto& pair : nodes) {
        std::cout << "Nodo: " << pair.first << " -> Adyacentes: ";

        for (const auto& vecino : pair.second) {
            std::cout<<vecino.first << " "<<vecino.second;
        }
        std::cout << std::endl;
    }
}




float Graph::calculate_tour_distance(const std::vector<std::string>& tour){
    float total_distance = 0;
    for (size_t i = 0; i < tour.size(); ++i) {
        total_distance += nodes[tour[i]][tour[(i + 1) % tour.size()]];
    }
    return total_distance;
}


std::vector<std::string> Graph::two_opt_swap(const std::vector<std::string>& tour, int i, int j) {

    std::vector<std::string> new_tour = tour;
    std::reverse(new_tour.begin() + i, new_tour.begin() + j + 1);
    return new_tour;
}





std::vector<std::string> Graph::two_opt() {

    
    std::vector<std::string> best_tour = initial_tour;
    bool improved = true;
    
    float best_distance = calculate_tour_distance(best_tour);

    while (improved) {

        improved = false;
        
        for (size_t i = 1; i < best_tour.size() - 2; ++i) {
            for (size_t j = i + 1; j < best_tour.size() - 1; ++j) {
              
                std::vector<std::string> new_tour = two_opt_swap(best_tour, i, j);
                float new_distance = calculate_tour_distance(new_tour);

                if (new_distance < best_distance) {
                    best_tour = new_tour;
                    best_distance = new_distance;
                    improved = true;
                    break;  
                }
            }
            if (improved) {
                break;
            }
        }
    }
    
    std::cout << "Mejor tour: ";
    for (const auto& node : best_tour) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout <<"distancia:"<<best_distance<< std::endl;


    return best_tour;
}




std::vector<std::string> Graph::two_opt_norte() {

    
    std::vector<std::string> best_tour = locales_norte;
    bool improved = true;
    
    float best_distance = calculate_tour_distance(best_tour);

    while (improved) {

        improved = false;
        
        for (size_t i = 1; i < best_tour.size() - 2; ++i) {
            for (size_t j = i + 1; j < best_tour.size() - 1; ++j) {
              
                std::vector<std::string> new_tour = two_opt_swap(best_tour, i, j);
                float new_distance = calculate_tour_distance(new_tour);

                if (new_distance < best_distance) {
                    best_tour = new_tour;
                    best_distance = new_distance;
                    improved = true;
                    break;  
                }
            }
            if (improved) {
                break;
            }
        }
    }
    
    std::cout << "Mejor tour: ";
    for (const auto& node : best_tour) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout <<"distancia:"<<best_distance<< std::endl;


    return best_tour;
}





std::vector<std::string> Graph::two_opt_sur() {

    
    std::vector<std::string> best_tour = locales_sur;
    bool improved = true;
    
    float best_distance = calculate_tour_distance(best_tour);

    while (improved) {

        improved = false;
        
        for (size_t i = 1; i < best_tour.size() - 2; ++i) {
            for (size_t j = i + 1; j < best_tour.size() - 1; ++j) {
              
                std::vector<std::string> new_tour = two_opt_swap(best_tour, i, j);
                float new_distance = calculate_tour_distance(new_tour);

                if (new_distance < best_distance) {
                    best_tour = new_tour;
                    best_distance = new_distance;
                    improved = true;
                    break;  
                }
            }
            if (improved) {
                break;
            }
        }
    }
    
    std::cout << "Mejor tour: ";
    for (const auto& node : best_tour) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout <<"distancia:"<<best_distance<< std::endl;


    return best_tour;
}


void Graph::ejecutar(){

    two_opt_sur();
    two_opt_norte();

}