/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

	// テクスチャファイル名を指定して、スプライトを作成
	sprite = Sprite::create("EXVS.png");
	// シーングラフにつなぐ
	this->addChild(sprite);

	//表示座標指定
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	////拡縮を指定
	sprite->setScale(0.5f);

	//MoveBy*action1 = MoveBy::create(1.0, Vec2(200, 100));
	//ScaleBy*action1 = ScaleBy::create(1.0f, 5.0f);
	//JumpTo*action1 = JumpTo::create(1.0, Vec2(200, 100), 500.0f,2);

	//ベジェ曲線
	/*ccBezierConfig conf;
	conf.controlPoint_1 = Vec2(800, 700);
	conf.controlPoint_2 = Vec2(1000, 700);
	conf.endPosition = Vec2(1000, 360);
	BezierTo*action1 = BezierTo::create(2.0f, ccBezierConfig(conf));
	sprite->runAction(action1);*/

	sprite->setOpacity(0);
	FadeIn*action1 = FadeIn::create(1.0f);
	sprite->runAction(action1);

	////回転角を指定
	//sprite->setRotation(0.0f);

	//sprite2->setScale(5.0f);
	////非表示にする
	//sprite->setVisible(true);
	////色合いを設定する
	////sprite->setColor(Color3B(0xff, 0xff, 0xff));
	////不透明度を設定
	//sprite->setOpacity(255);
	//sprite2->setOpacity(0);
	////画像の基準点（アンカーポイント）を設定
	//sprite->setAnchorPoint(Vec2(0, 1));
	//sprite2->setAnchorPoint(Vec2(0, 1));

	//反転
	//sprite->setFlippedX(true);

	//色
	//sprite->setColor(Color3B(255, 0, 0));
	//sprite->setColor(Color3B(0, 0, 255));

	//ずらしと一部切り取り
	/*sprite->setTextureRect(Rect(0, 64, 32, 32));
	sprite2->setTextureRect(Rect(0, 64, 32, 32));*/

	//update関数を有効にする
	//this->scheduleUpdate();

	//sprite->getTexture()->setAliasTexParameters();
	//sprite2->getTexture()->setAliasTexParameters();

	//state = 0;

	//blue = 0;

	//op1 = 255.0;
	//op2 = 0;

	this->scheduleUpdate();

    return true;
}

void HelloWorld::update(float delta)
{
	//ここに毎フレーム処理を書く

	//回転
	//float rot = sprite->getRotation();
	//rot += float(-10.0f);
	//sprite->setRotation(rot);

	//変色
	//blue += 255.0f/180.0f;
	//if (blue > 255.0f) {
	//	blue = 255.0f;
	//}
	//sprite->setColor(Color3B(255.0f - blue, 0, blue));


	//フェード
	//GLubyte op1 = sprite->getOpacity();
	//GLubyte op2 = sprite2->getOpacity();

	//op1 += float(-1);
	//op2 += float(1);
	//if (op2 > 255.0f) {
	//	op1 = 0;
	//	op2 = 255.0f;
	//}
	//sprite->setOpacity(op1);
	//sprite2->setOpacity(op2);

	//移動
	//Vec2 pos = sprite->getPosition();
	//switch (state) {
	//case 0:
	//	pos = sprite->getPosition();
	//	pos += Vec2(5.0f, 0);
	//	sprite->setPosition(pos);
	//	if (pos.x>=-100 ) {
	//		state = 1;
	//	}
	//	break;
	//case 1:
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0);
	//	sprite->setPosition(pos);
	//	if (pos.x <= 100) {
	//		state = 0;
	//	}
	//	break;
	//}
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

