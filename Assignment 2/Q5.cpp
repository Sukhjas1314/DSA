#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Node{
    public :
        char ch;
        int freq;
        Node* left;
        Node* right;

        Node(char ch,int freq){
            this->ch = ch;
            this->freq = freq;
            left = right = nullptr;
        }
};

class Compare{
    public :
        bool operator()(Node* a,Node* b){
            return a->freq > b->freq;
        }
};

int findChar(char chars[],int size,char c){
    for (int i = 0 ; i < size ; i++){
        if (chars[i] == c){
            return i;
        }
    }
    return -1;
}

void getCodes(Node* root,string code,char chars[],string codes[],int& index){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL){
        chars[index] = root->ch;
        codes[index] = code;
        index++;
    }
    getCodes(root->left,code + '0',chars,codes,index);
    getCodes(root->right,code + '1',chars,codes,index);
}

string encode(string text,char chars[],string codes[],int size){
    string result = "";
    for (int i = 0 ; i < text.length() ; i++){
        char c = text[i];
        for (int j = 0 ; j < size ; j++){
            if (chars[j] == c){
                result += codes[j];
                break;
            }
        }
    }
    return result;
}

string decode(Node* root,string encoded){
    string result = "";
    Node* current = root;
    for (int i = 0 ; i < encoded.length() ; i++){
        if (encoded[i] == '0'){
            current = current->left;
        }
        else{
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL){
            result += current->ch;
            current = root;
        }
    }
    return result;
}

int main(){
    string text;
    cout << "Enter the string : ";
    getline(cin,text);

    char chars[256];
    int freq[256];
    int size = 0;

    for (int i = 0 ; i < text.length() ; i++){
        char c = text[i];
        int index = findChar(chars,size,c);
        if (index == -1){
            chars[size] = c;
            freq[size] = 1;
            size++;
        }
        else{
            freq[index]++;
        }
    }

    priority_queue<Node*,vector<Node*>,Compare> pq;
    for (int i = 0 ; i < size ; i++){
        pq.push(new Node(chars[i],freq[i]));
    }

    while(pq.size() > 1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node('\0',left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();
    string codes[256];
    int index = 0;
    getCodes(root,"",chars,codes,index);

    cout << "\nHuffman codes : " << endl;
    for (int i = 0 ; i < index ; i++){
        cout << chars[i] << " : " << codes[i] << endl;
    }

    string encoded = encode(text,chars,codes,index);
    cout << "\nEncoded : " << encoded << endl;

    string decoded = decode(root,encoded);
    cout << "\nDecoded : " << decoded << endl;
    cout << endl;

    return 0;
}