# Trabajo-Practico-InfoII-

# Memoria descriptiva de una automatización de una compactadora.

La compactadora a automatizar se encuentra dentro de una fábrica que produce envases de cartón, que posee un sistema de aspiración encargado de triturar cartón sobrante de las máquinas para luego succionarlo y llevarlo a una sala en donde cae por un tubo cuadrado de grandes dimensiones. La compactadora cumple la función de empujar este cartón hacia un contenedor para luego ser reciclado. El sistema de aspiración lleva el cartón hacia una sala 
Ahora bien, la automatización consta de tres puntos importantes:

## 1. Ciclo automático
La idea es que la compactadora se accione bajo una sola condición y cumpla un ciclo (que empuje el cartón y regrese a su posición inicial). La condición es que compacte un bloque de cartón, para lo que se implementarán dos sensores a un determinado nivel de altura desde donde cae el cartón, de forma que cuando los dos sensores simultáneamente detecten que el cartón llegó a ese nivel, la compactadora se active, los empuje al contenedor y regrese a la posición de reposo.

## 2. Compuerta de desvío
Pueden ocurrir imprevistos como pueden ser que la compactadora no funcione, o bien que el contenedor esté lleno, provocando la acumulación no deseada de cartón, haciendo que lugar por donde cae el material se tape. Por lo que para prevenir esto, podemos agregar un nuevo sensor que esté por encima de los del punto 1, de manera que detecte si el cartón llegó a ese nivel accione una compuerta de desvió y el cartón caiga en otro depósito de forma provisoria hasta que se solucione la falla. Esta compuerta se accionaría mediante un pistón neumático, por lo que el sensor habilitaría una electroválvula para que dicho pistón se mueva. También el sensor encendería una alarma, para que el personal encargado solucione el problema.

## 3. Predicción de contenedor lleno
Cuando el contenedor se llena es retirado, para que el cartón sea reciclado, y sustituido por uno vacío. Para lograr una estimación de cuando se llenaría dicho depósito habría que hacer un conteo de la cantidad de veces que la compactadora cumple un ciclo automático. Entonces, si ocurrieron 150 ciclos, se debería encender una luz testigo, de forma que el personal pueda solicitar el cambio de contenedor y así evitar imprevistos como los mencionados en el punto 2.

# Máquina de estado

![./materiales/Maquina de estados.jpg](https://github.com/user-attachments/assets/b1f01575-c5dd-4e30-bcee-2f433fcb6654)

- S1 y S2 son los sensores de nivel.
- S3 es el sensor de nivel superior
- RUN es el flag de arranque, se dará cuando se compruebe que está todo en orden o se haya restaurado alguna falla.
- CONT es un contador que lleva la cuenta de los ciclos.

