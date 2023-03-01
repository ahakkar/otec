/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T8 Taulukon arvojen muunto
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

void muunnaTaulu(int n, double *taulu, double (*f)(double)) {
    int i = 0;

    for (; i < n; i++) {
        taulu[i] = f(taulu[i]);
    }
}
