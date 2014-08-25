#include "GUILayer.h"
#include "BattleScene.h"
#include "Audio.h"

bool GUILayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	CCMenuItemImage * pause = CCMenuItemImage::create();
	pause->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_pause_nor"));
	pause->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_pause_pressed"));
	pause->initWithTarget(this,menu_selector(GUILayer::pause));
	//pause->initWithTarget((BattleScene *)this->getParent(),menu_selector(BattleScene::pause));
	CCMenu * pauseMenu = CCMenu::createWithItem(pause);
	pauseMenu->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-80,CCDirector::sharedDirector()->getWinSize().height-30));

	CCMenuItemImage * resume = CCMenuItemImage::create();
	resume->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_resume_nor"));
	resume->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_resume_pressed"));
	resume->initWithTarget(this,menu_selector(GUILayer::resume));
	CCMenu * resumeMenu = CCMenu::createWithItem(resume);
	resumeMenu->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-30,CCDirector::sharedDirector()->getWinSize().height-30));
	

	this->addChild(pauseMenu);
	this->addChild(resumeMenu);


	CCMenuItemImage * backGame = CCMenuItemImage::create();
	backGame->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("btn_finish"));
	backGame->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("btn_finish"));
	backGame->initWithTarget(this,menu_selector(GUILayer::unPause));
	backMenu = CCMenu::createWithItem(backGame);
	backMenu->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2));

	this->addChild(backMenu);
	backMenu->setVisible(false);

	return true;
}

void GUILayer::addFinishBth()
{
	backMenu->setVisible(true);
	
}

void GUILayer::removeFinishBtn()
{
	backMenu->setVisible(false);
}


void GUILayer::pause(CCObject * psender)
{
	EFFECTMUSIC_FUNC(BUTTON_MUSIC);
	BattleScene * scene = (BattleScene * )this->getParent();
	//uiLayer->addFinishBth();
	scene->pause(psender);
}

void GUILayer::resume(CCObject * psender)
{
	EFFECTMUSIC_FUNC(BUTTON_MUSIC);
	BattleScene * scene = (BattleScene * )this->getParent();
	//uiLayer->addFinishBth();
	scene->resume(0.1f);
}

void GUILayer::unPause(CCObject * psender)
{
	EFFECTMUSIC_FUNC(BUTTON_MUSIC);
	BattleScene * scene = (BattleScene * )this->getParent();
	//uiLayer->addFinishBth();
	scene->unPause(psender);
}