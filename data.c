//
// Created by Lies Amarouche on 02/01/2021.
//

#include "data.h"
#include "list.h"

//load data file
iris_data save_data_file(){
    iris_data iris_data = malloc(DATA_SIZE * sizeof(*iris_data));
    FILE *fp;
    int i=0;
    char str[BUFFER_SIZE];
    char *token;
    fp = fopen("../iris.data" , "r");
    if(fp == NULL) {
        perror("Error opening file");
    }
    while((fgets(str, BUFFER_SIZE, fp) != NULL)){
        iris_data[i].spec=malloc(SPEC_SIZE * sizeof(*iris_data[i].spec));
        token = strtok(str,",");
        for(int j=0; j < SPEC_SIZE; j++){
            if(token){
                iris_data[i].spec[j]=strtod(token, NULL);
                token = strtok(NULL,",");
            }
        }
        iris_data[i].norm = vec_norm(iris_data[i]);
        normalize_vec(iris_data[i], iris_data[i].norm);
        token=strtok(token,"\n");
        iris_data[i].label=strdup(token);
        i++;
    }
    return iris_data;
}


//calculate norm
double vec_norm(iris_input_data_unit_t input_vec){
    double norm=0;
    for (int i = 0; i < SPEC_SIZE; ++i)
    {
        norm = norm + input_vec.spec[i] * input_vec.spec[i];

    }
    return sqrt(norm);
}

//vector normalize
void normalize_vec(iris_input_data_unit_t input_vec, double norm){
    for (int i = 0; i < SPEC_SIZE; ++i)
    {
        input_vec.spec[i]= input_vec.spec[i] / norm;
    }
}

void swap (int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}



//calculate average vector
double * average_vector(iris_data iris){
    double * vec =  malloc(SPEC_SIZE * sizeof(*vec));;

    for (int i = 0; i < DATA_SIZE; i++){
        for (int j= 0; j < SPEC_SIZE; j++){
            vec[j]+= iris[i].spec[j];
        }
    }
    for (int i = 0; i < SPEC_SIZE; ++i)
    {
        vec[i]/=DATA_SIZE;
    }
    return vec;
}



//randomize in certain range min max
double rand_range(double feature,double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return  feature + min + ((double)rand() / div);
}

//peak random index in table
int * randomize(){
    int * tab = malloc(DATA_SIZE * sizeof(*tab));;
    int random_access;
    for (int i = 0; i < DATA_SIZE; ++i){
        tab[i]=i;
    }
    for (int i = 0; i < DATA_SIZE; ++i){
        random_access= rand() % (DATA_SIZE - i) + i;
        swap(&tab[i], &tab[random_access]);
    }
    return tab;
}

//generate processing units matrix
processing_units init_processing_units_network_matrix(iris_data data){

    double * av_vector = average_vector(data);
    processing_units network = malloc (sizeof(* network));



    network->units = malloc(MATRIX_NB_LINE * sizeof(iris_input_data_unit_t));
    for(int i = 0; i<MATRIX_NB_LINE; ++i)
        network->units[i] = malloc(MATRIX_NB_COLUMN * sizeof(iris_input_data_unit_t));



    for(int i = 0; i<MATRIX_NB_LINE; ++i){
        for (int j= 0; j< MATRIX_NB_COLUMN; ++j){
            network->units[i][j].spec = malloc(SPEC_SIZE * sizeof(* network->units[i][j].spec));
            for (int k = 0; k < SPEC_SIZE; ++k){
                double val=rand_range(av_vector[k],0.05, 0.05);
                network->units[i][j].spec[k] = val;
            }
            network->units[i][j].label = NULL;
        }
    }
    return network;
}

//calculer la distance euclidienne entre deux vecteurs
double distance(double* unit, double* input_vec){
    return sqrt(pow((unit[0] - input_vec[0]), 2.0)
                +pow((unit[1] - input_vec[1]), 2.0)
                +pow((unit[2] - input_vec[2]), 2.0)
                +pow((unit[3] - input_vec[3]), 2.0));
}

//fonction pour avoir la liste des units gagnants
list best_match_unit_s(processing_units network, double * vec){
    position neurone_winner_coord;
    list winners = list_contructor();

    neurone_winner_coord.i=0;
    neurone_winner_coord.j=0;

    double distance_min,distance_;
    distance_min=distance(vec, network->units[0][0].spec);
    for (int l= 0; l <MATRIX_NB_LINE; ++l){
        for(int c=1; c < MATRIX_NB_COLUMN; ++c){
            distance_ = distance(vec, network->units[l][c].spec);
            if(distance_ < distance_min){
                distance_min = distance_;
                neurone_winner_coord.i=l;
                neurone_winner_coord.j=c;
            }
        }
    }
    push_back(winners, neurone_winner_coord);

    for (int l= 0; l <MATRIX_NB_LINE; ++l){
        for(int c=0; c < MATRIX_NB_COLUMN; ++c){
            distance_ = distance(vec, network->units[l][c].spec);
            if(distance_ == distance_min && (l!=neurone_winner_coord.i&&c!=neurone_winner_coord.j)){
                neurone_winner_coord.i=l;
                neurone_winner_coord.j=c;
                push_back(winners, neurone_winner_coord);
            }
        }
    }

    return winners;
}


