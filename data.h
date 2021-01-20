//
// Created by Lies Amarouche on 02/01/2021.
//

#ifndef MY_SOM_DATA_H
#define MY_SOM_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define DATA_SIZE 150
#define SPEC_SIZE 4
#define BUFFER_SIZE 256
#define MATRIX_NB_LINE 12
#define MATRIX_NB_COLUMN 5

//structure pour conserver les données du fichier iris
struct iris_input_data_unit
{
    double *spec;
    char *label;
    double norm;
};

typedef struct iris_input_data_unit iris_input_data_unit_t;
typedef struct iris_input_data_unit* iris_data;

struct neurone{
    double *spec;
    char *label;
};

typedef struct neurone neurone;

//structure pour representer la matrice des units
struct network{
    neurone ** units;
};
typedef struct network* processing_units;

//structure pour representer les coordonées des units
struct position{
    int i;
    int j;
};
typedef struct position position;

iris_data save_data_file();
double vec_norm(iris_input_data_unit_t input_vec);
void normalize_vec(iris_input_data_unit_t input_vec, double norm);
int * randomize();
double * average_vector(iris_data t);
processing_units init_processing_units_network_matrix(iris_data data);
void collaboration(position unit_map_position, int radius, processing_units network, int *adjacent_units);
void learning(iris_data iris_data, processing_units network, double alpha0, int radius, int nb_iteration);
void classification(iris_data data, processing_units network);
void processing_units_network_after_learning_display(processing_units network);




#endif
