#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(2);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = 300;
	for (int i = 0; i < 255; i += 3) {

		ofSetColor(239, i);

		float deg_1 = ofRandom(360);
		deg_1 += ofMap(ofNoise((deg_1 + i) * 0.1, ofGetFrameNum() * 0.0005), 0, 1, -180, 180);
		float deg_2 = ofRandom(360);
		deg_2 += ofMap(ofNoise((deg_2 + i) * 0.1, ofGetFrameNum() * 0.0005), 0, 1, -180, 180);

		ofPoint point_1 = ofPoint(radius * cos(deg_1 * DEG_TO_RAD), radius * sin(deg_1 * DEG_TO_RAD));
		ofPoint point_2 = ofPoint(radius * cos(deg_2 * DEG_TO_RAD), radius * sin(deg_2 * DEG_TO_RAD));

		ofDrawLine(point_1, point_2);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}