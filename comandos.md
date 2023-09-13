# git
- puxar commits do remoto
git fetch origin main
git pull origin main

- enviar commits para o remoto
git add .
git commit -m "mensagem do commit"
git push origin main

# build
g++ -Wall -o build/FreeCell FreeCell.cpp src/*.cpp src/verificacao/*.cpp
g++ -Wall -o build/FreeCell.exe FreeCell.cpp src/*.cpp src/verificacao/*.cpp
g++ -Wall -Wextra -pedantic -o build/FreeCell FreeCell.cpp src/*.cpp src/verificacao/*.cpp