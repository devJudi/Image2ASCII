#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

void generateTextFile(sf::Image img, std::string fileName, bool reverseColors);

int main()
{
    sf::Image image;

    std::cout<<"Name of file? (ex. img.png, make sure that the image is in the same folder with exe file)"<<std::endl;
    std::string path, name;
    std::cin>>name;
    path = name;
    for(int i = 0; i<name.size(); i++)
    {
        if(name[i]=='.')
        {
            name.erase(name.begin()+i, name.end());
            break;
        }
    }

    if(image.loadFromFile(path))
    {
        std::cout<<"Image loaded!"<<std::endl;
        bool isNegative = false;
        std::cout<<"Do you want to reverse colors? (Y/N)"<<std::endl;
        char ans;
        std::cin>>ans;
        while(ans!='Y'&&ans!='y'&&ans!='N'&&ans!='n')
        {
            std::cin>>ans;
        }
        if(ans=='Y'||ans=='y') isNegative = true;
        generateTextFile(image, name, isNegative);
    }
    else std::cerr<<"Make sure that the file is in the same folder!"<<std::endl;

    getch();
    return 0;
}

void generateTextFile(sf::Image img, std::string fileName, bool reverseColors)
{
    std::cout<<"...creating output file..."<<std::endl;
    std::ofstream off;
    if(reverseColors) off.open(fileName+"(reversed colors).txt");
    else off.open(fileName+".txt");

    for(int i = 0; i<img.getSize().y; i++)
    {
        for(int j = 0; j<img.getSize().x; j++)
        {
            int red = img.getPixel(j, i).r;
            int green = img.getPixel(j, i).g;
            int blue = img.getPixel(j, i).b;

            int gray = (red+green+blue)/3;
            if(reverseColors) gray = 255-gray;

            if(gray<20) off<<"#";
            else if(gray<40) off<<"W";
            else if(gray<60) off<<"@";
            else if(gray<80) off<<"H";
            else if(gray<100) off<<"&";
            else if(gray<120) off<<"O";
            else if(gray<140) off<<"=";
            else if(gray<160) off<<"U";
            else if(gray<180) off<<"o";
            else if(gray<200) off<<"*";
            else if(gray<220) off<<"-";
            else if(gray<240) off<<"'";
            else off<<" ";

        }
        off<<std::endl;
        i++;
    }

    std::cout<<"File created successfully!"<<std::endl;

    off.close();
}
