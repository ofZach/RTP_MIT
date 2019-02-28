#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("UniversLTStd-Black.otf", 200, true, true, true);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofTranslate(200,500);
    
    vector < ofPath > letters = font.getStringAsPoints("hello");

    for (int i = 0; i < letters.size(); i++){
        vector < ofPolyline > lines = letters[i].getOutline();
        for (int j = 0; j < lines.size(); j++){
            
            // make a copy of the line, since we will resample / blur it
            
            ofPolyline temp = lines[j];
            temp = temp.getResampledBySpacing(5);
            temp = temp.getSmoothed(ofMap(mouseX, 0, ofGetWidth(), 0, 100, true));
            for (int k = 0; k < temp.size(); k++){
                ofDrawCircle(temp[k], 1);
            }
        }
    }
    
    
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
