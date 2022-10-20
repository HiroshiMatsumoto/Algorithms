#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> IPv4_ADD;


class Ipv4{
    public:
    string address = "";
    IPv4_ADD segments = {"", "", "", ""};
    Ipv4 operator++(int);

    Ipv4(string address){        
        this->address = address;
        this->split();
    }
    void split();

    friend ostream& operator<<(ostream& out, const Ipv4& ip);
    bool operator==(const Ipv4& ip);
    bool operator!=(const Ipv4& ip);
};

ostream &operator<<(ostream& out, const Ipv4& ip){
    out << ip.segments[0] << "." << ip.segments[1] << "." << ip.segments[2] << "." << ip.segments[3];
    return out;
}

bool Ipv4::operator==(const Ipv4& ip){
    for(int i=3; 0 < i ; i--){
        if(this->segments[i] != ip.segments[i]){
            return false;
        }
    }
    return true;
}

bool Ipv4::operator!=(const Ipv4& ip){
    return !(*this == ip);
}

Ipv4 Ipv4::operator++(int){
    int segment = 0;
    bool segment_incremnt = true;

    for(int i=3; 0 < i ; i--){
        if(!segment_incremnt)
            break;
        segment = std::stoi(this->segments[i]) + 1;
        // cout << "increment: " << segment << endl;
        if(segment < 256){            
            this->segments[i] = to_string(segment);
            segment_incremnt = false;
        }
        else if(segment_incremnt){
            this->segments[i] = to_string(0);
            segment_incremnt = true;
        }        
    }
    return *this;
}

void Ipv4::split(){
    string tmp = "";
    int segment_idx = 0;
    for(int i = 0; i < this->address.size(); i++){
        if(this->address[i] == '.')
        {
            this->segments[segment_idx] = tmp;
            tmp = "";
            segment_idx++;
            continue;
        }
        tmp.push_back(this->address[i]);
        if(segment_idx == 3)
        {
            this->segments[segment_idx] = tmp;
        }
    } 
}




int main(){
    string input_address = "";
    cout << "type in starting IPv4 address: ";
    cin >> input_address;
    // input_address = "127.0.0.1";
    Ipv4 current_ip = Ipv4(input_address);

    cout << "type in ending IPv4 address: ";
    cin >> input_address;    
    Ipv4 end_ip = Ipv4(input_address);

    cout << current_ip << endl;
    while(current_ip != end_ip){
        cout << current_ip << endl;
        current_ip++;        
    }
    cout << current_ip << endl;

    return 0;
}