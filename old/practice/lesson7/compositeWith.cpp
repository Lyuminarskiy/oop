#include <list>
#include <string>
#include <exception>
#include <iostream>

using namespace std;

// Исключение, сигнализирующее о неподдерживаемой операции.
class NotSupportedException : public exception {} notSupportedException;

// Узел файловой системы.
class FileSystemNode
{
protected:
  string name;

public:
  FileSystemNode(const string& name) : name(name) {}
  virtual void add(FileSystemNode* node) = 0;
  virtual void remove(FileSystemNode* node) = 0;
  virtual void display(string prefix = "")
  {
    cout << prefix << name << endl;
  }
};

// Файл в файловой системе.
struct File : public FileSystemNode
{
  File(const string& name) : FileSystemNode(name) {}
  virtual void add(FileSystemNode* node) override
  {
    throw notSupportedException;
  }
  virtual void remove(FileSystemNode* node) override
  {
    throw notSupportedException;
  }
};

// Каталог файловой системы.
class Directory : public FileSystemNode
{
  list<FileSystemNode*> childNodes;

public:
  Directory(const string& name) : FileSystemNode(name) {}
  virtual void add(FileSystemNode* node) override
  {
    childNodes.push_back(node);
  }
  virtual void remove(FileSystemNode* node) override
  {
    childNodes.remove(node);
  }
  virtual void display(string prefix = "") override
  {
    FileSystemNode::display(prefix);

    if(childNodes.size())
    {
      prefix = "-> " + prefix;
      for(auto node: childNodes)
        node->display(prefix);
    }
  }
};

int main()
{
  Directory fileSystem("Файловая система");
  Directory driveA("Раздел A");
  Directory driveB("Раздел B");

  fileSystem.add(&driveA);
  fileSystem.add(&driveB);

  File doc("Реферат.docx");
  File image("23-05-2017.png");

  driveA.add(&doc);
  driveA.add(&image);

  fileSystem.display();
  /*
  Файловая система
  -> Раздел A
  -> -> Реферат.docx
  -> -> 23-05-2017.png
  -> Раздел B
  */

  Directory documents("Документы");
  File text("записка.txt");
  File presentation("презентация.pptx");

  driveA.remove(&doc);
  driveB.add(&documents);

  documents.add(&doc);
  documents.add(&text);
  documents.add(&presentation);

  fileSystem.display();
  /*
  Файловая система
  -> Раздел A
  -> -> 23-05-2017.png
  -> Раздел B
  -> -> Документы
  -> -> -> Реферат.docx
  -> -> -> записка.txt
  -> -> -> презентация.pptx
  */

  return 0;
}