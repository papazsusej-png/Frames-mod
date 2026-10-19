#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

// Hook para interceptar la entrada de clics/toques en el juego
class $modify(MyPlayLayer, PlayLayer) {
    void handleButton(bool down, int button, bool isPlayer1) {
        // Aquí puedes añadir tu lógica personalizada para los frames/ticks

        // Llamamos a la función original para no interrumpir el juego
        PlayLayer::handleButton(down, button, isPlayer1);
    }
};

// Hook para añadir un botón en el menú de pausa
class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto menu = this->getChildByID("center-menu");
        if (menu) {
            auto myButton = CCMenuItemSpriteExtra::create(
                CCLabelBMFont::create("Mod Click", "bigFont.fnt"),
                this,
                menu_selector(MyPauseLayer::onMyButtonClicked)
            );
            myButton->setScale(0.5f);
            menu->addChild(myButton);
            menu->updateLayout();
        }
    }

    void onMyButtonClicked(CCObject* sender) {
        FLAlertLayer::create("Mod de Clics", "¡Modo cambiado correctamente!", "OK")->show();
    }
};
