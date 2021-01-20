
//
// Created by Lies Amarouche on 02/01/2021.
//

#include "data.h"
#include<time.h>

int main(){
    srand(time(NULL));
    iris_data data;
    processing_units network;

    data = save_data_file();
    network= init_processing_units_network_matrix(data);

    learning(data, network, 0.9, 3, 500);
    learning(data, network, 0.09, 1, 1500);

    classification(data, network);

    processing_units_network_after_learning_display(network);
}