#include <iostream>
#include <string>
using namespace std;
// Структура - вузол дерева
struct Node
{
  string faktura;// поле даних
  int counter = 0;//кількість висвітлень
  struct Node *left;  // лівий потомок
  struct Node *right; // правий потомок
};
// Вивід дерева
void printTree(Node *tree)
{
  if (tree != NULL) {      //Поки не зустріницься пустий вузол
      printTree(tree->left);  //Рекурсивний вивід лівого піддерева
      for (int i = 0; i<=tree->counter; i++) { //повтор по кількості зустрінутих повторів
          cout << tree->faktura << "\n"; //Виводим корінь дерева
      }
      printTree(tree->right); //Рекурсивний вивід правого піддерева
  }
}
// Додавання вузлів з даними до дерева
struct Node * insert(Node *tree, string a) {
  if (tree == NULL)     // Якщо немає дерева, то формуєм корінь
  {
    tree = new Node; //память під вузол
    tree->faktura = a;   //дані
    tree->left = NULL;
    tree->right = NULL; // Вітки робимо пустими
  }
  else
    if (a < tree->faktura)   //Якщо елемент менший за корінь ідемо вліво
      tree->left = insert(tree->left,a); //Рекурсивно додаєм ел
    else if (a > tree->faktura)  //Інакше ідем вправо
      tree->right = insert(tree->right,a); //РРекурсивно додаєм ел
    else{
        tree->counter++;
        return tree;
    }
    return(tree);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    struct Node *root = nullptr;

    int n;
    cin>>n;
    
    for (int i =0; i<n; i++) {
        string s;
        cin>> s;
        root = insert(root, s);
    }

    printTree(root);

    return 0;
}