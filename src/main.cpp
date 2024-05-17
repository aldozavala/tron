#include <iostream>//flujos de entrada y salida 
#include<ftxui/screen/screen.hpp>
#include<ftxui/dom/elements.hpp>
#include<thread>//hilos de proceso
#include<fstream>//flujos de archivos
#include<string>//control de cadenas
#include<Dibujo.hpp>
using namespace std;
using namespace ftxui;

    int main (int argc, char const *argv[])
    {
        Dibujo moto("./assets/assets/images/moto.txt");
        Dibujo bloque("./assets/assets/images/bloque.txt");
        int fotograma=0;
        while(true)
        {
       this_thread::sleep_for(0.1s);
        fotograma ++;
        Element personaje = spinner (21,fotograma) | bold | color(Color::Red) | bgcolor(Color::White);
       // Element eMoto = moto| bold | color(Color::Orange1) | bgcolor(Color::White);;
        Element dibujo = vbox({personaje,moto.GetElement(),bloque.GetElement()});
        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();

        
        }
        return EXIT_SUCCESS;
    }