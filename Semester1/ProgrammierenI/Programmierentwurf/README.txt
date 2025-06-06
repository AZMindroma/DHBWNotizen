=== Programmentwurf Dateikartensystem ===
Offiziell ist nur Linux als Betriebssystem unterstützt. 
Das Projekt ist abhängig zu cJSON und curl.
cJSON ist im Projekt selber vorhanden, aber das curl-Entwicklungspaket muss installiert und als ein Extraargument (-lcurl) beim Kompilieren des Programms hinzugefügt werden.

Für APT:
sudo apt install libcurl4-openssl-dev

gcc program.c -lcurl -o program

Kompiliertes Programm wird mit ./program ausgeführt



=== Program Draft File Card System ===
Only Linux is officially supported as an Operating System.
The project depends on cJSON and curl.

cJSON has been included in the project itself, but the curl development package needs to be installed and added as an extra argument (-lcurl) when compiling the program. 

For APT: 
sudo apt install libcurl4-openssl-dev

gcc program.c -lcurl -o program

Execute compiled program with ./program