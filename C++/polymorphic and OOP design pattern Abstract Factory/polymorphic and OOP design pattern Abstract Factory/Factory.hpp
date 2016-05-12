#ifndef Factory_hpp
#define Factory_hpp

#include <iostream>
#include "Product.hpp"

class UIFactory {
public:
    virtual Window* getToolboxWindow() = 0;
    virtual Window* getLayersWindow() = 0;
    virtual Window* getMainWindow() = 0;
    void deleteWindow(Window* w) {
        if (w != NULL) {
            delete w;
        }
    }
    virtual ~UIFactory() {}
};

class MFCUIFactory: public UIFactory {
    Window* getToolboxWindow() {
        return new MFCUI_tw;
    }
    Window* getLayersWindow() {
        return new MFCUI_lw;
    }
    Window* getMainWindow() {
        return new MFCUI_gm;
    }
};

class GtkUIFactory: public UIFactory {
    virtual Window* getToolboxWindow() {
        return new Gtk_tw;
    }
    virtual Window* getLayersWindow() {
        return new Gtk_lw;
    }
    virtual Window* getMainWindow() {
        return new Gtk_gm;
    }
};

class QtUIFactory: public UIFactory {
    virtual Window* getToolboxWindow() {
        return new Qt_tw;
    }
    virtual Window* getLayersWindow() {
        return new Qt_lw;
    }
    virtual Window* getMainWindow() {
        return new Qt_gm;
    }
};

#endif /* Factory_hpp */
