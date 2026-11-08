#include <bits/stdc++.h>

using namespace std;

struct File
{
    string name;
    string extension;
    uint64_t byteSize;
    string getFullFilename()
{
     return name + '.' + extension;
}
};

struct Directory
{
    string name;
    vector<File *> files;
    vector<Directory *> dirs;
    Directory *parent = nullptr;

uint64_t getDirectorySize()
{
    uint64_t siz = 0;
    for (size_t  i = 0; i < files.size(); i++)
    {
        siz += files[i]->byteSize;
    }
    for (size_t i = 0; i < dirs.size(); i++)
    {
        siz += dirs[i]->getDirectorySize();
    }
    return siz;
}

bool addFile(File *f)
{
    string name = f->getFullFilename();

    for (size_t i = 0; i < files.size(); i++)
    {
        if (files[i]->getFullFilename() == name)
        {
            return false;
        }
    }
    files.push_back(f);
    return true;
}
bool addDirectory(Directory *d)
{
    string name = d->name;

    for (size_t i = 0; i < dirs.size(); i++)
    {
        if (dirs[i]->name == name)
        {
            return false;
        }
    }
    dirs.push_back(d);
    d->parent = this;
    //this is a pointer to the current directory;
    return true;
}

bool Exists(const string &filename)
{
    for (size_t i = 0; i < files.size(); i++)
    {
        if (files[i]->getFullFilename() == filename)
        {
            return true;
        }
    }
    return false;
}

bool moveFile(const string &filename, Directory &to)
{
    if (to.Exists(filename))
    {
        return false;
    }

    File *file = nullptr;
    for (size_t i = 0; i < files.size(); i++)
    {
        if (filename == files[i]->getFullFilename())
        {
            file = files[i];
            for (size_t j = i; j < files.size() - 1; j++)
            {
                files[j] = files[j + 1];
            }
            files.pop_back();
            to.files.push_back(file);
            return true;
        }
    }
    return false;
}

void printDir(int depth = 0)
{
    cout << name << endl;

    for (size_t i = 0; i < files.size(); i++)
    {
        cout << files[i]->getFullFilename() << endl;
    }
    for (size_t i = 0; i < dirs.size(); i++)
    {
        dirs[i]->printDir(depth + 1);
    }
}

Directory* up()
{
    if (parent == nullptr)
    {
        cout << "/(root)" << endl;
    }

    return parent;
}

bool findx(const string &targetName)
{
    for (size_t i = 0; i < files.size(); i++)
    {
        if (files[i] != nullptr && files[i]->getFullFilename() == targetName)
        {
            return true;
        }
    }

    for (size_t i = 0; i < dirs.size(); i++)
    {
        if (dirs[i] != nullptr && dirs[i]->name == targetName)
        {
            return true;
        }

        if (dirs[i]->findx(targetName))
        {
            return true;
        }
    }

    return false;
}
};

int main()
{

    Directory root, child1, child2;
    root.name = "downloads";
    child1.name = "C1";
    child2.name = "C2";

    child1.parent = &root;
    child2.parent = &child1;

    root.dirs.push_back(&child1);
    child1.dirs.push_back(&child2);

    File a, b, c;

    root.addFile(&a);
    child1.addFile(&b);
    child2.addFile(&c);

    a.name = "A";
    a.extension = "txt";
    a.byteSize = 500;

    b.name = "B";
    b.extension = "jpeg";
    b.byteSize = 4000000;

    c.name = "C";
    c.extension = "cpp";
    c.byteSize = 10000;

    Directory docs;
    docs.name = "documents";

    root.addDirectory(&docs);

    cout<<root.getDirectorySize();
    cout<<endl<<endl;

    if (root.moveFile("A.txt", child2))
    {
    cout << "File moved successfully!" << endl;
    }

    cout<<endl<<"Printing child1:";

    child1.printDir();

    cout<<endl;

    if (child1.findx("A.txt"))
    {
    cout << "File was found";
    }
    else
    {
    cout << "File not found";
    }
    cout<<endl;
    if (child2.findx("B.jpeg"))
    {
    cout << "File was found";
    }
    else
    {
    cout << "File not found";
    }

    cout<<endl<<endl;

    cout<<child2.up()->name;
    cout<<endl;
    cout<<root.up()->name;

return 0;
}
