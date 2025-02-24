#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


void displayTape(const vector<int>& tape, int pos) {
    int windowSize = 10; 
    int start = max(0, pos - windowSize / 2);
    int end = min((int)tape.size(), start + windowSize);

    cout << "\nTAPE VALUES:\n---------------------------\n";

    // Print tape values
    for (int i = start; i < end; i++) {
        if (i == pos) cout << "[" << tape[i] << "] "; 
        else cout << tape[i] << " ";
    }
    cout << "\n---------------------------\n";
    cout << "\nMEMORY ADDRESS:\n---------------------------\n";

    // Print tape values
    for (int i = start; i < end; i++) {
        if (i == pos) cout << "[" << i << "] "; 
        else cout << i << " ";
    }
    
   
    cout << "\n";
}


void saveTape(const vector<int>& tape, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "--File Error--\nFailed to save tape!\n\n";
        return;
    }
    for (int bit : tape) {
        file << bit;
    }
    file.close();
    cout << "--TAPE SAVED--\nFile: " << filename << "\n\n";
}

void loadTape(vector<int>& tape, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "--File Error--\nTape file not found!\n\n";
        return;
    }
    
    tape.clear();
    char bit;
    while (file.get(bit)) {  // Use file.get to read character-by-character
        if (bit == '0' || bit == '1') {
            tape.push_back(bit - '0'); // Convert char to int
        }
    }
    file.close();
    cout << "--TAPE LOADED--\nNew size: " << tape.size() << "\n\n";
}
int main() {
    std::vector<int> tape;
    int pos = 0;
    char move;
    int oldpos;
    
    for(int i=0; i<2040; i++){
        tape.push_back(rand() % 2);
    }
    cout<<"Tape>";
    cin>>move;
    while(1){
        if (move == 'o') {
            string fname;
            cout<<"SAVE TAPE AS: ";
            getline(cin>>ws, fname);
            saveTape(tape, fname);
        } else if (move == 'l') {
            string fname;
            cout<<"LOAD TAPE: ";
            getline(cin>>ws, fname);
            
            loadTape(tape, fname);
        } else
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
            displayTape(tape, pos);
        
    
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
                tape.resize(pos + 1); 
                cout << "--PARTITION--\n";
                cout << "Tape split at position: " << pos << "\n";
                cout << "New tape size: " << tape.size() << "\n\n";
            } else {
                cout << "--Memory Error--\nCannot partition at this position.\n\n";
            }
        }else
        if (move == 'e') { 
            int newSize;
            cout << "\nEXPAND TAPE BY: ";
            cin >> newSize;
        
            if (newSize > 0) {
                int oldSize = tape.size();
                tape.resize(oldSize + newSize);  // Resize first, without setting values
        
                // Randomize only the new part
                for (int i = oldSize; i < tape.size(); i++) {
                    tape[i] = rand() % 2;  // Now each new element is randomized
                }
        
                cout << "--TAPE EXPANDED--\nNew tape size: " << tape.size() << "\n\n";
            } else {
                cout << "--Memory Error--\nNew size must be a positive number!\n\n";
            }
        }
        
        else
        if (move == 's') {
            cout<<"TAPE SIZE: "<<tape.size()<<"\n";
        }else
        if (move == 'f') {
            cout << "FULL TAPE:\n";
            for (size_t i = 0; i < tape.size(); i++) {
                cout << tape[i] << " ";
                if ((i + 1) % 50 == 0) cout << "\n"; 
            }
            cout << "\n\n";
        }
        
        cout<<"Tape>";
        cin>>move;
    }
    
    return 0;
}
