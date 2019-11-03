#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

void generateTextFile(sf::Image img);

int main()
{
    sf::Image image;

    std::cout<<"Name of file? (ex. img.png, make sure that the image is in the same folder with exe file)"<<std::endl;
    std::string path;
    std::cin>>path;

    if(image.loadFromFile(path))
    {
        std::cout<<"Image loaded!"<<std::endl;
        generateTextFile(image);
    }
    else std::cerr<<"Make sure that the file is in the same folder!"<<std::endl;

    return 0;
}

void generateTextFile(sf::Image img)
{
    std::cout<<"...creating output file..."<<std::endl;
    std::ofstream off;
    off.open("output.txt");

    for(int i = 0; i<img.getSize().y; i++)
    {
        for(int j = 0; j<img.getSize().x; j++)
        {
            int red = img.getPixel(j, i).r;
            int green = img.getPixel(j, i).g;
            int blue = img.getPixel(j, i).b;
            int gray = (red+green+blue)/3;

            if(gray<25) off<<"#";
            else if(gray<50) off<<"@";
            else if(gray<75) off<<"%";
            else if(gray<100) off<<"g";
            else if(gray<125) off<<"&";
            else if(gray<150) off<<"x";
            else if(gray<175) off<<"=";
            else if(gray<200) off<<"o";
            else if(gray<225) off<<"-";
            else off<<" ";

        }
        off<<std::endl;
        i++;
    }

    std::cout<<"File created successfully!"<<std::endl;

    off.close();
}
