#include "board.h"
#include "piece.h"
#include "solver.h"

solver::solver(std::string game){
    int counter_variable=0;
    std::string line_string_counter="";
	std::ifstream my_inputFile_count;
	my_inputFile_count.open(game.c_str());
    while(getline(my_inputFile_count,line_string_counter)){
        counter_variable++;
    }
    this->numGames=counter_variable;
    my_inputFile_count.close();
    std::string line_string="";
	std::ifstream my_inputFile;
	my_inputFile.open(game.c_str());
    boards = new board*[this->numGames];
    for(int k_iterator=-0;k_iterator<this->numGames;k_iterator++){
        boards[k_iterator]=NULL;
    }
    std::string Temp_Holder;
    int k_num_boards = 0;
    int *priorities_array=new int[this->numGames];
    int *sort_priority_array=new int[this->numGames];
    while(getline(my_inputFile,Temp_Holder) && k_num_boards<this->numGames){
        std::stringstream ss_priority (Temp_Holder);
        getline(ss_priority,Temp_Holder,',');
        this->boards[k_num_boards]=new board(Temp_Holder);
        ss_priority>>sort_priority_array[k_num_boards];
        priorities_array[k_num_boards]=sort_priority_array[k_num_boards];
        k_num_boards+=1;
    }
    int temp_variable;
	for(int i_iterator=0;i_iterator<this->numGames;i_iterator++){		
		for(int j_iterator=i_iterator+1;j_iterator<this->numGames;j_iterator++){
			if(sort_priority_array[i_iterator]>sort_priority_array[j_iterator]){
				temp_variable  =sort_priority_array[i_iterator];
				sort_priority_array[i_iterator]=sort_priority_array[j_iterator];
				sort_priority_array[j_iterator]=temp_variable;
			}
		}
	}
    for(int i_iterator = 0;i_iterator<this->numGames;i_iterator++){
        for(int  j_iterator=0; j_iterator<this->numGames; j_iterator++){
            if(sort_priority_array[i_iterator]==priorities_array[j_iterator]){
                std::cout<<"["<<sort_priority_array[i_iterator]<<"] ";
                this->boards[j_iterator]->operator--();
            }
        }
    }
    my_inputFile.close();
}
solver::~solver(){
    for(int k_iterator=0;k_iterator<this->numGames;k_iterator++){
        if(boards[k_iterator]!=NULL){
            delete this->boards[k_iterator];
            boards[k_iterator]=NULL;
        }
    }
    delete [] boards;
    boards = NULL;
    std::cout<<"Num Boards Deleted: "<<this->numGames<<std::endl;
}