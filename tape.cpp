#include <iostream>
#include <vector>


using namespace std;
int main() {
    std::vector<int> tape;
    int pos = 0;
    char move;
    int oldpos;
    
    for(int i=0; i<2040; i++){
        tape.push_back(rand() % 2);
    }

    while(1){
        cout<<"Tape>";
        cin>>move;
        if(move == '>'){
            oldpos = pos;
            if(pos!=tape.size()){
                pos += 1;
                cout<<"\nSHIFTED FROM: "<<oldpos<<" TO: "<<pos<<"\n";
            }else
            if(pos == tape.size()){
                cout<<"--Memory Overflow Error--\n"<<"Cannot go above tape length\n\n";
            }
        }else

        if(move == '<'){
            oldpos = pos;
            if(pos>0){
                pos -= 1;
                cout<<"\nSHIFTED FROM: "<<oldpos<<" TO: "<<pos<<"\n";
            }else
            cout<<"--Memory Underflow Error--\n"<<"Cannot go below address 0\n\n";
        }else

        if(move == 'r'){
            cout<<"VALUE: "<<tape[pos]<<" AT ADDRESS: "<<pos<<"\n";
        }else

        if(move == 'w'){
            int writeMem;
            cout<<"\nWRITE AT ADRESS: "<<"\n"<<"Write>";
            cin>>writeMem;
            if(writeMem == 0||writeMem==1){
                tape[pos] = writeMem;
            }
            else
            cout<<"--Memory Error--\n"<<"Can only write binary digit to memory\n\n";


        }else
        if (move == 't') {
            int displayPos = pos; 
            std::string indexPointer;
            int limit = min(pos + 10, (int)tape.size()); 
            cout<<"\nTAPE:";
            cout << "\nVALUES:  ";
            for (int i = displayPos; i < limit; i++) {
                if(i<10){
                    indexPointer =  "/\\\n";
                    cout << tape[i] << "|";
                }else
                if(i>10){
                    indexPointer =  " /\\\n";
                    cout << tape[i] << " |";
                }
            }
            cout << "\nADDRESS: ";
            for (int i = displayPos; i < limit; i++) {
                
                cout << i << "|";
                
            }
            cout << "\n        "+indexPointer;
        
    
        }else
        if (move == 'x') {
            cout<<"\nWIPED VALUE: "<<tape[pos]<<" FROM ADDRESS: "<<pos<<"\n";
            tape[pos] = 0;
            
        
    
        }else
        if (move == 'j') {
            int index; 
            int oldindex = pos;
            
            
            cout<<"\nJUMP TO ADRESS: "<<"\n"<<"Jump>";
            cin>>index;
            if(index >= 0 && index < tape.size()) { pos = index; 
                cout<<"\nJUMPED FROM: "<<oldindex<<" TO: "<<index<<"\n";}  
            
            else { cout << "--Memory Error--\nInvalid jump address.\n\n"; }
            
        
    
        }else
        if (move == 'c') {
            int from; 
            int to;
            
                cout<<"\nCOPY FROM ADDRESS: "<<"\n"<<"Copy From>";
                cin>>from;
                cout<<"\nTO ADDRESS: "<<"\n"<<"Into>";
                cin>>to;
            
                if(to >= 0 && to < tape.size() && from >= 0 && from < tape.size()){
            
                cout<<"\nCOPIED VALUE: "<<tape[from]<<" FROM ADDRESS: "<<from;
                cout<<"\nOVERWRITING VALUE: "<<tape[to]<<" AT ADRESS: "<<to<<"\n";
                tape[to] = tape[from];
            }else{ cout << "--Memory Error--\nInvalid Copy address.\n\n"; };
            
        }else
        if (move == 'p') {
            if (pos < tape.size()) {
                tape.resize(pos + 1); // Cut the tape at the current position
                cout << "--SPLIT--\n";
                cout << "Tape split at position: " << pos << "\n";
                cout << "New tape size: " << tape.size() << "\n\n";
            } else {
                cout << "--Memory Error--\nCannot partition at this position.\n\n";
            }
        }else
        if (move == 's') {
            cout<<"TAPE SIZE: "<<tape.size()<<"\n";
        }else
        if (move == 'f') {
            cout << "FULL TAPE:\n";
            for (size_t i = 0; i < tape.size(); i++) {
                cout << tape[i] << " ";
                if ((i + 1) % 50 == 0) cout << "\n"; // Newline every 50 values for readability
            }
            cout << "\n\n";
        }
        
        
    }

    return 0;
}
