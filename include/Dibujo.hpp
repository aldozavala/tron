
class Dibujo
{
private:
    ifstream archivo;
    Element contenido;

public:
    Dibujo(string path)
    {
        archivo.open(path);
            string linea;
        Elements elementos;
        while (getline(archivo, linea))
        {
            elementos.emplace_back(text(linea));
        }
     contenido = vbox(elementos);
        archivo.close();
    }

    Element GetElement()
    {
        return this->contenido;
    }
    ~Dibujo() {}
};