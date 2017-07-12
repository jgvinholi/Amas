# Acquatic Measurements Automated System

There's an old mine that has been abandoned for several years, in the south of Brazil. Due to not being closed properly, this mine is releasing highly toxic substances to the local enviroment, through the water that flows out of the abandoned facility. This project is aimed to take pH measures from this contamined water and, with the data collected, aid researchers to more easily detect the usefulness of their work - consisted by seeking for methods to purificate the water.

### Sensors and Modules
* [Servomotor](https://www.wikiwand.com/en/Servomotor) (x2)
* [DS18B20 Thermometer](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf) (Only implemented on software.)
* [Analog pHmeter + Generic pH Sensor Module](https://forum.arduino.cc/index.php?topic=336012.0) (Detailed informations are on one of the commentaries of the link.)
* [Generic MicroSDC Module](https://www.arduino.cc/en/Tutorial/ReadWrite)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Building
You'll need to install the following applications to build this project:
* [Git](https://git-scm.com/downloads)
* [VSCode](https://code.visualstudio.com/)
* [PlatformIO Plugin for VSCode](http://docs.platformio.org/en/latest/ide/vscode.html)
* [Arduino IDE](https://www.arduino.cc/en/main/software)

Firstly, clone the repository to the desired local directory
```
git clone https://github.com/jgvinholi/Amas.git
```
Extract the following Arduino libraries, downloaded from [here](https://www.arduino.cc/en/Reference/Libraries), to the ``src/`` directory:
* OneWire.h
* DallasTemperature.h
* SD.h

Open VSCode and, after having installed the PlatformIO Plugin for VSCode, go to ``File > Open Folder...``. Select the folder where the repository has been cloned.

To initialize the PlatformIO Project, press ``Control + Alt + I`` and wait around a minute.

With your Arduino Uno board plugged into your machine, you can now build and send the program to your device. Do this by pressing ``Control + Alt + U``.

Done.

## Built With

* [VSCode](https://code.visualstudio.com/)
* [PlatformIO Plugin for VSCode](http://docs.platformio.org/en/latest/ide/vscode.html)
* Previous versions used another IC, the TI-MSP432F, which was programmed with [TI Code Composer Studio v7](http://www.ti.com/tool/ccstudio)


## Authors

* **João Vinholi** - *Coding* - [Github](https://github.com/jgvinholi) [E-mail](mailto:jgvinholi@gmail.com)
* **Felipe Castro** - *Project administration and electronics assembling* - [E-mail](mailto:felipecastrofreitas@gmail.com)
* **Gabriel Ferrazzo** - *Mechanical system modelling* - [E-mail](mailto:gacferrazzo@gmail.com)
See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* TODO
