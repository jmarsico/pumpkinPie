#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    state = 0;
    
    
}

//--------------------------------------------------------------
void testApp::update()
{
    
    //if gameplaystate is zero, update the menu
    if(0==state)
    {
    menu.update();
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw()
{
    //if gameplaystate is zero, update the menu
    if(0==state)
    {
    menu.draw();
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
    
    
    //send the mouseX and mouseY coordinates to the menu.select function
    menu.select(x, y);
    
    //find what the current selection is in menu object
    if(menu.getSelection() == 0)
    {
        state = 1;              //if selection is zero, change game state to 1 (gameplay)
    }
    ofLog() << "from main app: " << menu.getSelection();


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
