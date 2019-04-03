#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    cam.begin();
    cam.enableOrtho();
    ofScale(1,-1,1);
    ofRotateX(30);
    
    ofSetColor(255,255,255,50);
    for (int i = 0; i < 480; i++){
        
        ofPolyline line;
        for (int j = 0; j < 640; j++){
            float brightness = grabber.getPixels().getColor(j,i).getBrightness();
            float offset = ofMap(brightness, 0, 255, 0, 100);
            line.addVertex(j-640/2,i-480/2,offset);
        }
        line = line.getSmoothed(5);
        line.draw();
    }
    cam.end();
    
    //grabber.draw(640,0);
    
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