//fonction pour tirer un neurone au hasard dans une liste
position unit_selection(list l, int nb_iteration){
    position n;
    n=back(l);
    for(int i=0;i<nb_iteration;i++){
        pop_back(l);
        n=back(l);
    }
    return n;
}


//fonction d'collaboration selon le rayon
void collaboration(position unit_map_position, int radius, processing_units network, int* adjacent_units){
    adjacent_units[0] = unit_map_position.i - radius < 0 ? 0 : unit_map_position.i - radius ;//north
    adjacent_units[1] = unit_map_position.i + radius > MATRIX_NB_LINE - 1 ? MATRIX_NB_LINE - 1 : unit_map_position.i + radius;//south
    adjacent_units[2] = unit_map_position.j + radius > MATRIX_NB_COLUMN - 1 ? MATRIX_NB_COLUMN - 1 : unit_map_position.j + radius;//west
    adjacent_units[3] = unit_map_position.j - radius < 0 ? 0 : unit_map_position.j - radius;//east
}





void learning(iris_data iris_data, processing_units network, double alpha0, int radius, int nb_iteration){
    double alpha ;
    int *peak_random_index_tab;
    position winner_coord;
    int* adjacent_units;
    adjacent_units=malloc(4 * sizeof(int));
    int cycle_iteration = nb_iteration/radius;

    for (int nb = 1; nb < nb_iteration; ++nb){

        alpha = alpha0 * (1.0 - ((double)nb / (double)nb_iteration));

        peak_random_index_tab= randomize();
        for (int i = 0; i < DATA_SIZE; ++i){
            double *v = iris_data[peak_random_index_tab[i]].spec;
            winner_coord= unit_selection(best_match_unit_s(network, v), rand() % size(best_match_unit_s(network, v)));

            for(int i=0;i<4;i++){
                adjacent_units[i]=0;
            }

            if(nb%(cycle_iteration) == 0)
                radius--;

            collaboration(winner_coord, radius, network, adjacent_units);

            for (int l=adjacent_units[0]; l <= adjacent_units[1] ; l++){
                for (int c =adjacent_units[3] ; c <= adjacent_units[2]; c++){
                    double *w = network->units[l][c].spec;
                    for (int k=0; k < SPEC_SIZE; ++k){
                        w[k] += alpha * (v[k] - w[k]);

                    }
                }
            }

        }
        free(peak_random_index_tab);

    }
}
//fonction d'etiquittage selon la distance
void classification(iris_data data, processing_units network){

    double min_distance;
    double current_distance;

    int winner_index = 0;

    for (int l = 0; l < MATRIX_NB_LINE; l++){
        for(int c=0;c< MATRIX_NB_COLUMN; c++){
            min_distance=distance(data[0].spec, network->units[l][c].spec);
            for (int i= 1; i < DATA_SIZE ; ++i){
                current_distance = distance(data[i].spec, network->units[l][c].spec);
                if(current_distance < min_distance){
                    min_distance = current_distance;
                    winner_index = i;
                }
            }
            network->units[l][c].label =data[winner_index].label;
        }
    }
    free(data);
}

void processing_units_network_after_learning_display(processing_units network){
    for (int i = 0; i < MATRIX_NB_LINE; ++i){
        for (int j= 0; j< MATRIX_NB_COLUMN; ++j){
            if((strcmp(network->units[i][j].label, "Iris-virginica")) == 0) {
                printf("\033[1;31m");
                printf("1 ");
            }
            if((strcmp(network->units[i][j].label, "Iris-versicolor")) == 0) {
                printf("\033[1;32m");
                printf("2 ");
            }
            if((strcmp(network->units[i][j].label, "Iris-setosa")) == 0) {
                printf("\033[1;34m");
                printf("3 ");
            }
            if((strcmp(network->units[i][j].label, "NULL")) == 0)
                printf("%d",0);
        }
        printf("\n");
    }

    printf("\n");

    printf("\033[1;31m");
    printf("1 -> virginica");
    printf("\n");
    printf("\033[1;32m");
    printf("2 -> versicolor");
    printf("\n");
    printf("\033[1;34m");
    printf("3 -> setosa");

    free(network);


}

