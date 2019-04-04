#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    pos = 0;
    toSize = 0;
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

    for (int i = 0; i < 2; i++){
    if (buffer.size() > 0 && pos < toSize){
        unsigned char c = buffer.getBinaryBuffer()[pos];
        cout << c << endl;
        addBitsFromChar(c);
        pos++;
    }
    }
}

void testApp::addBitsFromChar( unsigned char c){
    for (int i = 0; i < 8; i++){
        if ((c >> (7-i)) & 0x01){
            bits.push_back(true);
        } else {
            bits.push_back(false);
        }
        
    }
}


//--------------------------------------------------------------
void testApp::draw(){
    
    float x = 0;
    float y = 0;
    for (int i = 0; i < bits.size(); i++){
        if (bits[i] == true){
            ofSetColor(255);
            ofRect( x, y, 10, 10);
            
            
        }
        x += 10;
        if (x > ofGetWidth()){
            x = 0;
            y += 10;
        }
    }
    
    int totalNum = (ofGetWidth() / 10) * (ofGetHeight()/10);
    while (bits.size() > totalNum){
        bits.erase(bits.begin(), bits.begin() + (ofGetWidth() / 10) + 1);
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    addBitsFromChar(key);
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
    
    cout << dragInfo.files[0] << endl;
    
    buffer = ofBufferFromFile(dragInfo.files[0]);
    
    pos = 0;
    toSize =  buffer.size();
    bits.clear();
    //cout << buffer.size() << endl;
}