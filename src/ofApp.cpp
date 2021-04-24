#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setNearClip(0.0f);
	cam.setFarClip(-1.0f);
	cam.setFov(120);	
	//cam.setGlobalPosition({ 800,400,100 });
	s = 100; //Wielkoœæ uk³adu
	float prob = 0.5; // prawdopodbieñstwo
	gra = grawzyc(s, s, prob);
	std::shared_ptr<renderer> rend = std::make_unique<renderer>(20.f,20.f, 20.f); //wielkoœæ elementów x y z
	gra.set_renderer(rend);
	//camera.rotate(90, camera.getUpDir());
	pointLight.setPosition(0, 2000, 0);
	pointLight2.setPosition(0, -2000, 0);

	pointLight3.setPosition(0, 0, -100);
	pointLight4.setPosition(1500, 0, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (i < 1 * 3000)
	{
		if (i % 1 == 0)
		{
			gra.calc_life_non(_c);
			gra.render3dnew(_c);
			_c = 1 - _c;
			//i = 0;
			//gra.write(_c);
			std::cout << i << std::endl;
		}
		i++;
	}
	else if (count < 0)
	{
		i = 0;
		count++;
		_c = 0;
		gra.reset();
		
	}
	else
	{
		ofExit(0);
	}
	

//c)
	



}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	ofSetColor(24, 50, 124);
	ofEnableDepthTest();
	pointLight.enable();
	pointLight2.enable();
	pointLight3.enable();
	pointLight4.enable();
	ofBoxPrimitive nod = gra.render3dfresh(_c);
	if (&nod != nullptr) //obs³uga kamery
	{
		glm::vec3 pos = nod.getPosition();
		glm::vec3 pos2 = pos;
		pos[0] -= 0;
		pos[1] +=0;
		pos[2] += 400;
		
		//cam.rollDeg(30);
		
		Angle += 2.f;
		AngleZ += 0.5f;
		if (Angle > 360.f)
		{
			Angle = 0.0f;
		}
		if (AngleZ > 360.f)
			AngleZ = 0.0f;
		pos[0] = pos[0] + cos(Angle * PI / 180) * 20*s;
		pos[1] = pos[1] + sin(Angle * PI / 180) * 20*s;
		pos[2] = pos[2] + cos(AngleZ * PI / 180) * sin(AngleZ * PI / 180) * 20*s*(cos(AngleZ * PI / 180) * sin(AngleZ * PI / 180) + 0.3);
		cam.setPosition(pos);



		cam.lookAt(pos2, ofVec3f(0, 0, 1));
		
		
		
	}



	//gra.render3dfresh(_c);
	//gra.render3d(_c);
	//gra.render(_c);
	//Sleep(5000);
	ofDisableDepthTest();
	ofSaveFrame();
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
