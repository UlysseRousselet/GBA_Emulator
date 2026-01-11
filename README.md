# GBA_Emulator
A simple GameBoy Advance emulator made in C++

1. **Launch the project** :
   ```sh
   cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build --parallel
   ```

Liens utiles :

https://cturt.github.io/cinoop.html
http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf
http://gameboy.mongenel.com/dmg/opcodes.html
https://meganesu.github.io/generate-gb-opcodes/?utm_source=chatgpt.com

| Flag | Valeur | Pourquoi          |
| ---- | ------ | ----------------- |
| Z    | 1      | résultat = 0      |
| N    | 0      | pas une SUB       |
| H    | 0      | pas de half-carry |
| C    | 0      | pas de carry      |
Z N H C 0 0 0 0
1 0 0 0 0 0 0 0
le registre F sert a retenir des infos