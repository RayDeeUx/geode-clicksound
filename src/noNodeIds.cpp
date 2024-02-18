#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/loader/Loader.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/loader/Index.hpp>

using namespace geode::prelude;

// test disabling the menulayer
class $modify(newl,MenuLayer) { 
    void index(CCObject*) {
        try {
            auto indexlook = geode::Index::get();
            auto nodeIDSmod =  indexlook->getItemsByModID("geode.node-ids");
            if(nodeIDSmod.size() != 0){
            auto nodeIDSMod2 = nodeIDSmod.back();
            auto nodeIdsMetadata = nodeIDSMod2->getMetadata();
            Mod theNodeIds = Mod(nodeIdsMetadata);
            Mod* theNodeId2 = &theNodeIds;
            geode::openIndexPopup(theNodeId2);
            } else {
                auto alerterror = FLAlertLayer::create(
                "Click Sounds Error",
                "Unable to fetch mod, please download from the <cp>geode website!</c> ",  
                "OK"
            );
            alerterror->show();
            }
        } catch (const std::exception& e) {
            auto alerterror = FLAlertLayer::create(
                "Click Sounds Error",
                "Unable to fetch mod, please download from the <cp>geode website!</c> ",  
                "OK"
            );
            alerterror->show();
        }

        /*if (indexlook != nullptr) {
        auto nodeIDSmod =  indexlook->getItemsByModID("geode.node-ids").back();
        auto nodeIdsMetadata = nodeIDSmod->getMetadata();
        Mod theNodeIds = Mod(nodeIdsMetadata);
        Mod* theNodeId2 = &theNodeIds;
        geode::openIndexPopup(theNodeId2);
        }
        else {
            auto alerterror = FLAlertLayer::create(
            "Click Sounds Error",
            "Unable to fetch mod, please download from the <cp>geode website!</c> ",  
            "OK"
        );*/
        //alerterror->show();
        //this->getChildByID("bottom-menu")->getChildByID("geode.loader/geode-button")->setVisible(true);
    };
    void index2(CCObject*) {
        utils::game::restart();
    };

    void initUi() {
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        // auto spr = ButtonSprite::create("/nodeIdsLogo.png"_spr);
        auto spr = CCSprite::create("nodeIdsLogo.png"_spr);
        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(newl::index)
        );
        btn->setScale(.7);
        btn->setPosition(winSize.width / 2, winSize.height / 2);
         this->getChildByID("Beat.PleaseDONOTREMOVE")->addChild(btn);
    };
    void initUi2() {
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        // auto spr = ButtonSprite::create("/nodeIdsLogo.png"_spr);
        auto spr = ButtonSprite::create("Restart Game");
        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(newl::index2)
        );
        btn->setScale(.7);
        btn->setPosition(winSize.width / 2, (winSize.height / 2) - 10);
         this->getChildByID("Beat.PleaseDONOTREMOVE")->addChild(btn);
    };

    static void onModify(auto& self) {
        self.setHookPriority("MenuLayer::init", -100); // GO LAST :O (IDK WHY IT SAID GO FIRST)
    }
    bool init() {
        auto winSize = CCDirector::get()->getWinSize();
        if (!MenuLayer::init())
            return false;
        
        if (Loader::get()->isModLoaded("geode.node-ids")) {
            return true;
        };

        auto alert = FLAlertLayer::create(
            "Click Sounds Error",
            "Please install Node Ids from the <cp>Geode Index</c>!",  
            "OK"
        );
        alert->m_scene = this;
        
        for(auto items : CCArrayExt<CCNode*>(this->getChildren())) {
            items->setVisible(false);
        };
            for(auto items : CCArrayExt<CCNode*>(this->getChildByID("bottom-menu")->getChildren())) {
            items->setVisible(false);
        };
        this->getChildByID("bottom-menu")->setVisible(true);
            if (this->getChildByID("close-menu")) {
            this->getChildByID("close-menu")->setVisible(true);
            }
        
         this->getChildByID("Beat.PleaseDONOTREMOVE")->setLayout(
                RowLayout::create()
                ->setGap(14)
                 ->setGrowCrossAxis(true)
                 ->setCrossAxisReverse(true)
                 ->setAutoScale(true)
                 ->setAxisAlignment(AxisAlignment::Center)
                );
        
        auto menu = CCMenu::create();
        menu->setID("Beat.PleaseDONOTREMOVE");
        menu->setPosition(winSize.width / 2, 0);
        
        this->getChildByID("bottom-menu")->getChildByID("geode.loader/geode-button")->setVisible(true);
        this->getChildByID("bottom-menu")->setVisible(true);
        //this->getChildByID("bottom-menu")->getChildByID("geode.loader/geode-button")->setScale(0.2);
        //this->getChildByID("bottom-menu")->getChildByID("geode.loader/geode-button")->setPosition(99999, 99999);
        this->getChildByID("Beat.PleaseDONOTREMOVE")->setPosition(winSize.width / 2, 0);
          this->getChildByID("Beat.PleaseDONOTREMOVE")->setContentSize({284.500,45.000});
         this->getChildByID("Beat.PleaseDONOTREMOVE")->setScale(1.1);
        this->getChildByID("Beat.PleaseDONOTREMOVE")->setVisible(true);
        alert->show();
        newl::initUi2();
        newl::initUi();
         this->getChildByID("Beat.PleaseDONOTREMOVE")->updateLayout();
        /*auto listener = EventListener<ModInstallFilter>(+[](ModInstallEvent* ev) {
        this->setVisible(false);
        hello2->setVisible(true);
        }, ModInstallFilter("geode.node-ids"));e*/
           
               
        return true;
    };
};


