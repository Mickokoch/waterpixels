#include <string>
#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

class Pixel {

    private:

        unsigned int red;
        unsigned int green;
        unsigned int blue;

    public:

        Pixel(unsigned int red, unsigned int green, unsigned int blue){
            
            if((red>0)&&(red<0xFF)){this->red=red;}
            this->green=green;
            this->blue=blue;
        }

        Pixel(){
            this->red = rand() % 255;
            this->green = rand() % 255;
            this->blue = rand() % 255;
        }

        //Pixel():Pixel(0xFF,0xFF,0xFF){}

        int R() const{
            return red;
        }
        int G() const {
            return green;
        }
        int B() const {
            return blue;
        }


        /*
        ostream& operator << (ostream &os, const Pixel &p){
            return (os << "red : "<<red<<" green : "<<green<<" blue : "<<blue);
        }
            

        string toString() const {

        }
        */

};

class Image {
    private : 
        unsigned int length;
        unsigned int height;


        // tableau de Pixel de taille length*height
        vector<vector<Pixel>> image;

        

    public:

        Image(unsigned int length, unsigned int height){
            this->length=length;
            this->height=height;

            //this->image.assign(height, vector<Pixel>(length));

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 254);

            image.resize(height, vector<Pixel>(length));

            for(auto& row : image){
                for(auto& px : row){
                    px=Pixel(dis(gen),dis(gen),dis(gen));
                }
            }


            /*
            for(const auto& ligne : image){
                for(auto pix : ligne){
                    pix = Pixel();
                }
            }
            */
            
        }



        void renderPPM(){
            // output le fichier en format bitmap (couleur) .ppm

            ofstream file("image.ppm");
            file<<"P3"<<endl;
            file<<length<<" "<<height<<endl;
            file<<255<<endl;


            for(int l=0; l<image.size(); l++){
                for(int c=0; c<image[l].size(); c++){
                    Pixel pixel = image[l][c];
                    file<<pixel.R()<<" "<<pixel.G()<<" "<<pixel.B()<<endl;
                }
                file<<endl;

            }

            file.close();
        }
};

int main(){

    

    Pixel rouge = Pixel(250,0,0);

    Image test = Image(100,100);
    test.renderPPM();

    return 0;
}