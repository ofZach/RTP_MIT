#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // 3 trues, last one is important !!!
    font.load("UniversLTStd-Black.otf", 100, true, true, true );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofEnableDepthTest();
    
    cam.enableOrtho();
    cam.begin();
    
    
    
    ofDrawAxis(100);
    
    font.drawStringAsShapes("Muriel", 0, 0);
    ofPushMatrix();
    ofRotateY(90);
    font.drawStringAsShapes("Cooper", 0, 0);
    ofPopMatrix();
    
    
    //ofPopMatrix();
    
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
