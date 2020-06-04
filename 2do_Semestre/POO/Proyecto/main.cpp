//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <typeinfo>

#include "Pelicula.h"
#include "Capitulo.h"
#include "Serie.h"

using namespace std;

vector<Video *> videos; //vector de apuntadores para videos(peliculas/capitulos)
vector<Serie *> series; //vector de apuntadores para series

vector<int> indexP; //indices de peliculas
vector<int> indexC; //indices de capitulos

int cPeliculas = 0; //cantidad de peliculas
int cCapitulos = 0; //cantidad de capitulos
int cSeries = 0;    //cantidad de series

/*FUNCIONES HELPER */
bool to_bool(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::istringstream is(str);
    bool b;
    is >> std::boolalpha >> b;
    return b;
}

//busqueda adelante/atras/contraccion
int search(string arr[], int n, string x) { 
    int front = 0, back = n - 1; 
    while (front <= back) { 
        if (arr[front] == x){
            return front;
        }
        else if(arr[back] == x){
            return back;
        } 
        front++; 
        back--; 
    } 
    return -1; 
} 

//obtener posiciones de los capitulos de la serie
vector<int> positionsSerie(string title){
    vector<int> pos;
    int front = 0, back = videos.size() - 1; 
    while (front <= back) { 
        if (videos[front]->getTitle() == title){
            pos.push_back(front);
        }
        else if(videos[back]->getTitle() == title){
            pos.push_back(back);
        } 
        front++; 
        back--; 
    } 
    return pos;
}


/*LECTURA DE DATOS */
//leer datos de los archivos TSV 👍
void fetchData(){
    //variables generales
    int id;//identificador
    bool adult;//pelicula para mayores de 18
    string language;//idioma original
    float duration;//duracion en minutos
    string title;//titulo del video
    string description;//descripcion del video
    string genre;//genero del video
    float rating;//calificacion del video

    //variables movies
    vector<string> productionCompanies;//compañias productoras
    string releaseDate;//fecha de estreno

    //variables capitulos
    string stitle;//titulo de la serie a la que pertenece
    int season;//temporada
    int chapter;//capitulo
    string airDate;//fecha de estreno
    string chapterDescription;//descripcion del capitulo

    //variables series
    string network;//cadena o televisora
    string runtime;//duracion de la serie en años
    vector<Video *> capitulos;

    //Movies
    ifstream myFile;
    myFile.open("./Data/movies.txt");

    int counter = 0;
    
    while(myFile.good()){
        string line;
        getline(myFile,line,'\t');
        //cout<<line<<endl;
        //id	adult	language	duration	title	description	genre	rating	companies	companies	companies	releasedate
        switch(counter){
            case 0:
                break;
            case 1:
                id = stoi(line);
                indexP.push_back(id);
                break;
            case 2:
                adult = to_bool(line);
                break;
            case 3:
                language = line;
                break;
            case 4:
                duration = stof(line);
                break;
            case 5:
                title = line;
                break;
            case 6:
                description = line;
                break;
            case 7:
                genre = line;
                break;
            case 8:
                rating = stof(line);
                break;
            case 9:
                productionCompanies.push_back(line);
                break;
            case 10:
                productionCompanies.push_back(line);
                break;
            case 11:
                productionCompanies.push_back(line);
                break;
            case 12:
                releaseDate = line.substr(0, line.size()-1);;
                videos.push_back(new Pelicula(id,adult,language,duration,title,description,genre,rating,productionCompanies,releaseDate));
                productionCompanies.clear();
                cPeliculas++;
                counter = 0;
                break;
            default:
                break;
        }
        counter++;
    }
    myFile.close();

    //Capitulos--------------------------------------------------------------------------------------------------
    myFile.open("./Data/chapters.txt");
    counter = 0;
    while(myFile.good()){
        string line;
        getline(myFile,line,'\t');
        //cout<<line<<endl;
        //tipo	id	adult	language	duration	title	description	genre	rating	companies	companies	companies	releasedate
        switch (counter){
            case 0:
                break;
            case 1:
                id = stoi(line);
                indexC.push_back(id);
                break;
            case 2:
                adult = to_bool(line);
                break;
            case 3:
                language = line;
                break;
            case 4:
                duration = stof(line);
                break;
            case 5:
                title = line;
                break;
            case 6:
                description = line;
                break;
            case 7:
                genre = line;
                break;
            case 8:
                rating = stof(line);
                break;
            case 9:
                stitle = line;
                break;
            case 10:
                season = stoi(line);
                break;
            case 11:
                chapter = stoi(line);
                break;
            case 12:
                airDate = line;
                break;
            case 13:
                chapterDescription = line.substr(0, line.size()-1);
                videos.push_back(new Capitulo(stitle,id,adult,language,duration,title,description,genre,rating,season,chapter,airDate,chapterDescription));
                cCapitulos++;
                counter = 0;
                break;
            default:
                break;
        }
        counter++;
    }
    myFile.close();

    //Series-----------------------------------------------------------------------------------------------------
    myFile.open("./Data/series.txt");
    counter = 0;

    while(myFile.good()){
        string line;
        getline(myFile,line,'\t');
        //cout<<line<<endl;
        //tipo	id	title	network	rating	runtime
        switch (counter){
            case 0:
                break;
            case 1:
                id = stoi(line);
                break;
            case 2:
                title = line;
                break;
            case 3:
                network = line;
                break;
            case 4:
                rating = stof(line);
                break;
            case 5:
                runtime = line.substr(0, line.size()-1);
                for(auto i: indexC){
                    if(Capitulo* v = dynamic_cast<Capitulo*>(videos[i-1])) {
                        //se hace sobre carga con un cast dinamico para pasar de clase base a clase hija capitulo
                        if(v->getSTitle() == title){
                            capitulos.push_back(videos[i-1]);
                        }
                    }
                }
                series.push_back(new Serie(id,title,network,runtime,rating,capitulos));
                cSeries++;
                capitulos.clear();
                counter = 0;
            default:
                break;
        }
        counter++;
    }
    myFile.close();
}


