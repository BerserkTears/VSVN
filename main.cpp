#include "fstream"
#include "iostream"

void RewriteBackwards(std::fstream &input, std::fstream &output){
    char tmp[1];
    while(input.tellg() != 0) {
        long long pos = input.tellg();
        pos -= 1;
        input.seekg(pos);
        input.read(tmp, sizeof(tmp));
        output.write(tmp, sizeof(tmp));
        input.seekg(pos);
    }
}

int main(int argc, char *argv[]) {
    std::fstream input(argv[1], std::fstream::in | std::fstream::binary | std::fstream::ate),
                 output(argv[2], std::fstream::out | std::fstream::trunc | std::fstream::binary);
    if(argc < 3){
        throw std::invalid_argument("not enough arguments");
    }
    if(!input.good()){
        throw std::invalid_argument("error while opening input file");
    }
    if(!output.good()){
        throw std::invalid_argument("error while opening output file");
    }
    RewriteBackwards(input, output);
}