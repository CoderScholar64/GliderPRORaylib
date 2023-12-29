# Glider PRO raylib Port
This project is yet another porting attempt for Glider Pro.
This project aims to be coded in standard C99 as much as possible. This project is to make it easier to port to things like MS-DOS or other low-spec systems. If you want a fully featured Glider PRO port with the map editor and everything, play [Aerofoil](https://github.com/elasota/Aerofoil).

## Goals
 * Port this source code to standard C99. 
 * Clean up the source code.
 * Make this project easier to port.
 * Recreate the GUI that would be TV and gamepad-friendly.
 * Make this project work with GPF format developed by the Aerofoil Author [elasota](https://github.com/elasota/Aerofoil). Rationale: Resource Forks are obsolete.
 * Write a software renderer with 24-bit full color, 16-bit partial color, 8-bit palette, and 4-bit palette support. Rationale: QuickDraw is no longer supported, and a software renderer would make this project easier to port. 640x480 is the planned resolution.
 * Remove the map editor. Rationale: Aerofoil already has that feature, and it would simplify this code base.

## Original Author
Sources for the Macintosh game, Glider PRO, written by John Calhoun and published by Casady &amp; Greene Inc.

![Splash screen](https://github.com/softdorothy/glider_pro/blob/master/GliderProSplash.png)

Additional credits:
* Demo House and CD Demo House are by John Calhoun and Kim Money.
* Davis Station, Metropolis and Titanic are by Jonathan Chin (alias Paul Finn) and John Calhoun.
* Grand Prix, Leviathan, ImagineHouse PRO II and In The Mirror are by Jonathan Chin (alias Paul Finn).
* Land of Illusion, Nemo's Market, Rainbow's End and SpacePods are by Ward Hartenstein.
* Slumberland is by John Calhoun (first house and top of fourth house) Jonathan Chin (second house), Steve Sullivan (third house) and Ward Hartenstein (bottom of fourth house).
* Teddy World is by Shawn Brenneman.
* The Asylum Pro is by Steve Sullivan.
* PICT resource 3975 (Ozma) is derived from an illustration by John R. Neill from [Ozma of Oz](https://www.gutenberg.org/files/33361/33361-h/33361-h.htm).
* PICT resource 153 (About box) features a portion of [this Little Nemo comic](http://www.comicstriplibrary.org/display/116) by Winsor McCay.

Legal
The source for Glider PRO is released under the GNU General Public License 2 as published by the Free Software Foundation.
