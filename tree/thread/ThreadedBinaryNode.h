// ThreadedBinaryNode.h 스레드 이진 트리를 위한 노드 클래스
class ThreadedBinNode
{
private:
    int data;
    ThreadedBinNode* left;
    ThreadedBinNode* right;
public:
    bool bThread;
    ThreadedBinNode(int val, ThreadedBinNode* l, ThreadedBinNode* r, bool bTh)
        : data(val), left(l), right(r), bThread(bTh) {}
    int getData() { return data; }
    void setRight(ThreadedBinNode* r) { right = r; }
    ThreadedBinNode* getLeft() { return left; }
    ThreadedBinNode* getRight() { return right; }
};