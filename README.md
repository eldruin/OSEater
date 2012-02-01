# OSEater
## Description
OSEater is a "Pac-Man" like game in which "Tux", the Linux pet has to
collect all the dots in the map avoiding the Windows logos.
There also exist Apple logos that when they are eaten by Tux the game
mode is changed and the hero can eat the Windows logos.

## Platform
It's developed for the LPC2378-STK board from Olimex, based on the
LPC2378 microcontroller from NXP which has an ARM architecture.
The peripherals used are the built in screen, joystick and digital to
analog converter to play sounds.

It's developed under an evaluation version of CrossWorks for GNU/Linux
and was developed for the subject "Microcontrollers and
microprocessors" of the university.

## Design
OSEater follows an object oriented design using a component based
metodology in C++ programming language.
Due to the strong hardware limitations and my own C/C++ knowledge, the
code is not as beautiful as it could be.

Many thanks to my teacher Víctor Manuel Sánchez Corbacho for the
development of the low-level interface for the board, to the
freesound.org project and to the user HardPCM for creating the sounds
I've used in this game.

## Website
http://blog.eldruin.com/oseater

## Copyright
Copyright (C) 2008, 2009 Diego Barrios Romero

The Windows logo is property of Microsoft.
The Apple logo is property of Apple.
I hope they don't mind I use their logos, after all, sometimes they
will win the match ;)

## License
OSEater is free software under the terms of the GNU General Public
License as published by the Free Software Foundation, either version
3 of the License, or (at your option) any later version. A copy of

OSEater is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with OSEater.  If not, see <http://www.gnu.org/licenses/>.
