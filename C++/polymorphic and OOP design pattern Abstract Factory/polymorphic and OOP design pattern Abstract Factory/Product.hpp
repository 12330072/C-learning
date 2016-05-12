#ifndef Product_hpp
#define Product_hpp
#include <iostream>

using std::cout;
using std::string;

class Window {
public:
    virtual void draw() = 0;
    virtual string getToolkit() = 0;
    virtual string getType() = 0;
};

class MFCUI_tw : public Window {
public:
    void draw() {
        cout << "MotifButton\n";
    }
    string getToolkit() {
        return "MFC";
    }
    string getType() {
        return "ToolboxWindow";
    }
};

class MFCUI_lw : public Window {
public:
    void draw() {
        cout << "MotifButton\n";
    }
    string getToolkit() {
        return "MFC";
    }
    string getType() {
        return "LayersWindow";
    }
};

class MFCUI_gm : public Window {
public:
    void draw() {
        cout << "MotifButton\n";
    }
    string getToolkit() {
        return "MFC";
    }
    string getType() {
        return "MainWindow";
    }
};

class Gtk_tw : public Window {
public:
    void draw() {
        cout << "MotifMenu\n";
    }
    string getToolkit() {
        return "Gtk";
    }
    string getType() {
        return "ToolboxWindow";
    }
};

class Gtk_lw : public Window {
public:
    void draw() { cout << "MotifMenu\n"; }
    string getToolkit() {
        return "Gtk";
    }
    string getType() {
        return "LayersWindow";
    }
};

class Gtk_gm : public Window {
public:
    void draw() { cout << "MotifMenu\n"; }
    string getToolkit() {
        return "Gtk";
    }
    string getType() {
        return "MainWindow";
    }
};

class Qt_tw : public Window {
public:
    void draw() { cout << "WindowsButton\n"; }
    string getToolkit() {
        return "Qt";
    }
    string getType() {
        return "ToolboxWindow";
    }
};

class Qt_lw : public Window {
public:
    void draw() { cout << "WindowsButton\n"; }
    string getToolkit() {
        return "Qt";
    }
    string getType() {
        return "LayersWindow";
    }
};

class Qt_gm : public Window {
public:
    void draw() { cout << "WindowsButton\n"; }
    string getToolkit() {
        return "Qt";
    }
    string getType() {
        return "MainWindow";
    }
};

#endif
