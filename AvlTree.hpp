/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:52:58 by mmounib           #+#    #+#             */
/*   Updated: 2022/12/22 12:48:22 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_AVLTREE_HPP
#define FT_CONTAINERS_AVLTREE_HPP

# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define YELLOW "\e[1;33m"
# define PURPLE "\e[1;35m"
# define BLUE "\e[1;34m"

#include "pair.hpp"
#include <iostream>
#include <memory>


namespace ft {

    template < class Allocator, class pair, class Compare >

    class Tree {

    public :
        typedef pair           value_type;
        typedef Allocator   _allocator;
        typedef Compare     _compare;


        class Node {

        public :
            Node(value_type value) : left(NULL), right(NULL), parent(NULL), height(0), Key(value) {}

            ~Node() {}

            Node* minValueAVL_Node2(Node* node) {
                Node* r = node;
                while (r && r->left != NULL)
                    r = r->left;
                return r;
            }

            Node* maxValueAVL_Node2(Node* root) const {
                Node* r = root;

                while (r && r->right != NULL)
                    r = r->right;

                return r;
            }

            Node* get_successor(Node* _node)
            {
                if (_node && _node->right)
                    return (minValueAVL_Node2(_node->right));

                Node* temp = _node->parent;
                while (temp && temp->right && temp->right->Key.first == _node->Key.first)
                {
                    _node = temp;
                    temp = temp->parent;
                }
                return (temp);
            }

        public :
            Node *left;
            Node *right;
            Node *parent;
            int height;
            value_type Key;

           // ///////////////// I HAVE TO CONSTRUCT A NODE AND USE REBIND FUNCTION TEMPLATE IN ORDER TO MAKE ANOTHER ALLOCATOR THAT WILL ALLOCATE THE NODE  /////////////////////
        };

    private :
        typedef typename _allocator::template rebind<Node>::other _node_allocator_type;
        _node_allocator_type _node_allocator;
        _allocator _tree_allocator;


    public :

        int heightinit(Node *N) {
            if (N == NULL)
                return 0;
            return N->height;
        }

        int max(int a, int b){
            return (a > b) ? a : b;
        }

        bool avlsearch(Node* root, value_type key) {
            if (root == NULL)
                return false;

            else if (root->Key.first == key.first)
                return true;

            else if (_cmp(key.first, root->Key.first)) {
                return (avlsearch(root->left, key));
            }

            else {
                return (avlsearch(root->right, key));
            }
        }

        Node* avlsearch2(Node* root, value_type key) const {

            if (root == NULL)
                return (NULL);

            if (root->Key.first == key.first)
                return (root);

            else if (_cmp(key.first, root->Key.first)) {
                return (avlsearch2(root->left, key));
            }

            else if (_cmp(root->Key.first, key.first)){
                return (avlsearch2(root->right, key));
            }

            return (NULL);
        }

        Node* createNode(Node* par, value_type value) {
            Node* node = _node_allocator.allocate(1);
            _node_allocator.construct(node, Node(value));

            node->height = 1;
            node->parent = par;

            return (node);
        }

        Node* upper_bound(value_type p) const
        {
            Node* root = this->_Node;
            Node* temp = NULL;

            while (root)
            {
                if (this->_cmp(p.first, root->Key.first))
                {
                    temp = root;
                    root = root->left;
                }
                else
                    root = root->right;
            }
            return (temp);
        }

        /*
            Destroying The Node...
        */

        void destroyNode(Node* node)
        {
            _node_allocator.destroy(node);
            _node_allocator.deallocate(node, 1);
        }
