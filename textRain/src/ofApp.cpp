#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(640, 480);
    img.allocate(640,480, OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 100; i++){
        pts[i].x = ofRandom(0,640);
        pts[i].y = 0;
        speed[i] = ofRandom(1,3);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    
    for (int i = 0; i < 100; i++){
        
        ofColor color = img.getPixels().getColor(pts[i].x, pts[i].y);
        if (color.getBrightness() > 127){
            pts[i].y = pts[i].y + speed[i];
            if (pts[i].y > 480){
                pts[i].y = 0;
            }
        } else {
            
            for (int j = pts[i].y; j >= 0; j--){
                ofColor color = img.getPixels().getColor(pts[i].x, j);
                if (color.getBrightness() > 127 || j == 0){
                    pts[i].y = j;
                    break;
                }
            }
            // ?
        }
        
        
    }
    
    
    // disneyland !
    for (int i = 0; i < 640; i++){
        for (int j = 0; j < 480; j++){
            ofColor color = grabber.getPixels().getColor(i, j);
            if (color.getBrightness() > mouseX){
                img.setColor(i,j, ofColor::white);
            } else {
                img.setColor(i,j, ofColor::black);
            }
        }
    }
    img.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    grabber.draw(0,0);
    img.draw(640,0);
    
    
    ofSetColor(255,0,0);
    
    for (int i = 0; i < 100; i++){
        ofDrawCircle(pts[i], 2);
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
