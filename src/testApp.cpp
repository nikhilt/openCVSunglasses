#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	img.loadImage("sunglasses.png");
	finder.setup("haarcascade_frontalface_default.xml");
	//finder.findHaarObjects(img);
    grabber.initGrabber(640,480);
    ofEnableAlphaBlending();
    ofSetWindowShape(grabber.getWidth(), grabber.getHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    grabber.grabFrame();
    if(grabber.isFrameNew()){
        finder.findHaarObjects(grabber.getPixelsRef(), grabber.getWidth()/5, grabber.getHeight()/5);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	grabber.draw(0, 0);
	ofNoFill();
	for(int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
		//ofRect(cur.x, cur.y, cur.width, cur.height);
        img.draw(cur);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}