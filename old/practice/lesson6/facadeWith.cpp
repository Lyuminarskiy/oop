#include <iostream>

using namespace std;

struct Editor
{
    void create()
    {
        cout << "Код написан" << endl;
    }

    void save()
    {
        cout << "Код сохранён" << endl;
    }
};

struct Compiler
{
    void compile()
    {
        cout << "Код скомпилирован" << endl;
    }
};

struct Runtime
{
    void execute()
    {
        cout << "Код запущен" << endl;
    }

    void terminate()
    {
        cout << "Код остановлен" << endl;
    }
};

class IDE
{
    Editor *editor;
    Compiler *compiler;
    Runtime *runtime;

public:
    IDE(Editor *editor, Compiler *compiler, Runtime *runtime) :
        editor(editor), compiler(compiler), runtime(runtime) {}

    void start()
    {
        editor->create();
        editor->save();
        compiler->compile();
        runtime->execute();
    }

    void stop()
    {
        runtime->terminate();
    }
};

void main()
{
    IDE ide(new Editor(), new Compiler(), new Runtime());
    ide.start();
    ide.stop();
}