#ifndef LIBBRENT_H
#define LIBBRENT_H


double brent(double (*function)(double), double a, double b, double epsi, int iter, bool debug);

#endif // LIBRENT_H
