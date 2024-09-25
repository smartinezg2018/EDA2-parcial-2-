#include <iostream>
#include <vector>
#include <unordered_map>


class Graph {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, float>> nodes;
    std::unordered_map<std::string,std::vector<float>> locales; //locales con coordenadas en el vector
    std::vector<std::string> initial_tour ;
    std::vector<std::string> locales_sur;
    std::vector<std::string> locales_norte;


public:

    void agregarLocal(std::string local, float lat, float lon);
    float calcularDistancia(std::string origen, std::string destino);
    void llenarAdyacencia() ;
    void imprimirAdyacencia() const;


    float calculate_tour_distance(const std::vector<std::string>& tour);
    std::vector<std::string> two_opt_swap(const std::vector<std::string>& tour, int i, int j);
    std::vector<std::string> two_opt();
    std::vector<std::string> two_opt_norte();
    std::vector<std::string> two_opt_sur();
    void imprimir();
    void ejecutar();




};
