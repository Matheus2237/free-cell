# git

- puxar commits do remoto
git fetch origin main
git pull origin main

- enviar commits para o remoto
git add .
git commit -m "mensagem do commit"
git push origin main

# build
g++ -o build/freecell src/*.cpp
g++ -o build/freecell.exe src/*.cpp