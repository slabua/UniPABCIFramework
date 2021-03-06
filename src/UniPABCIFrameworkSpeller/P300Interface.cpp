/*****************************************************************************
* 
* UniPA BCI Framework: an Augmented BCI Framework
* 
* Copyright (C) 2016-2017 Salvatore La Bua (slabua@gmail.com)
* RoboticsLab, Department of Industrial and Digital Innovation (DIID),
* Universita' degli Studi di Palermo, V. delle Scienze, Palermo, Italy.
* 
* http://www.slblabs.com/projects/unipa-bci-framework
* https://github.com/slabua/UniPABCIFramework
* 
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* 
*****************************************************************************/

#include "P300Interface.h"
#include <iostream>

using std::cout;
using std::endl;


P300Interface::P300Interface() {
	setNumberEl(-1);
	for (int i=0; i<dim_i; i++)
		row[i] = NULL;
}

P300Interface::P300Interface(int elem) {
	setNumberEl(elem);
	
	// SLB
	int rows = ceil(sqrt(elem));
	if (rows > 100) {
		cout << endl << "Errore, inserito numero di elementi errato." << endl;
		exit(1);
	}
	//

	for (int i=0; i<rows; i++)
		row[i] = new P300Row(rows);
}

P300Interface::P300Interface(int elem, int width, int height, int freq, int flash, int sessions, string path) {
	setNumberEl(elem);
	setWindowWidth(width);
	setWindowHeight(height);
	setFlashFrequency(freq);
	setNumberOfFlash(flash);
	setMaxSessions(sessions);
	setTexturePathName(path);
}

P300Interface::~P300Interface() {
	for (int i=0; i<dim_i; i++)
		delete row[i];
	delete row;
}

void P300Interface::setNumberEl(int number) {
	numberEl = number;
}

void P300Interface::setWindowWidth(int width) {
	windowWidth = width;
}

void P300Interface::setWindowHeight(int height) {
	windowHeight = height;
}

void P300Interface::setFlashFrequency(int freq) {
	flashFrequency = freq;
}

void P300Interface::setTexturePathName(string path) {
	texturePathName = path;
}

void P300Interface::setNumberOfFlash(int flash) {
	numberOfFlash = flash;
}

void P300Interface::setMaxSessions(int sessions) {
	maxSessions = sessions;
}

int P300Interface :: getNumberEl() {
	return numberEl;
}

P300Row* P300Interface::getRow(int index) {
	return row[index];
}

bool P300Interface::addRow(P300Row *r_row) {
	if (numberEl == -1) {
		setNumberEl(0);
		row[numberEl] = r_row;
	}
	else if ((numberEl != -1) && (numberEl<dim)) {
		for (int i=0; i<numberEl; i++) {
			if (row[i] == NULL) {
				row[i] = r_row;
				numberEl = i;

				return true;
			}
		}
	}
	return false;
}

int P300Interface::getWindowWidth() {
	return windowWidth;
}

int P300Interface::getWindowHeight() {
	return windowHeight;
}

int P300Interface::getFlashFrequency() {
	return flashFrequency;
}

string P300Interface::getTexturePathName() {
	return texturePathName;
}

int P300Interface::getNumberOfFlash() {
	return numberOfFlash;
}

int P300Interface::getMaxSessions() {
	return maxSessions;
}