#include <stdio.h>
#include <math.h>

typedef struct grado_s{
    int g;
    int m;
    int s;
} tgrado;

tgrado radianti2gradi(float);
float gradi2radianti(tgrado);

int main(int argc, char * argv[]) {
    float torad, rad = 0.82223430;
    tgrado togr, gr = { .g = 90, .m=30, .s=15 };

    togr = radianti2gradi(rad);
    torad = gradi2radianti(gr);
    printf("[rad] %f -> [gr] %d* %d' %d''\n", rad, togr.g, togr.m, togr.s);
    printf("[gr] %d* %d' %d'' -> [rad] %f\n", gr.g, gr.m, gr.s, torad);

    return 0;
}

tgrado radianti2gradi(float rad) {
    tgrado res;
    float tmp;

    tmp = (rad*180)/M_PI;
    res.g = (int) tmp;
    tmp -= res.g;
    tmp *= 60;
    res.m = (int) tmp;
    tmp -= res.m;
    tmp *= 60;
    res.s = (int) tmp;

    return res;
}

float gradi2radianti(tgrado gr) {
    float res, tmp;

    tmp = gr.g + gr.m/60 + gr.s/3600;
    res = (M_PI*tmp)/180;

    return res;
}
