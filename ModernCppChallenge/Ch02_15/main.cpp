#include <iostream>
#include <vector>

using namespace std;

typedef vector<string> IPv4_ADD;


class ipv4{
    public:
    string address = "";
    IPv4_ADD segments = {"", "", "", ""};

    ipv4(string address){        
        this->address = address;
        this->split();
    }

    void split(){// string address){
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
    friend ostream& operator<<(ostream& out, const ipv4& ip);
};

ostream &operator<<(ostream& out, const ipv4& ip){
    out << ip.segments[0] << "." << ip.segments[1] << "." << ip.segments[2] << "." << ip.segments[3];
    return out;
}

int main(){
    string input_address = "";
    cout << "type in IPv4 address: ";
    cin >> input_address;
    ipv4 ip = ipv4(input_address);
    cout << ip << endl;   
    return 0;
}