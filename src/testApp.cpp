#include "testApp.h"
//state = 0 = show menu and don't update/draw gameplay
//state = 1 = transition state, only for creating world based on menu selection
//state = 2 = game play


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
    else if (1 == state)
    {
        WorldBox.draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    switch(key) {
        case OF_KEY_RIGHT:
            WorldBox.boxx+=100;
            break;
        case OF_KEY_LEFT:
            WorldBox.boxx-=100;
            break;
        case OF_KEY_UP:
            WorldBox.boxy-=100;
            break;
        case OF_KEY_DOWN:
            WorldBox.boxy+=100;
            break;
        case 'z':
            WorldBox.boxz+=10;
            break;
        case 'x':
           WorldBox.boxz-=10;
            break;
	}
    

    
    
    if(key==' ')
    {
        state = 0;
    }

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
