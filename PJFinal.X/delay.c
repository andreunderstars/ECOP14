void atraso(unsigned char milisegundos) {

    volatile unsigned char i, j, k;
    for (i = 0; i < milisegundos; i++) {
        for (j = 0; j < 41; j++) {
            for (k = 0; k < 3; k++);
        }
    }
}
