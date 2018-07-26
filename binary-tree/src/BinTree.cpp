#include "BinNode.hpp";

template <typename T> class BinTree{
    protected:
        int _size; BinNodePosi(T) _root;    //规模; 根节点
        virtual int updateHeight( BinNodePosi(T) x);    //更新节点x的高度
        void updateHeightAbove (BinNodePosi(T) x);  //更新节点x及其祖先的高度
    public:
        BinTree():_size(0),_root(NULL){}    //构造函数
        ~BinTree(){if(0<_size)remove(_root);}   //析构函数
        int size const{return _size;}   //获取规模
        bool isEmpty() const {return !_root;}   //判断是否为空
        BinNodePosi(T) getRoot() const { return _root;} //返回根节点
        BinNodePosi(T) insertAsRoot(T const& e);    //插入根节点
        BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);    //e作为x的左孩子插入
        BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);    //e作为x的右孩子插入
        BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &T);    //T作为x左子树插入
        BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &T);    //T作为x右子树插入
        int remove(BinNodePosi(T) x);   //删除以位置x处节点为根的子树,返回该子树原先的规模
        BinTree<T>* secede(BinNodePosi(T) x);   //将子树x从当前的树中摘除,并将其转换为一棵独立子树
        template <typename VST> //操作器
        void travPre(VST& visit){
            if (_root) _root->travPre(visit);//先序遍历
        }
        template <typename VST> //操作器
        void travIn(VST& visit){
            if(_root) _root->travIn(visit); //中序遍历
        }
        template <typename VST> //操作器
        void travPost(VST& visit){
            if(_root) _root->travPost(visit);   //后序遍历
        }
        bool operator< (BinTree<T> const& t)    //比机器
        {
            return _root && t._root && lt(_root, t._root);
        }
        bool operator== (BinTree<T> const& t){
            return _root && t._root && (_root == t._root);
        }
};

template <typename T> int BinTree<T> :: updateHeight(BinNodePosi(T) x){
    return x->height = 1+max(stature(x->lc), stature(x->rc));
}