#ifndef KEYBOARD_STATE
#define KEYBOARD_STATE

class KeyboardState {

	static KeyboardState* instance;
	static constexpr int CHAR_NUMBER = 128;

	bool keyboardState[CHAR_NUMBER];

	void initKeyboardState() {
		for (int i = 0; i < CHAR_NUMBER; i++) {
			keyboardState[i] = false;
		}
	}


	KeyboardState() {
		initKeyboardState();
	}
public:


	static KeyboardState* Instance() {
		if (instance != nullptr) return instance;

		instance = new KeyboardState();
		return instance;
	}

	void setKeyDown(char key) {
		keyboardState[key] = true;
	}

	void setKeyUp(char key) {
		keyboardState[key] = false;
	}

	bool getKeyState(char key) {
		return keyboardState[key];
	}

};

#endif
