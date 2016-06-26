##ITBA 2016
##Criptografia y Seguridad

##Integrantes
Kevin Hirschowitz Kraus

Jorge* Exequiel Gomez

Francisco Depascuali

Kevin Jack Hanna

Mostrar todas las opciones para ingresar parámetros
```
./stegowav -h 
Esteganografía de archivos wav.


    -h, --help                Ayuda acerca de parametros
    -t, --test                Corre pruebas de embeber y extraer

Opciones basicas
    -e, --embed               Indica que se va a ocultar la informacion. En caso de no poner este flag se asume que se extrae
    -i, --in  str             Achivo de entrada.
    -o, --out  str            Archivo de salida.
    -w, --wavefile  str       Archivo wave.
    -s, --steg  str           Algoritmo de esteganografiado. (LSB1 | LSB4 | LSBE)

Opcionales
    -a, --algorithm  str      Algoritmo de encriptacion. (aes128 | aes192 | aes256 | des)
    -m, --blockcipher  str    Algoritmo de cifrado de bloques. (ecb | cfb | ofb | cbc)
    -p, --password  str       Contraseña.


```
Extrae del archivo funTE el archivo oculto y lo guarda baja el nombre kitty usando el metodo LSBE
```
./stegowav -w "Wavs/Examples/funTE.wav" --out "/path/to/directory/filename" --steg LSBE

./stegowav -w "Wavs/Examples/funT1.wav" --out "path/to/directory/filename" --steg LSB1

./stegowav -w "Wavs/Examples/funT4.wav" --out "path/to/directory/filename" --steg LSB4
```
Para usuarios con Mac cuando se compila el proyecto puede resultar necesario el linkeo con openssl de forma explicita
```
brew link openssl --force
```
Como embeber un archivo con contraseña?
```
./stegowav --embed -w "Wavs/tpPropuestoPorCatedra/whateveroasis11a.wav" --out "Wavs/solucionTpCatedra/kitty.wav" --in "Wavs/Examples/out.wmv" --steg LSB1 --password aplausos --algorithm aes128 --blockcipher cfb
```
Como embeber un archivo sin contraseña?
```
./stegowav --embed -w "Wavs/tpPropuestoPorCatedra/whateveroasis11a.wav" --out 
"Wavs/solucionTpCatedra/kitty.wav" --in "Wavs/Examples/out.wmv" --steg LSB1
```
Como extraer un archivo sin constraseña/cifrado?
```
./stegowav -w "kitty.wav" --out "miravideo" --steg LSB1
```
Como extraer un archivo con constraseña/cifrado?
```
./stegowav -w "kitty.wav" --out "miravideo" --steg LSB1 --password aplausos --algorithm aes128 --blockcipher cfb
```
La solución al tp propuesto por la cátedra se puede conseguir corriendo los siguientes comandos:
```
./stegowav -w "Wavs/tpPropuestoPorCatedra/bendita11a.wav" --out "Wavs/solucionTpCatedra/buscaminas" --steg LSB4

./stegowav -w "Wavs/tpPropuestoPorCatedra/whateveroasis11a.wav" --out "Wavs/solucionTpCatedra/video" --steg LSB1 --password aplausos --algorithm aes128 --blockcipher cfb

./stegowav -w "Wavs/tpPropuestoPorCatedra/whateveroasis11b.wav" --out "Wavs/solucionTpCatedra/pdf" --steg LSBE
```

