#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    
    shader.load("", "shader.frag");
    
}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetFrameNum() % 60 ==0) shader.load("", "shader.frag");
    
    grabber.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    shader.begin();
    shader.setUniformTexture("image", grabber.getTexture(), 0);
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("mouse", mouseX, mouseY);
    
    grabber.draw(0,0);
    shader.end();
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
