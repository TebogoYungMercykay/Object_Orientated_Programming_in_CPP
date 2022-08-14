#include "GreenBabushka.h"
#include "DisplacementException.h"
#include <string>

GreenBabushka::GreenBabushka(const unsigned char* id, unsigned int displacement) : Babushka(id){
    this->displacement = displacement;
}
void GreenBabushka::encrypt(unsigned char* data, int size){
    DisplacementException DisplacementEx;
    unsigned char ftttt;
    if(this->displacement > size)throw DisplacementEx;
    else{
        std::string holder_thingie="";
        for(int k=0; k< size; k++)holder_thingie += data[k];
        int p = displacement+2;
        for(int i=0; i<size; i+=p)
            if(i<size){
                int dfGG = i+p;
                if(dfGG-1 < size){
                    ftttt = holder_thingie[i];
                    holder_thingie[i] = holder_thingie[dfGG-1];
                    holder_thingie[dfGG-1] = ftttt;
                }
            }
        for(int k=0; k< size; k++)data[k] = holder_thingie[k];
    } 
}
void GreenBabushka::decrypt(unsigned char* data, int size){
    this->encrypt(data,size);
}