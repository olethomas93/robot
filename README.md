# robot
Web controlled robot

### Hardware required:
* Raspberry Pi (I used model B)
* Arduino Mega (software serial needs to be implemented for Uno)
* Sabertooth motor controller (my setup uses the 2x5)
* Wireless Dongle for raspberry pi
* LiPO battery (7.4V or 11.1V will work)
* Portable cell phone battery pack to power raspberry pi and arduino
* RC car chassis with two sets of wheels (my setup uses rear wheel drive with front wheel servo steering. Differential drive would work better, and the code would require only slight modification.)
* Raspberry Pi camera module
* RGB LED (for a light on the robot)
	
### Software Setup:
1. Install raspbian on raspberry pi. 
    * In raspi-config, expand filesystem, enable raspberry pi camera module, and change the memory split to 256/256.
    * Make sure your raspberry pi is up to date:  
	`sudo apt-get update`  
     	`sudo apt-get dist-upgrade`
        `sudo rpi-update`
2. Install Node.js. I ran into a number of issues installing node, but the following worked for me:  
	`curl -sLS https://apt.adafruit.com/add | sudo bash`  
       	`sudo apt-get install node`  
3. Clone this repository https://github.com/rykerDial/robot.git, then navigate to the directory *robot/robotweb*
4. Install the node packages express, serialport, and socket.io with npm  
       `echo 'export PATH="$PATH:/opt/node/bin"' >> ~/.bashrc`  
       `source ~/.bashrc`  
       `npm install express serialport socket.io`  	
5. Upload the firmware on your arduino mega:
    * Go to the directory robot/robotweb/firmware and upload firmware.ino to your arduino mega
6. Install uv4l driver via instructions at http://www.linux-projects.org/modules/sections/index.php?op=viewarticle&artid=14
    * Install the required packages  
       `sudo apt-get install uv4l uv4l-raspicam`  
       `sudo apt-get install uv4l-server`  

### Hardware Setup:
1. Plug in RGB LED to Arduino
    * Solder resistors to the cathodes of your RGB LED, then plug in the leads like so:  
          `Red Lead: Pin 8  Green Lead: Pin 9  Blue Lead: Pin 10  Anode: GND`
2. Plug in wifi dongle, arduino mega, camera module, and battery pack into your raspberry pi.
3. Setup Sabertooth:
    * Connect Sabertooth 0V to Arduino GND and Sabertooth S1 to Arduino TX1
    * Connect the steering motor to M1A and M1B and the drive motor to M2A and M2B
    * Configure DIP switches. Using sabertooth DIP switch wizard:  
          `1: UP  2: DOWN  3: DOWN  4: DOWN  5: UP  6: UP`
    * Hook up your LiPO battery to B+ and B-

### Start Robot!
1. Start server on raspberry pi:  
       `sudo node server.js <path_to_serial_port> (e.g. /dev/ttyACM0)`
2. Start video stream  
	   `uv4l --driver raspicam --auto-video_nr --width 640 --height 480 --encoding mjpeg --framerate 25 --quality 5 --server-option '--port=9000'`  
3. Open up your web browser and go to the address of your raspberry pi!
