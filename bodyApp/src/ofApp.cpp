#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    player.load("input.mov");
    player.play();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    player.update();

    if (player.isFrameNew()){
        
        finder.findContours(player);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    player.draw(player.getWidth(),0);
    //finder.draw();
    
    if (finder.size() > 0){
        ofPolyline line = finder.getPolyline(0);
        
        ofPoint midPt;
        for (int i = 0; i < line.size(); i++){
            midPt += line[i];
        }
        midPt /= (line.size());
        //ofDrawCircle(midPt, 5);
        //line = line.getResampledByCount(20);
        //line.draw();
        
        ofRectangle bounds = line.getBoundingBox();
        //ofDrawCircle(bounds.getCenter(), 5);
        ofDrawLine(midPt, bounds.getCenter());
        float xDiff = (midPt.x - bounds.getCenter().x);
        xDiffSmooth = 0.9 * xDiffSmooth + 0.1 * xDiff;
        ofDrawBitmapString(ofToString(xDiff), 10,10);
        ofSetColor(ofMap(xDiffSmooth, -20, 20, 0, 255, true));
        ofDrawRectangle(0,400,800,400);
        ofSetColor(255);
        
        
        ofPoint topPoint = line[0];
        for (int i = 0; i < line.size(); i++){
            if (line[i].y < topPoint.y){
                topPoint = line[i];
            }
        }
        line.draw();
        topSmoothed = 0.9 * topSmoothed + 0.1 * topPoint;
        ofDrawCircle(topSmoothed, 10);
        
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