/*
    Function to update the heights
*/
        void update_height(Node* root) {

            if (root != NULL) {
                int val = 1;

                if (root->left != NULL)
                    val = root->left->height + 1;

                if (root->right != NULL)
                    val = max(val, root->right->height + 1);

                root->height = val;
            }
        }

        Node* maxValueAVL_Node(Node* root) const {
            Node* r = root;

            while (r && r->right != NULL)
                r = r->right;

            return r;
        }

        Node *rightRotate(Node *y){
            Node *x = y->left;
            Node *z = x->right;

            if (x->right)
                x->right->parent = y;

            y->left = z;
            x->right = y;

            x->parent = y->parent;
            y->parent = x;

            if (x->parent && _cmp(y->Key.first, x->parent->Key.first))
                x->parent->left = x;
            else if (x->parent)
                x->parent->right = x;

            y = x;

            update_height(y->left);
            update_height(y->right);
            update_height(y);
            update_height(y->parent);

            return y;
        }

        Node *leftRotate( Node *x ) {
            Node *y = x->right;
            Node *z = y->left;

            x->right = z;

            if (y->left != NULL)
                y->left->parent = x;
            y->left = x;

            y->parent = x->parent;
            x->parent = y;

            if (y->parent != NULL && _cmp(x->Key.first, y->parent->Key.first)) {
                y->parent->left = y;
            }
            else if (y->parent != NULL)
                y->parent->right = y;

            update_height(x->left);
            update_height(x->right);
            update_height(x);
            update_height(x->parent);

            return y;
        }

        int getBalance( Node *N ) {
            if (N == NULL)
                return 0;

            return ( heightinit(N->left) - heightinit(N->right) );
        }

        // /////////////////////       (Node*&  root) TO DESTROY THE NODE ITSELF NOT THE COPY OF THE NODE                 ////////////////////////////////



        ~Tree(){
            destroyAll(_Node);
        }

        void destroyAll(Node *&root)
        {
            if (root) {
                destroyAll(root->left);
                destroyAll(root->right);
                _node_allocator.destroy(root);
                _node_allocator.deallocate(root, 1);
                root = NULL;
            }
        }

