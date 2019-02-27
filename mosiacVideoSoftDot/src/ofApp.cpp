#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    spot.load("spot.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    grabber.draw(640,0);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    for (int i = 0; i < grabber.getWidth(); i+=20){
        for (int j = 0; j < grabber.getHeight(); j+=20){
            ofColor color = grabber.getPixels().getColor(i,j); // disneyland!
            // img.getPixels().getData(); // Detroit
            
            float brightness = color.getBrightness();
            
            float radius = ofMap(brightness, 0, 255, 0, 30);
            spot.draw(i,j,radius, radius);
            
        }
    }
    ofSetRectMode(OF_RECTMODE_CORNER);
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
