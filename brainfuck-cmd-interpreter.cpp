
#include <iostream>
#include <vector>
#define pc(x) putchar(x)
#define gc() getchar()

 int main(int argc, char** argv){
    char* data = (char*) calloc(30000, sizeof(char));
    char* input = argc > 0 ? argv[1] : (char*)0x0;
    char* data_ptr = data;
    if(input == 0x0){
        std::cout << "No string has been entered: exiting. . .";
        return 0;
    }
        std::vector<char*>jump_loc;
        for(char* instr_ptr = input; ; instr_ptr++){
            switch(*instr_ptr){
                case '>':
                    data_ptr++;  break;  
                case '<':
                    data_ptr--;  break;
                case '+':           
                   ++*data_ptr; break;
                case '-':
                    --*data_ptr; break;
                case '.':
                    pc(*data_ptr); break;
                case ',':
                    *data_ptr=gc(); break;
                case ']':
                    if(*data_ptr){
                        instr_ptr = jump_loc.back();
                        instr_ptr--; 
                    }
                    jump_loc.pop_back();
                    break;
                case '[':
                    if(*data_ptr)
                        jump_loc.push_back(instr_ptr); 
                    else
                        for(;*instr_ptr != ']'; instr_ptr++);    
                    break;
                default:  
                    char* inst_peek = instr_ptr;
                    if(*inst_peek =='E')
                        if(*(++inst_peek) =='N')
                            if(*(++inst_peek) =='D'){
                                std::cout << std::endl << "end sequence found: terminating. . . ";
                                return 0;
                            }
                    else if(*inst_peek == '\0')
                        return 0;
                    else if(*inst_peek == 'D')
                        if(++*inst_peek == 'B'){
                            int start,stop;
                            std::cout << "\nDEBUG: Specifiy tape range (space seperated): ";
                            std::cin >> start >> stop;
                            std::cout << "\nindex\thex\tdec";
                            for(; start <= stop; start++)
                                std::cout << start << "\t" << std::hex << std::uppercase << data[start] << "\t" << std::dec << std::nouppercase << data[start];
                        }

            }
        }
     return 0;
 }