/*
    Function to construct a tree.
*/
        Node* AVL_insert(Node *par, Node* root, value_type value) {

/*
    Perform the normal BST insertion
*/
            if (root == NULL)
                return ( createNode(par, value) );

            if (_cmp(value.first, root->Key.first))
                root->left = AVL_insert(root, root->left, value);

            else if (_cmp(root->Key.first, value.first))
                root->right = AVL_insert(root, root->right, value);

            else
                return (root);

/*
    Step 1: Find the balance factor of parent
*/
            int balance = getBalance(root);

            if (balance > 1) {

                if (_cmp(value.first, root->left->Key.first))
                    return rightRotate(root);
                else if (_cmp(root->left->Key.first, value.first))
                {
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
            }
            if (balance < -1) {

                if (_cmp(root->right->Key.first, value.first))
                    return leftRotate(root);
                else if (_cmp(value.first, root->right->Key.first))
                {
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
            }

            update_height(root);

            return root;
        }

        Node* make_root(value_type value)
        {
            _Node = this->AVL_insert(NULL, _Node, value);

            Node* temp = this->avlsearch2(_Node, value);
            return (temp);
        }

        void change_root(value_type value)
        {
            _Node = this->AVL_delete(_Node, value);
        }

        Node* root_search(value_type value) const
        {
            return (this->avlsearch2(_Node, value));
        }

/*
    Function to find the AVL_Node with minimum Key value
*/
        Node* minValueAVL_Node(Node* node) const {
            Node* r = node;
            while (r && r->left != NULL)
                r = r->left;
            return r;
        }

        Node* get_root() const { return (this->_Node); }

/*
    Function to delete an Tree with the given Key from the subtree
*/

        Node* AVL_delete(Node* root, value_type value) {

            if (root == NULL)
                return root;

            else if ( _cmp(value.first, root->Key.first) )
                root->left = AVL_delete(root->left, value);

            else if ( _cmp(root->Key.first, value.first) )
                root->right = AVL_delete(root->right, value);

            else
            {
                if (root->left == NULL && root->right == NULL) {
                    destroyNode(root);
                    root = NULL;
                    return (root);
                }
                else if (root->left == NULL)
                {
                    Node*	temp = root;

                    root = root->right;
                    root->parent = temp->parent;
                    destroyNode(temp);
                    temp = NULL;
                    return (root);
                }
                else if (root->right == NULL)
                {
                    Node*	temp = root;

                    root = root->left;
                    root->parent = temp->parent;
                    destroyNode(temp);
                    temp = NULL;
                    return (root);
                }
                else {
                    Node*	temp = minValueAVL_Node(root->right);
                    Node *newNode = createNode(root->parent, temp->Key);
                    newNode->left = root->left;
                    newNode->right = root->right;

                    if (newNode->right)
                        newNode->right->parent = newNode;
                    if (newNode->left)
                        newNode->left->parent = newNode;

                    if (!root->parent) {
                        this->_Node = newNode;
                    }
                    else if (root->parent->left == root)
                    {
                        root->parent->left = newNode;
                    }

                    else if (root->parent->right == root)
                        root->parent->right = newNode;

                    destroyNode(root);

                    newNode->right = AVL_delete(newNode->right , temp->Key);

                    if (newNode == NULL)
                        return newNode;

                    update_height(newNode);

                    int balance = getBalance(newNode);

                    if (balance > 1) {
                        if (getBalance(newNode->left) >= 0)
                            return rightRotate(newNode);
                        else {
                            newNode->left = leftRotate(newNode->left);
                            return rightRotate(newNode);
                        }
                    }

                    if (balance < -1) {
                        if (getBalance(newNode->right) <= 0)
                            return leftRotate(newNode);
                        else {
                            newNode->right = rightRotate(newNode->right);
                            return leftRotate(newNode);
                        }
                    }
                    return (newNode);
                }
            }

/*
    If the tree had only one AVL_Node then return
*/
            if (root == NULL)
                return root;

            update_height(root);

            int balance = getBalance(root);

            if (balance > 1) {
                if (getBalance(root->left) >= 0)
                    return rightRotate(root);
                else {
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
            }

            if (balance < -1) {
                if (getBalance(root->right) <= 0)
                    return leftRotate(root);
                else {
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
            }

            return (root);
        }

        void swapTree(Tree& tree)
        {
            Node* root_temp =   tree._Node;
            tree._Node = this->_Node;
            this->_Node = root_temp;

            _allocator alloc_temp = tree._tree_allocator;
            tree._tree_allocator = this->_tree_allocator;
            this->_tree_allocator = alloc_temp;

            _node_allocator_type _node_alloc_temp = tree._node_allocator;
            tree._node_allocator = this->_node_allocator;
            this->_node_allocator = _node_alloc_temp;

            _compare temp_cmp = tree._cmp;
            tree._cmp = this->_cmp;
            this->_cmp = temp_cmp;
        }

        /*            **********************            Printing The Tree                 *************************             */

        struct Trunk
        {
            Trunk *prev;
            std::string str;

            Trunk(Trunk *prev, std::string str)
            {
                this->prev = prev;
                this->str = str;
            }
        };

        // Helper function to print branches of the binary tree
        void showTrunks(Trunk *p)
        {
            if (p == nullptr) {
                return;
            }

            showTrunks(p->prev);
            std::cout << p->str;
        };

        void printTree(Node* root, Trunk *prev, bool isLeft)
        {
            if (root == nullptr)
                return;
            std::string prev_str = "    ";
            Trunk *trunk = new Trunk(prev, prev_str);
            // if (root->right != this->_end)
            printTree(root->right, trunk, true);

            if (!prev) {
                trunk->str = "———";
            }
            else if (isLeft)
            {
                trunk->str = ".———";
                prev_str = "   |";
            }
            else {
                trunk->str = "`———";
                prev->str = prev_str;
            }

            showTrunks(trunk);
            std::cout << RED << "{ " << root->Key.first << " | " << root->Key.second << " } "<< RESET;
            if (root->parent != nullptr)
                std::cout << " {P: " << root->parent->Key.first << "} H: " << root->height << GREEN << " FB: " << getBalance(root) << RESET << std::endl;
            else
            std::cout << " {P: NULL" << "} H: " << root->height  << GREEN << " FB: " << getBalance(root) << RESET << std::endl;

            // std::cout << GREEN << "ROOT Parent : " << this->_root->parent->Key.first << RESET << std::endl;
            if (prev) {
                prev->str = prev_str;
            }
            trunk->str = "   |";

            printTree(root->left, trunk, false);
        };

        void	print() { printTree(this->_Node, nullptr, false); };

    private:
        Node* _Node;
        _compare _cmp;
    };
}

#endif //FT_CONTAINERS_AVLTREE_HPP
