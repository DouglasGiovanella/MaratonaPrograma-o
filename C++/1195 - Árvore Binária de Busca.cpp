#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cassert>

using namespace std;


///=============================================================================///
///=============================================================================///
///=============================================================================///
#define LEAF NULL
template <class T>
class BinaryTreeNode{
    private:T element;
    private:BinaryTreeNode* left;
    private:BinaryTreeNode* right;

    ///////////////////////////////////////////////////////////////////////////////
    // Constructors
    public:BinaryTreeNode( const T value ){
        element = value;
        left = right = LEAF;
    }
    ///////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////
    // Getters & Setters
    public:T getElement(){ return element; }
    public:BinaryTreeNode** getLeftBranch(){ return &left; }
    public:BinaryTreeNode** getRightBranch(){ return &right; }
    public:void setElement( T value ){ element = value; }
    public:void setLeftBranch( BinaryTreeNode<T>* branch ){ left = branch; }
    public:void setRightBranch( BinaryTreeNode<T>* branch ){ right = branch; }
    ///////////////////////////////////////////////////////////////////////////////
};
///=============================================================================///
///=============================================================================///
///=============================================================================///



///=============================================================================///
///=============================================================================///
///=============================================================================///
#define LEAF NULL
template <class T>
class BinaryTree{
    private:BinaryTreeNode<T>* root;

    ///////////////////////////////////////////////////////////////////////////////
    // Constructors
    public:BinaryTree(  ){ root = LEAF; }
    ///////////////////////////////////////////////////////////////////////////////
    public:BinaryTree( const T value ){ root = new BinaryTreeNode<T>( value ); }
    ///////////////////////////////////////////////////////////////////////////////
    // Create a BinaryTree based on Pre-Order and In-Order paths
    // REQUIREMENT: createBT( )
    /// O( V log V )
    public:BinaryTree( vector<T> preOrder, vector<T> inOrder ){
        assert( preOrder.size() == inOrder.size() );
        unsigned n = preOrder.size()-1;
        map<T, unsigned> inOrderMap;
        for( unsigned i=0; i<inOrder.size(); i++ )
            inOrderMap[ inOrder[i] ] = i;
        root = createBT( preOrder, inOrder, inOrderMap, 0, n, 0, n );
    }
    ///////////////////////////////////////////////////////////////////////////////
    // USED BY: BinaryTree( ) #constructor#
    private:BinaryTreeNode<T>* createBT( vector<T>& pre, vector<T>& in,
                    map<T,unsigned>& inMap, unsigned ps, unsigned pe,
                    unsigned is, unsigned ie ){
        if( ps > pe || is > ie ) return LEAF;
        BinaryTreeNode<T>* node = new BinaryTreeNode<T>( pre[ps] );
        unsigned ip = inMap[ pre[ps] ];
        node->setLeftBranch( createBT(pre, in, inMap, ps+1, ps+(ip-is), is, ip-1) );
        node->setRightBranch( createBT(pre, in, inMap, ps+(ip-is)+1, pe, ip+1, ie ) );
        return node;
    }
    ///////////////////////////////////////////////////////////////////////////////




    ///////////////////////////////////////////////////////////////////////////////
    // Getters & Setters
    public:BinaryTreeNode<T> getRoot(){ return root; }
    ///////////////////////////////////////////////////////////////////////////////





    ///////////////////////////////////////////////////////////////////////////////
    // ADD ELEMENT
    // Add a new element in the the binary tree keeping it sorted
    // PARAMETER equal_value_option: used when the new element already exists in the BT
    //      less than 0   => put the new element in the left branch
    //      bigger than 0 => put the new element in the right branch
    //      equals to 0   => does not add new element in the BT
    // REQUIREMENT: addElementInTree
    /// O( V + E )
    public:void addElement( const T value, int equal_value_option=0 ){
        addElementInTree( &root, value, equal_value_option );
    }
    ///////////////////////////////////////////////////////////////////////////////
    // USED BY: addElement( )
    private:void addElementInTree( BinaryTreeNode<T>** bt, const T value, int option ){
        // if the tree is a LEAF
        if( *bt == LEAF ){ *bt = new BinaryTreeNode<T>( value ); }
        // if it's the same element
        else if( value == (*bt)->getElement() ){
            if( option < 0 )
                addElementInTree( (*bt)->getLeftBranch(), value, option );
            else if( option > 0 )
                addElementInTree( (*bt)->getRightBranch(), value, option );
        }
        // if value is lower than element then add to the left
        else if( value < (*bt)->getElement() )
            addElementInTree( (*bt)->getLeftBranch(), value, option );
        // if value is bigger than element then add to the right
        else if( value > (*bt)->getElement() )
            addElementInTree( (*bt)->getRightBranch(), value, option );
    }
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // PRE ORDER PATH
    // Generates the path visiting: node element, left branch, then right branch
    // REQUIREMENTS: preOrder()
    /// O( V + E )
    public:vector<T> pathPreOrder( ){
        vector<T> path;
        preOrder( path, root );
        return path;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // used by: pathPreOrder()
    private:void preOrder( vector<T>& path, BinaryTreeNode<T>* node ){
        if( node == LEAF ) return;
        path.push_back( node->getElement() );
        preOrder( path, *(node->getLeftBranch()) );
        preOrder( path, *(node->getRightBranch()) );
    }
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // IN ORDER PATH
    // Generates the path visiting: left branch, node element, then right branch
    // REQUIREMENTS: inOrder()
    /// O( V + E )
    public:vector<T> pathInOrder( ){
        vector<T> path;
        inOrder( path, root );
        return path;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // used by: pathInOrder()
    private:void inOrder( vector<T>& path, BinaryTreeNode<T>* node ){
        if( node == LEAF ) return;
        inOrder( path, *(node->getLeftBranch()) );
        path.push_back( node->getElement() );
        inOrder( path, *(node->getRightBranch()) );
    }
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // POS ORDER PATH
    // Generates the path visiting: left branch, right branch, then node element
    // REQUIREMENTS: posOrder()
    /// O( V + E )
    public:vector<T> pathPosOrder( ){
        vector<T> path;
        posOrder( path, root );
        return path;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // used by: pathPosOrder()
    private:void posOrder( vector<T>& path, BinaryTreeNode<T>* node ){
        if( node == LEAF ) return;
        posOrder( path, *(node->getLeftBranch()) );
        posOrder( path, *(node->getRightBranch()) );
        path.push_back( node->getElement() );
    }
    ///////////////////////////////////////////////////////////////////////////////
};


int main(){
    
    int c, qunt,a;
    vector<int> num, resut;
    cin >> c;
    
    for(int i=0;i<c;i++){
    	
    	cin >> qunt;
    	
    	BinaryTree<int> bt = BinaryTree<int>(); 
    	
    	for(int j=0;j<qunt;j++){
    		
    		cin >> a;
			bt.addElement(a);
    		
		}

    	cout << "Case " << i+1 << ":" << endl;
    	cout << "Pre.:";
    	resut = bt.pathPreOrder();
		for(int j=0;j<qunt;j++){
			cout << " ";
			cout << resut[j];
		}
    	cout << endl;
    	
    	cout << "In..:";
    	resut = bt.pathInOrder();
		for(int j=0;j<qunt;j++){
			cout << " ";
			cout << resut[j];
		}
    	cout << endl;
    	
    	cout << "Post:";
    	resut = bt.pathPosOrder();
		for(int j=0;j<qunt;j++){
			cout << " ";
			cout << resut[j];
		}
    	cout << endl << endl;
    	//cout << endl;
	}
    
    
}