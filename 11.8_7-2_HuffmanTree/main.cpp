#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

class minHeapNode {
public:
    int frequency;
    char chara;
    minHeapNode *left, *right;

    minHeapNode(int frequency, char chara) {
        this->frequency =frequency;
        this->chara = chara;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//用于优先队列的比较类
class compare {
public:
    bool operator() (minHeapNode *l, minHeapNode *r) {
        return l->frequency > r->frequency;
    }
};

void calculateHuffmanCodes(minHeapNode *root, string s, map<char, string>& huffmanCodes) {
    if(root == nullptr) return;

    if(root->chara != '!') {
        huffmanCodes.insert(make_pair(root->chara, s));
    }

    calculateHuffmanCodes(root->left, s + "0", huffmanCodes);
    calculateHuffmanCodes(root->right, s + "1", huffmanCodes);
}

map<char, string> getHuffmanCodes(int arr[], int size, char charas[]) {
    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> queue;

    map<char, string> huffmanCodes;

    for(int i = 0; i < size; i++) {
        queue.push(new minHeapNode(arr[i], charas[i]));
    }

    while(queue.size() != 1) {
        minHeapNode *left = queue.top();    //将最小的元素作为左节点
        queue.pop();

        minHeapNode *right = queue.top();
        queue.pop();

        minHeapNode *root = new minHeapNode(left->frequency + right->frequency, '!');
        root->left = left;
        root->right = right;

        queue.push(root);
    }

    calculateHuffmanCodes(queue.top(), "", huffmanCodes);

    return huffmanCodes;
}


int main() {
    int arr[8] = {7, 19, 2, 6, 32, 3, 21, 10};
    char charas[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    map<char, string> huffmanCodes;

    huffmanCodes = getHuffmanCodes(arr, 8, charas);

    string s, tmp;
    char temp;
    int i = 0;

    while(scanf("%c", &temp) != EOF) {
        if(temp == '\n') break;
        s.push_back(temp);
    }

    while(s.size() > 0) {
        for(i = 0; i < s.size(); i++) {
            tmp.assign(s, 0, i + 1);
            for(char j = 'a'; j <= 'h'; j++) {

                if(huffmanCodes[j] == tmp) {
                    cout << j;
                    s.erase(0, i + 1);
                    i = -1;
                    break;
                }
            }

        }
    }

    return 0;
}
