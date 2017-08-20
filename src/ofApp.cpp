#include "ofApp.h"
#include <algorithm>
#include <vector>
#include <string>


bool ofApp::sortingFunction(ofColor x, ofColor y){
  return ((x.a << 24) + (x.r << 16) + (x.g << 8) + x.b) < ((y.a << 24) + (y.r << 16) + (y.g << 8) + y.b);
}

void ofApp::sorter(ofImage &img){
  vector<ofColor> newColors;

  for(int i = 0; i < img.getWidth(); i++){
    for(int j = 0; j < img.getHeight(); j++){
      ofColor tmp = img.getColor(i, j);
      newColors.push_back(tmp);
    }
  }

  std::sort(newColors.begin(), newColors.end(), sortingFunction);

  ofPixels newPix;
  newPix.allocate(img.getWidth(), img.getHeight(), 4);

  int k = 0;
  for(int i = 0; i < newPix.getHeight(); i++){
    for(int j = 0; j < newPix.getWidth(); j++){
      newPix.setColor(j, i, newColors[k]);
      k++;
    }
  }

  img.setFromPixels(newPix);
}

//--------------------------------------------------------------
void ofApp::setup(){

  // img.load("babylon.jpg");
  //
  // pix = img.getPixels();
  //
  // for(int i = 0; i < img.getWidth(); i++){
  //   for(int j = 0; j < img.getHeight(); j++){
  //     ofColor tmp = img.getColor(i, j);
  //     colors.push_back(tmp);
  //   }
  // }
  //
  // std::sort(colors.begin(), colors.end(), sortingFunction);
  //
  // ofPixels newPix;
  // newPix.allocate(img.getWidth(), img.getHeight(), 4);
  //
  // cout << "colors size: " << colors.size() << endl;
  // cout << "pix size: " << newPix.getWidth() << ", " << newPix.getHeight() << endl;
  //
  // int k = 0;
  // for(int i = 0; i < newPix.getHeight(); i++){
  //   for(int j = 0; j < newPix.getWidth(); j++){
  //     newPix.setColor(j, i, colors[k]);
  //     k++;
  //   }
  // }
  //
  // img.setFromPixels(newPix);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  if(!img.isAllocated()) return;

  if(img.getWidth() > img.getHeight()){

    float scaledHeight = (ofGetWidth() * img.getHeight()) / img.getWidth();
    float yOff = (ofGetHeight() - scaledHeight)/2;

    img.draw(0, yOff, ofGetWidth(), scaledHeight);

  }else{

    float scaledWidth = (ofGetHeight() * img.getWidth()) / img.getHeight();
    float xOff = (ofGetWidth() - scaledWidth)/2;

    img.draw(xOff, 0, scaledWidth, ofGetHeight());

  }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  if(key == 115){

    string fileName("sorted");
    fileName += to_string(index);
    fileName += ".png";

    img.save(fileName);
    index++;

  }

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

  cout << dragInfo.files[0] << endl;

  img.load(dragInfo.files[0]);

  // sorter(img);

}
