# wiring-skeleton
Arduino Framework based Skeleton Embedded Application, powered by [PlatformIO](http://platformio.org "Cross-platform build system").

With this project you have a good starting point to create your own application that shall be based on the Arduino Framework. 

The project is able to run and has been tested on the following controller boards:

* [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3)
* [Arduino Mega 2560](https://store.arduino.cc/arduino-mega-2560-rev3)
* [Arduino Due](https://store.arduino.cc/arduino-due)
* [Adafruit Feather M0](https://www.adafruit.com/?q=Adafruit%20Feather%20M0)
* [Wemos D1 Mini](https://de.aliexpress.com/item/32764312651.html)
* [NodeMcu](https://de.aliexpress.com/item/32733851178.html)
* [Adafruit Huzzah ESP8266](https://learn.adafruit.com/adafruit-huzzah-esp8266-breakout)
* [DoIt ESP32 DEVKIT V1](https://de.aliexpress.com/item/32807028338.html)
* [LOLIN D32](https://www.wemos.cc/en/latest/d32/d32.html)

It could be easily ported to many other controller boards, as long as the Arduino Framework is used with PlatformIO and the board is listed in the [PlatformIO boards registry](https://platformio.org/boards).

## Purpose
This skeleton application demonstrates how to integrate libraries provided by the PlatformIO ecosystem and also how to use your own libraries and can help you to build up your own Arduino Framework based applications with a bare metal approach (i.e. without using an operating system). 

It comprises of several components helping with debugging and integrating embedded applications on several different controller modules.

This project demonstrates how to integrate the following **components**:

* [***Timer***](https://github.com/dniklaus/wiring-timer): configurable recurring or non-recurring timer to schedule events without having to use Arduino delay() function; helps to improve your application's architecture by encapsulating the timers into your components and thus make them active
* [***DbgTrace***](https://github.com/ERNICommunity/dbg-trace): debug trace log environment with configurable log levels
* [***Debug-Cli***](https://github.com/ERNICommunity/debug-cli): interactive console environment with command tree that can be built up decentralized (from any different location in your application code and within any component)
* [***App-Dbg***](https://github.com/dniklaus/wiring-app-debug): boilerplate code setting up all the debug environment such as CLI and Tracing and free RAM info printer
* [***Ramutils***](https://github.com/dniklaus/arduino-utils-mem): helps to determine the free Ram that is currently available

The **command line interface** provides the following **functionalities**:  
* set the trace level of the free heap monitoring printer
* set the onboard built in indicator LED display mode (on | off | blinking)

## Toolchain
[PlatformIO](http://platformio.org "Cross-platform build system") is the ideal foundation when developing IoT devices. It supports cross-platform development for many different controller boards widely used in the maker field and also for industrial applications.

### Installation
#### Python 3.7

**Windows**

* download Python 3.7.x or later from: https://www.python.org/downloads/
* select destination directory: keep default
* make sure python.exe is added to the search path

**Linux**

* Install Python 3.7 or later using your package manager. 
* Be sure the python binary is added to the search path.

#### PlatformIO
Install PlatformIO using the Python Package Manager
(see also http://docs.platformio.org/en/latest/installation.html#python-package-manager):

* in a cmd shell enter: `pip install -U platformio`
* upgrade pip, in the cmd shell enter: `python -m pip install --upgrade pip`
* upgrade PlatformIO, in the cmd shell enter: `pio upgrade`

### Working with Visual Studio Code

#### Prepare the project for VSCode

  1. Create a directory where your code project shall be cloned into. E.g. `C:\git\pio-prj`
  2. Clone this repository into the folder you created before: 
     `git clone git@github.com:ERNICommunity/wiring-skeleton.git` (ssh) or
     `git clone https://github.com/ERNICommunity/wiring-skeleton.git` (ssl)
  3. Open a command shell in the just cloned project folder, i.e. in `C:\git\pio-prj\wiring-skeleton`
  4. Run the command `pio init --ide vscode`. 
     This prepares the project to be edited using Visual Studio Code.

#### Install the PlatformIo Plugin for VSCode

1. Open VSCode
  2. On the *Activity Bar* on the left side click on the *extension icon* or just type *Ctrl+Shift+X*
  3. In the *Extensions* search field type `Platformio IDE` and hit ENTER
  4. The PlatformIO IDE Extension is shown, click on the *Install* button

#### Open project in VSCode

In the menu click on *File > Open Folder...* and choose the project folder that has been created after you cloned the project before, i.e `C:\git\pio-prj\wiring-skeleton` and click on *Select Folder*

### Working with Eclipse CDT

#### Prepare the project for Eclipse CDT

  1. Create a directory where your **Eclipse workspace** will be stored and where this project shall be cloned into. E.g. `C:\git\pio-prj`
  2. Clone this repository into the folder you created before: 
     `git clone git@github.com:ERNICommunity/wiring-skeleton.git` (ssh) or
     `git clone https://github.com/ERNICommunity/wiring-skeleton.git` (ssl)
  3. Open a command shell in the just cloned project folder, i.e in `C:\git\pio-prj\wiring-skeleton`
  4. Run the command `pio init --ide eclipse`. 
     This prepares the project to be edited using Eclipse CDT.
  5. Run the command `pio run`, this starts the project build 


#### Open project in Eclipse CDT

  1. Open Eclipse CDT, choose the folder you created before as **Eclipse workspace**, i.e `C:\git\pio-prj`
  2. Import the project with *File > Import > General > Existing Projects* into Workspace, choose the 
     `wiring-skeleton` (i.e `C:\git\pio-prj\wiring-skeleton`)

### Build the Application

1. Run the command `pio run -t clean` to clean the project.
2. Run the command `pio run`, this starts the project build.

### Upload the Application

1. In the file `platformio.ini`, in the section `[platformio] default_envs =`,  uncomment the line matching your MCU board, comment all the others by adding a `;` in front of the lines that have to be deactivated.
2. Connect your MCU board with USB to your PC
3. In a cmd shell type `pio run -t upload`

### Connect Terminal Emulation


In order to test and run the CLI commands, a terminal emulation program shall be used. The one giving you the best experience will be the [HTerm](http://www.der-hammer.info/terminal/). 

Load the _hterm-com10.cfg_ file (to be found in the project root directory) to configure HTerm properly. Alter the *COM10* accordingly to the one that has been selected on your computer.

## Debug Features
### Debug CLI Commands
#### Command Tree
    dbg                      Debug CLI root node
      tr                     Debug Trace Port config access
        heap                 Particular Trace Port (heap: see below in chapter Trace Port)
          out                Trace Output config access for the current trace port
            get              Show the assigned Trace Output
            set <outName>    Set a particular Trace Output name
            list             Show all available Trace Output names (& currently selected)
          lvl                Trace Level config access for the current trace port
            get              Show the current trace level
            set <level>      Set a particular trace level
            list             Show all available trace levels (& currenntly selected)
        led
          out
            ...
          lvl
            ...    
      led                    Built in LED access
        set                  Set LED state (Usage: dbg led set [blink|on|off])

#### Example commands
* `dbg tr heap lvl set debug`
* `dbg led set on`
* `dbg led set blink`


### Trace Port

|Trace Port|default level|functionality|
|----------|-------------|:------------|
|heap|info|if set to debug level: automatically print free heap memory [bytes], every 10 seconds|
|led |notice|used for _dbg led_ CLI commands print out (which level is defined as _alert_)|


## Library Usage
This chapter lists all the libraries this project is using.

### PlatformIO Libraries

|ID|Name|URL|Description|
|:---|:------------|:----------------|:-----------------------|
| 173|SerialCommand|https://github.com/kroimon/Arduino-SerialCommand|A Wiring/Arduino library to tokenize and parse commands received over a serial port.|
|1699|wiring-timer |https://github.com/dniklaus/wiring-timer|Universal recurring or non-recurring Timer.|
|1716|debug-cli|https://github.com/ERNICommunity/debug-cli|Debug CLI for Embedded Applications - Command Line  Interface for debugging and testing based on object oriented tree structure.|
|1717|dbg-trace|https://github.com/ERNICommunity/dbg-trace|Debug Trace component for Embedded Applications - Debug and Trace Log message system based on trace ports with adjustable levels.|



### Homebrew Libraries

|Name|URL|Description|
|:------|:---------------------|:-------------------------------|
|RamUtils|https://github.com/dniklaus/arduino-utils-mem|Arduino Memory Utilities, provides free heap information|
|App-Debug  |https://github.com/dniklaus/wiring-app-debug.git|Wiring application debug setup component                                                                                         |



## Create a new project based on this skeleton application

To use *wiring-skeleton* as a template for a new project, it has to be forked locally.

1. On **GitHub:** create new repository, i.e. *my-test*
2. Within a **Git Bash:**
   1. Clone the *wiring-skeleton* as a **bare repository**:
   ```bash
      git clone --bare git@github.com:ERNICommunity/wiring-skeleton.git
   ```
   2. Replace origin with the one for your new project (i.e. project *my-test*, with *your-name* as GitHub user name):
   ```bash
      cd ./wiring-skeleton.git
      git remote rm origin
      git remote add origin git@github.com:your-name/my-test.git
   ```
   3. Push the bare repo as a **mirror** to your new origin:
   ```bash
      git push --mirror
   ```
   4. Clone the new project (i.e. project *my-test*, with *your-name* as GitHub user name):
   ```bash
      cd ..
      git clone git@github.com:your-name/my-test.git
   ```
   5. Remove the bare *wiring-skeleton* template project:
   ```bash
      rm -rf ./wiring-skeleton.git
   ```

