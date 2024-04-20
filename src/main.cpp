#include <iostream>//flujos de entrada y salida 
#include<ftxui/screen/screen.hpp>
#include<ftxui/dom/elements.hpp>
#include<thread>//hilos de proceso
#include<fstream>//flujos de archivos
#include<string>//control de cadenas
using namespace std;
using namespace ftxui;

    int main (int argc, char const *argv[])
    {
        fstream archivo;
        archivo.open("assets/assets/images/moto.txt");
        string moto;
        archivo >> moto;
        while (archivo.good())
        {
            archivo >> moto;
        }
        archivo.close();
        this_thread::sleep_for(0.1s);
        int fotograma=0;
        while(true)
        {
        fotograma ++;
        Element personaje = spinner (21,fotograma) | bold | color(Color::Red) | bgcolor(Color::White);
        Element eMoto = text(moto)| bold | color(Color::Orange1) | bgcolor(Color::White);;
        Element dibujo = hbox({personaje,eMoto});
        Screen pantalla = Screen::Create(Dimension::Full());
        Render(pantalla,dibujo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();

        
        }
        return EXIT_SUCCESS;
    }