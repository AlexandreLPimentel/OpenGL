#ifndef Vector3_h
#define Vector3_h

class Vector3{

    private:
		float x;
		float y;
		float z;
	
	public:
		float GetX();
		float GetY();
		float GetZ();
		void Set(float x, float y, float z);
		Vector3();
};

#endif