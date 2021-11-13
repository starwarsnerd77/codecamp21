#include "pixel.h"
#include <iostream>

Pixel::Pixel(QGroupBox *parent) : QGroupBox(parent), pxlRed(0), pxlGreen(0), pxlBlue(0), pxlSize(20){

}

Pixel::Pixel(QColorDialog* cp) {
    colorPicker = cp;
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pxlRed = 255;
    pxlGreen = 255;
    pxlBlue = 255;
}

int Pixel::getRed() const{

	return pxlRed;

}

int Pixel::getGreen() const{

	return pxlGreen;

}

int Pixel::getBlue() const{

	return pxlBlue;

}

void Pixel::setRed( const int& red ){

	if(red >= 0 && red <= 255){
		pxlRed = red;
	}
}

void Pixel::setGreen( const int& green ){

	if(green >= 0 && green <= 255){
		pxlGreen = green;
	}
}

void Pixel::setBlue( const int& blue ){

	if(blue >= 0 && blue <= 255){
		pxlBlue = blue;
	}
}

void Pixel::setSize( const int& size ){

	if(size >= 0 && size <= 80){ //Does this need to be changed?
		pxlSize = size;
        this->resize(pxlSize, pxlSize);
	}
}


void Pixel::mousePressEvent(QMouseEvent *event) {
    (void) event;
    this->setStyleSheet("");
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, colorPicker->currentColor());
    this->setRed(colorPicker->currentColor().red());
    this->setGreen(colorPicker->currentColor().green());
    this->setBlue(colorPicker->currentColor().blue());
    this->setAutoFillBackground(true);
    this->setPalette(pal);
//    this->show();
}

std::string Pixel::getRGB( ) const{
	return std::to_string(getRed()) + "," + std::to_string(getGreen()) + "," + std::to_string(getBlue());

}

