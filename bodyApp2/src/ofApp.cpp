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
        ofPolyline line = finder.getPolyline(0).getSmoothed(3);
        
        float time = ofGetElapsedTimef();
        lines.push_back(line);
        if (lines.size() > 300){
            lines.erase(lines.begin());
        }
        for (int i = 0; i < lines.size(); i++){
            ofSetColor( sin(-time*3 + ofMap(i, 0, lines.size(), 0, 10)) * 127 + 127);
            ofFill();
            ofBeginShape();
            for (int j = 0; j < lines[i].size(); j++){
                ofVertex(lines[i][j]);
            }
            ofEndShape();
            //lines[i].draw();
        }
        ofSetColor(255);
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
