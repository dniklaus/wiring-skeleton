# wiring-skeleton
Arduino Framework based Skeleton Embedded Application, powered by [PlatformIO](http://platformio.org "Cross-platform build system").

The project is suitable for the following controller boards:

* Arduino Uno
* Arduino Mega2560
* Arduino Due
* Adafruit Feather M0
* NodeMcu
* Adafruit Huzzah ESP8266

## Purpose
This project builds up an Arduino Framework based application skeleton and it comprises of several components helping with debugging and integrating embedded applications on several different contoller modules.

This skeleton application can help you to build up your own Arduino Framework based applications while working with [PlatformIO](http://platformio.org "Cross-platform build system").

This project integrates the following **components**:

* ***Timer***: configurable recurring or non-recurring timer to schedule events without having to use Arduino delay() function; helps to improve your application's architecture by encapsulating the timers into your components and thus make them active
* ***Ramutils***: helps to determine the free Ram that is currently available
* ***DbgTrace***: debug trace log environment with configurable log levels
* ***DbgCLI***: interactive console environment with command tree that can be built up decentralized (from any different location in your application code and within any component)
* ***App-Dbg***: boilerplate code setting up all the debug environment such as CLI and Tracing and free RAM info printer
The **command line interface** provides the following **functionality**:  

* set the trace level of the free heap monitoring printer

This skeleton application demonstrates how to integrate libraries provided by the PlatformIO ecosystem and also how to use your own libraries and can help you to build up your own Arduino Framework based applications with focus on IoT. 

The following components are in focus:

* [Timer](https://github.com/dniklaus/wiring-timer)
* [Debug-Cli](https://github.com/ERNICommunity/debug-cli)
* [Dbg-Trace](https://github.com/ERNICommunity/dbg-trace)

## Toolchain
[PlatformIO](http://platformio.org "Cross-platform build system") is the ideal foundation when developing IoT devices. It supports cross-platform development for many different controller boards widely used in the maker field and also for industrial applications.

### Installation
#### Python 3.7

**Windows**

* download Python 3.7.x or later from: https://www.python.org/downloads/
* select destination directory: keep default
* make sure python.exe is added to path

**Linux**

Install Python 3.7 or later using your package manager.

#### PlatformIO
Install PlatformIO using the Python Package Manager
(see also http://docs.platformio.org/en/latest/installation.html#python-package-manager):

* in a cmd shell enter: `pip install -U platformio`
* upgrade pip, in the cmd shell enter: `python -m pip install --upgrade pip`
* upgrade PlatformIO, in the cmd shell enter: `pio upgrade`


## How to build for Eclipse CDT
  1. Create a directory where your Eclipse Workspace will be stored and where this project shall be cloned into. E.g. `C:\git\pio-prj`
  2. Clone this repository recursively into the folder you created before, `git clone --recursive git@github.com:dniklaus/wiring-skeleton.git`
  3. Open a command shell in the just cloned project folder, i.e in `C:\git\pio-prj\wiring-skeleton`
  4. Run the command `pio init --ide eclipse`, this prepares the project to be edited using Eclipse CDT
  5. Run the command `pio run`, this starts the project build 

Note: Print a list of all available boards with the command: `pio boards`

## Open project in Eclipse CDT
  1. Open Eclipse CDT, choose the folder you created before as workspace, i.e `C:\git\pio-prj`
  2. Import the project with File->Import->General->Existing Projects into Workspace, choose the `wiring-skeleton` (i.e `C:\git\pio-prj\wiring-skeleton`)

## Connect Terminal Emulation
In order to test and run the CLI commands, a terminal emulation program shall be used. The one giving you the best experience will be the [HTerm](http://www.der-hammer.info/terminal/). 

Load the _hterm-com10.cfg_ file to configure HTerm properly. Alter the COM10 accordingly to the one that has been selected on your computer.

## Debug Features
### Debug CLI Commands
#### Command Tree
     dbg                      Debug CLI root node
       tr                     Debug Trace Port config access
         heap                 Particular Trace Port (heap: see below in chapter Trace Port)
           out                Trace Output config access for the current trace port
             get              Show the assigned Trace Output
             set <outName>    Set a particular Trace Output name
             list             Show all available Trace Output names (and the currently selected)
           lvl                Trace Level config access for the current trace port
             get              Show the current trace level
             set <level>      Set a particular trace level
             list             Show all available trace levels (and the currenntly selected)
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

