#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofFile jsonFile("settings.json"); // atidaromas failas
	jsonFile.setWriteable(true);
	if (!jsonFile.exists()) // jei failas neegzistuoja sukuriamas
	{
		jsonFile.create();
		string jsonEmptyValue = "{}";
		jsonFile.write(jsonEmptyValue.c_str(), 2);
	}

	jsonFile >> json; // stream'as perkeliamas i json objekta


	// Nuskaito reiksmes json'e
	for (auto& item : json.items()) // nuskaitomas json pirmas objektu lygis 
	{
		string key = item.key();
		if (key == "pages")
		{
			for (auto& page : item.value().items()) // nuskaitomas antra objektu lygis
			{
				cout << page.key() << endl;
			}
		}
	}

	// istrina objekta
	cout << "before item erase" << endl;
	json.erase("pages");
	for (auto& item : json.items()) // nuskaitomas json pirmas objektu lygis 
	{
		cout << item.key() << endl;
	}
	cout << "after \"pages\" delete" << endl;
	
	
	// Prideda objekta
	json["pages"]["pirmas"]["title"] = "Pirmas page";
	json["pages"]["pirmas"]["address"] = 1;

	for (auto& item : json.items()) // nuskaitomas json pirmas objektu lygis 
	{
		string key = item.key();
		if (key == "pages")
		{
			for (auto& page : item.value().items()) // nuskaitomas antra objektu lygis
			{
				cout << "page key: " << page.key() << endl;
				for (auto& obj : page.value().items()) // nuskaitomas antra objektu lygis
				{
					cout << obj.key() << endl;
				}
			}
		}
	}

	// issaugo json faila

	jsonFile.write(json.dump().c_str() , json.dump().size());
	cout << json.dump() << endl;
	//jsonFile.write(json.)
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
