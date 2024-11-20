WI-FI-MANAGER
Overview

Wi-Fi Manager in C is a command-line utility designed for managing Wi-Fi networks on Windows systems. It utilizes the netsh command-line tool to perform network-related operations such as scanning for available networks, connecting to a specific network, and checking the current connection status.

This project is an example of how system commands can be integrated into C programs to perform system-level tasks programmatically.

Features

Scan Available Networks
Lists all Wi-Fi networks in range by executing the netsh wlan show networks command.

Connect to a Network
Allows users to connect to a specified Wi-Fi network by providing the SSID and password.

Dynamically creates a Wi-Fi profile in XML format for the connection.
Uses the netsh wlan connect command to initiate the connection.
Check Connection Status
Displays the current Wi-Fi connection status, including the SSID of the connected network.

User-Friendly Menu
A simple, interactive menu for easy navigation.

How It Works

1.The program leverages the system() function to run Windows netsh commands for Wi-Fi management.

2.It generates a temporary XML profile for securely handling SSID and password data during connection.

Prerequisites:-

1.Windows Operating System: The program relies on the Windows netsh tool.

2.Wi-Fi Enabled: Ensure the Wi-Fi adapter is active before using the program.

3.C Compiler: Use a compiler like GCC or MSVC to build the code.

output:

![image](https://github.com/user-attachments/assets/c580f712-572c-4a8a-8e58-f79086b84749)


![image](https://github.com/user-attachments/assets/c8429828-1027-4571-8faa-ffdfcae780f2)


Usage

1.Clone the repository:

git clone https://github.com/yourusername/Wi-Fi-Manager-C.git
cd Wi-Fi-Manager-C

2.Compile the code:

gcc wifi_manager.c -o wifi_manager

3.Run the program:

./wifi_manager

4.Follow the interactive menu to:

List available networks.
Connect to a network.
Check your current connection status.

Contributions:

Contributions are welcome! If you have ideas for improving the program or want to add features, feel free to fork the repository and open a pull request.

License:

This project is licensed under the MIT License. See the LICENSE file for details.

