cd ..
./stegowav -w "Wavs/tpPropuestoPorCatedra/bendita11a.wav" --out "Wavs/solucionTpCatedra/buscaminas" --steg LSB4

./stegowav -w "Wavs/tpPropuestoPorCatedra/whateveroasis11a.wav" --out "Wavs/solucionTpCatedra/video" --steg LSB1 --password aplausos --algorithm aes128 --blockcipher cfb

./stegowav -w "Wavs/tpPropuestoPorCatedra/whateveroasis11b.wav" --out "Wavs/solucionTpCatedra/pdf" --steg LSBE
