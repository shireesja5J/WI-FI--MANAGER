#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to list available Wi-Fi networks
void list_available_networks() {
    printf("\nScanning for Wi-Fi networks...\n");
    int result = system("netsh wlan show networks");
    if (result != 0) {
        printf("Error: Unable to list networks. Ensure Wi-Fi is enabled.\n");
    }
}

// Function to connect to a Wi-Fi network
void connect_to_network(const char *ssid, const char *password) {
    char command[512];

    // Create a network profile with the SSID and password
    snprintf(command, sizeof(command),
        "netsh wlan add profile filename=wifi_profile.xml interface=\"Wi-Fi\" >nul && netsh wlan connect name=\"%s\"",
        ssid);

    // Generate Wi-Fi profile XML content dynamically
    FILE *profile = fopen("wifi_profile.xml", "w");
    if (profile == NULL) {
        printf("Error: Unable to create Wi-Fi profile file.\n");
        return;
    }

    fprintf(profile,
        "<?xml version=\"1.0\"?>\n"
        "<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\">\n"
        "    <name>%s</name>\n"
        "    <SSIDConfig>\n"
        "        <SSID>\n"
        "            <name>%s</name>\n"
        "        </SSID>\n"
        "    </SSIDConfig>\n"
        "    <connectionType>ESS</connectionType>\n"
        "    <connectionMode>auto</connectionMode>\n"
        "    <MSM>\n"
        "        <security>\n"
        "            <authEncryption>\n"
        "                <authentication>WPA2PSK</authentication>\n"
        "                <encryption>AES</encryption>\n"
        "                <useOneX>false</useOneX>\n"
        "            </authEncryption>\n"
        "            <sharedKey>\n"
        "                <keyType>passPhrase</keyType>\n"
        "                <protected>false</protected>\n"
        "                <keyMaterial>%s</keyMaterial>\n"
        "            </sharedKey>\n"
        "        </security>\n"
        "    </MSM>\n"
        "</WLANProfile>\n",
        ssid, ssid, password);

    fclose(profile);

    printf("\nConnecting to network: %s...\n", ssid);
    int result = system(command);
    if (result == 0) {
        printf("Successfully connected to %s.\n", ssid);
    } else {
        printf("Failed to connect to %s. Please check the SSID and password.\n", ssid);
    }

    // Clean up the generated XML file
    remove("wifi_profile.xml");
}

// Function to check the current Wi-Fi connection status
void check_connection_status() {
    printf("\nChecking connection status...\n");
    int result = system("netsh wlan show interfaces | findstr SSID");
    if (result != 0) {
        printf("Not connected to any Wi-Fi network.\n");
    }
}

int main() {
    int choice;
    char ssid[100];
    char password[100];

    while (1) {
        printf("\nWi-Fi Manager:\n");
        printf("1. List Available Networks\n");
        printf("2. Connect to a Network\n");
        printf("3. Check Connection Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                list_available_networks();
                break;
            case 2:
                printf("Enter the SSID of the network: ");
                fgets(ssid, sizeof(ssid), stdin);
                ssid[strcspn(ssid, "\n")] = 0; // Remove trailing newline
                printf("Enter the password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove trailing newline
                connect_to_network(ssid, password);
                break;
            case 3:
                check_connection_status();
                break;
            case 4:
                printf("\nExiting Wi-Fi Manager. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