/*REQUISITOS MINIMOS*/
//mostrar todas las peliculas👍
void mostrarPeliculas(){
    for(auto i: indexP){
        videos[i-1]->mostrar();
        cout<<endl;
    }
}

//mostrar todas las series 👍
void mostrarSeries(){
    for(int i = 0; i<series.size();i++){
        series[i]->mostrar();
        cout<<endl;
    }
}

//mostrar videos por calificacion a partir del input del usuario👍
void mostrarPorCalificacion(float rating){
    for(int i = 0;i<videos.size();i++){
        if(videos[i]->getRating() >= rating){
            videos[i]->mostrar();
            cout<<endl;
        }
    }
}

//mostrar todos los videos de cierto genero ingresado por el usuario👍
void mostrarPorGenero(string genre){
    for(int i = 0; i <videos.size();i++){
        if(videos[i]->getGenre() == genre){
            videos[i]->mostrar();
            cout<<endl;
        }
    }
}

//funcion para mostrar los episodios de una serie a partir del input del usuario👍
void mostrarEpisodios(string serie){
    for(auto i: series){
        if(i->getTitle() == serie){
            for(auto i: i->getCapitulos()){
                i->mostrar();
                cout<<endl;
            }
        }
    }
}

//Funcion para mostrar las peliculas con cierta calificacion ingresada por el usuario  👍
void mostrarPeliculasPorCalificacion(float rating){
    for(int i = 0;i<videos.size();i++){
        if(find(indexP.begin(), indexP.end(),i+1)!= indexP.end()){
            if(videos[i]->getRating()>=rating){
                videos[i]->mostrar();
                cout<<endl;
            }
        }
    }
}


/*FUNCIONES EXTRA*/
void searchVideo(string title){
    for(auto i:videos){
        if(i->getTitle() == title){
            i->mostrar();
            cout<<endl;
        }
    }
}


int main(){
    cout<<endl;
    fetchData();
    
    cout<<"-----------------------------------------------------------------------"<<endl;
    return 0;
}
