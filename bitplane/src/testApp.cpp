#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    grabber.initGrabber(320,240);
    grabberAsGray.allocate(320, 240, OF_IMAGE_GRAYSCALE);
    for (int i = 0; i < 8; i++){
        bitPlanes[i].allocate(320, 240, OF_IMAGE_GRAYSCALE);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        
        unsigned char * colorPix = grabber.getPixels().getData();
        unsigned char * grayPix = grabberAsGray.getPixels().getData();
        
        for (int i = 0; i < 320*240; i++){
            grayPix[i] = colorPix[i*3];
            
            for (int j = 0; j < 8; j++){
                bitPlanes[j].getPixels()[i] = (grayPix[i] >> (7-j)) & 0x01 ? 255 : 0;
            }
        }
        
    }
    
    grabberAsGray.update();
    for (int i = 0; i < 8; i++){
        bitPlanes[i].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    grabberAsGray.draw(0,0);
    
    
    for (int i = 0; i < 8; i++){
        bitPlanes[i].draw((i%4)*ofGetWidth()/4, 240 + (i/4) * ofGetWidth()/4 * (240.0/320.0),ofGetWidth()/4, ofGetWidth()/4 * (240.0/320.0));
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
