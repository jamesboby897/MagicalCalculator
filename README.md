# ESP32-Based Discreet WebSocket+WebServer Controller for Android Calculator Magic Trick

## Overview

This project demonstrates a clever use of an ESP32 microcontroller to create a discreet WebSocket+WebServer controller that interacts with a WebView-based Android calculator app. The goal is to perform a magic trick where the calculator app displays the user's phone number when the '=' key is pressed, allowing you to retrieve the user's number.

## Components

- **ESP32 Microcontroller**: Acts as the WebSocket server and WebServer.
- **Android Calculator App**: A decoy app built using Android Studio that displays the magic trick.
- **WebSocket Communication**: Enables real-time communication between the ESP32 and the Android app.
- **WebServer**: Serves the necessary HTML and JavaScript files to the Android app.

## How It Works

1. **Setup the ESP32**:
   - The ESP32 is programmed to act as a WebSocket server and WebServer.
   - It serves an HTML file with JavaScript that communicates with the WebSocket server.
   - The ESP32 listens for specific commands from the Android app to display the phone number.

2. **Android Calculator App**:
   - The app is built using Android Studio and includes a WebView component.
   - The WebView loads the HTML file served by the ESP32.
   - When the '=' key is pressed, the app sends a command to the ESP32 via WebSocket.
   - The ESP32 responds with the phone number, which is then displayed in the calculator app.

3. **Performing the Magic Trick**:
   - Approach the target and engage in small talk.
   - Ask if they want to see a magic trick.
   - Instruct them to think of a few numbers and say them out loud.
   - Perform arbitrary mathematical calculations to make it seem like you're deriving a phone number.
   - Press the '=' key on the calculator app, and the ESP32 to display your phone number.
   - Get target to call number
   - The target will be amazed when your phone rings, and you can retrieve their number.

## Setup Instructions

### ESP32 Firmware

1. **Install the ESP32 Board Package**:
   - Open the Arduino IDE.
   - Go to `File` > `Preferences`.
   - In the "Additional Board Manager URLs" field, add: `https://dl.espressif.com/dl/package_esp32_index.json`.
   - Go to `Tools` > `Board` > `Boards Manager`.
   - Search for "esp32" and install the package.

2. **Upload the Firmware**:
   - Connect your ESP32 to your computer.
   - Open the `esp32_firmware.ino` file in the Arduino IDE.
   - Select the correct board and port from the `Tools` menu.
   - Upload the firmware to the ESP32.

### Android Calculator App

1. **Compile the Mobile App**:
   - Open Android Studio and load the project located in `AndroidStudioProject`.
   - Connect your Android device to your computer.
   - Click the `Run` button (green play icon) to build and run the app on your device.
## Enjoy!
