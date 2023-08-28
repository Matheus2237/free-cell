# git
- puxar commits do remoto
git fetch origin main
git pull origin main

- enviar commits para o remoto
git add .
git commit -m "mensagem do commit"
git push origin main

# build
g++ -o build/FreeCellApp FreeCellApp.cpp src/*.cpp src/verificacao/*.cpp
g++ -o build/FreeCellApp.exe FreeCellApp.cpp src/*.cpp src/verificacao/*.cpp